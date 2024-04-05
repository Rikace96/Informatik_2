//Was gibt das folgende Programm speikla1.c aus?
#include <stdio.h>
int i=0;
int setze1(int x);
int setze2(int x);
int main(void)
{
auto int i=5;
setze1(i/2); printf("i = %d\n", i);
setze1(i=i/2); printf("i = %d\n", i);
i = setze1(i/2); printf("i = %d\n", i);
setze2(i); printf("i = %d\n", i);
return(0);
}
int setze1(int i)
{
i = i<=2 ? 5 : 0;
return(i);
}
int setze2(int i)
{
i = i%i * (i*i/(2*i)+4); printf("i = %d\n", i);
return(i);
}
