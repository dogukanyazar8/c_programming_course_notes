/*

Ders13

If kontrol deyiminin doğru kısmındaki deyim bir boş deyim olabilir, 
bir ifade deyimi olabilir, başka bir kontrol deyimi olabilir, ya da bloklanmış bir bileşik deyim olabilir.

if (x != 0)
if (x)

Diğer dillerde bu şekilde kullanmak sorun olabilir fakat 
C dilinde bu iki koşul deyimi arasında bir fark yoktur.

if (x == 0)
if (!x)

if(isupper(c) != 0)
if(isupper(c))

if(isupper(c) == 0)
if(!isupper(c))

---------------------------------------------------------------------------------------

Çok sık kullanılan bir C idiyomu. If koşun parantezinin içinde ilk önce x'e atama yapılmış,
atama operatörünün ürettiği değer nesnenin değeri, ardından karşılaştırılma yapılmış.

x = func();
if (x == -1) {

}

if ((x = func()) == -1)

---------------------------------------------------------------------------------------

If parantezi içinde atama operatörüyle oluşturulmuş bir ifade.

    FILE* f;
    if((f = fopen("dogukan.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file\n");
        return 1;
    }

---------------------------------------------------------------------------------------

if((c = getchar()) != '\n) {} -> Atama operatörünün ürettiği değerden faylanan if deyimi

if(c = getchar(), c != '\n') {} -> Virgül operatörü kullanılan if deyimi (yan etki oluşturuluyor)

Yukarıdaki iki if deyimi de pratikte aynı. Her ikisinin de yaptığı iş aynı.

---------------------------------------------------------------------------------------

Yanlış kısmı olan if deyimi

Buradaki amaç koşul doğruysa bir iş, koşul yanlışsa başka bir iş.

if (expr)
    statement_1;
else
    statement_2;

---------------------------------------------------------------------------------------

    int age;
    printf("Yasinizi giriniz: ");
    scanf("%d", &age);

    if (age >= 18){
        printf("Evet giris yapabilirsiniz.\n");
    }
    else{
        printf("Bu mekana girmek icin 18 yasinizi doldurmus olmalisiniz.\n");
    }

---------------------------------------------------------------------------------------

if (10 < x < 20) {} -> Bu if koşul parantezi always true. 

if (x > 10 && x < 20)

if (x = 10)     //karşılaştırma operatörü yerine atama operatörünü kullandık. 
                //atama operatörünün ürettiği değer nesneye atanan değer olduğu için, lojik yorumlandığında true olacak.
    dothis();

Böyle durumlarda, eskiden beri kullanılan idiyomatik yapı, sağ taraf değeri olan ifadeyi karşılaştırma operatörnün sol operandı yapıyorduk.

if (10 == x)
    dothis();

Lojik hata ya da çalışma zamanı hatası olacağına sentaks hatası olsun!

if (x = 0)      //atama operatörünün ürettiği değer nesneye atanan değer olduğu için, lojik yorumlandığında false olacak.
    dothis();

if (exp1 & exp2) //lojik ve operatörü yerine bitsel ve operatörünü yanlışlıkla kullanmak. dikkat edilmesi gerekir.

if (exp1 | exp2) //lojik veya operatörü yerine bitsel veya operatörünü yanlışlıkla kullanmak. dikkat edilmesi gerekir.

if (dval > 7,5) //gerçek sayı sabitini ifade eden . yerine , yazmak. Virgül operatörünün ürettiği değer sağ operandın değeridir. Lojik yorumlamaya tabi tutulduğunda, always true olacak.
    dothis();

if (dval > 7,0) //always false. 
    dothis();


---------------------------------------------------------------------------------------

int func(void)
{
    printf("func cagrildi!\n");
    return 0; // return 1; olsaydı, if'in doğru kısmına girecekti programın akışı.
}

int main(){

    if(func()) { //fonksiyon çağrı ifadesinin değeri, fonksiyonun geri dönüş değeri. burada geri dönüş değeri 0. bu yüzden lojik yorumlamaya tabi tutuldu ve if'in yanlış kısmına girdi.
        printf("evet evet evet\n");
    }
    else {
        printf("hayir hayir hayir\n");
    } 
}

---------------------------------------------------------------------------------------

int func(void)
{
    printf("func cagrildi!\n");
    return 0; // 
}

int main(){

    if(func) { //programcı fonksiyon çağrı operatörünü yazmayı unutmuş. () Bu kod sentaks hatası değil. Çalıştırdığımızda if'in doğru kısmına girecek. Always true.
        printf("evet evet evet\n");
    }
    else {
        printf("hayir hayir hayir\n");
    } 
}

Fonksiyon ismi, dilin kurallarına göre bir ifade içinde kullanıldığında, bu fonksiyonun adresine dönüştürülecek
ve fonksiyon adresi lojik yorumlamaya tabi tutulduğunda, lojik doğru olarak yorumlanacak.

Yani biz istemeden fonksiyonun çağrılmamasına yol açtık. Hem de bu ifade artık always true oldu.

regex - regular expression

Kodlama editörlerinin hepsi regex ile arama yapmaya izin verir.
if parantezinden sonra noktalı virgül olup olmadığını kontrol edebiliriz, sınayabiliriz.

---------------------------------------------------------------------------------------
x 10'a ya da 23'e eşit değilse, func fonskiyonunu çağır.

if (x != 10 || x != 23) always true. dilin kullanımında "veya" "ya da" geçtiği için ifade yanlış kurulmuş.
    func();
---------------------------------------------------------------------------------------

Bu iki ifadenin denkliğini sağlayan lojik ve operatörünün kısa devre davranışıdır.

if (x > 10)
    if (y < 30)
        ++m;

if (x > 10 && y < 30) // x > 10 ifadesi yanlışsa, diğer sınama yapılmayacak.
    ++m;
---------------------------------------------------------------------------------------

if kontrol deyiminin doğru kısmı mutlaka olmak zorundadır.

Eğer gerçekten if'in doğru kısmında bir şey yapılmasını istemiyorsak bunu yapmanın iki yolu var.

Kötü yol:

if (x > 10)
    ;
else
    ++m;

İyi yol:

if(!(x > 10))

if (x <= 10)
    ++m;

Her türlü aşağıdaki kullanım türünden kaçınmalıyz.

//Kötü yol
if (exp)
    ;
else
    dothis();

//İyi yol
if(!exp)
    dothis();

---------------------------------------------------------------------------------------

dangling else - her iki if deyimine de aitmiş gibi duran else deyimi. bu tür durumlarda else, içteki if'in else'dir.

if (x > 10)
    if (y > 20)
        ++m;
else
    --z;

---------------------------------------------------------------------------------------

Gereksiz if deyimi kullanımı. Derleyici optimizasyonu düzgün yapmazsa verimlilik sorunu olur.

if (x == 10) //eğer x'in değeri 10 ise, alttaki if'lerin doğru sonuçlanması ihtimali yok. birbirinden bağımsız if'ler. 
    func1();

if (x == 20)
    func2();

if (x == 30)
    func3();

if (x == 40)
    func4();

Else if merdiveni:

if (x == 10)
    func1();

else if (x == 20)
    func2();

else if (x == 30)
    func3();

else if (x == 40)
    func4();

else if merdiveni kullanmamız gereken yerde ayrık if deyimleri yazmamamız lazım.

a) kodun okunmasını zorlaştırabiliriz.
b) kodu okuyanı yanıltabiliriz.
c) derleyicinin bir optimazyon yapmaması durumunda daha verimsiz bir kod oluşmasına yol açabiliriz.
d) ilerde öğreneceğimiz switch deyiminin bariz kullanabileceği yerlerde, else if merdiveni yerine switch deyimini kullanmalıyız.
    i) kodun okunmasını kolaylaştırırız
    ii) duruma göre else if merdivenine göre derleyici switch deyimi için daha etkin bir kod oluşturabilir.

Bir else if merdiveninde, en sonda else deyiminin olup olmaması kodun anlamını tamamen değiştiriyor. Hayati bir önem taşıyor.
Eğer else if merdiveninin son basamağında else yok ise, bu merdivenden hiçbir şey yapılmadan çıkılabilir.

if (x == 10)
    func1();

else if (x == 20)
    func2();

else if (x == 30)
    func3();

else if (x == 40)
    func4();
else
    dothis();

---------------------------------------------------------------------------------------

Else if merdiveninde oluşma sıklığı ya da olasılığı yüksek olan durumları başa yazmalıyız.
Aynı şey switch deyimi için de geçerlidir.

Örnek olarak, bu fonksiyon daha çok aralık ayı için çağrılıyor diyelim.
Bu yüzden oluşma olasalığı daha yüksek olan koşulları başa taşımalıyız.

Switch deyiminde de bu koşulun karşılığı default case.

void func(int m)

if (m == 1)

if (m == 2)

if (m == 12)

---------------------------------------------------------------------------------------

if (++x > 10) //if parantezi, bir sequence point oluşturuyor. yan etki noktası.

bu koşuldan sonra ister doğru kısmına girsin, ister yanlış kısmına girsin, x'i ilk kullandığım yerde x'in artmış değerini kullanacağımın garantisi var.

---------------------------------------------------------------------------------------

redundant else

Öyle yerler var ki, else anahtar sözcüğünü koymamız gerekiyor ama contexte baktığımızda else anahtar sözcüğünü koymakla koymamak arasında bir fark yok.
Bu tamamen kişisel bir seçim. Else olsa da, olmasa da bir anlam farkı yok.

int getabs(int x){
    if (x >= 0)
        return x;
    else //buradaki else olsa da, olmasa da, kodun anlamında bir değişiklik yok.
        return -x;
}

while (expr){
    statement1;
    statement2;
    if (c_ex)
        break;
    else { //buradaki else hiç olmasaydı, kodun anlamında hiçbir değişiklik olmayacaktı.
        statement3;
        statement4;
        statement5;
    }
}

while (expr){
    statement1;
    statement2;
    if (c_ex)
        continue;
    else { //buradaki else hiç olmasaydı, kodun anlamında hiçbir değişiklik olmayacaktı.
        statement3;
        statement4;
        statement5;
    }
}

---------------------------------------------------------------------------------------

if (x != 0)
    y = x;
else
    y = 0;

Bu kod, y = x anlamına geliyor. Gereksiz if deyimi kullanımı.

x'in değeri 0'a eşit olmadığı zaman, y değişkenine x'in değeri atanacak.
aksi hâlde, y değişkenine 0 değeri atanacak.

Zaten x'in değeri 0 olsa, y değişkenine 0 atanacak.

Yani her koşulda x'in değeri y'ye atanacak.

Sentaks hatalarından korkmaya gerek yok, sentaks hatası bizim en büyük dostumuz.
Önemli olan lojik hatalar, tanımsız davranışlar.

else bir if'e ait olmalı.
if'i olmayan bir else her zaman sentaks hatasıdır.

if (x > 10); //buraya yanlışlıkla noktalı virgül atomunu koyarsak, if deyiminin else ile ilişkisi kesilir ve sentaks hatası alırız.
    bunuyap();
else
    sunuyap();

---------------------------------------------------------------------------------------
Başlangıç seviyesinde olan programcıların yaptıkları sentaks hataları;

    int x;
    int y;

    y = x; // Çöp değerle, otomatik ömürlü bir nesnenin değerini kullanmak. Undefined Behavior - Tanımsız Davranış

---------------------------------------------------------------------------------------

    int x;
    printf("Bir tam sayi girin: ");
    scanf("%d", x); //adres operatörünü yazmayı unuttuk. & operatörünü yazsaydık, bu call by reference olacağı için uyarı mesajı vermeyecekti.
                    //ama burada, scanf fonksiyonuna x'in çöp değerini gönderdik. otomatik ömürlü bir nesnenin çöp değerini kullanmak

---------------------------------------------------------------------------------------

Bir değişken tanımlamak ama kod içerisinde kullanmamak. Derleyicilerin hemen hepsi bu durumu yakalar.
unreference local variable / derleyici uyarı mesajlarında bu sözel yapı farklı olabilir.

---------------------------------------------------------------------------------------

Yan etkisi olmayan bir ifade deyimi yazmak, yani öyle bir deyim ki, derleyiciye göre onun olmasıyla olmaması arasında bir fark yok.

int x = 5;
int y = 15;

x == y //yanlışlıkla atama operatörü yerine karşılaştırma operatörü kullanılmış. bir sentaks hatası yok.

C'nin kurallına göre bir ifade geçerliyse, o ifadenin sonuna ; atomunu koyarak oluşturduğumuz ifade deyimi de geçerlidir.

result of expression not used; did you intend '='?

---------------------------------------------------------------------------------------

int x = 5;
int y = 15;

x + y; // işlemli atama operatörü yerine sadece toplama operatörü olan +'yı yanlışıkla yazdık.

'+' result of expression not used

---------------------------------------------------------------------------------------

Programcı burada abs fonksiyonunun geri dönüş değerini kullanmamış, discard etmiş.
Bu örnekte bu fonksiyonun geri dönüş değerini kullanmamak lojik hata. Derleyici herhangi bir uyarı vermeyebilir.

Her fonksiyonun geri dönüş değerini kullanmak zorunda mıyız? Hayır. 
Bazı fonksiyonlar içsel olarak derleyici tarafından etiketleniyorlar. Böyle fonksiyonlara popüler olarak no-discard fonksiyonlar diyoruz.

C++ ise bu zaten dilin aracı ile belirliyoruz. Attribute
Bu fonksiyonun kullanılmadığını saptarsan, sentaks hatası ver.

[[nodiscard]] int foo(int x)
{
    return x + 5;
}

C de ise standart değil, derleyicilerin extensionları.

    int x;
    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    abs(x);

---------------------------------------------------------------------------------------

Örnek olarak scanf fonksiyonunun geri dönüş değerini discard ediyorsak, bunu okuyucuya anlatmak için bu şekilde yazabiliriz.
Derleyici bu durumda hiçbir uyarı mesajı vermeyecek.

int ival;
printf("Bir tam sayi giriniz: ");
(void)scanf("%d", &ival);

---------------------------------------------------------------------------------------

Standart getchar ve putchar fonksiyonları

01.22.00

*/


#include <stdio.h>
#include <math.h>

int main(){

    int x;
    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    abs(x);
}