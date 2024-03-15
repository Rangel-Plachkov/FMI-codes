#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>

#include"user/user.h"
#include"user/user.cpp"

#include"library/library.h"
#include"library/library.cpp"




//! Максимален размер на input  при login
const size_t MAX_INPUT = 100;
//! user който се използва при грешни данни в login
const user Guess("Guest" , "guest" , 0);

size_t numberOfUsers = 8;
user* users = new user[numberOfUsers];
library lib;

//! Функция login която връща user-a който си е въвел данните. Ако те са грешни автоматично връща guess който не е админ
const user& login(){
    
    char input[MAX_INPUT];
    std::cout<<"Username: ";
    std::cin>>input;
    for(int i=0; i<numberOfUsers; i++ ){
        if( users[i].checkUsername(input) == true ){
            std::cout<<std::endl;
            std::cout<<"Password: ";

            char secInput[MAX_INPUT];
            std::cin>>secInput;

            if( users[i].checkPassword(secInput) == false ){

                std::cout<<"Wrong password!"<<std::endl;
                std::cout<<"Login as guest"<<std::endl;
                std::cout<<std::endl;
                return Guess;

            }else{
                std::cout<<"Welcome, "<<users[i].getUsername();
                std::cout<<std::endl;
                return users[i];
            }
        }       
    }
    std::cout<<"Username not found!"<<std::endl;
    std::cout<<"Login as guest"<<std::endl;
    std::cout<<std::endl;
    return Guess;
} 
int main(){

    users[0].setAll("Admin" , "admin" , 1);
    users[1].setAll("Ivan" , "123456" , 1);
    users[2].setAll("Nikolai","cubaBuba",0);
    users[3].setAll("Pesho","pesho123",0);
    users[4].setAll("Gosho" , "password" , 1);
    users[5].setAll("Mitko" , "000000" , 0);
    users[6].setAll("Ivo","ivo20102002",1);
    users[7].setAll("Papagal","wgopuwgog(^2871280g",0);

    Guess.createUserFile();
    book Bone("midas","myth","books/midas.txt","golden touch",3.7,"11111111");
    book Btwo("moonLanding","history.com","books/moonLanding.txt","1969 moonlading",4.8,"2222222");
    book Bthree("Elizabeth2","britannica.com","books/queenElizabeth.txt","The queen of england",1.8,"333");
    
    book Bfour("TheGreatGatsby","F. Fitzgerald","books/TheGreatGatsby.txt","book sumunary",5.0,"44444444444");
    book Bfive("Sonnets","Willian Shekspere","books/sonnets.txt","some SHekespere sonnets",4.9,"55555555");

    //Bone.createBookInfoFile();
    //Btwo.createBookInfoFile();

    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    lib.addBook(Bfour);
    lib.addBook(Bfive);
    //std::cout<<"KRAI";

    //std::cout<<Bfive.getIsbn();


    lib.menu( login() );
     
//}