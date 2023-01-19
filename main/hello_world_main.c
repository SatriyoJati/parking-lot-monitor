#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "distanceSensor.h"
#include "driver/gpio.h"

#include "esp_system.h"
// #include "esp_spi_flash.h"
#define GPIO_TRIG 8
#define GPIO_ECHO 7
    
QueueHandle_t xQueue;

Distance_Sensor HRCSensor =
{
    .sensorID = "1",
    .trig_pin = GPIO_TRIG,
    .echo_pin = GPIO_ECHO,
    .nameSensor = "HRC04"
};

static void vSensorInputTask(void *pvParameters)
{   
    xEcho_TimeStamp = xQueueCreate(15, sizeof(Distanc_Sensor));
    xTrigger_Command = xQueueCreate(10, sizeof(Distance_Sensor));

    for(;;)
    {
        send_trigger_command(pvParameters);
        vTaskDelay(pdMS_TO_TICKS(10));
        BaseType_t status = xQueueReceive(xTrigger_Command) 
        if (status== pdPASS)
        {
            while (gpio_)
        }
    }
}

static void  vSenderTask(void *pvParameters)
{
    int32_t lValueToSend;
    BaseType_t xStatus;
    TickType_t LastWakeTime = xTaskGetTickCount();
    TickType_t frequencyTime = pdMS_TO_TICKS(3000);
    lValueToSend = (int32_t ) pvParameters;

    for(;;)
    {

        xStatus =  xQueueSendToBack(xQueue, &lValueToSend ,0);
        if (xStatus != pdPASS)
        {
            printf("Could not send the queue. \r\n");
        }
        vTaskDelayUntil(&   LastWakeTime, frequencyTime);
    }
}

static void vReceiverTask(void *pvParameters)
{
    int32_t lReceivedValue;
    BaseType_t xStatus;

    const TickType_t xTicksTimeToWait = pdMS_TO_TICKS(100);

    for(;;)
    {
        if (uxQueueMessagesWaiting (xQueue) != 0)
        {
            printf("Queue should have been empty!\n\r");
        }


        xStatus = xQueueReceive(xQueue, &lReceivedValue, xTicksTimeToWait);

        if (xStatus == pdPASS)
        {
            printf("Received : %d\n", lReceivedValue);
        }
        else
        {
            printf("Could not Receiving the value\n");
        }
    }
}

void app_main()
{
    esp_err_t pins_config;
    xQueue = xQueueCreate( 5, sizeof( int32_t));

    //initializing pins 
    pins_config = initialize_sensor_pin(&HRCSensor);
    if (pins_config != ESP_OK)
    {
        printf("config for pins unsuccessful... Please try again");
    }
    else if(pins_config == ESP_OK)
        printf("config pins succesful ... Continue to integrate the system")

    if(xQueue != NULL)
    {
        xTaskCreate(vSenderTask, "Sender1" , 1000, (void * ) 100, 1, NULL);
        xTaskCreate(vSenderTask, "Sender2" , 1000, (void *) 250, 1, NULL );

        xTaskCreate(vReceiverTask, "Recevier" ,1000, NULL,2,NULL);
    } 
    else
    {
    }
    printf("Hello world!\n");
    printf("Restarting now.\n");
    fflush(stdout);
    // esp_restart();
}
