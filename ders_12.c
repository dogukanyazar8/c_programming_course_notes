/* 

Ders12

Sequence Point (Sequencing)
Yan Etki Noktası

Kaynak kodda öyle bir nokta ki, bu noktadan önceki kodlardan oluşan yan etkiler, bu noktadan sonra gerçekleşmiş olmak zorundadır. Bu noktalara sequence point denir.

Bir değişkenin değerinin değişmesi bir yan etkidir. Side Effect.
Eğer yan etkiye uğramış bir nesneyi bu yan yetkinin gerçekleşmiş olmak garantisi olmadan yeniden kullanmak tanımsız davranıştır. UB

int x = 10;

++x;

(peki yukarıdaki kodda, x'in değeri tam olarak ne zaman değişecek?)

C dilinde sequence point olarak noktalar:

1) Deyim Sonu

x = y;
func(x);

++a;
b = a;

2) 4 Tane Operatör

exp1 && exp2    (Logical And)
exp1 || exp2    (Logical Or)
a > 10 ? b : c  (Turnary Operator)
++x, y = x;     (Comma Operator)


İlk değer verme listesindeki virgül de bir yan etki noktası oluşturuyor.

int x = 10, y = x++, z = x + y;


 */

#include <stdio.h>

int main()
{
/*     int x = 10, y = x++, z = x + y;
    printf("%d - %d - %d", x, y, z);

    return 0; */

    for (int i = 95; i < 10l; ++i)
    printf("%d", i);

}