/*

Ders16

Aşağıdaki programda
ya bir karakter değiştirilecek
ya da bir karakter eklenecek
ekranda 5 kere necati çıktısı olucak.

int main()
{
    int n = 5;

    for (int i = 0; i < n; i--)
        printf("necati\n");
}

---------------------------------------------------------------

1 - Döngünün her turunda n'nin değerini azaltıyoruz. n'nin değeri 0 olduğunda döngü sonlanıyor. 

int main()
{
    int n = 5;

    for (int i = 0; i < n; n--)
        printf("necati\n");
}

---------------------------------------------------------------

2 - Döngünün her turunda i'nin işaretini değiştiriyoruz, i'nin değeri -1 ise, +1 oluyor. i'nin değeri 5 olduğunda döngü sonlanıyor.

#include <stdio.h>

int main()
{
    int n = 5;

    for (int i = 0; -i < n; i--)
        printf("necati\n");
}

---------------------------------------------------------------

3 - Döngünün her turunda i ile n değerlerini topluyoruz. i'nin değeri -5 olduğunda i + n = 0 oluyor ve döngü sonlanıyor.

#include <stdio.h>

int main()
{
    int n = 5;

    for (int i = 0; i + n; i--)
        printf("necati\n");
}

---------------------------------------------------------------
0 ve 1 asal sayı değil.

Döngüyü x'ye kadar değil de, yarısına kadar yapabiliriz.
Eğer bir sayının yarısına kadar böleni yoksa, böleni yoktur.

Matematiğe göre, sayının kareköküne kadar gitsek yeterlidir.

#include <stdio.h>

int isprime(int x){

    if (x < 2)      //sayı 2'den küçük mü kontrolü.
        return 0;
    
    if (x % 2 == 0)
        return x == 2; // bu ifadenin değeri, x'in değeri 2 ise, evet asal anlamında 1 değerini döndürüyorum.
                       // eğer x'in değeri 2 değil ise, 0 değerini döndürüyorum.

    if (x % 3 == 0)
        return x == 2; // bu ifadenin değeri, x'in değeri 3 ise, evet asal anlamında 1 değerini döndürüyorum.
                       // eğer x'in değeri 3 değil ise, 0 değerini döndürüyorum.
    if (x % 5 == 0)
        return x == 2; // bu ifadenin değeri x'in değeri 5 ise, evet asal anlamında 1 değerini döndürüyorum.
                       // eğer x'in değeri 5 değil ise, 0 değerini döndürüyorum.

    for (int i = 7; i * i <= x; i += 2){
        if (x % i == 0)
            return 0;
    }
        
    return 1;
}

int main()
{
    int low, high;

    printf("Bir aralik girin: [low] [high] ");
    scanf("%d%d", &low, &high);

    for (int i = low; i <= high; ++i){
        if (isprime(i)){
            printf("%d ", i);
        }
    }
}

---------------------------------------------------------------
ÖDEV

Armstrong sayıları

Örneğin üç basamaklı sayılar için;

abc = a3 + b3 + c3
abcd = a4 + b4 + c4 + d4

Bütün armstrong sayılarını ekrana yazdıracak program. Mümkün olan en kısa sürede bunu yapacak.

0 ile 999'999'999.

---------------------------------------------------------------

perfect number

Mükemmel sayı, bölenlerinin toplamı kendisine eşit olacak. Kendisi hariç, 1 dahil, bölenlerinin toplamı.

6 -> 1 + 2 + 3 

28 -> 1 + 2 + 4 + 7 + 14

#include <stdio.h>

int is_perfect(int val){ //bu fonksiyonun varlık nedeni sadece perfect sayı olup olmadığı bilgisini iletmek.

    int div_sum = 0;

    for (int i = 1; i <= val / 2; ++i){// i <= val yapmadık çünkü yarısına kadar böleni var, yarısından sonrası için böleni olmadığı kesin.
        if (val % i == 0)
            div_sum += i;
    }

    return val == div_sum; //burada kesinlikle return 0 veya return 1 için if deyimini kullanmaya gerek yoktur. kötü kod kullanımı.
                            //zaten karşılaştırma operatörleri 0 veya 1 değerlerini dönüyor.
}

int main()
{
    for (int i = 1; i < 10000; ++i)
        if(is_perfect(i))
            printf("%d is perfect!\n", i);
}

---------------------------------------------------------------

ÖDEV - En fazla terimi bulan programı yazınız. 

n bir tam sayı olmak üzere, 
n çift ise , serinin yeni terimi n /2
n tek ise, 3 * n + 1 olacak. 

Ve bu seri, 8 - 4 - 2 - 1 ile sonlanır.

#include <stdio.h>

void print_u(int val)
{
    while (1){
        printf("%d ", val);
        if (val == 1)
            break;
        if (val % 2 == 0)
            val /= 2;
        else
            val = val * 3 + 1;
    }

    printf("\n");
}

int main()
{
    print_u(45223234);
}

---------------------------------------------------------------

C dilinde sonsuz döngü idiomunun 2 tane popüler yazım biçimi var.
İkisi arasında hiçbir fark yok. Tamamen programcının kendi kişisel tercihi, seçimi.

while (1)

for (;;)

for (;;) // lojik 1 sabiti yazılmış kabul ediliyor. for (;1;)

Ana akım programlama dillerinde, java c# gibi dillerde while (1) geçerli değil.
Çünkü bu tarz dillerde lojik ifade beklenen yerlerde boolean türden ifade yazmak gerekiyor.

1, o dillerde boolean türünden değil. C dilinde böyle bir kısıtlama yok. Doğrudan 1 yazabiliyoruz.

Java, C# gibi dillerde sentaks hatası olur.

for (;;) {

}

İç İçe Döngüler

Bir çok algoritmaların implementasyonunda bir döngü deyiminin içinde, ikinci bir, belki üçüncü bir döngü deyimi yazmamız gerekiyor.
Bu bazen iç içe iki, üç veya dört döngü olabilir.

nested loops.

döngü {

    döngü {

    }
}

---------------------------------------------------------------

int main(){

    for (int i = 0; i < 10; ++i) { //Bu döngü 10 kez dönecek. Döngünün gövdesinde deyimler 10 kez yapılacak.
        for (int j = 0; j < 10; ++j) { //Dıştaki döngünün her turunda, bu döngü deyimi 1 kez yürütülecek.

        }
    }

    for (int i = 0; i < 10; ++i) { //Bu döngü 10 kez dönecek. Döngünün gövdesinde deyimler 10 kez yapılacak.
        for (int j = 0; j < 20; ++j) { //İçteki döngü 20 kez döndüğüne göre, dıştaki döngünün her turunda bu döngü deyimi 1 kez yürütüldüğüne göre, içteki döngünün gövdesindeki deyimler bu döngünun dönüş sayısı çarpı dıştaki döngünün dönüş sayısı kadar yapılacak.
            printf("%d %d\n", i, j); //Döngünün ilk turunda, i = 0, j = 0. döngünün son turunda i = 9, j = 19
        }
    }
}

---------------------------------------------------------------

Teknik mülakatlarda sınav yapılan siteler var. Bunlardan en meşhuru codility isimli site.

Orada sorulan sorulardan biri;

Bu program çalıştırıldığında, ekrana ne yazılır.

int main()
{
    int i, k;

    for (i = 0; i < 5; ++i)
        for (k = 0; k < 7; ++k);
            printf("(%d %d)", i, k);
}

Cevap: 5 ve 7 yazar.

Çünkü;

int main(){

    int i, k;

    for (i = 0; i < 5; ++i)
        for (k = 0; k < 7; ++k)
            ; //null statement, boş deyim var. 

    //döngü sonlanınca i = 5, k = 7

    printf("%d %d", i, k);
}

---------------------------------------------------------------

#include <stdio.h>

int main(){

    int cnt = 0;

    for (int i = 0; i < 10; ++i) {      //döngülerin dönüş sayısı, dıştaki döngü * içteki döngü = 10 * 20 * 30 = 6000
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 30; ++k){
                ++cnt;
            }
        }
    }

    printf("cnt = %d", cnt);
}

---------------------------------------------------------------

Armstrong sayıları

153
370
371
407 = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407

int main(){

    int x = 100;

    //Bu döngüde, 100'den başlayarak bütün 3 basamaklı sayıları yazdırmış oluyoruz.
    //En içteki döngünün her turunda, i yüzler basamağı, j onlar basamağı, k birler basamağı.
    //Bu şekilde bir sayının basamak değerlerinin kübünün toplamı, sayının kendisine eşit mi değil mi öğrenebiliyoruz.
    
    for (int i = 1; i < 10; ++i){
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k){
                if (x == i * i * i + j * j * j + k * k * k)
                    printf("%d\n", x);
                ++x;
            }
        }
    }
}

---------------------------------------------------------------

Bazı iç içe döngü senaryonlarında, bazı durumda içteki döngü, dıştaki döngünün, döngü değişkeni değeri kadar dönsün isteniliyor.

Girdiğimiz tam sayı = 5

*
**
***
****
*****

Dıştaki döngü ile bu satırları oluşturabiliriz, içteki döngüyle de buradaki yıldızları ekrana basabiliriz.

int main(){
    
    int n;
    printf("Bir tam sayi girin: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < i; ++k) {
            putchar('*');
        }
        putchar('\n');
    }
}

---------------------------------------------------------------

Diziler konusunda çok daha fazla döngü kullanımı yapacağız.

Acaba döngüden break deyimi ile mi çıktık yoksa for döngüsünün koşulu sağlanmadığı için mi çıktı?
Yani döngüden break ile mi çıktık yoksa break olmadan mı çıktık.

Bu durumun iki tane tipik çözümü var. 

Bir tanesi bayrak değişkenler. Bütün döngülere uygulayabiliriz. Boolean türünden değişkenler.
Bize bu tür durumlarda yardımcı oluyor. flag

Eğer hiçbir kod bu flag değişkeninin değerini değiştirmezse, flag değişkeninin değeri false olacak.

int main()
{
    bool flag = false;

    for (int i = 0; i < 1000; ++i) {
        ////
        if (expr) {
            flag = true;
            break;
        }
        ////
    }

    if (flag) //döngüden break ile mi çıktık yoksa break olmadan mı çıktık.
}

Bu tür for döngülerinde bu kontrolü yapabilmek için bir olanak daha var.
O da döngü değişkeninin kendisini kullanmak.

int main()
{
    int i;

    for (i = 0; i < 1000; ++i) {
        ////
        if (expr) {
            break;
        }
        ////
    }

    if (i < 1000) //aynı koşulu tekrar sınıyoruz. döngüden break ile mi çıktık yoksa break olmadan mı çıktık.
}

---------------------------------------------------------------

Veri yapıları üstünde çok sıkça uygulanan algoritmalardan bir tanesinin ismi: linear search.
Yani bir veri yapısında bir değeri aramak.

Bayrak değişkeni kullanarak yazdığımız program

int main(){

    int a[10] = {2, 5, 7, 8, 1, 9, 12, 56, 21, 56};
    int ival;
    int flag = 0;

    printf("Bir tam sayi girin: ");
    scanf("%d", &ival);

    for (int i = 0; i < 10; ++i) {
        if (a[i] == ival) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("evet dizide mevcut\n");
    }
    else {
        printf("hayir dizide mevcut degil\n");
    }
}

---------------------------------------------------------------

Döngü değişkeninin kendisini kullanarak yazdığımız program

int main(){

    int a[10] = {2, 5, 7, 8, 1, 9, 12, 56, 21, 56};
    int ival;
    int i;

    printf("Bir tam sayi girin: ");
    scanf("%d", &ival);

    for (i = 0; i < 10; ++i) {
        if (a[i] == ival) {
            break;
        }
    }

    if (i < 10) {
        printf("evet dizide mevcut\n");
    }
    else {
        printf("hayir dizide mevcut degil\n");
    }
}

01.03.00

*/

#include <stdio.h>

int main(){
}
