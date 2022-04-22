@if "%~1"=="" goto skip

@setlocal enableextensions
@pushd %~dp0
@echo "%~1\*.*" "..\..\..\FSD\*.*" > autogen.txt
".\UnrealPak\Engine\Binaries\Win64\UnrealPak.exe" "%~1.pak" -platform="Windows" -create="%CD%\autogen.txt" -compress
@popd
@rem pause

:skip