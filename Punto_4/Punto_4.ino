const int buttonPin =2;
const int ledPin =6;

void setup() {
  DDRD = B00100000;
  PORTD = B00000100;
}

void loop() {
  int led = digitalRead(buttonPin);

  if(buttonPin == LOW){
    PORTD = (1 << ledPin) | PORTD;
  }else{
    PORTD = ~ (1 << ledPin) & PORTD;
  }

}
