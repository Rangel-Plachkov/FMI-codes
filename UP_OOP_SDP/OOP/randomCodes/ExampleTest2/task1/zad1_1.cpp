#include<iostream>
#include<cstring>

using namespace std;

class veichle{
    private:
        size_t maxSpeed;
        char* name;
        void free(){
            delete []name;
        }
        void copyFrom(const veichle& other){

            setMaxSpeeed(other.getMaxSpeed() );
            
            name = new char[ strlen(other.getName() ) ];
            strcpy(name , other.getName() );
        }
        virtual bool isValidMaxSpeed(const size_t newMaxSpeed)const{
            return true;
        }
        
    public:
        virtual size_t speedOnHighway()const{
            return maxSpeed;
        }
        virtual size_t speedOnSpeedway()const{
            return maxSpeed;
        }
        virtual size_t speedOnThirdClass()const{
            return maxSpeed;
        }
        veichle(const size_t newMaxSpeed , const char* newName){
            
            maxSpeed = newMaxSpeed;
            if(newName == nullptr){
                name = nullptr;
            }else{
                
                name = new char[ strlen(newName) + 1];
                strcpy(name , newName);
            }
            
        }
        veichle(const veichle& other){
            copyFrom(other);
        }
        veichle(){
            maxSpeed = 0;
            name = nullptr;
        }
        ~veichle(){
            free();
        }
        veichle& operator=(const veichle& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        }

        void setMaxSpeeed(int newMaxSpeed){
            
            if( isValidMaxSpeed(newMaxSpeed) ){
                maxSpeed = newMaxSpeed;
            }else{
                maxSpeed = 0;
            }
            //cout<<"aqaaaa";
        }
        void setName(const char* newName){
            delete []name;
            if(newName == nullptr){
                name = nullptr;
            }else{
                name = new char[ strlen(newName) ];
                strcpy(name , newName);
            }
        }
        const char* getName()const{
            return name;
        }
        size_t getMaxSpeed()const{
            return maxSpeed;
        }
};

class car: public veichle{
    protected:
        bool isValidMaxSpeed(size_t newMaxSpeed)const{
            if(newMaxSpeed < 180 || newMaxSpeed > 240){
                return false;
            }else{
                return true;
            }
        }
    public:
        car(const size_t newMaxSpeed, const char* newName) : veichle(newMaxSpeed, newName){
            setMaxSpeeed(newMaxSpeed);
        }
        size_t speedOnHighway()const{
            return getMaxSpeed();
        }
        size_t speedOnSpeedway()const{
            return getMaxSpeed();
        }
        size_t speedOnThirdClass()const{
            return getMaxSpeed();
        }
};
class miniVan: public veichle{
    protected:
        bool isValidMaxSpeed(size_t newMaxSpeed)const{
            if(newMaxSpeed < 120 || newMaxSpeed > 260){
                return false;
            }else{
                return true;
            }
        }
    public:
        miniVan(int newMaxSpeed,const char* newName) : veichle(newMaxSpeed, newName){
            setMaxSpeeed(newMaxSpeed);
        }
        size_t speedOnHighway()const{
            return getMaxSpeed();
        }
        size_t speedOnSpeedway()const{
            return getMaxSpeed()/2;
        }
        size_t speedOnThirdClass()const{
            return getMaxSpeed()/3;
        }
};
class truck: public veichle{
    protected:
        bool isValidMaxSpeed(size_t newMaxSpeed)const{
            if(newMaxSpeed < 80 || newMaxSpeed > 140){
                return false;
            }else{
                return true;
            }
        }
    public:
        truck(int newMaxSpeed,const char* newName) : veichle(newMaxSpeed, newName){
            setMaxSpeeed(newMaxSpeed);
        }
        size_t speedOnHighway()const{
            return getMaxSpeed()/2;
        }
        size_t speedOnSpeedway()const{
            return getMaxSpeed()/4;
        }
        size_t speedOnThirdClass()const{
            return 10;
        }
};
class garage{
    private:
        static const size_t DEFAULT_STARTING_SIZE = 16;
        size_t arrSize;
        size_t numberOfCars;
        

        void copyFrom(const garage& other){
            arrSize = other.arrSize;
            numberOfCars = other.numberOfCars;
            for(int i = 0; i<arrSize; i++){
                veichles[i] = other.veichles[i];
            }
        }
        void free(){
            delete []veichles;
        }
        void resize(){

        }
    public:
    veichle** veichles;
        garage(){
            arrSize = DEFAULT_STARTING_SIZE;
            numberOfCars = 0;
            veichles = new veichle* [arrSize];
        }
        garage(const garage& other){
            copyFrom(other);
        }
        ~garage(){
            free();
        }
        garage& operator=(const garage& other){
            if(this != &other){
               free();
               copyFrom(other); 
            }
            return *this;
        }
        void addVeicle(const veichle& newVeichle){
            if(numberOfCars+1 > arrSize ){
                resize();
            }
            
            veichles[numberOfCars] =new veichle( newVeichle );
            numberOfCars++;
            
        }
        void list()const {
            for(int i=0;i<numberOfCars;i++){
                std::cout<<veichles[i]->getName()<<std::endl;
            }
        }
        


};

int main(){
    //veichle o(1,"kur");
    car A(200 ,"audi");
    miniVan B(120 ,"VMW");
    truck C(100 ,"kamion");
    garage gar;
    
    gar.addVeicle(A);
    gar.addVeicle(B);
    gar.addVeicle(C);
    //gar.list();
    cout<<gar.veichles[2]->speedOnHighway();
    
}