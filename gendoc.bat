@ECHO OFF
ECHO "Deleting old documentation..."
@RD /S /Q ".\docs\html"
@RD /S /Q ".\docs\latex"
@RD /S /Q ".\local_docs"
ECHO "Generating new documentation..."
doxygen Doxyfile
SETLOCAL
CALL .\docs\latex\make.bat
ENDLOCAL
MKDIR ".\local_docs\html"
MOVE /Y ".\docs\html" ".\local_docs\html
MKDIR ".\local_docs\pdf"
COPY /Y ".\docs\latex\refman.pdf" ".\local_docs\pdf\documentation.pdf"
@RD /S /Q ".\docs\latex"
