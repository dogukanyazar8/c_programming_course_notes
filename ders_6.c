/* 

Ders6

Fonksiyonlar (Function, Subroutine)

double func (int x, int y)
{

}

fonksiyonun parametre değişkeni
formal parameter 

C dili geçmişe doğru uyumlu bir dildir. Bu standartlar tarafından temel bir ilkedir.

explicit 

implicit int
(örtülü - gizli - kapalı)

C89 standartlarında dilin kuralları gereği eğer belli bir alanı boş bırakırsak int yazmış kabul ediliyor.

implicit int kuralı günümüzde geçerli değildir. C99 standartlarıyla dilden kaldırılmıştır.

Derleyiciler implicit int durumlarında hata vermezler, uyarı verebilirler.

C89 standartlarında fonksiyonun geri dönüş değerini boş bırakmak varsayılan olarak int türü kabul edilir. (implicit int)

Geri dönüş değeri olmayan bir fonksiyon tanımlamak istediğimiz void anahtar sözcüğünü kullanıyoruz.

Fonksiyonun parametre değişkenleri otomatik ömürlü değişkenlerdir.

void func(void)
{

}

Otomatik ömürlü değişkenler ile Statik ömürlü değişkenlerin farkı

++Bu program çalıştırıldığında a değişkenin değeri hep 10 olacak.

void func(void)
{
    int a = 10;     //otomatik ömürlü yerel değişken
    
    printf("a = %d\n", a);

    a += 5;
}

int main ()
{
    func();
    func();
    func();
    func();

}
-----------------------------------------------------------------------

++Bu program çalıştırıldığında a değişkeni hayata bir kere gelecek.
++Bu fonksiyon kaç kere çağrılırsa çağrılsın bu bildirim bir daha hayata gelmeyecek.


void func(void)
{
    static int a = 10;     //statik ömürlü yerel değişken
    
    printf("a = %d\n", a);

    a += 5;
}

int main ()
{
    func();
    func();
    func();
    func();

}

C ve C++ dillerinde bir fonksiyonun içerisinde bir fonksiyon tanımlanması yoktur. Sentaks hatasıdır.
Fonksiyon içinde fonksiyon tanımlanamaz.

Bütün fonksiyonlar global alanda ayrı ayrı tanımlanırlar.

Fonksiyonların geri dönüş değeri üretmesi ve return deyimi

RETURN STATEMENT

Statements

expression statement
x + 5;
compound statement
{

}
null statement
;
control statement
if
while
for
do while

switch
go to

continue
break
return

-----------------------------------------------------------------------

RETURN STATEMENT

Yalın Return Deyimi (İfadesiz Return Deyimi)
return;

Yanında ifade olan return deyimi (İfadeli Return Deyimi)
return expr;

Yalın return deyimi void fonksiyonlarda kullanılır.
Geri dönüş değeri üretmeyen fonksiyonlar kullanılır.

Return deyiminin yürütülmesiyle bir fonksiyonun kodunun çalışması sona erer.

void func(void)
{
    statement1;
    statement2;
    if(x > 10)
        return;
    statement3;
}

Return ifadesinin değeri hesaplanır ve hesaplanan değer fonksiyonun geri dönüş değeri olarak fonksiyonu çağıran koda iletilir.

return x + y;
return a * a * a;
return 8;

C ve C++ dillerinde bir fonksiyon yalnızca tek bir değer döndürebilir.


//one-liner
Bir fonksiyonun kodu tek bir satırsa, bu fonksiyona one-liner fonksiyon deniliyor.

int sum (int x, int y)
{
    return x + y;
}

int max2 (int x, int y)
{
    if (x > y)
        return x;
    
    return y;
}  

int abs (int x)
{
    if (x < 0)
        return -x;
    return x;
}

int max3 (int x, int y, int z)
{
    int max = x;
    
    if (y > max)
        max = y;
    if (z > y)
        max = c;
    
    return max;
}

Geri dönüş değeri olan bir fonksiyonun tanımında return deyimi olmaması tanımsız davranıştır. 
Fonksiyonun geri dönüş değeri çöp değerindedir. Garbage value - indetermined value.
Derleyicinin yaptığı lojik kontrollere takılır.

Örnek Fonksiyon:

int func (int x)
{
    if (x > 210)
        return x;
    //?? return deyimi yok.
}

DK 1:48:30

 */