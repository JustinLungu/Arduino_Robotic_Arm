#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40); // default address 0x40

#define SERVOMIN  125  // 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625  // 'maximum' pulse length count (out of 4096)

// Define the straight position for each servo
const int STRAIGHT_POSITION = 45;

// Servo channels
const int CLAW = 11;
const int WRIST_ROTATE = 8;
const int WRIST_UP_DOWN = 13;
const int ELBOW = 7;
const int BASE_UP_DOWN = 15;
const int BASE_ROTATE = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
  // Move all servos to the straight position
  makeArmStraight();
  
  // Add a delay to avoid continuous operation
  delay(5000);
}

void makeArmStraight() {
  //board1.setPWM(CLAW, 0, angleToPulse(STRAIGHT_POSITION));
  //board1.setPWM(WRIST_ROTATE, 0, angleToPulse(STRAIGHT_POSITION));
  //board1.setPWM(WRIST_UP_DOWN, 0, angleToPulse(STRAIGHT_POSITION));
  //board1.setPWM(ELBOW, 0, angleToPulse(STRAIGHT_POSITION));
  board1.setPWM(BASE_UP_DOWN, 0, angleToPulse(STRAIGHT_POSITION));
  //board1.setPWM(BASE_ROTATE, 0, angleToPulse(STRAIGHT_POSITION));
}

int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
  Serial.print("Angle: ");
  Serial.print(ang);
  Serial.print(" pulse: ");
  Serial.println(pulse);
  return pulse;
}