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



const int trigPin1 = 12; //D6
const int echoPin1 = 13; //D7
const int trigPin2 = 12; //D6
const int echoPin2 = 15; //D8

DistanceSensor FrontSensor;
DistanceSensor LeftSensor;



void setup() {
    Serial.begin(115200); // Starts the serial communication

  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  FrontSensor.SetUltrasonicPins(trigPin1,echoPin1);
  
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  LeftSensor.SetUltrasonicPins(trigPin2,echoPin2); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print("Front distance = ");
   Serial.print( FrontSensor.FindDistance());
   Serial.print(" cm \n");

 delay(2000);
   Serial.print("Left distance = ");
   Serial.print( LeftSensor.FindDistance());
   Serial.print(" cm \n");
   delay(2000);
}
