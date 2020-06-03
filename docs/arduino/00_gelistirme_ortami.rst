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
Arduino Geliştirme Ortamı
********************************************************************************

Arduino gcc-avr derleyici topluluğunun C/C++ derleyicisini kullanır. AVR ve bazı
3. parti kütüphaneler harici bir çok kütüphanesi C++ ile yazılmıştır. IDE
üzerinde yazılan kodlarınız aslında bir C++ kod dosyası içine alınarak aşağıdaki
main.cpp dosyası içinden çağırılır. 

.. note::
   
   Özellikle gömülü sistemler alanında eğitim veren mühendislik bölümlerinde
   **sadece** Arduino öğretilmesine karşıyım. Normalde Arduino örneği yazmayı
   düşünmüyordum ama matematik karşısında elim kolum bağlandı. Matematik diyor
   ki hiçbir şey yapmamak ile az da olsa bir şeyler ile başlayarak öğrenmek 
   arasında sonsuz oran vardır. Öğrenmede tatmin edicilik olması ve gerçek 
   dünyada çalışan bir kodu görmeniz için açısından ucuz ve kolay bulunan Arduino 
   bordları için de örneklere yer vereceğim.

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

.. literalinclude:: ../../code_snippets/arduino_main.cpp
   :linenos:
   

.. |arduino_ide_link_html| raw:: html 

   <a href="https://www.arduino.cc/en/Main/Software" 
   target="_blank">Arduino IDE</a>

.. |arduino_ide_link_latex| raw:: latex

   \href{https://www.arduino.cc/en/Main/Software}{Arduino IDE}
