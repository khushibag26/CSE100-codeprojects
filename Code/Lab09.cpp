#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
// #include <map>

using namespace std;

struct MinHeapNode {
    char codes;
    int frequency;
    MinHeapNode* left;
    MinHeapNode* right;

    MinHeapNode(char code, int freq) : codes(code), frequency(freq), left(nullptr), right(nullptr) {}
};

struct Huffman_tree {

    unsigned amountVal; // not adding another limit here
    std::vector<MinHeapNode*> arr; // this here decalres a pointer that is able to make the array dynamically established
};



struct compare {
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return left->frequency > right->frequency;
    }
};

void traverse(MinHeapNode* root, string str, unordered_map<char, string> &huffmanTree) {
    if (root == nullptr)
        return;

    if (!root-> left && !root-> right) {
        huffmanTree[root->codes] = str;
    }

    traverse(root->left, str + "0", huffmanTree);
    traverse(root->right, str + "1", huffmanTree);
}


// Main function
int main() {
    const int size = 6;
    vector<char>code = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequency[size];

    // cout << "Enter frequencies for characters A to F:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> frequency[i];
    }

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeapCode;

    for (int i = 0; i < size; ++i) {
        minHeapCode.push(new MinHeapNode(code[i], frequency[i]));
    }

    while (minHeapCode.size() > 1) {
        MinHeapNode*left = minHeapCode.top(); minHeapCode.pop();
        MinHeapNode*right = minHeapCode.top(); minHeapCode.pop();

        MinHeapNode*insideNode = new MinHeapNode('\0', left->frequency + right-> frequency);
        insideNode->left = left;
        insideNode->right = right;

        minHeapCode.push(insideNode);
    } 

    MinHeapNode*root = minHeapCode.top();

    unordered_map<char, string> huffmanTree;
    traverse(root, "", huffmanTree);

    for (char codes : code) {
        cout << codes << ":" << huffmanTree[codes] << endl;
    }


    // CodesDisplay(codes, frequency, size);

    return 0;
}

