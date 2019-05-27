#include <stdio.h>
#include "paket.h"
#include "uygulama.h"

static unsigned char paket[PAKET_BOYUT_MAX];

void Uygulama_Init(void)
{
   //....
   //....
   Paket_Init();
   //....
   //....
}

void Uygulama_Kontrol(void)
{
   unsigned int uzunluk;
   //....
   //....
   uzunluk = snprintf(paket, PAKET_BOYUT_MAX, "Deneme metin\n");
   Paket_Gonder(paket, uzunluk);
}