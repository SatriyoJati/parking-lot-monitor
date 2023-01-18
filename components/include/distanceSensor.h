#include "stdio.h"
#include <stdint.h>

#ifndef DISTANCESENSOR_H
#define DISTANCCESENSOR_H
typedef struct 
{
    int distance;
    char* sensorID;
    uint8_t trig_pin;
    uint8_t echo_pin;
    char* nameSensor;
}Distance_Sensor;

int initialize_sensor_pin(Distance_Sensor* Sensor);

int calculate_distance(Distance_Sensor* Sensor);

#endif