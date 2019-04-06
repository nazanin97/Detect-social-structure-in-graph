#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include<iomanip>
#include<iostream>
#include <vector>
#include"edge.h"
#include"node.h"
#include<limits>

using namespace std;

class list {
public:
    node* first;
    node* first2;
    vector<edge>e_boxes;
    list();
    void deg_count();
    void add(int m,int n);
    void print();
    void assign_zc();
};

#endif 
