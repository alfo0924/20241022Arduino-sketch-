
void setup() {
  // 設置初始化代碼，只運行一次
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(32, OUTPUT);  // 設置引腳4為輸出模式
  pinMode(33, OUTPUT);  // 設置引腳4為輸出模式
  pinMode(25, OUTPUT);  // 設置引腳4為輸出模式
  
}



void loop() {
digitalWrite(32 ,HIGH);
digitalWrite(33 ,HIGH);
digitalWrite(25 ,HIGH);

}
