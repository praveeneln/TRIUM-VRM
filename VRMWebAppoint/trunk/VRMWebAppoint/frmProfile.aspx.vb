﻿Imports LinqDB.TABLE
Imports System.Data
Imports LinqDB.ConnectDB

Partial Class frmProfile
    Inherits System.Web.UI.Page


    Public ReadOnly Property strId() As String
        Get
            Return Val(Page.Request.QueryString("id") & "")
        End Get
    End Property
    Public ReadOnly Property strext() As String
        Get
            Return Page.Request.QueryString("ext") & ""
        End Get
    End Property

    Protected Sub Page_Init(sender As Object, e As EventArgs) Handles Me.Init
        If strext = "0" Then
            divHeader.Style.Add("display", "none")
        Else
            divHeader.Style.Add("display", "")
        End If
    End Sub

    Protected Sub Page_Load(sender As Object, e As EventArgs) Handles Me.Load

        If Not Page.IsPostBack Then
            PopulateData()
        End If
    End Sub

    Private Sub PopulateData()
        'Dim clsTbUserLinqDB As New TbUserLinqDB
        'Dim trans As New TransactionDB
        'Dim sql As String

        ''sql = "select ROW_NUMBER() OVER(ORDER BY U.id asc) AS No,U.ID_CardNo as CardNo,U.Id"
        ''sql += " ,First_name_th + ' ' + Last_Name_TH as FullName_TH"
        ''sql += " ,First_name_EN + ' ' + Last_Name_EN as FullName_EN"
        ''sql += " ,U.Address"
        ''sql += " ,(select case "
        ''sql += " when isnull(B.ID_CardNo,'') =  ''  then ''"
        ''sql += " else 'checked' end) "
        ''sql += " as IsBlacklist"
        ''sql += " ,U.BirthDate"
        ''sql += " ,U.IssueDate"
        ''sql += " ,U.expdate"
        ''sql += " from TB_User U"
        ''sql += " LEFT JOIN TB_Blacklist B"
        ''sql += " ON U.ID_CardNo = B.ID_CardNo Order by U.ID_CardNo"

        'clsTbUserLinqDB.GetDataByPK(strId, trans.Trans)
        'With clsTbUserLinqDB
        '    If .HaveData = True Then
        '        CheckBlackList(.ID_CARDNO, trans)
        '        lblUnderImage.InnerText = .FIRST_NAME_EN & " " & .LAST_NAME_EN
        '        lblCardNo.Text = .ID_CARDNO
        '        lblNameThai.Text = .FIRST_NAME_TH & " " & .LAST_NAME_TH
        '        lblNameEng.Text = .FIRST_NAME_EN & " " & .LAST_NAME_EN
        '        lblBirth.Text = Utility.DateFunction.ConvertDateToShow(.BIRTHDATE)
        '        lblIssueDate.Text = Utility.DateFunction.ConvertDateToShow(.ISSUEDATE)
        '        lblExpiry.Text = Utility.DateFunction.ConvertDateToShow(.EXPDATE)
        '        lblAddress.Text = .ADDRESS
        '        If Not IsNothing(.ID_PICTURE) Then
        '            picavatar.Src = "data:image/jpeg;base64," & System.Convert.ToBase64String(.ID_PICTURE)
        '        End If
        '        divRecentActivities1.Style.Add("display", "")
        '        divRecentActivities2.Style.Add("display", "")
        '    Else
        '        divRecentActivities1.Style.Add("display", "none")
        '        divRecentActivities2.Style.Add("display", "none")
        '    End If
        'End With
        'trans.CommitTransaction()
        'clsTbUserLinqDB = Nothing
        ''  Dim dt As DataTable = clsTbUserLinqDB.GetListBySql(sql, Nothing)
    End Sub
    Private Sub CheckBlackList(ID_CARDNO As String, trans As TransactionDB)
        'Dim clsTbBlacklistLinqDB As New TbBlacklistLinqDB
        'With clsTbBlacklistLinqDB
        '    Dim dt As DataTable = .GetDataList("ID_CARDNO='" & ID_CARDNO & "'", "", trans.Trans)
        '    If dt.Rows.Count = 0 Then
        '        divAddBlackList.Style.Add("display", "")
        '    Else
        '        divAddBlackList.Style.Add("display", "none")
        '    End If

        'End With
        'clsTbBlacklistLinqDB = Nothing
    End Sub
End Class
