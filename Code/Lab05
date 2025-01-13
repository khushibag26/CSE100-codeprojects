#include <iostream>

using namespace std;

// radix sort is included in the int function
int Radix_Sort(int A[], int d) {
    int big_num = A[0];
    for (int i = 1; i < d; i++) {
        if (A[i] > big_num) {
            big_num = A[i];
        }
    }
    return big_num;
}


void Count_Sort(int A[][10], int B, int j) {
    int user_answer[B][10]; // output array to hold sorted values
    int counting[10] = {0}; 

    // store the count of occurrences of each digit at digit place j
    for (int i = 0; i < B; i++) {
        int digit = A[i][j]; // get the digit at the current place
        counting[digit]++; // increment count for the digit
    }

    // checks each 10 values
    for (int i = 1; i < 10; i++) {
        counting[i] += counting[i - 1];
    }

    for (int i = B - 1; i >= 0; i--) {
        int digit = A[i][j]; 
        for (int k = 0; k < 10; k++) { 
            user_answer[counting[digit] - 1][k] = A[i][k];
        }
        counting[digit]--; 
    }

    
    for (int i = 0; i < B; i++) {
        for (int k = 0; k < 10; k++) {
            A[i][k] = user_answer[i][k]; 
        }
    }
}


void radixSort(int A[][10], int B) {
    int max = Radix_Sort(A[0], B); 

    // counting sort for the order of significant number
    for (int j = 9; j >= 0; j--) {
        Count_Sort(A, B, j);
    }
}

int main() {
    int B;
    cin >> B; 

    int A[B][10]; 

    
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j]; 
        }
    }

    
    radixSort(A, B);

    
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j]; 
            if (j != 9) cout << ";"; 
        }
        cout << ";" << endl; 
    }

    return 0; 
}
