set modDirs=ModMOTD DRGLib UI\Menu_Options ModHub _ModHub
set mod="MOTD_standalone"

@set scriptDir="Scripts\"

@call %scriptDir%\Vars.bat
@call %scriptDir%\_MoveFilesToInput.bat
del %target%\Content\DRGLib\Trapcard\LIB_O_TrapCard.*
@call %scriptDir%\_Repack.bat
"%PROGRAMFILES%/7-Zip/7z.exe" a -tzip Input.zip Input.pak
rm Input.pak