
int randNumber;
void box_muller(double sigma, double *r1, double *r2);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  random(analogRead(0));
}


void loop() {
  double r1;
  box_muller(2, &r1);
  Serial.print(r1);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));   // turn the LED on/off
  randNumber = random(25, 40);
  delay(randNumber);                       // wait 
   digitalWrite(3, HIGH);  
  digitalWrite(5, HIGH);
  randNumber = random(25, 100);
  delay(randNumber);                       // wait 
   digitalWrite(3, LOW);  
   digitalWrite(5, LOW);
  
}
