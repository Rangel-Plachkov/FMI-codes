/*
#include<iostream>
#include<fstream>
#include<cstring>

size_t getFileSize(std::ifstream& file)
{
	size_t currentPosition = file.tellg();

	//file.seekg(0, ios::end);
	size_t result = file.tellg();
	file.seekg(currentPosition);
	return result;
}


bool duplicate (const char* filePath, const char* newFile, int n){
    //ifstream inputFile(filePath);

    if(!inputFile.is_open ){
        return 0;
        std::cout<<"Failed to open";
    }
    unsigned sizeInput = getFileSize(inputFile);
    //inputFile.getline(sizeInput, );


    //char* copytext[i] = new char [1]


}
int main(){
    duplicate( "myFile.txt","newFile.txt",3);

}
*/