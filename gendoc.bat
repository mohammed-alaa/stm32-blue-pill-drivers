@ECHO OFF
ECHO "Deleting old documentation..."
@RD /S /Q ".\docs"
ECHO "Generating new documentation..."
doxygen Doxyfile
@RD /S /Q ".\docs\html"
SETLOCAL
CALL .\docs\latex\make.bat
ENDLOCAL
COPY /Y ".\docs\latex\refman.pdf" ".\docs\docs.pdf"
@RD /S /Q ".\docs\latex"
