; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNtDriverLoaderDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NtDriverLoader.h"

ClassCount=3
Class1=CNtDriverLoaderApp
Class2=CNtDriverLoaderDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NTDRIVERLOADER_DIALOG

[CLS:CNtDriverLoaderApp]
Type=0
HeaderFile=NtDriverLoader.h
ImplementationFile=NtDriverLoader.cpp
Filter=N

[CLS:CNtDriverLoaderDlg]
Type=0
HeaderFile=NtDriverLoaderDlg.h
ImplementationFile=NtDriverLoaderDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BTN_INSTALL

[CLS:CAboutDlg]
Type=0
HeaderFile=NtDriverLoaderDlg.h
ImplementationFile=NtDriverLoaderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NTDRIVERLOADER_DIALOG]
Type=1
Class=CNtDriverLoaderDlg
ControlCount=12
Control1=IDC_BTN_LOOKFOR,button,1342242816
Control2=IDC_BTN_INSTALL,button,1342242816
Control3=IDC_BTN_START,button,1342242816
Control4=IDC_BTN_STOP,button,1342242816
Control5=IDC_BTN_UNINSTALL,button,1342242816
Control6=IDC_BTN_ABOUT,button,1342242816
Control7=IDC_BTN_EXIT,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_SYSFILE,edit,1484849280
Control10=IDC_STATIC_STATUS,static,1342308352
Control11=IDC_BTN_HELP,button,1342242816
Control12=IDC_Btn_SCM,button,1342242816

