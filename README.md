# Projet Capteur CO2

Bienvenue dans le projet Capteur CO2 ! Ce projet vise à mesurer les niveaux de dioxyde de carbone (CO2) dans l'environnement à l'aide d'un capteur dédié.

## Table des matières

- [Matériel utilisé](#matériel-utilisé)
- [Configuration](#configuration)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Contributions](#contributions)
- [Licence](#licence)

## Matériel utilisé

- **Capteur de CO2:** [SGP 30 Grove](https://www.gotronic.fr/art-capteur-de-gaz-sgp30-grove-101020512-28427.htm)
- **Microcontrôleur:** [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3)
- **Afficheur:** [Écran LCD Grove](https://www.gotronic.fr/art-afficheur-lcd-2x16-grove-104030001-21308.htm)
- **Autres composants:** [ServoMoteur](https://www.gotronic.fr/art-servomoteur-grove-316010005-20640.htm)

## Configuration

Avant de commencer, assurez-vous d'avoir tous les composants matériels nécessaires pour le projet. Voici comment configurer chaque composant en tenant compte des ports de connexion spécifiés :

### Capteur de CO2 (SGP 30 Grove)

1. Connectez le capteur de CO2 au port I2C sur le microcontrôleur.
2. Assurez-vous que le capteur est alimenté correctement selon les spécifications du fabricant.
3. Consultez la documentation du capteur pour obtenir des détails sur la communication avec le microcontrôleur.

### Microcontrôleur (Arduino Uno)

1. Assurez-vous d'avoir le logiciel Arduino IDE installé sur votre ordinateur.
2. Connectez l'Arduino Uno à votre ordinateur via un câble USB.
3. Téléversez le code du projet sur l'Arduino en utilisant l'IDE Arduino.

### Afficheur LCD (Écran LCD Grove)

1. Connectez l'afficheur LCD au port I2C sur le microcontrôleur.
2. Assurez-vous que l'afficheur est alimenté correctement selon les spécifications du fabricant.
3. Consultez la documentation de l'afficheur pour obtenir des détails sur l'initialisation et l'affichage de données.

### ServoMoteur

1. Connectez le ServoMoteur au port 8 sur le microcontrôleur.
2. Assurez-vous que le ServoMoteur est alimenté correctement selon les spécifications du fabricant.
3. Consultez la documentation du ServoMoteur pour obtenir des détails sur son utilisation.

## Installation

1. Clonez ce dépôt sur votre machine locale.
   ```
   git clone https://github.com/votre-utilisateur/votre-projet.git
   ```
2. Naviguez vers le répertoire du projet.
   cd votre-projet

3. Installez les bibliothèques nécessaires en utilisant l'IDE Arduino. Assurez-vous d'installer les bibliothèques suivantes :

   - DHT by Adafruit
   - Grove RGB
   - SGP 30

4. Téléversez le code sur l'Arduino à l'aide de l'IDE Arduino.
   Assurez-vous d'ajuster ces instructions en fonction des spécificités de votre projet et des composants réels que vous utilisez.
