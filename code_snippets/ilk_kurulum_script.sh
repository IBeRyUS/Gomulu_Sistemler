#!/bin/sh

#  Copyright 2019 Ibrahim USLAN(IBeRyUS) - mixer_opq@hotmail.com
#  
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#  
#     http://www.apache.org/licenses/LICENSE-2.0
#  
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

#  Msys2 platformunda kurulumlari yapar.
tool_path=/c/ARM/gcc-arm-none-eabi-7/bin/

pacman -S make cmake nano jsoncpp-devel p7zip mingw-w64-x86_64-gcc openssh vim --noconfirm --needed
cd /c
mkdir ARM
cd ARM
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-win32.zip
echo "Dosyalar cikartiliyor. Lutfen bekleyin..."
7z x gcc-arm-none-eabi-7-2018-q2-update-win32.zip -ogcc-arm-none-eabi-7 -aoa
rm gcc-arm-none-eabi-7*.zip
kontrol=$(cat ~/.bashrc | grep -ow $tool_path)
if [[ $kontrol == $tool_path ]]; then
   echo "PATH girdisi var."
else
   echo 'PATH=$PATH:'$tool_path >> ~/.bashrc
fi
echo "Kurulum tamamlandi. Lutfen Terminali tekrar baslatin." 
