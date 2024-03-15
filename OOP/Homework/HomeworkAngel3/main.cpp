/*
#include<iostream>
//#include"set.h"
int main(){
//Set a;
//std::cout<<a.numberOfWords;

char* name = "wiueguohewohwfwef";
//std::cout<<name;
name = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA ";
std::cout<<name;
}
*/
#include<iostream>

class student{
    private:
        int age;            //>18 //<60
        int grade;             //>2    <6
    public:
        student (int age, int grade){
            setAge(age);
            this->grade = grade;
        }
        void setAge(int age){
            if(age>18 && age<60){
                this->age = age;
            }
        }
        int getAge()const{
            return this->age;
        }

 
};
int main(){
    student A(17,100);
    //A.grade = 7;
    A.getAge();




}