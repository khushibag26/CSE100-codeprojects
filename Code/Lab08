#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;


string optimalParens(const vector<vector<int> > &s, int i, int j) {
    if (i == j) {
        return "A" + to_string(i);
    }
    int k = s[i][j];
    return "(" + optimalParens(s, i, k) + optimalParens(s, k + 1, j) + ")";
}

// implemented the matrixChainOrder psuedocode
pair<int, string> matrixChainOrder(const vector<int> &length) {
    int num = length.size() - 1;
    vector<vector<int> > m(num, vector<int>(num, 0)); 
    vector<vector<int> > s(num, vector<int>(num, -1)); 

    
    for (int l = 2; l <= num; l++) { // l is the chain length
        for (int i = 0; i <= num - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + length[i] * length[k + 1] * length[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; 
                }
            }
        }
    }

    string parenthesisAns = optimalParens(s, 0, num - 1);
    return std::make_pair(m[0][num - 1], parenthesisAns);  
}

void MatrixChain() { // the actual input and output of the user's values will be established here
    int n;

    while (cin >> n) {
        vector<int> length(n + 1);

        for (int i = 0; i <= n; i++) {
            cin >> length[i];
        }

        pair<int, string> answers = matrixChainOrder(length);

        cout << answers.first << endl;
        cout << answers.second << endl;
    }
}

int main() { // returns the values from MatrixChain void type function
    MatrixChain();
    return 0;
}
