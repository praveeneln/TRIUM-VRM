Imports Microsoft.VisualBasic
Imports System
Imports System.IO
Imports Neurotec.Biometrics
Imports Neurotec.Images
Imports Neurotec.Licensing
Imports Neurotec.Media

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [source] [output template] <optional: is url>", Utils.GetAssemblyName())
		Console.WriteLine(vbTab & "[source]          - filename or url frames should be captured from")
		Console.WriteLine(vbTab & "[output template] - file to save captured template to")
		Console.WriteLine(vbTab & "[is url]          - specifies that passed source parameter is url (value: 1) or filename (value: 0)")
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Biometrics.FaceExtraction,Media"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Dim isUrl As Boolean = False
		Dim extractor As NLExtractor = Nothing
		Dim template As NLTemplate = Nothing
		Dim mediaSource As NMediaSource = Nothing
		Dim mediaReader As NMediaReader = Nothing
		Try
			' Obtain license.
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine("Could not obtain licenses for components: {0}", Components)
				Return -1
			End If

			If args.Length > 2 Then
				isUrl = args(2) = "1"
			End If

			' Create an extractor
			extractor = New NLExtractor()

			' Set extractor template size (recommended, for enroll to database, is large) (optional)
			extractor.TemplateSize = NleTemplateSize.Large

			' Detect all faces features
			extractor.DetectAllFeaturePoints = True

			' Start extraction of face template from a stream (sequence of images)
			extractor.ExtractStart()

			Dim extractionStatus As NleExtractionStatus = NleExtractionStatus.None

			' create media source
			mediaSource = IIf(isUrl, NMediaSource.FromUrl(args(0)), NMediaSource.FromFile(args(0)))

			mediaReader = New NMediaReader(mediaSource, NMediaType.Video, True)

			Dim image As NImage
			Dim details As NleDetectionDetails = Nothing
			mediaReader.Start()
			image = mediaReader.ReadVideoSample()
			Do While image IsNot Nothing AndAlso extractionStatus = NleExtractionStatus.None
				Using grayscaleImage As NGrayscaleImage = image.ToGrayscale()
					image.Dispose()

					' use image as another frame of stream
					extractionStatus = extractor.ExtractNext(grayscaleImage, details)
					If details.FaceAvailable Then
						Console.WriteLine("found face:")
						Console.WriteLine(vbTab & "location = ({0}, {1}), width = {2}, height = {3}, confidence = {4}", details.Face.Rectangle.X, details.Face.Rectangle.Y, details.Face.Rectangle.Width, details.Face.Rectangle.Height, details.Face.Confidence)
					End If
					If details.RightEyeCenter.Confidence > 0 OrElse details.LeftEyeCenter.Confidence > 0 Then
						Console.WriteLine(vbTab & "found eyes:")
						If details.RightEyeCenter.Confidence > 0 Then
							Console.WriteLine(vbTab + vbTab & "Right: location = ({0}, {1}), confidence = {2}", details.RightEyeCenter.X, details.RightEyeCenter.Y, details.RightEyeCenter.Confidence)
						End If
						If details.LeftEyeCenter.Confidence > 0 Then
							Console.WriteLine(vbTab + vbTab & "Left: location = ({0}, {1}), confidence = {2}", details.LeftEyeCenter.X, details.LeftEyeCenter.Y, details.LeftEyeCenter.Confidence)
						End If
					End If
					If details.NoseTip.Confidence > 0 Then
						Console.WriteLine(vbTab & "found nose:")
						Console.WriteLine(vbTab + vbTab & "location = ({0}, {1}), confidence = {2}", details.NoseTip.X, details.NoseTip.Y, details.NoseTip.Confidence)
					End If
					If details.MouthCenter.Confidence > 0 Then
						Console.WriteLine(vbTab & "found mouth:")
						Console.WriteLine(vbTab + vbTab & "location = ({0}, {1}), confidence = {2}", details.MouthCenter.X, details.MouthCenter.Y, details.MouthCenter.Confidence)
					End If
				End Using
				image = mediaReader.ReadVideoSample()
			Loop

			Dim baseFrameIndex As Integer
			template = extractor.ExtractEnd(baseFrameIndex, details, extractionStatus)
			If extractionStatus <> NleExtractionStatus.TemplateCreated Then
				Console.WriteLine("face template extraction failed!")
				Return -1
			End If

			Console.WriteLine("Created template containing {0} faces", template.Records.Count)
			Console.WriteLine("Base frame index is {0}", baseFrameIndex)

			' save compressed template to file
			File.WriteAllBytes(args(args.Length - 1), template.Save().ToArray())
			Return 0
		Catch ex As Exception
			Console.WriteLine(ex)
			Dim neurotecException As INeurotecException = TryCast(ex, INeurotecException)
			If neurotecException IsNot Nothing Then
				Return neurotecException.Code
			End If
			Return -1
		Finally
			NLicense.ReleaseComponents(Components)

			If template IsNot Nothing Then
				template.Dispose()
			End If

			If extractor IsNot Nothing Then
				extractor.Dispose()
			End If

			If mediaReader IsNot Nothing Then
				mediaReader.Stop()
				mediaReader.Dispose()
			End If

			If mediaSource IsNot Nothing Then
				mediaSource.Dispose()
			End If
		End Try
	End Function
End Class
