#include<iostream>
#include<cstring>
#include<fstream>

const unsigned int MAX_NAME_LEN = 100;

class Pencil{
    private:
        char name[MAX_NAME_LEN+1];
        unsigned int year;
        unsigned int hardening;
    public:
        Pencil(){
            setName("default");
            setYear(0);
            setHardening(0);
        }
        Pencil(const char* name, int year, int hardening ){
            setName(name);
            setYear(year);
            setHardening(hardening);
        }
        void setName(const char* name){
            if( sizeof(name) > 100){
                strcpy(this->name ,"undefined");
            }else{
                strcpy(this->name, name);
            }
        }
        const char* getName()const{
            return this->name;
        }
        void setYear(int year){
            this->year = year;
        }
        const int getYear()const{
            return this->year;
        }
        void setHardening(int hard){
            if(hard>=0 && hard<=14){
                this->hardening = hard;
            }else{
                this->hardening = 0;
            }
        }
        const int getHardening()const{
            return this->hardening;
        }
};
bool insertFile(){
    std::ifstream ifile("pensils.txt");
    if(ifile.is_open() != true ){
        return -1;
    }

    char* input;
    ifile.read(input, '\0');
    std::cout<<input;

    ifile.close();

};
bool exportToFile(const Pencil& array){
    int numberOfPencils = sizeof(array) / sizeof(Pencil);
    std::ofstream ofile("branded.dat" ,std::ios::trunc|std::ios::binary);
        if(ofile.is_open != true){
            return -1;
        }
        for(int i=0;i<numberOfPencils;i++){
            ofile.write(array[i].getName() ,sizeOf(array[i].getName)+1);
            ofile.write(array[i].getYear() ,sizeOf(array[i].getYear)+1);
            ofile.write(array[i].getHardening() ,sizeOf(array[i].getHardening));
        }
        oflie.close();
    
}
int main(){
    insertFile();
    Pencil array[10];
    exportToFile(array)
};