/*
  I2C Master Demo
  i2c-master-demo.ino
  Demonstrate use of I2C bus
  Master sends character and gets reply from Slave
  DroneBot Workshop 2019
  https://dronebotworkshop.com

  MEGA used as the master
  Okay so the way this works. Basically the arduino mega is going to send a signal to the uno
  to say like "yo whats up we need a value". But that's just gonna be a character. Next thing
  the uno takes that value, gets us our string and sends that bad boy back. After that, the 
  uno stores the value in the variable. We run this 3 times (1 for solar input, 1 for hand crank
  input, 1 for battery value). Then the code takes those inputs and displays them on the user display. Meanwhile if the user display is interactive then it will be also interpreting the user input. 
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define Slave answer size - will probably change 
#define ANSWERSIZE 5

//defining the strings that will be the values here 
String solarvalue = "";
String crankvalue = "";
String batteryvalue = "";



void setup() {

  // Initialize I2C communications as Master
  Wire.begin();
  
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop() {
  panels();
  crank();
  battery();
  displayvalues(); //not sure if we are gonna need to always be running display values - might need to run something interactive simultaneously//
  delay(50); //delay for however long we want our systems to check the values// 
}


void panels() {
   
  delay(50); //not sure we need these delays// 
  //use this to check the slave arduino for data from solar panels 
  Serial.println("Write data to slave");
  
  // Write a charatre to the Slave to signal that we want that solar DATA 
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();
    
  Serial.println("Receive data");
  
  // Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR,ANSWERSIZE);
  
  // Add characters to string
  while (Wire.available()) {
      char b = Wire.read();
      solarvalue += b;
  } 
  
  // Print to Serial Monitor
  Serial.println(solarvalue);
  }

  void crank() {
  delay(50);
  //use this to check the slave arduino for data from crank wattmeter and store value 
  Serial.println("Write data to slave");
  
  // Write a charatre to the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();
    
  Serial.println("Receive data");
  
  // Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR,ANSWERSIZE);
  
  // Add characters to string
  while (Wire.available()) {
      char b = Wire.read();
      crankvalue += b;
  } 
  
  // Print to Serial Monitor
  Serial.println(crankvalue);
  }

  void battery() {
  delay(50);
  //use this to check the slave arduino for data from battery wattmeter  
  Serial.println("Write data to slave");
  
  // Write a charatre to the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();
    
  Serial.println("Receive data");
  
  // Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR,ANSWERSIZE);
  
  // Add characters to string
  while (Wire.available()) {
      char b = Wire.read();
      batteryvalue += b;
  } 
  
  // Print to Serial Monitor
  Serial.println(batteryvalue);
  }

  void displayvalues(){
    //write code here to take stored values and update user display
  }
