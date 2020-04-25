//libraries
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

//led strips
#define PIN1 24
#define PIN2 25
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(60, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(60, PIN2, NEO_GRB + NEO_KHZ800);

//servos
Servo servoLR1;
Servo servoUD1;
Servo servoLR2;
Servo servoUD2;
Servo angerservo;
Servo mouthservo;

//servos poses
int pos0 = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

//red leds anger
int leda = 3;
int ledb = 2;
int ledc = 4;
int ledd = 5;
//red leds heart
int lede = 22;
int ledf = 23;


void setup() {
  // put your setup code here, to run once:
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

strip1.begin();
strip2.begin();
strip1.setBrightness(10);
strip2.setBrightness(10);
strip1.show(); // Initialize all pixels to 'off'
strip2.show();

Serial.begin(9600);

/*servoUD1.attach(6);
servoLR1.attach(7);
servoUD2.attach(8);
servoLR2.attach(9);
angerservo.attach(10);
mouthservo.attach(11);*/

pinMode(leda, OUTPUT);
pinMode(ledb, OUTPUT);
pinMode(ledc, OUTPUT);
pinMode(ledd, OUTPUT);
pinMode(lede, OUTPUT);
pinMode(ledf, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
servoLR1.attach(7);
servoLR2.attach(9);
servoUD1.attach(6);
servoUD2.attach(8);
delay(1000);
eyesSlow();
eyesSlow();
servoLR1.detach();
servoLR2.detach();
servoUD1.detach();
servoUD2.detach();
mouthservo.detach();
angerservo.detach();
delay(10);
signals(strip1.Color(127, 127, 127), 50);
signals(strip2.Color(127, 127, 127), 50);
angerservo.attach(10);
//delay(5);
angerSlow();
angerSlow();
mouthservo.attach(11);
//delay(5);
mouthSlow();
mouthSlow();
servoLR1.attach(7);
servoLR2.attach(9);
servoUD1.attach(6);
servoUD2.attach(8);
delay(1000);
eyesAvrage();
eyesAvrage();
servoLR1.detach();
servoLR2.detach();
servoUD1.detach();
servoUD2.detach();
mouthservo.detach();
angerservo.detach();
delay(10);
signals(strip1.Color(127, 127, 127), 50);
signals(strip2.Color(127, 127, 127), 50);
angerservo.attach(10);
//delay(5);
angerAvrage();
angerAvrage();
mouthservo.attach(11);
//delay(5);
mouthAvrage();
mouthAvrage();
servoLR1.attach(7);
servoLR2.attach(9);
servoUD1.attach(6);
servoUD2.attach(8);
delay(1000);
eyesFast();
eyesFast();
eyesFast();
servoLR1.detach();
servoLR2.detach();
servoUD1.detach();
servoUD2.detach();
mouthservo.detach();
angerservo.detach();
delay(10);
signals(strip1.Color(127, 127, 127), 50);
signals(strip2.Color(127, 127, 127), 50);
angerservo.attach(10);
//delay(5);
angerFast();
angerFast();
mouthservo.attach(11);
//delay(5);
mouthFast();
mouthFast();
mouthFast();
}


void eyesSlow(){ 
for (pos1 = 90; pos1 <= 110; pos1 += 1){
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
  
}
for (pos1 = 110; pos1 >= 90; pos1 -= 1) {
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}

for (pos2 = 50; pos2 <= 120; pos2 += 1) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
for (pos2 = 120; pos2 >= 90; pos2 -= 1) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
}

void eyesAvrage(){ 
for (pos1 = 90; pos1 <= 110; pos1 += 3){
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
  
}
for (pos1 = 110; pos1 >= 90; pos1 -= 3) {
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}

for (pos2 = 50; pos2 <= 120; pos2 += 3) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
for (pos2 = 120; pos2 >= 90; pos2 -= 3) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
}

void eyesFast(){ 
for (pos1 = 90; pos1 <= 110; pos1 += 6){
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
  
}
for (pos1 = 110; pos1 >= 90; pos1 -= 6) {
  pos3 = 180 - pos1;
  servoUD1.write(pos1);
  servoUD2.write(pos3);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}

for (pos2 = 50; pos2 <= 120; pos2 += 6) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
for (pos2 = 120; pos2 >= 90; pos2 -= 6) {
  servoLR1.write(pos2);
  servoLR2.write(pos2);
  //delay(10);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(40);
}
}
void angerSlow(){
  for (pos0 = 0; pos0 <= 90; pos0 += 3) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);             
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
  }
  for (pos0 = 90; pos0 >= 0; pos0 -= 3) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);              
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
}   
}

void angerAvrage(){
  for (pos0 = 0; pos0 <= 90; pos0 += 5) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);             
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
  }
  for (pos0 = 90; pos0 >= 0; pos0 -= 5) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);              
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
}   
}

void angerFast(){
  for (pos0 = 0; pos0 <= 90; pos0 += 8) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);             
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
  }
  for (pos0 = 90; pos0 >= 0; pos0 -= 8) {

      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      angerservo.write(pos0);              
      digitalWrite(leda, HIGH);
      digitalWrite(ledb, HIGH);
      digitalWrite(ledc, HIGH);
      digitalWrite(ledd, HIGH); 
      delay(30);
      digitalWrite(leda, LOW);
      digitalWrite(ledb, LOW);
      digitalWrite(ledc, LOW);
      digitalWrite(ledd, LOW);
      delay(10);
}   
}

void mouthSlow(){
  for (pos4 = 0; pos4 <= 180; pos4 += 3){
  mouthservo.write(pos4);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
}
for (pos4 = 180; pos4 >= 180; pos4 -= 3){
  mouthservo.write(pos4);  
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
}
}

void mouthAvrage(){
  for (pos4 = 0; pos4 <= 180; pos4 += 6){
  mouthservo.write(pos4);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
}
for (pos4 = 180; pos4 >= 180; pos4 -= 6){
  mouthservo.write(pos4);  
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
}
}

void mouthFast(){
  for (pos4 = 0; pos4 <= 180; pos4 += 8){
  mouthservo.write(pos4);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
}
for (pos4 = 180; pos4 >= 180; pos4 -= 8){
  mouthservo.write(pos4);  
  digitalWrite(lede, LOW);
  digitalWrite(ledf, LOW);
  delay(20);
  digitalWrite(lede, HIGH);
  digitalWrite(ledf, HIGH);
  delay(20);
}
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
}

void signals(uint32_t c, uint8_t wait) {
    for (int q=0; q <10; q++) {
      for (uint16_t i=0; i < strip1.numPixels(); i=i+10) {
        strip1.setPixelColor(i+q, c);    //turn every fifty pixel on
      }
      for (uint16_t i=0; i < strip2.numPixels(); i=i+10) {
        strip2.setPixelColor(i+q, c);    //turn every fifty pixel on
      }
      digitalWrite(lede, HIGH);
      digitalWrite(ledf, HIGH);
      delay(30);
      digitalWrite(lede, LOW);
      digitalWrite(ledf, LOW);
      delay(30);
      strip1.show();
      strip2.show();

      delay(wait);

      for (uint16_t i=0; i < strip1.numPixels(); i=i+10) {
        strip1.setPixelColor(i+q, 0);        //turn every fifty pixel off
      }
      for (uint16_t i=0; i < strip2.numPixels(); i=i+10) {
        strip2.setPixelColor(i+q, 0);        //turn every fifty pixel off
      }
    }
  }
