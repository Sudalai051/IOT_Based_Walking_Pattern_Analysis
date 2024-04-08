#include <Adafruit_MPU6050.h>

#include<Wire.h> 
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"
#define BLYNK_TEMPLATE_ID "TMPL1utlRtzI"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "HFgc_qU6pmdyRKpfmiQrPha_3ze-FdQC"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 // I2C address of the MPU-6050 
 char auth[] = "HFgc_qU6pmdyRKpfmiQrPha_3ze-FdQC"; 
 

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OPPO F21 Pro";
char pass[] = "Sudalai@051";

const int MPU_addr2=0x69; 
int16_t AcX, AcY, AcZ, Tmp; 
int16_t AcX1, AcY1, AcZ1, Tmp1; 
int16_t AcX2, AcY2, AcZ2, Tmp2; 
int i=1; 
void setup() { 
   Blynk.begin(auth, ssid, pass);
  Wire.begin(); 
  Wire.beginTransmission(MPU_addr2); 
 Wire.write(0x6B);  // PWR_MGMT_1 register 
  Wire.write(0);     // set to zero (wakes up the MPU-6050) 
 Wire.endTransmission(true); 
  Serial.begin(9600); 
  pinMode(14,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(13,OUTPUT);   
} 
void loop() { 
   Blynk.run();
  if(i>3){ 
    i=1; 
  } 
  if(i==1){ 
    Serial.print("1 is high"); 
    digitalWrite(12,HIGH); 
    digitalWrite(13,LOW); 
    digitalWrite(14,LOW); 
    Wire.beginTransmission(MPU_addr2); 
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H) 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr2, 14, true); // request a total of 14 registers 
    float AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
    float AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L) 
    float AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
    Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
    Serial.print(" AcX: ");  
    Serial.print(AcX / 16384); 
    Blynk.virtualWrite(V0,AcX / 16384);
    Serial.print(" AcY: ");  
    Serial.print(AcY / 16384); 
     Blynk.virtualWrite(V1,AcY / 16384);
    Serial.print(" AcZ: ");  
    Serial.print(AcZ / 16384);
     Blynk.virtualWrite(V2,AcZ / 16384); 
    Serial.print(" Temp: ");  
    Serial.println(Tmp / 340.00 + 36.53); 
    if((-9.543<AcX1> -9.789)&&(-1.654<AcY1>-1.890)&&(0<AcZ1>-0.456)){
    Blynk.virtualWrite(V10,"Normal");
    }
     else{
      Blynk.virtualWrite(V10,"Abnormal");
     }
    delay(1000); 
  } 
  else if(i==2){ 
    Serial.print("2 is high"); 
    digitalWrite(12,LOW); 
    digitalWrite(13,HIGH); 
    digitalWrite(14,LOW); 
    Wire.beginTransmission(MPU_addr2); 
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H) 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr2, 14, true); // request a total of 14 registers 
    float AcX1 = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
    float AcY1 = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L) 
    float AcZ1 = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
    Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
    Serial.print(" AcX1: ");  
    Serial.print(AcX1 / 16384); 
     Blynk.virtualWrite(V3,AcX1 / 16384);
    Serial.print(" AcY1: ");  
    Serial.print(AcY1 / 16384);
     Blynk.virtualWrite(V4,AcY1 / 16384); 
    Serial.print(" AcZ1: ");  
    Serial.print(AcZ1 / 16384);
     Blynk.virtualWrite(V5,AcZ1 / 16384); 
    Serial.print(" Temp1: ");  
    Serial.println(Tmp1 / 340.00 + 36.53); 
     Blynk.virtualWrite(V10,Tmp1 / 340.00 + 36.53);
     if((-9.543<AcX1> -9.789)&&(-1.654<AcY1>-1.890)&&(0<AcZ1>-0.456)){
    Blynk.virtualWrite(V10,"Normal");
    }
     else{
      Blynk.virtualWrite(V10,"Abnormal");
     }
    delay(1000); 
  } 
  else if(i==3){ 
    Serial.print("3 is High"); 
    digitalWrite(12,LOW); 
    digitalWrite(13,LOW); 
    digitalWrite(14,HIGH); 
    Wire.beginTransmission(MPU_addr2); 
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H) 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr2, 14, true); // request a total of 14 registers 
    float AcX2 = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
    float AcY2 = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L) 
    float AcZ2 = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
    Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
    Serial.print(" AcX2: ");  
    Serial.print(AcX2 / 16384); 
    Blynk.virtualWrite(V6,AcX2 / 16384);
    Serial.print(" AcY2: ");  
    Serial.print(AcY2 / 16384);
    Blynk.virtualWrite(V7,AcY2 / 16384); 
    Serial.print(" AcZ2: ");  
    Serial.print(AcZ2 / 16384); 
     Blynk.virtualWrite(V8,AcZ2 / 16384);
    Serial.print(" Temp2: ");  
    Serial.println(Tmp / 340.00 + 36.53);
    if((-9.543<AcX1> -9.789)&&(-1.654<AcY1>-1.890)&&(0<AcZ1>-0.456)){
      Blynk.virtualWrite(V10,"Normal");
    }
     else{
      Blynk.virtualWrite(V10,"Abnormal");
     } 
    delay(1000); 
  } 
  i++; 
}
