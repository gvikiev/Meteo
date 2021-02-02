#include "config.h"
#include "LIGHTActuator.h"
#include <Arduino.h>
#include "Log.h"

bool LIGHT_Setup()
{
    if(LIGHT_SENSOR_ANALOG_Setup()) {
        LIGHT_SENSOR_ANALOG_Setup();
        Log("LIGHT sensor analog setup complete");
         return true; 
    }    
    if(LIGHT_SENSOR_DIGITAL_Setup()){
        LIGHT_SENSOR_DIGITAL_Setup();
        Log("LIGHT sensor digital setup complete");
        return true;
    }
    else {
        Log("LIGHT sensor setup failed");
        return false;
    }

}

bool LIGHT_SENSOR_ANALOG_Setup()
{
    if(LIGHT_SENSOR_ANALOG_PIN!=-1){
        pinMode(LIGHT_SENSOR_ANALOG_PIN, INPUT);
        return true;
    }
    else {
        return false;
    }
    
    
}

bool LIGHT_SENSOR_DIGITAL_Setup()
{
    if(LIGHT_SENSOR_DIGITAL_PIN!=-1){
        pinMode(LIGHT_SENSOR_DIGITAL_PIN, INPUT);
        return true;    
    }
    else {
        return false;
    }
}

float LIGHT_GET_data()
{
    int raw = -1;

    if(LIGHT_SENSOR_ANALOG_PIN!=-1){
        raw = analogRead(LIGHT_SENSOR_ANALOG_PIN) * 0.48 / 100;         
    }
    if(LIGHT_SENSOR_DIGITAL_PIN!=1){
        raw = digitalRead(LIGHT_SENSOR_DIGITAL_PIN) * 0.48 / 100;
    }

   Log("LIGHT sensor data " + String(raw));

   return raw;
}

