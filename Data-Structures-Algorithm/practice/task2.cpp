#include<iostream>
#include<list>
#include<iterator>

void rearrange(std::list<int>& list){
    if(list.empty()){
        return;
    }
    std::list<int> result;
    for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
        if(   !( (*it) % 2 ) ){
            result.push_back(*it);
            it = list.erase(it);
            --it;
        }
    }
    
    for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
        if(    (*it) % 2 ) {
            result.push_back(*it);
            it = list.erase(it);
            --it;
        }
    }
    list = result;
}

void printList(const std::list<int> list){
    if(list.empty()){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    std::list<int>::const_iterator it = list.begin();
    while(it != list.end() ){
        std::cout<<*it;
        if(it != --list.end()){
            std::cout<<" -> ";
        }
        ++it;
    }
    std::cout<<std::endl;
}

int main(){
    std::list<int> A = {1,2,3,4,5,6,7,8,9,2,5,3,6,5,4,5,5,5,5};

    
    rearrange(A);
    printList(A);

}