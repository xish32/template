#include<bits/stdc++.h>
using namespace std;
int main() {
//	         0  1  2  3  4  5  6  7  8  9  10 11
  int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
 
  cout << (lower_bound(a, a + 12, 4) - a) << endl; //输出 9
  cout << (upper_bound(a, a + 12, 4) - a) << endl; //输出 12
  cout << (lower_bound(a, a + 12, 1) - a) << endl; //输出 0
  cout << (upper_bound(a, a + 12, 1) - a) << endl; //输出 3
  cout << (lower_bound(a, a + 12, 3) - a) << endl; //输出 6
  cout << (upper_bound(a, a + 12, 3) - a) << endl; //输出 9
  cout << (lower_bound(a, a + 12, 5) - a) << endl; //输出 12
  cout << (upper_bound(a, a + 12, 5) - a) << endl; //输出 12
  cout << (lower_bound(a, a + 12, 0) - a) << endl; //输出 0
  cout << (upper_bound(a, a + 12, 0) - a) << endl; //输出 0
 
  return 0;
}

