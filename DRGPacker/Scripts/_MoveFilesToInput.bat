@REM // Cleanup %target%
md %target% 2> nul
del %target%\AssetRegistry.bin
copy %source%AssetRegistry.bin %target%AssetRegistry.bin

rd /s /q %target%\Content
md %target%\Content 2> nul

@REM // Copy modDirs to %target%\Content
del __fileCopyLog.txt
(for %%d in (%modDirs%) do (
   (echo D|xcopy %source%\Content\%%d %target%\Content\%%d /E /D) >> __fileCopyLog.txt
))