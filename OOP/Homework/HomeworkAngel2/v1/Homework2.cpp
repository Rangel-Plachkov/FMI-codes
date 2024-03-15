#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

unsigned getFileSize(std::fstream &iFile){          //size_t??? //тук се пробвах да го викна само с ifstream обаче не се компилира
	unsigned currentPosition = iFile.tellg();                     //В такъв влучай просто навсякъде fstream ли въпреки че за самата функция не променям неща
	iFile.seekg(0, ios::end);
	unsigned result = iFile.tellg();
	iFile.seekg(currentPosition);
	return result-1;                          
}

void viewFile(std::fstream& iFile){  //каква е разликата дали го викам обикновенно или по референция
  unsigned currentPosition = iFile.tellg();
  iFile.seekg(ios::beg);
  unsigned size = getFileSize(iFile); //не е завършено
  //cout<<size;
  iFile.clear();                      //сложих го докато дебъгвах още незнам как работи
  /*
  for(int i=0;i<size;i++){
    char symbol = iFile.get();
    
      cout<<symbol<<" "; 
  }*/

  iFile.seekg(ios::beg);
  
  for(int i=0;i<size;i++){            //size-1 защото иначе добавя една екстра точка отзад. Има ли по готино решение? Да го променя ли просто в getSize функцията
    char symbol;
    iFile.read((char*)&symbol , sizeof(char));
    if( (symbol >=  65 && symbol <= 90 ) || (symbol >= 97 && symbol<=122 ) ){
      cout<<symbol;
    }else{
      cout<<".";
    }
  }

  iFile.seekg(currentPosition);
  
}
void change(std::fstream& oFile, int position,const char* newSym){
  unsigned currentPosition = oFile.tellp();

  //unsigned size = getFileSize(oFile);
  oFile.seekp( position - sizeof(char) );
  oFile.write( newSym , sizeof(char));            //неразбирам как работи write защо трябва да е const char* а неможе char

  oFile.seekp(currentPosition);

}

void remove(std::fstream& oFile){
  unsigned currentPosition = oFile.tellp();

  unsigned size=getFileSize(oFile);
  char* text = new char[size];
  char* newText = new char[size];
  oFile.seekp(ios::beg);
  oFile.read( (char*)text ,size-1);
  oFile.seekp(ios::beg);
  strncpy(newText,text,size-1);
  newText[size] = '\0';
  //cout<<text<<endl;
  //cout<<newText<<endl;
  //oFile<<newText;
  oFile.write( (char*)newText ,size);     

  delete []text;
  delete text;                              //Това е ненужно нали?
  delete []newText;
  oFile.seekp(currentPosition);
}
void add(std::fstream& oFile ,char newSym){
  unsigned size=getFileSize(oFile);
  unsigned currentPosition = oFile.tellp();

  char* text = new char[size+1];
  oFile.seekp(ios::beg);
  oFile.read( (char*)text ,size );
  text[size] = newSym;
  oFile.seekp(ios::beg);
  oFile.write( (char*)text ,size+2);     //Тук с проба грешка стигнах до извода че трябва да е +2 но не знам защо не е +1

  delete []text;
  oFile.seekp(currentPosition);
}
void editFile(const char* source){

}
int main(){
  fstream file("file.dat", ios::out | ios::in | ios::binary | ios::trunc);   //ако нямам trunc  и файлът не съществува то тогава няма да се създаде нов
  if(!file.is_open()){
    cout<<"ne se otvarq";
    return 0;
  }
  char str[13] = "efo5i124^ubA";
  file.write((const char*)&str, sizeof(str));   
  
  //change(file,2,'A');
  remove(file);
  remove(file);
  remove(file);
  //add(file , 'B');
  //add(file , 'R');
  //add(file , 'O');
  viewFile(file);
  file.close();

const char* fileOne = "file1.dat";
const char* fileTwo = "file2.dat";
const char* fileThree = "file3.dat";
//char* activeFile = fileOne;
//char* array = new char[];

}