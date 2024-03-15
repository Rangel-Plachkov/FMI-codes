#include<iostream>
#include<fstream>
#include<cstring>
const int NUMBEROFTASKS = 4;

struct Task{
    char* name;
    char* text;
    int points;


    Task(const char* name,const char* text, const int points){
        this->name = new char[100];
        strcpy(this->name ,name);
        this->text = new char[100];
        strcpy(this->text, text);
        this->points = points;
    }

    ~Task(){
        delete[] name;
        delete[] text;
    }
    void changeName(const char* newName){
         delete[] name;
        name = new char[100];
        strcpy(this->name ,newName);
    }
    void changeText(const char* newText){
         delete[] text;
        text = new char[100];
        strcpy(this->text ,newText);
    }
    void changePoints(int points){
        this->points = points;
    }
    void printTask(){
        std::cout<<name<<std::endl;
        std::cout<<text<<std::endl;
        std::cout<<"Points: "<<points<<std::endl<<std::endl;
    }
};


struct Test{
    Task Tasks[NUMBEROFTASKS];
    int passBar;
    Test(){
        passBar=20;
    }

    void addTask(const char* name, const char* desc, int pnts, int index){
        Tasks[index] = Task(name, desc, pnts);
    }

    void writeToFile(){
        ofstream outputFile("test.txt");

    }
    void changeMin(int newBar){
        passBar=newBar;
    }
    int getMax(){
        return Tasks[0].points + Tasks[1].points + Tasks[2].points + Tasks[3].points;
    }
};


int main(){
    Task a("zad1","testtesttest",7);
    Task b("zad2","222222222222",12);
    Task c("zad3","tes135346324646",17);
    Task d("zad4","qqqqqqqqqqqqqqqqqqq",1);

    a.cPrintTask();
    b.cPrintTask();
    b.changeName("zele");
    b.cPrintTask();

    Test testOne;
    std::cout<<testOne.getMax();



}
