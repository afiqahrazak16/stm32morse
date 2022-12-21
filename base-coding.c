#include "stm32f4xx.h"

// Pin configuration
#define LED_PIN    GPIO_Pin_12
#define LED_PORT   GPIOD
#define LED_CLK    RCC_AHB1Periph_GPIOD

// Morse code definitions
#define DOT        1
#define DASH       3
#define CHAR_GAP   3
#define WORD_GAP   7

// Morse code lookup table
// Each entry consists of a series of dots and dashes,
// separated by spaces. For example, the entry for 'A'
// is ".-", which represents a dot followed by a dash.
const char *morse_codes[] = {
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
  // Initialize LED
  GPIO_InitTypeDef gpio_init;
  RCC_AHB1PeriphClockCmd(LED_CLK, ENABLE);
  gpio_init.GPIO_Pin = LED_PIN;
  gpio_init.GPIO_Mode = GPIO_Mode_OUT;
  gpio_init.GPIO_OType = GPIO_OT
