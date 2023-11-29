// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
      Servo1.write(90); 

}
void loop(){ 
   Servo1.write(45); 
   delay(1000); 
  
   // Make servo go to 180 degrees 
   Servo1.write(90); 
   delay(1000); 

  Servo1.write(135); 
   delay(1000); 
}
