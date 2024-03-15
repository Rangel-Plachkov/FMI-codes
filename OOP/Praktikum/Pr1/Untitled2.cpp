#include<iostream>
const int NUMBEROFSTUDENTS=5;
const double MINSCOLARSHIP = 5.50;
struct student{
    int facNumber;
    int year;
    double average;
    bool scholarship = 0;
};
void initStudent(student& a){
    std::cin>>a.facNumber;
    std::cin>>a.year;
    std::cin>>a.average;
}
void printStudent(const student& a){
    std::cout<<"student number: " <<a.facNumber<<std::endl;
    std::cout<<"year: " <<a.year<<std::endl;
    std::cout<<"average grade: " <<a.average<<std::endl;
}

struct group{
    student students[NUMBEROFSTUDENTS];
    double average;
};
void groupAverage(group& gr){
    gr.average=0;
    for(int i=0;i<NUMBEROFSTUDENTS;i++){
        gr.average=gr.average + gr.students[i].average;

    }
    gr.average=gr.average/NUMBEROFSTUDENTS;
}

void scholarshipass(group& gr){
    for(int i=0;i<NUMBEROFSTUDENTS){
        if(gr.students[i].average>=NIMSCOLARSHIP){
            gr.student[i].scholarship = 1;
        }
    }
}
/*
void scholarshipList(){
    double maxGrade=0;
    for(int i=0; i<NUMBEROFSTUDENTS; i++){
            if(gr.average[])
    }

}
*/
int main(){
    group six;
    six.students[1]={10000, 1 , 6.00};
    six.students[2]={10001, 1 , 2.70};
    six.students[3]={10002, 1 , 3.40};
    six.students[4]={10003, 1 , 5.70};
    six.students[5]={10004, 1 , 5.00};
    groupAverage(six);
    std::cout<<six.average;

    /*
    student a;
    initStudent(a);
    printStudent(a);
    */

}
