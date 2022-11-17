#include <stdio.h>
#include <math.h>

void sort(int *num, int n){
    int i, j, key;
    for (i=1; i<n; i++){
        key = num[i];
        j = i-1;

        //loop to swap elements greater than key
        while (j>=0 && num[j]>key){
            num[j+1]=num[j];
            j=j-1;
        }
        num[j+1]=key;
    }
}

//printing output list
void printList(int *arr, int n){
    printf("Output");
    for (int i=0; i<n; i++){
        printf("\n%d", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //taking list input
    int num[n];
    for (int i=0; i<n; i++){
        scanf("\n%d", &num[i]);
    }
    sort(num, n);
    printList(num, n);
    return 0;
}