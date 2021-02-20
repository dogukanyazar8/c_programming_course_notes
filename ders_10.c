/*

Ders10

Operatörler (OPERATORS)

Operator
Operand
Operand Sayısı (Unary, Binary, Turnary)
Operator ile Operand Konumsal İlişkisi (Prefix, Postfix, Infix)
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

+ - * & gibi tokenları derleyici nasıl ayırt ediyor?

Bu operatörlerin unary veya binary olmasından dolayı anlıyor. Operand sayısına göre yani.

a = *ptr * 5;

*ptr ifadesindeki * derefencing operatorü. unary, tek operandlı.

*ptr * 5 ifadesindeki * ise binary, multiplication operatörü, binary, iki operandlı.

a = ((*ptr) * 5);

x *= y += z %= t; //buradaki operatörlerin hepsi aynı seviyede, operatör öncelik yönü ise sağdan sola.

x *= (y += (z %= t))

Operator Önceliği -> Operator Presedence / Operator Priority
Operator Öncelik Yönü -> Associativity 

-----------------------------------------------------------------------------------------

Side Effect (Yan Etki)

Yan etki, programda bir durum değişikli demektir.

Mesela bir değişkenin değerinin değişmesi bir yan etkidir.
Dışsal bir aygıta bir çıkış işleminin yapılması, bir yan etkidir. (Giriş çıkış işlemleri)

Tüm operatörler bir değer üretir fakat bazı operatörlerin yaptırdığı işlem sonucunda bir nesneni değeri değişir.

!x //bu operatörün yan etkisi var mıdır? logic değil operatörünün yan etkisi yoktur. bu işlemden sonra nesneni değerini değiştirmez

a + b //bu operatörün yan etkisi var mıdır? toplama operatörünün yan etkisi yoktur, a veya b değişkeninin değerini değiştirmiyor.

x++ // bu operatörün yan etkisi vardır. ++ operatörü, operandı olan nesnenin değerini 1 arttırıyor.


Neden bu durum için side effect, yan etki terimi kullanılmış?

Çünkü operatörün asıl işlevi bir değer üretmek. 
Operatörün bir değer üretmesi başka bir durum
bu işlem esnasında bir değişkenin değerinin değişmesi başka bir durum.

Yan Etkisi Olan Operatörler

++
--
=
*= += -= /= (tüm işlemli atama operatörleri)

//Aşağıdaki programda x'in değeri değişmez. Yan etki yoktur. Logic değil operatörü yan etki üretmez.

int x = 248;

!x;

printf("X = %d", x);

//Aşağıdaki programda x'in değeri değişir. Yan etki vardır. ++ Operatörü yan etki üretir.

int x = 248;

++x;

printf("X = %d", x);

//Aşağıdaki programdaki x'in değeri değişir. Yan etki vardır. İşlemli atama operatörü yan etki üretir.

int x = 24;

x /= 2;

printf("X = %d", x);

-------------------------------------------------------------------

Value Category (Değer Kategorisi)
    L Value Category
    R Value Category

Değer kategorisi, C dilinde bir ifade nitelendiriyor. 
Ya sol taraf değeri olacak ya da sağ taraf değeri olacak. İkisi birden olamaz.

Bir ifadenin hangi değer kategorisinde olduğunu anlamak için, o ifadeyi adres operatörünün operandı yapabiliriz.
Hata vermiyorsa, o ifade sol taraf değeridir. Hata veriyorsa sağ taraf değeridir.

C dilinde bazı operatörlerle oluşturulan ifadeler R taraf değeri olabilir,
C++ dilinde sol taraf değeri olabiliyor.

    int x;

    x + 5;  -> R Value Expression / Sağ Taraf Değeri

    +x;     -> R Value Expression / Sağ Taraf Değeri

    ++x;    -> R Value Expression / Sağ Taraf Değeri

    x = 5;  -> R Value Expression / Sağ Taraf Değeri

Operatörlerin Gruplandırılması

Aritmetik Operatörler
    C dilinde aritmetik işlem yapılmasını sağlıyorlar.
        + - (işaret operatörleri) ++ --
        * / %
        + - (toplama çıkarma operatörleri)
-------------------------------------------------------------------
İlişkisel Operatörler (Relational Operators)
    C dilinde karşılaştırma yapılmasını sağlıyorlar.
        > >= < <=
        == !=
-------------------------------------------------------------------
Mantıksal Operatörler (Logical Operators)
    C dilinde mantıksal işlemlerin yapılmasını sağlıyorlar.
        !   &&  ||
-------------------------------------------------------------------
Atama Operatörleri (Assignment Operators)
    C dilinde atama işlemlerinin yapılmasını sağlıyorlar.
        = += -=
Pointer Operatörleri
        & address of
        * [] dereferencing
        index / subscript
        -> (member selection - arrow operator)
-------------------------------------------------------------------
ternary operator
sizeof
type-cast

, virgül operatörü (comma operator)
 
+= veya -= gibi operatörlere compound assignment operators deniliyor.
İşlemli Atama Operatörleri
-------------------------------------------------------------------
                            OPERATÖRLER
-------------------------------------------------------------------
Topalama ve Çıkarma Operatörü

Binary Infix (iki operand, orta operatör konumunda)
Operandları L value veya R value expression olabilir.
Oluşturulan ifadenin kendisi de R value expressiondır.
Her iki operatör de 4. öncelik seviyesinde ve SOLDAN SAĞA öncelik yönüne sahiptir.
Her iki operatörün de yan etkisi yoktur.

İşaretli tam sayı türlerinde taşma, tanımsız davranıştır.

Dolayısıyla bu operatörleri kullanırken dikkat edilmesi gerekiyor. 
İşlemden elde edilecek değer, ilgili türün taşıyabileceği değer aralığı içinde değilse, taşma olacak.

İşaretsiz türlerde taşma tanımsız davranış değildir.

    int x, y;
    printf("iki tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d + %d + %d\n", x, y, x + y);
    printf("%d + %d = %d\n", x, y, x - y);

Bir de işaret operatörleri var. Unary olarak kullanıldıklarında bunlar işaret operatörüdür.
2. öncelik seviyesindedir.
İşaret operatörleri yan etkiye sahip değildir.
Nesnenin değerini değiştirmez fakat value kategorisini değiştirir.

-x ->>> 0 - x
+x ->>> 0 + x 

    int ival;

    +ival;  ->>> Burada L value olan ival, işaret operatörünün operandı yaptığımızda R value kategorisinde oluyor.

    +ival = 24; ->>> Bu geçersiz bir ifadedir.

- İşaret Operatörü

    int x;

    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    x = -x;

    printf("X = %d", x);

        int x, y;

        printf("bir tam sayi girin: ");
        scanf("%d", &x);

        y = -x - 5; ->>> -x işaret operatörü -, diğer - ise çıkartma operatörü olan -.

        printf("Y = %d", y);

Çarpma, Bölme, Mod Operatörler (Multiplication, Division, Modulus(Remainder))

Bu operatörler 3. öncelik seviyesindedirler.
Bu 3 operatör de 3. öncelik seviyesinde ve SOLDAN SAĞA öncelik yönüne sahiptir.
Binary Infix Operatörlerdir (iki operand, orta operatör konumunda)
Oluşturulan ifadenin kendisi de R value expressiondır.
Bu 3 operatörün de yan etkisi yoktur.

x * y
x / y
x % y

C dilinde, tam sayıyı tam sayıya bölerek, gerçek sayı elde edemeyiz.

int x = 10;
int y = 3;

x / y -> sonuç bir tam sayı olmak zorundadır. 3. int.

Yuvarlama yapılmaz. Ondalık kısım kaybedilir. (Truncation)

Tam sayı işlemlerinde 0'a bölmek, tanımsız davranıştır. Sağdaki operandın 0 olmamasından biz sorumluyuz.

Mod operatörü bazı programlama dillerinden farklı olarak, C dilinde bir tam sayı operatörüdür. 
Mod operatörünün sol veya sağ operandının gerçek sayı olması sentaks hatasıdır.

C dilinde bir gerçek sayının bir gerçek sayıya bölümünü, 

x % y


*/

#include <stdio.h>

int main()
{
    int x, y;

    printf("bir tam sayi girin: ");
    scanf("%d", &x);

    y = -x - 5;

    printf("Y = %d", y);
}