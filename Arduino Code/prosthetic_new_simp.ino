#include <Servo.h>
#include "HCPCA9685.h"
#define  I2CAdd 0x40
HCPCA9685 HCPCA9685(I2CAdd);
int ind_cl = 13;
int mid_cl = 11;
int rin_cl = 5;
int lit_cl = 1;
int thu_cl = 15;

int ind_val;
int mid_val;
int rin_val;
int lit_val;
int thu_val;

int ind_ang;
int mid_ang;
int rin_ang;
int lit_ang;
int thu_ang;

int ind_sensor = A2;
int mid_sensor = A3;
int rin_sensor = A4;
int lit_sensor = A5;
int thu_sensor = A1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);

  HCPCA9685.Servo(ind_cl, 0);
  HCPCA9685.Servo(mid_cl, 0);
  HCPCA9685.Servo(rin_cl, 0);
  HCPCA9685.Servo(lit_cl, 0);
  HCPCA9685.Servo(thu_cl, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  ind_val = analogRead(ind_sensor);
  mid_val = analogRead(mid_sensor);
  rin_val = analogRead(rin_sensor);
  lit_val = analogRead(lit_sensor);
  thu_val = analogRead(thu_sensor);
  
  ind_ang = map(ind_val,750,900,360,0);
  mid_ang = map(mid_val,750,880,360,0);
  rin_ang = map(rin_val,890,960,360,0);
  lit_ang = map(lit_val,910,975,360,0);
  thu_ang = map(thu_val,720,790,360,0);

  HCPCA9685.Servo(ind_cl, ind_ang);
  HCPCA9685.Servo(mid_cl, mid_ang);
  HCPCA9685.Servo(rin_cl, rin_ang);
  HCPCA9685.Servo(lit_cl, lit_ang);
  HCPCA9685.Servo(thu_cl, thu_ang);

  Serial.print(ind_val);
  Serial.print("    ");
  Serial.print(mid_val);
  Serial.print("    ");
  Serial.print(rin_val);
  Serial.print("    ");
  Serial.print(lit_val);
  Serial.print("    ");
  Serial.print(thu_val);
  Serial.println("    "); 

}
