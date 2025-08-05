// Summary:
// 1) reads a temperature sensor
// 2) prints raw value, voltage, and temp to the serial monitor
// 3) activates 0, 1, 2, or 3 LEDs depending on how much the temp rises above the baseline

const int sensorPin = A0;                              // set analog pin a0 for sensor
const float baselineTemp = 128;                       // base temp ref in C

void setup(){                                          // runs once at startup
  Serial.begin(9600);                                  // start/open serial port at 9600 baud
  for(int pinNumber = 2; pinNumber<5; pinNumber++){    // set pins 2-4 as output, turn off
    pinMode(pinNumber, OUTPUT);                        // make pin output
    digitalWrite(pinNumber, LOW);                      // set pin low
  }
}

void loop(){                                           // main loop
  int sensorVal = analogRead(sensorPin);               // read temp sensor
  Serial.print("Sensor Value: ");                      // print raw analaog value
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) *5.0;             // convert to volts
  Serial.print(", Volts: ");                          // print voltage
  Serial.print(voltage);
  Serial.print(", degrees C: ");                       // label for temp
  float temperature = (voltage - .5) * 100;            // calc temp from voltage
  Serial.println(temperature);                         // print temp
  if(temperature < baselineTemp+2){                    // if temp < base + 2C, all off
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);                              // if temp between base +2 and base +4, light one
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){    
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);                               // if temp between base +4 and base +6, light two
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+6){              // if temp > or = tp base +6, light all
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);                                              // short delay
}
