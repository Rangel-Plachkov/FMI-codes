#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<iterator>

const size_t MAX_INPUT_SIZE = 64;

class Graph{
    public:
        void getAll();

        void getSize();
        void getPoints();
        void getLinks();
        void getInterestedPoints();

        bool interestedPath();
        void printPath()const;
    private:
        std::vector< std::vector<bool> > m_Matrix;
        std::vector<int> m_PointsArr;
        std::vector<size_t> m_InterestedId;
        std::vector<int> m_Path;
        size_t m_Size;

        size_t findIdOfPoint(int name)const;
        void resizeMatrix();

        void bfsRec(std::vector<int>& graph, int currLen, std::queue<int>& Q, size_t toID)const;
        std::stack<size_t> findPath(int fromID, int toID)const;
        void backTrac(const std::vector<int>& graph,size_t currId ,std::stack<size_t>& path)const;
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
        m_Matrix[i].resize(m_Size);
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
void Graph::bfsRec(std::vector<int>& graph, int currLen, std::queue<int>& Q, size_t toID)const{
    if(Q.empty()){
        return;
    }
    size_t currId = Q.back();
    Q.pop();
    graph[currId] = currLen;
    if(currId == toID){
        return;
    }
    for(int i=0 ;i<m_Size; i++){
        if(m_Matrix[currId][i] && graph[i] != -1){
            Q.push(i);
        }
    }
    
    bfsRec(graph, Q,(currLen+1));
}
std::stack<size_t> Graph::findPath(int fromID , int toID)const{
    if(fromID >= m_Size || fromID < 0 || toID >= m_Size || toID < 0){
        return {};
    }
    std::vector<int> temp;
    temp.resize(m_Size);
    for(int i=0; i<m_Size; i++){
        temp[i] = -1;
    }

    std::queue<int> Q;
    Q.push(fromID);
    bfsRec(temp,Q,0);
    
    if(temp[toID] == -1){
        return {};
    }
    std::stack<size_t> pathOfIDs;
    backTrac(temp, toID, pathOfIDs);

}

void Graph::backTrac(const std::vector<int>& graph,size_t currId ,std::stack<size_t>& path)const{
    if(currId == 0){
        return;
    }
    for(size_t i=0; i<m_Size; i++){
        if(m_Matrix[i][currId] && graph[i] == (graph[currId]-1) ){
            path.push(i);
            backTrac(graph, i, path);
            return;
        }
    }
    
}
void Graph::getAll(){
    getSize();
    getPoints();
    getLinks();
    getInterestedPoints();
}
bool Graph::interestedPath(){
    size_t intrPointCount = m_InterestedId.size();
    if(intrPointCount == 0){
        return true;
    }else if(intrPointCount == 1){
        m_Path.push_back(m_PointsArr[ m_InterestedId[0] ]);
    }else{
        for(int i=1; i<intrPointCount; i++){
            std::stack<size_t> temp;
            temp = findPath(i-1,i);
            while( !temp.empty() ){
                m_Path.push_back( m_PointsArr[temp.push()]);
                
                temp.pop();
            }
        }
    }
    return true;
}
void Graph::printPath()const{
    size_t pathLen = m_Path.size();
    for(size_t i=0; i<pathLen; i++){
        std::cout<<m_Path[i];
        if(i != pathLen -1){
            std::cout<<" -> ";
        }
    }
}

int main(){

}