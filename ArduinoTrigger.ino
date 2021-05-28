void setup() {
  pinMode(A0, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
} 

// the loop function runs over and over again forever
void loop() {
  float fps=20; //Choose fps of camera
  int sensorValue=analogRead(A1); //recuperation valeur A1
  float Voltage=5.0*sensorValue/1023.0; //Conversion en Volt
  Serial.println(Voltage); // Affichage voltage
  if (Voltage >= 3.0){
    
    digitalWrite(A0, HIGH);   // send the trigger
    digitalWrite(LED_BUILTIN, HIGH);// turn the LED on (HIGH is the voltage level)
    delay(0.5*1000/fps);      // wait
    digitalWrite(A0, LOW);    // drop the trigger
    digitalWrite(LED_BUILTIN, LOW);// turn the LED off by making the voltage LOW
    delay(0.5*1000/fps);      // wait
  }
  
}
