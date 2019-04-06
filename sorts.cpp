#include "sorts.hpp"
#include<iostream>
using namespace std;
void op_insertion(vector<edge>&arr,long int left,long int right, int n){
    long int i = left, j = right;
    edge tmp;
    double pivot = arr[(left + right) / 2].c;
    while (i <= j) {
        while (arr[i].c < pivot)
            i++;
        while (arr[j].c > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        if (j-left+1 < n) {
            insertionSort(arr, left,j);
        }
    else
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        if (right-i+1 < n) {
            insertionSort(arr, i,right);
        }
        else
            quickSort(arr, i, right);
    }
    
}

void op_bubble(vector<edge>&arr,long int left,long int right, int n){
    long int i = left;
    long int j = right;
    edge tmp;
    double pivot = arr[(left + right) / 2].c;
    while (i <= j) {
        while (arr[i].c < pivot)
            i++;
        while (arr[j].c > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        if (j-left+1 < n) {
            bubbleSort(arr,left, j);
        }
        else
            quickSort(arr, left, j);
    }
    if (i < right)
    {
        if (right-i+1 < n) {
            bubbleSort(arr, i,right);
        }
        else
            quickSort(arr, i, right);
    }
    
}
void quickSort(vector<edge>&arr,long int left,long int right){
    long int i = left;
    long int j = right;
    edge tmp;
    double pivot = arr[(left + right) / 2].c;
    while (i <= j) {
        while (arr[i].c < pivot)
            i++;
        while (arr[j].c > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void insertionSort(vector<edge>&arr,long int left,long int right) {
    
    long int j{};
    edge tmp;
    for (long int i = left+1; i < right-left+1; i++) {
        j = i;
        while ((j > left) && (arr[j - 1].c > arr[j].c)) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}
void Merge(vector<edge>&arr,long int low,long int high,long int mid)
{

    long int i{low}, j{mid + 1}, k{};
    edge temp[high-low+1];

    while (i <= mid && j <= high)
    {
        if (arr[i].c < arr[j].c)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
        arr[i] = temp[i-low];
}

void MergeSort(vector<edge>&arr,long int low,long int high)
{
    long int mid{};
    if (low < high)
    {
        mid=(low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, high, mid);
    }
}
void bubbleSort(vector<edge>&arr,long int left,long int right) {
    bool swapped = true;
    int j = 0;
    edge tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (long int i = left; i < right-left+1 - j; i++) {
            if (arr[i].c > arr[i + 1].c) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

void printResult(vector<edge>&arr){
    cout << "result:" << endl;
    for (int i =0; i < arr.size(); i++) {
        cout << setprecision(3) << arr[i].c << endl;
    }
    
}
