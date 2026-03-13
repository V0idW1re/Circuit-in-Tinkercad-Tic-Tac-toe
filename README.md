---
🎮 Arduino Tic-Tac-Toe (Tinkercad Circuit)
--
An interactive Tic-Tac-Toe game implemented with Arduino, a 4x4 keypad, and three I2C LCD displays.
The project was designed and simulated in Tinkercad Circuits and demonstrates how microcontrollers can be used to build simple interactive games using external hardware.

Players enter their moves using the keypad, while the LCD displays show the current board state and player turns in real time.

---
📸 Project Overview
--
The system allows two players to play Tic-Tac-Toe on a physical interface:

A Keypad is used to select board positions.

Three LCD displays show the game board and game information.

An Arduino Uno controls the game logic and hardware communication.

---
🧩 Hardware Components
--
Component	Description  
Arduino Uno	Main microcontroller controlling the system  
4x4 Keypad	Player input for selecting moves  
3 × 16x2 I2C LCD Displays	Display the board and player turns  
Breadboard	Circuit prototyping  
Jumper wires	Electrical connections  

---
🔌 Circuit Design
--
Keypad Connections

The keypad is connected to digital pins 2–9 of the Arduino.

Rows → Pins 9, 8, 7, 6
Columns → Pins 5, 4, 3, 2
LCD I2C Connections

All LCD screens communicate via I2C protocol.

LCD Pin	Arduino Connection
VCC	5V
GND	GND
SDA	A4
SCL	A5

Each LCD uses a different I2C address:

LCD 1 → Address 0  
LCD 2 → Address 1  
LCD 3 → Address 2  

---
🖥 Display Layout
--
The LCDs are used to show the game board and information.

LCD	Function  
LCD 1	Game title and current player's turn  
LCD 1 (line 2)	First row of the board  
LCD 2	Second row of the board  
LCD 3	Third row of the board  

Example board display:

|X|O|X|  
| |X|O|  
|O| | |  

---
🎮 How to Play
--
1. Power on the Arduino.

2. The LCD displays will show "Tic-Tac-Toe".

3. Player X starts first.

4. Press numbers 1-9 on the keypad to place your mark.

Keypad Mapping
1 | 2 | 3
4 | 5 | 6
7 | 8 | 9

Each number corresponds to a position on the board.

Special Key  
Key - Action  
0 - Reset the game  

---
⚙️ Software Overview
--
The Arduino program manages:

System initialization

Keypad input reading

Game logic processing

LCD display updates

Win and draw detection

---
📚 Libraries Used
--
#include <Wire.h>  
#include <Adafruit_LiquidCrystal.h>  
#include <Keypad.h>  

Library - Purpose  
Wire - Enables I2C communication  
Adafruit_LiquidCrystal - Controls the LCD displays  
Keypad - Reads keypad button presses  

---
🧠 Game Logic
--
The program implements the classic Tic-Tac-Toe rules.

Game Features:

✔ Turn-based gameplay  
✔ Real-time board updates  
✔ Win detection:  
------Horizontal  
------Vertical  
------Diagonal    
✔ Draw detection  
✔ Manual reset option  

---
🧪 Testing & Debugging
--
The system was tested for:

All keypad inputs (1-9)

Horizontal win conditions

Vertical win conditions

Diagonal win conditions

Draw situations

The Serial Monitor was also used for debugging during development.

---
🚀 Possible Improvements
--
Future improvements could include:

🤖 AI Opponent
--
Add a player vs computer mode with a basic AI algorithm.

🔊 Sound Feedback
--
Add a buzzer to confirm player moves or indicate victory.

🌐 Online Multiplayer
--
Connect a Wi-Fi module (ESP8266 / ESP32) to enable remote gameplay.

🏆 Score Tracking
--
Keep track of wins and losses across multiple games.

💡 LED Indicators
--
Use LEDs for additional visual feedback.

---
🔄 Alternative Hardware Ideas
--
Replace Arduino Uno with Arduino Mega to support more peripherals.

Replace LCD displays with a TFT display for graphical interface.

Integrate touch input instead of keypad.

---
🛠 Built With
--
Arduino IDE

Tinkercad Circuits

C++ (Arduino)

---
📜 License
--
This project is open-source and free to use for educational purposes.

---
<img width="974" height="1164" alt="image" src="https://github.com/user-attachments/assets/50b1cf36-6412-4ce5-ad7a-ede38e99ee1f" />
Tinkercad simulation link:    

https://www.tinkercad.com/things/i5KoJDtCui6-tic-tac-toe?sharecode=1nIo-TQtMarcCsbxdiZUKp03t4qaofmqOEDW_Acgvks
