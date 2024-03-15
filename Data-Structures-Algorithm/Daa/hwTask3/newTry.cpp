#include <string>
#include <vector>
#include <iostream>

using namespace std;

string txt;
vector<int> leftVec, rightVec;

void process() {
    leftVec[0] = 0;
    rightVec[txt.size()-1] = txt.size() - 1;

    for (int i = 1; i < txt.size(); ++i) {
        if (txt[i] != txt[i-1]) leftVec[i] = i;
        else leftVec[i] = leftVec[i-1];
    }

    for (int i = txt.size() - 2; i >= 0; --i) {
        if (txt[i] != txt[i+1]) rightVec[i] = i;
        else rightVec[i] = rightVec[i+1];
    }
}

int length_max_subarray(int i) {
    return rightVec[i] - leftVec[i] + 1;
}

void replace_position(int i) {
    txt[i] = '#';
    int l = leftVec[i], r = rightVec[i];
    for (int j = l; j <= r; ++j) {
        if (j < i) rightVec[j] = i - 1;
        if (j > i) leftVec[j] = i + 1;
    }
    leftVec[i] = rightVec[i] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> txt;
    leftVec.resize(txt.size());
    rightVec.resize(txt.size());
    process();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        size_t queryType, pos;
        cin >> queryType >> pos;
        if (queryType == 1) {
            cout << length_max_subarray(pos) << "\n";
        } else {
            replace_position(pos);
        }
    }
    return 0;
}
