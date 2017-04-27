#include <CurieIMU.h>
#include <BMI160.h>

int ax, ay, az, gx, gy, gz;
int left[7][7] = {
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}
};
int right[7][7] = {
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}
};

void setup() {
  Serial.begin(9600);
  CurieIMU.begin(); //Initialize the Curie IMU.
  CurieIMU.setGyroRate(1600); //Set to second highest frequency to match with accelerometer.
  CurieIMU.setAccelerometerRate(1600); //Set to highest frequency.
  CurieIMU.autoCalibrateGyroOffset(); //Calibrate gyro.
  CurieIMU.autoCalibrateAccelerometerOffset(X_AXIS,0); //Calibrate X axis of accelerometer.
  CurieIMU.autoCalibrateAccelerometerOffset(Y_AXIS,0); //Calibrate Y axis of accelerometer.
  CurieIMU.autoCalibrateAccelerometerOffset(Z_AXIS,1); //Calibrate Z axis of accelerometer.
}

void loop() {
  // put your main code here, to run repeatedly:
  CurieIMU.readMotionSensor(ax, ay, az, gx, gy, gz);
  Serial.print(ax);Serial.print(",");Serial.print(ay);Serial.print(",");Serial.print(az);Serial.print(":");Serial.print(gx);Serial.print(",");Serial.print(gy);Serial.print(",");Serial.println(gz);
}
