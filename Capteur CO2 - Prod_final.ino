//Configuration :
//Servo : 8
//Sensor : I2C
//écran LCD : I2C

//Bibliothèques à installer pour le fonctionnement :
// DHT by Adafruit
// Grove RGB
// SGP 30
 
//Bibliothèques de pour le capteur de CO2
#include <Wire.h>
#include "Adafruit_SGP30.h"
Adafruit_SGP30 sgp;

//Bibliothèques ServoMoteur
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int servo_pin = 8;  // Branchement du servo

//Bibliothèques écran LCD
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD
rgb_lcd lcd; // Création d'un objet lcd, facilitation du programme

//Bibliothèques DHT
#include <DHT.h>
#define branchement 6    // La ligne de données de notre DHT22 sera branchée sur la pin D6 de notre Arduino
#define ref DHT22             // Spécification du type de DHT utilisé (ici, ce sera un DHT22, comme indiqué)
DHT dht(branchement, ref); // Instanciation de la librairie DHT


void setup() {
  //Setup du servomoteur
  myservo.attach(servo_pin);  //Définition du servo
//Setup du capteur de CO2, sur un port I2C Grove
  Serial.begin(115200);
  sgp.begin();
  delay(200);
//Setup écran LCD
lcd.begin(16, 2);   // Détermination nombre : collonnes, lignes
lcd.setRGB(255,229,0); // Configuration couleur écran LCD
lcd.setCursor(2,0);lcd.print("Capteur de CO2 "); //Première partie du message d'accueil
lcd.setCursor(2,1);lcd.print("Je demarre... ");//Deuxième partie du message d'accueil
delay(2000);
//Setup DHT22 (Température)
  dht.begin();
}

void loop() {
    sgp.IAQmeasure();
  if (sgp.eCO2 < 800) {
  lcd.setRGB(0,255,0);
  sgp.IAQmeasure(); // Première mesure
  lcd.setCursor(1,0);lcd.print("CO2 ");lcd.setCursor(5,0);lcd.print(sgp.eCO2);lcd.print(" ppm");//Affichage taux de CO2  sur le LCD
  lcd.setCursor(1,1);lcd.print("Temp ");lcd.setCursor(6,1);lcd.print((float)dht.readTemperature());lcd.print(" c");
  delay(1000);
  lcd.clear(); // Affichage température sur le LCD
  }

  //Si taux supérieur de CO2
    else {
  lcd.setRGB(255,0,0);
  myservo.write(180);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  sgp.IAQmeasure();
  lcd.setCursor(1,0);lcd.print("CO2 ");lcd.setCursor(5,0);lcd.print(sgp.eCO2);lcd.print(" ppm"); //Affichage taux de CO2  sur le LCD
  lcd.setCursor(1,1);lcd.print("Temp ");lcd.setCursor(6,1);lcd.print((float)dht.readTemperature());lcd.print(" c");delay(500);lcd.clear(); // Affichage température sur le LCD
  delay(1000);
  lcd.clear();
  }
}
