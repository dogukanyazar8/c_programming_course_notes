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

DK 35.47

 */