// 初始化參數
float filteredVal = 0; // 用於存儲濾波後的數值
const float alpha = 0.1; // 濾波系數，0.0~1.0之間，越大越敏感
int ledPin = 4; // LED 連接的引腳
int buttonPin = 16; // 開關按鍵的引腳
bool ledState = false; // LED 狀態 (true: 亮, false: 暗)
bool buttonState = false; // 按鍵狀態
bool lastButtonState = false; // 上一次按鍵狀態

void setup() {
  Serial.begin(115200);  
  pinMode(13, INPUT);  // 可變電阻的輸入引腳
  pinMode(ledPin, OUTPUT);  // LED 輸出引腳
  pinMode(buttonPin, INPUT_PULLUP); // 開關按鍵，使用內建上拉電阻
}

void loop() {
  // 讀取按鍵狀態
  buttonState = digitalRead(buttonPin);
  
  // 如果按鍵從未按下狀態變為按下狀態，切換LED狀態
  if (buttonState == LOW && lastButtonState == HIGH) { 
    ledState = !ledState;  // 切換 LED 狀態
  }
  lastButtonState = buttonState;  // 記錄這次按鍵狀態

  // 根據 LED 狀態調整亮度
  if (ledState) {
    // 讀取可變電阻的模擬值
    int rawVal = analogRead(13);  
    
    // 應用低通濾波
    filteredVal = alpha * rawVal + (1 - alpha) * filteredVal;
    
    // 將模擬輸入值分段到 0-255 之間，適合 PWM 信號
    int pwmVal = (int)(filteredVal / 16.0);  // 4095 除以 16 大約等於 255
    
    // 確保 pwmVal 在 0 到 255 之間
    pwmVal = constrain(pwmVal, 0, 255);
    
    // 設定 LED 亮度
    analogWrite(ledPin, pwmVal);
  } else {
    // LED 關閉時設為 0
    analogWrite(ledPin, 0);
  }
  
  // 輸出當前 LED 狀態和亮度值
  Serial.print("LED State: ");
  Serial.println(ledState ? "ON" : "OFF");
  if (ledState) {
    Serial.print("Brightness: ");
    Serial.println((int)(filteredVal / 16.0));
  }

  delay(100);
}
