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

#define MOD 1000000007

using namespace std;

class TheCowDivTwo {
	public:
	int find(int N, int K) {
		int a[2][1000][1000];
		
		memset(a, 0, sizeof(a));
		
		a[1][1][0] = 1;
		a[0][0][0] = 1;
		a[1][0][0] = 1;
		
		for(int n=2, nl=0;n<=N;++n, nl = 1-nl) {
			for(int k=1;k<=K;++k) {
				for(int r=0;r<N;++r) {
					a[nl][k][r] = a[1-nl][k][r] + a[1-nl][k-1][(N + r - n + 1)%N];
					//cout<<n<<" "<<k<<" "<<r<<" "<<a[nl][k][r]<<endl;
					a[nl][k][r] %= MOD;
				}
			}
		}
		return a[N%2][K][0];
	}
};
