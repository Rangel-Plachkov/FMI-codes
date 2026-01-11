#include<iostream>

void pivot(int arr[], unsigned int size, int x){
    int* tempS = new int [size];
    int* tempB = new int [size];
    int idS = 0; 
    int idB = 0;

    for(int i=0; i<size; i++){
        if(arr[i] < x){
            tempS[idS] = arr[i];
            idS++;
        }else{
            tempB[idB] = arr[i];
            idB++;
        }
    }

    for(int i=0; i<idS; i++){
        arr[i] = tempS[i];
    }
    for(int i=idS; i<size; i++){
        arr[i] = tempB[i - idS];
    }


    delete tempS;
    delete tempB;
}

int main(){
    int arr[] = {10,200,30,40,5,60};
    pivot(arr,6,30);
    std::cout<<arr[0]<<" ";
    std::cout<<arr[1]<<" ";
    std::cout<<arr[2]<<" ";
    std::cout<<arr[3]<<" ";
    std::cout<<arr[4]<<" ";
    std::cout<<arr[5]<<" ";
}