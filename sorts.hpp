#ifndef sorts_hpp
#define sorts_hpp
#include <stdio.h>
#include <vector>
#include <iomanip>
#include"edge.h"
using namespace std;

void quickSort(vector<edge>&arr,long int left,long int right);
void Merge(vector<edge>&arr,long int low,long int high,long int mid);
void MergeSort(vector<edge>&arr,long int low,long int high);
void bubbleSort(vector<edge>&arr,long int left,long int right);
void insertionSort(vector<edge>&arr,long int left,long int right);
void printResult(vector<edge>&arr);
void op_insertion(vector<edge>&arr,long int left,long int right, int n);
void op_bubble(vector<edge>&arr,long int left,long int right, int n);
#endif 
