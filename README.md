
## sketch_oct22a.ino 程式碼解析 

這個程式碼主要是讀取類比輸入並控制LED亮度：

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int val = analogRead(13);
  int val2 = val*0.06 ;
  analogWrite(4,val2);
  Serial.println(val2);
  delay(100);
}
```

**功能說明：**
- 從引腳13讀取類比值
- 將讀取的值乘以0.06轉換為PWM值
- 使用PWM控制引腳4的LED亮度
- 每100毫秒執行一次，並通過串口輸出PWM值

## sketch_oct22b.ino 程式碼解析 

這個程式碼實現了更複雜的功能，包括按鈕控制和LED亮度調節：

```cpp
// 初始化參數
float filteredVal = 0;
const float alpha = 0.1;
int ledPin = 4;
int buttonPin = 16;
bool ledState = false;
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  Serial.begin(115200);  
  pinMode(13, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // 按鈕控制和LED亮度調節邏輯
  // ...（省略具體代碼）
}
```

**功能說明：**
- 使用按鈕控制LED的開關
- 讀取可變電阻值並應用低通濾波
- 根據濾波後的值調整LED亮度
- 通過串口輸出LED狀態和亮度值

## sketch_oct22c.ino 程式碼解析 

這個程式碼簡單地控制三個LED：

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  digitalWrite(32 ,HIGH);
  digitalWrite(33 ,HIGH);
  digitalWrite(25 ,HIGH);
}
```

**功能說明：**
- 將引腳32、33和25設置為輸出模式
- 在主循環中持續點亮這三個LED

## sketch_oct22d.ino 程式碼解析 

這個程式碼實現了RGB LED的顏色切換功能：

```cpp
const int buttonPin = 4;
const int redPin = 32;
const int greenPin = 33;
const int bluePin = 25;

int colorState = 0;
int lastButtonState = HIGH;
int buttonState;

void setup() {
  // 初始化設置
}

void loop() {
  // 按鈕檢測和顏色更新邏輯
}

void updateColor() {
  // 根據colorState更新LED顏色
}
```

**功能說明：**
- 使用按鈕控制RGB LED的顏色變化
- 每次按下按鈕，顏色狀態會改變
- 提供7種不同的顏色組合
- 使用switch語句根據顏色狀態控制LED
