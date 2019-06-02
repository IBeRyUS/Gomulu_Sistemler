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
Gömülü Sistem Ne Demektir
********************************************************************************

Gömülü sistemler kısaca sistemin çalışması için gereken tüm donanım ve yazılım
ekipmanların bir arada bulunduğu sistemlerdir. Gömülü sistemler genel 
kullanımdan ziyade ihtiyaç duyulan göreve/işe göre özel olarak tasarlanırlar. 
Gömülü sistemleri buradaki bir kaç satır ile anlatmak maalesef mümkün değildir.
Daha detaylı bilgiler için diğer kaynakları araştırmanızı tavsiye ederim.

********************************************************************************
Geliştirme Ortamı
********************************************************************************

Gömülü sistem örneklerinde genel olarak bare-metal(herhangi bir işletim
sistemi veya iş yönetim sistemi kullanmadan direk yazılımın mikrodenetleyici
üzerinde çalışığı) örneklere yer vereceğim. Bare-metal uygulamalarda
kullanılan programlama dilleri genellikle assembler ve C dilidir. Buradaki
örnekler C dilinde yazılmış olacaktır.

Özellikle birden fazla kişinin birlikte çalıştığı projelerde kodlama
standardı uygulanması proje yönetimi ve kod anlaşılabilirliğini arttırır.
Kodlama yapılırken sadece kodlama standardı değil farklı standartlara 
uygunluk da kontrol edilebilir. Örneğin güvenlik 
öncelikli(İng.Safety-critical) sistemlere ait kodlarda MISRA standartlarına 
uygunluk da kontrol edilir. Örnek kodlama standardı olarak |barr_link_html|
|barr_link_latex|'na bakabilirsiniz.

.. |barr_link_html| raw:: html
   
   <a href="https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard" 
   target="_blank">Barr Kodlama Standardı</a>

.. |barr_link_latex| raw:: latex

   \href{https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard}
   {Barr Kodlama Standardı}

Kullanılacak Yazılımlar ve Donanımlar
================================================================================

.. note::
   
   Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde
   **sadece** Arduino öğretilmesine karşıyım fakat buradaki örneklerin aynı
   zamanda gerçek donanım üzerinde de test edilebilmesi için en ucuz ve
   kolay bulunan prototip bordu olan Arduino örnekleri ile başlayacağız. Arduino
   IDE'si tanımladığınız fonksiyonların prototip tanımlarını otomatik olarak 
   derleme aşamasından önce derlenecek koda ekliyor. O yüzden **Arduino** 
   örneklerinde fonksiyon prototipleri verilen kodlarda yoktur.

\

   *  Şemalar simulasyon odaklı verilecektir. Simulasyon için Proteus yazılımı
      kullanılacaktır. Proteus versiyon 8.7 SP3'dür. Proteus nereden bulunur vb.
      soruları lütfen sormayınız.
   *  Arduino Atmega328p çipine sahip UNO veya NANO 
   *  |arduino_ide_link_html| |arduino_ide_link_latex| 

.. note::

   Arduino örneklerinde main() fonksiyonu yerine setup() ve loop() fonksiyonları
   bulunmaktadır. Setup() açılışta bir defa çalışır loop() ise sonsuz döngü
   içinde döner.

.. |arduino_ide_link_html| raw:: html 

   <a href="https://www.arduino.cc/en/Main/Software" 
   target="_blank">Arduino IDE</a>

.. |arduino_ide_link_latex| raw:: latex

   \href{https://www.arduino.cc/en/Main/Software}{Arduino IDE}


C Programlama Dili 
================================================================================

Gömülü sistemlerde programlama yapmak Windows ve benzeri ortamlarda
programlama yapmaktan biraz farklı ve genelde daha kısıtlıdır. En önemli
kısıt RAM ve ROM miktarlarındadır. C diline ait detaylı açıklamalar için 
:doc:`bu linki <00_C_aciklama>` takip edebilirsiniz.
