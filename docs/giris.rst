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

Gömülü sistem örneklerinde genel olarak bare-metal(herhangi bir işletim
sistemi veya iş yönetim sistemi kullanmadan direk yazılımın mikrodenetleyici
üzerinde çalışığı) örneklere yer vereceğim. Bare-metal uygulamalarda kullanılan 
programlama dilleri genellikle assembler ve C/C++ dilleridir. Buradaki örnekler 
C dilinde yazılmış olacaktır.

********************************************************************************
Ekstra Bilgiler
********************************************************************************

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
