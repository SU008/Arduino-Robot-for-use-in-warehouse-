
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
/*
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80); //Server on port 80
*/
//===============================================================
// define the class for MotorDirection 
//===============================================================
class MotorDirection
{
 public: 
  MotorDirection();
  void SetMotorValues(int motor1,int pin1,int pin2,int motor2,int pin3,int pin4);
  void Forward();
  void Backward();
  void Right();
  void Left();
  void RightR(int val);
  void LeftL(int val);
  void StopWheels();
  void SetDutyCycle(int AcycleNum);
  int  GetDutyCycle();
  
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
  //DutyCycle = AcycleNum;
  DutyCycle = ((256*AcycleNum)/100 ) ; 
}

inline int MotorDirection::GetDutyCycle(){
 // Serial.print("The Duty cycle is = ");
 // Serial.print(DutyCycle);
 
 return DutyCycle;
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
// define the class for DistanceSensor
//===============================================================
class DistanceSensor 
{
  public:
  DistanceSensor();
  void SetUltrasonicPins(int aTrig, int aEcho);
  float FindDistance();
  float Calculate_cm(); 
 private:
  int Trig_pin;
  int Echo_pin;
  float Duration_Signal;
  float Distance_cm;
};
//==============================================================
//                  FUNCTIONS For DistanceSensor class
//==============================================================
inline DistanceSensor::DistanceSensor(){
  Trig_pin = 0;
  Echo_pin = 0; 
}

inline void DistanceSensor::SetUltrasonicPins(int aTrig,int aEcho){
  Trig_pin = aTrig;
  Echo_pin = aEcho;
}

inline float DistanceSensor::FindDistance(){
  digitalWrite(Trig_pin, LOW);//send out a low pulse before we send high pulse, clean signal
  delayMicroseconds(5);//wait for 5 microsec
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  Duration_Signal = pulseIn(Echo_pin, HIGH);// save the duration from echo pin to "duration"
  return DistanceSensor::Calculate_cm();
}

inline float DistanceSensor::Calculate_cm(){
  // 340 m/s = 0.034 cm/µs    
  Distance_cm = Duration_Signal*0.0343/2; // distance = speed* time
  return Distance_cm;
}

//===============================================================
/*
//Website code 
String M = "  <!DOCTYPE html><html><body><h2>Arduino Robot<h2><h3>ESP8266 Web Server</h3><h4>Grid Coordinates</h4><form action=\"action_page\">Enter X-Value:<br><input type=\"text\" name=\"X-Value\" value=\"   \"><br>Enter Y-Value:<br><input type=\"text\" name=\"Y-Value\" value=\"   \"><br><br><input type=\"submit\" value=\"Submit\"></form> </body></html>         ";

//SSID and Password of your WiFi router
const char* ssid = "Sajjad_WIFI";
const char* password = "iawt9904";
*/

// defines pins numbers
#define MotorL 16 //Enable pins //D0
#define MotorR 5  //Enable pins //D1

const int trigPin1 = 12; //D6
const int echoPin1 = 13; //D7
const int trigPin2 = 12; //D6
const int echoPin2 = 15; //D8
/*
 const int trigPin1 = 2;  //D4   12 //D6
const int echoPin1 = 0;  //D3   13 //D7
const int trigPin2 = 13;  //D7  12 //D6
const int echoPin2 = 15;  //D8  15//D8
 */

int Xval = 20;
int Yval = 30;

int DefaultDistance = 15;


//==============================================================
//                  SETUP
//==============================================================
MotorDirection MTR ;
DistanceSensor FrontSensor;
DistanceSensor LeftSensor;

void setup() {
  Serial.begin(9600); // Starts the serial communication

  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  FrontSensor.SetUltrasonicPins(trigPin1,echoPin1);
  
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  LeftSensor.SetUltrasonicPins(trigPin2,echoPin2); 

  pinMode(4, OUTPUT);// +terminal of R  //D2
  pinMode(0, OUTPUT);// - terminal of R //D3
  pinMode(2, OUTPUT);// +terminal of L //D4
  pinMode(14,OUTPUT);//- terminal of L //D5
  MTR.SetMotorValues(MotorR, 2,14,  MotorL, 4,0);


/*
        WiFi.begin(ssid, password);     //Connect to your WiFi router
        Serial.println("");

        // Wait for connection
        while (WiFi.status() != WL_CONNECTED)
        {
        delay(500);
        Serial.print(".");
        }

        //If connection successful show IP address in serial monitor
        Serial.println("");
        Serial.print("Connected to ");
        Serial.println("WiFi");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());  //IP address assigned to your ESP
         
        server.on("/", handleRoot);      //Which routine to handle at root location
        server.on("/action_page", handleForm); //form action is handled here
        
        server.begin();                  //Start server
        Serial.println("HTTP server started");
        */
 }


//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  MTR.SetDutyCycle(40);
  
  //while( Xval == 0 || Yval == 0){
  //Serial.print("Waiting for coordinates \n");
  //server.handleClient();          //Handle client requests
  //}

  while(  FrontSensor.FindDistance() > Yval  )
  {
   Serial.print("Going to Y coordinate: Front distance = \n");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");
   MTR.Forward();
   if (LeftSensor.FindDistance() > DefaultDistance ){   MTR.RightR(30);    }
   if (LeftSensor.FindDistance() < DefaultDistance ){   MTR.LeftL(30);    }
  }


    delay(5000);

    while( FrontSensor.FindDistance() > Xval )
    {
     Serial.print("Going to X coordinate: Front distance = \n");
     Serial.print( FrontSensor.FindDistance());
     Serial.print(" cm \n");
     MTR.Forward();
     if (LeftSensor.FindDistance() > Yval ){   MTR.RightR(30);    }
     if (LeftSensor.FindDistance() < Yval ){   MTR.LeftL(30);    }     
      
    }

MTR.StopWheels();
delay(10000);

 
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

  Xval = 0;
  Yval = 0;
  
}
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
/*
void handleRoot() {
 String s = M; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
*/
//===============================================================
// This routine is executed when you press submit
//===============================================================
/*
void handleForm() {
 String Xvalue = server.arg("X-Value"); 
 String Yvalue = server.arg("Y-Value"); 
 
 //convert string to int in-order to save value
 Xval = Xvalue.toInt();  
 Yval = Yvalue.toInt();
 
 Serial.print("Recived X-Value:");
 Serial.println(Xvalue);

 Serial.print("Recived Y-Value:");
 Serial.println(Yvalue);
 
 Serial.print("Coordinates are:(") ;
 Serial.print(Xvalue);
 Serial.print(",");
 Serial.print(Yvalue);
 Serial.print(")\n ");
 //Serial.print("Coordinates are:");
 
 Serial.print("\n\n");
// String s = "<a href='/'> Go Back </a>";
// server.send(200, "text/html", s); //Send web page
  //Refresh the webpage to the same page 
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated– Press Back Button");
}
*/







 
