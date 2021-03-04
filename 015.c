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
bir de öyle durumlar var ki, biz bilerek bir döngüden, döngünün kontrol ifadesinin yanlış olması nedeniyle döngüden çıksın istemiyoruz.

while (1) {

}

Döngüden zaten çıkılmayacak. Program açık kaldığı sürece bu döngünün gövdesindeki deyimler yapılacak.
Mesela embedded programlarının bir kısmı bu şekilde. Main fonksiyonları içinde böyle bir döngü deyimi var.

Döngüden başka bir yolla çıkmak.
Bir döngüden çıkış yolları:

i)   döngünün kontrol ifadesinin yanlış olması ile
ii)  break statement ile
iii) return statement ile
iv)  goto deyimi ile
v)   programın sonlanması

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

Bu tarz programlama dillerinde standart kütüphanenin programları sonlandıran fonksiyon ya da fonksiyonları oluyor.
exit
abort

27.00

*/

#include <stdio.h>

int main(){

}


