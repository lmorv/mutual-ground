#include <CapacitiveSensor.h>

long automataCS;
long bracelet1, bracelet2;

CapacitiveSensor cs_3_2 = CapacitiveSensor(3, 2);  // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
CapacitiveSensor cs_11_10 = CapacitiveSensor(11, 10);


void setup() {
  Serial.begin(9600);
  Serial.println("start");
  cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);  // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_11_10.set_CS_AutocaL_Millis(0xFFFFFFFF);

}

void loop() {

  automataCS = cs_3_2.capacitiveSensor(30);
  bracelet1 = cs_7_6.capacitiveSensor(30);
  bracelet2 = cs_11_10.capacitiveSensor(30);

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