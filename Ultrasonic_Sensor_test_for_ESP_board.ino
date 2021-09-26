
/*//static const uint8_t D0   = 16;
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
// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
const int trigPin2 = 13;  //D7
const int echoPin2 = 15;  //D8

// defines variables
long duration;
int distance;
long duration2;
int distance2;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT);

Serial.begin(115200); // Starts the serial communication
}

void loop() {
  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance: ");

Serial.println(distance);
delay(100);



// Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);

// Calculating the distance
distance2= duration2*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("\nDistance2: ");
Serial.println(distance2);
delay(100);

}
