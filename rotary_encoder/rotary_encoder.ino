int pin_A = 2; 
int pin_B = 3; 
int LastPinA; 
int LastPinB; 
int CurrentPinA; 
int CurrentPinB; 
int encoder_counter;
bool clockwise = 1; 
bool counter_clockwise = 0; 
int direction = clockwise; 
int prev_counter; 

void setup() {
  Serial.begin(9600); 
  pinMode(pin_A, INPUT); 
  pinMode(pin_B, INPUT); 
  LastPinA = digitalRead(pin_A);
  attachInterrupt(digitalPinToInterrupt(pin_A), read_pulse, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(pin_B), read_pulse, CHANGE); 
}

void loop() {
  CurrentPinA = digitalRead(pin_A); 
  CurrentPinB = digitalRead(pin_B); 

  if (prev_counter != encoder_counter) {
    if (direction == clockwise) {
      Serial.println("direction: clockwise"); 
    }
    else {
      Serial.println("direction: counter clockwise"); 
    }

    Serial.println(encoder_counter); 
    prev_counter = encoder_counter; 
  }

  LastPinA = CurrentPinA; 
  LastPinB = CurrentPinB; 
}


void read_pulse() {
 if (CurrentPinA == LOW && LastPinA == HIGH) {
  if (CurrentPinB == LOW) {
    encoder_counter++; 
    direction = clockwise; 
  } 
  else {
    encoder_counter--; 
    direction = counter_clockwise; 
  }
 }

 if (CuurentPinB == HIGH && LastPinB == LOW) {
  if (CurrentPinA == HIGH) {
    encoder_counter--; 
    direction = counter_clockwise; 
  }
  else {
    encoder_counter++; 
    direction = clockwise; 
  }
 }
}

