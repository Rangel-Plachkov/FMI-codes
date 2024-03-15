#include<iostream>
#include<queue>
#include<string>

struct ppl{
    int age;
    std::string name;

    bool operator<(const ppl& other){
        return age < other.age;
    }
}

int main(){
    std::priority_queue<ppl> pq;
    //std::ios_base::sync_with_stdio(false);
    //td::sort(numbers.begin(), numbers.end());

    std::cout<<pq.top();
    pq.pop();
    std::cout<<pq.top();
}