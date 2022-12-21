#include <stdio.h>
int size = 0;

void heapify(int a[], int size, int i){
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    printf("max - %d\n", i);
    if (l < size && a[l] > a[max])
        max = l;
    if (r < size && a[r] > a[max])
      max = r;
    if (max != i)
    {
      int temp = a[i];
      a[i] = a[max];
      a[max] = temp;
      heapify(a, size, max);
    }
}

void insert(int a[], int c){
    if (size == 0){
        a[0] = c;
        size += 1;
    } else {
        a[size] = c;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(a, size, i);
        }
    }
}

void printHeap(int a[], int n){
    for (int i=0; i<n; ++i){
        printf("%d", a[i]);
    }
}

int main(){
    int n,c;
    printf("Enter size- ");
    scanf("%d", &n);
    int a[n];

    for (int i=0; i<n; i++){
        scanf("%d", &c);
        insert(a, c);
    }

    printHeap(a, size);
}

