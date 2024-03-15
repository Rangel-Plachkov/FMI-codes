#include<iostream>
#include<cstring>
using namespace std;
char arr[732839380714496];
int n;
char letters[26];
int values[26];
void input(){
    cin.getline(arr,732839380714496);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>letters[i];
    }

    for(int i=0; i<n; i++){
        cin>>values[i];
    }


}
int main(){

    input();

    int lenght = strlen(arr);
    int current = 1;
    int sum = 0;
    for(int i=0; i<lenght ; i++){
        if(arr[i] == '+'){
            sum=sum+current;
            current=1;
        }else{
            if(arr[i] == '.'){

            }else{
                char letter=arr[i];
                for(int j=0;j<26;j++){
                    if(letter == letters[j]){
                        current=current*values[j];
                        break;
                    }
                }
            }
        }
    }
    cout<<sum+current;

}
