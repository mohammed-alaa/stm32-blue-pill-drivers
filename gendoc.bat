@ECHO OFF
ECHO "Deleting old documentation..."
@RD /S /Q ".\docs"
ECHO "Generating new documentation..."
doxygen Doxyfile
SETLOCAL
CALL .\docs\latex\make.bat
ENDLOCAL
COPY /Y ".\docs\latex\refman.pdf" ".\docs\pdf\documentation.pdf"
@RD /S /Q ".\docs\latex"
