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
C Dilinde Kullanılan Bazı Terimler
********************************************************************************

Burada C dilinde kullanılan bazı terimlerin nasıl kullanıldığını anlatmaya
çalışacağım.

:index:`#include` Preprocessor
================================================================================

``#include`` terimi başka bir başlık dosyasının içeriğinin kaynak veya başlık 
dosyasına dahil edilmesini sağlar. ``#include`` terimi ile sadece başlık
dosyalarını dahil etmeniz önerilir. 

Bir başlık dosyasını ``#include`` direktifi ile dahil ettiğinizde, o başlık 
dosyasındaki tüm deyim ve tanımlar dosyanıza dahil edilecektir. Bir başlık 
dosyası başka bir başlık dosyasını dahil edebilir. Burada önemli olan nokta 
içiçe başlık dosyalarını dahil etmemektir. 

Elimizde 4 adet modul1, modul2, modul3 ve modul4 olarak adlandırılımış modüller
olsun. Aşağıdaki şartlarda çalışması istenen bir projede başlık dosyalarını
başlık dosyaları içinde dahil ederseniz bu yapıyı kuramazsınız. Başlık dosyaları
içinde diğer başlık dosyalarını dahil ederseniz tüm modüller birbirine 
erişebilir durumda olacaktır ve hata ayıklamak zor olacaktır. Ayrıca derleme 
süreniz de uzayacaktır.

   *  Modul1; modul2’ye ve modul3’e erişebilsin, modul4'e erişemesin.
   *  Modul2; modul4’e erişşin, diğerlerine erişemesin
   *  Modul3; modul4’e erişsin, diğerlerine erişemesin

Ben kaynak dosyalarında şu sıra ile ``#include`` direktiflerini kullanırım. 

   #. mikrodenetleyiciye ait başlık dosyaları
   #. Standard C kütüphaneleri başlık dosyaları
   #. Dahil edilecek diğer modül başlık dosyaları
   #. Kaynak dosyasına ait başlık dosyası
   
:index:`#define` Preprocessor
================================================================================

``#define`` terimi ile kodda kullanılacak koda özel tanımlamaları tanımlarız. 
Bu terim ile tek bir değer tanımlamaktan makro fonksiyon tanımlamaya kadar
bir çok tanımlama yapabiliriz. Aynı zamanda farklı derleme modları için
tanımlama yaparak farklı çıktı üretebiliriz. 

Örnek olarak bir projede iki adet baskı devre kartı yada sistem kurdunuz. Bir
tanesinde LCD ekran ile direk bilgi alırken diğer kartta LCD ekran bulunmuyor.
LCD ekran üzerinde hata ayıklama mesajları gösterirken aynı kodun LCD ekran
olmayan test kartında da çalışmasını istiyorsunuz. Bunu yapmak için aşağıdaki
gibi bir kod yazabiliriz.
   
.. code-block::
   
   #define LCD_DEBUG
   
      ....
      ....
      sonuc = fonksiyon(degisken1, degisken2);
   
   #ifdef LCD_DEBUG
      lcd_yazdir(sonuc);
   #endif
      seri_port_gonder(sonuc);


Bu kod ile ``LCD_DEBUG`` tanımlamasını aktif ettiğinizde sonucunuz lcd ekrana
yazdırılırken, tanımlamayı deaktif ederseniz lcd ekrandan çıktı almazsınız.

:index:`volatile`
================================================================================

C dilinde anlaşılması zor olan terimlerden birisidir ``volatile`` terimi. 
Direk çevirisi uçucu olan bu terim bir çok hata(İng.bug)'nın ana sebebidir. 
Kod normal çalışırken optimizasyon açıldığı anda düzgün çalışmamaya başlar 
ise büyük ihtimal bir değişken ``volatile`` tanımlanması gerekirken 
``volatile`` olarak tanımlanmamıştır. 

``volatile`` değişken tanımlanırken kullanılan bir terimdir. Bu terim
derleyiciye tanımlanan değişkenin uçucu bir değere sahip olduğunu belirtir. 

Peki nedir bu uçucu tanımı? Uçucu; değişkenin değerinin her an değişebileceği
ve her seferinde yeni değerin kullanılması gerektiğini belirtir. Aşağıdaki 
kod üzerinde incelersek:

.. literalinclude:: ../../code_snippets/volatile_ornek.c
   :lines: 20-
   :linenos:   

``timer_ISR()`` fonksiyonu bir zamanlama kesme fonksiyonu olarak çalışıyor.
Belirli bir zaman geçtikten sonra periyodik zamanlanmış görevlerin yerine 
getirilmesi için ``flag`` değişkenine 1 değerini atıyor ve main fonksiyonu bu
değeri kontrol ederek zamanlanmış görevleri yerine getiriyor. Özellikle 
birden fazla working register'a sahip işlemcilerde derleyiciler optimizasyon
esnasında değişkenleri working registerlarda saklamaya çalışırlar ve 
gerekmedikçe RAM'den okuma yazma yapmazlar. Eğer derleyiciye ``flag`` 
değişkenin uçucu olduğunu belirtmez isek ``main()`` fonksiyonu ``flag`` 
değişkenine ait değeri working register'ına kopyalayacak ve tüm kontrolleri
working registerdaki değere göre yapacaktır. ``flag`` değişkeninin değeri
``main()`` fonksiyonu haricinde bir yerde değiştirildiğinde ``main()`` 
fonksiyonu değişkeni tekrar okuyarak kontrol etmediği için yapılan değişimin
bir etkisi olmayacaktır. 

:index:`const`
================================================================================

``const`` **constant** kelimesinin kısaltması olarak yazılmış ve sabit anlamına
gelmektedir. ``const`` terimi derleyiciye tanımlanan değişkenin değerinin 
değiştirilemeyeciğini belirtmektir. Her değiştirelemeyen değişken ROM üzerinde
tanımlanmaz. Çoğu durumda ``const`` ile tanımlı değişkenler RAM'de tanımlıdır. 

:index:`static`
================================================================================

``static`` terimini Türkçe'ye sabit yada kalıcı olarak çevirebiliriz. C dilinde
``static`` terimi kalıcı ve gizli görevlerini yerine getirir. Eğer bir fonksiyon
içinde statik değişken tanımlarsanız bu değişken fonksiyondan çıkıldığında
değerini muhafaze edecek ama o fonksiyon dışında erişilemez olacaktır. Eğer bir
fonksiyon veya genel değişken tanımında ``static`` terimini kullanırsanız bu 
değişken veya fonksiyon diğer modüller tarafından ulaşılamaz olacaktır. Nesne
tabanlı programlama dillerindeki **private** terimine benzer bir kullanım söz
konusu olacaktır.
