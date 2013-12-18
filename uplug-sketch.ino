#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

boolean isOn  = true;
int relay_pin = 8;

void setup()
{
  Serial.begin(115200);

  pinMode(relay_pin,OUTPUT);
  emon1.current(0, 111.1);             // Current: input pin 0, calibration.
}

void loop(){
   while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if(inChar=='1'){
      relay_pin != relay_pin;
      digitalWrite(relay_pin, relay_pin);
    }
  }

  double Irms1 = emon1.calcIrms(1480);  // Calculate Irms only

  // calibration parameters
  Irms1-=0.33;
  Irms1=Irms1/4;

  Serial.print("<");   Serial.print(Irms1*230.0);   Serial.print("#");   Serial.print("0.0");   Serial.println(">");
  delay(1000);
}