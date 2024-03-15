#include<iostream>
#include<cstring>

const size_t MAX_RESTRANT_NAME_SIZE = 25;
const size_t MAX_DELIVERY_METHOD_SIZE = 30;

class product{
    private:
        char* name;
    public:
        product(){
            this->name = new char[strlen("unknown") + 1];
            strcpy(this->name , "unknown");
        }
        product(const char* name){
            this->name = new char[strlen(name) + 1];
            strcpy(this->name , name);
        }
        void free(){
            delete []this->name;
        }
        ~product(){
            free();
        }
        void setName(const char* name){
            delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name , name);
        }
        const char* getName() const {
            return this->name;
        }
        void copyFrom(const product& other){
            name = new char[ strlen( other.getName() ) + 1 ];
            strcpy(this->name , other.getName() );
        }
        product&  operator=(const product& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        }

};
class restrant{
    private:
        char name[MAX_RESTRANT_NAME_SIZE];
        int arraySize = 2;
        product* products = new product[this->arraySize];
        int numberOfProducts = 0;
        char deliveryMethod[MAX_DELIVERY_METHOD_SIZE];
    public:
        restrant(){
            //product* products = new product[this->arraySize];
            setName("default");
            setDelivery("default");
        }
        restrant(const char* name){
           setName(name);
        }
        restrant(const char* name , const char* delivery){
            setName(name);
            setDelivery(delivery);
        }
        ~restrant(){
            free();
        }
        void setName(const char* name){
            strcpy(this->name , name);
        }
        void setDelivery(const char* delivery){
            strcpy(this->deliveryMethod, delivery);
        }
        const char* getName()const{
            return name;
        }
        const char* getDelivery()const{
            return deliveryMethod;
        }
        void addProduct(const product& newItem){

            if(arraySize <= (this->numberOfProducts)  ){

                this->arraySize = this->arraySize*2;
                product* productsBuff = new product[this->arraySize];
                for(int i = 0; i<numberOfProducts; i++){
                    productsBuff[i] = products[i];
                }
                free();
                this->products = productsBuff;

                products[numberOfProducts] = newItem;
                productsBuff = nullptr;
                this->numberOfProducts++;

            }else{
                products[numberOfProducts] = newItem;
                this->numberOfProducts++;
            }

        }
        void free(){
            delete []this->products;
        }
        void listProducts()const {
            std::cout<<getName()<<std::endl;
            for(int i = 0; i < this->numberOfProducts; i++){
                std::cout<<i<<". "<<products[i].getName()<<std::endl;
            }
            std::cout<<"Delivery: "<<getDelivery()<<std::endl;
        }
        void copyFrom(const restrant& other){
            strcpy(this->name , other.getName() );
            this->arraySize = other.arraySize;
            this->numberOfProducts = other.numberOfProducts;
            free();
            products = new product[this->arraySize];
            for(int i=0 ; i < this->numberOfProducts ; i++){
                this->products[i] = other.products[i];
            }
            strcpy(this->deliveryMethod, other.deliveryMethod);
        }
        restrant& operator=(const restrant& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        } 
};
class Foodpanda{
    private:
        int arraySize=16;
        int numberOfRestrants = 0;
        restrant* restrants = new restrant[this->arraySize];
    public:

};
int main(){
    product A("A");
    product B("B");
    product C("C");
    product D("D");
    product E("E");
    /*
    product F;
    F.copyFrom(A);
    F = B;
    */

    restrant W("restorant W");
    
    restrant X("restorant X", "wallking");
    X.addProduct(A);
    X.addProduct(B);
    X.addProduct(C);

    restrant Y("restorant Y", "bike");
    Y.addProduct(A);
    Y.addProduct(C);
    Y.addProduct(D);

    restrant Z("restorant Z", "car");
    Z.addProduct(A);
    Z.addProduct(B);
    Z.addProduct(C);
    Z.addProduct(D);
    Z.addProduct(E);
    /*
    restrant Q;
    Q.copyFrom(X);
    Q = Z;
    Q.listProducts();
    */

}
