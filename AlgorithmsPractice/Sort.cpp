#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Insertion sort.
 * input:
 * arr - pointer to array.
 * size - size of the array.
*/
void insertionSort(int *a, int size){
    if(size<2)
        return;
    for(int i=1;i<size;i++){
        int j = i-1;
        int temp = *(a+i);
        while(j>=0 && temp < *(a+j)){
            *(a+j+1) = *(a+j);
            j--;
        }
        *(a+j+1) = temp;
    }
}

void insertionSort_Main(){
    int a[] = {5,3,7,9,11,6,1,13,21,2};

    cout<<"Insertion Sort\n";
    cout<<"--------------\n\n";
    cout<<"Before Sorting:\n";
    for(auto i: a)
        cout<<i<<", ";

    insertionSort(a,10);

    cout<<"\n\nAfter Sorting:\n";
    for(auto i: a)
        cout<<i<<", ";
}

/**
 * Bubble sorting algorithm.
 * input:
 * arr - pointer to array.
 * size - size of the array.
*/
void bubbleSort(int *arr, int size){
    for(int j=0;j<size;j++){
        for(int i=0;i<size-j-1;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void bubbleSort_Main(){
    int a[] = {5,3,7,9,11,6,1,13,21,2};

    cout<<"Bubble Sort\n";
    cout<<"--------------\n\n";
    cout<<"Before Sorting:\n";
    for(auto i: a)
        cout<<i<<", ";

    bubbleSort(a,10);

    cout<<"\n\nAfter Sorting:\n";
    for(auto i: a)
        cout<<i<<", ";
}