/**
   Projet du dé électronique - FabTronic 2021
   Source :
   
   ATtiny85 (8MHz)

   Libraries used are the properties of the respective authors.

   Sleep mode use about 70 µA (0.07 mA)

   Battery life in sleep mode, assuming 10 wake-ups pr.hour:
   ----------------------------------------------------------
   2 x AA at 2500mAh      =
   1 x 3.7v Saft LS14500  =
   1 x 550mAh coin cell   =
   1 x 240mAh coin cell   =
   ----------------------------------------------------------
   Battery Life Calculator <http://oregonembedded.com/batterycalc.htm>

   Reference > Language > Functions > Random numbers > Random
   https://www.arduino.cc/reference/en/language/functions/random-numbers/random/

*/


// ATMEL ATTINY 25/45/85 / ARDUINO
//
//                  +--\/--+
// Ain0 (D 5) PB5  1|      |8  Vcc
// Ain3 (D 3) PB3  2|      |7  PB2 (D 2) Ain1
// Ain2 (D 4) PB4  3|      |6  PB1 (D 1) pwm1
//            GND  4|      |5  PB0 (D 0) pwm0
//                  +------+

#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/sleep.h>

#define LEDUNSIX       1     // Leds 1 et 6 sur PB1
#define LEDTROISQUATRE 0     // Leds 3 et 4 sur PB5
#define LEDDEUXCINQ    4     // Leds 2 et 5 sur PB4
#define LEDSEPT        3     // Leds 7 sur PB3
#define UNESECONDE     100   // 1 seconde égal à 1000 ms --> TODO: Déterminer la Fq de travail et la bonne valeur

volatile uint8_t roll = 0, initSeed = 0, seed = 0;

ISR(INT0_vect) {
  MCUCR &= ~(1 << SE); // Idle of sleep mode -> disable
  roll = 1;
  if (initSeed == 0) {
    randomSeed(seed);
    initSeed = 1;
  }
}

void action() {
  uint8_t tirage = 0;
  uint8_t newTirage = 0;

  //  for (uint8_t i = 0; i < random(10, 21); i++) {
  for (uint8_t i = 0; i < random(3, 11); i++) {
    do {
      newTirage = random(1, 7);
    } while (tirage == newTirage);
    tirage = newTirage;

    onEteind();
    afficheTirage(tirage); // on affiche le tirage
    _delay_ms(UNESECONDE / 4);
  }

  // Phase de tirage réel
  onEteind();
  do {
    newTirage = random(1, 7);
  } while (tirage == newTirage);

  afficheTirage(newTirage);
  _delay_ms(UNESECONDE * 5);           // Tirage final, on fait une pause de 5 secondes.*/
  onEteind();
  roll = 0;
}

void init_ISR() { // INITIALISATION des routines d'initialisation
  PORTB |= 1 << PB2; //|1<<PB5;   // configuration du port B2  PULL UP (PB2) (AND USUED PIN PB5 : pas utilisé)
  MCUCR |= 1 << ISC01; // Falling EDGE INT0 (PB2)
  GIMSK |= 1 << INT0; // Activate the INT0
  sei();             //Active General Interrupt
}

void init_GPIO() {
  // On configure les PINs en sortie pour les LEDs
  DDRB |= (1 << LEDUNSIX) | (1 << LEDTROISQUATRE) | (1 << LEDDEUXCINQ) | (1 << LEDSEPT);
}

void onEteind() {
  PORTB &= ~((1 << LEDUNSIX) | (1 << LEDTROISQUATRE) | (1 << LEDDEUXCINQ) | (1 << LEDSEPT));
  _delay_ms(UNESECONDE / 5);
}

void afficheTirage(uint8_t tirage) {
  PORTB &= ~((1 << LEDUNSIX) | (1 << LEDTROISQUATRE) | (1 << LEDDEUXCINQ) | (1 << LEDSEPT));
  switch (tirage) {
    case 1:
      PORTB |= (1 << LEDSEPT);
      break;
    case 2:
      PORTB |= (1 << LEDUNSIX);
      break;
    case 3:
      PORTB |= (1 << LEDUNSIX) | (1 << LEDSEPT);
      break;
    case 4:
      PORTB |= (1 << LEDUNSIX) | (1 << LEDDEUXCINQ);
      break;
    case 5:
      PORTB |= (1 << LEDUNSIX) | (1 << LEDDEUXCINQ) | (1 << LEDSEPT);
      break;
    case 6:
      PORTB |= (1 << LEDUNSIX) | (1 << LEDDEUXCINQ) | (1 << LEDTROISQUATRE);
      break;

    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}

int main() {
  init_GPIO();
  init_ISR();

  while (1) {
    if (initSeed == 0) {
      seed++;
    }

    if (roll == 1) {
      action();
      MCUCR |= (1 << SE); // Idle Mode of sleep mode
      sleep_mode();
    }
  }

  return 0;
}
