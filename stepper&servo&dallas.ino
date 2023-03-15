#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200


// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);
int rev = 2;
int i =1;

//__________________________________________________
// servo
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;   

//___________________________________________________
// hitanemi
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

int cnt = 0;


void setup()
{
  //Dallas
  Serial.println("Faum okkur supu");
  sensors.begin();	// Start up the library

  Serial.begin(9600);

  //stepper
  
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(15);

  // servo
  myservo.attach(8);


  //1
//servo botnstada
  for (pos = 0; pos <= 12; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 12; pos >= -3; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);

}

void loop()
{
// //1
// //servo botnstada
//   for (pos = 0; pos <= 12; pos += 1) { // goes from 0 degrees to 180 degrees
//     // in steps of 1 degree
//     myservo.write(pos);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(2000);
//   for (pos = 12; pos >= -3; pos -= 1) { // goes from 180 degrees to 0 degrees
//     myservo.write(pos);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(2000);

//2
//hitanemi
  // Send the command to get temperatures
  sensors.requestTemperatures(); 
  // int T = sensors.getTempCByIndex(0);
  // while (sensors.getTempCByIndex(0)>20){
  //   Serial.print("Supa er of heit, hun er ");
  //   Serial.print(sensors.getTempCByIndex(0));
  //   Serial.println(" °C");
  //   // T = sensors.getTempCByIndex(0);    
  //   Serial.println(cnt);
  //   cnt++;
  //   delay(2000);    
  // }

  int T = sensors.getTempCByIndex(0);
  if (T>38){
    Serial.print("Supa er of heit, hun er ");
    Serial.print(T);
    Serial.println(" °C");      
    return;
  }

  Serial.print("Supa er ekki of heit, hun er ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" °C");
  Serial.println(cnt);
  cnt++;
  delay(500);

//3
//stepper
  while (i<=rev){
    Serial.println("Upp");
    stepper.step(STEPS);
    //Serial.println("Backward");
    //stepper.step(-STEPS);
    Serial.println(i);
    i++;
  }
  delay(1000);
//4
// servo toppstada
  for (pos = 0; pos <= 8; pos += 01) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(1000);

//5
//stepper
  while (i>=rev){
  
    Serial.println("Nidur");
    stepper.step(-STEPS);
    Serial.println(i);
    i--;
    }
  delay(1000);

//1
//servo botnstada
  for (pos = 0; pos <= 12; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 12; pos >= -3; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);

  
}