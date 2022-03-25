#include "MPU9250.h"
MPU9250 mpu;

// Initialize variables

float YAW,YAWfilter;

float offset_yaw = -60;
float I_YAW = 0; 
boolean mpusetup = false;



void mpu_setup() {
  Wire.begin();
  delay(200);
  if (!mpu.setup(0x68)) {  // change to your own address
    long start = millis();
    while (millis() - start < 5000) {
      Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
      delay(1000);
    }
  }

  mpu.setAccBias(-87.91, -7.44, -30.48);
  mpu.setGyroBias(-1.65, 1.09, 0.7);
  mpu.setMagBias(223.69, 28.85, -180.51);
  mpu.setMagScale(1.05,0.98,0.98);
  mpu.setMagneticDeclination(0.26);

}

void motion_sense(){
    if (mpu.update()) {
    static uint32_t prev_ms = millis();
    if (millis() > prev_ms + 25) {
    YAW = mpu.getYaw(), 2;
    YAWfilter = 0.4*YAW + YAWfilter*0.6;
      prev_ms = millis();
    }
  }
  }
