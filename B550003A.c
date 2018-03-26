#include <jde.h>
#include <io.h>

#define b550003A_c


/*****************************************************************************
 *    Source File:  b550003A
 *
 *    Description:  PREIT File Copy Source File
 *
 *        History:
 *          Date        Programmer  SAR# - Description
 *          ----------  ----------  -------------------------------------------
 *   Author 4/13/2005   PREITDEV10  Unknown  - Created  
 *
 * Copyright (c) J.D. Edwards World Source Company, 1996
 *
 * This unpublished material is proprietary to J.D. Edwards World Source Company.
 * All rights reserved.  The methods and techniques described herein are
 * considered trade secrets and/or confidential.  Reproduction or
 * distribution, in whole or in part, is forbidden except by express
 * written permission of J.D. Edwards World Source Company.
 ****************************************************************************/
/**************************************************************************
 * Notes:
 *
 **************************************************************************/

#include <b550003A.h>


/**************************************************************************
 *  Business Function:  PREITCopyFileLong
 *
 *        Description:  PREIT Copy File Long
 *
 *         Parameters:
 *           LPBHVRCOM           lpBhvrCom    Business Function Communications
 *           LPVOID              lpVoid       Void Parameter - DO NOT USE!
 *           LPDSD550003A        lpDS         Parameter Data Structure Pointer 
 *
 *         lpDS->szFromPath is the path to the copied file, e.g c:\myfiles\
 *         lpDS->szToPath is the path to the new file, e.g. c:\mynewfiles\
 *         This function can only create two layers of directories
 *         If lpDS->toFileName is not blank, rename the copying file
 *         cMode = M Move the file. Default or C copy the file
 *
 *************************************************************************/

JDEBFRTN (ID) JDEBFWINAPI PREITCopyFileLong (LPBHVRCOM lpBhvrCom, LPVOID lpVoid, LPDSD550003A lpDS)  
{
   /************************************************************************
    *  Variable declarations
    ************************************************************************/	
	JCHAR	szTempPath[256];	
	int		iStrLength = 0;

	lpDS->cFlag = _J('0');
   /************************************************************************
    * Declare structures
    ************************************************************************/

   /************************************************************************
    * Declare pointers
    ************************************************************************/

   /************************************************************************
    * Check for NULL pointers
    ************************************************************************/
   if ((lpBhvrCom == (LPBHVRCOM) NULL) ||
       (lpVoid    == (LPVOID)    NULL) ||
       (lpDS      == (LPDSD550003A)	NULL))
   {
     jdeErrorSet (lpBhvrCom, lpVoid, (ID) 0, _J("4363"), (LPVOID) NULL);
     return ER_ERROR;
   }

   /************************************************************************
    * Set pointers
    ************************************************************************/

   /************************************************************************
    * Main Processing
    ************************************************************************/
   

   jdeStripTrailingBlanks(lpDS->szFromPath);
   jdeStripTrailingBlanks(lpDS->szToPath);
   jdeStripTrailingBlanks(lpDS->szFromFileName);

   if (IsStringBlank(lpDS->szToFileName)) 
	   jdeStrncpy(lpDS->szToFileName, lpDS->szFromFileName, DIM(lpDS->szToFileName));
   else   
	   jdeStripTrailingBlanks(lpDS->szToFileName);
   
   /* Build the full path to the file */
   jdeStrncat(lpDS->szFromPath, lpDS->szFromFileName, DIM(lpDS->szFromPath));
   /* If the from directory does not exist, return error */
   
    if (jdeAccess(lpDS->szFromPath, 0) != 0)
	{
		lpDS->cFlag = _J('1');
		return ER_ERROR;
	}
	else
	{
		/* check to see if the new directory exists */
		if (jdeAccess(lpDS->szToPath, 0) != 0) 
		{
			if(!(CreateDirectory(lpDS->szToPath, NULL)))
			{
				jdeStrncpy(szTempPath, lpDS->szToPath, DIM(szTempPath));
				/* Create directory and sub directory */
				iStrLength = jdeStrlen(szTempPath)-1;
				szTempPath[iStrLength] = _J(' ');

				while(szTempPath[iStrLength]!=_J('\\'))
				{
					szTempPath[iStrLength] = _J(' ');
					iStrLength--;
				}

				jdeStripTrailingBlanks(szTempPath);
				if(!(CreateDirectory(szTempPath, NULL))) 
				{
					lpDS->cFlag = _J('1');
					return ER_ERROR;
				}
				if(!(CreateDirectory(lpDS->szToPath, NULL))) 
				{
					lpDS->cFlag = _J('1');
					return ER_ERROR;
				}

			}
		}

		/* move/copy the file to the new direcotory */
		jdeStrncat(lpDS->szToPath, lpDS->szToFileName, DIM(lpDS->szFromPath));
		if (lpDS->cMode == _J('M') || lpDS->cMode == _J('m'))
		{
			if (!(MoveFile(lpDS->szFromPath, lpDS->szToPath)))
			{
				lpDS->cFlag = _J('1');
				return ER_ERROR;
			}			
		}
		else
		{
			
			if (!(CopyFile(lpDS->szFromPath, lpDS->szToPath, FALSE)))
			{
				lpDS->cFlag = _J('1');
				return ER_ERROR;
			}
		}
	}


   /************************************************************************
    * Function Clean Up
    ************************************************************************/

   return (ER_SUCCESS);
}

/* Internal function comment block */
/**************************************************************************
 *   Function:  Ixxxxxxx_a   // Replace "xxxxxxx" with source file number
 *                           // and "a" with the function name
 *      Notes:
 *
 *    Returns:
 *
 * Parameters:
 **************************************************************************/

