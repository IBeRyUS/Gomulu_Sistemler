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


.. |arm_gnu_wp_link_html| raw:: html

   <a href="https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads" 
   target="_blank">ARM GNU Toolchain</a>
   
.. |arm_gnu_wp_link_latex| raw:: latex

   \href{https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads}
   {ARM GNU Toolchain}
   

********************************************************************************
Windows Ayarları
********************************************************************************

ARM GNU toolchain **MinGW** terminali altında script ile kurulduktan sonra 
herhangi bir ek ayara gerek kalmadan çalışacaktır. Fakat Windows için ARM GNU 
toolchain ve MSYS2 kurulumlarının PATH'e eklenmesi gerekmektedir. Windows ortam
değişkenlerinden PATH değişkenine **C:\\ARM\\gcc-arm-none-eabi-7\\bin** ve 
**X:\\msys64\\usr\\bin** yollarını eklemeniz gereklidir. Eğer **MSYS2**
kurulumunu başka bir yere yaptı iseniz yolu değiştirmeniz gerekli.

.. image:: ../pictures/02_toolchain_01.png
   :align: center
