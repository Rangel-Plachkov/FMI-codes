#include<iostream>
#include<vector>
#include<list>
#include<iterator>

struct Node {
    int value;
    std::vector<Node> children;
};

int sumVector(std::list<Node>& path){
    int sum = 0;
    for(std::list<Node>::iterator itr = path.begin(); itr != path.end(); itr++){
        sum += (*itr).value;
        
        
    }
    return sum;
}
int sumVectorT(const std::vector<Node>& path){
    size_t pathSize = path.size();
    int sum = 0;
    for(int i=0; i<pathSize; i++){
        sum += path[i].value;
    }
    return sum;
}
/*
int pathRec(const Node* currNode, int val, std::vector<Node>& result){
    if(currNode == nullptr){
        return 0;
    }
    size_t childCount = currNode->children.size();
    for(int i=0; i<childCount; i++){

    }
    
}

std::vector<Node> shortestPath(const Node* root){
    if(root == nullptr){
        return {};
    }
    std::vector<Node*> minPath;
    std::vector<Node*> currPath;
    //int minSum = INT::MIN();
}
*/
int main(){
    std::list<Node> vec;
    Node a,b,c;
    a.value= 1;
    b.value = 2;
    c.value = 3;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    std::cout<<sumVector(vec);


}