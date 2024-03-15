#include <cmath>
const int min_AGE = 18;
class casino{
private:
    player person;
    void validAge()const{
        if ( person.getAge() < min_AGE ){
            std::cout<<"under age player"<<std::endl;
            exit();
        }
    }
    void bancyptCheck()const{
        if( this->person.getMoney() <= 0){
            std::cout<<"The playes has no money"<<std::endl;
            exit();
        }
    }
    void validatePassword(){
        char* input = new char [256];
        std::cin.getline(input,256,'\n');
        if( person.checkPassword(input) == 0 ){
            std::cout<<"Wrong Password"<<std::endl;
            delete []input;
            exit();
        }
        delete []input;

    }
    int randomNumber()const{
        return 51;/////////////////////////////////////////////////////////////////////////////////////
    }
    void setMoney(int money){
        this->person.setMoney(money);
        bancyptCheck();
        menu();
    }

    bool isItPrimary(int number)const{
        int opt = sqrt(number);
        for(int i=2 ;i<opt;i++){
            if(number%i == 0){
                return false;
            }
        }
        return true;
    }
    bool isItPowOfTwo(int number)const{
        while(number > 1){
            if(number%2 == 1){
                return false;
            }else{
                number = number/2;

            }
        }
        if(number == 1){
            return true;
        }else{
            return false;
        }
    }
    void exit()const{
        std::cout<<"Exiting game"<<std::endl;
        //~casino();
    }
public:
    casino(){
        //player person;
    }

    void evenOdd(int bet , bool guess){
        if( guess == randomNumber() % 2){
            std::cout<<"You win"<<std::endl;
            setMoney(this->person.getMoney() + ((bet*6)/5) );
        }else{
            std::cout<<"You lose"<<std::endl;
            setMoney(this->person.getMoney() - bet);
        }
    }
    void primary(int bet){
        if(isItPrimary( randomNumber() )   ){
            std::cout<<"You win"<<std::endl;
            setMoney(this->person.getMoney() + ((bet*3)/2) );
        }else{
            std::cout<<"You lose"<<std::endl;
            setMoney(this->person.getMoney() - bet);
        }
    }
    void powOfTwo(int bet){
        if( isItPowOfTwo( randomNumber() )   ){
            std::cout<<"You win"<<std::endl;
            setMoney(this->person.getMoney() + (bet*2) );
        }else{
            std::cout<<"You lose"<<std::endl;
            setMoney(this->person.getMoney() - bet);
        }
    }
    void higherLower(int bet, bool higher, int guess){
        int rng = randomNumber();
        if( (guess > rng && higher == true)  || (guess<rng && higher == false) ){
            std::cout<<"You win"<<std::endl;
            setMoney(this->person.getMoney() + (bet/4) );
        }else{
            std::cout<<"You lose"<<std::endl;
            setMoney(this->person.getMoney() - bet );
        }
    }
    void guessNumber(int bet, int guess){
        if( guess == randomNumber() ){
            std::cout<<"You win"<<std::endl;
            setMoney(this->person.getMoney() + (bet*10) );
        }else{
            std::cout<<"You lose"<<std::endl;
            setMoney(this->person.getMoney() - bet);
        }
    }
    void menu(){
        std::cout<<"Welcome "<<person.getName()<<std::endl;
        std::cout<<"Balance: "<<person.getMoney()<<" select action: "<<std::endl;
        std::cout<<"1.Even or Odd"<<std::endl;
        std::cout<<"2.Primary number"<<std::endl;
        std::cout<<"3.Pow of 2"<<std::endl;
        std::cout<<"4.Higher or lower"<<std::endl;
        std::cout<<"5.Number guessing"<<std::endl;
        std::cout<<"x.Exit"<<std::endl;
        char input;
        std::cin>>input;
        if(input == 'x'){
            exit();
        }
        int bet;
        std::cout<<"bet: ";
        std::cin>>bet;
        if(bet <= person.getMoney() ){
            switch(input){
                case '1':
                    bool guessEven;
                    std::cout<<"0 - Even \n 1 - Odd"<<std::endl;
                    std::cin>>guessEven;
                    evenOdd(guessEven , bet);
                    break;
                case '2':
                    primary(bet);
                    break;
                case '3':
                    powOfTwo(bet);
                    break;
                case '4':
                    int guessNum;
                    bool higher;
                    std::cout<<"Select number: ";
                    std::cin>>guessNum;
                    if(guessNum < 20 || guessNum > 60){
                        std::cout<<"Invalid input";
                        menu();
                    }else{
                        std::cout<<"0 - lower or 1 - higher: ";
                        std::cin>>higher;
                        higherLower(bet , higher, guessNum);
                    }
                    break;
                case '5':
                    int guess;
                    std::cout<<"Guess number: ";
                    std::cin>>guess;
                    guessNumber(bet , guess);
                    break;
                case 'x':
                    exit();
                    break;
                default:
                    std::cout<<"Invalid command"<<std::endl;
                    menu();

            }
        }else{
            std::cout<<"Not enough money"<<std::endl;
            bancyptCheck();
            menu();
        }
    }
    void play(player& player){
        this->person = player;
        validatePassword();
        validAge();
        bancyptCheck();
        menu();
    }
};
