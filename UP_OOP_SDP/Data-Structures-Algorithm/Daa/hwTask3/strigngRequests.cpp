#include <string>
#include <vector>
#include <iostream>

class CapitalLetters {
public:
    CapitalLetters(const std::string& s) : str(s), left(s.size()), right(s.size()) {
        preprocess();
    }
    
    int length_of_max_subarray(int i) {
        return right[i] - left[i] + 1;
    }
    
    void replace_position(int i) {
        str[i] = '#';
        int l = left[i], r = right[i];
        for (int j = l; j <= r; ++j) {
            if (j < i) right[j] = i - 1;
            if (j > i) left[j] = i + 1;
        }
        left[i] = right[i] = i;
    }
    
private:
    std::string str;
    std::vector<int> left, right;

    void preprocess() {
        left[0] = 0;
        right[str.size()-1] = str.size() - 1;

        for (int i = 1; i < str.size(); ++i) {
            if (str[i] != str[i-1]) left[i] = i;
            else left[i] = left[i-1];
        }

        for (int i = str.size() - 2; i >= 0; --i) {
            if (str[i] != str[i+1]) right[i] = i;
            else right[i] = right[i+1];
        }
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::cin >> input;
    CapitalLetters letters(input);
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        size_t type, pos;
        std::cin >> type >> pos;
        if (type == 1) {
            std::cout << letters.length_of_max_subarray(pos) << "\n";
        } else {
            letters.replace_position(pos);
        }
    }
    return 0;
    int A[10][10];

}

