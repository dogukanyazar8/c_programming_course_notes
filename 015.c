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

//eğer daha anlamlı bir isim mevcut değilse, değişkenin tek varlık nedeni fonksiyonun geri dönüş değerini oluşturmak ise, bu isimleri kullanabiliriz.
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
Project -> project_name Properties -> Code Analysis -> Enable Microsoft Code Analysis

*/

#include <stdio.h>

int main(){

}


