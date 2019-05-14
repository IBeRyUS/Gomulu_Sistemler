################################################################################
Giriş
################################################################################

.. note::
   Buradaki örneklerde ya da açıklamalarda C dili anlatılmayacak, daha çok C dilinin uygulamaları üzerine bilgiler verilecektir. Buradaki uygulamaları incelemek ve anlamak için temel elektronik, mikrodenetleyici donanım, algoritma ve C programlama dili bilgilerine sahip olmanız gerekmektedir. Verilen kodların satır satır açıklamaları yapılmayacak, şemalarda çok fazla detaya inilmeyecektir.

********************************************************************************
1. Gömülü Sistem Ne Demektir
********************************************************************************

   Gömülü sistemler kısaca üzerinde çalışan yazılımın kullanıcı tarafından özelleştirilmesinin ve değiştirilmesinin (üreticinin sağladığı yazılım güncellemesinden hariç kullanıcı tarafından yazılan yazılım ile fonksiyonun değiştirilmesi) çok kolay olmadığı, sistemin çalışması için gereken tüm ekipmanların bir kart veya kutu içerisinde toplandığı sistemlerdir. Bununla ilgili internette birçok kaynak mevcut ufak bir araştırma ile daha detaylı bilgilere ulaşabilirsiniz. 
   

********************************************************************************
2. Geliştirme Ortamı
********************************************************************************

   Gömülü sistem örneklerinde genel olarak bare-metal(herhangi bir işletim sistemi veya iş yönetim sistemi kullanmadan direk yazılımın mikrodenetleyici üzerinde çalışığı) örneklere yer vereceğim. Bare-metal uygulamalarda kullanılan programlama dilleri genellikle assembler ve C dilidir. Biz örneklerimizde özellikle gömülü sistemler için kullanılan C diline ait kodları inceleyeceğiz. 

   Özellikle birden fazla kişinin birlikte çalıştığı projelerde kodlama standardı uygulanır. Kodlama yapılırken sadece kodlama standardı değil farklı standartlarda kontrol edilebilir. Örneğin güvenlik öncelikli sistemlere ait kodlarda MISRA standartlarına uygunluğu da kontrol edilir. Örnek kodlama standardı olarak `Barr Kodlama Standardına <https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard>`_ bakabilirsiniz.


2.1. Kullanılacak Yazılımlar ve Donanımlar
================================================================================

   .. note:: 
      Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde **sadece** Arduino öğretilmesine karşıyım. Buradaki örneklerin aynı zamanda gerçek donanım üzerinde de test edilebilmesi için en ucuz ve kolay bulunan protorip bordu olan Arduino örneklerine de yer vereceğiz.
      
   * Şemalar simulasyon odaklı verilecektir. Simulasyon için Proteus yazılımı kullanılacaktır. Proteus versiyon 8.7 SP3'dür. Proteus nereden bulunur vb. soruları lütfen sormayınız.
   * Arduino Atmega328p çipine sahip UNO veya NANO 
   * `Arduino geliştirme ortamı <https://www.arduino.cc/en/Main/Software>`_ 
