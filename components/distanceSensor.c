#include "distanceSensor.h"
#include "driver/gpio.h"

int initialize_sensor_pin(Distance_Sensor *Sensor)
{
    printf("Configuring the gpio pins for one sensor");
    esp_err_t status_config_echo_pin;
    // esp_err_t status_config_trig_pin;
    esp_err_t pins[1];

    pins[0] = gpio_set_direction(Sensor->trig_pin, GPIO_MODE_OUTPUT);
    pins[1] = gpio_set_direction(Sensor->echo_pin, GPIO_MODE_INPUT);

    status_config_echo_pin = gpio_set_intr_type(Sensor->echo_pin, GPIO_INTR_ANYEDGE);
    if (status_config_echo_pin == ESP_OK)
    {
        for(int i=0;i < 2 ; i++)
        {
            if(pins[i] != ESP_OK)
                return ESP_FAIL;
        }
        return ESP_OK;
    }
    return ESP_FAIL;
}

// int calculate_distance(Distance_Sensor *input)
// {
//     return 0;
// }