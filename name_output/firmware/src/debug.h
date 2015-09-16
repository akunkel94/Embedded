/* 
 * File:   debug.h
 * Author: root
 *
 * Created on September 16, 2015, 2:33 PM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

#ifdef	__cplusplus
extern "C" {
#endif

void Debug_Initialize ( void );
void dbgOutputState(unsigned int state);


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

