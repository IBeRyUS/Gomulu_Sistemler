################################################################################
Giriş
################################################################################

.. note::
   Buradaki örneklerde ya da açıklamalarda C dili anlatılmayacak, daha çok C
   dilinin uygulamaları üzerine bilgiler verilecektir. Buradaki uygulamaları
   incelemek ve anlamak için temel elektronik, mikrodenetleyici donanım,
   algoritma ve C programlama dili bilgilerine sahip olmanız gerekmektedir.
   Verilen kodların satır satır açıklamaları yapılmayacak, şemalarda çok fazla 
   detaya inilmeyecektir.

********************************************************************************
1. Gömülü Sistem Ne Demektir
********************************************************************************

   Gömülü sistemler kısaca üzerinde çalışan yazılımın kullanıcı tarafından
   özelleştirilmesinin ve değiştirilmesinin (üreticinin sağladığı yazılım
   güncellemesinden hariç kullanıcı tarafından yazılan yazılım ile fonksiyonun
   değiştirilmesi) çok kolay olmadığı, sistemin çalışması için gereken tüm
   ekipmanların bir kart veya kutu içerisinde toplandığı sistemlerdir. Bununla
   ilgili internette birçok kaynak mevcut ufak bir araştırma ile daha detaylı
   bilgilere ulaşabilirsiniz. 
   

********************************************************************************
2. Geliştirme Ortamı
********************************************************************************

   Gömülü sistem örneklerinde genel olarak bare-metal(herhangi bir işletim
   sistemi veya iş yönetim sistemi kullanmadan direk yazılımın mikrodenetleyici
   üzerinde çalışığı) örneklere yer vereceğim. Bare-metal uygulamalarda
   kullanılan programlama dilleri genellikle assembler ve C dilidir. Biz
   örneklerimizde özellikle gömülü sistemler için kullanılan C diline ait
   kodları inceleyeceğiz. 

   Özellikle birden fazla kişinin birlikte çalıştığı projelerde kodlama
   standardı uygulanır. Kodlama yapılırken sadece kodlama standardı değil farklı
   standartlarda kontrol edilebilir. Örneğin güvenlik öncelikli sistemlere ait
   kodlarda MISRA standartlarına uygunluğu da kontrol edilir. Örnek kodlama
   standardı olarak |barr_link|'na bakabilirsiniz.

   .. |barr_link| raw:: html
      
      <a href="https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard" 
      target="_blank">Barr Kodlama Standardı</a>

2.1. Kullanılacak Yazılımlar ve Donanımlar
================================================================================

   .. note:: 
      
      Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde
      **sadece** Arduino öğretilmesine karşıyım. Buradaki örneklerin aynı
      zamanda gerçek donanım üzerinde de test edilebilmesi için en ucuz ve
      kolay bulunan protorip bordu olan Arduino örnekleri ile başlayacağız. 
      
   *  Şemalar simulasyon odaklı verilecektir. Simulasyon için Proteus yazılımı
      kullanılacaktır. Proteus versiyon 8.7 SP3'dür. Proteus nereden bulunur vb.
      soruları lütfen sormayınız.
   *  Arduino Atmega328p çipine sahip UNO veya NANO 
   *  |arduino_ide_link| 
   
   
   
   
   .. |arduino_ide_link| raw:: html 
   
      <a href="https://www.arduino.cc/en/Main/Software" 
      target="_blank">Arduino IDE</a>
   
2.2. C Programlama Dili 
================================================================================

   Gömülü sistemlerde programlama yapmak Windows ve benzeri ortamlarda
   programlama yapmaktan biraz farklı ve genelde daha kısıtlıdır. En önemli
   kısıt RAM ve ROM miktarlarındadır. Gömülü sistemlerde bare-metal programlama
   yapılırken dinamik hafıza yönetimi istenmez. Kod içinde kullanılan tüm hafıza
   bileşenleri sabit adres ve büyüklüğe sahip olacak şekilde ayarlanır. C ile
   yazılan bir programın derlenme ve çalışma aşamalarına bakalım. 
   
2.2.1. Preprocessor (Ön işlemci) 
--------------------------------------------------------------------------------
   
   Preprocessor programın derlenmesinden önce çalıştırılan bir prosestir.
   Aslında bir nevi ön derleyici de denebilir. Preprocessor komutları diyez
   işareti (#) ile başlar. Preprocessor komutları kodun taşınabilirliğine
   büyük katkı sağlar. Yazmış olduğunuz kodları farklı mikrodenetleyicilerde
   kullanmak istiyorsanız donanıma özgü tanımlamaları kendi kodlarınızdan önce
   tanımlamanız gerekmektedir.
   
   .. code-block:: C
      
      #if defined(__ARMCC_VERSION)
      const char *mimari = "ARM"
      #elif defined(__AVR__)
      const char *mimari = "AVR"      
      #else
      const char *mimari = "Bilinmeyen"
      #endif
      
      printf("%s\n", mimari);
   
   Bu örnekte kullandığımız işlemciye göre mimariyi printf ile yazdırabiliriz.
   Eğer bu kod ARM derleyicide çalışırsa preprocessor öntanımlı
   ``__ARMCC_VERSION`` tanımından dolayı ``mimari`` katar dizisine ``ARM``
   yazacaktır. Eğer bu kod parçağını ``ARM`` ya da ``AVR`` harici bir derleyici
   ile derlerseniz ``mimari`` katar dizisine ``Bilinmeyen`` yazacaktır. 
   
   .. code-block:: C
      
      #define LED_PIN  (13)
      
      pinMode(LED_PIN, OUTPUT);
      
   Bu örnekte ise preprocessor çalıştıktan sonra kod ``pinMode(13, OUTPUT);``
   olarak değişecek ve derleyici değişmiş kod üzerinden derleme yapacaktır.
   
2.2.2. Derleyici (Compiler) 
--------------------------------------------------------------------------------

   Derleyici yazmış olduğumuz C kodlarından assembler kodlarını üreten bir
   yazılımdır. Eğer optimizasyon aktif ise kod optimizasyonu bu aşamada
   gerçekleştirilir. Her bir modül tek tek derlenerek her modüle ait obje
   dosyaları oluşturulur. Burada oluşturulan obje dosyaları adres bilgisi
   içermezler. 

2.2.3. Bağlayıcı (Linker) 
--------------------------------------------------------------------------------

   Wikipedia linker için bağlayıcı terimini kullanmış. Bu aşama son aşamadır.
   Oluşturulan obje dosyalarından çalışabilir uygulama oluşturulur. Bağlayıcı
   programa adres haritası verilmesi gerekir. Adres haritasında hafıza blokları
   ve özellikleri belirtilir. Aşağıda STM32F103X6 mikrodenetleyicisine ait ROM
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
        RAM (rw) : ORIGIN = 0x20000000, LENGTH = 0x00002800
      }

   Bağlayıcı; derleyici tarafından oluşturulan obje dosyalarında tanımlanmış
   fonksiyon, değişken, vb diğer tanımları alır ve sırayla kod bloğuna
   yerleştirir. Fonksiyonların, değişkenlerin adresleri bu aşamada belirlenir.
   En son çalışmaya hazır olan program dosyası üretilir. Bu dosya direk
   işlemciye yazılacak kodu, hata ayıklama bilgileri, adres haritası vb. bir çok
   bilgiyi de içerir. İşlemciye kopyalanacak dosya obje kopyalama programları
   ile bu dosya içerisinden çıkartılır.





























