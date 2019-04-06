#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits>
#include<iomanip>
#include"list.hpp"
#include"sorts.hpp"
#include "vertices.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;
char mode{};
int min(int m, int n);
void DFS(vector<edge>&arr,vector<vertices>&v1, int m,list& l1);
void count_Cs(vector<edge>&save);
void linked_list(string file,list& l1,vector<vertices>&v);
void matrix(string file,vector<edge>&save,vector<vertices>&v);
int next(vector<edge>&arr,vector<vertices>&v, list& l1);
int main()
{
    string f_name;
    cout << "Enter your file name: ";
    cin >> f_name;
    string fnm = f_name+ ".txt";
    ofstream output("result.txt");
    list l1;
    vector<edge>save;
    vector<vertices>v;
    vector<bool>vs;
    vertices f;
    f.num = 1;
    v.push_back(f);
    int input{};
    int N{};
    int cnt{};
    
    cout << "1-RUN LinkedList Quick" << endl;
    cout << "2-RUN Matrix Quick" << endl;
    cout << "3-RUN LinkedList Insertion" << endl;
    cout << "4-RUN Mtrix Insertion" << endl;
    cout << "5-RUN LinkedList Merge" << endl;
    cout << "6-RUN Matrix Merge" << endl;
    cout << "7-RUN LinkedList Bubble" << endl;
    cout << "8-RUN Matrix Bubble" << endl;
    cout << "9-RUN LinkedList Optimum Insertion N" << endl;
    cout << "10-RUN Matrix Insertion" << endl;
    cout << "11-RUN LinkedList Optimum Bubble N" << endl;
    cout << "12-RUN Matrix Optimum Bubble N" << endl;
    cout << "choose your number: ";
    cin >> input;
    auto t3 = Clock::now();
    switch (input)
    {
        case 1:
        {
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                quickSort(l1.e_boxes, 0, l1.e_boxes.size()-1);
                cnt = next(l1.e_boxes,v,l1);
            }while(cnt==1);
            //printResult(l1);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 2:
        {
            matrix(fnm, save, v);
            auto t1 = Clock::now();
            do {
                count_Cs(save);
                quickSort(save, 0, save.size()-1);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 3:
        {
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                insertionSort(l1.e_boxes,0,l1.e_boxes.size()-1);
                cnt = next(l1.e_boxes, v,l1);
            } while (cnt == 1);
            //printResult(l1.e_boxes);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 4:
        {
            matrix(fnm, save, v);
            auto t1 = Clock::now();
            do {
                count_Cs(save);
                insertionSort(save,0,save.size()-1);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 5:
        {
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                MergeSort(l1.e_boxes, 0, l1.e_boxes.size() -1);
                cnt = next(l1.e_boxes,v,l1);
            }while(cnt==1);
            
            //printResult(l1.e_boxes);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 6:
        {
            matrix(fnm, save, v);
            auto t1 = Clock::now();
            do {
                count_Cs(save);
                MergeSort(save, 0, save.size()-1);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 7:
        {
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                bubbleSort(l1.e_boxes,0, l1.e_boxes.size()-1);
                cnt = next(l1.e_boxes,v,l1);
            }while(cnt==1);
            //printResult(l1.e_boxes);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 8:
        {
            matrix(fnm, save, v);
            auto t1 = Clock::now();
            do {
                count_Cs(save);
                bubbleSort(save,0, save.size()-1);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 9:
        {
            cout << "Insert N: ";
            cin >> N;
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                op_insertion(l1.e_boxes, 0, l1.e_boxes.size() -1,N);
                cnt = next(l1.e_boxes,v,l1);
            }while(cnt==1);
            //printResult(l1.e_boxes);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 10:
        {
            cout << "Insert N: ";
            cin >> N;
            auto t1 = Clock::now();
            matrix(fnm,save,v);
            do {
                count_Cs(save);
                op_insertion(save, 0, save.size()-1,N);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        case 11:
        {
            cout << "Insert N: ";
            cin >> N;
            linked_list(fnm,l1,v);
            auto t1 = Clock::now();
            do {
                count_Cs(l1.e_boxes);
                op_bubble(l1.e_boxes, 0, l1.e_boxes.size() -1,N);
                cnt = next(l1.e_boxes,v,l1);
            }while(cnt==1);
            
            //printResult(l1.e_boxes);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds"<< endl;
            break;
        }
        case 12:
        {
            cout << "Insert N: ";
            cin >> N;
            matrix(fnm,save,v);
            auto t1 = Clock::now();
            do {
                count_Cs(save);
                op_bubble(save, 0, save.size()-1,N);
                cnt = next(save,v,l1);
            }while(cnt==1);
            //printResult(save);
            auto t2 = Clock::now();
            cout<< "Algorithm time : " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " seconds\n";
            break;
        }
        default:
            cout << "Enter correct number!" << endl;
            break;
    }
    
    cout << "process done!" << endl;
    for (int m=0; m < v.size(); m++) {
        if (v[m].visit)
            v[m].lable = 'A';
    }
    
    for (int j=0; j< v.size(); j++) {
        output << "#" << v[j].num << " : " << v[j].lable << endl;
    }
    output.close();
    auto t4 = Clock::now();
    cout << "Program whole time : " << chrono::duration_cast<chrono::seconds>(t4 - t3).count() << " seconds\n";
    return 0;
}

int min(int m, int n)
{
    if (m<=n)
        return m;
    else
        return n;
}

void count_Cs(vector<edge>&arr){
    for (int i=0; i< arr.size(); i++) {
        if ((arr[i].k1 == 1) || (arr[i].k2 == 1)) {
            arr[i].c = numeric_limits<float>::infinity();
            continue;
        }
        arr[i].c = 1.0 * (arr[i].z + 1) / min((arr[i].k1 - 1),(arr[i].k2 - 1));
    }
}

void matrix(string file,vector<edge>&save,vector<vertices>&v){
    mode = 'm';
    int num1{},num2{};
    int zi{};
    char in{};
    ifstream infile;
    infile.open(file);
    auto t1 = Clock::now();
    while (!infile.eof())
    {
        infile >> num1 >> in >> num2;
        edge e;
        e.v1 = num1;
        e.v2 = num2;
        if (num1 != v[zi].num) {
            vertices v1;
            v1.num = num1;
            v.push_back(v1);
            zi++;
        }
        save.push_back(e);
    }
    auto t2 = Clock::now();
    cout<< "Storing time: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milli seconds\n";
    infile.close();
    //assigning degree of v1
    for (int i = 0; i < save.size(); i = i+zi) {
        zi = 0;
        for (int j=i; save[i].v1 == save[j].v1; j++) {
            save[i].k1 = save[i].k1 + 1;
            zi++;
        }
        for (int x=1; x < zi; x++) {
            save[x+i].k1 = save[i].k1;
        }
    }
    
    //assigning degree of v2
    for (int i=0; i < save.size(); i++) {
        for (int j=0; j < save.size(); j++) {
            if (save[i].v2 == save[j].v1) {
                save[i].k2 = save[j].k1;
                break;
            }
        }
    }
    
    //counting Zs
    for (int i=0; i < save.size() ; i++) {
        for (int j=0; j < save.size(); j++) {
            if ((save[i].v1 != save[j].v1) ||(i==j)) {
                continue;
            }
            for (int m=0; m < save.size(); m++) {
                if (((save[m].v1 == save[i].v2) && (save[m].v2 == save[j].v2)) || ((save[m].v2 == save[i].v2) && (save[m].v1 == save[j].v2))) {
                    (save[i].z)++;
                    break;
                }
            }
        }
    }
    //deleting extra edges
    for (int i=0; i < save.size(); i++) {
        for (int j=i+1; j < save.size(); j++) {
            if((save[i].v1==save[j].v2) &&(save[i].v2==save[j].v1)){
                save.erase(save.begin() + j);
                break;
            }
        }
    }
}
int next(vector<edge>&arr,vector<vertices>&v,list& l1){
    int zi{};
    
    for (int j=0; j < arr.size(); j++) {                                    //mohasebe onayi ke ba hazfe yal Zeshon taghir mikone
        if ((arr[j].v1== arr[0].v1) || (arr[j].v2 == arr[0].v1)) {          //check beshe ke bazam az yeki az ras haye oon edge i ke mikhad
            if(arr[j].v1 == arr[0].v1)                                      //hazf beshe darim ya na
                zi = arr[j].v2;                                             //oon yeki moteghayer save beshe dakhele zi
            else                                                            //bebinim edge i darim ke ras hash zi va oon yeki ras yal hazfi hast
                zi = arr[j].v1;                                             //age dashtim z har 2 yal yeki kam she
            
            for (int m=0; m < arr.size(); m++) {
                if (((arr[m].v1 == arr[0].v2) && (arr[m].v2 == zi)) || ((arr[m].v2 == arr[0].v2) && (arr[m].v1 == zi))) {
                    if (!arr[j].visited && !arr[m].visited) {
                        (arr[j].z)--;
                        (arr[m].z)--;
                        arr[j].visited = true;
                        arr[m].visited = true;
                        break;
                    }}}}}
    if (mode=='l') {
        for (node* p =l1.first; p!= 0 ; p=p->link) {
            if (p->data == arr[0].v1) {
                node* q=p->dlink;
                node* t=q;
                
                for (;q !=0 && (q->data != arr[0].v2); q=q->link)
                {
                    t = q;
                }
                if (t==q) {
                    p->dlink =q->link;
                }
                else
                    t->link = q->link;
            }
            if (p->data == arr[0].v2) {
                node* q=p->dlink;
                node* t=q;
                for (; q !=0 && (q->data != arr[0].v1); q=q->link)
                {
                    t = q;
                }
                if (t==q)
                    p->dlink =q->link;
                else
                    t->link = q->link;
            }
        }
    }
    std::cout << arr[0].v1 << ", " << arr[0].v2 << " : deleted\n";
    arr.erase(arr.begin());
    for (int j=0; j< v.size(); j++){
        v[j].visit = false;
    }
    DFS(arr,v,0,l1);
    for (int j=0; j < v.size(); j++) {
        if (!v[j].visit) {
            return 2;
        }
    }
    return 1;
}
void DFS(vector<edge>&arr,vector<vertices>&v1,int m,list& l1){
    v1[m].visit = true;
    int tmp{};
    if (mode=='m') {
       for (int i = 0; i < arr.size();i++) {
           if(arr[i].v1 == m+1 || arr[i].v2 == m+1)
            {
                if (arr[i].v1 == m+1) {
                    tmp = arr[i].v2;}
                
                else{
                    tmp = arr[i].v1;}
                
                if (!v1[tmp-1].visit) {
                    DFS(arr,v1,tmp-1,l1);
                }
            }
        }
    }
    else if (mode == 'l') {
        node* p;
        //p = l1.get_first();
        p = l1.first;
        while (p->data != m + 1) {
            p = p->link;
        }
        
        for(node* q = p->dlink; q != NULL; q = q->link){
            tmp = q->data -1;
            if (!(v1[tmp].visit)) {
                DFS(arr,v1, tmp, l1);
            }
        }
    }
}
void linked_list(string file, list& l1,vector<vertices>&v){
    mode = 'l';
    ifstream infile;
    infile.open(file);
    int num1{},num2{};
    int zi{};
    char in{};
    auto t1 = Clock::now();
    do {
        infile >> num1 >> in >> num2;
        l1.add(num1, num2);
        if (num1 != zi+1) {
            vertices v1;
            v1.num = num1;
            v.push_back(v1);
            zi++;
        }
    } while (!infile.eof());
    auto t2 = Clock::now();
    
    cout<< "Storing time: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milli seconds\n";
    //counting degree
    l1.deg_count();
    //show genlist with l1.print()
    //counting C and Z
    l1.assign_zc();
    infile.close();
    
}


