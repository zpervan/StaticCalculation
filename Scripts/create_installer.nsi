; Include Modern UI

  !include "MUI2.nsh"
  !include "FileFunc.nsh"

; General

  ; Defines
  !define PRODUCT_NAME "Statika Torzo"
  !define PRODUCT_FILE "StatikaTorzo"

  ; Properly display all languages (Installer will not work on Windows 95, 98 or ME!)
  Unicode true

  ; Name and file
  Name "Statika Torzo"
  OutFile "StatikaTorzo.exe"

  ; Default installation folder - install directory path - C:\Program files\Statika Torzo
  InstallDir "$PROGRAMFILES\StatikaTorzo"
  
  ; Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\StatikaTorzo" ""

  ; Request application privileges for Windows Vista
  RequestExecutionLevel admin

; Pages
  !insertmacro MUI_PAGE_WELCOME
  !insertmacro MUI_PAGE_LICENSE "InstallerComponents\License.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH
  
; Language
  !insertmacro MUI_LANGUAGE "Croatian"

; Installer Sections

Section -Prerequisites
  SetOutPath $INSTDIR\InstallerComponents
  MessageBox MB_YESNO "Instaliraj dodatne programske pakete?" IDYES true IDNO false
  true:
    File "InstallerComponents\VC_redist.x64.exe"
    ExecWait "$INSTDIR\InstallerComponents\VC_redist.x64.exe"
    Goto end_components_installation
  false:
    DetailPrint "Skipping installing additional packages"

  end_components_installation:
SectionEnd

Section "Aplikacija"
  SetOutPath $INSTDIR

  ; Copy the application
  File /nonfatal /a /r StatikaTorzo

  ; Create desktop shortcut
  CreateShortCut "$DESKTOP\${PRODUCT_NAME}.lnk" "$INSTDIR\StatikaTorzo\${PRODUCT_FILE}.exe" ""
  
  ; Store installation folder
  WriteRegStr HKCU "Software\StatikaTorzo" "" $INSTDIR
  
  ; Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

  ; Clean-Up
  RMDir /r "$INSTDIR\InstallerComponents"

SectionEnd

; Uninstaller Section

Section "Uninstall"

  RMDir /r "$INSTDIR\StatikaTorzo"
  Delete "$INSTDIR\Uninstall.exe"
  DeleteRegKey /ifempty HKCU "Software\StatikaTorzo"

SectionEnd