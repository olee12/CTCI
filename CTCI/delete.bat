@echo off
@setlocal 

set start=%time%
del /S *.class
del /S *.o
del /S *.exe
cmd /c %*

set end=%time%