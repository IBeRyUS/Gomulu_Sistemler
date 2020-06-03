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
Geliştirme Ortamı
********************************************************************************

ST firmasının STM32 serisi ARM Cortex çekirdeklerini kullanıyor. ST firmasının 
STM32F103C8T6 model mikrodenetleyicisinin olduğu küçük prototip kartını makul bir
fiyata alabilirsiniz. Bu kartı programlamak için ayrıca SWD destekli bir 
programlayıcı modülü de almanız gerekiyor. ST-LINK/V2 klonları işinizi 
görecektir.(Bu yazının yazıldığı 10.06.2019 tarihinde iki modülün toplam fiyatı
50 TL civarındadır)

Eğer elinizde herhangi bir ST Nucleo, Discovery yada Eval board var ise onların 
üzerindeki ST-LINK'leri kullanabilirsiniz.

STM32 serisi için Proteus kısıtlı bir simulasyon desteği sağlıyor. STM32F103C8
modeli yok ama STM32F103C6 modeli mevcut. ROM/RAM yarısı ve bazı donanımların
sayısı az ama test örnekleri için yeterli olacaktır. 

STM chipleri için ST firmasının ücretsiz olarak sağladığı |stm32cubeide_link_html|
|stm32cubeide_link_latex|'yi indirebilirsiniz. STM32CubeIDE Eclipse tabanlı bir IDE'dir. 
Eclipse CDT üzerine ST firmasının yazdığı plug-in'ler; donanım üzerinde hata ayıklama, 
STM için optimize newlib kütüphanesi, CubeMX entegrasyonu, vb. bir sürü ekleme mevcuttur. 

Burada bulunan örnek projeler STM32CubeIDE ile oluşturulmuştur. 

STM32 örnekleri için ihtiyacımız olanlar :

   *  STM32F103C8 prototip bordu
   *  SWD desteği olan bir programlayıcı (ST_LINK/V2 klonları uygundur)
   *  |stm32cubeide_link_html| |stm32cubeide_link_latex|



.. |stm32cubeide_link_html| raw:: html

   <a href="https://www.st.com/en/development-tools/stm32cubeide.html"
   target="_blank">STM32CubeIDE</a>

.. |stm32cubeide_link_latex| raw:: latex

   \href{https://www.st.com/en/development-tools/stm32cubeide.html}
   {STM32CubeIDE}

.. |keil_link_html| raw:: html

   <a href="http://www.keil.com/"
   target="_blank">Keil</a>

.. |keil_link_latex| raw:: latex

   \href{http://www.keil.com/}
   {Keil}

