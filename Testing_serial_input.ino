void setup() {
  Serial.begin(9600);
}

int Xval = 0;
int Yval = 0;

void loop() {
  
  while( Xval == 0 || Yval == 0){
     GetValMonitor();
  }

  
}


void GetValMonitor(){
  //https://www.c-sharpcorner.com/article/reading-input-from-serial-monitor-in-arduino/
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
  Serial.println("The Xval = ");
  Serial.println(Xval);
  Serial.println("\TheYal = ");
  Serial.println(Yval);
  
}
