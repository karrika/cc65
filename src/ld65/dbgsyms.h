/*****************************************************************************/
/*                                                                           */
/*				   dbgsyms.h				     */
/*                                                                           */
/*		   Debug symbol handing for the ld65 linker		     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998     Ullrich von Bassewitz                                        */
/*              Wacholderweg 14                                              */
/*              D-70597 Stuttgart                                            */
/* EMail:       uz@musoftware.de                                             */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/



#ifndef DBGSYMS_H
#define DBGSYMS_H



#include <stdio.h>

/* common */
#include "exprdefs.h"
#include "filepos.h"
	  
/* ld65 */
#include "objdata.h"



/*****************************************************************************/
/*     	       	    	      	     Data				     */
/*****************************************************************************/



/* Debug symbol structure */
typedef struct DbgSym_ DbgSym;
struct DbgSym_ {
    DbgSym*    	       	Next;  		/* Pool linear list link */
    unsigned   		Flags;		/* Generic flags */
    ObjData*   		Obj;	    	/* Object file that exports the name */
    FilePos    		Pos;		/* File position of definition */
    ExprNode*  		Expr;		/* Expression (0 if not def'd) */
    unsigned char	Type;		/* Type of symbol */
    char*      	       	Name;		/* Name - dynamically allocated */
};



/*****************************************************************************/
/*     	      	    		     Code			       	     */
/*****************************************************************************/



DbgSym* ReadDbgSym (FILE* F, ObjData* Obj);
/* Read a debug symbol from a file, insert and return it */

long GetDbgSymVal (DbgSym* D);
/* Get the value of this symbol */

void PrintDbgSymLabels (ObjData* O, FILE* F);
/* Print the debug symbols in a VICE label file */



/* End of dbgsyms.h */

#endif



				
