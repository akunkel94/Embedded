/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_public.h"
#include "app_timer.h"
#include "debug.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
QueueHandle_t xQueue = NULL;
unsigned char Name[16] = {'C', 'H', 'R', 'I', 'S', 'T', 'I', 'A', 'N',
                        ' ', 'W', 'E', 'N', 'D', 'T', ' '};
unsigned int counter = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, 
                                    0x00FF);
    
    xQueue =  xQueueCreate(10, sizeof( unsigned char ) );
    if(xQueue == 0)        
    {
        ErrorRoutine();
    }
    
    Timer_Initialize();
    
   /* TimerHandle_t xtimer = NULL;
    TickType_t period = ( 50 / portTICK_PERIOD_MS);
    
    xtimer = xTimerCreate("Timer", period, pdTRUE, 0, TimerCallback);
    xTimerStart(xtimer, 0);*/
    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        unsigned char value;
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            for(;;)
            {
                xQueueReceive( xQueue, &value, portMAX_DELAY );
                PLIB_PORTS_Write (PORTS_ID_0, PORT_CHANNEL_E, value);
            }
            break;
        }

        /* TODO: implement your application state machine.*/

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

int sendMsgToQ( void )
{
    unsigned char value;
    value = Name[counter];
    xQueueSend( xQueue, &value, 0 );
    counter++;
    if(counter == 16)
    {
        counter = 0;
    }
}

void ErrorRoutine( void )
{
    for(;;)
    {
        
    }
}
 
/*void TimerCallback(TimerHandle_t xTimer)
{
    unsigned char value;
    value = Name[counter];
    xQueueSend( xQueue, &value, 0 );
    counter++;
    if(counter == 16)
    {
        counter = 0;
    }
}*/

/*******************************************************************************
 End of File
 */
