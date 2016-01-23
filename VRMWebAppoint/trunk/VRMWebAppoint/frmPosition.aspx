﻿<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmPosition.aspx.vb" Inherits="frmPosition" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
     <div class="main-content">
        <div class="breadcrumbs" id="breadcrumbs">
            <ul class="breadcrumb">
                <li>
                    <i class="icon-home home-icon"></i>
                    <a href="frmMain.aspx">Home</a>

                    <span class="divider">
                        <i class="icon-angle-right arrow-icon"></i>
                    </span>
                </li>
                <li class="active">Position</li>
            </ul>
            <!--.breadcrumb-->

            <%--            <div class="nav-search" id="nav-search">
                <form class="form-search" />
                <span class="input-icon">
                    <input type="text" placeholder="Search ..." class="input-small nav-search-input" id="nav-search-input" autocomplete="off" />
                    <i class="icon-search nav-search-icon"></i>
                </span>
                </form>
            </div>--%>
            <!--#nav-search-->
        </div>

        <div class="page-content">

 
            <div class="row-fluid">
                <div class="span12">
                    <!--PAGE CONTENT BEGINS-->
                    <h3 class="header smaller lighter blue">Position</h3>

                    <div class="row-fluid">
                        <div class="span12">
                            <button class="btn btn-small btn-success" id="btnAdd" name="btnAdd">
                                <i class="icon-plus"></i>
                                Add New
                            </button>
                        </div>


                        <%--      <div class="dt_out_actions">
                            <div class="btn-group pull-Left">
                                <button class="btn btn-small btn-info" id="btnPrint" name="btnPrint" style="display: none">
                                    <i class="icon-print"></i>
                                    Print
                                </button>
                            
                                <button class="btn btn-small btn-danger" id="btnDelete" name="btnDelete" style="display: none">
                                    <i class="icon-trash"></i>
                                    Delete
                                </button>

                            </div>
                        </div>--%>
                    </div>
                       <div class="space-2"></div>
                    <div class="row-fluid">
                        <div class="span12">
                            <table class="table table-striped table-bordered table-hover" id="dt_out"></table>
                        </div>
                    </div>


                </div>

            </div>
            <!--/.span-->
        </div>
        <!--/.row-fluid-->

        <!--/.page-content-->



        <%--    <div class="ace-settings-container" id="ace-settings-container">
            <div class="btn btn-app btn-mini btn-warning ace-settings-btn" id="ace-settings-btn">
                <i class="icon-cog bigger-150"></i>
            </div>

            <div class="ace-settings-box" id="ace-settings-box">
                <div>
                    <div class="pull-left">
                        <select id="skin-colorpicker" class="hide">
                            <option data-class="default" value="#438EB9" />
                            #438EB9
									<option data-class="skin-1" value="#222A2D" />
                            #222A2D
									<option data-class="skin-2" value="#C6487E" />
                            #C6487E
									<option data-class="skin-3" value="#D0D0D0" />
                            #D0D0D0
                        </select>
                    </div>
                    <span>&nbsp; Choose Skin</span>
                </div>

                <div>
                    <input type="checkbox" class="ace-checkbox-2" id="ace-settings-header" />
                    <label class="lbl" for="ace-settings-header">Fixed Header</label>
                </div>

                <div>
                    <input type="checkbox" class="ace-checkbox-2" id="ace-settings-sidebar" />
                    <label class="lbl" for="ace-settings-sidebar">Fixed Sidebar</label>
                </div>

                <div>
                    <input type="checkbox" class="ace-checkbox-2" id="ace-settings-breadcrumbs" />
                    <label class="lbl" for="ace-settings-breadcrumbs">Fixed Breadcrumbs</label>
                </div>

                <div>
                    <input type="checkbox" class="ace-checkbox-2" id="ace-settings-rtl" />
                    <label class="lbl" for="ace-settings-rtl">Right To Left (rtl)</label>
                </div>
            </div>
        </div>--%>
        <!--/#ace-settings-container-->
    </div>


    <div id="dialog-edit" style="display: none;">

        <div class="row-fluid">
            <div class="span12">

                <div class="span4">
                    <label class="control-label" id="lblPositionName">Position Name</label>
                </div>
                <div class="span8">

                    <input type="text" id="txtPositionName" placeholder="Position Name" class="span12 limited" data-maxlength="50" maxlength="50">
                    <span  class="help-inline color red" id="lblvalidPositionName" style="display: none">This field is required</span>

                </div>

            </div>
        </div>
        <div class="row-fluid" style="display:none">
            <div class="span12">

                <div class="span4">
                    <label class="control-label" id="lblPositionDesc">Position Desc</label>
                </div>
                <div class="span8">
                    <textarea id="txtPositionDesc" placeholder="Position Desc" style="height: 120px; resize: none;" class="span12 limited" data-maxlength="255" maxlength="255"></textarea>
                    <span class="help-inline color red" id="lblvalidPositionDesc" style="display: none">This field is required</span>
                </div>

            </div>
        </div>
        <div class="row-fluid">
            <div class="span4">
                <label class="control-label" id="lblPositionActive">Active</label>
            </div>
            <div class="span8">
                <div class="controls">
                    <label class="inline">
                        <input name="ckbActive" type="checkbox" id="ckbActive" />
                        <span class="lbl">&nbsp;</span>
                    </label>

                </div>
            </div>
        </div>

    </div>


<%--    <style type="text/css" media="all">

	.my_class {
				word-wrap: break-word;
			}
    </style>--%>


    <script type="text/javascript">
        //Open page
        $(document).ready(function () {

            //Load Position
            var oTable;
            var isAddNew = false;
            LoadData();

            //Add Click
            $("#btnAdd").click(function () {
                onEdit(0); return false;
            });


        });

       

        //Call
        function LoadData() {
            var dataurl = 'WebSevice/WebService.asmx/LoadPosition';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "success": PopulateGrid
            });
        }

        //Populate Grid
        function PopulateGrid(jsondata) {
            var jsonobject = JSON.parse(jsondata.d);
            var columns = [{
                "sTitle": "No",
                "sType": "numeric",
                "mDataProp": "no",
                "bUseRendered": false

            },
                            {
                                "sTitle": "Position Name",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "position_name"

                            },
                            //{
                            //    "sTitle": "Position Description",
                            //    "sType": "string",
                            //    "sDefaultContent": "",
                            //    "mDataProp": "position_desc"
                            //   // "fnRender": function (obj) {
                            //    //   // return '<div style="word-wrap: break-word; width: 300px" id="lblPositionDescBild">999999999999999999999999999999999999999999999999991111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111</div>';
                            //    //    // wordWrap(str, 40)
                                   
                            //    //    //return wordWrap(obj.aData.position_desc , 10);
                            //    //    return '<div class="my_class" id="lblPositionDescBild">' + obj.aData.Position_desc + '</div>';
                            //   // }

                            //},
                            {
                                "sTitle": "Active",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "active_status_desc"

                            },

                            {
                                "sTitle": "Action",
                                "bSortable": false,
                                "fnRender": function (obj) {
                                    return '<div class="hidden-phone visible-desktop action-buttons">'
                                            + '<a href="#"  class="Green"  title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                            + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"  class="Red"  title="Delete" onclick="onConfirmDelete(' + obj.aData.id + ');" >'
                                            + '<span class="red"><i class="icon-trash bigger-130"></i></span>'
                                            + '</a>'
                                            + '</div>'
                                            + '<div class="hidden-desktop visible-phone">'
                                            + '			<div class="inline position-relative">'
                                            + '				<button class="btn btn-minier btn-primary dropdown-toggle" data-toggle="dropdown">'
                                            + '					<i class="icon-cog icon-only bigger-110"></i>'
                                            + '				</button>'
                                            + '				<ul class="dropdown-menu dropdown-icon-only dropdown-yellow pull-right dropdown-caret dropdown-close">'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#"   class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                            + '							<span class="green">'
                                            + '								<i class="icon-edit bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + '					<li>'
                                            + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDelete(' + obj.aData.id + ');">'
                                            + '							<span class="red">'
                                            + '								<i class="icon-trash bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + '				</ul>'
                                            + '			</div>'
                                            + '		</div>'


                                    ;
                                },
                                "sDefaultContent": "",
                                "bUseRendered": false
                            }
            ];

            oTable = $('#dt_out').dataTable({
                "aaData": jsonobject,
                "bAutoWidth": false,
                "aoColumnDefs": [
                { "sWidth": "10%", "aTargets": [0] },
                { "sWidth": "60%", "aTargets": [1] },
                //{ "sWidth": "35%", "aTargets": [2] },
                { "sWidth": "15%", "aTargets": [2] },
                { "sWidth": "15%", "aTargets": [3] }
                ],
                "aoColumns": columns,
                "bDestroy": true,
            });


        }

        //Add or Edit 
        function onEdit(id) {
            onValidHide();
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/GetPositionById",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);
              
                    if (strvalue.length == 1) {
                        $("#txtPositionName").val(strvalue[0].position_name);
                        $("#txtPositionDesc").val(strvalue[0].position_desc);
                        if (strvalue[0].active_status == "Y") {
                            $("#ckbActive").prop("checked", true);
                        } else {
                            $("#ckbActive").prop("checked", false);
                        }
                    } else {
                        $("#txtPositionName").val("");
                        $("#txtPositionDesc").val("");
                        $("#ckbActive").prop("checked", false);
                    }
                }
            });



            $("#dialog-edit").dialog({
                autoOpen: false,
                resizable: false,
                width: "500px",
                modal: true,
                buttons: {
                    "Save": function () {
                        var ret = onValid();
                        if (ret == true) {
                            onSave(id);
                        }

                    },
                    "Close": function () {
                        $(this).dialog("close");
                    }

                },
                show: {
                    effect: 'size',
                    duration: 500
                },
                hide: {
                    effect: 'size',
                    duration: 500
                }
            });

            var titledialog;
            if (id == 0) {
                titledialog = "Add New";
            } else {
                titledialog = "Edit";
            }

            $("#dialog-edit").dialog("option", "title", titledialog).dialog("open");

        }

        //Save Position
        function onSave(id) {
            var UserID = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var Position_name = $('#txtPositionName').val();
            var Position_desc = $('#txtPositionDesc').val();
            var Position_active = $('input[name="ckbActive"]:checked').length;
            var param = "{'id':" + JSON.stringify(id) + ",'position_name':" + JSON.stringify(Position_name) + ",'position_desc':" + JSON.stringify(Position_desc) + ",'userid':" + JSON.stringify(UserID) + ",'active':" + JSON.stringify(Position_active) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SavePosition",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onPositionSuccess,
                error: onFailed
            });
        }
        //Delete Position
        function onDelete(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeletePosition",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onDeleteSuccess,
                error: onDeleteFailed
            });
        }

        //Confirm delete Position
        function onConfirmDelete(id) {

            var msg = 'Please confirm the delete';
            var div = $("<div>" + msg + "</div>");
            div.dialog({
                title: "Confirm",
                modal: true,
                buttons: [
                            {
                                text: "Yes",
                                click: function () {
                                    div.dialog("close");
                                    onDelete(id);

                                }
                            },
                            {
                                text: "No",
                                click: function () {
                                    div.dialog("close");
                                }
                            }
                ]
            });



        }

        //Group  Alert  True
        function onPositionSuccess(result) {

            if (result.d == "YES") {
                $("#dialog-edit").dialog('close');
                onAlert("Save Complete");
                LoadData();
            } else {
                if (result.d == "DUPLICATE") {
                    onAlert("Position name already exists. Please modify position name.");
                    LoadData();
                } else {
                    onAlert("Save Fail");
                }

            }

        }

        //Alert Save when false
        function onFailed() {
            onAlert("Save Fail");
        }

        //Alert Delete when true
        function onDeleteSuccess(result) {

            if (result.d == true) {
                onAlert("Delete Complete");
                LoadData();

            } else {
                onAlert("Delete Fail");
            }

        }

        //Alert Delete when false
        function onDeleteFailed() {
            onAlert("Delete Fail");
        }


        // Alert Box
        function onAlert(msg) {

            var div = $("<div>" + msg + "</div>");
            div.dialog({
                title: "Message",
                modal: true,
                buttons: [

                            {
                                text: "Ok",
                                click: function () {
                                    div.dialog("close");
                                }
                            }
                ]
            });

        }



        //Hide Valid
        function onValidHide() {
            $("#lblvalidPositionName").hide();
            $("#lblvalidPositionDesc").hide();

        }
        //Check Valid
        function onValid() {
            var isValid;
            isValid = true;
            var Position_name = $('#txtPositionName').val();
           // var Position_desc = $('#txtPositionDesc').val();
            if (Position_name == '') {
                $("#lblvalidPositionName").show();
                isValid = false;
            } else {
                $("#lblvalidPositionName").hide();
            }
            //if (Position_desc == '') {
            //    $("#lblvalidPositionDesc").show();
            //    isValid = false;
            //} else {
            //    $("#lblvalidPositionDesc").hide();

            //}

            return isValid;


        }


    </script>
</asp:Content>

