#include "debug.h"

void Debug_Initialize ( void )
{
     PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, 
                                    0x00FF);
}

void dbgOutputState(unsigned int state)
{
     PLIB_PORTS_Write (PORTS_ID_0, PORT_CHANNEL_E, state);
}
