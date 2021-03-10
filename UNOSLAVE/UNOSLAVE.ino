//Slave sender: Functionality: Will collect values from slave and send to the master

#include <Wire.h>
float solar;
float battery; //might be uneccessary for these values 
float crank;
String solarvalue = "";
String crankvalue = "";
String batteryvalue = "";
#define X 3 //arbitrary 

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(voltmeterSolar); // address # 8 = solar values 
  Wire.begin(9);               //address # 9 = battery values
  Wire.onRequest(voltmeterBattery); // 
  Wire.begin(10);               //address #10 = crank value 
  Wire.onRequest(voltmeterCrank); 
}

void loop() {
  delay(100);
}


// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void voltmeterSolar() {
  //gather the value through the wattmeter
  solar = analogRead(X); //This aint it but it's something like that 
  //transform into a strannnggg
  solarvalue = String(solar); 
  Wire.write(solarvalue); // respond with message of 6 bytes
  // as expected by master
}

void voltmeterBattery(){
  //gather the value through the wattmeter
  battery = analogRead(X); //This aint it but it's something like that 
  //transform into a strannnggg
  batteryvalue = String(battery); 
  Wire.write(batteryvalue); // respond with message of 6 bytes
  // as expected by master
}

void voltmeterCrank(){
  //gather the value through the wattmeter
  crank = analogRead(X); //This aint it but it's something like that 
  //transform into a strannnggg
  crankvalue = String(crank); 
  Wire.write(crankvalue); // respond with message of 6 bytes
  // as expected by master
  
}
