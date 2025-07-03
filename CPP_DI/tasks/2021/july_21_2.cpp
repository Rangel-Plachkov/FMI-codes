#include<iostream>
#include<vector>
#include<queue>
#include<set>


const size_t ROW_COUNT_M = 6;
const size_t COL_COUNT_N = 6;

struct cords{
    size_t x,y;
    cords() = default;
    cords(size_t x, size_t y): x(x), y(y){}
    bool operator==(const cords& other) const {
        return x == other.x && y == other.y;
    }
    bool operator<(const cords& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

std::vector<cords> getNeibours(const cords& currCords) {
    std::vector<cords> result;

    if (currCords.x > 0)
        result.push_back({currCords.x - 1, currCords.y});

    if (currCords.x + 1 < ROW_COUNT_M)
        result.push_back({currCords.x + 1, currCords.y});

    if (currCords.y > 0)    
        result.push_back({currCords.x, currCords.y - 1});

    if (currCords.y + 1 < COL_COUNT_N)
        result.push_back({currCords.x, currCords.y + 1});

    if (currCords.x > 0 && currCords.y > 0)
        result.push_back({currCords.x - 1, currCords.y - 1});

    if (currCords.x > 0 && currCords.y + 1 < COL_COUNT_N)
        result.push_back({currCords.x - 1, currCords.y + 1});

    if (currCords.x + 1 < ROW_COUNT_M && currCords.y > 0)
        result.push_back({currCords.x + 1, currCords.y - 1});

    if (currCords.x + 1 < ROW_COUNT_M && currCords.y + 1 < COL_COUNT_N)
        result.push_back({currCords.x + 1, currCords.y + 1});

    return result;
}

std::set<cords> getSectionByCords(const cords& newCords, const std::vector<std::vector<int>>& matrix) {
    std::set<cords> result;
    std::queue<cords> q;

    q.push(newCords);
    result.insert(newCords);

    while (!q.empty()) {
        cords head = q.front();
        q.pop();

        std::vector<cords> neighbours = getNeibours(head);
        for (const auto& i : neighbours) {
            if (matrix[i.x][i.y] != 0 && result.find(i) == result.end()) {
                result.insert(i);
                q.push(i);
            }
        }
    }

    return result;
}
int main(){

    std::vector<std::vector<int>> matrix(ROW_COUNT_M, std::vector<int>(COL_COUNT_N, 0));
    
    


}