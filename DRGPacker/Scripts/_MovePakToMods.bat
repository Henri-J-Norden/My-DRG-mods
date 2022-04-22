move "Input.pak" %mod%.pak

@REM // Make mod dir and move mod .pak there
md %moveTo% 2> nul
move %mod%.pak %moveTo%\%mod%.pak