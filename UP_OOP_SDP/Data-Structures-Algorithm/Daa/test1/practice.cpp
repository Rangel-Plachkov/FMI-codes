#include <iostream>
#include<algorithm>
#include<string>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string temp[10];
    temp[0] = "oufgr";
    temp[1] = "opgihrp[igr]";
    temp[2] = "0qw-38epouwf";
    temp[3] = "w[gpihwq[vw]]";
    temp[4] = "wqp[gihwqg]";
    temp[5] = "wq[eig0qw]";
    temp[6] = "90-wqiefgh";
    temp[7] = "qow[piuugfh]";

    std::sort(temp, temp+8, [](std::string a ,std::string b){return a[1] > b[1];});
    for(int i=0; i<8; i++){
        std::cout<<temp[i]<<std::endl;
    }

    return 0;
}