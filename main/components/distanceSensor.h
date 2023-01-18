typedef struct 
{
    int distance;
    char* sensorID;
    uint8_t trig_pin;
    uint8_t echo_pin;
    char* nameSensor;
}Distance_Sensor;

int initialize_sensor(Distance_sensor* input);

int calculate_distance(Distance_sensor* input);