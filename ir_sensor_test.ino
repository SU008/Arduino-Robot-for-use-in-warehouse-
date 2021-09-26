//pwm//>>>https://create.arduino.cc/projecthub/muhammad-aqib/arduino-pwm-tutorial-ae9d71
//example>>https://circuitdigest.com/microcontroller-projects/line-follower-robot-using-arduino



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




#define FrontSensor_Trig 13
#define FrontSensor_Echo 12

//#define BackSensor_Trig 1
//#define BackSensor_Echo 2

#define LeftSensor_Trig 8
#define LeftSensor_Echo 9

#define RightSensor_Trig 4  //13
#define RightSensor_Echo 7   //12
////////////////////////////////////


//#define FrontSensor_Trig 5
//#define FrontSensor_Echo 16

DistanceSensor FrontSensor;
DistanceSensor LeftSensor;
void setup()
{
  Serial.begin(9600);

  
  //front distance sesnor
  FrontSensor.SetUltrasonicPins(FrontSensor_Trig,FrontSensor_Echo);

  //Left distance sesnor setup
  LeftSensor.SetUltrasonicPins(LeftSensor_Trig,LeftSensor_Echo); 

  

}


void loop()
{  

  Serial.print("\n               Front ");
  Serial.print(FrontSensor.FindDistance());
  Serial.print(" cm");

  Serial.print("\n Left ");
  Serial.print(LeftSensor.FindDistance());
  Serial.print(" cm");
  
}

//---------------------------------------------------------------------






inline DistanceSensor::DistanceSensor()
{
  Trig_pin = 0;
  Echo_pin = 0; 
}

inline void DistanceSensor::SetUltrasonicPins(int aTrig,int aEcho)
{
  Trig_pin = aTrig;
  Echo_pin = aEcho;
  pinMode(Trig_pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
}

inline float DistanceSensor::FindDistance()
{
  digitalWrite(Trig_pin, LOW);//send out a low pulse before we send high pulse, clean signal
  delayMicroseconds(5);//wait for 5 microsec
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  Duration_Signal = pulseIn(Echo_pin, HIGH);// save the duration from echo pin to "duration"
  return DistanceSensor::Calculate_cm();
}

inline float DistanceSensor::Calculate_cm()
{
  // 340 m/s = 0.034 cm/µs    
  Distance_cm = Duration_Signal*0.0343/2; // distance = speed* time
  return Distance_cm;
}
