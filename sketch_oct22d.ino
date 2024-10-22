const int buttonPin = 4;
const int redPin = 32;
const int greenPin = 33;
const int bluePin = 25;

int colorState = 0;
int lastButtonState = HIGH;
int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    colorState = (colorState + 1) % 7;
    updateColor();
    delay(50);  // 消除按鈕彈跳
  }

  lastButtonState = buttonState;
}

void updateColor() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  switch (colorState) {
    case 0:
      digitalWrite(redPin, HIGH);  // 紅色
      break;
    case 1:
      digitalWrite(greenPin, HIGH);  // 綠色
      break;
    case 2:
      digitalWrite(bluePin, HIGH);  // 藍色
      break;
    case 3:
      digitalWrite(redPin, HIGH);  // 紅色 + 綠色
      digitalWrite(greenPin, HIGH);
      break;
    case 4:
      digitalWrite(greenPin, HIGH);  // 綠色 + 藍色
      digitalWrite(bluePin, HIGH);
      break;
    case 5:
      digitalWrite(redPin, HIGH);  // 紅色 + 藍色
      digitalWrite(bluePin, HIGH);
      break;
    case 6:
      digitalWrite(redPin, HIGH);  // 紅色 + 綠色 + 藍色
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      break;
  }
}
