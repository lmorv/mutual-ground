#include <CapacitiveSensor.h>

long automataCS;
long bracelet1, bracelet2;
int motorPin = 9;
int braceletStates[2] = {0}; // index position (0 or 1) refers to either bracelet1 or bracelet2

CapacitiveSensor cs_3_2 = CapacitiveSensor(3, 2);  // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
CapacitiveSensor cs_11_10 = CapacitiveSensor(11, 10);

enum {
  A,
  B,
  C,
  D
} state;


void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("start");
  cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);  // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_11_10.set_CS_AutocaL_Millis(0xFFFFFFFF);

}

void getBracelet(int b, int idb) {

switch (b) {
    case 30 ... 100:
      if(!idb) braceletStates[0] = A;
      if(idb) braceletStates[1] = A;
      // Serial.println("AA");
      break;

    case 101 ... 400:
      if(!idb) braceletStates[0] = B;
      if(idb) braceletStates[1] = B;
      // Serial.println("BB");
      break;

    case 401 ... 6000:
      if(!idb) braceletStates[0] = A;
      if(idb) braceletStates[1] = B;
      //  Serial.println("AB");
      break;

    default:
      if(!idb) braceletStates[0] = B;
      if(idb) braceletStates[1] = A;
      // Serial.println("BA");
      break;
  }

}

void runBState() {

if (automataCS > 30){
  if (braceletStates[0] == A && braceletStates[1] == A) {
      analogWrite(motorPin, 200);  // Low power to motor
        // Serial.println("V1.");

    } else if (braceletStates[0] == B && braceletStates[1] == B) {
      analogWrite(motorPin, 215);  // Medium power to motor
        // Serial.println("V2");

    } else if (braceletStates[0] == A && braceletStates[1] == B) { 
      analogWrite(motorPin, 230);  // Medium power to motor
        // Serial.println("V3");
 
    } else if (braceletStates[0] == B && braceletStates[1] == A) { 
      analogWrite(motorPin, 250);  // High power to motor
        // Serial.println("V4");

    } 
}
}

void loop() {

  automataCS = cs_3_2.capacitiveSensor(30);
  bracelet1 = cs_7_6.capacitiveSensor(30);
  bracelet2 = cs_11_10.capacitiveSensor(30);

  getBracelet(bracelet1, 0); // set the state of bacelet1 acording to value thresholds
  getBracelet(bracelet2, 1);// set the state of bacelet2 acording to value thresholds
  getBracelet(automataCS, 2);
  // Serial.println(braceletStates[0]);
  
  runBState(); // power motor at a set intensity for each state configuration

  Serial.print("autoCS: ");  // tab character for debug window spacing
  Serial.print(automataCS);  // print sensor output 1

 Serial.print("\t");
 Serial.print("b1: ");
 Serial.print(bracelet1);

  
  Serial.print("\t");
  Serial.print("b2: ");
  Serial.println(bracelet2);

  delay(10);  // arbitrary delay to limit data to serial port

}