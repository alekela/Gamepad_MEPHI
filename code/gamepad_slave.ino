char value;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  mode = 0;
}

void loop() {
  if (Serial.available()){
    value = Serial.read();
    Serial.print(value);
    if ((value == 'A')){
      digitalWrite(8, HIGH);
    }
    if (value == 'a'){
      digitalWrite(8, LOW);
    }
    
  }
}
