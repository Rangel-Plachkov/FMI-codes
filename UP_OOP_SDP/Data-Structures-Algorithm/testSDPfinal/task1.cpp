#include<iostream>
#include<vector>

const size_t MEDCHECK_COUNT = 10;

struct teacher{
    public:
        std::vector<bool> m_checkArr;
        teacher();
        bool finished()const;
        
};

teacher::teacher(){
    for(size_t i=0; i<MEDCHECK_COUNT; i++){
        m_checkArr.push_back(false);
    }
}
bool teacher::finished()const{
    for(size_t i=0; i<MEDCHECK_COUNT; i++){
        if(m_checkArr[i] == false){
            return false;
        }
    }
    return true;
}

class waitingQ{
    public:

    private:
        const size_t M = 10;
        const size_t N = 10;

};

int main(){

}