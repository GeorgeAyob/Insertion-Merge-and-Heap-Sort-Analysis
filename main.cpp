#include <iostream>
#include <cmath>
#include <time.h>
#include<iomanip>
using namespace std;

void HSort(int *, int, int);
void HeapSort(int *, int);
void insertionSort(int * , int);
void merge(int *,int, int , int );
void mergeSort(int * , int , int );


int main()
{
    clock_t start;
    double durationA,durationB,durationC;
    int size[]={100,1000,10000,50000,100000,200000};
    
    cout <<"Input Size" <<setw(30)<< "Insertion Sort (seconds)" <<setw(30)<< "\tMerge Sort (seconds) " <<setw(30)<<"\tHeap Sort (seconds) " <<endl;

    
    for(int i=0;i<6;i++)
    {
        int array[size[i]];
        int n=size[i];
        
        for(int j=0;j<n;j++)
        {
            array[j]=rand()%100 -1;
        }
        
        start = clock();                  // start clock
        insertionSort(array, n-1);       // call function
        durationA = (clock()-start)/ (long double)CLOCKS_PER_SEC; // change to seconds and subtract time take from start and end of clock
        
        start = clock();               //restart clock
        mergeSort(array, 1, n-1);
        durationB = (clock()-start)/ (long double)CLOCKS_PER_SEC;
        
        start = clock();               //restart clock
        mergeSort(array, 1, n-1);
        durationC = (clock()-start)/ (long double)CLOCKS_PER_SEC;
        
    
        cout<<fixed<<setprecision(8);
        cout<<size[i]<<setw(30)<<durationA<<setw(30)<<durationB<<setw(30)<<durationC<<endl;
        
    }
    
}

void insertionSort(int *arr, int n)
{
    int i,j,tmp;
    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
    
    }


void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
    
    else return;
}


void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[200000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}

void HSort(int *arr, int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        HSort(arr, n, largest);
    }
}

void HeapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        HSort(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        HSort(arr, i, 0);
    }
}

/*
 Input Size      Insertion Sort (seconds)            Merge Sort (seconds)         Heap Sort (seconds)
 100                    0.00002000                    0.00002000                    0.00000900
 1000                   0.00103800                    0.00008700                    0.00007900
 10000                  0.14124300                    0.00095900                    0.00092400
 50000                  2.78918900                    0.00534700                    0.00554700
 100000                11.06887900                    0.01132800                    0.01124800
 200000                   47.94948000                    0.02614200                    0.02720100

 
 */
 
