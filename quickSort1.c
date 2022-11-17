#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    //loop to segregate elements smaller than pivot
    for (int j = low; j <=high - 1; j++){
        if (arr[j] < pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    //bringing smaller elements to the front
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p+1, high);
    }

}

//printing output
int* sort(int *a, int n){
    quicksort(a, 0, n-1);
    printf("Output- \n");
    for (int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return a;
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i=0; i<n; i++){
        scanf("\n%d", &a[i]);
    }

    sort(a, n);
}