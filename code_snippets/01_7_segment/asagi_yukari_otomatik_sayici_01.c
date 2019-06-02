#define BIRLER_BASAMAGI_BASLANGIC    (8U)
#define ONLAR_BASAMAGI_BASLANGIC    (14U)
#define DISPLAY_PIN_SAYISI           (4U)
#define YUKARI_DUGME                 (2U)
#define ASAGI_DUGME                  (3U)
#define LED_PIN                     (13U)
#define SAYAC_MAKSIMUM              (99U)
#define SAYI_TABANI                 (10U)
#define DEGISIM_ZAMAN_FARKI_MS     (500U)

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
   static unsigned char asagi_basili;
   static unsigned long asagi_artis_bekleme;   
   static unsigned char yukari_basili;
   static unsigned long yukari_artis_bekleme;   
   const unsigned long yeni_zaman = millis();
   
   if (LOW == digitalRead(ASAGI_DUGME))
   {
      if (false != asagi_basili)
      {
         asagi_basili = true;
         sayac--;
         asagi_artis_bekleme = yeni_zaman + DEGISIM_ZAMAN_FARKI_MS;
      }
      else
      {
         if (yeni_zaman >= asagi_artis_bekleme)
         {
            sayac--;
            asagi_artis_bekleme = yeni_zaman + DEGISIM_ZAMAN_FARKI_MS;
         }
      }      
      if (SAYAC_MAKSIMUM < sayac)
      {
         sayac = 0;      
      }
   }
   else
   {
      asagi_basili = false;
   }

   if (LOW == digitalRead(YUKARI_DUGME))
   {
      if (false != yukari_basili)
      {
         yukari_basili = true;
         sayac++;
         yukari_artis_bekleme = yeni_zaman + DEGISIM_ZAMAN_FARKI_MS;
      }
      else
      {
         if (yeni_zaman >= yukari_artis_bekleme)
         {
            sayac++;
            yukari_artis_bekleme = yeni_zaman + DEGISIM_ZAMAN_FARKI_MS;
         }
      }      
      if (sayac >= SAYAC_MAKSIMUM)
      {
         sayac = SAYAC_MAKSIMUM;      
      }
   }
   else
   {
      yukari_basili = false;
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