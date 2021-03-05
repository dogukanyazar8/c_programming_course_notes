/*

Ders15

While Döngü Deyimi

While parantezi içerisindeki ifade, doğru olduğu sürece döngü gövdesindeki deyimin yapılmasını sağlıyordu.

--------------------------------------------------------------------------

n kez dönen, C idiomu.

Burada, bir döngü oluşturucaz ve bu döngünün kaç kez dönmesi gerektiği belli.

    int n;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &n);

    while (n-- > 0){ // son ek -- operatörünün ürettiği değer, nesnenin kendi değeri. while (n--) yazsaydık da sonuç aynı olurdu. n = 0 olduğunda lojik yorumlamaya tabii tutulduğunda, döngüden çıkılacaktı.
        printf("Dogukan Yazar\n");
    }

--------------------------------------------------------------------------

    int n;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &n);

    while (n --> 0){ // programcıları kandırmak için --> böyle bir operatör varmış gibi gösteriyorlar. Aslında böyle bir operatör yok, ifade bu şekilde: n-- > 0
                    // derleyici kaynak kodu atomlarına ayırırken maximum munch kuralını uyguluyor ve olabilecek en uzun atomu seçiyor.
        printf("Dogukan Yazar\n");
    }

--------------------------------------------------------------------------

#include <stdio.h>

//eğer daha anlamlı bir isim mevcut değilse, değişkenin tek varlık nedeni fonksiyonun geri dönüş değerini tutmak ise, bu isimleri kullanabiliriz.
// result - ret
int power(int base, int exp){

    int result = 1;

    while (exp--){ //Döngü deyimini gövdesi sadece bir deyimden oluşuyorsa, bu deyimini bloklamak veya bloklamamak arasında bir fark yok.
        result *= base;
    }

    return result;
}

int main(){
    int x, y;
    printf("Iki tam sayi giriniz: "); // 3 ve 3
    scanf("%d%d", &x, &y);

    printf("%d ==> %d = %d\n", x, y, power(x, y));
}

--------------------------------------------------------------------------

Microsoft Visual Studio IDEsini kullanıyorsak, 
Project -> project_name Properties -> Code Analysis -> Enable Microsoft Code Analysis [NO] 
scanf gibi fonksiyonlarda uyarı vermemesi için.

--------------------------------------------------------------------------

sonsuz döngü - infinite loop

sonsuz döngü terimi iki ayrı anlamda kullanılabiliyor.
birincisi bir kodlama hatasını işaretlemek için kullanılıyor.

int main(){
    int low, high;
    int n;
    int i;

    printf("Bir aralik girin: [low high]: ");
    scanf("%d%d", &low, &high);
    printf("Kaca tam bolunenler yazilsin: ");
    scanf("%d", &n);

    i = low;

    while (i < high){
        if (i % n == 0) {
            printf("%d", i);
            ++i;    //programcı burada i'nin arttırılma yerini yanlış yere yazmış.
        }           //burada sonsuz bir döngü var.
    }
}

//sonsuz döngü idiomu
bir de öyle durumlar var ki, biz bilerek bir döngüden, döngünün kontrol ifadesinin yanlış olması nedeniyle döngüden çıkılsın istemiyoruz.

while (1) {

}

Döngüden zaten çıkılmayacak. Program açık kaldığı sürece bu döngünün gövdesindeki deyimler yapılacak.
Mesela embedded programlarının bir kısmı bu şekilde. Main fonksiyonları içinde böyle bir döngü deyimi var.

Bu tarz programlama dillerinde standart kütüphanenin programları sonlandıran fonksiyon ya da fonksiyonları oluyor.
exit
abort

Döngüden başka bir yolla çıkmak.
Bir döngüden çıkış yolları:

i)   döngünün kontrol ifadesinin yanlış olması ile
ii)  break statement ile
iii) return statement ile
iv)  goto deyimi ile (goto deyiminin zaten varlık nedeni programın akışını koşulsuz belirli bir noktaya yönlendirmek. döngünün içinden döngünün dışındaki bir noktaya)
v)   programın sonlanması (exit - abort -> bir fonksiyon çağrısı ile programın sonlandırılmasını sağlayıp, döngüden çıkabiliriz.)

while (expr) {
    //statement
    //statement
    if (c_ex)
        return 1;
    //statement
    //statement

while (expr) {
    //statement
    //statement
    if (c_ex)
        break;
    //statement
    //statement
}

while (expr) {
    //statement
    //statement
    if (c_ex)
        exit(EXIT_FAILURE);
    //statement
    //statement
}

while döngü deyimi oluştururken döngünün kontrol ifadesini hemen yazmak istemek.
a) bu döngünün başında belli olmayabilir. dinamik olarak döngünün gövdesinde belirli oluyor olabilir.
b) evet böyle bir ifade yazılabilir ama böyle bir ifadeyi yazmak görece olarak zor olabilir.

Ama biz döngünün gövdesinde diğer yollardan biriyle döngüden çıkabiliriz.

while (1) { //sonsuz döngü deyimi

    if(????)
}

--------------------------------------------------------------------------

Break Statement - Break Deyimi

Break deyimi sentaks açısından C'nin en basit deyimlerinden biri.
break bir anahtar sözcük. ve bu anahtar sözcüğü doğrudan sonlandırıcı atomu izliyor ve bu break deyimi oluyor.
break;

Break deyiminin geçerli olabilmesi için:

a) bir döngü deyiminin gövdesinde,
b) bir switch deyiminin gövdesinde,

Eğer bu noktalardan birinde değilse, sentaks hatasıdır.

Break deyiminin yürütülmesi programın akışını döngüden sonraki ilk deyime yönlendiriyor.

while (expr) {
    statement;
    statement;
    statement;
    statement;
    if (c_exp)  //eğer programın akışında, if ifadesi doğru olursa, break deyimi çalışır ve programın akışı döngüden sonraki ilk deyime yönlendirilir.
        break;
    statement;
    statement;
}
    statement_after_loop;

Bu döngüden, hangi noktada çıkmak istiyorsak, 

while (1) {
    if (!c_exp)  
        break;
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
}
    statement_after_loop;

Yukarıdaki döngü deyimi ile aşağıdaki döngü deyiminin hiçbir farkı yoktur.

while (c_exp) {
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
}
    statement_after_loop;


Örnek, aşağıdaki döngünün gövdesinde, if deyimindeki koşul ifadesi doğru olduğu sürece bu döngüdeki deyimler yapılacak.

while (1) {
    statement;
    statement;
    statement;
    statement;
    statement;
    statement;
    if (!c_exp)
        break;
}

Bu da aslında do-while döngü deyiminin bir örneği. Döngünün koşul ifadesi döngünün başında kontrol edilmiyor, döngünün sonunda kontrol ediliyor.

Döngüyü kontrol eden ifade döngünün başındaysa, bu normal while döngüsü.
Döngüyü kontrol eden ifade döngünün sonundaysa, bu do while döngüsü.

Bu IF - BREAK yapısı döngünün içerisinde sadece bir noktada değil, birden fazla noktada da kullanılabilir.

--------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int c;
    int ival;
    int cnt = 0;
    int sum = 0;
    int min, max;

    while (1) {
        printf("Tam sayi girecek misiniz [e] [h] : ");
        while ((c = getch()) != 'e' && c != 'h') //atama operatörünün ürettiği değer nesneye atanan değerdir. ayrıca kısa devre davranışı var. burada girişi e ve h tuşlarına kitledik.
        ;                                        //null statement - döngünün gövdesinde bir şey yapılmayacak.
        printf("%c\n", c);
        if (c == 'h')
            break;
        printf("Tam sayiyi giriniz: ");
        //scanf("%d", &ival);
        ival = (rand() % 2 ? 1 : -1) * rand();
        sum += ival;
        if(cnt == 0)
            min = max = ival;
        else if (ival > max)
            max = ival;
        else if (ival < min)
            min = ival;

        ++cnt;
        printf("%d\n [Giris Sayisi: %d]", ival, cnt);
    }

    if (cnt != 0){
        printf("Toplam %d sayi girdiniz.\n", cnt);
        printf("Ortalama = %f\n", (double)sum/cnt); //(double) tür dönüştürme operatörü. derleyic sum değişkenini double olarak işleme sokacak. 
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }
    else {
        printf("Hic sayi girmediniz.\n");
    }
}

--------------------------------------------------------------------------

 

*/

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int c;
    int ival;
    int cnt = 0;
    int sum = 0;
    int max = INT_MIN; //Ön işlemci komutlarını kullanarak, max değişkenine olabilecek en küçük değeri verdik. makro konusuyla ilgili.
    int min = INT_MAX; //Ön işlemci komutlarını kullanarak, max değişkenine olabilecek en büyük değeri verdik. makro konusuyla ilgili.

    while (1) {
        printf("Tam sayi girecek misiniz [e] [h] : ");
        while ((c = getch()) != 'e' && c != 'h') //atama operatörünün ürettiği değer nesneye atanan değerdir. ayrıca kısa devre davranışı var. burada girişi e ve h tuşlarına kitledik.
        ;                                        //null statement - döngünün gövdesinde bir şey yapılmayacak.
        printf("%c\n", c);
        if (c == 'h')
            break;
        printf("Tam sayiyi giriniz: ");
        //scanf("%d", &ival);
        ival = (rand() % 2 ? 1 : -1) * rand();

        if(cnt == 0)
            min = max = ival;
        else if (ival > max)
            max = ival;
        else if (ival < min)
            min = ival;

        sum += ival;
        ++cnt;

        printf("%d\n [Giris Sayisi: %d]", ival, cnt);
    }

    if (cnt != 0){
        printf("Toplam %d sayi girdiniz.\n", cnt);
        printf("Ortalama = %f\n", (double)sum/cnt); //(double) tür dönüştürme operatörü. derleyic sum değişkenini double olarak işleme sokacak. 
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }
    else {
        printf("Hic sayi girmediniz.\n");
    }
}


