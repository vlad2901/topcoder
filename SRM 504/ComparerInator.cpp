#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ComparerInator {
	public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {

		int n = A.size();
		int a, b, ab, ba;
		
		a = b = ab = ba = 0;
		
		for(int i=0;i<n;++i) {
			if(A[i] == wanted[i]) {
				++a;
			}
			if(B[i] == wanted[i]) {
				++b;
			}
			if((A[i]<B[i]?A[i]:B[i]) == wanted[i]) {
				++ab;
			}
			if((A[i]<B[i]?B[i]:A[i]) == wanted[i]) {
				++ba;
			}
		}
		if(a == n || b == n) {
			return 1;
		}
		if(ab == n || ba == n) {
			return 7;
		}
		return -1;
	}
};
