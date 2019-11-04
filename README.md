# sonarduino
Project for TN425


![Circuit Diagram of Project](https://github.com/ban-ware/sonarduino/blob/master/Diagram.png)


Loosely based on this https://create.arduino.cc/projecthub/faweiz/arduino-radar-69b8fe project.

For this implementation, the focus is placed on the interactivity of the sonar device.  By attaching
the ultrasonic sensor to a google cardboard setup, and streaming the output of the program to an android device
placed inside the cardboard, we hope to create a game of sorts.  There are multiple ways to tackle this, and as the project develops, we will comment on the changes and considerations made for this use case.

The general setup of the hardware is as follows:

          Pin 2: Trigger //Ultrasonic Sensor input
          Pin 3: Echo //Ultrasonic Sensor Output
          Pin 9: Servo PWM Pin //Servo input
          5V power running both servo and sensor.
          This can be run on a serial cable alone.  Ideal setup is with 9v battery pack powering everything, but availability is        
          lacking.
          This is the same setup as outlined on the diagram above.
          
Current progress:

      * Program code for Arduino server & processing written
      
      * Testing required for devices, processing code runs but has not been tested with any incoming data
      
Schedule:

      * Finish testing by Friday, Nov 1st.
      
      * Commit changes, begin prepping for presentation.
      
      * Tweak as needed.
      
Faulty Equipment discovered 10/30/19.  New sensors & servo motor arriving 11/1/19.  From there testing is to be done.

Codebase is complete as of 10/30/19.  Changes only need to be made in order to create a more convenient & efficient program.


Changes made are primarily on the Arduino side, specifically to get our use case working.  We will be using the radar screen code from the mentioned project, with minor changes, as it fits what is needed and there is no point in reinventing the wheel.
