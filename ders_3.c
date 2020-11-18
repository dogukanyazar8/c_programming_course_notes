/* 

Ders3

-----------------------------------------------------------------------
OPERATORS (Operatörler)

Dilin işlem yaptıran atomlarına operatör denir.
C dilinin 45 operatörü vardır.
Bazı operatörler tek karakterlik atomlardır. Örnek: + - ~ !
Bazı operatörler iki karakterlik atomlardır. Örnek: >= || ++ ==
Bazı operatörler üç karakterlik atomlardır.  Örnek: >>= <<=
sizeof bir anahtar sözcük olmasına karşın C dilinin bir operatörü olarak kullanılmaktadır.
-----------------------------------------------------------------------
CONSTANT (Sabitler)

Doğrudan sayısal bütünlük ifade eden atomlar.

x = 24;     // x bir identifier. 24 ise sabit.

Tam sayı sabitlerini 3 ayrı şekilde ifade etme olanağımız var.

x = 123;    10'luk sayı sistemi ifadesi (123)
x = 0x123;  16'lık sayı sistemi ifadesi (291)
x = 0123;    8'lik sayı sistemi ifadesi (83)

Çift tırnak içerisinde yazılan atomlar ayrı bir kategoridir. Yazı sabitleri (string literals)

"Arpeggio" 

sum += val;     
// sum (identifier)
// += (operator)
// val (identifier)
// ; ()

"sum += val;"
//tek bir atomdur.

C, C++, C#, Java gibi programlama dilleri atomik dillerdir. Yani kaynak kodun en küçük birimi bir atomdur.
Atomlar arasındaki boşluk karakterlerinin (white-space) kodun üzerinde bir etkisi yoktur. 
Compiler için bir etkisi yoktur.

Code Convention (Konvensiyon)
Code Layout     (Yerleşim)
-----------------------------------------------------------------------
EXPRESSION (İfade)

C ve C++ dillerinde bir ifade, 
İsimlerin, Operatörlerin, Sabitlerin oluşturduğu bir birim.

if(expression)

x               //ifade
24              //ifade
x = 12          //ifade
y = x + 10 > 5  //ifade

Bir ifadenin bütününü değil de, bir bileşenini kastettiğimizde ona sub-expression denir.

İfadenin Değer Kategorisi (Value Category)

Bir ifade, ya bir sol taraf değeri ifadesidir, ya da bir sağ taraf değeri ifadesidir. İkisi birden olamaz.

L Value Expression (Sol taraf değeri ifadesi)
R Value Expression (Sağ taraf değeri ifadesi)

L Value Expression: 
Okuma veya yazma amacıyla kullanabilecek, erişilebilir bir bellek alanından, yerden bahsediyoruz.
Object (Nesne) (Programın çalışma zamanındaki bellekteki bir yer)
Örnek: x = 10; x; a[8];

R Value Expression:
Bellekte bir yere karşılık gelmiyor. 
Aritmetik operatörlerle oluşturulan hiçbir ifade sağ taraf değeri olamaz.
Örnek: x + 8

Eğer ifadeyi adres operatörünün operandı yaptığımızda derleyici;
sentaks hatası verirse sağ taraf değeridir, 
sentaks hatası vermezse sol taraf değeridir.

int a[10];

&[5];


EXPRESSION -> Data Type (Veri Türü)
Her ifadenin bir veri türü olmak zorundadır. Dil tarafından belirlenmiş türlerden biri olmak zorundadır.
Bir ifadenin değeri ve türü vardır.


int x = 10;
x + 2;

value of an expression (ifadenin değeri)

EXPRESSION -> Constant Expression (Sabit İfadesi)
Derleyici, derleme zamanında ifadenin değerini tam olarak hesaplayabiliyor.
Yani ifadenin değeri programın çalışma zamanına ilişkin değil, derleme zamanında ilişkindir.

x + y           //sabit ifadesi değildir.
10 + 20 - 5     //sabit ifadesidir. (25)

int a[buradaki_sabit_ifadesi_olması_gerekir];
int a[10];



 */