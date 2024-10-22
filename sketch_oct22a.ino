

void setup() {
  // 設置初始化代碼，只運行一次
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(13,INPUT);
  pinMode(4, OUTPUT);  // 設置引腳4為輸出模式
  
}



void loop() {
int val = analogRead(13);
int val2 = val*0.06 ;
analogWrite(4,val2);
Serial.println(val2);

delay(100);


}
