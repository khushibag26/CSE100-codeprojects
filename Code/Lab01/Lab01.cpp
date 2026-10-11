#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

    // intialize values
    int n = 1;  
    cin >> n;

    // intialized the k value that helps to sort and the key value is a placeholder value
    int k = 0;
    int key = 0;

    // the sequence uses a pointer
    int* sequenceList;

    sequenceList = new int[n];

// referenced lab_00 code here
    for (int i = 0; i < n; i++) 
    {
      cin >> sequenceList[i];
    }


// mainfesting this to my main function
// looks like I cannot compare values from a pointer and an integer so I changed my code accordingly
    for (int i = 1; i < n; i++) 
    {
        key = sequenceList[i];
        k = i - 1;
        while (sequenceList[k] > key && k >= 0)  
        {
            sequenceList[k + 1] = sequenceList[k];
            k--;
        }
        sequenceList[k + 1] = key;

       // the code reads each value individually after it is sorted from the lines 27 - 36
        for (int m = 0; m <= i; m++){
            cout << sequenceList[m];
                cout << ";";
        }
        cout << endl;
        // cout and use semicolon and iterate the value and create a new variable
        
    }
        
    // to allocate more space as mentioned from last lab
    delete[] sequenceList;

}
