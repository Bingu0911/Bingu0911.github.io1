// 연결핀 변수 설정
int Button1Pin = 7;
int VibPin = 4;
int LED = 11;
int trigPin = 13;
int echoPin = 12;
int flag = 0; 

void setup() {
  Serial.begin(9600);

  pinMode(Button1Pin, INPUT_PULLUP);
  pinMode(VibPin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

}

void loop() {

  // 스위치 현재 상태 저장
  bool button1 = digitalRead(Button1Pin);

  // 초음파 거리 센서
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration / 1000)) / 2;

  // 초음파 거리 센서 시리얼 모니터에 결과 출력
  Serial.print("Duration");
  Serial.print(duration);
  Serial.print("＼nDistance:");
  Serial.print(distance);
  Serial.println("mm＼n");

  delay(500);
  
  /* 스위치1 작동*/
  if (button1 == false) //스위치 1 누름
  {
    if(flag == 1)
    {
      flag = 0;
    }
    else
    {
      flag = 1;
    }
    delay(1000);
  }

  if (flag == 1)
  {
    if (distance <= 600) //물체가 특정 거리 내 진입
    {
      digitalWrite(VibPin, HIGH); // 진동 모터 ON
      delay(1000); // wait for 1000 millisecond(s)
      digitalWrite(VibPin, LOW); // 진동 모터 OFF
      delay(1000); // wait for 1000 millisecond(s)
    }
    else
    {
      analogWrite(VibPin, LOW); // 진동 모터 OFF
      delay(1000);
    }
  }
  delay(100);

}
