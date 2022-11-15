#include <stdio.h>

void sort(int *num, int n){
    
    int min; //index of minimum element

    for (int i=0; i<n-1; i++){
        min = i;
        for (int j=i+1; j<n; j++){

            //searching for smallest element
            if (num[j] < num[min]){
                min = j;
            }

            //interchanging elements
            if (min != i){
                int temp = num[min];
                num[min] = num[i];
                num[i] = temp;
                min = i;
            }
        }
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