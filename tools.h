/* file: tools.h ------------------------------------------------------------- */
/* header file for the tools library.                                          */
/* --------------------------------------------------------------------------- */
/* Local definitions and portability code.                                     */
/* Please enter your own system, name, class, and printer stream name.         */
/* --------------------------------------------------------------------------- */
#ifndef TOOLS_C
#define TOOLS_C

#define UNIX            /* or VISUAL */
#define NAME    "Put Your Own Name Here"
#define CLASS   "CSCI 2212"

#include <stdio.h>
#include <stdlib.h>     /* for malloc() and calloc()*/
#include <math.h>
#include <string.h>     /* for time_t, time() and ctime()*/
#include <time.h>
#include <ctype.h>      /* for isspace() and isdigit() */
#include <limits.h>     /* for INT_MAX */
#include <float.h>      /* for DOUBLE_MAX, etc. */
#include <stdarg.h>     /* for functions with variable # of arguments */
#include <stdbool.h>    /* for boolean type */
#include <unistd.h>     /* for usleep */

typedef char * cstring;
typedef const char * const_cstring;
typedef FILE * cstream;

/* --------------------------------------------------------------------------- */
/* Macros to make more convenient use of standard library functions.           */
/* --------------------------------------------------------------------------- */
#define strequal(a,b)   	!strcmp(a,b)
#define strnequal(a,b,n)  	!strncmp(a,b,n)

/* --------------------------------------------------------------------------- */
/* Portable definition; requires user to #define name of local system.         */
/* --------------------------------------------------------------------------- */
void    clearscreen( void );

/* --------------------------------------------------------------------------- */
/* Routine screen and process management.------------------------------------- */
/* --------------------------------------------------------------------------- */
void    fbanner(cstream sout );
void    banner( void );
void    say( const_cstring format, ... );
void 	delay ( int );	// seconds to wait
void 	mdelay( int );	// milliseconds to wait
void    hold( void );
void    bye( void );

/* --------------------------------------------------------------------------- */
/* Error handling. ----------------------------------------------------------- */
/* --------------------------------------------------------------------------- */
int     fatal( const_cstring format, ... );
void    cleanline( cstream sin );
void 	clean_and_log( cstream sin, cstream sout );

/* --------------------------------------------------------------------------- */
/* Time and date. -------------------------------------------------------------*/
/* --------------------------------------------------------------------------- */
void    when( char date[], char hour[] );
cstring  today( char date[] );
cstring  oclock( char hour[] );

#endif
