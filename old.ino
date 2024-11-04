#define EN1 2
#define rpwn1 5//电机正传
#define lpwn1 3//电机反转
#define EN2 4
#define rpwn2 7
#define lpwn2 6
#define EN3 8
#define rpwn3 9//电机正传
#define lpwn3 10//电机反转
#define EN4 13
#define rpwn4 12
#define lpwn4 11

int red1 = 22;
int value1 = 0;
int red2 = 24;
int value2 = 0;
int red3 = 26;
int value3 = 0;
int red4 = 28;
int value4 = 0;

int IRpin1 = 0;
int IRpin2 = 1;
int IRpin3 = 2;
int IRpin4 = 3;
int IRpin5 = 4;
int IRpin6 = 5;
int IRpin7 = 6;
int IRpin8 = 7;
int IRpin9 = 8;

long endcount = 0;
int myrand;//随机数
long starttime = 0; //计时器

int door;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(rpwn1, OUTPUT);
  pinMode(lpwn1, OUTPUT);
  pinMode(rpwn2, OUTPUT);
  pinMode(lpwn2, OUTPUT);
  pinMode(rpwn3, OUTPUT);
  pinMode(lpwn3, OUTPUT);
  pinMode(rpwn4, OUTPUT);
  pinMode(lpwn4, OUTPUT);

  pinMode(red1, INPUT);
  pinMode(red2, INPUT);
  pinMode(red3, INPUT);
  pinMode(red4, INPUT);

  setPwmFrequency(rpwn1, 1);
  setPwmFrequency(lpwn1, 1);
  setPwmFrequency(rpwn2, 1);
  setPwmFrequency(lpwn2, 1);
  setPwmFrequency(rpwn3, 1);
  setPwmFrequency(lpwn3, 1);
  setPwmFrequency(rpwn4, 1);
  setPwmFrequency(lpwn4, 1);
  float dis7;
  float dis8;
//  wheel1(-50);
//      wheel2(50);
//      wheel3(50);
//      wheel4(-50);
//  delay(10000);
  starttime = millis();
  do
  {
    float volts7 = analogRead(IRpin7) * 0.0048828125;
    dis7 = 65 * pow(volts7, -1.10);
    float volts8 = analogRead(IRpin8) * 0.0048828125;
    dis8 = 65 * pow(volts8, -1.10);
    Serial.print(dis7 );
    Serial.print("她她她");
    Serial.println(dis8);
    if (millis() - starttime > 5000) {
      dis7 = 0;
      dis8 = 0;
    }
  } while (dis7 > 40 || dis8 > 40);

  //        wheel1(-100);
  //        wheel2(-100);
  //        wheel3(-100);
  //        wheel4(-100);
  //        delay(1100);



}
void wheel1(int t1) {

  if ( t1 > 0) {
    digitalWrite(EN1, HIGH);
    analogWrite(rpwn1, 0) ;
    analogWrite(lpwn1, t1);
  }
  if (t1 < 0) {
    digitalWrite(EN1, HIGH);
    analogWrite(rpwn1, -t1);
    analogWrite(lpwn1, 0);
  }
  if (t1 == 0) {
    digitalWrite(EN1, HIGH);
    analogWrite(rpwn1, 0);
    analogWrite(lpwn1, 0);
  }
}
void wheel2(int t2) {

  if ( t2 > 0) {
    digitalWrite(EN2, HIGH);
    analogWrite(rpwn2, 0) ;
    analogWrite(lpwn2, t2);
  }
  if (t2 < 0) {
    digitalWrite(EN2, HIGH);
    analogWrite(rpwn2, -t2);
    analogWrite(lpwn2, 0);
  }
  if (t2 == 0) {
    digitalWrite(EN2, HIGH);
    analogWrite(rpwn2, 0);
    analogWrite(lpwn2, 0);
  }
}
void wheel3(int t3) {

  if ( t3 > 0) {
    digitalWrite(EN3, HIGH);
    analogWrite(rpwn3, 0) ;
    analogWrite(lpwn3, t3);
  }
  if (t3 < 0) {
    digitalWrite(EN3, HIGH);
    analogWrite(rpwn3, -t3);
    analogWrite(lpwn3, 0);
  }
  if (t3 == 0) {
    digitalWrite(EN3, HIGH);
    analogWrite(rpwn3, 0);
    analogWrite(lpwn3, 0);
  }
}
void wheel4(int t4) {

  if ( t4 > 0) {
    digitalWrite(EN4, HIGH);
    analogWrite(rpwn4, 0) ;
    analogWrite(lpwn4, t4);
  }
  if (t4 < 0) {
    digitalWrite(EN4, HIGH);
    analogWrite(rpwn4, -t4);
    analogWrite(lpwn4, 0);
  }
  if (t4 == 0) {
    digitalWrite(EN4, HIGH);
    analogWrite(rpwn4, 0);
    analogWrite(lpwn4, 0);
  }
}
void attack() {
  wheel1(120);
  wheel2(120);
  wheel3(120);
  wheel4(120);
}

void back1() {
  wheel1(-100);
  wheel2(-100);
  wheel3(-100);
  wheel4(-100);
}
void back2() {
  wheel1(80);
  wheel2(80);
  wheel3(80);
  wheel4(80);
}
void back3() {
  wheel1(-50);
  wheel2(-50);
  wheel3(-50);
  wheel4(-50);
}
void turnl() {
  wheel1(160);
  wheel2(-160);
  wheel3(-160);
  wheel4(160);
}
void turnr() {
  wheel1(-160);
  wheel2(160);
  wheel3(160);
  wheel4(-160);
}
void loop() {

  float volts1 = analogRead(IRpin1) * 0.0048828125;
  float distance1 = 65 * pow(volts1, -1.10);
  float volts2 = analogRead(IRpin2) * 0.0048828125;
  float distance2 = 65 * pow(volts2, -1.10);
  float volts3 = analogRead(IRpin3) * 0.0048828125;
  float distance3 = 65 * pow(volts3, -1.10);
  float volts4 = analogRead(IRpin4) * 0.0048828125;
  float distance4 = 65 * pow(volts4, -1.10);
  float volts5 = analogRead(IRpin5) * 0.0048828125;
  float distance5 = 65 * pow(volts5, -1.10);
  float volts6 = analogRead(IRpin6) * 0.0048828125;
  float distance6 = 65 * pow(volts6, -1.10);
  float volts7 = analogRead(IRpin7) * 0.0048828125;
  float distance7 = 65 * pow(volts7, -1.10);
  float volts8 = analogRead(IRpin8) * 0.0048828125;
  float distance8 = 65 * pow(volts8, -1.10);
  float volts9 = analogRead(IRpin9) * 0.0048828125;
  float distance9 = 65 * pow(volts9, -1.10);
  Serial.println(distance9);
  value1 = digitalRead(red1);
  value2 = digitalRead(red2);
  value3 = digitalRead(red3);
  value4 = digitalRead(red4);

  /*****************随机走位***************/
  if (value1 == 0 && value2 == 0 && value3 == 0 && value4 == 0 && distance1 > 60 && distance2 > 60 && distance3 > 60 && distance4 > 60 && distance5 > 60 && distance6 > 60 && distance7 > 60 && distance8 > 60 && distance9 > 60)
  {
    //Serial.println("走位");
    if (endcount == 0)
    {
      myrand = random(2, 3);
      starttime = millis();
    }
    if (millis() - starttime < 400)
    {

      wheel1(-90);
      wheel2(90);
      wheel3(90);
      wheel4(-90);
      endcount = 1;

    }
    if ((millis() - starttime > 400) && (millis() - starttime) < myrand * 5000)
    {

      wheel1(90);
      wheel2(90);
      wheel3(90);
      wheel4(90);

    }
    if ((millis() - starttime) > myrand * 5000)
    {
      endcount = 0;
    }
  }

  /**************防掉*************/
  

  /*************进攻*************/
  if (value1 == 0 && value2 == 0 && value3 == 0 && value4 == 0) {


    if ((distance1 < 35 || distance2 < 35)) {
      attack();
      //Serial.println("前攻击");
    }

    if (distance3 < 60 && distance1 > 40 && distance2 > 40 && distance4 > 60) {
      //Serial.println("左前攻击");
      turnl();
    }

    if (distance4 < 60 && distance1 > 40 && distance2 > 40 && distance3 > 60) {
      turnr();
      //Serial.println("右前攻击");
    }
    if (distance5 < 60 && distance1 > 40 && distance2 > 40 && distance3 > 40 && distance6 > 40) {
      wheel1(160);
      wheel2(-160);
      wheel3(-160);
      wheel4(160);
      //Serial.println("后侧有人");
    }
    if (distance6 < 60 && distance1 > 40 && distance2 > 40 && distance3 > 40 && distance5 > 40) {
      wheel1(-150);
      wheel2(150);
      wheel3(150);
      wheel4(-150);
      //Serial.println("后侧有人");
    }
    if (distance7 < 55 && distance1 > 40 && distance2 > 40 && distance3 > 40 && distance5 > 40 && distance6 > 40) {
      wheel1(150);
      wheel2(-150);
      wheel3(-150);
      wheel4(150);
      //Serial.println("正左");
    }
    if (distance8 < 55 && distance1 > 40 && distance2 > 40 && distance3 > 40 && distance5 > 40 && distance6 > 40) {
      wheel1(-150);
      wheel2(150);
      wheel3(150);
      wheel4(-150);
      //Serial.println("正右");
    }
  }
  else if ((value1 == 1 || value2 == 1)&&value3 == 0&& value4 == 0) {
    endcount = 0;
    back1();
  }
  else if ((value3 == 1 || value4 == 1)&&value1 == 0 && value2 == 0) {
    endcount = 0;
    back2();
  }
  else if(value1 == 1 || value2 == 1 || value3 == 1  || value4 == 1){
    door == 1;
  }
  /**********台上台下********/

  if (distance1 < 30 && distance2 < 30 && distance5 < 50 && distance6 < 50 && distance9 < 50 && door == 0) {
    Serial.println("直接上台");
    wheel1(70);
    wheel2(70);
    wheel3(70);
    wheel4(70);
    delay(500);
    wheel1(-120);
    wheel2(-120);
    wheel3(-120);
    wheel4(-120);
    delay(1200);
    float volts9 = analogRead(IRpin9) * 0.0048828125;
    float distance9 = 65 * pow(volts9, -1.10);
    if (distance9 < 50) {
      wheel1(30);
      wheel2(30);
      wheel3(30);
      wheel4(30);
      delay(1000);
    }
  }

  if (distance1 < 50 && distance2 < 50 && distance5 < 50 && distance6 < 30 && distance9 > 50) {
    // Serial.println("调头上台");
    door = 1;
  }
  if (distance3 < 50 && distance8 < 40 || distance4 < 50 && distance7 < 40) {
    // Serial.println("旋转上台");
    door = 1;
  }
  if (door == 1) {
    do
    {
      //float dis9;
      float volts9 = analogRead(IRpin9) * 0.0048828125;
      distance9 = 65 * pow(volts9, -1.10);

      Serial.print(distance9 );
      Serial.print("旋转");
      wheel1(-50);
      wheel2(50);
      wheel3(50);
      wheel4(-50);

    } while (distance9 > 30);
    door = 0;
  }
  else  if ((distance1 < 50 && distance2 < 50 && distance3 < 50 && distance7 < 50 && distance9 < 50) || (distance1 < 50 && distance2 < 50 && distance4 < 50 && distance8 < 50 && distance9 < 50)) {
    // Serial.println("倒退");
    wheel1(-50);
    wheel2(-50);
    wheel3(-50);
    wheel4(-50);
    delay(1800);
    door = 1;//8.26号加的

  }
  //     if(distance1<35&&distance2<35&&distance3<50){
  //         int time1 = millis();
  //         if ((millis - time1) < 2000){
  //         back3();
  //
  //         }
  //      }
  //Serial.println(distance6);
}




/*********************************************/

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if ((pin >= 2 && pin <= 13) || (pin >= 44 && pin <= 46))
  {
    switch (divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if (pin == 4 || pin == 13) //Timer0
    {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    }
    else if (pin == 11 || pin == 12 || pin == 13) //Timer1
    {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
    else if (pin == 8 || pin == 9) //Timer2
    {
      TCCR2B = TCCR2B & 0b11111000 | mode;
    }
    else if (pin == 5 || pin == 2 || pin == 3) //Timer3
    {
      TCCR3B = TCCR3B & 0b11111000 | mode;
    }
    else if (pin == 6 || pin == 7 || pin == 8) //Timer4
    {
      TCCR4B = TCCR4B & 0b11111000 | mode;
    }
    else if (pin == 46 || pin == 45 || pin == 44) //Timer5
    {
      TCCR5B = TCCR5B & 0b11111000 | mode;
    }

  }

}

/******************************************************/
