byte motorSpeed= 255;  // change this (0-255) to control the speed of the motors
  // Left Motor 
  const int leftDirControl1 = 10;
  const int leftDirControl2 = 11;
  const int leftSpeedControlPin = 4; // Needs to be a PWM pin to be able to control motor speed

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);

  //Define L298N Dual H-Bridge Motor Controller Pins
  pinMode(leftDirControl1,OUTPUT);
  pinMode(leftDirControl2,OUTPUT);
  pinMode(leftSpeedControlPin,OUTPUT);

  motorSpeed = 0;
  analogWrite(leftSpeedControlPin, motorSpeed); // sets speed via PWM 
  digitalWrite(leftDirControl1,LOW);
  digitalWrite(leftDirControl2,LOW);
  Serial.println("All Motors STOPPED");
  delay(1000);
  
}
   
void loop() {
 // same code as dcMotorTest, but uses function calls.  call functions with motor speed
    stopMotor();
    delay(500); 
    motorSpeed = 140;         //Sets speed variable via PWM = 140;
    spinMotorClockwise(motorSpeed);
    delay(1000); 
    stopMotor();
    delay(500); 
    motorSpeed = 140;         //Sets speed variable via PWM = 140;
    spinMotorCounterClockwise(motorSpeed);
    delay(1000); 
     
 }

//------------------------------------------------------------------------
 int spinMotorClockwise(int spinSpeed)
  {
    analogWrite(leftSpeedControlPin, spinSpeed);//Sets speed variable via PWM
    digitalWrite(leftDirControl1, LOW);
    digitalWrite(leftDirControl2, HIGH);
    Serial.print("Clockwise with a speed of ");
    Serial.println(spinSpeed);
    Serial.println("   "); // Creates a blank line printed on the serial monitor
  }

int spinMotorCounterClockwise(int spinSpeed)
  {
    analogWrite(leftSpeedControlPin, spinSpeed);//Sets speed variable via PWM
    digitalWrite(leftDirControl1, HIGH);
    digitalWrite(leftDirControl2, LOW);
    Serial.print("CounterClockwise with a speed of ");
    Serial.println(spinSpeed);
    Serial.println("   ");
  }

void stopMotor()
  {
    analogWrite(leftSpeedControlPin, 0);//Sets speed variable via PWM
    digitalWrite(leftDirControl1, LOW);
    digitalWrite(leftDirControl2, LOW);
    Serial.println("All Motors STOPPED"); 
    Serial.println("   ");
  }
