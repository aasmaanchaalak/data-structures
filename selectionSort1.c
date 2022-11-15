#include <stdio.h>

static void sort(int *num){
    printf("%d", num[0]);
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int num[n];
    for (int i=0; i<n; i++){
        scanf("\n%d", &num[i]);
    }
    sort(num);
    return 0;
}