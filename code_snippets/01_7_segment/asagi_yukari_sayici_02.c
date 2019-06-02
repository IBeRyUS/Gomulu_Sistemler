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