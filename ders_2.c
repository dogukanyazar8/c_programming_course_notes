/* 

Ders2

Dosya
İkincil saklama ortamlarında ikilik sayı sisteminde tutulan verilerdir.

100001010000100010001010001010100 (File Format - Dosya Formatı)
En çok kullanılan metin formatı ASCII Text File'dır.

BABA
66 65 66 65 (4 byte'lık büyüklüğünde bir metin)

Bit (Binary Digit)

Translator: Programın amacı bir dilde yazılmış bir programı başka bir dile çevirmekse, çevirici (translator) olarak adlandırılır.
Compiler: Bu çevirme işleminde daha yüksek bir seviyeli dilden, düşük seviyeye çeviren program compiler (derleyici) olarak adlandırılır.

-----------------------------------------------------------------------
Source File (Kaynak dosyası - guitar_tuner.c veya arpeggio.cpp)

Preprocessor        (Önişlemci)
Translation Unit    (Çeviri Birimi)
Compiler            (Derleyici)
Assembly Code       (Makine Kodu)
Assembler           (Makine Kodu Çeviricisi)
Object Code         (Hedef Kod)
Linker              (Bağlayıcı)
Executable Code     (Çalıştırılabilir Kod)
-----------------------------------------------------------------------

Preprocessing Time (Önişlemci Zamanı)
Compile Time (Derleme Zamanı)
Link Time (Bağlama Zamanı)
Run Time (Çalışma Zamanı)


Bulgu İletisi

Diagnastic (Message) (Dilin kuralları ihlal edildiğinde derleyicinin ürettiği hata mesajlarıdır. Derleyici bazen kodu derleyip, warning mesajı verebilir.)
    Error Message (%99)
    Warning Message

Syntax Error (Sentaks Hatası)
ill-formed code well-formed code
illegal code    legal code (perfectly legal)
invalid code    valid code

Geçersiz Kod
Yanlış Kod
Kötü Kod

Derleyici sentaks kontrolÜ, lojik kontrol ve optimizasyon yapar.

Warning (Lojik Uyarı Mesajları)
Derleyici bazı durumlarda, dilin kuralları çiğnememiş olsa bilse, bir kodu yanlışlıkla yazdığımızı düşünerek bizi uyarıyor. %95 Haklıdır.

Compiler Switches
Derleyicinin uyarı ayarlarını değiştirip lojik kontrolleri sıkılaştırıp, gevşetebiliriz. (Warning Level)

Optimizing Compilers
Derleyiciler kodu derlerken düzenleyerek, en iyi hâle getirirler. Optimize ederler.

Döngüler, programın en çok zaman kaybettiği yerlerden birisidir. Derleyici yazdığımız döngüleri düzenleyip, optimize ederler.
Loop Reversal
Loop Unrolling
Death-code Elimination

İkilik Sayı Sistemi

Integers            (Tam Sayılar)
    Unsigned        (İşaretsiz - Negatif tam sayılar mevcut değil.)
    Signed          (İşaretli - Hem pozitif hem negatif tam sayılar mevcut.)
Floating Numbers    (Gerçek Sayılar)

Bit (Binary Digit)
Byte = 8 Bit

Most Significant Bit    (En Yüksek Anlamlı Bit)
Least Significant Bit   (En Düşük Anlamlı Bit)

1 Byte  255
2 Byte  65.635
4 Byte  4.294.967.295
8 Byte  18.446.744.073.709.551.615

One's Complement (Bire Tümleme)
Two's Complement (İkiye Tümleme)

0101 1100
1111 1111
0010 1000
0001 0000

Negatif bir tam sayının değerini almak için o sayının ikiye tümleyini alınır.

*/