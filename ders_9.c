/* 

Ders9

Standart C Library (Standart C Kütüphanesi)

Giriş - Çıkış İşlemleri

Output Stream
Input Stream

Standart Giriş Akımı
Standart Çıkış Akımı

Giriş Çıkış işlemleri aşağıdaki gibi iki farklı yapıda olabiliyor.

Formatlı Çıkış İşlemi
Formatsız Çıkış İşlemi

Bellekteki bitlerden ve bytelardan yola çıkarak, kullanılan sistemdeki karakter kodlamasına göre karakterlerin kod numarasını elde edeceğiz.
Bu maliyetli bir işlemdir, programın çalışma zamanında yapılacaktır.

Bellekte tutulan bir veriyi, insanın anlayacağı formatta, karakter kodlarına dönüştürerek dış dünyaya aktarmak, formatlı çıkış işlemidir.

Formatsız çıkış işlemi de, bellekteki bytelar ne ise, onları karakter kodlarına dönüştürmeden, olduğu gibi aktarılır. 
Örnek olarak iki cihazın haberleşmesi, insanın anlayacağı bir çıkışa gerek yoktur.

Giriş çıkış işlemlerini sağlayan standart C kütüphanesi
<stdio.h>

Formatlı çıkış işlemi sağlayan standart c kütüphanesi fonksiyonlarının sonunda F harfi vardır.

f: formatted

printf
fprintf
sprintf
snprintf

Format, formatlamak ne demek? Bir verinin formatlanması, o verinin insanın tercihlerine, istenilen şekline göre düzenlenmesidir.

Tam sayıların yazımında, hangi sayı sisteminde yazılacağı, sayı tabanın gösterilip gösterilmeyeceği, harf karakterlerinin büyük veya küçük yazılması, pozitif değerler için + karakteri yazılacak mı.
Bunların hepsi formatlama özelliğidir.

Yazma alanı genişliği
Output width

Doldurma karakteri
Fill character

Yazma Alanı Genişliği içerisindeki karakterlerin oryantasyonu, sağa dayalı, sola dayalı ya da internal biçimde oluşturabiliriz.

Internal (İşaretler ve Sayılar Alt Alta Geliyor)

+       567
-      2000

4564454 Doğukan Yazar
144 Soner Yazar
44 Ezgi Yazar
1123 Ticen Yazar

4564454 Doğukan Yazar
144.... Soner Yazar
44..... Ezgi Yazar
1123... Ticen Yazar

Gerçek sayıların yazdırılmasında da formatlama işlemleri kullanılır.
Noktadan sonra kaç basamak gösterilsin,
Nokta işareti gösterilsin mi,

Gerçek Sayıların Formatlanması

Fixed Notation      2323.56123  (10 üzeri çarpanı biçimde gösterilmiyor)
Scientific Notation 4.3         (10 üzeri çarpanı biçiminde ifade etmek)

C++'ın standart giriş çıkış işlemleri kütüphanesindeki yaklaşımı nesne yönelimli programlama yaklaşımı,
C'nin standart giriş çıkış işlemleri kütüphanesindeki yaklaşımı ise alt seviyeli bir yaklaşım söz konusu. 

Alt Seviye Avantajları:     ++Maliyet. Alt seviye, verimlilik, hakimiyet.
Alt Seviye Dezavantajları:  --Hata yapma riski çok yüksek.

----------------------------------------------------------------------------------------------------------

En sık kullanılan formatlı çıkış fonksiyonu: printf fonksiyonu

printf fonksiyonunun bildirimi <stdio.h> içerisindedir. 

int printf(const char *p, ...);

... -> ellipsis atomu

printf variadic bir fonksiyondur.

Variadic fonksiyona çağrı yapılırken uyulması gereken kural,

ellipsis ifadesi karşılığına dilediğimiz kadar parametre gönderebiliriz.

const char *p, 

bazı fonksiyonların parametre değişkenleri pointer, yani bu fonksiyonlar bizden adres istiyor. 

array (dizi)

int a[10];  

C dilinde diziyi bir fonksiyona göndermenin tek yolu call by reference. Diziler call by reference ile fonksiyonlara aktarılmalıdır.
Fonksiyonun parametre değişkeni pointer değişkeni olacak, biz de dizinin adresini göndereceğiz. Tek Yol: CALL BY REFERENCE

C dilinde bir fonksiyon, dizi üzerinden işlem yapmak için yazılmışsa en az bir tane parametresi pointer değişkeni olmak zorundadır. 
Bazı fonksiyonların parametre değişkenileri pointer ve bunlar bizden fonksiyona dizinin adresini göndermemizi istiyorlar.

Bir çok programlama dilinde yazılar, yazı türünü tutan değişkenler vardır.

string s = "arpeggio";

Fakat C dilinde yazılar char türünden dizilerde tutulur.

char str[100];

int printf(const char *p, ...);

printf fonksiyon bildirimindeki ilk parametrenin char *p türünden olması, bu parametrenin bizden bir char dizinin, bir yazının adresini istediği anlamına geliyor. 
Bu bir pointer parametre değişkeni.

const: pointer parametreler iki şekilde olabiliyor. 
ilkinde, o diziye bir değer göndermek veya o değeri değiştirmek.
ikincisinde ise o diziye salt okuma izni elde etmek.

void func(int *ptr);        //buradaki amaç nesneyi değiştirmek
void func(const int *ptr);  //buradaki amaç nesneyi değiştirmek değil

'B'
'A'
'B'
'A'
'\0' -> yazının bittiğini anlatan null ifadesi.

printf'in geri dönüş değeri tamamlayıcı bir bilgidir. standart output'a gönderilen karakter sayısıdır.

int val = printf("dogukan");

printf ile herhangi bir ifadenin değerini dilediğimiz formatlama özellikleriyle standart output'a yazdırabiliriz.

printf'in birinci parametresine gönderdiğimiz yazıda, % karakteri başlayan karakter başka bir anlama geliyor. escape sequence

printf'in formatlama notasyonu. 

convertion specifier
%d -> işaretli int türden bir değeri 10'luk sayı sisteminde ekrana yazdırma
%lf
%f
%i
%zu

printf("%d + %d + %d = %d", x, y, z, x + y + z);

gerçek sayı yazdırırken

for (int i = 0; i < 100; ++i)
{
    printf("%d sayisinin karekökü %f", i , sqrt(i));
}

*/

/*

#include <stdio.h>

void func(int, int, ...);

int main()
{
    func(11); // sentaks hatası, fonksiyon bildirimindeki parametre sayısı kadar argüman göndermeliyiz.
    func(11, 22);
    func(11, 22, 33);
    func(11, 22, 33, 44, 55, 66, 77, 88);
}

#include <stdio.h>

int main()
{
    char str[100];
    printf(str);
}

*/

/*
#include <stdio.h>

int main()
{
    int x, y;
    
    printf("2 sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d * %d + %d * %d = %d", x, x, y, y, x * x + y * y);
}
*/

/*

#include <stdio.h>

int main()
{
    int x;
    
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);

    printf("decimal: %d - octal: %o - hex: %x", x, x, x);
}

*/