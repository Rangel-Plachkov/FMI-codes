#include<iostream>
#include<cmath>

int calc(int a[5]){
    int sum = 8;
    for (int i = 0; a[i]; ++i)
    sum += i;
    return sum;
}

void f(int * arr1, const int * arr2){
    int *p1 = arr1;
    const int *p2 = arr2;
    while(*p2 >= 0){
        *p1++ = *p2++;
    }
}
struct Point{
    float x,y;  
};
struct Circle{
    Point center;
    float radius;   
};
enum RelativePosition {NO_COMMON_POINTS, 
                        TOUCHING,
                        INTERSECTING,
                        SAME};


RelativePosition findRelativePosition(Circle A, Circle B){
    double distance = sqrt(pow(A.center.x - B.center.x, 2) + pow(A.center.y - B.center.y, 2));

    if(A.center.x == B.center.x && A.center.y == B.center.y && A.radius == B.radius){
        return  SAME;
    }else if((distance - A.radius - B.radius > 0)||
                (distance + A.radius < B.radius)||
                distance + B.radius < A.radius){
        return NO_COMMON_POINTS;
    }else if((distance - A.radius - B.radius == 0) ||
                (distance + A.radius == B.radius) ||
                (distance + B.radius == A.radius)){
        return TOUCHING;
    }else{
        return INTERSECTING;
    }
}                    

int main(){
    // int a[7] = {1, 2, 3};
    // std::cout << calc(a);

    // char text[] = "hello", *p = text;
    // while (*p) std::cout << ++*p++;

    // int *pt;
    // int a[3] = {4, 19, 13};
    // pt = &a[1];
    // pt += 1;
    // std::cout << *pt << std::endl;

    // int A[4] = {-1, -2, -3, -4};
    // int B[4] = {10, 20, 30, -1};
    // f(A, B);

    // for(int i=0; i<4; i++){
    //     std::cout<<A[i] <<" " <<B[i] << '\n';
    // }

    



}