#include <Servo.h>

Servo myservo; // Create a servo object
int axeX = A0; // signal de l'axe X sur entrée A0 
int axeY = A1; // signal de l'axe Y sur entrée A1 
int BP7 = 7; // Bouton-poussoir en broche 7

void setup() {
  myservo.attach(9); // Attach the servo to pin 9
  pinMode (axeX, INPUT); // définition de A0 comme une entrée 
  pinMode (axeY, INPUT); // définition de A1 comme une entrée 
  pinMode (BP7, INPUT); // définition de 7 comme une entrée 
  digitalWrite(BP7, HIGH); // Activation de la résistance de Pull-Up interne de la carte Uno 
  Serial.begin (9600);
}

void loop() {
  // Gradually increase the speed in the clockwise direction
 // for (int i = 0; i <= 180; i++) {
 //  myservo.write(i);
  //delay(5); // Adjust this delay for slower or faster motion
 // }
//Define for bouton
  float X, Y;
  int Bouton;
  X = analogRead (axeX) * (5.0 / 1023.0);
  Y = analogRead (axeY) * (5.0 / 1023.0);
  Bouton = digitalRead (BP7);
 // Serial.print ("Axe X:"); Serial.print (X, 4); Serial.print ("V, ");
 // Serial.print ("Axe Y:"); Serial.print (Y, 4); Serial.print ("V, ");
  Serial.print ("Bouton:");
  if (Bouton==1)
  {
    Serial.println (" Aucune pression sur le bouton poussoir "); }
  else
  {
    Serial.println (" Bouton-poussoir actif ");
  }
  delay (500);
  Serial.print ("X: rotation de :"); Serial.print (X, 1); Serial.print ("V, ");
  Serial.print ("Y: rotation de :"); Serial.print (Y, 1); Serial.print ("V, ");
  int X_int = X;
  int Y_int = Y;
  int N = 0;
  int N2 = 180;
  switch (X_int) {
    case 0:
      Serial.print("Test\n");
      myservo.write(N++);
      break;
    case 3:
      Serial.print("Test 2\n");
      myservo.write(N2--);
      N2--;
      break;
  }
  switch (Y_int)
  {
    case 0:
      Serial.print("Test 2 is good\n");'
      break;
    case 3:
      Serial.print("Test 3 is good\n");
      break;
  }
 // delay(10); // Pause for 1 second
  
  // Gradually decrease the speed in the counterclockwise direction
  //for (int i = 180; i >= 0; i--) {
  //  myservo.write(i);
   // delay(10); // Adjust this delay for slower or faster motion
 // }
 // delay(10); // Pause for 1 second
}
