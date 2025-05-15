# define the name of the installer
Outfile "IEEE11073Analyser.exe"
Icon "IEEE11073Analyser\health.ico"

InstallDir $TEMP\IEEE11073AnalyserSetup

AutoCloseWindow true

# default section
Section

HideWindow

SetOutPath $INSTDIR

File /r IEEE11073AnalyserSetup\Release\*.*
nsExec::Exec "$INSTDIR\Setup.exe"

RMDir /r "$INSTDIR"

SectionEnd
