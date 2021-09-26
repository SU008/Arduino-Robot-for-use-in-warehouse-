
class MotorDirection
{
 public: 
  MotorDirection();
  void SetMotorValues(int motor1,int pin1,int pin2, int motor2,int pin3,int pin4   );
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

inline void MotorDirection::SetMotorValues(int motor1,int pin1,int pin2,
                                           int motor2,int pin3,int pin4)
{
   MotorA = motor1;
   MTR_A_pin1 = pin1;
   MTR_A_pin2 =pin2;
 
   MotorB = motor2;
   MTR_B_pin1 = pin3;
   MTR_B_pin2 = pin4;

   pinMode(MotorA, OUTPUT);
   pinMode(MotorB, OUTPUT);
  
   pinMode(MTR_A_pin1, OUTPUT);
   pinMode(MTR_A_pin2, OUTPUT);
   pinMode(MTR_B_pin1, OUTPUT);
   pinMode(MTR_B_pin2,OUTPUT);
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
  Serial.print("\nTuring Right \n ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, DutyCycle);
  
  digitalWrite(MotorB, LOW); 
}

inline void MotorDirection::RightR(int val){
  Serial.print("\nTuring Right\n ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, DutyCycle);

  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin1, LOW);
  analogWrite(MTR_B_pin2, val);
}


inline void MotorDirection::Left(){
  Serial.print("\nTuring left\n ");
  digitalWrite(MotorA, LOW);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2, LOW);
  analogWrite(MTR_B_pin1, DutyCycle);
}

inline void MotorDirection::LeftL(int val){
  Serial.print("\nTuring left \n");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin2, LOW);
  analogWrite(MTR_A_pin1, val);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin2, LOW);
  analogWrite(MTR_B_pin1, DutyCycle);
}
//==============================================================

inline void MotorDirection::SetDutyCycle(int AcycleNum){
  DutyCycle = ((256*AcycleNum)/100 ) ; 
}

inline int MotorDirection::GetDutyCycle(){
  return DutyCycle;
}

inline void MotorDirection::Backward(){
  Serial.println("\nWheels turning Backwards \n ");
  digitalWrite(MotorA, HIGH);
  digitalWrite(MTR_A_pin1, LOW);
  analogWrite(MTR_A_pin2, DutyCycle);
  
  digitalWrite(MotorB, HIGH);
  digitalWrite(MTR_B_pin1, LOW);
  analogWrite(MTR_B_pin2, DutyCycle);
}

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

  pinMode(Trig_pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
}

inline float DistanceSensor::FindDistance(){
  //send out a low pulse before we send high pulse,clean signal
  digitalWrite(Trig_pin, LOW);
  //wait for 5 microsec
  delayMicroseconds(5);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  
  // save the duration from echo pin 
  Duration_Signal = pulseIn(Echo_pin, HIGH);
  //call the calculation function
  return DistanceSensor::Calculate_cm();
}

inline float DistanceSensor::Calculate_cm(){
  // 340 m/s = 0.034 cm/µs 
  // distance = time *speed   
  Distance_cm = Duration_Signal*0.0343/2; 
  return Distance_cm;
}




////////////////////////////////////
#define MotorL 3
#define MotorR 2

#define FrontSensor_Trig 13
#define FrontSensor_Echo 12

#define LeftSensor_Trig 8
#define LeftSensor_Echo 9

#define RightSensor_Trig 4  
#define RightSensor_Echo 7   

void GetValMonitor(void); //function for serial monitor input

MotorDirection MTR;
DistanceSensor FrontSensor;
DistanceSensor LeftSensor;
DistanceSensor RightSensor;

void setup()
{
  Serial.begin(9600);

  //front distance sesnor setup
  FrontSensor.SetUltrasonicPins(FrontSensor_Trig,FrontSensor_Echo);
 
  //Left distance sesnor setup
  LeftSensor.SetUltrasonicPins(LeftSensor_Trig,LeftSensor_Echo); 
  
  //Right distance sesnor setup
  RightSensor.SetUltrasonicPins(RightSensor_Trig,RightSensor_Echo); 
  
  MTR.SetMotorValues(MotorR, 5,6,  MotorL, 10,11);
}


//create variables
float Xval = 0;
float Yval = 0;

float DefaultDistance = 20;


void loop()
{  
    MTR.SetDutyCycle(40);
   
    while( Xval == 0 && Yval == 0)
    {
     GetValFromMonitor();
    }
   

     AlignToWall(); // used to align the robot to the wall 
     
     Serial.print("\nWaiting 5 seconds before starting \n");
     delay(5000);
  

   //move to Y value 
   while( FrontSensor.FindDistance() > Yval) 
   { Serial.print("\n Going to Y value \n");
     Serial.print("Front Distance = ");
     Serial.print( FrontSensor.FindDistance());
     Serial.print(" cm \n");
     
     MTR.Forward();
     if (LeftSensor.FindDistance() > DefaultDistance  ){  MTR.RightR(30);   }
     if (LeftSensor.FindDistance() < DefaultDistance  ){  MTR.LeftL(30);    }
   }

    //turn on the spot ( do by hand)
    MTR.StopWheels();
    Serial.print("\n Waiting 5 seconds for turning \n");
    delay(20000);
   
   //move to X value
   while( FrontSensor.FindDistance() > Xval) //move to X value 
   {Serial.print(" \n Going to X value \n");
    Serial.print("Front Distance = ");
    Serial.print( FrontSensor.FindDistance());
    Serial.print(" cm \n");
    MTR.Forward();
    if (LeftSensor.FindDistance() > Yval  ){  MTR.RightR(30);   }
    if (LeftSensor.FindDistance() < Yval  ){  MTR.LeftL(30);    }
   }

   //stop robot 
   MTR.StopWheels();
   delay(100000);

 
   /*reset X & Y to zero for getting user coordinates
   * from the start of loop during next collection 
   */
   Xval = 0;
   Yval = 0;

}

//------------------------------------------------------
void GetValFromMonitor(){
  
         Serial.println("Enter your Xval");
         while (Serial.available()==0) {     }//Wait for user input 
         String tmpX =" ";
         tmpX =   Serial.readString();
         Xval = tmpX.toInt();

         Serial.println("Enter your Yval");
         while (Serial.available()==0) {     }//Wait for user input 
         String tmpY =" ";
         tmpY =   Serial.readString();
         Yval = tmpY.toInt();

  Serial.println("\nData saved\n ");
  Serial.println("\nThe Xval = ");
  Serial.println(Xval);
  Serial.println("\nThe Yal = ");
  Serial.println(Yval);
  
}

void AlignToWall(){
  
      while( LeftSensor.FindDistance() > DefaultDistance)
      { 
       Serial.print("\nLED blinking \n");
       digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
       delay(70);                       
       digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
       delay(70); 
      }
}
