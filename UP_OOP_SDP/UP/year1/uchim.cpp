#include<iostream>
//#include<cassert>
#include<cstring>
//using namespace std;
int main(){
    //cout<<sizeof(bool);
    //cout<<(char)(1.52 + 56.2);
    //cout<<static_cast<int>(13.7+52.06);
    //cout<<(int)'F';
    /*dl;
    cout<< &arr<<endl;
    cout<< &arr[0]<<endl;
    cout<< &arr[1]<<endl;
    */

    /*
    int
    switch(n){
        case 1:
            break;
        case 2:
            break;
        default:
            break;

    }
    */
    /*
    int arr[5]={0,1,2,3,4};
    int prom = 7;
    cout<< arr<<ena = 5;
    int b = 7;
    int* y = &a;
    y = &b;
    cout<<*y;
    */
    /*
    int a = 5;
    int c = 6;
    int &b = a;
    b = c;
    //b = a;
    //a = 7;
    cout<<b;
    */

    /*
    char str[10];
    char strB[10];
    cin.getline(str,50);
    cout<<str;
    cout<<strlen(str);
    strncat(<str1>, <str2>, n);//Прехвърля n символа или е достигнат края на str2.
    strcpy(str1, str2);
    strstr(<str1>, <str2>) //tryrsi masiv v masiv
    strchr(<str1>, <expr>) //truci char v cstring
    strspn(<str1>, <str2>) //дължината на низа до първия различен символ.
    atoi(<str>) Преобразуване на низ в цяло число
    atof(<str>) Преобразуване на низ в realno число
    */

    //new
    //delete
    
    int* i = new int;
    *i = 5;
    std::cout<<*i;
    delete i;
    std::cout<<*i;
    
   //std::cout<<"hello";

}
