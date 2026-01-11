#include<iostream>

#include <stdlib.h>
#include <chrono>
#include <thread>

const size_t MOVING_RANGE = 50;
//MOVING_RANGE трябва да е съобразен спремо размера на конзолата ,когато се изпълнява програмата
const size_t FPS = 60;
// Анимацията има константен брой кадри (MOVING_RANGE * 2), при повече FPS ще се изпълнява по-бързо;

void printSpace(const size_t times){
    for(size_t i=0; i<times; i++){
        std::cout<<" ";
    }
    return;
}

void printVeicle(const size_t distanceFront){
    std::cout<<std::endl;
    printSpace(distanceFront);
    std::cout<<"  _________________________    "<<std::endl;
    printSpace(distanceFront);
    std::cout<<" |   |     |     |    | |  \\  "<<std::endl;
    printSpace(distanceFront);
    std::cout<<" |___|_____|_____|____|_|___\\ "<<std::endl;
    printSpace(distanceFront);
    std::cout<<" |                    | |    \\" <<std::endl;
    printSpace(distanceFront);
    std::cout<<" `--(o)(o)--------------(o)--' " <<std::endl;
    std::cout<<std::endl;
    return;
}
void animation(const size_t FPS, const size_t movingRange){
    size_t counter = 0;
    bool forward = true;
    const size_t timeBetweenFrames = 1000 / FPS;
    while(1){
        printVeicle(counter);
        counter += forward*2-1;
        if(counter == movingRange || counter == 0){
            forward = !forward;
        }
        std::this_thread::sleep_for (std::chrono::milliseconds(timeBetweenFrames));
        system("CLS");
    }
    return;
}

int main(){
    animation(FPS, MOVING_RANGE);
}