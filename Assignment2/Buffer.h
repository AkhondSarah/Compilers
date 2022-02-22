/*************************************************************
* REPLACE the file header below with your file header (see CST8152_ASSAMG.pdf for details).
* File Name: buffer.h
* Version: 1.20.1
* Author: S^R
* Date: 1 January 2020
* Preprocessor directives, type declarations and prototypes necessary for buffer implementation
* as required for CST8152-Assignment #1.
* The file is not completed.
* You must add your function declarations (prototypes).
* You must also add your constant definitions and macros,if any.
*/

#ifndef BUFFER_H_
#define BUFFER_H_

/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */

/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer) */
enum BUFFERMODES {
	MODE_FIXED = 'F',
	MODE_ADDIT = 'A',
	MODE_MULTI = 'M'
};

/* TO_DO: Adjust all constants to your Language */

#define BUFFER_ERROR (-1)				/* General error message */
#define BUFFER_EOF '\0'					/* General EOF */

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (IVA) .................................. */

#define IVA_DEFAULT_SIZE 100			/* default initial buffer capacity */
#define IVA_DEFAULT_INCREMENT 10		/* default increment factor */

/* You should add your own constant definitions here */
#define IVA_MAX_SIZE SHRT_MAX-1		/*maximum capacity*/ 

/* Add your bit-masks constant definitions here - Defined for IVA */
/**/
#define IVA_DEFAULT_FLAG 0xFC 	/* 1111.1100 */
#define IVA_SET_FLAG_RLC 0x02		/* 0000.0010 */
#define IVA_RST_FLAG_RLC 0xFD		/* 1111.1101 */
#define IVA_CHK_FLAG_RLC 0x02		/* 0000.0010 */
#define IVA_SET_FLAG_EOB 0x01		/* 0000.0001 */
#define IVA_RST_FLAG_EOB 0xFE		/* 1111.1110 */
#define IVA_CHK_FLAG_EOB 0x01		/* 0000.0001 */

/* TO_DO: Adjust to operate with MSB */
/*
#define YOURLANG_DEFAULT_FLAG		TO_DEFINE
#define YOURLANG_SET_FLAG_RLC		TO_DEFINE
#define YOURLANG_RST_FLAG_RLC		TO_DEFINE
#define YOURLANG_CHK_FLAG_RLC		TO_DEFINE
#define YOURLANG_SET_FLAG_EOB		TO_DEFINE
#define YOURLANG_RST_FLAG_EOB		TO_DEFINE
#define YOURLANG_CHK_FLAG_EOB		TO_DEFINE
*/

/* Logical constants - adapt for your language */
#define IVA_TRUE 1
#define IVA_FALSE 0

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (IVA) .................................. */

typedef short			iva_int;
typedef char			iva_chr;
typedef unsigned char	iva_flg;
typedef char			iva_bol;

/* user data type declarations */
typedef struct OffsetIva {
	iva_int addC;      /* the offset (in chars) to the add-character location */
	iva_int getC;      /* the offset (in chars) to the get-character location */
	iva_int mark;      /* the offset (in chars) to the mark location */
} Offset;

/* user data type declarations */
typedef struct BufferIva {
	iva_chr* string;         /* pointer to the beginning of character array (character buffer) */
	iva_int size;            /* current dynamic memory size (in bytes) allocated to character buffer */
	iva_int increment;       /* character array increment factor */
	iva_int mode;            /* operational mode indicator*/
	iva_flg flags;  /* contains character array reallocation flag and end-of-buffer flag */
	Offset offset;
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */

/* Function declarations */

BufferPointer bufferCreate(iva_int, iva_int, iva_int);
BufferPointer bufferAddChar(BufferPointer const, iva_chr);
iva_bol bufferRetract(BufferPointer const);
iva_bol bufferRestore(BufferPointer const);
iva_bol bufferRewind(BufferPointer const);
iva_bol bufferClean(BufferPointer const);
iva_bol bufferDestroy(BufferPointer const);

iva_bol bufferSetOffsetMark(BufferPointer const, iva_int);
iva_int bufferPrint(BufferPointer const);
iva_int bufferLoad(BufferPointer const, FILE* const);

iva_bol bufferCheckFull(BufferPointer const);
iva_bol bufferCheckEmpty(BufferPointer const);

iva_int bufferGetSize(BufferPointer const);
iva_int bufferGetOffsetAddC(BufferPointer const);
iva_int bufferGetOffsetMark(BufferPointer const);
iva_int bufferGetOffsetGetC(BufferPointer const);
iva_int bufferGetIncrement(BufferPointer const);
iva_int bufferGetMode(BufferPointer const);
iva_chr bufferGetChar(BufferPointer const);
iva_chr* bufferGetSubString(BufferPointer const, iva_int);
iva_flg bufferGetFlags(BufferPointer const);


#endif
