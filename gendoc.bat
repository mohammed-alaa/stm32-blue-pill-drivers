@ECHO OFF
ECHO "Deleting old documentation..."
@RD /S /Q ".\docs\html"
@RD /S /Q ".\docs\latex"
ECHO "Generating new documentation..."
doxygen Doxyfile
SETLOCAL
CALL .\docs\latex\make.bat
ENDLOCAL
MKDIR ".\docs\html\docs\pdf"
COPY /Y ".\docs\latex\refman.pdf" ".\docs\html\docs\pdf\documentation.pdf"
@RD /S /Q ".\docs\latex"
