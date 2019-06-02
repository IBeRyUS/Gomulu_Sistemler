#define BIRLER_BASAMAGI_MASKE          (0x0F)
#define ONLAR_BASAMAGI_MASKE           (0x0F)
#define BIRLER_BASAMAGI_YON_REGISTER   DDRB
#define ONLAR_BASAMAGI_YON_REGISTER    DDRC
#define BIRLER_BASAMAGI_PORT_REGISTER  PORTB
#define ONLAR_BASAMAGI_PORT_REGISTER   PORTC
#define DUGMELER_YON_REGISTER          DDRD
#define DUGMELER_PORT_REGISTER         PORTD
#define DUGMELER_PIN_REGISTER          PIND
#define YUKARI_DUGME                   (1 << 2U)
#define ASAGI_DUGME                    (1 << 3U)
#define LED_PORT_REGISTER              PORTB
#define LED_PIN                        (1 << 5U)
#define SAYAC_MAKSIMUM                 (99U)
#define SAYI_TABANI                    (10U)

void setup() 
{
   BIRLER_BASAMAGI_YON_REGISTER = (BIRLER_BASAMAGI_MASKE | LED_PIN);
   ONLAR_BASAMAGI_YON_REGISTER  = ONLAR_BASAMAGI_MASKE;
   DUGMELER_YON_REGISTER        = ~(YUKARI_DUGME | ASAGI_DUGME);
   DUGMELER_PORT_REGISTER       = (YUKARI_DUGME | ASAGI_DUGME);
}

void loop() 
{
   static unsigned int sayac = 0;
      
   if (ASAGI_DUGME != (ASAGI_DUGME & DUGMELER_PIN_REGISTER))
   {
      LED_PORT_REGISTER |= LED_PIN;
      while (ASAGI_DUGME != (ASAGI_DUGME & DUGMELER_PIN_REGISTER))
      {
         /* Buton basılı iken bekle */
      }
      LED_PORT_REGISTER &= ~LED_PIN;
      sayac--;
      if (SAYAC_MAKSIMUM < sayac)
      {
         sayac = 0;      
      }
   }
   if (YUKARI_DUGME != (YUKARI_DUGME & DUGMELER_PIN_REGISTER))
   {
      LED_PORT_REGISTER |= LED_PIN;
      while (YUKARI_DUGME != (YUKARI_DUGME & DUGMELER_PIN_REGISTER))
      {
         /* Buton basılı iken bekle */
      }
      LED_PORT_REGISTER &= ~LED_PIN;
      sayac++;
      if (sayac >= SAYAC_MAKSIMUM)
      {
         sayac = SAYAC_MAKSIMUM;      
      }
   }
   Yazdir(&BIRLER_BASAMAGI_PORT_REGISTER, (sayac % SAYI_TABANI), BIRLER_BASAMAGI_MASKE);
   Yazdir(&ONLAR_BASAMAGI_PORT_REGISTER, (sayac / SAYI_TABANI), ONLAR_BASAMAGI_MASKE);
}

void Yazdir(volatile uint8_t *const port, const uint8_t deger, const uint8_t maske)
{
   uint8_t port_gecici_deger;

   port_gecici_deger  = *port & ~maske;
   port_gecici_deger |= deger & maske;
   *port = port_gecici_deger;
}