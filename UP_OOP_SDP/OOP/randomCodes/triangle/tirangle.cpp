#include<iostream>

class Triangle
{
private:
    int a;
    int b;
    int c;
    int Area;
    bool isValidTriangle(){
        if(a + b > c && a + c > b && b + c > a){
            return true;
        }
        return false;
    }
public:
Triangle(int a, int b, int c);

int getA() const;
int getB() const;
int getC() const;

void setA(int a);
void setB(int b);
void setC(int c);

int Perimeter()const;
void Area();

};

int Triangle::getA() const
{
    return a;
}
int Triangle::getB() const
{
    return b;
}
int Triangle::getC() const
{
    return c;
}

void Triangle::setA(int a)
{
    if(a>99)
   std::cout << "Invalid A!" <<std::endl;
    this->a = a;
}
void Triangle::setB(int b)
{
    if(b>99)
    std::cout << "Invalid B!" << std::endl;
    this->b = b;
}
void Triangle::setC(int c)
{
    if(c>49)
    std::cout << "Invalid C!" << std::endl;
    this->c = c;
}

Triangle::Triangle(int a, int b, int c)
{
    setA(a);
    setB(b);
    setC(c);
    isValidTriangle();
    Area();
}

int Triangle::Perimeter()const
{
    int p;
    p = a + (b + c);
    //std::cout << "The perimeter of the triangle is :" << p << std::endl;
    //this->a = a;
    //this->b = b;
    //this->c = c;
    return p;

}
void Triangle::Area()
{
int semiP;
semiP = Perimeter()/2;
}

int main()
{
    Triangle Q(10, 15, 20);
    std::cout<<Q.Perimeter();
}