#include <ESP32Servo.h>

#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

// Connect servo vcc pin to 5v, gnd pin to gnd and control pin to i/o 2
const int servoPin = 2;

// Create servo object to control a servo
Servo myServo;

void setup() {
  // Start Serial monitor
  Serial.begin(115200);

  // Set bluetooth name of your device, this is also how your device's name going to look like on dabble app
  Dabble.begin("GEZGIN");

  myServo.setPeriodHertz(50); // Standart 50hz servo
  myServo.attach(servoPin, 500, 2400); // Min ve Max values 

}

void loop() {
  // This function is used to refresh data obtained from smartphone. Hence calling this function is mandatory in order to get data properly from your mobile.
  Dabble.processInput();


  // We're going to use joystick mode on app, so we should pick joystick mode

  float valX = GamePad.getXaxisData(); // Get X axis value
  float valY = GamePad.getYaxisData(); // Get Y axis value
  float angle = GamePad.getAngle(); // Get angle value
  float radius = GamePad.getRadius(); // Get radius value
  
  // Print X axis, Y axis, angle and radius values 

  Serial.print("ValX: ");
  Serial.println(valX);

  Serial.print("ValY: ");
  Serial.println(valY);

  Serial.print("Angle: ");
  Serial.println(angle);

  Serial.print("Radius: ");
  Serial.println(radius);

  // Scale X axis value for use with the servo
  int position = map(valX, 6, -6, 0, 180); // Get x axis value(-6 to +6) set it to servo's 0-180 degree spinning angle

  // Print position value
  Serial.print("Position: ");
  Serial.println(position);

  //Sets the servo position according to the scaled value
  myServo.write(position);

  delay(15); // Add a short delay for the update
}


