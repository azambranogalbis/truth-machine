//LEDS
#define GREEN D1
#define RED D2
#define BUTTON D3

void setup() {
  Serial.begin(9600);
  Serial.println();
  
  //LEDs
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
}

int state = 0;
unsigned long pressStart = 0;

void loop() {
  int buttonState = digitalRead(BUTTON);
  
  if(buttonState == LOW && pressStart == 0) {
    Serial.println("BOTON");
    pressStart = millis();
  }

  unsigned long diff = millis() - pressStart;
  
  if(buttonState == LOW) {
    if((diff / 500) % 2 == 0) {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);
    }
    else {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
    }
  }
  
  if (buttonState == HIGH && pressStart > 0) {
    if((diff / 1000) % 2 == 0) {
      Serial.println("MENTIRA");
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);
    }
    else {
      Serial.println("VERDAD");
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
    }
    pressStart = 0;
  }
}
