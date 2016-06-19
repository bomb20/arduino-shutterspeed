long stime = 0;
bool measuring = false;
int toggleValue;
const byte sensorPin = 0;
const float toggleFactor = 0.95;
int sensorValue;

void setup() {
  Serial.begin(9600);
  Serial.println("open shutter!");
  delay(2000);
  int valueSum = 0;
  for (int i = 0; i < 10; i++){
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    valueSum += sensorValue;
    delay(500);
  }
  toggleValue = (int)(((float)valueSum / 10.0) * toggleFactor);
  Serial.println(toggleValue);
  Serial.println("Beginning...");
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if ((measuring == false) && (sensorValue > toggleValue)){
    stime = micros();
    measuring = true;
  }
  else if ((measuring == true) && (sensorValue < toggleValue)){
    Serial.println(1.0/((float)(micros() - stime) / 1000000.0));
    measuring = false;
  }

}
