@echo off
CLS
SETLOCAL EnableDelayedExpansion
SET t=2&if "%date%z" LSS "A" set t=1
For /f "skip=1 tokens=2-4 delims=(-)" %%A in ('echo/^|date') do (
  For /f "tokens=%t%-4 delims=.-/ " %%J in ('date/t') do (
		SET %%A=%%J
		SET %%B=%%K
		SET %%C=%%L
	)
)
SET "author=Mohamed Alaa"
SET "dateFormat=!yy!-!mm!-!dd!"
ECHO	[1] = Module
ECHO	[2] = Testing Application
SET /p "choice=What do you want to generate? "

IF !choice! NEQ 1 (
	IF !choice! NEQ 2 (
		echo Invalid choice!
		ENDLOCAL
		EXIT /B 1
	)
)

IF !choice! EQU 1 (
	ECHO	[1] = MCAL
	ECHO	[2] = HAL
	SET /p "modulePathOption=What is the path of the module? "

	IF !modulePathOption! NEQ 1 (
		IF !modulePathOption! NEQ 2 (
			echo Invalid path!
			ENDLOCAL
			EXIT /B 1
		)
	)

	IF !modulePathOption! EQU 1 (
		SET modulePath=MCAL
	)

	IF !modulePathOption! EQU 2 (
		SET modulePath=HAL
	)

	SET /p "moduleName=What is the name of the module? "
	SET "moduleCompletePath=.\src\COTS\!modulePath!\!moduleName!"
	SET "moduleFilesCompletePath=!moduleCompletePath!\!moduleName!"

	:: Make directory for module
	MKDIR !moduleCompletePath!

	@REM :: Create <moduleName>_interface.h
	SET "targetFileNamePostfix=_interface.h"
	SET "targetFile=!moduleFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !moduleName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file is the interface file for the !moduleName! module.>> !targetFile!
	ECHO  * @details This file contains the prototypes of the functions of the !moduleName! module.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #ifndef _!moduleName!_INTERFACE_H_>> !targetFile!
	ECHO #define _!moduleName!_INTERFACE_H_>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #endif /* _!moduleName!_INTERFACE_H_ */>> !targetFile!

	@REM :: Create <moduleName>_private.h
	SET "targetFileNamePostfix=_private.h"
	SET "targetFile=!moduleFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !moduleName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file contains the private macros and registers for the !moduleName! module.>> !targetFile!
	ECHO  * @details This file contains the private macros and registers for the !moduleName! module.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #ifndef _!moduleName!_PRIVATE_H_>> !targetFile!
	ECHO #define _!moduleName!_PRIVATE_H_>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #endif /* _!moduleName!_PRIVATE_H_ */>> !targetFile!

	@REM :: Create <moduleName>_config.h
	SET "targetFileNamePostfix=_config.h"
	SET "targetFile=!moduleFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !moduleName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file contains the configuration parameters for the !moduleName! module.>> !targetFile!
	ECHO  * @details This file contains the configuration parameters for the !moduleName! module.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #ifndef _!moduleName!_CONFIG_H_>> !targetFile!
	ECHO #define _!moduleName!_CONFIG_H_>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #include "!moduleName!_interface.h">> !targetFile!
	ECHO.>> !targetFile!
	ECHO #endif /* _!moduleName!_CONFIG_H_ */>> !targetFile!

	@REM :: Create <moduleName>_program.c
	SET "targetFileNamePostfix=_program.c"
	SET "targetFile=!moduleFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !moduleName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file contains the implementation for the !moduleName! module.>> !targetFile!
	ECHO  * @details This file contains the implementation for the !moduleName! module.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #include "!moduleName!_private.h">> !targetFile!
	ECHO #include "!moduleName!_interface.h">> !targetFile!
	ECHO #include "!moduleName!_config.h">> !targetFile!
	ECHO.>> !targetFile!

	ENDLOCAL
	EXIT /B 0
)

IF !choice! EQU 2 (
	SET /p "testingAppName=What is the name of the testing application? "
	SET completeTestingAppName=TestApp_!testingAppName!
	SET "testingAppCompletePath=.\src\APPS\!testingAppName!"
	SET "testingAppFilesCompletePath=!testingAppCompletePath!\!completeTestingAppName!"

	:: Make directory for module
	MKDIR !testingAppCompletePath!

	@REM :: Create <testingAppName>_main.h
	SET "targetFileNamePostfix=_main.h"
	SET "targetFile=!testingAppFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !completeTestingAppName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file contains the main header file for the !completeTestingAppName! application.>> !targetFile!
	ECHO  * @details This file contains the main header file for the !completeTestingAppName! application.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #ifndef _!completeTestingAppName!_MAIN_H_>> !targetFile!
	ECHO #define _!completeTestingAppName!_MAIN_H_>> !targetFile!
	ECHO.>> !targetFile!
	ECHO void v!completeTestingAppName!_main^(void^);>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #endif /* _!completeTestingAppName!_MAIN_H_ */>> !targetFile!

	@REM :: Create <testingAppName>_main.c
	SET "targetFileNamePostfix=_main.c"
	SET "targetFile=!testingAppFilesCompletePath!!targetFileNamePostfix!"
	ECHO /**>> !targetFile!
	ECHO  * @file !completeTestingAppName!!targetFileNamePostfix!>> !targetFile!
	ECHO  * @author !author!>> !targetFile!
	ECHO  * @version 1.0.0>> !targetFile!
	ECHO  * @brief This file contains the main implementation for the !completeTestingAppName! application.>> !targetFile!
	ECHO  * @details This file contains the main implementation for the !completeTestingAppName! application.>> !targetFile!
	ECHO  * @date !dateFormat!>> !targetFile!
	ECHO  */>> !targetFile!
	ECHO.>> !targetFile!
	ECHO #include "!completeTestingAppName!_main.h">> !targetFile!
	ECHO.>> !targetFile!
	ECHO void v!completeTestingAppName!_main^(void^)>> !targetFile!
	ECHO {>> !targetFile!
	ECHO.>> !targetFile!
	ECHO 	for ^(;;^)>> !targetFile!
	ECHO 	{>> !targetFile!
	ECHO 		/* Do nothing */>> !targetFile!
	ECHO 	}>> !targetFile!
	ECHO }>> !targetFile!

	ENDLOCAL
	EXIT /B 0
)
ENDLOCAL
