/*

Ders10

Operatörler (OPERATORS)

Operator
Operand
Operand Sayısı (Unary, Binary, Turnary)
Operator ile Operand Konumsal İlişkisi (Prefix, Postfix, Inefix)
Operator Kısıtlamaları (Constraints)
C dilinde her operatör bir değer üretir.
Operatör Önceliği

Operatör önceliği bir işlemin bir işleme göre fiziksel olarak daha önce ya da daha sonra yapılacağı anlamına gelmiyor!

int func(void)
{
    printf("func cagrildi\n");
}

int foo(void)
{
    printf("foo cagrildi\n");
}

int main()
{
    int x;

    x = func() + 5 * foo(); //Burada hangisi daha önce çağrılacak, func mı foo mu?
}

Yukarıdaki x'e yapılan atama ifadesinde, hangi fonksiyonun daha önce çağrılacağı unspecified behavior, derleyici istediği kodu üretebilir.

x = func() + 5 * foo();

(5 * foo()) bu işlemden elde edilen değer, toplama operatörünün sağ operandı olacak.

func() + (5 * foo())

C dilinde operatör önceliği nasıldır?

Operatör Öncelik Tablosu

! ->> Logical Not
~ ->> Bitwise Not

--------------------------------------------------------------------------------------
1   ()  []  .   ->                                                              
--------------------------------------------------------------------------------------
2   +   -   !   ~   &   *   sizeof (type)   ++  -- (* dereference)      RIGHT TO LEFT
--------------------------------------------------------------------------------------
3   *   %   /
--------------------------------------------------------------------------------------
4   +   -   (toplama ve çıkartma operatörleri)
--------------------------------------------------------------------------------------
5   >>  << (bitwise right and left shift)
--------------------------------------------------------------------------------------
6   <   <=  >   >=
--------------------------------------------------------------------------------------
7   ==  !=
--------------------------------------------------------------------------------------
8   & (bitsel ve)
--------------------------------------------------------------------------------------
9   ^ (bitsel xor)
--------------------------------------------------------------------------------------
10  | (bitsel veya)
--------------------------------------------------------------------------------------
11  && (logical and)
--------------------------------------------------------------------------------------
12  || (logical or)
--------------------------------------------------------------------------------------
13  ? (turnary operator)                                                RIGHT TO LEFT                                                   
--------------------------------------------------------------------------------------
14 = += -= *= /= %= >>= <<= &= ^= |=                                    RIGHT TO LEFT
--------------------------------------------------------------------------------------
15  , (comma operator)
--------------------------------------------------------------------------------------

Her öncelik seviyesinin bir öncelik yönü vardır. Associativity

Left Associative    Soldan Sağa
Right Associative   Sağdan Sola

3 tane öncelik seviyesi dışından, bütün öncelik seviyelerinin yönü soldan sağa.
Unary operatörlerini koyduğumuz 2. öncelik seviyesi.
Koşul operatörünün bulunduğu 13. öncelik seviyesi.
Atama operatörlerinin bulunduğu 14. öncelik seviyesi.

Associative ne demektir?

x++ * y - 10 / 5 < z % 2

Derleyici, biz hiç öncelik parantezi kullanmamış olsak da, bu ifadeyi aşağıdaki gibi yorumlayacak. Operatör önceliğine göre.

(((x++) * y) - (10 / 5)) < (z % 2)

a * b - 5 > 10

((a * b) - 5) > 10

x * y / z % t

((x * y) / z) % t

x * (y / z) % t ->>>>>>> Aynı öncelik seviyesinde olan operatörlerde, öncelik parantezi kullanarak kendimiz önceliği belirleyebiliriz.

!~x++ 

! ~ ve ++ 2. öncelik seviyesinde. sağdan solda. right associative. Öncelik bu şekildedir -> !(~(x++)) 

*/

