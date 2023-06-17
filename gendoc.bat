@echo off
echo "Deleting old documentation..."
@RD /S /Q "./docs"
echo "Generating new documentation..."
doxygen Doxyfile
.\docs\latex\make.bat
