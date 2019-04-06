#include "list.hpp"
using namespace std;

list::list(){
        first = 0;
        first2 = 0;
    }
void list::add(int m,int n){
    node* q;
    q = new node;
    if (!first) {
        node* p;
        p = new node;
        p->data = m;
        p->dlink = q;
        p->link = first;
        first = p;
    }
    else if(first->data != m)
    {
        node* p;
        p = new node;
        p->data = m;
        p->dlink = q;
        p->link = first;
        first = p;
        first2 = 0;
    }
    else {first->dlink = q;
    }
    q->link = first2;
    first2 = q;
    q->data = n;
    
}

void list:: print(){
    node* p;
    node* q;
    p = first;
    while(p != 0)
    {
        cout << p->data << "->";
        q = p->dlink;
        while(q != 0){
            cout << q->data << ",";
            q = q->link;
        }
        p = p->link;
        cout << endl;
    }
}

void list::deg_count(){                               //counting degree of each vertex(p) and store it in p->degree variable
    node* p;
    node* q;
    p = first;
    long int count{};
    while(p)
    {
        q = p->dlink;
        while(q)
        {
            (p->degree)++;
            q = q->link;
        }
        p = p->link;
    }
    p = first;
    node* t;
    while (p) {
        q = p->dlink;
        while (q) {
            t = first;
            while (t) {
                if (q->data == t->data) {
                    q->degree = t->degree;
                    break;
                }
                t = t->link;
            }
            q = q->link;
        }
        p = p->link;
    }
    for (node* p=first; p!=0; p=p->link) {
        count = p->degree+count;
    }
    cout << "avg degree: "<< count/10000 << endl;
}

void list::assign_zc(){
    //counting Zs
    for (node* p = first; p != 0; p = p->link)
    {
        for (node* q = p->dlink; q != 0; q = q->link)
        {
            edge ex;
            ex.v1 = p->data;
            ex.v2 = q->data;
            ex.k1 = p->degree;
            ex.k2 = q->degree;
            node* find;
            find = first;
            while(q->data != find->data){
                find = find->link;
            }
            for (node* r = p->dlink; r != 0; r = r->link)
            {
                if(r->data == q->data)
                    continue;

                for (node* find2 = find->dlink; find2 != 0; find2 = find2->link) {
                    if (r->data == find2->data) {
                        (ex.z)++;
                    }
                }
            }
            e_boxes.push_back(ex);
        }
    }
    
    //deleting extra edges
    for (int i=0; i < e_boxes.size(); i++) {
        for (int j=i+1; j < e_boxes.size(); j++) {
            if((e_boxes[i].v1==e_boxes[j].v2) &&(e_boxes[i].v2==e_boxes[j].v1)){
                e_boxes.erase(e_boxes.begin() + j);
                break;
            }
        }
    }
    
    //counting Cs
    for (int i=0; i< e_boxes.size(); i++) {
        if ((e_boxes[i].k1 == 1) || (e_boxes[i].k2 == 1)) {
            e_boxes[i].c = numeric_limits<float>::infinity();
            continue;
        }
        e_boxes[i].c = 1.0 * (e_boxes[i].z + 1) / min((e_boxes[i].k1 - 1),(e_boxes[i].k2 - 1));
    }

}




