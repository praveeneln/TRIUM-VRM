Imports Microsoft.VisualBasic
Imports System
Imports Neurotec.Licensing
Imports Neurotec.Media
Imports Neurotec.Sound

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [source] [bufferCount] <optional: is url>", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "source - filename or url sound buffers should be captured from")
		Console.WriteLine(vbTab & "bufferCount - number of sound buffers to capture from specified filename or url")
		Console.WriteLine(vbTab & "is url - specifies that passed source parameter is url (value: 1) or filename (value: 0)")
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Const Components As String = "Media"

		Utils.PrintTutorialHeader(args)

		If args.Length < 2 Then
			Return Usage()
		End If

		Try
			If (Not NLicense.ObtainComponents("/local", 5000, Components)) Then
				Console.WriteLine(String.Format("Could not obtain licenses for components: {0}", Components))
				Return -1
			End If

			Dim uri As String = args(0)
			Dim isUrl As Boolean = False
			Dim frameCount As Integer = Integer.Parse(args(1))
			If frameCount = 0 Then
				Console.WriteLine("no frames will be captured as frame count is not specified")
			End If

			If args.Length > 2 Then
				isUrl = args(2) = "1"
			End If

			' create media source
			Using mediaSource As NMediaSource = IIf((isUrl), NMediaSource.FromUrl(uri), NMediaSource.FromFile(uri))
				Console.WriteLine("display name: {0}", mediaSource.DisplayName)

				Using mediaReader As New NMediaReader(mediaSource, NMediaType.Audio, True, Nothing)
					ReadSoundBuffers(mediaReader, frameCount)
				End Using
			End Using
			Console.WriteLine("done")
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
		End Try
	End Function

	Private Shared Sub DumpMediaFormat(ByVal mediaFormat As NMediaFormat)
		If mediaFormat Is Nothing Then
			Throw New ArgumentNullException("mediaFormat")
		End If

		Select Case mediaFormat.MediaType
			Case NMediaType.Video
				Dim videoFormat As NVideoFormat = CType(mediaFormat, NVideoFormat)
				Console.WriteLine("video format .. {0}x{1} @ {2}/{3} (interlace: {4}, aspect ratio: {5}/{6})", videoFormat.Width, videoFormat.Height, videoFormat.FrameRate.Numerator, videoFormat.FrameRate.Denominator, videoFormat.InterlaceMode, videoFormat.PixelAspectRatio.Numerator, videoFormat.PixelAspectRatio.Denominator)
			Case NMediaType.Audio
				Dim audioFormat As NAudioFormat = CType(mediaFormat, NAudioFormat)
				Console.WriteLine("audio format .. channels: {0}, samples/second: {1}, bits/channel: {2}", audioFormat.ChannelCount, audioFormat.SampleRate, audioFormat.BitsPerChannel)
			Case Else
				Throw New ArgumentException("unknown media type specified in format!")
		End Select
	End Sub

	Private Shared Sub ReadSoundBuffers(ByVal mediaReader As NMediaReader, ByVal bufferCount As Integer)
		Dim mediaSource As NMediaSource = mediaReader.Source

		Console.WriteLine("media length: {0}", mediaReader.Length)

		Dim mediaFormats() As NMediaFormat = mediaSource.GetFormats(NMediaType.Audio)
		If mediaFormats Is Nothing Then
			Console.WriteLine("formats are not yet availbel (should be availble after media reader is started")
		Else
			Console.WriteLine("format count: {0}", mediaFormats.Length)
			For i As Integer = 0 To mediaFormats.Length - 1
				Console.Write("[{0}] ", i)
				DumpMediaFormat(mediaFormats(i))
			Next i
		End If

		Dim currentMediaFormat As NMediaFormat = mediaSource.GetCurrentFormat(NMediaType.Audio)
		If currentMediaFormat IsNot Nothing Then
			Console.WriteLine("current media format:")
			DumpMediaFormat(currentMediaFormat)

			If mediaFormats IsNot Nothing Then
				Console.WriteLine("set the last supported format (optional) ... ")
				mediaSource.SetCurrentFormat(NMediaType.Audio, mediaFormats(mediaFormats.Length - 1))
			End If
		Else
			Console.WriteLine("current media format is not yet available (will be availble after media reader start)")
		End If

		Console.Write("starting capture ... ")
		mediaReader.Start()
		Console.WriteLine("capture started")

		Try
			currentMediaFormat = mediaSource.GetCurrentFormat(NMediaType.Audio)
			If currentMediaFormat Is Nothing Then
				Throw New Exception("current media format is not set even after media reader start!")
			End If
			Console.WriteLine("capturing with format: ")
			DumpMediaFormat(currentMediaFormat)

			For i As Integer = 0 To bufferCount - 1
				Dim timeSpan, duration As TimeSpan

				Using buffer As NSoundBuffer = mediaReader.ReadAudioSample(timeSpan, duration)
					If buffer Is Nothing Then ' end of stream
						Return
					End If

					Console.WriteLine("[{0} {1}] sample rate: {2}, sample length: {3}", timeSpan, duration, buffer.SampleRate, buffer.Length)
				End Using
			Next i
		Finally
			mediaReader.Stop()
		End Try
	End Sub
End Class
