/*
 * Copyright 2019 İbrahim USLAN(IBeRyUS) - mixer_opq@hotmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * 
 */

/* Kodlar 20. Satırdan itibaren html dosyalarında gösterilecek */
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