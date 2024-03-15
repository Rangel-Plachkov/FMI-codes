#include<iostream>
#include<fstream>
#include<cstring>
const int MAX_SIZE = 1024;
bool difference(const char* source){
    std::fstream File(source);
    if(!File.is_open()){
        std::cout<<"Eror on opening 2"<<std::endl;
        return 0;
    }
    int sum,mult;
    File>>sum>>mult;
    File<<sum-mult;
    File.close();
    return 1;
}

bool inputResult(int& numberA,int& numberB, int& numberC){
    std::ofstream outFile("result.txt");
    if(!outFile.is_open()){
        std::cout<<"Eror on opening 1"<<std::endl;
        return 0;
    }

    outFile <<numberA+numberB+numberC<<" ";
    outFile <<numberA*numberB*numberC<<std::endl;
    outFile.close();
    return 1;
}

int lenghtOfFile(const char* source){
    std::ifstream outFile(source);
    if(!outFile.is_open()){
        std::cout<<"Eror on opening 3";
        return -1;
    }
    int counter = -1;
    while(!outFile.eof()){
        char c;
        outFile.get(c);
        counter++;
    }
    return counter;
}
int lenghtOfFileTrue(const char* source){
    std::ifstream outFile(source);
    if(!outFile.is_open()){
        std::cout<<"Eror on opening 3";
        return -1;
    }

    outFile.seekg(0,std::ios::end);
    unsigned counter =outFile.tellg();
    outFile.close();
    return counter;
}
 int main(){
     //zad1
    int numberA,numberB,numberC;
    std::cin>>numberA>>numberB>>numberC;
    inputResult(numberA,numberB,numberC);
    difference("result.txt");
    //zad2
    std::cout<<lenghtOfFile("result.txt");
    //


 }
