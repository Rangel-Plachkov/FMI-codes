#include<iostream>

struct int_array{
    int *arr;
    unsigned int size;
};

int_array filter_evens(const int_array& n){
    unsigned int size = n.size;
    
    int_array res;
    res.size = 0;
    for(int i=0; i<size; i++){
        if(n.arr[i]%2 == 0){
            res.size++;
        }
    }

    res.arr = new int [res.size];
    int id = 0;

    for(int i=0;i<size; i++){
        if(n.arr[i]%2 == 0){
            res.arr[id] = n.arr[i];
            id++;
        }
    }
    return res;
}

int main(){
    int_array v;
    v.size = 5;
    v.arr = new int[v.size];
    v.arr[0] = 5;
    v.arr[1] = 6;
    v.arr[2] = 7;
    v.arr[3] = 8;
    v.arr[4] = 10;

    int_array res = filter_evens(v);
    
    delete v.arr;
    delete res.arr;
    
}