int pin_A = 2; 
int pin_B = 3; 
int LastPinA; 
int CurrentPinA; 
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
  attachInterrupt(digitalPinToInterrupt(pin_A), read_pulse, RISING); 
  attachInterrupt(digitalPinToInterrupt(pin_B), read_pulse, FALLING); 
}

void loop() {
  CurrentPinA = digitalRead(pin_A); 

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
}


void read_pulse() {
  bool A_state = digitalRead(pin_A);
  bool B_state = digitalRead(pin_B);

  if (A_state ^ B_state) {
    encoder_counter--; 
    direction = counter_clockwise; 
  }
  else {
    encoder_counter++; 
    direction = clockwise; 
  }
}
