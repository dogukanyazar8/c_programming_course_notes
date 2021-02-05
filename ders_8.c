

/*

Ders8

Sabitler (Constants)

Integer Constants (tam sayı sabitleri)
    int (charachter literals)
    unsigned int
    long
    unsigned long
    long long
    unsigned long long
Floating Constants (gerçek sayı sabitleri)
    float
    double
    long double

C dilinde sabitlerin yazımında 3 farklı sayı sistemini kullanabiliyoruz. (Sabitin türü değil! Sayı sistemi!)
    Decimal
    Octal
    Hexadecimal

Öyle alanlar var ki, bu alanlarda varsayılan olarak hexadecimal veya octal sayı sistemleri kullanılıyor.
Örnek olarak mikroişlemcilerin adreslenmesinde hexadecimal sayı sistemi kullanılıyor.

Tam Sayı Sabitleri

int x = 41;     //Decimal
int y = 041;    //Octal
int z = 0x41;   //Hexadecimal

16'lık sayı sisteminin yazımı

0X41 veya 0x41. Harfler küçük de olabilir büyük de. (en iyisi - ya hepsini büyük, ya da hepsini küçük yazmaktır.)

Derleyiciler, standart C dilinin kurallarının yanı sıra, programcının işini kolaylaştırmak için standart olmayan araç ya da araçlar da sunuyorlar.
Bu öğelere derleyici eklentileri deniliyor. Compiler Extensions

+GCC derleyicisinin eklentileri.

Mesela, C dilinde ikilik sayı sisteminde bir sabit yazılamaz fakat derleyici eklentisiyle yazılabilir. (C++'da ise ikilik sayı sistemi standart.)

Örnek olarak: int x = 0b1100101;

int x = 87'321'784; // C dilinde derleyici etklentisi olabilir, C++ dilinde standart

--------------------------------------------------------------------------------------------------------

Eğer yazılan bir tam sayı sabiti sistemin işaretli int türünü sınırını aşmıyorsa türü int türüdür. (sabitlerin türü taşmıyorsa default olarak int)


2147483647 -> Sabitin türü int.
2147483648 -> Sabitin türü unsigned long.

50000 - Bu sabitin türü nedir?
Cevap: Impletation Defined.

0x1ac4 - Bu sabitin türü nedir?
Cevap: int (çünkü sistemdeki int sınırlarını taşmıyor)

unsigned int türünden sabitler. U harfi küçük veya büyük olabilir.

642u;
542U;
0X12u;
0156U;

long türünden sabitler. L harfi küçük veya büyük olabilir fakat küçük harf kullanmamak lazım çünkü "1 ile l" karıştırılabilir.

45L;
39l;
0x65L;
04234L;

unsigned long türünden sabitler. UL harfi küçük veya büyük olabilir, harflerin sırası da önemli değil.

46UL;
46LU;

long long türünden sabitler. LL harfi küçük veya büyük olabilir, harflerin sırası da önemli değil.

55LL;
55ll;

unsigned long long türünden sabitler. ULL harfi küçük veya büyük olabilir.

55ULL;
55LLU;

Ek olarak 0 da bir sabittir. Sıfırın da türü vardır.

0;
0U;
0UL;
0LL;

--------------------------------------------------------------------------------------------------------

Taşma durumunda ne olur?

Eğer yazılan sabit bir son ek içermiyorsa ve int türünü aşıyorsa, sabitin türü bu durumda hangi sayı sisteminde yazıldığında da bağlı
    
    Eğer taşan sabit, 10'luk sayı sisteminde yazılmışsa

    int'e sığmadı,
    long'a sığmadı,
    unsigned long'a sığmadı,
    long long'a sığmadı,
    unsigned long long

    Eğer taşan sabit, 8'lik veya 16'lık sayı sisteminde yazılmışsa

    int'e sığmadı,
    unsigned int'e sığmadı,
    long'a sığmadı,
    unsigned long'a sığmadı,
    long long'a sığmadı,
    unsigned long long

    4976123871u -> Sonunda U son eki olduğunda, taşsa da unsigned olmak zorundadır.

------------------------------------------------------------------------------------------------


Gerçek Sayı Sabitleri

Eğer bir sabit nokta içeriyorsa varsayılan olarak sabitin türü double'dır.

Sabiti 34.4 olarak yazıyoruz fakat bilgisayar bunu bize 34.39999999999 gibi bir şekilde gösteriyor. Bu neden?

Biz 34.4 gerçek sayı sabitini yazıyoruz fakat double sayı formatında bunun karşılığını elde etmek tam olarak mümkün değil.

Mantissa alanındaki bit sayıları toplandığında tam olarak 34.4 yapmıyor. 34.4'e en fazla bu şekilde yaklaşabiliyoruz.

34.;
34.0;
0.52;
.52;
.4;

Gerçek sayı sabitinin float türü olması için küçük veya büyük harf f - F eki alması gerekiyor.

34.8F;
22.4f;
0.f;
762f;   -> sentaks hatası. nokta içermiyor.

8;      int
8L;     long
8.;     double
8.L;    long double

Gerçek sayı sabitlerinin yazımında kullanılan notasyona üstel notasyon diyoruz. (Scientific Notation)

2.7 * 10^4

2.7e3
2.7E-5

3E4
3e4
23e-4

2.6e3;
2E4;

#include <stdio.h>

int main()
{
    3E4;
    2.6E3;
    2E4;   
    1.2E-3;

    float f = 1.4;

    if (f == 1.4)
    {
        printf("Dogru!\n");
    }
    
    else
        printf("Yanlis!\n");       

    return 0;
}

#include <stdio.h>

int main()
{
    double dval = 0.;

    for (int i = 0; i < 10; ++i)
        dval += 0.1;
    printf("dval = %f\n", dval);

    if (dval == 1.) {
        printf("Evet Dogru!\n");
    } else {
        printf("Hayır Yanlis!\n");
    }
}

Yukarıdaki iki program da programın çalışma zamanında yanlış kısmına girecektir. Gerçek sayı aritmetiği, tam sayı aritmetiği gibi değildir.

------------------------------------------------------------------------------------------------

Karakter Sabitleri

int türden sabitlerin bir alt kategorisidir, sabitlerin bir yazım biçimidir.

C dilinde karakter sabitlerinin türü int türüdür.
C++ dilinde karakter sabitlerinin türü char türüdür.

'A'
'D'
'+'

Escape Sequence 

'\n'
'\45'
'\145'

Karakter Kodlaması (Character Encoding)

ASCII
UNICODE
EBCDIC

'A'

A karakterinin karakter kodlamasında kullanılan B karakterinin kod numarası. Karakter kodlama sistemlerinde her bir karakterin bir kod numarası vardır. (Coding Place)

ASCII karakter kodlamasında 128 tane karakter vardır.



 










*/


