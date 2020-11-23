/* 

Ders5

Global Namespace (Global İsim Alanı)
Local Namescape (Lokal İsim Alanı)

Global bütün değişkenler statik ömürlü olmak zorundadır.
Yerel değişkenler biz istersek statik veya otomatik ömürlü olabilirler.

void func(void)
{
    int x;          //automatic storage class
    static int y;   //static storage class
}

, (comma operator veya delimeter(ayıraç) olarak kullanılır)

aynı türden birden fazla değişken tanımlamak istenildiğinde

int x, y, z; //comma separated list

constant expression (sabit ifadesi)
Derleyici programın çalışma zamanında ifadenin değerini tam olarak hesaplayabiliyor.
C dilinin kurallarında bazı yerlerde sabit ifadesi kullanmak gerekiyor.

++statik ömürlü değişkenlere ilk değer veren ifadelerin sabit ifadesi olması gerekir.

int x = 0;
int y = x + 5; (bu bir sabit ifadesi değildir, x değişkendir.)

C dilinde statik ömürlü değişkenlere ilk değer veren ifadenin sabit ifadesi olması gerekir.
C++ dilinde statik ömürlü değişkenlere ilk değer veren ifadenin sabit ifadesi olmasına gerek yoktur.

C89 Standartlarında yerel düzeyde yapılan bildirimlerde bir deyimden sonra bir bildirim yapılamaz.
Aşağıdaki kod bloğu C89 standartlarına göre sentaks hatasıdır.

{
    int x = 10;
    ++x;
    int y = 5;

    veya 

    printf("dogukanyazar");
    int x = 10;
}

// C89 standartlarında bu açıklama satırı biçimi yoktu.

C99 Standartlarında ise kod bloğunun istediğimiz yerinde değişken bildirimi yapabiliriz.

Scope (Bilinirlik Alanı - Kapsam)

Her ismin bir kapsamı (scope) vardır.
Bir ismin kapsamı dışında kullanılması sentaks hatasıdır.
Tanımlanan isimlerin kapsamları dilin kurallarına göre belirlenir.

scope
name lookup

C'nin scope kategorileri.

file scope (dosya kapsamı) //en çok bizi ilgilendiren
block scope (blok kapsamı) //en çok bizi ilgilendiren

function prototype scope (işlev prototip kapsamı)
function scope (işlev kapsamı)

File Scope (dosya kapsamı)
Bir isim global kod alanında bildirilmişse, bu isim bildirildiği noktadan dosyanın sonuna kadar kullanılabilir.

Block Scope (blok kapsamı)

{
    int x = 10;
    //Bu ismi sadece ilgili bloğun sonuna kadar kullanabiliriz.
}

Bloklar iç içe olabilir. Nested block. Aynı kurallar geçerlidir.

İsim Arama Kuralları

Eğer bir isim, bir blok içerisinde kullanılmışsa önce kullanıldığı yerden kullanıldığı bloğun başına kadar olan kod alanında aranır.
Eğer bu alan bulunamaz ise, kapsayan bloğun başından içsel bloğun başladığı yere kadar aranır.
Eğer isim kapsayan blokların hiçbirinde bulunamazsa, global isim alanında dosyanın başından ismin kullanıldığı fonksiyonun tanımına kadar olan kod alanında aranır.


{   
    //2
    {   
        //1
        x;
    }
}

Aynı kapsamda isim birden fazla varlığa verilemez.
Ama farklı kapsamlarda bildirilen varlıkların isimleri aynı olabilir.
Örnek olarak global isim alanında birden farklı varlığa aynı isim verilemez.

Eğer iki ismin kapsamı aynı kapanış paranteziyle sonlanıyorsa, kapsamları aynıdır.
Eğer iki ismin kapsamı farklı kapanış paranteziyle sonlanıyorsa, kapsamları farklıdır.


int x = 10; //1

int main()
{
    int x = 20; //2

    if (x > 5) {
        int x = 30; //3
        
        if(x > 10){
            int x = 40; //4
        }
    }
}


NAME HIDING (İsmin Gizlenmesi)

int x = 10;

int main()
{
    int x = 45; //İlk önce burada aranır.
    
    printf("x = %d", x);
}

 */