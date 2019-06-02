Aşağı Yukarı Sayıcı
--------------------------------------------------------------------------------

Bu örnek iki buton ile 0 - 99 sayıcı örneğidir. Aşağıda aynı işi yapan farklı 
kod örnekleri vardır.  

İlk örnek kod taşınabilirliği ve anlaşılabilirliği açısından zayıf bir örnektir.
Kodlar optimize yazılmamış ve kod yoğunluğu gayet düşük bir koddur. 

İkinci örnek aynı kodun taşınabilirliği, okunabilirliği ve optimize edilmiş 
halini içerir. Pin giriş ve çıkışların Arduino kütüphaneleri kullanılmıştır.

Üçüncü örnek herhangi bir  kütüphane kullanmadan bir mikrodenetleyici nasıl C 
ile kodlanır örneğidir. Bu örnek ile ikinci örneği karşılaştırıp **Arduino**
fonksiyonları yerine direk mikrodenetleyici registerları ile nasıl yapıldığını
anlamaya çalışmanızı tavsiye ederim. 

.. note::

   Üçüncü örnek de Arduino IDE'sinde yapılacağı için **setup()**, **loop()** 
   fonksiyonları bu örnekte de bulunmaktadır.

Örnek - 1 
================================================================================

Bu örnek ilk programlamaya başladığım zamanlarda yazdığım kodlara çok benzer :)
Listede bu kodun eksik noktaları belirtilmiştir.

   #. Tekrarlanan işler döngülere alınmamış Kopyala-yapıştır ile çoğaltılmış
   #. Tanımlama hiç kullanılmamış, en ufak pin değişikliğinde tüm kodun elden 
      geçmesi gerekir
   #. Aynı işi yapan iki ayrı fonksiyon kullanılmış
   #. Lokal bir değişken ile çözülebilecek ``sayac`` değişkeni global olarak
      tanımlanmış
   #. Kod yoğunluğu ve derleyici optimizasyonu uygunluğu düşük bir kod

.. literalinclude:: ../../code_snippets/01_7_segment/asagi_yukari_sayici_01.c
   :linenos:
   
Örnek - 2
================================================================================

Bu örnekte C dilinde ön-işlemci tanımlamaları, döngüler, bit işlemleri, **? : 
operatörü**, fonksiyonlaştırma örneklerini göstermeye çalıştım. LED Display
bağlantıları değişirse sadece ilk baştaki tanımları değiştirmeniz yeterlidir. 
Hatta maksimum değer, sayı tabanı vb. değerleri değiştirdiğinizde sonuç çok
kolay bir şekilde üretilecektir. Üçüncü bir display ekleyip 8'li sayı tabanında
bir sayıcı yapmayı deneyebilirsiniz.

.. literalinclude:: ../../code_snippets/01_7_segment/asagi_yukari_sayici_02.c
   :linenos:

Örnek - 3
================================================================================

Bu örnekte ise mikrodenetleyiciye ait bir sürücü kütüphanemiz yok. Tüm giriş ve
çıkış işlemleri mikrodenetleyici Port donanımı üzerinden yapılacak. Sadece AVR
derleyici ve üretici tanım başlık dosyaları kullanılmıştır. PORTB adresini elle 
tanımlamak yerine üretici başlık dosyasındaki tanımı kullanır.

.. literalinclude:: ../../code_snippets/01_7_segment/asagi_yukari_sayici_03.c
   :linenos:
