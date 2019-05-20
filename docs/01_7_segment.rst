********************************************************************************
7 Segment BCD
********************************************************************************

   İlk örnekte yeni başlayanlara kolaylık olması için 7 segment LED display
   BCD -> 7 Segment Decoder (örnek |4056_link|) entegre edilmiş direk BCD
   sürülebilen ekranlar seçtim.

1. 7 Segment Bağlantı 
================================================================================

   Aşağıdaki şemada ATmega328p mikrodenetleyicisine bağlanmış iki adet 7 segment
   LED display ve iki buton bulunmaktadır. Şema simulasyon için yeterli
   elemanlara sahiptir. 
   
   .. figure:: ../schematics/7_segment_01.PNG
      :align: center
      :alt: 7-Seeegment Şema
      :figclass: align-center
      
      7-Segment Şema

   |7_segment_link|.

   .. |4056_link| raw:: html
   
      <a href="https://www.st.com/resource/en/datasheet/cd00002658.pdf" 
      target="_blank">4056</a>

   .. |7_segment_link| raw:: html

      <a href="https://github.com/IBeRyUS/Gomulu_Sistemler/raw/13f76d1e08a89eb1ba80ff6f02cbc2153e7c5997/packed/7segment.7z"
      target="_blank">Buradan bu örneğe ait proje dosyasını indirebilirsiniz</a>


2. Kod 
================================================================================
   
   Yukarıdaki bağlantı şeması ile birlikte aşağıdaki örnekleri kullanabilirsiniz.
   
   .. toctree:: 
      :maxdepth: 1
         
      01_7_segment/sample_1






