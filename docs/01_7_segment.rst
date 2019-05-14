********************************************************************************
7 Segment LED
********************************************************************************

   İlk örnek olarak 7 segment LCD display ile başlayacağız. 

1. 7 Segment Şema
================================================================================

   Aşağıdaki şemada ATmega328p mikrodenetleyicisine bağlanmış iki adet 7 segment LED display ve iki buton bulunmaktadır. 

   https://gomulu-sistemler.readthedocs.io/tr/feature-gs-3_7-segment_ornegi_ekle/_static/code_snippets/main.c

   https://gomulu-sistemler.readthedocs.io/tr/feature-gs-3_7-segment_ornegi_ekle/_images/7_segment_01.PNG

   Örnek kod için `kod <_static/code_snippets/main.c>`_ 

   .. figure:: ../schematics/7_segment_01.PNG
      :align: center
      :alt: 7-Segment Şema
      :figclass: align-center
      
      7-Segment Şema


2.1. Kullanılacak Yazılımlar ve Donanımlar
================================================================================

   .. note:: 
      Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde **sadece** Arduino öğretilmesine karşıyım. Buradaki örneklerin aynı zamanda gerçek donanım üzerinde de test edilebilmesi için en ucuz ve kolay bulunan protorip bordu olan Arduino örneklerine de yer vereceğiz.
      
   * Şemalar simulasyon odaklı verilecektir. Simulasyon için Proteus yazılımı kullanılacaktır. Proteus versiyon 8.7 SP3'dür. Proteus nereden bulunur vb. soruları lütfen sormayınız.
   * Arduino Atmega328p çipine sahip UNO veya NANO 
   * `Arduino geliştirme ortamı <https://www.arduino.cc/en/Main/Software>`_ 
