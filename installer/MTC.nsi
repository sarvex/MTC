!include "MUI2.nsh"
!include InstallOptions.nsh
!include "nsProcess.nsh"

OutFile "..\cdrom\setup.exe"

LangString Name 1033 'MTC Connect'
LangString Name 1049 'МТС Коннект'
LangString Name 1058 'МТС Коннект'

Name "$(Name)"
BrandingText "MTC Dialer"
InstallDir "$PROGRAMFILES32\MTC\"
RequestExecutionLevel admin

!define MUI_ICON "resource\logo.ico"
!define MUI_UNICON "resource\logo.ico"

!define MUI_WELCOMEFINISHPAGE_BITMAP "resource\splash.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "resource\splash.bmp"

;Pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES  
!insertmacro MUI_PAGE_FINISH
!define MUI_ABORTWARNING

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH
!define MUI_UNABORTWARNING

!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Russian"
!insertmacro MUI_LANGUAGE "Ukrainian"

LangString CLOSE_MTC 1033 'Close "MTC Connect" before continue'
LangString CLOSE_MTC 1049 'Для продолженя закройте МТС Коннект'
LangString CLOSE_MTC 1058 'Для продовження закрийте МТС Коннект'

LangString ALREADY_MTC_RUNNING_ENG 1033 'MTC Connect is already installed. $\n$\nClick `OK` to remove the \ previous version or `Cancel` to cancel this upgrade'
LangString ALREADY_MTC_RUNNING_RUS 1033 'МТС Коннект уже установлена. Нажмите ОК чтобы удалить предыдущую версию программы или Отменить для отмены обновления'
LangString ALREADY_MTC_RUNNING_UKR 1033 'МТС Коннект вже встановлена. Натискуйте ОК щоб видалити попередню версію програми або Скасувати для відміни оновлення'

LangString ALREADY_MTC_RUNNING_ENG 1049 'MTC Connect is already installed. $\n$\nClick `OK` to remove the \ previous version or `Cancel` to cancel this upgrade'
LangString ALREADY_MTC_RUNNING_RUS 1049 'МТС Коннект уже установлена. Нажмите ОК чтобы удалить предыдущую версию программы или Отменить для отмены обновления'
LangString ALREADY_MTC_RUNNING_UKR 1049 'МТС Коннект вже встановлена. Натискуйте ОК щоб видалити попередню версію програми або Скасувати для відміни оновлення'

LangString ALREADY_MTC_RUNNING_ENG 1058 'MTC Connect is already installed. $\n$\nClick `OK` to remove the \ previous version or `Cancel` to cancel this upgrade'
LangString ALREADY_MTC_RUNNING_RUS 1058 'МТС Коннект уже установлена. Нажмите ОК чтобы удалить предыдущую версию программы или Отменить для отмены обновления'
LangString ALREADY_MTC_RUNNING_UKR 1058 'МТС Коннект вже встановлена. Натискуйте ОК щоб видалити попередню версію програми або Скасувати для відміни оновлення'

Function .onInit
ReadRegDWORD $language HKLM "SOFTWARE\MTC" "Preference"
!insertmacro MUI_UNGETLANGUAGE
BringToFront
; Check if already running
System::Call "kernel32::CreateMutexA(i 0, i 0, t '$(^Name)') i .r0 ?e"
Pop $0
StrCmp $0 0 launch
StrLen $0 "$(^Name)"
IntOp $0 $0 + 1
loop:
FindWindow $1 '#32770' '' 0 $1
IntCmp $1 0 +5
System::Call "user32::GetWindowText(i r1, t .r2, i r0) i."
StrCmp $2 "$(^Name)" 0 loop
System::Call "user32::ShowWindow(i r1,i 9) i."         ; If minimized then restore
System::Call "user32::SetForegroundWindow(i r1) i."    ; Bring to front
Abort
launch:

advsplash::show 1000 600 400 0x04025C ..\resource\splash

ReadRegStr $R0 HKLM \
			   "Software\Microsoft\Windows\CurrentVersion\Uninstall\MTC" \
			   "UninstallString"
			   StrCmp $R0 "" done


			   ${If} $language == "1033"
			   MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
				   "$(ALREADY_MTC_RUNNING_ENG)" \
				   IDOK uninst
				   Abort
				   ${EndIf}

				   ${If} $language == "1049"
				   MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
					   "$(ALREADY_MTC_RUNNING_RUS)" \
					   IDOK uninst
					   Abort
					   ${EndIf}

					   ${If} $language == "1058"
					   MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
						   "$(ALREADY_MTC_RUNNING_UKR)" \
						   IDOK uninst
						   Abort
						   ${EndIf}

						   ;Run the uninstaller
						   uninst:
						   ClearErrors
						   ExecWait '$R0 _?=$INSTDIR' ;Do not copy the uninstaller to a temp file

						   IfErrors no_remove_uninstaller done
						   ;You can either use Delete /REBOOTOK in the uninstaller or add some code
						   ;here to remove the uninstaller. Use a registry key to check
						   ;whether the user has chosen to uninstall. If you are using an uninstaller
						   ;components page, make sure all sections are uninstalled.
						   no_remove_uninstaller:

!insertmacro MUI_LANGDLL_DISPLAY
done:
FunctionEnd

Function un.onInit
ReadRegDWORD $language HKLM "SOFTWARE\MTC" "Preference"

FunctionEnd 

Section "Desktop Shortcut" SectionX
SetOutPath $INSTDIR
SetShellVarContext current    
CreateShortCut "$DESKTOP\MTC.lnk" "$INSTDIR\MTC.exe" "" "$INSTDIR\MTC.exe" 0
SectionEnd

Section "Quick Launch Shortcut" SectionY
SetOutPath $INSTDIR
SetShellVarContext current   
CreateShortCut "$QUICKLAUNCH\MTC.lnk" "$INSTDIR\MTC.exe" "" "$INSTDIR\MTC.exe" 0
SectionEnd

Section "MTC"
!include "FileFunc.nsh"

;Add registry keys
WriteRegStr HKLM "SOFTWARE\MTC" "InstallationDirectory" $INSTDIR
WriteRegStr HKLM "SOFTWARE\MTC" "Preference" $language
WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC" "DisplayName" "MTC"
WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC" "UninstallString" '"$INSTDIR\uninstall.exe"'
WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC" "NoModify" 1
WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC" "NoRepair" 1

SetOutPath $INSTDIR

CreateDirectory "$SMPROGRAMS\MTC"
CreateShortCut "$SMPROGRAMS\MTC\MTC.lnk" "$INSTDIR\MTC.exe" "" "$INSTDIR\MTC.exe" 0
CreateShortCut "$SMPROGRAMS\MTC\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\MTC.exe" 0

File ..\release\MTC.exe
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\libgcc_s_dw2-1.dll
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\mingwm10.dll        
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\QtCore4.dll         
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\QtGui4.dll
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\QtNetwork4.dll     
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\bin\QtSql4.dll

WriteUninstaller "uninstall.exe"

File resource\logo.ico

SetOutPath $INSTDIR\sqldrivers
File C:\QtSdk\Desktop\Qt\4.8.0\mingw\plugins\sqldrivers\qsqlite4.dll


SetOutPath $INSTDIR\drivers
File drivers\modem.exe
File drivers\psexec.exe

SetOutPath $INSTDIR\drivers\x86
File drivers\x86\dpinst.xml
File drivers\x86\dpinst.exe
File drivers\x86\Olive_USB_BusEnum.cat
File drivers\x86\Olive_USB_BusEnum.inf
File drivers\x86\Olive_USB_BusEnum.sys
File drivers\x86\Olive_USB_ETS.cat
File drivers\x86\Olive_USB_ETS.inf
File drivers\x86\Olive_USB_ETS.sys
File drivers\x86\Olive_USB_MODEM.cat
File drivers\x86\Olive_USB_MODEM.inf
File drivers\x86\Olive_USB_MODEM.sys
File drivers\x86\Olive_USB_WinMux.cat
File drivers\x86\Olive_USB_WinMux.inf
File drivers\x86\Olive_USB_WinMux.sys

SetOutPath $INSTDIR\drivers\x64
File drivers\x64\dpinst.xml
File drivers\x64\dpinst.exe
File drivers\x64\Olive_USB_BusEnum.cat
File drivers\x64\Olive_USB_BusEnum.inf
File drivers\x64\Olive_USB_BusEnum.sys
File drivers\x64\Olive_USB_ETS.cat
File drivers\x64\Olive_USB_ETS.inf
File drivers\x64\Olive_USB_ETS.sys
File drivers\x64\Olive_USB_MODEM.cat
File drivers\x64\Olive_USB_MODEM.inf
File drivers\x64\Olive_USB_MODEM.sys
File drivers\x64\Olive_USB_WinMux.cat
File drivers\x64\Olive_USB_WinMux.inf
File drivers\x64\Olive_USB_WinMux.sys

WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC" "DisplayIcon" "$INSTDIR\logo.ico"


SectionEnd

Section "Drivers"
!include "x64.nsh"
${If} ${RunningX64}
ExecWait $INSTDIR\drivers\x64\dpinst.exe
${Else}
ExecWait $INSTDIR\drivers\x86\dpinst.exe
${EndIf} 
ExecWait $INSTDIR\drivers\modem.exe
SectionEnd

Section "Uninstall"
loop:
${nsProcess::FindProcess} "MTC.exe" $R0
StrCmp $R0 0 0 +2
MessageBox MB_OK|MB_ICONEXCLAMATION "$(CLOSE_MTC)" IDOK loop 


!include "x64.nsh"
${If} ${RunningX64}
ExecWait '"$INSTDIR\drivers\x64\dpinst.exe" /U "$INSTDIR\drivers\x64\Olive_USB_BusEnum.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x64\dpinst.exe" /U "$INSTDIR\drivers\x64\Olive_USB_ETS.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x64\dpinst.exe" /U "$INSTDIR\drivers\x64\Olive_USB_MODEM.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x64\dpinst.exe" /U "$INSTDIR\drivers\x64\Olive_USB_WinMux.inf" /S /D'
${Else}
ExecWait '"$INSTDIR\drivers\x86\dpinst.exe" /U "$INSTDIR\drivers\x86\Olive_USB_BusEnum.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x86\dpinst.exe" /U "$INSTDIR\drivers\x86\Olive_USB_ETS.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x86\dpinst.exe" /U "$INSTDIR\drivers\x86\Olive_USB_MODEM.inf" /S /D'
ExecWait '"$INSTDIR\drivers\x86\dpinst.exe" /U "$INSTDIR\drivers\x86\Olive_USB_WinMux.inf" /S /D'
${EndIf}

; Remove registry keys
DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\MTC"
DeleteRegKey HKLM "SOFTWARE\MTC" 

; Remove files and uninstaller
Delete $INSTDIR\olive
Delete $INSTDIR\uninstall.exe
Delete $INSTDIR\MTC.exe
Delete $INSTDIR\libgcc_s_dw2-1.dll
Delete $INSTDIR\mingwm10.dll 
Delete $INSTDIR\QtCore4.dll        
Delete $INSTDIR\QtGui4.dll  
Delete $INSTDIR\QtSql4.dll  
Delete $INSTDIR\QtNetwork4.dll   
Delete $INSTDIR\MTC.chm
Delete $INSTDIR\logo.ico
Delete $INSTDIR\sqldrivers\qsqlite4.dll

;delete driver file
Delete $INSTDIR\drivers\x64\dpinst.xml
Delete $INSTDIR\drivers\x64\dpinst.exe
Delete $INSTDIR\drivers\x64\Olive_USB_BusEnum.cat
Delete $INSTDIR\drivers\x64\Olive_USB_BusEnum.inf
Delete $INSTDIR\drivers\x64\Olive_USB_BusEnum.sys
Delete $INSTDIR\drivers\x64\Olive_USB_ETS.cat
Delete $INSTDIR\drivers\x64\Olive_USB_ETS.inf
Delete $INSTDIR\drivers\x64\Olive_USB_ETS.sys
Delete $INSTDIR\drivers\x64\Olive_USB_MODEM.cat
Delete $INSTDIR\drivers\x64\Olive_USB_MODEM.inf
Delete $INSTDIR\drivers\x64\Olive_USB_MODEM.sys
Delete $INSTDIR\drivers\x64\Olive_USB_WinMux.cat
Delete $INSTDIR\drivers\x64\Olive_USB_WinMux.inf
Delete $INSTDIR\drivers\x64\Olive_USB_WinMux.sys
Delete $INSTDIR\drivers\x86\dpinst.xml
Delete $INSTDIR\drivers\x86\dpinst.exe
Delete $INSTDIR\drivers\x86\Olive_USB_BusEnum.cat
Delete $INSTDIR\drivers\x86\Olive_USB_BusEnum.inf
Delete $INSTDIR\drivers\x86\Olive_USB_BusEnum.sys
Delete $INSTDIR\drivers\x86\Olive_USB_ETS.cat
Delete $INSTDIR\drivers\x86\Olive_USB_ETS.inf
Delete $INSTDIR\drivers\x86\Olive_USB_ETS.sys
Delete $INSTDIR\drivers\x86\Olive_USB_MODEM.cat
Delete $INSTDIR\drivers\x86\Olive_USB_MODEM.inf
Delete $INSTDIR\drivers\x86\Olive_USB_MODEM.sys
Delete $INSTDIR\drivers\x86\Olive_USB_WinMux.cat
Delete $INSTDIR\drivers\x86\Olive_USB_WinMux.inf
Delete $INSTDIR\drivers\x86\Olive_USB_WinMux.sys
Delete $INSTDIR\drivers\modem.exe
Delete $INSTDIR\drivers\psexec.exe

; Remove shortcuts, if any
Delete "$SMPROGRAMS\MTC\Olive\MTCDialer\MTC.lnk"
Delete "$SMPROGRAMS\MTC\Olive\MTCDialer\Uninstall.lnk"
Delete "$DESKTOP\MTC.lnk"
Delete "$QUICKLAUNCH\MTC.lnk"

; Remove directories used
RMDir "$SMPROGRAMS\MTC\Olive\MTCDialer"
RMDir "$SMPROGRAMS\MTC\Olive"
RMDir "$SMPROGRAMS\MTC"

RMDir "$INSTDIR\drivers\x86"
RMDir "$INSTDIR\drivers\x64"
RMDir "$INSTDIR\drivers"
RMDir "$INSTDIR\sqldrivers"
RMDir "$INSTDIR"
RMDir "$PROGRAMFILES32\MTC\"

SectionEnd
