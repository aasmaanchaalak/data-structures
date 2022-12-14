#include <stdio.h>

// I want you to change the increment and n and see at what point you end up with an extra loop

int main(int argc, char** argv){

    float i, increment, n;
    int count;

    printf("Test 1: 10 times\n");
    increment = 0.000000001; //Change around this
    n = 0.00000001; //And this (this is 10 times increment)
    count = 1;
    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    printf("Test 2: 100 times\n");
    increment = 0.0000000001; //(this is 100 times increment)
    n = 0.00000001;
    count = 1;
    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    printf("Test 3: 1000 times\n");
    increment = 0.00000000001; //(this is 1000 times increment)
    n = 0.00000001;
    count = 1;
    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    printf("Test 4: 100,000 times\n");//(this is 100,000 times increment)
    increment = 0.0000000000000001;
    n = 0.00000000001;
    count = 1;
    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    printf("Test 5: 100,000 times; both values changed\n");
    increment = 0.0000000000000001; //(this is 100,000 times increment)
    n = 0.00000000001; //this is also changed
    count = 1;
    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    printf("The loop breaks early in Test 4.\n");
    printf("An extra loop starts in Test 5.\n");

    return 0;
}