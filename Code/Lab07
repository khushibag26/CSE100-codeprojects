#include <iostream>
#include <vector>
#define INF -2147483647

using namespace std;

vector<vector<int> > cutRod(vector<int>& q, int length) {
  vector<vector<int> > num(2, vector<int>(length + 1, 0));

  for (int i = 1; i <= length; i++) {
    int sum = -1;
    for (int j = 1; j <= i; j++) {
      if (sum < q[j] + num[0] [i - j]) {
        sum = q[j] + num[0] [i - j];
        num[1] [i] = j;
      }
    }
    num[0] [i] = sum;
  }
  return num;
}
// int BottomUp (int* price, int n, int* rev, int *srod) {

  
  // Khushi's previous code
//  for (int j = 1; j <= n; j++) {
//     int q = -2147483647;

//     for (int i = 1; i <= j; i++) {
//       if (q < price[i - 1] + rev[j - i]) {
//         q = price[i - 1] + rev[j - i];
//         srod[j] = i;
//       }
//     }
//     rev[j] = q;
//   }

//   int A[n+1] = {0};
//    // cin >> p[i]; // move the p[i] in the beginning of the for loop?
//   for (int i = 1; i <= n; i++) {
//     int max_amount = 0;
//     for (int j = 0; j < i; j++) {
//       max_amount = max(max_amount, price[j] + A[i - j - 1]);
//     }
//     A[i] = max_amount; // remember there must be some type of array that points to another int value
//   }

//   return A[n];

// }
  

void Solution(vector<int> & q, int length){
  vector<vector<int> > print = cutRod(q, length);
  vector<int>& priceOne = print[0];
  vector<int>& priceTwo = print[1];
  
  cout << priceOne[length] << endl;
  while (length > 0) {
    cout << priceTwo[length] << " ";
    length = length - priceTwo[length];
  }
  cout << "-1\n";
}


int main(int argc, char**argv) {
  int length;

  cin >> length;

  vector<int> q(length + 1, 0);

  // when I removed the equal sign only values that are less than the given size where allowed to be entered
  for (int i = 1; i <= length; i++) {
        cin >> q[i];
  }
  Solution(q, length);
  return 0;

}
