# CollisionDetection
An IOT based project to alert vehicle drivers about any nearby objects and vehicles which can potentially collide with the car .
The major components of the system were :
Hardware requirements - 
ESP8266
ultrasonic sensor
peizo buzzer
LED lights
jumper wires

Software requirements :
arduino IDE ,
NODE JS & npm
Vs code

It consists of a ultrasonic sensor which is used to calculate the distance between the vehicle and the object , which then lets the system decide what action needs to be taken.

The system consists of mainly 3 zones. 
Zone 1 is the Green zone of the most safe zone where no action need to taken by the driver. We have kept zone 1 beyond 50 cms.
Zone 2 is the yellow zone which is consider as the safe zone , here if any object is within the proximity of 20cms - 50cms and LED will start blinking . 
Zone 3 is the red zone which is consider as the threat zone , here if any object is within the proximity of 20cm or less than it , a buzzer will start ringing indicating an immediate action needs to be taken.. 
