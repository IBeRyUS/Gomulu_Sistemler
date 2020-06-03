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
Blink (Göz kırpma)
********************************************************************************

Bu örnek hem çok basit hem de en zor işlemlerden biri olan blink örneğidir.
Normal bilgisayar programlarında ekrana **"Merhaba Dünya"** yazdırmak ile aynı
özelliktedir. Eğer bir kodu derleyip çalıştırdığınızda ekranda **"Merhaba Dünya"**
yazdırabiliyorsanız çalışma ortamınız kod yazmaya hazırdır demektir. Mikrodenetleyici
dünyasında **"Merhaba Dünya"**'nın karşılığı olarak ben blink kodunu denerim. 
Mikrodenetleyiciye blink kodunu derleyip yükleyip çalıştırdığınızda ledini yanıp
sönüyorsa kod yazmaya hazırsınız demektir. Eğer yanıp sönme istediğiniz gibi
değilse bir yerlerde yanlışlık vardır ve asıl kodunuzu yazmaya başlamadan önce
bu sorunu bulup çözmeniz gerekir.

Bağlantı Şeması
================================================================================

Aşağıdaki şemada ATmega328p mikrodenetleyicisine bağlanmış üç adet 7 segment
LED display ve iki buton bulunmaktadır. Şemada kullanılan bütün dirençler 
**Proteus**'da digital olarak seçilmiştir. Bu özellik ile digital bağlantılarda 
kullanılan dirençler simulasyon esnasında analog hesaplamalara tabi tutulmaz.
Bu sayede simulasyon daha hızlı çalışır.
