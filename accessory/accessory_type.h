/****************************************************************************
 *
 * MODULE:             accessory_type.h
 *
 * COMPONENT:          homekit interface
 *
 * REVISION:           $Revision:  1.0$
 *
 * DATED:              $Date: 2017-01-11 15:13:17 +0100 (Fri, 12 Dec 2016 $
 *
 * AUTHOR:             PCT
 *
 ****************************************************************************
 *
 * Copyright panchangtao@gmail.com 2017. All rights reserved
 *
 ***************************************************************************/

#ifndef __H_ACCESSORY_TYPE_H_
#define __H_ACCESSORY_TYPE_H_

#if defined __cplusplus   
extern "C" {
#endif
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "utils.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum{
    E_HAP_TYPE_UNKONWN              = 0,
    E_HAP_TYPE_OTHER                = 1,
    E_HAP_TYPE_BRIDGE               = 2,
    E_HAP_TYPE_FAN                  = 3,
    E_HAP_TYPE_GARAGE_DOOR_OPENER   = 4,
    E_HAP_TYPE_LIGHT_BULB           = 5,
    E_HAP_TYPE_DOOR_LOOK            = 6,
    E_HAP_TYPE_OUTLET               = 7,
    E_HAP_TYPE_SWITCH               = 8,
    E_HAP_TYPE_THERMOSTAT           = 9,
    E_HAP_TYPE_SENSOR               = 10,
    E_HAP_TYPE_ALARM_SYSTEM         = 11,
    E_HAP_TYPE_DOOR                 = 12,
    E_HAP_TYPE_WINDOW               = 13,
    E_HAP_TYPE_WINDOW_COVERING      = 14,
    E_HAP_TYPE_PROGRAMMALBE_SWITCH  = 15,
    E_HAP_TYPE_IP_CAMERA            = 17,
} teAccessoryType;


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local    Functions                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif /*__H_ACCESSORY_TYPE_H_*/


