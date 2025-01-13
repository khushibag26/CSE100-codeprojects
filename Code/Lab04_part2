#include <iostream>
#include <random>

using namespace std;


// Part is showing the part where each number has a partition into groups
int Part(int A[], int p, int r) {
    int value, value1;
    int x = A[r];
    int num = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            num = num + 1;
            value = A[num];
            A[num] = A[j];
            A[j] = value;
        }
    }
    value1 = A[num+1];
    A[num + 1] = A[r];
    A[r] = value1;
    return num + 1; 
}
// here is what the code for the void Random_QuickSort would go in

void Random_QuickSort(int A[], int p, int r) {
    if (p < r) {
        int q = Part(A, p, r); // called in line 6
        Random_QuickSort(A, p, q-1);
        Random_QuickSort(A, q + 1, r);
    }
}

// actual function that check for the floor function and swaps the value according to the least to greatest amount
int Randomized_Partition(int A[], int p, int r, int i) {
    int value = p + rand()%(r-p);
    swap(A[r], A[i]); 
    return Part(A, p, r);
}

int main() {

    int n;
    cin >> n;
// new array pointer, where each n value points to the next one
    int* A = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

// starts to check the second element value in the array list
    int l = 1; 
    Random_QuickSort(A, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << ";";
    }

    return 0;
}
