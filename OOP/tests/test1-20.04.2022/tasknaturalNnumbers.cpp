#include<iostream>
#include<cstring>

class Set{
    private:
        size_t arraySize = 16;  
        long long* numbers = new long long[arraySize];
        char* name;
        size_t numberOfNumbers = 0;
        bool vallidNumberCheck(long long num){
            if(num >= 0){
                return true;
            }else{
                return false;
            }
        }
        void resize(){
            this->arraySize = this->arraySize*2;
            long long* buffArr = new long long [ this->arraySize ];
            for(int i = 0; i<arraySize; i++){
                buffArr[i] = this->numbers[i];
            }
            delete []numbers;
            numbers = buffArr;
            buffArr = nullptr;
        }
    public:
        Set(){
            this->name = new char[ sizeof("Empty set") + 1 ];
            strcpy(this->name , "Empty set");
        }
        Set(const char* name , const long long* array){
            this->name = new char[ sizeof(name) + 1 ];
            strcpy(this->name , name);
            this->numberOfNumbers = sizeof(array)/8;
            while(this->numberOfNumbers >= this->arraySize){
                resize();
            }
            for(int i = 0; i < numberOfNumbers; i++){
                if(vallidNumberCheck ( array[i] ) ){
                    numbers[i] = array[i];
                }else{
                    numbers[i] = 0;
                }
            }
            
        }
        void free(){
            delete []this->name;
            delete []this->numbers;
        }
        ~Set(){
            free();
        }
        void setName(){
            delete []this->name;
            this->name = new char[ sizeof(name) + 1 ];
            strcpy(this->name , name);
        }
        const char* getName()const{
          return this->name;  
        }
        const long long getNumber(int i)const{
            return this->numbers[i];
        }
        const int getArraySize()const {
            return this->arraySize;
        }
        const int getNumberOfNumbers()const{
            return this->numberOfNumbers;
        }
        void setNumber(int num, int index){
            if(vallidNumberCheck (num) ){
                this->numbers[index] = num;
            }
        }
        void copyFrom(const Set& other){
            this->name = new char[ sizeof( other.getName() ) + 1 ];
            strcpy(this->name, other.getName() );
            this->arraySize = other.getArraySize();
            this->numberOfNumbers = other.getNumberOfNumbers();
            numbers = new long long[arraySize];
            for(int i = 0; i<numberOfNumbers;i++){
                setNumber(other.getNumber (i) , i );
            }
        }
        Set& operator=(const Set& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        }

};

int main(){
    long long array[4];
    array[0] = 13;
    array[1] = 1;
    array[2] = 0;
    array[3] = -7;
    Set B("set2" , array);
    std::cout<<B.getNumber(3);
    //std::cout<<sizeof(array);
    //long long i;
    //std::cout<<sizeof(i);

}