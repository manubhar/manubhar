
/*****************************************************************************
 *    Header File:  B550003A.h
 *
 *    Description:  PREIT File Copy Header File
 *
 *        History:
 *          Date        Programmer  SAR# - Description
 *          ----------  ----------  -------------------------------------------
 *   Author 4/13/2005   PREITDEV08  Unknown  - Created  
 *
 *
 * Copyright (c) J.D. Edwards World Source Company, 1996
 *
 * This unpublished material is proprietary to J.D. Edwards World Source 
 * Company.  All rights reserved.  The methods and techniques described 
 * herein are considered trade secrets and/or confidential.  Reproduction
 * or distribution, in whole or in part, is forbidden except by express
 * written permission of J.D. Edwards World Source Company.
 ****************************************************************************/

#ifndef __B550003A_H
#define __B550003A_H

/*****************************************************************************
 * Table Header Inclusions
 ****************************************************************************/

/*****************************************************************************
 * External Business Function Header Inclusions
 ****************************************************************************/

/*****************************************************************************
 * Global Definitions
 ****************************************************************************/

/*****************************************************************************
 * Structure Definitions
 ****************************************************************************/

/*****************************************************************************
 * DS Template Type Definitions
 ****************************************************************************/

/*****************************************
 * TYPEDEF for Data Structure
 *    Template Name: PREIT File Copy long
 *    Template ID:   D550003A
 *    Generated:     Thu Nov 30 10:51:48 2006
 *
 * DO NOT EDIT THE FOLLOWING TYPEDEF
 *    To make modifications, use the OneWorld Data Structure
 *    Tool to Generate a revised version, and paste from
 *    the clipboard.
 *
 **************************************/
/**
 * TYPEDEF for Data Structure
 * D550003A : PREIT File Copy
 *
 * Copyright Oracle USA
 *
 * This is a JDEdwards EnterpriseOne generated file.
 * Do not modify this file.
 * Only re-generate with the appropriate tool.
 * Generation Date : 3/24/2018
 */

#ifndef DATASTRUCTURE_D550003A
#define DATASTRUCTURE_D550003A

typedef struct tagDSD550003A
{
  JCHAR          szFromPath[256];
  JCHAR          szToPath[256];
  JCHAR          szFromFileName[51];
  JCHAR          cMode;
  JCHAR          cFlag;
  JCHAR          szToFileName[101];
} DSD550003A , *LPDSD550003A;

#define IDERRszFromPath_1                         1L
#define IDERRszToPath_2                           2L
#define IDERRszFromFileName_10                    10L
#define IDERRcMode_13                             13L
#define IDERRcFlag_14                             14L
#define IDERRszToFileName_16                      16L

#endif /* DATASTRUCTURE_D550003A */

/*****************************************************************************
 * Source Preprocessor Definitions
 ****************************************************************************/
#if defined (JDEBFRTN)
	#undef JDEBFRTN
#endif

#if defined (WIN32)
	#if defined (WIN32)
		#define JDEBFRTN(r) __declspec(dllexport) r
	#else
		#define JDEBFRTN(r) __declspec(dllimport) r
	#endif
#else
	#define JDEBFRTN(r) r
#endif

/*****************************************************************************
 * Business Function Prototypes
 ****************************************************************************/
JDEBFRTN (ID) JDEBFWINAPI PREITCopyFileLong       (LPBHVRCOM lpBhvrCom, LPVOID lpVoid, LPDSD550003A lpDS);


/*****************************************************************************
 * Internal Function Prototypes
 ****************************************************************************/

#endif    /* __B550003A_H */

