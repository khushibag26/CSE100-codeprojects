#include <iostream>
#define INF 2147483647
using namespace std;

void merge(int A[], int p, int q, int r) {
    int num1 = q - p + 1;
    int num2 = r - q;

    int L[num1 + 1];
    int R[num2 + 1];

    for (int i = 0; i <= num1; i++) {
        L[i] = A[p + i - 1];
    } 
    for (int j = 0; j <= num2; j++) {
        R[j] = A[q + j];
    }

    // ADD SENTINELS 
    // got to understand that each value must an increase an place value and still need to understand the difference between both when adding the plus 1 and not adding it inside the paratheses
    L[num1 + 1] = 2147483647;
    R[num2 + 1] = 2147483647;
    // int L[n1 + 1] = std::numeric_limits<int>::max();

    // can't have int i = 0 and int j = 0 as that would mean we are starting from the 1st element of the list which would mean we aren't using the divide and conquer approach

    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++) {  // can add k++ to check what we will get
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        }
        else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {

    // intializing values for 
    int n;
    cin >> n;
    
    // no need of pointers, since we are going to split the sequence list in half
    int array[n]; 
    for (int i = 0; i < n; i++) 
    {
      int list;
      cin >> list;
      array[i] = list;
      
    }  
    
    mergeSort(array, 0, n-1);

    // final step to show merge sort worked
    for (int i = 0; i < n; i++){
        cout << array[i] << ";";
    }

    // the next line made my tests incorrect when applied 
    // cout << endl;
    return 0; 
}
