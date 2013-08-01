#if 0

#include "REG1210.h"
#define RAM_START 0xc000000
#define LOG_DATA_START_ADDRESS (RAM_START + 0x1000)
#define MAX_LOG_INDEX 0x4000

char xdata clock_tic;
int xdata boot_time;
unsigned xdata voltage_samples[25];
code char version[13] =   "ACME V1.42\n";
at LOG_DATA_START_ADDRESS xdata unsigned log_flash[MAX_LOG_INDEX + 1];
void clock_tic_isr() interrupt 1 using 1
{
	clock_tic++;
	//.. other stuff
}

void say_hi()
{
  IE = 0b11000000;
  SBUF0 = (0x68);

  while(TI_0 == 0);
  TI_0 = 0;

  SBUF0 = (0x69);

  while(TI_0 == 0);
  TI_0 = 0;

  SBUF0 = (0x0a);

  while(TI_0 == 0);
  TI_0 = 0;

  SBUF0 = (0x0d);

  while(TI_0 == 0);
  TI_0 = 0;

  IE = 0b11010000;
}

#endif
