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