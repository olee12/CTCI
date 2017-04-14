@echo off
@setlocal 

set start=%time%
del /S *.class
cmd /c %*

set end=%time%