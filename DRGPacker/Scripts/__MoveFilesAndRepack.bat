@echo off
set target="Input\"
set source="..\WindowsNoEditor\FSD\"
set moveTo="C:\Program Files (x86)\Steam\steamapps\common\Deep Rock Galactic\FSD\Mods"\%mod%\

REM // Cleanup %target%
md %target% 2> nul
@echo on
del %target%\AssetRegistry.bin
copy %source%AssetRegistry.bin %target%AssetRegistry.bin

rd /s /q %target%\Content
md %target%\Content 2> nul

@REM // Copy modDirs to %target%\Content
del __fileCopyLog.txt
(for %%d in (%modDirs%) do (
   (echo D|xcopy %source%\Content\%%d %target%\Content\%%d /E /D) >> __fileCopyLog.txt
))

@echo off
REM // Get abs path for _Repack.bat
rem // Save current directory and change to target directory
pushd %target%
rem // Save value of CD variable (current directory)
set ABS_TARGET=%CD%
rem // Restore original directory
popd
@echo on

call _Repack.bat %ABS_TARGET%

move "Input.pak" %mod%.pak

@REM // Make mod dir and move mod .pak there
md %moveTo% 2> nul
move %mod%.pak %moveTo%\%mod%.pak

pause