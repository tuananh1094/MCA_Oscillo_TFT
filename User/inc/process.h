#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "main.h"

// Zero point: (5,75);
#define LENGHT_ACIS_X		180
#define LENGHT_ACIS_Y		150

void displayAdvertisement(void);
void DisplayHomeOscillo(void);
void DisplayCaro(void);
void _drawValue(uint16_t *value);
void __mainProcess(void);

void buzz(uint8_t bip);

uint8_t set(void);
uint8_t increase(void);
uint8_t reduced(void);
uint8_t enter(void);

#endif


