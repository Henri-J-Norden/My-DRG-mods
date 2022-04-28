@set scriptDir="Scripts\"

@call %scriptDir%\Vars.bat
@call %scriptDir%\_MoveFilesToInput.bat
@call %scriptDir%\_Repack.bat
"%PROGRAMFILES%/7-Zip/7z.exe" a -tzip Input.zip Input.pak
@call %scriptDir%\_MovePakToMods.bat
@call %scriptDir%\_RunGame.bat
