int readValue;
int brightness;

constexpr int RED = 11;
constexpr int GREEN = 10;
constexpr int BLUE = 9;
constexpr int YELLOW = 6;
constexpr int BUTTON = 5;
constexpr int NUMBER_BLINKS = 10;
constexpr int DIM = 0;

bool buttonPressed = false;

void setup() {

  constexpr int pins[] {YELLOW, BLUE, GREEN, RED};
  for (const auto& pin: pins)
    pinMode(pin, OUTPUT);

  pinMode(BUTTON, INPUT); 
}

void loop() {
  readValue = analogRead(A0);
  brightness = readValue / 4;

  buttonPressed = (digitalRead(BUTTON) == HIGH);

  analogWrite(YELLOW, brightness);
  analogWrite(BLUE, brightness);
  analogWrite(GREEN, brightness);
  analogWrite(RED, brightness);

  if (buttonPressed) {
    
    analogWrite(RED, DIM);
    analogWrite(GREEN, DIM);
    analogWrite(BLUE, DIM);
    analogWrite(YELLOW, DIM);
    delay(1000);

    // light show...
    analogWrite(RED, brightness);
    delay(250);
    analogWrite(GREEN, brightness);
    delay(250);
    analogWrite(BLUE, brightness);
    delay(250);
    analogWrite(YELLOW, brightness);
    delay(250);
    analogWrite(RED, DIM);
    analogWrite(GREEN, DIM);
    analogWrite(BLUE, DIM);
    analogWrite(YELLOW, DIM);
    delay(1000);

    analogWrite(YELLOW, brightness);
    delay(250);
    analogWrite(BLUE, brightness);
    delay(250);
    analogWrite(GREEN, brightness);
    delay(250);
    analogWrite(RED, brightness);
    delay(250);
    analogWrite(RED, DIM);
    analogWrite(GREEN, DIM);
    analogWrite(BLUE, DIM);
    analogWrite(YELLOW, DIM);
    delay(1000);

    for (int i = 0; i < NUMBER_BLINKS; i++) {
      analogWrite(RED, brightness);
      analogWrite(GREEN, brightness);
      analogWrite(BLUE, brightness);
      analogWrite(YELLOW, brightness);
      delay(250);
      analogWrite(RED, DIM);
      analogWrite(GREEN, DIM);
      analogWrite(BLUE, DIM);
      analogWrite(YELLOW, DIM);
      delay(250);
    }
  }
}


