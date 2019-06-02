static unsigned int sayac;

void setup() 
{
   unsigned int pin;

   pinMode(2, INPUT_PULLUP);
   pinMode(3, INPUT_PULLUP);
   pinMode(13, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   
   pinMode(14, OUTPUT);
   pinMode(15, OUTPUT);
   pinMode(16, OUTPUT);
   pinMode(17, OUTPUT);

   sayac = 0;
}

void loop() 
{
   if (LOW == digitalRead(3))
   {
      digitalWrite(13, HIGH);
      while (LOW == digitalRead(3))
      {
         /* Buton basılı iken bekle */
      }
      digitalWrite(13, LOW);
      if (0 != sayac)
      {
         sayac--;
      }
         else
      {
         sayac = 0;      
      }
   }
   if (LOW == digitalRead(2))
   {
      digitalWrite(13, HIGH);
      while (LOW == digitalRead(2))
      {
         /* Buton basılı iken bekle */
      }
      digitalWrite(13, LOW);
      if (sayac < 99)
      {
         sayac++;
      }
      else
      {
         sayac=99;      
      }
   }
   
   Onlar_Yazdir();
   Birler_Yazdir();  
}

void Onlar_Yazdir(void)
{
   unsigned int onlar;
   
   onlar = sayac / 10;

   if (onlar & 1)
   {
      digitalWrite(14, HIGH);
   }
   else
   {
      digitalWrite(14, LOW);
   }
   if (onlar & 2)
   {
      digitalWrite(15, HIGH);
   }
   else
   {
      digitalWrite(15, LOW);
   }
   if (onlar & 4)
   {
      digitalWrite(16, HIGH);
   }
   else
   {
      digitalWrite(16, LOW);
   }
   if (onlar & 8)
   {
      digitalWrite(17, HIGH);
   }
   else
   {
      digitalWrite(17, LOW);
   }
}  

void Birler_Yazdir(void)
{
   unsigned int birler;
   
   birler = sayac % 10;

   if (birler & 1)
   {
      digitalWrite(8, HIGH);
   }
   else
   {
      digitalWrite(8, LOW);
   }
   if (birler & 2)
   {
      digitalWrite(9, HIGH);
   }
   else
   {
      digitalWrite(9, LOW);
   }
   if (birler & 4)
   {
      digitalWrite(10, HIGH);
   }
   else
   {
      digitalWrite(10, LOW);
   }
   if (birler & 8)
   {
      digitalWrite(11, HIGH);
   }
   else
   {
      digitalWrite(11, LOW);
   }
}