#include<stdio.h>

#define FIB(num) ({\
    int fib1=1, fib2=1;\
    for(int i = 2; i<num; i++) {\
        fib2+=fib1;\
        fib1=fib2-fib1;\
    }\
    printf("%d fibonacci number is %d \n", num, fib2);\
})

void fibonacci(int num) {
    int fib1=1, fib2=1;
    for(int i = 2; i<num; i++) {
        fib2+=fib1;
        fib1=fib2-fib1;
    }
    printf("%d fibonacci number is %d \n", num, fib2);
}

void main() {
    // //fibonacci(3);
    // //FIB(6);
    // int f1=0,f2=1, n=10;
    // while(n--) {
    //     printf("%d \n", f2); f2+=f1; f1=f2-f1;
    // }
    char c = 'e';
    printf("%d\n", (int)sizeof(char));
    printf("%d\n", (int)sizeof(c));
    printf("%d\n", (int)sizeof('e'));
}
