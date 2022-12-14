#include <stdio.h>
#include <stdlib.h>

int main(){

    int p = 5;
    int *ptr = &p;
    printf("p = %d\n", p);
    printf("&p = %d\n", &p);
    printf("ptr = %d\n", ptr);
    printf("*ptr = %d\n", *ptr);
    printf("&ptr = %d\n\n", &ptr);

    int a[5];
    printf("a = %d\n", a);
    printf("*a = %d\n", *a);
    printf("&a = %d\n", &a);
    a[0] = 0;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    printf("a = %d\n", a);
    printf("*a = %d\n", *a);
    printf("&a = %d\n", &a);
    printf("&a[0] = %d\n", &a[0]);
    printf("a[3] = %d\n", a[3]);
    printf("a[4] = %d\n\n", a[4]);

    int* arrPtr;
    arrPtr = (int*)malloc(2*sizeof(int));
    printf("Size of int = %d\n", sizeof(int));
    arrPtr[0] = 0;
    arrPtr[1] = 1;
    arrPtr[2] = 2;
    arrPtr[3] = 3;
    arrPtr[4] = 4;
    arrPtr[5] = 5;
    arrPtr[6] = 6;
    arrPtr[7] = 7;
    arrPtr[8] = 8;
    arrPtr[9] = 9;
    arrPtr[10] = 10;
    printf("sizeof(arrPtr) = %d\n", sizeof(*arrPtr));
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("arrptr[10] = %d\n", arrPtr[10]);
    realloc(arrPtr, 12);
    arrPtr[11] = 11;
    arrPtr[12] = 12;
    printf("sizeof(arrPtr) = %d\n", sizeof(*arrPtr));
    free(arrPtr);
    printf("arrptr[12] = %d\n", arrPtr[12]);
    printf("sizeof(arrPtr) = %d\n", sizeof(*arrPtr));

    return 0;
}