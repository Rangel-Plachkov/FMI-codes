#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

long long matrix[610][610];
long long N,M,K;
long long bigNum = 999999999;
struct cords{
    int x;
    int y;
    cords(){x = 0;y = 0;};
    cords(int newX,int newY){
        x = newX;
        y = newY;
    }
};
cords hrana[510];
queue<cords> bfs;

long long getShortestPath(int x, int y){
    long long currMin = matrix[x][y];
    if (x > 0 && matrix[x-1][y] >= 0){
        currMin = min(currMin, matrix[x-1][y]);
    }
    if (y > 0 && matrix[x][y-1] >= 0){
        currMin = min(currMin, matrix[x][y-1]);
    }
    if (x < N-1 && matrix[x+1][y] >= 0){
        currMin = min(currMin, matrix[x+1][y]);
    }
    if (y < M-1 && matrix[x][y+1] >= 0){
        currMin = min(currMin, matrix[x][y+1]);
    }
    return currMin;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N>>M>>K;
    for(int x=0; x<N;x++){
        for(int y=0; y<M;y++){
            char currSym;
            cin>>currSym;
            if(currSym == '.'){
                matrix[x][y] = bigNum;
            }else{
                matrix[x][y] = -2;
            }
        }
    }
    for(int i=0; i<K; i++){
        cin>>hrana[i].x>>hrana[i].y;
        matrix[hrana[i].x][hrana[i].y] = bigNum;
        bfs.push(hrana[i]);
    }
    while ( bfs.size() != 0){
        int currX = bfs.front().x;
        int currY = bfs.front().y;
        bfs.pop();
        long long shortest = getShortestPath(currX,currY) + 1;
        matrix[currX][currY] = shortest;
        if( currX > 0 && matrix[currX-1][currY] == -1){
            cords temp(currX-1,currY);
            bfs.push(temp);
        }
        if( currY > 0 && matrix[currX][currY-1] == -1){
            cords temp(currX,currY-1);
            bfs.push(temp);
        }
        if( currX < N-1 && matrix[currX+1][currY] == -1){
            cords temp(currX+1,currY);
            bfs.push(temp);
        }
        if( currY < M-1 && matrix[currX][currY+1] == -1){
            cords temp(currX,currY+1);
            bfs.push(temp);
        }
    }
    int result =0;
    for(int x=0; x<N;x++){
        for(int y=0; y<M;y++){
            cout<<matrix[x][y]<<" ";
            if(matrix[x][y] >= 0){
                result += matrix[x][y];
            }
        }
        cout<<endl;
    }
    cout<<result;

}