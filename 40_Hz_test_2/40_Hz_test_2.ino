void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);  
  digitalWrite(5, HIGH);
  delay(12.);              
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);    
  delay(12.);   
}
