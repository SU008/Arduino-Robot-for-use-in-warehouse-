# Arduino-Robot-for-use-in-warehouse-
This is an Arduino Based robot for use in a warehouse environment, inspired by the Amazon Warehouse Robots 

Note: This page contains a summary of the project and its information, for full deatils use the Log book or project report documents. 

About Project: To use Arduino hardware and software tools to create a robot with the overall aim of navigating an enclosed area such as a warehouse, for the purpose of reaching a desired destination and travelling back with the desired contents.

A grid system is to be used for identifying unique shelf sections. For a basic implementation, the robot will start and end at the same designated spot. Once a user has entered in the desired shelf coordinate it will begin using its ultrasonic sensors at regular intervals for the purpose of identifying its relative distance from walls, ensuring it maintains a parallel path along the shelfs until a time when it identifies a turn it must make. After it makes this turn it will continue along this pathway until the correct shelf location has been reached. 

The overall goal of the project was then split into more manageable objectives:
    •	Produce a user defined data type for sensor behaviours e.g. find distance and calculate in cm.
    •	Produce a user defined data type for wheel behaviours e.g. forward, left, right etc.
    •	Set up wireless communication for remote transmission of grid coordinates.
    •	Get wheels to rotate forwards, backwards and at different speeds.
    •	Use sensors to get correct distance measurements.
    •	Attain movement in a straight path. 
    •	Attain 90 degree turns. 
    
The project makes use of Arduino hardware e.g. Boards & shields and the Arduino IDE to create a two wheeled robot capable of navigating an enclosed area with the utilization of ultrasonic sensors to detect walls, shelfs and obstacle detection. Initial work on creating code for the wheels and verifying its intended behaviour will be done in Tinkercad where hardware simulation will be the quickest route to achieving the aims for that aspect of the project. 


Prgramming languages used:
-C++

Main Components used: 
-1x H-Bridge L293D chip 
-3x Ultrasonic sensor HC-SR04


Arduino Boards used:
-Arduino Uno
-ESP8266 Node MCU for Wireless communication. 

Development Enviroments used:
-Tinkercad (https://www.tinkercad.com) for virtual simulation and Prototyping. 
-Arduino IDE (https://www.arduino.cc/en/software) for programming,compiling & uploading. 
