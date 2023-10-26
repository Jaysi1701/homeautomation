#define PIN_LM35       A0
const int ledPin = 2;
const int ldrPin = A1;
int relay_pin = 9;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(relay_pin, OUTPUT);
digitalWrite(relay_pin, HIGH);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(PIN_LM35);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print("C\n");
  delay(1000);
  int ldrStatus = analogRead(ldrPin);


if (ldrStatus>=1000) {

digitalWrite(ledPin, HIGH);

Serial.println("HIGH INTENSITY, LED is ON");

}
else if(ldrStatus<=300){
  
digitalWrite(ledPin, HIGH);

Serial.println("DARK SURROUNDING , LED is ON");
}

else {

digitalWrite(ledPin, LOW);

Serial.println("---------------");

}
if (temp_val > 40){
  digitalWrite(relay_pin, LOW); 
  delay(10);
}
else if (temp_val <35){
  digitalWrite(relay_pin, LOW); 
  delay(10);
}
else{
  digitalWrite(relay_pin, HIGH);

}
  delay(1000);
}