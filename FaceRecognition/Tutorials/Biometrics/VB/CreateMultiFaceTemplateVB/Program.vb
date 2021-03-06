Imports Microsoft.VisualBasic
Imports System
Imports System.Collections.Generic
Imports System.IO

Imports Neurotec.Biometrics

Friend Class Program
	Private Shared Function Usage() As Integer
		Console.WriteLine("usage:")
		Console.WriteLine(vbTab & "{0} [one or more templates] [output NLTemplate]", Utils.GetAssemblyName())
		Console.WriteLine()
		Console.WriteLine(vbTab & "[one or more NLTemplates]  - one or more files containing face templates.")
		Console.WriteLine(vbTab & "[output NTemplate]         - output NTemplate file.")
		Console.WriteLine()
		Return -1
	End Function

	Shared Function Main(ByVal args() As String) As Integer
		Utils.PrintTutorialHeader(args)
		If args.Length < 2 Then
			Return Usage()
		End If

		Try
			' Read all input NLTemplates
			Dim inputTemplates As New List(Of NTemplate)()
			For i As Integer = 0 To args.Length - 2
				Dim templateData() As Byte = File.ReadAllBytes(args(i))
				Console.WriteLine("reading {0}", args(i))

				inputTemplates.Add(New NTemplate(templateData))
			Next i

			' Create and fill output faces template
			Dim outputTemplate As New NLTemplate()
			For Each inputTemplate As NTemplate In inputTemplates
				If inputTemplate.Faces Is Nothing Then
					Continue For
				End If

				For Each inputRecord As NLRecord In inputTemplate.Faces.Records
					outputTemplate.Records.Add(CType(inputRecord.Clone(), NLRecord))
				Next inputRecord
			Next inputTemplate

			If outputTemplate.Records.Count = 0 Then
				Console.WriteLine("not writing template file because no records found.")
				Return -1
			End If

			Console.WriteLine("{0} face record(s) found.", outputTemplate.Records.Count)

			' Write output file
			Dim packetTemplate() As Byte = outputTemplate.Save().ToArray()
			File.WriteAllBytes(args(args.Length - 1), packetTemplate)
			Console.WriteLine("writing {0}", args(args.Length - 1))
			Return 0
		Catch ex As Exception
			Console.WriteLine(ex)
			Dim neurotecException As INeurotecException = TryCast(ex, INeurotecException)
			If neurotecException IsNot Nothing Then
				Return neurotecException.Code
			End If
			Return -1
		End Try
	End Function
End Class
