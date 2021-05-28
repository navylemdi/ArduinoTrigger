void setup() {
  pinMode(A0, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
} 

// the loop function runs over and over again forever
void loop() {

  float alpha=0.5; //rapport cyclique
  float fps=20; //Choose fps of camera
  int sensorValue=analogRead(A1); //recuperation valeur A1
  float Voltage=5.0*sensorValue/1023.0; //Conversion en Volt
  
  Serial.print(Voltage); // Affichage voltage
  Serial.println(" V");
  
  unsigned long StartTime = micros();
  
  if (Voltage >= 3.0){
    unsigned long CurrentTime = micros();
    unsigned long ElapsedTime = CurrentTime - StartTime;
    Serial.print(ElapsedTime);
    Serial.println(" microsecond");
    digitalWrite(A0, HIGH);   // send the trigger
    digitalWrite(LED_BUILTIN, HIGH);// turn the LED on (HIGH is the voltage level)
    delay(alpha*1000.0/fps);      // wait
    digitalWrite(A0, LOW);    // drop the trigger
    digitalWrite(LED_BUILTIN, LOW);// turn the LED off by making the voltage LOW
    delay((1.0-alpha)*1000.0/fps);      // wait
  }
  
}
