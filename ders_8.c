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

*/