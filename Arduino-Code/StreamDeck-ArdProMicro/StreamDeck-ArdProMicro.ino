// Libraries
#include <Encoder.h>
#define HID_CUSTOM_LAYOUT
#define LAYOUT_FRENCH
#include <HID-Project.h>

// Encoder pin
#define DT_PIN 3
#define CLK_PIN 4
#define SW_PIN 2

//Buttons Pins
#define BUTTON_1_PIN 5

// Variable(s)
int old_encoder = 0;

Encoder myEncoder(DT_PIN, CLK_PIN);

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
}

// Loop
void loop() {
  long encoderValue = myEncoder.read();

  //Serial.println(encoderValue);

  if (encoderValue != old_encoder){
    if (encoderValue < old_encoder){
      Consumer.write(MEDIA_VOLUME_UP); // Volume up
      old_encoder = encoderValue;
    }
    else if (encoderValue > old_encoder){
      Consumer.write(MEDIA_VOLUME_DOWN); // Volume down
      old_encoder = encoderValue;
    }
  }

  if (digitalRead(SW_PIN) == LOW) {
    Consumer.write(MEDIA_VOLUME_MUTE); // Mute/Unmute
    delay(500);
  }
  if (digitalRead(BUTTON_1_PIN) == 0){
    Keyboard.write('Y');
    while (digitalRead(BUTTON_1_PIN) == 0){
      delay(100);
    }
    delay(50);
  }

  delay(150);
}
