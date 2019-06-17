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
:index:`GNU Arm` Toolchain Kurulumu
################################################################################

ARM çekirdeğine sahip mikrodenetleyici ve mikroişlemcilerine yazılan C/C++
kodlarını derlemek için kullanılan derleyicilerden bir tanesi de GNU ARM 
derleyici topluluğudur. Bu derleyici topluluğu GNU C derleyicisinin ARM firması
tarafından dağıtılan bir versiyondur. ARM firması ayrıca ücretli ARM derleyicisi
de sağlamaktadır. İki derleyici arasındaki farklar genelde optimizasyon odaklı
konularda belli olmaktadır. Eğer ücretsiz sunulan GNU Arm derleyici performans 
konusunda işinize yaramaz ise diğer derleyicileri denemenizi tavsiye ederim.

GNU toolchain versiyonu olarak 
**ARM GNU 7.3.1 (GNU Tools for Arm Embedded Processors 7-2018-q2-update)** 
seçilmiştir. Bu versiyonun seçilme sebebi **Atollic**, **STM32CubeIDE**, 
**Atmel Studio** geliştirme ortamlarının da **7.3.1** versiyonunu kullanıyor 
olmasıdır.

|arm_gnu_wp_link_html| |arm_gnu_wp_link_latex| websitesinde detaylı bilgileri
bulabilirsiniz.

Bu sayfada bir IDE'ye ihtiyaç duymadan çapraz derleme(İng.cross-compile) için
gerekli kurulumları anlatacağım. Burada Windows tabanlı bir sistem kuracağız ama
Linux için de kurulumlar benzer olacaktır. Gerekli olan bileşenler:

   #. İnternet bağlantısı :)
   #. |msys2_wp_link_html| |msys2_wp_link_latex|
   #. |kurulum_script_link_html| |kurulum_script_link_latex|

.. note::
   
   STM32 ile verilen örneklerde GNU C kullanacağım. Derleme için CMake ve make
   birlikte kullanılacaktır. Derlemede kullanılan kaynak dosyaları, başlık
   dosyaları yolları, derleyici ve linker ayarları CMake script dosyasından
   ayarlanacaktır.


.. |arm_gnu_wp_link_html| raw:: html

   <a href="https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads" 
   target="_blank">ARM GNU Toolchain</a>
   
.. |arm_gnu_wp_link_latex| raw:: latex

   \href{https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads}
   {ARM GNU Toolchain}
   
********************************************************************************
MSYS2 Kurulumu
********************************************************************************

MSYS2 platformu en sade hali ile Windows üzerinde çalışan bir Bash terminal
emülatorüdür. |msys2_wp_link_html| |msys2_wp_link_latex| websitesinden en son
paketlenen sürümünü indirip kurun. 64-bit sürümünü kurmanızı tavsiye ederim.

.. image:: ../pictures/02_toolchain_01.png
   :align: center
   
Kurulum bittikten sonra başlat menünüze MSYS2 klasörü gelecektir. Başlat
menüsünden **MSYS2 MinGW 64-bit** olan sürümü çalıştırın.

.. image:: ../pictures/02_toolchain_02.png
   :align: center

Açılan terminal ekranına ``pacman -Syu`` komutunu yazıp onaylayın. 

.. image:: ../pictures/02_toolchain_03.png
   :align: center

Sistem güncellemesi yapıldıktan sonra terminal penceresini direk kapatmanızı 
isteyen bir not göreceksiniz. Terminal ekranın sağ üst köşesindeki **X** kapatma
düğmesine tıklayarak pencereyi kapatın. Tıkladığınızda bir uyarı verecektir 
onaylayıp pencereyi kapatın.

.. image:: ../pictures/02_toolchain_04.png
   :align: center

Tekrar **MSYS2 MinGW 64-bit** terminalini açın. Az önce verdiğimiz 
``pacman -Syu`` komutunu tekrar yazıp çalıştırın. Bu sefer sistem güncellemesi
değil kurulu paketlerin güncellenmesini onaylamanızı isteyecektir. Onaylayıp 
kurulumun bitmesini bekleyin.

.. image:: ../pictures/02_toolchain_05.png
   :align: center

Güncellemeler bittikten sonra |kurulum_script_link_html|
|kurulum_script_link_latex| dosyasını indirip MSYS2 kullanıcı kllasörüne
kopyalayın. MSYS2 kullanıcı klasörü MSYS2 kurulum klasörü altında 
**\\home\\KullanıcıAdı\\** klasörüdür. Klasöre kopyaladıktan sonra terminalde 
``cd #`` veya ``cd ~`` komutunu verin. ``ls`` komutu ile dizin içeriğini
listeleyin. Listede **ilk_kurulum_script.sh** dosyasını gördükten sonra 
``./ilk_kurulum_script.sh`` komutu ile kurulumu başlatın.

.. image:: ../pictures/02_toolchain_06.png
   :align: center

Kurulum süresi bağlantı hızınız, işlemci hızını vb. etkenlere göre değişiklik
gösterir ve 1-5 dk. sürebilir. Terminal ekranında durumu izleyebilirsiniz.
Kurulum bittikten sonra ARM GNU toolchain bilgisayarınıza kurulmuş olacaktır. 

********************************************************************************
Windows Ayarları
********************************************************************************

ARM GNU toolchain **MinGW** terminali altında script ile kurulduktan sonra 
herhangi bir ek ayara gerek kalmadan çalışacaktır. Fakat Windows için ARM GNU 
toolchain ve MSYS2 kurulumlarının PATH'e eklenmesi gerekmektedir. Windows ortam
değişkenlerinden PATH değişkenine **C:\\ARM\\gcc-arm-none-eabi-7\\bin** ve 
**X:\\msys64\\usr\\bin** yollarını eklemeniz gereklidir. Eğer **MSYS2**
kurulumunu başka bir yere yaptı iseniz yolu değiştirmeniz gerekli.

.. image:: ../pictures/02_toolchain_07.png
   :align: center

.. |msys2_wp_link_html| raw:: html

   <a href="https://www.msys2.org/"
   target="_blank">MSYS2</a>
   
.. |msys2_wp_link_latex| raw:: latex

   \href{https://www.msys2.org/}
   {MSYS2}

.. |kurulum_script_link_html| raw:: html

   <a href="https://raw.githubusercontent.com/IBeRyUS/Gomulu_Sistemler/521705a34a6dbaf0a705f55bfdcace467305f158/code_snippets/ilk_kurulum_script.sh"
   target="_blank">İlk Kurulum Script</a>
   
.. |kurulum_script_link_latex| raw:: latex

   \href{https://raw.githubusercontent.com/IBeRyUS/Gomulu_Sistemler/521705a34a6dbaf0a705f55bfdcace467305f158/code_snippets/ilk_kurulum_script.sh}
   {İlk Kurulum Script}
