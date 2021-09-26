
/*
static const uint8_t D0   = 16;
       const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
*/
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80); //Server on port 80

//===============================================================
// define the class for MotorDirection 
//===============================================================
class MotorDirection
{
  public: 
  MotorDirection();
  void SetMotorValues(int motor1,int pin1,int pin2, int motor2,int pin3,int pin4   );
  void Forward();
  void Backward();
  void Right();
  void Left();
  void RightR(int val);////////
  void LeftL(int val);//////
  void SetDutyCycle(int AcycleNum);
  void GetDutyCycle();
  void StopWheels();
 private: 
  int DutyCycle;
  int MotorA;
  int MTR_A_pin1;
  int MTR_A_pin2;
 
  int MotorB;
  int MTR_B_pin1;
  int MTR_B_pin2;
};
//==============================================================
//                  FUNCTIONS For MotorDirection class
//==============================================================
inline MotorDirection::MotorDirection(){
  int MotorA = 0;
  int MTR_A_pin1 = 0;
  int MTR_A_pin2 = 0;
 
  int MotorB = 0;
  int MTR_B_pin1 = 0;
  int MTR_B_pin2 = 0;
}

inline void MotorDirection::SetMotorValues(int motor1,int pin1,int pin2, int motor2,int pin3,int pin4){
   MotorA = motor1;
   MTR_A_pin1 = pin1;
   MTR_A_pin2 =pin2;
 
   MotorB = motor2;
   MTR_B_pin1 = pin3;
   MTR_B_pin2 = pin4;
   Serial.println(MotorB);
   Serial.println(MTR_B_pin1);
   Serial.println(MTR_B_pin2);
   Serial.println(MotorA);
   Serial.println(MTR_A_pin1);
   Serial.println(MTR_A_pin2);
}

inline void MotorDirection::Forward(){
  Serial.println("\nWheel is turning Forwards");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, DutyCycle);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2, LOW);
  analogWrite(MTR_B_pin1, DutyCycle);  
}

inline void MotorDirection::StopWheels(){
  Serial.print("\nWheels stopped\n ");
  digitalWrite(MotorA, LOW);
  digitalWrite(MotorB, LOW);
  
}

inline void MotorDirection::Right(){
  Serial.print("\nTuring Right ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, DutyCycle);
  
  digitalWrite(MotorB, LOW);
  //digitalWrite(MTR_B_pin2, LOW);
  //analogWrite(MTR_B_pin1, DutyCycle);
}

inline void MotorDirection::RightR(int val){
  Serial.print("\nTuring Right ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, DutyCycle);

  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2,  LOW);
  analogWrite(MTR_B_pin1, val);
  
  Serial.print("\nval = ");
  Serial.print(val);
}

inline void MotorDirection::Left(){
  Serial.print("\nTuring left ");
  digitalWrite(MotorA, LOW);
 // digitalWrite(MTR_A_pin2, LOW);
 // analogWrite(MTR_A_pin1, DutyCycle);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2, LOW);
  analogWrite(MTR_B_pin1, DutyCycle);
}

inline void MotorDirection::LeftL(int val){
  Serial.print("\nTuring left ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, val);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2, LOW);
  analogWrite(MTR_B_pin1, DutyCycle);
  Serial.print("\nval = ");
  Serial.print(val);
}

inline void MotorDirection::SetDutyCycle(int AcycleNum){
  DutyCycle = AcycleNum;
}

inline void MotorDirection::GetDutyCycle(){
  Serial.print("The Duty cycle is = ");
  Serial.print(DutyCycle);
}

inline void MotorDirection::Backward(){
  Serial.println("\nWheels turning Backwards");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin1, LOW);
  analogWrite(MTR_A_pin2, DutyCycle);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin1, LOW);
  analogWrite(MTR_B_pin2, DutyCycle);
}



//===============================================================

//Website code 
String M = "  <!DOCTYPE html><html><body><h2>Arduino Robot<h2><h3>ESP8266 Web Server</h3><h4>Grid Coordinates</h4><form action=\"action_page\">Enter X-Value:<br><input type=\"text\" name=\"X-Value\" value=\"   \"><br>Enter Y-Value:<br><input type=\"text\" name=\"Y-Value\" value=\"   \"><br><br><input type=\"submit\" value=\"Submit\"></form> </body></html>         ";

//SSID and Password of your WiFi router
const char* ssid = "Sajjad_WIFI";
const char* password = "iawt9904";


// defines pins numbers
#define MotorL 16 //Enable pins //D0
#define MotorR 5  //Enable pins //D1



int DefaultDistance = 15;


//==============================================================
//                  SETUP
//==============================================================
MotorDirection MTR ;


void setup() {
  Serial.begin(115200); // Starts the serial communication

  pinMode(4, OUTPUT);// +terminal of R  //D2
  pinMode(0, OUTPUT);// - terminal of R //D3
  pinMode(2, OUTPUT);// +terminal of L //D4
  pinMode(14,OUTPUT);//- terminal of L //D5
  MTR.SetMotorValues(MotorR, 2,14,  MotorL, 4,0);

   
 }


//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  MTR.SetDutyCycle(100);
  
  MTR.Forward();
  delay(1000);
/*
  while(  FrontSensor.FindDistance() > Yval  )
  {
   Serial.print("Going to Y coordinate: Front distance = \n");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");
   MTR.Forward();
   if (LeftSensor.FindDistance() <= DefaultDistance ){   MTR.RightR(50);    }
  }
 
  while(    LeftSensor.FindDistance() > Yval  )
  {  
   Serial.print("Turning : Left distance = \n");
   Serial.print( LeftSensor.FindDistance());
   Serial.print(" cm \n");
   MTR.Right();
  }

  while( FrontSensor.FindDistance() > Xval  )
  {
   Serial.print("Going to X coordinate \n");
   MTR.Forward();
   Serial.print("Front distance = \n");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");
  }


  while(    LeftSensor.FindDistance() > Xval  )
  {  
   Serial.print("Turning again \n");
   MTR.Right();
   Serial.print("Left distance = \n");
   Serial.print( LeftSensor.FindDistance());
   Serial.print(" cm \n");
  }
  
  Serial.print("\n Arrived at destination ");
  Serial.print("\n Waiting for 1 second ");
  delay(1000);

  while( FrontSensor.FindDistance() > DefaultDistance )
  {
    MTR.Forward();
   Serial.print("Front distance = \n");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");
  }

  while(LeftSensor.FindDistance() > DefaultDistance)
  {
   MTR.Right();
   Serial.print("Left distance = \n");
   Serial.print( LeftSensor.FindDistance());
   Serial.print(" cm \n");
  }

  while(  FrontSensor.FindDistance() > DefaultDistance  )
  {
   MTR.Forward();
   if (LeftSensor.FindDistance() <= DefaultDistance ){ MTR.Right();}
   Serial.print("Front distance = \n");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");
  }

  while(FrontSensor.FindDistance()  >DefaultDistance )
  {
   MTR.Right();
  }

  while(LeftSensor.FindDistance() != DefaultDistance)
  {
   MTR.Right();
   Serial.print("Left distance = \n");
   Serial.print( LeftSensor.FindDistance());
   Serial.print(" cm \n");
  }
  */

  
}








 
