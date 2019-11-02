#include <NewPing.h>
#include <Servo.h>

#define TRIGGER 2
#define ECHO 3
#define MAX_DISTANCE 250
#define SERVO 9

#define ANGLE_BOUNDS 80
#define ANGLE_STEP 1

int angle = 0;
 
// direction of servo movement 
// -1 = back, 1 = forward 
int dir = 1;
int cm = 0;
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
  Serial.begin(115200); // initialize the serial port:
  myservo.attach(SERVO); //set servo to Arduino's pin 9
}
 
void loop() {
 
  delay(50);
  // we must renormalize to positive values, because angle is from -ANGLE_BOUNDS .. ANGLE_BOUNDS
  // and servo value must be positive
  myservo.write(angle + ANGLE_BOUNDS);
  cm = sonar.ping_cm();
  Serial.print(angle, DEC);
  Serial.print(",");
  Serial.println(cm, DEC);
  // calculate angle 
  if (angle >= ANGLE_BOUNDS || angle <= -ANGLE_BOUNDS) {
    dir = -dir;
  }
  angle += (dir * ANGLE_STEP);  
}
