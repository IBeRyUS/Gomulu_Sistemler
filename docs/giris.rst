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

Gömülü sistemler örneklerinde kolaylıkla satın alınabilecek geliştirme kartları 
üzerinden örnekler vermeye çalışacağım. Özellikle Arduino ve STM32 kartları 
kolayca ve ucuza bulunabilmektedir. Gömülü sistemlerde bu tarz kartları yeni 
donanımları öğrenmek ve hızlıca testler yapmak için kullanabilirsiniz. Genel
olarak bu yaklaşımı uygulamıyorum. Önce şema ve ilk prototip kartını hazırlayıp
ondan sonra sürücü fonksiyonları ile başlıyorum. Kullanacak olduğunuz 
mikrodenetleyiciye ait donanımları okumadan, özelliklere bakmadan ezbere kod
yazmaya başlamak ileride size sorun yaratabilir. Bazen bir pin değişikliği ile
yüzlerce satır koddan kurtulabilir, daha hızlı cevaplar üretebilirsiniz.

Ben çoğu elektronik malzemeyi Çin'deki alışveriş sitelerinden alıyorum. Son
yayınlanan gümrük mevzuatı değişiklikleri ile artık Çin'den direk alım yapmak 
pek cazip değil. Yurtiçi firmalardan arduino klonlarını makul bir fiyata alıp
kullanmaya başlayabilirsiniz.

Arduino Ortamı 
================================================================================

Arduino gcc-avr derleyici topluluğunun C/C++ derleyicisini kullanır. AVR ve bazı
3. parti kütüphaneler harici bir çok kütüphanesi C++ ile yazılmıştır. IDE
üzerinde yazılan kodlarınız aslında bir C++ kod dosyası içine alınarak aşağıdaki
main.cpp dosyası içinden çağırılır. 

.. note::
   
   Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde
   **sadece** Arduino öğretilmesine karşıyım. Normalde Arduino örneği yazmayı
   düşünmüyordum ama matematik karşısında elim kolum bağlandı. Matematik diyor
   ki hiçbir şey yapmamak ile az da olsa bir şeyler ile başlayarak öğrenmek 
   arasında sonsuz oran vardır. (sayı / 0 :)) Öğrenmede tatmin edicilik olması 
   ve gerçek dünyada çalışan bir kodu görmeniz için açısından ucuz ve kolay 
   bulunan Arduino bordları için de örneklere yer vereceğim. 

.. warning::

   Arduino IDE'sinin hibrit yapısında dikkat etmeniz bir kaç nokta vardır. 
   Normal C projeleri gibi bir main() fonksiyonu yoktur. Bunun yerine setup() ve
   loop() fonksiyonlarını sağlar. Ayrıca fonksiyonların prototip tanımlarını 
   kodunuzu tarayarak otomatik olarak çıkartır.

\

   *  Şemalar simulasyon odaklı verilecektir. Simulasyon için Proteus yazılımı
      kullanılacaktır. Proteus versiyon 8.7 SP3'dür. Proteus nereden bulunur vb.
      soruları lütfen sormayınız.
   *  Arduino Atmega328p çipine sahip UNO veya NANO 
   *  |arduino_ide_link_html| |arduino_ide_link_latex| 

.. literalinclude:: ../code_snippets/arduino_main.cpp
   :linenos:
   

.. |arduino_ide_link_html| raw:: html 

   <a href="https://www.arduino.cc/en/Main/Software" 
   target="_blank">Arduino IDE</a>

.. |arduino_ide_link_latex| raw:: latex

   \href{https://www.arduino.cc/en/Main/Software}{Arduino IDE}

STM32 Ortamı 
================================================================================

ST firmasının STM32 serisi ARM Cortex çekirdeklerini kullanıyor. ARM çekirdek
ailesi ile hiçbir sorunum olmamasına rağmen ST firmasının donanımlarını pek
sevmiyorum. Dökümanlarını çoğu zaman az anlaşılır ve karışık bulmuşumdur. 
Özellikle donanımların ilave özelliklerini anlatan kısımların anlatımlarını zayıf
buluyorum. Genel olarak bu bilgiler size o mikrodenetleyici ile çalışmaya 
başladığınızda sürücü yazarken bir kere lazım oluyor. Sürücünüzü yazdıktan
sonra geriye kalan kısım C ile kod yazmak :) ST firmasının STM32F103C8T6 model
mikrodenetleyicisinin olduğu küçük prototip kartını yurtiçi piyasadan makul bir
fiyata alabilirsiniz. Bu kartı programlamak için ayrıca SWD destekli bir 
programlayıcı modülü de almanız gerekiyor. ST-LINK/V2 klonları işinizi 
görecektir.(Bu yazının yazıldığı 10.06.2019 tarihinde iki modülün toplam fiyatı
50 TL civarındadır)

STM32 serisi için Proteus kısıtlı bir simulasyon desteği sağlıyor. STM32F103C8
modeli yok ama STM32F103C6 modeli mevcut. ROM/RAM yarısı ve bazı donanımların
sayısı az ama test örnekleri için yeterli olacaktır. Derleyici olarak ücretsiz
eclipse tabanlı STM32CubeIDE kullanacağız. STM32CubeIDE ST firması tarafından
sağlanan GCC-ARM derleyici topluluğunu kullanan bir IDE'dir. Derleyici ARM
firması tarafından sağlanmakta, ST firması da eclipse tabanlı bir IDE
sunmaktadır. 

STM32 örnekleri için ihtiyacımız olanlar :

   *  STM32F103C8 prototip bordu
   *  SWD desteği olan bir programlayıcı (ST_LINK/V2 klonları uygundur)
   *  |stm32ide_link_html| |stm32ide_link_latex|

.. |stm32ide_link_html| raw:: html

   <a href="https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html" 
   target="_blank">STM32 Cube IDE</a>

.. |stm32ide_link_latex| raw:: latex

   \href{https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html}
   {STM32 Cube IDE}

C Programlama Dili 
================================================================================

Gömülü sistemlerde programlama yapmak Windows ve benzeri ortamlarda
programlama yapmaktan biraz farklı ve genelde daha kısıtlıdır. En önemli
kısıt RAM ve ROM miktarlarındadır. C diline ait detaylı açıklamalar için 
:doc:`bu linki <01_C_aciklama>` takip edebilirsiniz.
