/* 
 * File:   app_timer.h
 * Author: root
 *
 * Created on September 15, 2015, 1:34 PM
 */

#ifndef APP_TIMER_H
#define	APP_TIMER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    void Timer_Initialize ( void );
    void TimerCallback(TimerHandle_t xTimer);


#ifdef	__cplusplus
}
#endif

#endif	/* APP_TIMER_H */

