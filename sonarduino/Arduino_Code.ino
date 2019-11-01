#include <NewPing.h>
#include <Servo.h>

#define TRIGGER 2
#define ECHO 3
#define MAX_DISTANCE 250
#define SERVO 9

#define ANGLE_BOUNDS 80
#define ANGLE_STEP 1

int pos = 0;    // variable to store the servo position

Servo motor;
NewPing sonar(TRIGGER, ECHO, MAX_DISTANCE);

void setup(){
  Serial.begin(115200);
  motor.attach(SERVO);
}
void loop(){
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  getDistance();
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    motor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    motor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

int getDistance(){
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
