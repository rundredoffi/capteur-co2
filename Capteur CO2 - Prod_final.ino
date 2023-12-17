//Bibliothèques de pour le capteur de CO2
#include <Wire.h>
#include "Adafruit_SGP30.h"

int var;// Variable pour avoir la valeur du capteur de CO2
Adafruit_SGP30 sgp;

//Bibliothèques ServoMoteur
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// Variable Servomoteur
int servo_pin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

//LEDS
#define redLed 9
#define greenLed 11

void setup() {
//Setup du capteur de CO2, sur un port I2C Grove
  Serial.begin(115200);
  if (! sgp.begin()){ // Recherche du capteur de CO2
    Serial.println("Le capteur n'a pas été trouvé pensé à le mettre sur un port I2C !");
    while (1);
    }
  Serial.print("Capteur trouvé sur un port I2C !");
  delay(200);
  }
  Serial.print("Capteur trouvé sur un port I2C !");
int counter = 0;
// Fin du setup capteur de CO2
//Setup du servomoteur
  myservo.attach(servo_pin);  //Permet de définir le port de position ServoMoteur
//Fin du setup servomoteur
//Setup LEDS
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
//Fin du setup LEDS
}

void loop() {
  //Partie Capteur Arduino, requete d'information
if (! sgp.IAQmeasure()) {
    Serial.println("Erreur de mesure");
    return;
  }
  Serial.println("");
  Serial.print("Taux de CO2 "); Serial.print(sgp.eCO2); Serial.println(" ppm");
  var = sgp.eCO2;

  if (! sgp.IAQmeasureRaw()) {
    Serial.println("Erreur de mesure");
    return;
  }
  //Fin requete CO2
  //Taux inférieur de CO2
    while (var > 799) {
    digitalWrite( greenLed,   HIGH  ) ; // Led Rouge ON
    delay(15);                           // waits for the servo to get there
  }
  //Lorsque le taux de CO2 est trop haut
  while (var < 799) {
    digitalWrite( redLed,   HIGH  ) ; // Led Rouge ON
    myservo.write(180);                  // sets the servo position according to the scaled value
    delay(15);                           // waits for the servo to get there
  }
    while (var < 799) {
    digitalWrite( redLed,   HIGH  ) ; // Led Rouge ON
    myservo.write(180);                  // sets the servo position according to the scaled value
    delay(15);                           // waits for the servo to get there
  }
}
