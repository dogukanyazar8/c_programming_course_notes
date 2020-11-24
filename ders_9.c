/* 

Ders9

Standart C Library (Standart C Kütüphanesi)

Giriş - Çıkış İşlemleri

Output Stream
Input Stream

Standart Giriş Akımı
Standart Çıkış Akımı

Formatlı Çıkış İşlemi
Formatsız Çıkış İşlemi 
Bellekteki byte'lar ne ise, onları karakter kodları dönüşümü uygulamadan olduğu gibi aktarılır.
(örnek olarak iki cihazın haberleşmesi)

Giriş çıkış işlemlerini sağlayan standart C kütüphanesi
stdio.h

printf
fprintf
sprintf
snprintf

Bir verinin formatlanması, istenilen şekilde düzenlenmesidir.

Yazma alanı genişliği
Output width

Doldurma karakteri
Fill character

Internal


+       567
-      2000

Gerçek Sayıların Formatlanması

Fixed       2323.56123
Scientific  4.3 

Noktadan sonra kaç basamak yazılsın gibi.

++Maliyet. Alt seviye, verimlilik, hakimiyet.
--Hata yapma riski çok yüksek.



int printf(const char *p, ...);

... -> elipsis atomu

printf variadic bir fonksiyondur.

Variadic fonksiyona çağrı yapılırken uyulması gereken kural,

elipsis ifadesi karşılığına dilediğimiz kadar parametre gönderebiliriz.

const char *p, 

bazı fonksiyonların parametre değişkenleri pointer, bu fonksiyonlar bizden adres istiyor. 

C dilinde yazılar char türünden dizilerde tutulur.

'\0' -> yazının bittiğini anlatan null ifadesi.

char str[100];

 */