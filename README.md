# 🤖 Robot Mobile Éviteur d'Obstacles & Station Météo

Un système mécatronique embarqué autonome basé sur **Arduino Uno** et développé en **C++ orienté objet (POO)**. 

Le robot navigue de manière autonome en détectant et en évitant les obstacles grâce à un capteur à ultrasons monté sur un servomoteur orientable. En parallèle, il fait office de station environnementale en mesurant la température et l'humidité ambiantes et en les affichant sur un écran LCD I2C.

---

## 🛠️ Fonctions Principales

- **Navigation & Évitement d'Obstacles** : Détection de présence d'obstacle (< 15 cm), balayage angulaire (0° / 180°) pour évaluer la trajectoire la plus dégagée et prise de décision de pivotement automatique.
- **Modèle de Calibration Ultrason** : Correction expérimentale des mesures de distance par régression linéaire ($d_{predict} = a \times d + b$).
- **Surveillance Environnementale** : Lecture de la température et de l'humidité via le capteur DHT11.
- **Affichage LCD I2C** : Visualisation en temps réel des données environnementales et gestion des erreurs de capteur.
- **Architecture Modulaire C++** : Code propre, encapsulé en classes distinctes pour chaque composant matériel.

---

## 📐 Architecture Matérielle & Câblage

### Cartographie des Broches (Pinout)

| Composant | Signal / Broche Composant | Broche Arduino Uno |
| :--- | :--- | :--- |
| **Driver Moteur L298N** | ENA (Vitesse Moteur Gauche) | `D3` (PWM) |
| | IN1 / IN2 (Sens Moteur Gauche) | `D2` / `D4` |
| | ENB (Vitesse Moteur Droit) | `D5` (PWM) |
| | IN3 / IN4 (Sens Moteur Droit) | `D7` / `D8` |
| **Capteur Ultrason HC-SR04** | Trig (Émetteur) | `D12` |
| | Echo (Récepteur) | `D13` |
| **Servomoteur (SG90)** | Signal PWM | `D9` |
| **Capteur DHT11** | Signal Data | `D10` |
| **Écran LCD 16x2 I2C** | SDA | `SDA` (A4) |
| | SCL | `SCL` (A5) |

---

## 📁 Structure du Projet

```text
.
├── my_project.ino      # Programme principal (Setup et Loop)
├── L298N.h / .cpp      # Classe de contrôle du driver moteur
├── HCSR04.h / .cpp     # Classe du capteur ultrason avec régression linéaire
├── sensor_t_h.h / .cpp # Classe du capteur de température/humidité DHT11
├── ecran.h / .cpp      # Classe de gestion du moniteur LCD I2C
└── README.md           # Documentation du projet
