#include<iostream>
#include<vector>
using namespace std;

vector<int> rebuild( const vector<int>& input){
    vector<int> result( input.size() );
    for(size_t i=0; i < input.size() ; i++){
        result[i] = -1;
    }
    for(size_t i = 0; i < input.size(); i++){
        int counter = input[i];
        int position = 0;
        
        while(counter != 0){
            if( result[position] == -1){
                counter--;
            }
            position++;
        }
        while(result[position] != -1){
            position++;
        }

        result[position] = i+1;
    }
    return result;

}
void printVector(const vector<int> input){
    for(size_t i = 0; i<input.size(); i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> input = {4,1,1,0,2,3,0,0,0};
    //printVector(input);
    printVector(rebuild(input));

}