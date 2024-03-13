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
#define BUTTON_2_PIN 6
#define BUTTON_3_PIN 7
#define BUTTON_4_PIN 8
#define BUTTON_5_PIN 9
#define BUTTON_6_PIN 18
const int brocheLED = 10;
int IntLum = 60;

// Variable(s)
int old_encoder = 0;

Encoder myEncoder(DT_PIN, CLK_PIN);

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
  pinMode(BUTTON_6_PIN, INPUT_PULLUP);
  pinMode(brocheLED, OUTPUT);
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

  if (digitalRead(BUTTON_1_PIN) == 0){ // button
    Keyboard.write('Y');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 1 pressed");
    while (digitalRead(BUTTON_1_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  if (digitalRead(BUTTON_2_PIN) == 0){ // button
    Keyboard.write('Z');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 2 pressed");
    while (digitalRead(BUTTON_2_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  if (digitalRead(BUTTON_3_PIN) == 0){ // button
    Keyboard.write('A');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 3 pressed");
    while (digitalRead(BUTTON_3_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  if (digitalRead(BUTTON_4_PIN) == 0){ // button
    Keyboard.write('B');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 4 pressed");
    while (digitalRead(BUTTON_4_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  if (digitalRead(BUTTON_5_PIN) == 0){ // button
    Keyboard.write('C');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 5 pressed");
    while (digitalRead(BUTTON_5_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  if (digitalRead(BUTTON_6_PIN) == 0){ // button
    Keyboard.write('D');
    IntLum = 60;
    analogWrite(brocheLED, IntLum);
    Serial.println("Button 6 pressed");
    while (digitalRead(BUTTON_6_PIN) == 0){
      delay(100);
    }
    for (int i = 0; i < 12; i++) {
      analogWrite(brocheLED, IntLum);
      delay(50);
      IntLum = IntLum - 5;
    }
    delay(50);
    analogWrite(brocheLED, 0);
  }

  delay(100);
}
