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
#define BIRLER_BASAMAGI_BASLANGIC    (8U)
#define ONLAR_BASAMAGI_BASLANGIC    (14U)
#define DISPLAY_PIN_SAYISI           (4U)
#define YUKARI_DUGME                 (2U)
#define ASAGI_DUGME                  (3U)
#define LED_PIN                     (13U)
#define SAYAC_MAKSIMUM              (99U)
#define SAYI_TABANI                 (10U)

void setup() 
{
   unsigned int i;
   
   pinMode(YUKARI_DUGME, INPUT_PULLUP);
   pinMode(ASAGI_DUGME, INPUT_PULLUP);
   pinMode(LED_PIN, OUTPUT);
   for (i = 0; i < DISPLAY_PIN_SAYISI; i++)
   {
      pinMode((BIRLER_BASAMAGI_BASLANGIC + i), OUTPUT);
      pinMode((ONLAR_BASAMAGI_BASLANGIC + i), OUTPUT);
   }
}

void loop() 
{
   static unsigned int sayac = 0;
   
   if (LOW == digitalRead(ASAGI_DUGME))
   {
      digitalWrite(LED_PIN, HIGH);
      while (LOW == digitalRead(ASAGI_DUGME))
      {
         /* Buton basılı iken bekle */
      }
      digitalWrite(LED_PIN, LOW);
      sayac--;
      if (SAYAC_MAKSIMUM < sayac)
      {
         sayac = 0;      
      }
   }
   if (LOW == digitalRead(YUKARI_DUGME))
   {
      digitalWrite(LED_PIN, HIGH);
      while (LOW == digitalRead(YUKARI_DUGME))
      {
         /* Buton basılı iken bekle */
      }
      digitalWrite(LED_PIN, LOW);
      sayac++;
      if (sayac >= SAYAC_MAKSIMUM)
      {
         sayac = SAYAC_MAKSIMUM;      
      }
   }
   Yazdir(BIRLER_BASAMAGI_BASLANGIC, (sayac % SAYI_TABANI));
   Yazdir(ONLAR_BASAMAGI_BASLANGIC,  (sayac / SAYI_TABANI));  
}

void Yazdir (unsigned int ondalik, unsigned int sayi)
{
   unsigned int i;
   for (i = 0; i < DISPLAY_PIN_SAYISI; i++)
   {
      digitalWrite(ondalik++, (sayi & (1U << i)) ? HIGH : LOW);
   }
}