#include<iostream>
#include<cstring>

void print(const char* begin, const char* end){
    std::cout<<"kravas";
    for(size_t i = 0; i< end - begin; i++){
        std::cout<<*begin;
    }
}

void print_backwards(const char* begin, const char* end) {
    if (begin >= end)
        return;

    const char* iter = end - 1;

    while( iter >= begin && iter[0] < 33){
        iter--;
    }
    const char* world_end = iter;
    while( iter >= begin && iter[0] > 32){
        iter--;
    }
    const char* world_begin = iter;

    print(world_begin, world_end);

    print_backwards(begin , world_begin);
}

void print_backwards(const char* string){
    print_backwards(string, string + strlen(string));
}

int main() {
    print_backwards("I\tneed a break!");  // Очакван изход: break! a need I
    return 0;   
}
