#include<iostream>
#include "player.h"
#include "game.h"


int main(){
    player A("Ivan","123456",18,100);
    casino game;
    game.play(A);

    std::cout<<A.getMoney();
}
