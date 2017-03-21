#include <stdlib.h>

#include "mib-init.h"
#include "ber.h"
#include "utils.h"
#include "logging.h"

#if CONTIKI_TARGET_AVR_RAVEN && ENABLE_PROGMEM
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif

/* common oid prefixes*/
static u8t ber_oid_system_desc[] PROGMEM  = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00};
static ptr_t oid_system_desc PROGMEM      = {ber_oid_system_desc, 8};
static u8t ber_oid_system_uptime[] PROGMEM  = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x03, 0x00};
static ptr_t oid_system_uptime PROGMEM      = {ber_oid_system_uptime, 8};
static u8t ber_oid_system_name[] PROGMEM   = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x05, 0x00};
static ptr_t oid_system_name PROGMEM       = {ber_oid_system_name, 8};
static u8t ber_oid_system_temperature[] PROGMEM  = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x0A, 0x00};
static ptr_t oid_system_temperature PROGMEM      = {ber_oid_system_temperature, 8};
static u8t ber_oid_system_current[] PROGMEM  = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x0B, 0x00};
static ptr_t oid_system_current PROGMEM      = {ber_oid_system_current, 8};
static u8t ber_oid_system_voltage[] PROGMEM  = {0x2b, 0x06, 0x01, 0x02, 0x01, 0x01, 0x0C, 0x00};
static ptr_t oid_system_voltage PROGMEM      = {ber_oid_system_voltage, 8};




s8t getSysDescr(mib_object_t* object, u8t* oid, u8t len)
{
    if (!object->varbind.value.p_value.len) {
        object->varbind.value.p_value.ptr = (u8t*)"System Description";
        object->varbind.value.p_value.len = 18;
    }
    return 0;
}

s8t getTimeTicks(mib_object_t* object, u8t* oid, u8t len)
{
    object->varbind.value.u_value = 1234;
    return 0;
}

s8t getSysName(mib_object_t* object, u8t* oid, u8t len)
{
    if (!object->varbind.value.p_value.len) {
        object->varbind.value.p_value.ptr = (u8t*)"Sensor1";
        object->varbind.value.p_value.len = 7;
    }
    return 0;
}

s8t getSysTemperature(mib_object_t* object, u8t* oid, u8t len)
{
    if (!object->varbind.value.p_value.len) {
        object->varbind.value.p_value.ptr = (u8t*)10;
        object->varbind.value.p_value.len = 4;
    }
    return 0;
}

s8t getSysVoltage(mib_object_t* object, u8t* oid, u8t len)
{
    if (!object->varbind.value.p_value.len) {
        object->varbind.value.p_value.ptr = (u8t*)5;
        object->varbind.value.p_value.len = 2;
    }
    return 0;
}

s8t getSysCurrent(mib_object_t* object, u8t* oid, u8t len)
{
    if (!object->varbind.value.p_value.len) {
        object->varbind.value.p_value.ptr = (u8t*)2;
        object->varbind.value.p_value.len = 2;
    }
    return 0;
}


/*-----------------------------------------------------------------------------------*/
/*
 * Initialize the MIB.
 */
s8t mib_init()
{
    if (add_scalar(&oid_system_desc, 0, BER_TYPE_OCTET_STRING, 0, &getSysDescr, 0) == -1) {
            return -1;
        }
    if (add_scalar(&oid_system_uptime, 0, BER_TYPE_TIME_TICKS, 0, &getTimeTicks, 0) == -1) {
            return -1;
        }
    if (add_scalar(&oid_system_name, 0, BER_TYPE_OCTET_STRING, 0, &getSysName, 0) == -1) {
            return -1;
        }
    
   

    if (add_scalar(&oid_system_temperature, 0, BER_TYPE_INTEGER, 0, &getSysTemperature, 0) == -1) {
            return -1;
        }
    if (add_scalar(&oid_system_current, 0, BER_TYPE_INTEGER, 0, &getSysVoltage, 0) == -1) {
            return -1;
        }
   if (add_scalar(&oid_system_voltage, 0, BER_TYPE_INTEGER, 0, &getSysCurrent, 0) == -1) {
            return -1;
        }

    return 0;
}
