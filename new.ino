#include <Wire.h>
//#include <JY901.h>
#define EN1 2
#define rpwn1 3//电机正传
#define lpwn1 5//电机反转
#define EN2 4
#define rpwn2 7//电机正传
#define lpwn2 6//电机反转
#define EN3 8
#define rpwn3 10//电机正传
#define lpwn3 9//电机反转
#define EN4 13
#define rpwn4 12//电机正传
#define lpwn4 11//电机反转

#define delta_t 0.0
/***************/
int IRpin1 = 0;//正前
int IRpin2 = 1;//左1
int IRpin4 = 6;//左2
int IRpin9 = 12;//左3
int IRpin3 = 2;//右1
int IRpin6 = 7;//右2
int IRpin8 = 13;//右3

int IRpin5 = 8;//上-前
int IRpin7 = 9;//后

//int IRpin8 = 7;

int red1 = 50;
int value1 = 0;
int red2 = 51;
int value2 = 0;
int red3 = 48;
int value3 = 0;
int red4 = 49;
int value4 = 0;

long endcount = 0;
long endcount2 = 0;
int myrand;//随机数
long starttime = 0; //计时器
long attackstart = 0; //计时器
int door = 0;
int count = 0;

int d[5];

//int count = 0;//避免防掉进入死循环

int turn_count = 0;//避免旋转进入死循环

void setup() {
  // put your setup code here, to run once:
  pinMode(EN1, OUTPUT);
  pinMode(rpwn1, OUTPUT);
  pinMode(lpwn1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(rpwn2, OUTPUT);
  pinMode(lpwn2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(rpwn3, OUTPUT);
  pinMode(lpwn3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(rpwn4, OUTPUT);
  pinMode(lpwn4, OUTPUT);

  pinMode(red1, INPUT);
  pinMode(red2, INPUT);

  setPwmFrequency(rpwn1, 1);
  setPwmFrequency(lpwn1, 1);
  setPwmFrequency(rpwn2, 1);
  setPwmFrequency(lpwn2, 1);
  setPwmFrequency(rpwn3, 1);
  setPwmFrequency(lpwn3, 1);
  setPwmFrequency(rpwn4, 1);
  setPwmFrequency(lpwn4, 1);
  Serial.begin(9600);
  Serial1.begin(9600);

  float dis8;
  float dis9;

  starttime = millis();
  do
  {
    float volts8 = analogRead(IRpin8) * 0.0048828125;
    dis8 = 65 * pow(volts8, -1.10);
    float volts9 = analogRead(IRpin9) * 0.0048828125;
    dis9 = 65 * pow(volts9, -1.10);
    Serial.print(dis8 );
    Serial.print("她她她");
    Serial.println(dis9);
    if (millis() - starttime > 5000) {
      dis9 = 0;
      dis9 = 0;
    }
  } while (dis8 > 40 || dis9 > 40);

}


void wheel1(int t1) {

  if ( t1 > 0) {
    digitalWrite(EN1, LOW);
    digitalWrite(rpwn1, 0) ;
    analogWrite(lpwn1, t1);
  }
  if (t1 < 0) {
    digitalWrite(EN1, LOW);
    analogWrite(rpwn1, -t1);
    digitalWrite(lpwn1, 0);
  }
  if (t1 == 0) {
    digitalWrite(EN1, LOW);
    analogWrite(rpwn1, 0);
    analogWrite(lpwn1, 0);
  }
}
void wheel2(int t2) {

  if ( t2 > 0) {
    digitalWrite(EN2, LOW);
    digitalWrite(rpwn2, 0) ;
    analogWrite(lpwn2, t2);
  }
  if (t2 < 0) {
    digitalWrite(EN2, LOW);
    analogWrite(rpwn2, -t2);
    digitalWrite(lpwn2, 0);
  }
  if (t2 == 0) {
    digitalWrite(EN2, LOW);
    analogWrite(rpwn2, 0);
    analogWrite(lpwn2, 0);
  }
}
void wheel3(int t3) {

  if ( t3 > 0) {
    digitalWrite(EN3, LOW);
    digitalWrite(rpwn3, 0) ;
    analogWrite(lpwn3, t3);
  }
  if (t3 < 0) {
    digitalWrite(EN3, LOW);
    analogWrite(rpwn3, -t3);
    digitalWrite(lpwn3, 0);
  }
  if (t3 == 0) {
    digitalWrite(EN3, LOW);
    analogWrite(rpwn3, 0);
    analogWrite(lpwn3, 0);
  }
}
void wheel4(int t4) {

  if ( t4 > 0) {
    digitalWrite(EN4, LOW);
    digitalWrite(rpwn4, 0) ;
    analogWrite(lpwn4, t4);
  }
  if (t4 < 0) {
    digitalWrite(EN4, LOW);
    analogWrite(rpwn4, -t4);
    digitalWrite(lpwn4, 0);
  }
  if (t4 == 0) {
    digitalWrite(EN4, LOW);
    analogWrite(rpwn4, 0);
    analogWrite(lpwn4, 0);
  }
}
void Robot_wheel(int RobotV, int Yawrate) {

  wheel1(RobotV - Yawrate);
  wheel2(RobotV + Yawrate);
  wheel3(RobotV - Yawrate);
  wheel4(RobotV + Yawrate);

}

void loop() {

  /********************模拟红外测距************************/

  int vo1 = analogRead(IRpin1) ;
  float volts1 = vo1 == 0 ? 1 : vo1 * 0.0048828125;
  double distance1 = 65 * pow(volts1, -1.10);
  int vo2 = analogRead(IRpin2) ;
  float volts2 = vo2 == 0 ? 1 : vo2 * 0.0048828125;
  double distance2 = 65 * pow(volts2, -1.10);
  int vo3 = analogRead(IRpin3) ;
  float volts3 = vo3 == 0 ? 1 : vo3 * 0.0048828125;
  double distance3 = 65 * pow(volts3, -1.10);
  int vo4 = analogRead(IRpin4) ;
  float volts4 = vo4 == 0 ? 1 : vo4 * 0.0048828125;
  double distance4 = 65 * pow(volts4, -1.10);
  int vo5 = analogRead(IRpin5) ;
  float volts5 = vo5 == 0 ? 1 : vo5 * 0.0048828125;
  double distance5 = 65 * pow(volts5, -1.10);
  int vo6 = analogRead(IRpin6) ;
  float volts6 = vo6 == 0 ? 1 : vo6 * 0.0048828125;
  double distance6 = 65 * pow(volts6, -1.10);
  int vo7 = analogRead(IRpin7) ;
  float volts7 = vo7 == 0 ? 1 : vo7 * 0.0048828125;
  double distance7 = 65 * pow(volts7, -1.10);
  int vo8 = analogRead(IRpin8) ;
  float volts8 = vo8 == 0 ? 1 : vo8 * 0.0048828125;
  double distance8 = 65 * pow(volts8, -1.10);
  int vo9 = analogRead(IRpin9) ;
  float volts9 = vo9 == 0 ? 1 : vo9 * 0.0048828125;
  double distance9 = 65 * pow(volts9, -1.10);

  /*****************************数字红外测距***************************/
  value1 = digitalRead(red1);
  value2 = digitalRead(red2);
  value3 = digitalRead(red3);
  value4 = digitalRead(red4);

  Serial.println(distance9);

  /********************************走位*************************************/
  if ( value1 == 0 && value2 == 0 && value3 == 0 && value4 == 0 && distance1 > 30 && distance2 > 50 && distance3 > 50 && distance4 > 36 && distance6 > 36 && distance8 > 36 && distance9 > 36 ) {
    //Serial.println("走位");

    if (endcount == 0)
    {
      myrand = random(1, 2);
      starttime = millis();
    }
    if (millis() - starttime < 200 * myrand)
    {
      Robot_wheel(0, 60);
      endcount = 1;
    }
    if ((millis() - starttime > 500) && (millis() - starttime) < myrand * 5000000)
    {
      count = 0;
      Serial.print("走位    ");
      // Serial.println(count);
      Robot_wheel(70, 0);

    }
    if ((millis() - starttime) > myrand * 5000)
    {
      endcount = 0;
    }
  }
  /*******************************防掉*******************************/
  if ((value1 == 1 || value2 == 1) ) {
    Robot_wheel(-100, 0);
    endcount = 0;

    count += 1;
    Serial.print("防掉    ");
    //Serial.println(count);
    /**************避免防掉进入死循环******************/
    if (count > 300) {
      door = 1;
      count = 0;
    }
    /**********************************************/

  }
  //  if ((value3 == 1 || value4 == 1) && value1 == 0 && value2 == 0) {
  //    Robot_wheel(50, 0);
  //    endcount = 0;
  //  }
  /*********************************进攻,防掉**********************************/
  if ( (value1 == 0) && (value2 == 0)) {

    if ( (distance1 < 30) || ((distance1 < 30) && (distance2 < 40) ) || ((distance1 < 30) && (distance3 < 40) ) || ((distance1 < 30) && (distance4 < 40) ) || ((distance1 < 30) && (distance6 < 40) )) {
      //Serial.println("冲");
      Robot_wheel(150, 0);
    }
    else if ((distance6 < 36 )  ) {
      //Serial.println("左2");
      Robot_wheel(0, 130);
    }
    else if (distance8 < 40 ) {
      //Serial.println("左3");
      Robot_wheel(0, 130);
    }
    else if (distance4 < 36 ) {
      //Serial.println("右2");
      Robot_wheel(0, -130);
    }
    else if (distance9 < 40  ) {
      //Serial.println("右3");
      Robot_wheel(0, -130);
    }
    else if (distance7 < 50  ) {
      //Serial.println("后侧");
      Robot_wheel(0, -150);
    }

    else  {

    }
    //    if ((distance2 < 50) && (distance1 > 30) && (distance3 > 50) && (distance4 > 50) && (distance6 > 50)) {
    //      //Serial.println("左1");
    //      Robot_wheel(0, 90);
    //    }
    //    if ((distance3 < 50) && (distance1 > 30) && (distance2 > 50) && (distance4 > 50) && (distance6 > 50)) {
    //
    //      //Serial.println("右1");
    //      Robot_wheel(0, -90);
    //    }
  }

  /********************************************判断台下-上台*************************************/
  if (distance1 < 50  && distance7 < 50 && distance5 < 51) {
    Serial.print("直接上台");
    Robot_wheel(80, 0);
    delay(1000);
    Robot_wheel(-130, 0);
    delay(1200);
  }
  if (distance1 < 50  && distance5 < 50) {
    door = 1;
    Serial.print("台下");
  }

  if (door == 1) {
    turn_count = 0;
    do
    {
      float volts7 = analogRead(IRpin7) * 0.0048828125;
      distance7 = 65 * pow(volts7, -1.10);
      //Serial.print(distance5 );
      //Serial.print("旋转");
      Robot_wheel(0, 60);

      turn_count += 1;
      //Serial.println( turn_count);
      Serial.print("旋转    ");
      //Serial.println(count);

    } while (distance7 > 50  && turn_count < 300);
    door = 0;

//    if (distance7 < 40) {
//      Serial.println("直接上台");
//      wheel1(70);
//      wheel2(70);
//      wheel3(70);
//      wheel4(70);
//      delay(500);
//      wheel1(-130);
//      wheel2(-130);
//      wheel3(-130);
//      wheel4(-130);
//      delay(1300);
//      count = 0;
//    }


  }

}


/**********************************调频率***********************************/
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
    if (pin == 11 || pin == 12 || pin == 13) //Timer1
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
