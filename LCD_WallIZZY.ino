// Isabel Corrado, 18 Spetember 2018
// This arduino scritp was created for a sign.
// The character byte arrays are for one "square" on the LCD display
// I hope you find it somewhat interesting...

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13;    // pin 13 will control the backlight

byte gnuebotL[8] = {  // left side of bot byte array
  0b00001,
  0b00010,
  0b00010,
  0b01111,
  0b01011,
  0b01001,
  0b01110,
  0b01111
};

byte gnuebotR[8] = {   // right side of bot byte array
  0b10000,
  0b01000,
  0b01000,
  0b11110,
  0b11010,
  0b10010,
  0b01110,
  0b11110
};


void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.  
  lcd.begin(16,2);               // columns, rows.  use 16,2 for a 16x2 LCD, etc.

  lcd.createChar(0,gnuebotL);   // create custom character (gnu-e-bot)
  lcd.createChar(1,gnuebotR); 
  
  lcd.clear();                  // start with a blank screen
  
}

void loop()
{
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Hello, World");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,1);           // set cursor to column 0, row 1 (second row)
  lcd.print("I'm an Arduino");
 
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("You can learn");
  delay(1000);
  lcd.setCursor(0,1); 
  lcd.print("how I work");

  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);        
  lcd.print("Follow the bot");
  delay(1500);
  lcd.setCursor(0,1);           
  lcd.print(char(0));
  lcd.print(char(1));
  
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);           
  lcd.print("Follow the bot");
  lcd.setCursor(1,1);             // move the bot   
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.setCursor(3,1);
  lcd.print(" -->");
  
  delay(1000);
  lcd.clear();
  
  lcd.print("Follow the bot");
  lcd.setCursor(4,1);
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.setCursor(6,1);
  lcd.print(" ---->");
  
   delay(1000);
  lcd.clear();
  
  lcd.print("Follow the bot");
  lcd.setCursor(7,1);
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.setCursor(9,1);
  lcd.print(" ----->");

  delay(3000);
  lcd.clear();
}
