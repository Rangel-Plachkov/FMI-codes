#include <iostream>
using namespace std;
int main(){
    const int functionN = 36;
    int result[functionN];
    cin >> result[0];
    for (int f = 1; f < functionN; f++)
    {
        if (result[f - 1] % 2 == 0)
        {
            result[f] = result[f - 1] / 2;
        }
        else
        {
            result[f] = (result[f - 1] * 3) + 1;
        }
    }
    cout << "f35 = "<< result[functionN - 1] << endl;
}

