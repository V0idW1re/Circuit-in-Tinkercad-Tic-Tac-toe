#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

// Initialize 3 LCDs with I2C addresses (may need adjustment)
Adafruit_LiquidCrystal lcd1(0); // First LCD (Address 0)
Adafruit_LiquidCrystal lcd2(1); // Second LCD (Address 1)
Adafruit_LiquidCrystal lcd3(2); // Third LCD (Address 2)

// Keypad setup
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

// Keypad character mapping (matches physical layout)
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define keypad pin connections
byte rowPins[ROWS] = {9, 8, 7, 6}; // Row pins connected to Arduino
byte colPins[COLS] = {5, 4, 3, 2}; // Column pins connected to Arduino

// Create the keypad object
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Game Constants
const int PLAYER_NONE = 0; // No player has moved
const int PLAYER_X = 1;    // Player X
const int PLAYER_O = 2;    // Player O

// Tic-Tac-Toe board
int board[3][3];

// Game State
int currentPlayer; // Tracks whose turn it is
bool gameOver;     // Flag to indicate if the game is over

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor (for debugging)
  Wire.begin();       // Initialize I2C communication

  // Initialize LCDs
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  lcd3.begin(16, 2);

  // Turn on LCD backlights
  lcd1.setBacklight(1);
  lcd2.setBacklight(1);
  lcd3.setBacklight(1);

  // Clear displays
  lcd1.clear();
  lcd2.clear();
  lcd3.clear();

  // Show welcome message
  lcd1.setCursor(0, 0);
  lcd1.print("Tic-Tac-Toe");
  delay(2000); // Display message for 2 seconds

  resetGame(); // Start a new game
}

void loop() {
  char key = keypad.getKey(); // Read keypad input

  // If '0' is pressed, reset the game
  if (key == '0') {
    resetGame();
  }

  // If a number (1-9) is pressed and the game is not over
  if (!gameOver && key >= '1' && key <= '9') {
    int num = key - '1'; // Convert key to board index (0-8)
    int row = num / 3;   // Determine row (0-2)
    int col = num % 3;   // Determine column (0-2)

    // Check if the selected cell is empty
    if (board[row][col] == PLAYER_NONE) {
      board[row][col] = currentPlayer; // Mark the cell
      updateDisplay();                 // Refresh the LCDs
      checkWinCondition();             // Check if someone won
      if (!gameOver) switchPlayers();  // If no winner, switch turns
    }
  }
}

// Resets the game board
void resetGame() {
  // Clear board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = PLAYER_NONE;
    }
  }

  currentPlayer = PLAYER_X; // X always starts first
  gameOver = false;         // Reset game over flag
  updateDisplay();          // Update the LCDs
}

// Updates all 3 LCDs with the current board state
void updateDisplay() {
  lcd1.clear();
  lcd2.clear();
  lcd3.clear();

  // Display the current player's turn on LCD 1
  lcd1.setCursor(0, 0);
  lcd1.print("Turn: ");
  lcd1.print(symbolForPlayer(currentPlayer));

  // Display Tic-Tac-Toe board
  for (int row = 0; row < 3; row++) {
    String line = "|"; // Create row display
    for (int col = 0; col < 3; col++) {
      line += symbolForPlayer(board[row][col]); // Add X, O, or space
      line += "|"; // Separate columns
    }
    displayLine(row, line); // Show the row on correct LCD
  }
}

// Displays a row of the Tic-Tac-Toe board on the correct LCD
void displayLine(int row, String line) {
  if (row == 0) {
    lcd1.setCursor(0, 1); // Second row of LCD 1
    lcd1.print(line);
  } else if (row == 1) {
    lcd2.setCursor(0, 0); // First row of LCD 2
    lcd2.print(line);
  } else if (row == 2) {
    lcd3.setCursor(0, 0); // First row of LCD 3
    lcd3.print(line);
  }
}

// Returns the character ('X', 'O', or ' ') for a given player
char symbolForPlayer(int player) {
  if (player == PLAYER_X) return 'X';
  if (player == PLAYER_O) return 'O';
  return ' '; // Empty space if no move
}

// Switches turn between X and O
void switchPlayers() {
  currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
  updateDisplay(); // Update LCD to show new turn
}

// Checks if a player has won
void checkWinCondition() {
  // Check rows for a win
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != PLAYER_NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      gameOver = true;
      showWinner(board[i][0]);
      return;
    }
  }

  // Check columns for a win
  for (int j = 0; j < 3; j++) {
    if (board[0][j] != PLAYER_NONE && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      gameOver = true;
      showWinner(board[0][j]);
      return;
    }
  }

  // Check diagonal (top-left to bottom-right)
  if (board[0][0] != PLAYER_NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    gameOver = true;
    showWinner(board[0][0]);
    return;
  }

  // Check diagonal (top-right to bottom-left)
  if (board[0][2] != PLAYER_NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    gameOver = true;
    showWinner(board[0][2]);
    return;
  }

  // Check for a draw (if no empty cells remain)
  bool draw = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == PLAYER_NONE) {
        draw = false;
        break;
      }
    }
  }

  // If all cells are filled and no winner, it's a draw
  if (draw) {
    gameOver = true;
    lcd1.setCursor(0, 1);
    lcd1.print("It's a Draw!");
  }
}

// Displays the winner
void showWinner(int player) {
  lcd1.setCursor(0, 1);
  lcd1.print("Winner: ");
  lcd1.print(symbolForPlayer(player));
}
