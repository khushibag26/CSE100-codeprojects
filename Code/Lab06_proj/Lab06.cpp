#include <iostream>
#include <list>
using namespace std;

class HashTab {
private:
    list<int> *hashTab;
    
public:
    HashTab() {
      hashTab = nullptr;
    } // in case hastable isn't the nullptr
    ~HashTab() {
      if (hashTab != nullptr) {
        delete[] hashTab;
      }
    }
  

    void makeHashTab(int size) {
      hashTab = new list<int>[size];
    }
    void insert(int keys, int size) {
      hashTab[keys % size].push_front(keys);
    }

    bool removeKeys(int keys, int size) {
      list<int> &num = hashTab[keys % size];
      auto it = num.begin();
      for (; it != num.end(); it++) {
          if (*it == keys) {
            num.erase(it);
            return true;
          }
      }
      return false;
    }

  void searchNum(int keys, int size) {
      list<int> &num = hashTab[keys % size];
      int place = 0;

      for (const int &item : num) {
        if (item == keys) {
          cout << keys << ":FOUND_AT" << (keys % size) << "," << place << ";" << endl;
          return; 
        }
        place++;
      }
      cout << keys << ":NOT_FOUND;" << endl;
  }




// to help output the correct size
  void output(int size)  {
      for (int i = 0; i < size; i++) {
        cout << i << ":";
          if (!hashTab[i].empty()) {
            for (auto it = hashTab[i].begin(); it != hashTab[i].end(); ++it) {
              if (it != hashTab[i].begin()) {
                cout << "->";
              }
              cout << *it;
            }
            cout << "->;"; 
          } else {
            cout << ";";
          }
          cout << endl;
      }
  }
};


// main driver program
int main() {
    int size, keys;
    char ar;

    cin >> size;
    HashTab table;
    table.makeHashTab(size);

    cin >> ar;
    while (ar != 'e') {
        if (ar == 'i') {
            cin >> keys;
            table.insert(keys, size);
        } else if (ar == 'd') {
            cin >> keys;
            if (table.removeKeys(keys, size)) {
                cout << keys << ":DELETED;" << endl;
            } else {
                cout << keys << ":DELETE_FAILED;" << endl;
            }
        } else if (ar == 's') {
            cin >> keys;
            table.searchNum(keys, size);
        } else if (ar == 'o') {
            table.output(size);
        }
        cin >> ar;
    }

    return 0;
}
