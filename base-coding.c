#include "stm32f4xx.h"

// Morse code definitions
#define DOT 500
#define DASH 1000
#define INTER_LETTER 500
#define INTER_WORD 1000

const char* message = "HELLO WORLD";

// Define the Morse code alphabet
const char* morse_code[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

int main(void)
{
  // Initialize GPIO
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable GPIOD clock
  GPIOD->MODER |= (1 << 24); // Set GPIOD pin 12 to output mode
  
  while (1) {
    // Blink LED in Morse code
    for (int i = 0; i < strlen(message); i++) {
      char c = message[i];
      if (c == ' ') {
        delay(INTER_LETTER * 3); // Delay between words
      } else {
        for (int j = 0; j < strlen(MORSE_CODE[c - 'A']); j++) {
          GPIOD->ODR |= (1 << 12); // Turn on LED
          char code = MORSE_CODE[c - 'A'][j];
          if (code == '.') {
            delay(DOT);
          } else if (code == '-') {
            delay(DASH);
          }
          GPIOD->ODR &= ~(1 << 12); // Turn off LED
          delay(DOT); // Delay between dots and dashes
        }
        delay(INTER_LETTER); // Delay between letters
      }
    }
  }
}
