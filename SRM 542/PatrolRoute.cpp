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

class PatrolRoute {
	public:
	int countRoutes(int X, int Y, int minT, int maxT) {
		long long dx[8002], sy[20002];

		memset(dx, 0, sizeof(dx));
		memset(sy, 0, sizeof(sy));
		
		for(int i=1;i<=X;++i) {
			dx[2*i] = (X-i)*(i-1);
		}
		
		for(int i=2;i<=10000;++i) {
			if(i < Y)
				sy[2*i] = (sy[2*(i-1)] + (Y-i)*(i-1)) % MOD;
			else 
				sy[2*i] = sy[2*(i-1)];
			sy[2*i+1] = sy[2*i];
		}

		long long rez = 0;
		
		for(int i=2;i<X;++i) {
			int l = minT - 2*i;
						
			if(l < 1) {
				l = 1;
				if(maxT - 2*i < 0) {
					break;
				}
			}

			rez += dx[2*i] * (MOD + (sy[maxT - 2*i] - sy[l-1]));
			rez %= MOD;
		}
		
		return (int)((rez * 6) % MOD);
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
