set modDirs=ModMOTD DRGLib UI\Menu_Options ModHub _ModHub
set mod="MOTD_standalone"

@set scriptDir="Scripts\"

@call %scriptDir%\Vars.bat
@call %scriptDir%\_MoveFilesToInput.bat
del %target%\Content\DRGLib\Trapcard\LIB_O_TrapCard.*
@call %scriptDir%\_Repack.bat
@call %scriptDir%\_MovePakToMods.bat
@call %scriptDir%\_RunGame.bat
