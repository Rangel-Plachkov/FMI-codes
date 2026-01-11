#include<cstring>

const char* defaulName = "unknown";
const char* defaultPassword = "123456";
const int defaultAge = 0;
const int defaultMoney = 0;

class player{
private:
    char* name;
    char* password;
    int age;
    int money;


public:
    player(){                                                                     
        this->name = new char[strlen(defaulName)+1];
        strcpy(this->name , defaultPassword);

        this->password = new char[strlen(defaultPassword)+1];
        strcpy(this->password , defaultPassword);

        this->age = defaultAge;
        this->money = defaultMoney;
    }
    player(const char* name, const char* password ,int age,int  money ){

        this->name = new char[strlen(name)+1];
        strcpy(this->name , name);

        this->password = new char[strlen(password)+1];
        strcpy(this->password , password);

        this->age = age;
        this->money = money;
    }
     ~player(){
        free();
    }
    void free(){
        delete []name;
        delete []password;
    }
    void setPassword(const char* password){
        delete []this->password;
        this->password = new char [strlen(password)+1];
        strcpy(this->password, password);
    }
    bool checkPassword ( const char* input)const{
        //std::cout<<input<<std::endl;
        //std::cout<<this->password<<std::endl;
        if(     strcmp(this->password , input) == 0     ){
            return true;
        }else{
            return false;
        }
    }
    /*
    char* getPassword()const {
        return this->password;
    }
    */
    void setName(const char* name){
        delete []this->name;
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
    }
    char* getName()const {
        return this->name;
    }
    int getAge()const{
        return this->age;
    }
    void setAge(int age){
        this->age = age;
    }
    int getMoney()const{
        return this->money;
    }
    void setMoney(int money){
        this->money = money;
    }
    void copyFrom(const player& other){
	    this->name = new char[ strlen(other.name) + 1];
	    strcpy(this->name, other.name);

        this->password = new char[ strlen(other.password) +1 ];
        strcpy(this->password, other.password);

	    this->age = other.age;    
        this->money = other.money;
        }
    player& operator=(const player& other){
        if (this != &other){
            
		    free();
		    copyFrom(other);
	    }
	    return *this;
    }
};
