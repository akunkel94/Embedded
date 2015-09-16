#include "app_timer.h"
#include "app_public.h"

void Timer_Initialize ( void )
{
    TimerHandle_t xtimer = NULL;
    TickType_t period = ( 50 / portTICK_PERIOD_MS);
    
    xtimer = xTimerCreate("Timer", period, pdTRUE, 0, TimerCallback);
    if(xtimer == NULL)
    {
        ErrorRoutine();
    }
    xTimerStart(xtimer, 0);
}

void TimerCallback(TimerHandle_t xTimer)
{
    sendMsgToQ();
}