#ifndef DISTANCESENSOR_H
#define DISTANCCESENSOR_H

#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

typedef struct 
{
    int distance;
    char* sensorID;
    uint32_t trig_pin;
    uint32_t echo_pin;
    char* nameSensor;

    uint64_t start_echo;
    uint64_t stop_echo;
    
}Distance_Sensor;

extern Queue_Type_t xEcho_TimeStamp;
extern Queue_Type_t xTrigger_Command;

esp_err_t initialize_sensor_pin( Distance_Sensor* Sensor);

esp_err_t send_trigger_command(Distance_Sensor* Sensor);

int calculate_distance( Distance_Sensor* Sensor);

#endif