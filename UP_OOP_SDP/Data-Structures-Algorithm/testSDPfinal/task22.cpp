#include<iostream>
#include<vector>
#include<string>
#include<iterator>

const size_t MAX_INPUT_SIZE = 64;

class Graph{
    public:
        void getAll();

        void getSize();
        void getPoints();
        void getLinks();
        void getInterestedPoints();


    private:
        std::vector< std::vector<bool> > m_Matrix;
        std::vector<int> m_PointsArr;
        std::vector<size_t> m_InterestedId;
        size_t m_Size;

        size_t findIdOfPoint(int name)const;
        void resizeMatrix();

        std::vector<int> findPath(int from, int to)const;
};
size_t Graph::findIdOfPoint(int name)const{
    //for(const std::vector<int>::coniterator& itr = m_PointsArr.begin(); itr != m_PointsArr.end(); itr++){
    //}
    size_t arrLen = m_PointsArr.size();
    for(size_t i=0; i<arrLen; i++){
        if(m_PointsArr[i] == name){
            return i;
        }
    }
    throw "Invalid name \n"; //exeption
}

void Graph::resizeMatrix(){
    m_Matrix.resize(m_Size);
    for(size_t i=0; i<m_Size; i++){
        m_Matrix[i].resize(10);
    }
    for(size_t x =0; x<m_Size; x++){
        for(size_t y=0; y<m_Size; y++){
            m_Matrix[x][y] = false;
        }
    }
}
void Graph::getSize(){
    std::cout<<"Point count: ";
    std::cin>>m_Size;
    resizeMatrix();
}
void Graph::getPoints(){
    std::cout<<"Points: ";
    for(size_t i=0; i<m_Size; i++){
        int pointName;
        std::cin>>pointName;
        m_PointsArr.push_back(pointName);
    }
}
void Graph::getLinks(){
    std::cout<<"Link count: ";
    size_t linkCount;
    std::cin>>linkCount;
    for(size_t i=0; i<linkCount; i++){
        int from, to;
        std::string arrow;
        std::cin>>from;
        std::cin>>arrow;
        std::cin>>to;
        if(arrow == "<-->"){
            m_Matrix[from][to] = true;
            m_Matrix[to][from] = true;
        }else if(arrow == "--->"){
            m_Matrix[from][to] = true;
        }else if(arrow == "<---"){
            m_Matrix[to][from] = true;
        }else{
            m_Matrix[from][to] = false;
            m_Matrix[to][from] = false;
        }
    }
}
void Graph::getInterestedPoints(){
    size_t intrCount;
    std::cout<<"Interested points cout: ";
    std::cin>>intrCount;
    for(size_t i=0; i<intrCount; i++){
        int name;
        std::cin>>name;
        size_t id = findIdOfPoint(name);
        m_InterestedId.push_back(id);
    }

}
std::vector<int> findPath(int from , int to){
    //std::vector< std::vector<bool> >

}

void Graph::getAll(){
    getSize();
    getPoints();
    getLinks();
    getInterestedPoints();
}

int main(){
    std::string a;
    //std::cin.getline(a,100);
    std::cout<<a;
}