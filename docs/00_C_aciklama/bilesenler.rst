.. comment

   Copyright 2019 İbrahim USLAN(IBeRyUS) - mixer_opq@hotmail.com

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

********************************************************************************
C Dilinde Kullanılan Bileşenler
********************************************************************************

C ile yazılan bir programın derlenme ve oluşturulma aşamalarına kısaca 
bakalım. 

.. _preprocessor:

:index:`Ön işlemci` (:index:`Preprocessor`)
--------------------------------------------------------------------------------
   
Preprocessor programın derlenmesinden önce çalıştırılan bir prosestir.
Aslında bir nevi ön derleyici de denebilir. Preprocessor komutları diyez
işareti (#) ile başlar. Preprocessor komutları kodun taşınabilirliğine
büyük katkı sağlar. Yazmış olduğunuz kodları farklı mikrodenetleyicilerde
kullanmak istiyorsanız farklı donanım ve platformlara özgü tanımlamaları 
tanımlamanız gerekmektedir.

.. code-block:: C
   
   #if defined(__ARMCC_VERSION)
   const char mimari[] = "ARM"
   #elif defined(__AVR__)
   const char mimari[] = "AVR"      
   #else
   const char mimari[] = "Bilinmeyen"
   #endif
   
   printf("%s\n", mimari);

Bu örnekte kullandığımız işlemci mimarisinin ismini printf ile yazdırabiliriz
. Eğer bu kod ARM derleyici ile derlenir ise preprocessor öntanımlı
``__ARMCC_VERSION`` tanımından dolayı ``mimari`` katar dizisine ``ARM``
yazacaktır. Eğer bu kod parçağını ``ARM`` ya da ``AVR`` harici bir derleyici
ile derlerseniz ``mimari`` katar dizisine ``Bilinmeyen`` yazacaktır. 

.. code-block:: C
   
   #define LED_PIN  (13)
   
   pinMode(LED_PIN, OUTPUT);
   
Bu örnekte ise preprocessor çalıştıktan sonra kod ``pinMode(13, OUTPUT);``
olarak değişecek ve derleyici değişmiş kod üzerinden derleme yapacaktır.

.. _compiler:
   
:index:`Derleyici` (:index:`Compiler`) 
--------------------------------------------------------------------------------

Derleyici yazmış olduğumuz C kodlarından işlemci kodlarını üreten bir
yazılımdır. Eğer kod optimizasyonu aktif ise optimizasyon bu aşamada
gerçekleştirilir. Her bir modül tek tek derlenerek her modüle ait obje
dosyaları oluşturulur.

.. _linker:

:index:`Bağlayıcı` (:index:`Linker`) 
--------------------------------------------------------------------------------

Wikipedia linker için bağlayıcı terimini kullanmış. Bu aşama son aşamadır.
Oluşturulan obje dosyalarından çalışabilir uygulama oluşturulur. Bağlayıcı
programa adres haritası verilmesi gerekir. Adres haritasında hafıza blokları
ve özellikleri belirtilir. Aşağıda STM32F103X6 mikrodenetleyicisine ait RAM
ve ROM bloklarının tanımını görebilirsiniz. Aynı script dosyasında oluştulan
obje dosyalarındaki blokların nerelere yerleştireleceği, sıralaması vb.
bilgiler de bulunur. Her mikroişlemci mimarisinin başlangıc adres ve yerleşim
bilgileri farklıdır. Bunlar genel olarak kullanılan geliştirme ortamları
(IDE) veya derleyici kütüphanelerinde üreticiler tarafından hazırlanır. 

.. highlight:: none

::

   /*
    * Take a look in the "The GNU linker" manual, here you get
    * the following information about the "MEMORY":
    *
    * "The MEMORY command describes the location and size of 
    * blocks of memory in the target."
    */
   MEMORY
   {
     FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 0x00008000
     RAM (rw)   : ORIGIN = 0x20000000, LENGTH = 0x00002800
   }

Bağlayıcı; derleyici tarafından oluşturulan obje dosyalarında tanımlanmış
fonksiyon, değişken, vb diğer tanımları alır ve sırayla kod bloğuna
yerleştirir. Fonksiyonların, değişkenlerin adresleri bu aşamada belirlenir.
En son çalışmaya hazır olan program dosyası üretilir. Bu dosya direk
işlemciye yazılacak kodu, hata ayıklama bilgileri, adres haritası vb. bir çok
bilgiyi de içerir. İşlemciye kopyalanacak dosya obje kopyalama programları
ile bu dosya içerisinden çıkartılabilir.
