#include <IRremote.h>

#define IR_RECEIVE_PIN 2

#define IR_BUTTON_BLUE 36
#define IR_BUTTON_RED 37
#define IR_BUTTON_GREEN 38
#define IR_BUTTON_YELLOW 39

#define OUT_PIN_BLUE 6
#define OUT_PIN_RED 7
#define OUT_PIN_GREEN 8
#define OUT_PIN_YELLOW 9

byte outBlueState = LOW;
byte outRedState = LOW;
byte outGreenState = LOW;
byte outYellowState = LOW;

void setup() {
  //Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(OUT_PIN_BLUE,   OUTPUT);
  pinMode(OUT_PIN_RED,    OUTPUT);
  pinMode(OUT_PIN_GREEN,  OUTPUT);
  pinMode(OUT_PIN_YELLOW, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    //Serial.println(IrReceiver.decodedIRData.command);

    
    switch (command) {
      case IR_BUTTON_BLUE: {
        outBlueState = (outBlueState == LOW) ? HIGH : LOW;
        digitalWrite(OUT_PIN_BLUE, outBlueState);
        break;
      }
      case IR_BUTTON_RED: {
        outRedState = (outRedState == LOW) ? HIGH : LOW;
        digitalWrite(OUT_PIN_RED, outRedState);
        break;
      }
      case IR_BUTTON_GREEN: {
        outGreenState = (outGreenState == LOW) ? HIGH : LOW;
        digitalWrite(OUT_PIN_GREEN, outGreenState);
        break;
      }
      case IR_BUTTON_YELLOW: {
        outYellowState = (outYellowState == LOW) ? HIGH : LOW;
        digitalWrite(OUT_PIN_YELLOW, outYellowState);
        break;
      }
      default: {
        // do nothing
      }
    }
    delay(1000);
    IrReceiver.resume();
  }
}
