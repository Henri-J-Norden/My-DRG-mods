move "Input.pak" %mod%.pak
"%PROGRAMFILES%/7-Zip-Zstandard/7z.exe" a -tzip %mod%.zip %mod%.pak

@REM // Make mod dir and move mod .pak there
md %moveTo% 2> nul
move %mod%.pak %moveTo%\%mod%.pak