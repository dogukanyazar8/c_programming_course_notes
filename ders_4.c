/* 

Ders4
-----------------------------------------------------------------------
BASIC TYPES
    Integer Types
    Floating Types
USER DEFINED TYPES
    Structures
    Unions
    Enumarations
-----------------------------------------------------------------------
INTEGER TYPES

1 Byte
char (Implementation Defined (Derleyici karar veriyor))                
signed char
unsigned char

2 Byte
short int
unsigned short int

2/4/8 Byte
int
unsigned int

4/8 Byte
long int
unsigned long int

8 Byte
long long int (C99)
unsigned long long int (C99)

1 Byte
_Bool (Unsigned Integer Types)

printf("Size of char: %zu\n", sizeof(char))

Compiler Extensions (Derleyici Eklentisi)

Derleyicilerin programcılara sunduğu, işleri kolaylaştıran eklentiler. (Örnek: GCC)
Standart değildir. Farklı bir derleyicide elde edilen sonuçlar değişebilir.

Extended Integer Types
Derleyiciler var olan veri türlerinin dışında eklenti olarak daha geniş sınır aralığı olan tam sayı türleri sağlayabilir.
Örnek: int128_t
-----------------------------------------------------------------------
FLOATING TYPES - IEEE 754 Gerçek Sayı Formatı

4 Byte
(real floating types)
float       (4 Byte)   
double      (8 Byte) (En sık kullanılan gerçek sayı türü)
long double (8/10/12/16 Byte)

(complex types) (C99)
float_Complex      
double_Complex          
long double_Complex      

(imaginary) (C99)
float_Imaginary      
double_Imaginary          
long double_Imaginary  

32 Bitlik Alan => single precision
64 Bitlik Alan => double precision

sign bit
1--------***********************

1 bit: sayının işaretini belirtmek için kullanılıyor
8 bit: sayının büyüklüğü belirtmek için çarpan değerini tutuyor
23 bit: mantissa alanını belirtmek için kullanılıyor

 */