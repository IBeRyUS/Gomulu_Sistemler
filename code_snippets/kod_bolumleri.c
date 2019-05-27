#include <MIKRODENETLEYICI_MODEL.h>
#include <stdio.h>
#include "modul1.h"
#include "bu_modul.h"

#define FLAG_SAYAC_DEGERI  (500)
#define DURUM_FLAG_MASKE   ((1 << 4) - 1)

static volatile unsigned int flag;

void timer_ISR (void)
{
   static unsigned int sayac;
   //....
   if (0 == sayac)
   {
      flag = 1;
      sayac = FLAG_SAYAC_DEGERI;
   }
   else
   {
      sayac--;
   }
   
   //....
}

void main (void)
{
   unsigned int durum;
   //....
   //....
   if (flag == 1)
   {
      const unsigned int aktif_durum = durum & DURUM_FLAG_MASKE;
      flag = 0;
      //....
      //....
   }
   //....
   //....
}