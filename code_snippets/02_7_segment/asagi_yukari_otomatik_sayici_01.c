#define DISPLAY_DATA_YON_REGISTER         DDRD
#define DISPLAY_DATA_REGISTER             PORTD
#define DISPLAY_CONTROL_YON_REGISTER      DDRB
#define DISPLAY_CONTROL_DATA_REGISTER     PORTB

#define LED_PIN                     (13U)
#define DISPLAY_DATA_MASKE         (0X7F)
#define DISPLAY_CONTROL_MASKE      (0X07)

#define DISPLAY_SAYISI               (3U)

#define YUKARI_DUGME                (11U)
#define ASAGI_DUGME                 (12U)

#define SAYAC_MAKSIMUM             (999U)
#define SAYI_TABANI                 (10U)
#define DEGISIM_ZAMAN_FARKI_MS     (500U)
#define DISPLAY_BEKLEME_US        (1750U)

static const unsigned char numaralar[] = {
//    0     1     2     3     4     5     6     7     8     9
   0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f
};

void setup() 
{
   DISPLAY_CONTROL_DATA_REGISTER = 6;
   pinMode(YUKARI_DUGME, INPUT_PULLUP);
   pinMode(ASAGI_DUGME, INPUT_PULLUP);
   pinMode(LED_PIN, OUTPUT);
   DISPLAY_DATA_YON_REGISTER = DISPLAY_DATA_MASKE;
   DISPLAY_DATA_REGISTER     = numaralar[0];
   DISPLAY_CONTROL_YON_REGISTER  = DISPLAY_CONTROL_MASKE;
}

void loop() 
{
   static unsigned int sayac = 0;
   static unsigned char asagi_basili;
   static unsigned char yukari_basili;
   static unsigned long asagi_artis_bekleme;   
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
   Yazdir(sayac);
}

void Yazdir (const unsigned int sayi)
{
   unsigned int i;
   unsigned char display;
   unsigned int numara;
   unsigned int sayi_ic = sayi;
   
   for (i = 0; i < DISPLAY_SAYISI; i++)
   {
      display = (~(1U << i)) & DISPLAY_CONTROL_MASKE;
      numara = sayi_ic % SAYI_TABANI;
      DISPLAY_CONTROL_DATA_REGISTER = (DISPLAY_CONTROL_DATA_REGISTER & ~DISPLAY_CONTROL_MASKE) | display;
      DISPLAY_DATA_REGISTER = numaralar[numara];
      sayi_ic /= SAYI_TABANI;
      delayMicroseconds(DISPLAY_BEKLEME_US);
   }
}