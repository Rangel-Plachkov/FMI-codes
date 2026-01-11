#include<iostream>
#include<cmath>
class interval{
    private:    
        int A;
        int B;
        bool ValidInputCheck(){
            if(this->A > this->B){
                this->A = 0;
                this->B = 0;
            }
        }
        bool isItPrime(int number)const{
            int temp = sqrt(number);
            for(int i=2; i <= temp; i++){  
                if(number%i == 0){
                    return false;
                }
            }
            return true;
        }
        bool isItPalindrome(int number)const{
            int rev=0, rem, temp=number;
             while(temp>0){
                rem = temp%10;
                rev = (rev*10)+rem;
                temp = temp/10;
            }
            if(rev==number){
                return true;
            }else{
                return false;
            }
        }
        bool MatchingNumbersCheck(int number)const{
            bool numbers[10];
            for(int i=1;i<=10;i++){
                numbers[i]=0;
            }
            while (number>0){
                if( numbers[number%10] == 1){
                    return false;
                }else{
                    numbers[number%10]=1;
                    number = number/10;
                }
            }
            return true;
        }
        bool isItPowOfTwo(int number)const{
            if(number<=0){
                return false;
            }
            while(number%2 == 0){
                number=number/2;
            }
            if(number == 1){
                return true;
            }else{ 
                return false;
            }
        }

    public:
        interval(){
            setPoints(0,0);
        }
        interval(int n){
            if(n >= 0){
                setPoints(0,n);
            }else{
                setPoints(n,0);
            }
        }
        interval(int a, int b){
            setPoints(a,b);
        }
        void setPoints(int a ,int b){
            this->A = a;
            this->B = b;
            ValidInputCheck();
        }
        void setA(int a){
            this->A = a;
            ValidInputCheck();
        }
        void setB(int b){
            this->B = b;
            ValidInputCheck();
        }
        int getA() const{
            return this->A; 
        }
        int getB() const {
            return this->B;
        }
        int getLenght()const{
            return this->B - this->A;
        }
        int isItInInterval(int number)const{
            if(this->A <= number && this->B >= number){
                return true;
            }else{
                return false;    
            }
        }
        int primaryNumbersCount()const{
            int counter = 0;
            for(int i=this->A;i<=this->B;i++){
                if(isItPrime(i) == true){
                    counter++;
                }
            }
            return counter;
        }
        int PalindromeCounter()const{
            int counter = 0;
            int startA = this->A;
            if(this->B < 0){
                return counter;
            }
            if(startA < 0){
                startA = 0;
            }                   
            for(int i=startA;i<=this->B;i++){
                if(isItPalindrome(i) == true){
                    counter++;
                }
            }
            return counter;

        }
        int matchingNumbersCounter()const{
            int counter=0;
            for(int i=this->A;i<this->B;i++){
                if(MatchingNumbersCheck(i) == false){
                    counter++;
                }
            }
            return counter;
        }
        bool endsPowsofTwo()const{
            
            if(isItPowOfTwo(this->A) == true ){
                if(isItPowOfTwo(this->B) == true){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
            //return isItPowOfTwo(this->A) && isItPowOfTwo(this->B);
        }
        interval intersect(const interval& secondInterval)const{
            interval result;
            if(this->B > secondInterval.A){    
                result.setPoints(secondInterval.A,this->B);
                return result;
            }
            if(this->A < secondInterval.B){    
                result.setPoints(this->A,secondInterval.B);
                return result;
            }else{
                result.setPoints(0,0);
                return result; 
            }
        }
        interval combinationInterval(const interval& secondInterval)const{ 
            int Start;
            int End;
            interval result;
            if(this->B < secondInterval.A){
                result.setPoints(0,0);
                return result;
            }
            if(this->A > secondInterval.B){
                result.setPoints(0,0);
                return result;
            }

            if(this->A > secondInterval.A){
                Start = this->A;
            }else{
                Start = secondInterval.A;
            }

            if(this->B > secondInterval.B){
                End = this->B;
            }else{
                End = secondInterval.B;
            }
            //std::cout<<Start<<End;
            result.setPoints(Start,End);
            return result; 
        }

        bool isSuperInterval(const interval& secondInterval)const{
            if(this->B >= secondInterval.B && this->A >= secondInterval.A){
                return true;
            }
            return false;
        }
};
int main(){
    interval t1(3,10);
    interval t2(4,14);
    interval t3;
    //std::cout<<t3.getA()<<" "<<t3.getB();
    interval t4(2,16);
    //std::cout<<t4.endsPowsofTwo();
    interval result = t1.intersect(t2);
    //std::cout<<t2.PalindromeCounter();
    //std::cout<<result.getA()<<std::endl;
    //std::cout<<result.getB();
    //std::cout<<t2.isSuperInterval(result);
    //std::cout<<result.primaryNumbersCount();
    //interval resultTwo = t1.combinationInterval(t2);
    //std::cout<<resultTwo.getA()<<" ";
    //std::cout<<resultTwo.getB();
    //std::cout<<t1.combinationInterval(t2).getA()<<" ";
    //std::cout<<t1.combinationInterval(t2).getB();


}
