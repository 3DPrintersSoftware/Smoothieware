@for /f %%a in ('git describe') do @set myvar=%%a
@echo %myvar%
@copy /b  version.cpp+,, >NUL:

