/**************************************
 * File: debug.h
 * Author: Andreas Fröderberg
 * Description: Header file containing debug print macros. To enable debug
 * prints, #define DEBUG_PRINT. This can be done with compile flag -D
 * DEBUG_PRINT
 ***************************************/

// *** Macros ***
#ifndef DEBUG_H
#define DEBUG_H 

#ifdef DEBUG_PRINT
    #define DBG_PRINT(s) printf("%s\n", s); // Just print string given
    #define DBG_PRINT_FUN(s) printf("(-- Function %s() --)\n", s); // Print with formatting for showing function
    #define DBG_PRINT_CLASS(f, c) printf("<-- Function %s in class %s -->\n", f, c); // Print with formatting for showing class
#else
    #define DBG_PRINT(s);
    #define DBG_PRINT_FUN(s);
    #define DBG_PRINT_CLASS(f, c);
#endif

#endif /* ifndef DEBUG_H */
