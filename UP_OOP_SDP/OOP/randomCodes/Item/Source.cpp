#include<iostream>
#include<cstring>
#include<fstream>
class Item{
    private:
        char* name;
        double price;
    public:
        Item(){
            setPrice(0);
            setName("Unknown");
        }
        Item(char* name , double price){
            setPrice(price);
            setName(name);
        }
        void setPrice(double newPrice){
            this->price  = newPrice;
        }
        void setName(char* newName){
            this->name = newName;
        }
        double getPrice()const{
            return this->price;
        }
        char* getName()const{
            return this->name;
        }
};
class Shop{
    private:
        Item* items = new Item[1];
        int numberOfItems = 0; 
    public:
        bool addItem(const Item& item){
            this->items[numberOfItems] =  item;
            this->numberOfItems=this->numberOfItems+1;
            return true;
        }
        bool findItem(const char* itemToFind)const{
            for(int i=0;i<numberOfItems;i++){
                if(items[i].getName() == itemToFind){
                    return true;
                }
            }
            return false;
        }
        bool saveToFile(char* fileName){
            std::ofstream ofile(fileName , std::ios::trunc);
            if( ofile.is_open() ){
                return false;
            }
            for(int i=0;i<numberOfItems;i++){
                //ofile.write(char*);
            }


            return true;
        }
        


};
int main(){
    Item A ("Pesho",10);
    Item B ("Gosho",14);
    Item C ("Ivan",10);
    Item D ("Ivan2",14);
    Shop maazin;
    maazin.addItem(A);
    maazin.addItem(B);
    maazin.addItem(C);
    maazin.addItem(D);
    //std::cout<<maazin.findItem("Ivan2");

}