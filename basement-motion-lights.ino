// Basement light system. 2-pirs that trigger lights via relay
// See https://github.com/MKme/Wemos-D1-ESP8266-PIR-Alarm

// Run one PIR into each o of these pins.
int pirPins[] = {D6, D7};
int pirPinCount = 2;

void setup() {
  // Set up serial for debugging
  Serial.begin(9600);
  Serial.println("Booting done!");

  // Set the PIR pins to input mode.
  for (int i = 0; i < pirPinCount; i++) {
    pinMode(pirPins[i], INPUT);
  }
}

void loop() {
  
  // Check each PIR for motion
  for (int i = 0; i < pirPinCount; i++) {
    byte val = digitalRead(pirPins[i]); 
    if (val == HIGH){
      Serial.printf("MOTION on pin %d (%d)\n", i, pirPins[i]);
    } else {
      Serial.printf("nothing on pin %d (%d)\n", i, pirPins[i]);
    }
  }

  Serial.println("-");
  
  delay(1500);
}
