// ARDUINO PROJECT 04- COLOR MIXING LAMP

// Set Constants 
// - for input pins
const int greenLEDPin= 9;
const int redLEDPin= 10;
const int blueLEDPin= 11;
// - for output pins
const int redSensorPin= A0;
const int greenSensorPin= A1;
const int blueSensorPin= A2;

// Add variables 
// - for output values (used to fade LEDs)
int redValue= 0;
int greenValue= 0;
int blueValue= 0;
// - for incoming sensor values
int redSensorValue= 0;
int greenSensorValue= 0;
int blueSensorValue= 0;

// Setting direction of digital pins and setting up serial point
// - set up serial communication to display values of sensors in serial monitor
void setup() {
  Serial.begin(9600);
  // Define LED pins as output using pinMode()
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

// Reading value of each light sensor
// - read sensor values with analogRead() and store in variables
void loop() {
  redSensorValue= analogRead(redSensorPin);
  delay(5);
  greenSensorValue= analogRead(greenSensorPin);
  delay(5);
  blueSensorValue= analogRead(blueSensorPin);

// Report sensor readings to the computer
// - print sensor values (/t does this on single line)
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);

// Converting the sensor readings
  redValue= redSensorValue/4;
  greenValue= greenSensorValue/4;
  blueValue= blueSensorValue/4;

// Report the caluclated LED light levels
  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);

// Set LED light levels
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}