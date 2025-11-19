#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
/*
  RAW,      0 - Still functional
  BOILED,   1 - A bit soft
  BAKED,    2 - Getting warm
  FRIED,    3 - Sizzling
  MASHED,   4 - Completely blended
  CHARRED   5 - Burnt out
*/
#define timeRollOver 800

#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 32     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int startTime;
bool isPressed;
void setup() {
  pinMode(33, INPUT);
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 0);
  display.write("POTATO");
  display.setCursor(12, 16);
  display.write("METER 300");
  display.display();
  delay(2000);
}

void loop() {
  int deltaTime;
  if (digitalRead(33) && !isPressed) {
    Serial.println("isPressed");
    isPressed = true;
    startTime = millis();
  }
  if (!digitalRead(33) && isPressed) {
    Serial.println("Released");
    isPressed = false;
    deltaTime = millis() - startTime;
    Serial.println(deltaTime);
    potatoPrint(deltaTime);
  }
  delay(10);
  if (isPressed) {
    display.clearDisplay();
    deltaTime = millis() - startTime;
    float currentProgress= (float)deltaTime / timeRollOver;
    drawProgressBar(currentProgress);
  }
}
void potatoPrint(int deltaTime_i) {
  int currentPotato = deltaTime_i / timeRollOver;

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);

  switch (currentPotato) {
    case 0:
      printingFunction("RAW", 2);
      break;
    case 1:
      printingFunction("BOILED", 2);
      break;
    case 2:
      printingFunction("BAKED", 2);
      break;
    case 3:
      printingFunction("FRIED", 2);
      break;
    case 4:
      printingFunction("MASHED", 2);
      break;
    default:
      display.println("SEND HELP!");
      printingFunction("CHARRED", 2);
  }
}
void printingFunction(String displayText, char textSize) {
  Serial.println(displayText);
  display.setTextSize(textSize);
  display.println(displayText);
  display.println("POTATO!");
  display.display();
}
void drawProgressBar(float currentPotato) {
  if (currentPotato > 5) currentPotato = 5;  // Cap at CHARRED
  // Draw a progress bar at the bottom of the screen
  int barWidth = 118;  // Width of the progress bar
  int barHeight = 6;   // Height of the progress bar
  int x = 5;           // X position
  int y = 26;          // Y position (bottom of 32px display)

  // Draw background (empty bar)
  display.drawRect(x, y, barWidth, barHeight, SSD1306_WHITE);
  // Calculate filled width (max 5 potato levels -> CHARRED)
  float filledWidth = (currentPotato / 5.0) * barWidth;
  if (filledWidth > barWidth) filledWidth = barWidth;

  // Draw filled portion
  display.fillRect(x + 1, y + 1, filledWidth - 2, barHeight - 2, SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("POTATO-FYING...");
  display.setTextSize(1);
  display.print("Level: ");
  display.print(currentPotato);
  display.display();
}