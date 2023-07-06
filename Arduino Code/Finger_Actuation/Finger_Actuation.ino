#include<Servo.h>
#define numOfValsRec 5 //our case 5 fingers (no. of sensors)
#define digitsPerValRec 1    //Per finger will have 1 number

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;


int valsRec[numOfValsRec]; //array of no. of values received
int stringLength = numOfValsRec * digitsPerValRec + 1; // 5 fingers*1  + $special character at the start of string(For eg: @10101)
int counter = 0;
bool counterStart = false; //Flag to understand when $ received counter starts
String receivedString;



void setup() {
  Serial.begin(9600);
  servoThumb.attach(1);
  servoIndex.attach(3);
  servoMiddle.attach(5);
  servoRing.attach(7);
  servoPinky.attach(9);

}

void receiveData() {
  while (!Serial.available())
  {
    printf("alt1");
   // char c = Serial.read(); // Reading characters
   int c = Serial.read();
    if (c == '$') {
      printf("in loop:");
      counterStart = true;
    }
    if (counterStart) {
      if (counter < stringLength) {
        receivedString = String(receivedString + c);
        counter++;
      }
      if (counter >= stringLength) {
        for (int i = 0; i < numOfValsRec; i++)
        {
          int num = (i * digitsPerValRec) + 1;
          valsRec[i] = receivedString.substring(num, num + digitsPerValRec).toInt();
        }
        receivedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}
void loop() {
  receiveData();
  if (valsRec[0] == 1) {
    servoThumb.write(180);
  } else {
    servoThumb.write(0);
  }
  if (valsRec[1] == 1) {
    servoIndex.write(180);
  } else {
    servoIndex.write(0);
  }
  if (valsRec[2] == 1) {
    servoMiddle.write(180);
  } else {
    servoMiddle.write(0);
  }
  if (valsRec[3] == 1) {
    servoRing.write(180);
  } else {
    servoRing.write(0);
  }
  if (valsRec[4] == 1) {
    servoPinky.write(180);
  } else {
    servoPinky.write(0);
  }
}
