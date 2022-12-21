#include "stm32f4xx.h"

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

// Define the output pin and initialize it to low
#define LED_PIN GPIO_Pin_12
#define LED_PORT GPIOD
#define LED_ON()  GPIO_SetBits(LED_PORT, LED_PIN)
#define LED_OFF() GPIO_ResetBits(LED_PORT, LED_PIN)

int main(void)
{
  // Initialize the output pin
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  GPIO_InitTypeDef gpio_init;
  gpio_init.GPIO_Pin = LED_PIN;
  gpio_init.GPIO_Mode = GPIO_Mode_OUT;
  gpio_init.GPIO_OType = GPIO_OType_PP;
  gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_PORT, &gpio_init);
  LED_OFF();

  // Encode a message in Morse code
  const char* message = "HELLO WORLD";
  while (*message) {
    char c = *message++;

    // Make sure the character is uppercase
  }
