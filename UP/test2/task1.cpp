#include<iostream>

size_t getSize(){
    int result;
    std::cin>>result;
    if(result < 0){
        result *= -1;
    }
    return result;
}
void getPoints(int* ptrX , int* ptrY,const size_t size){
    for(size_t i=0; i<size;i++){
        std::cin>>ptrX[i];
        std::cin>>ptrY[i];
    }
}
void printTopLeft(int* ptrX, int* ptrY, const size_t size,size_t& x, size_t& y){
    int resultX = 0;
    for(size_t i=0; i<size;i++){
        if(ptrX[resultX] > ptrX[i] ){
            resultX = i;
        }
    }
    int resultY = 0;
    for(size_t i=0; i<size;i++){
        if(ptrY[resultY] < ptrY[i] ){
            resultY = i;
        }
    }
    x = ptrX[resultX];
    y = ptrY[resultY];
    std::cout<<"Top left: ";
    std::cout<<ptrX[resultX]<<" "<<ptrY[resultY];
    std::cout<<std::endl;
}
void printSides(int* ptrX, int* ptrY, const size_t size,int x, int y){
    int resultX = 0;
    for(size_t i=0; i<size;i++){
        if(ptrX[resultX] < ptrX[i] ){
            resultX = i;
        }
    }
    int resultY = 0;
    for(size_t i=0; i<size;i++){
        if(ptrY[resultY] > ptrY[i] ){
            resultY = i;
        }
    }
    
    std::cout<<"side X is: "<<ptrX[resultX]-x<<std::endl;
    std::cout<<"side Y is: "<<y-ptrY[resultY]<<std::endl;
}
int main(){
    size_t inputSize = getSize();
    int* pointsX = new int [inputSize];
    int* pointsY = new int [inputSize];
    
    size_t topLeftX,topLeftY;
    getPoints(pointsX,pointsY,inputSize);
    printTopLeft(pointsX,pointsY,inputSize,topLeftX,topLeftY);
    printSides(pointsX,pointsY,inputSize,topLeftX,topLeftY);
    
    delete pointsX;
    delete pointsY;


}