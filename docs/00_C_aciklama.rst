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
:index:`C` Programlama Dili
################################################################################

Buradaki açıklamaları kolay anlamak için en az bir programlama dilini 
bilmeniz gereklidir. Eğer C diline ait bir bilginiz yok ise tavsiyem C 
programlama dilini anlatan bir kitabı okumanızdır. Ben C diline
|rifat_colkesen_html| |rifat_colkesen_latex|'in yazmış olduğu C kitabını 
okuyarak başlamıştım. 

Gömülü sistemlerde genel olarak iki programlama mimarisinden biri seçilir. 
Bunlar:

   *  :index:`Bare-metal` (direk firmware hazırlamak)
   *  Gerçek zamanlı işletim sistemi(:index:`RTOS`) üzerinde çalışmak
         
Genel olarak ben bare-metal programlama tercih ediyorum. Şimdilerde gömülü 
sistemlerde kullanılan mikrodenetleyiciler eski mikrodenetleyicilerden daha 
fazla RAM ve ROMa sahip olduğu için RTOS'lerin kullanımı giderek artmakta.
Mesela 64 bayt RAM ve 1K işlemci komut hafızasına sahip bir mikrodenetleyici
ile RTOS gerçekleştirmek çok kolay olmasa gerek :)

C dili üst seviye bir programlama dili olmasına rağmen çok güçlü donanım 
erişimi sağlamasından dolayı gömülü sistemlerde yaygın olarak 
kullanılmaktadır. Dile ait ANSI ve ISO standartlarının yayınlanmasından sonra
kod taşınabilirliği önemli ölçüde kolaylaşmıştır. Bu sayede yazdığınız kodu
çok az değiştirerek farklı işlemci mimarileri için derlemeniz ve çalıştırmanız
mümkündür. Uygulama örneği olarak UNIX, Linux işletim sistemlerinin 
çekirdekleri C dili ile yazılmıştır. 
  
.. |rifat_colkesen_html| raw:: html

   <a href="https://www.dr.com.tr/Kitap/C-Programlama-Dili/Rifat-Colkesen/Egitim-Basvuru/Bilgisayar/urunno=0000000163645"
   target="_blank">Rifat Çölkesen - C Programlama Dili</a>

.. |rifat_colkesen_latex| raw:: latex

   \href{https://www.dr.com.tr/Kitap/C-Programlama-Dili/Rifat-Colkesen/Egitim-Basvuru/Bilgisayar/urunno=0000000163645}
   {Rifat Çölkesen - C Programlama Dili}

********************************************************************************
Kod Bölümleri
********************************************************************************

Her programlama dilinde olduğu gibi C dilinde de uyulması gereken bir format ve
kodlama terimleri mevcuttur. Burada kısaca C dilinde kullanılan bölümleri ve 
etkilerini anlatmaya çalışacağım. Aşağıdaki örnek koda bakalım:

.. literalinclude:: ../code_snippets/kod_bolumleri.c
   :lines: 20-
   :linenos:   


********************************************************************************
C Programlama Dili Konuları
********************************************************************************

.. warning::
   **C Programlama Dili Konuları** C dilini anlatmayı amaçlamamaktadır. Asıl
   amacı C diline ait terimlerin gömülü sistemlerdeki karşılığını ve kullanım
   yöntemlerini açıklamaya çalışmaktır. C diline ait açıklanmamış konular ve
   terimler için lütfen C programlama dilini anlatan bir kaynağa başvurun.

.. toctree:: 
   :maxdepth: 1
   
   00_C_aciklama/bilesenler.rst
   00_C_aciklama/hafiza_yonetimi.rst
   00_C_aciklama/terimler.rst
   00_C_aciklama/derleme_asamalari.rst
