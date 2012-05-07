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

#define MOD 1000000009
#define INF 1000000

using namespace std;

class YetAnotherIncredibleMachine {
	public:
	int search_left(vector<int> &balls, int x) {
		
		int st=0;
		int dr=balls.size()-1;
		int m, sol = 0;
		
		while(st <= dr) {

			m = (st + dr) / 2;
			if(x >= balls[m]) {
				sol = m;
				st = m+1;
			} else {
				dr = m-1;
			}
		}
		
		return sol;
			
	}
			
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
		long long sol = 1;
		
		balls.push_back(-INF);
		
		sort(balls.begin(), balls.end());
		
		for(int i=0;i<platformMount.size();++i) {
		
			int l = search_left(balls, platformMount[i]);

			
			int r;
			if(l < balls.size()-1) {
				r = balls[l+1];
			} else {
				r = INF;
			}
			
			l = balls[l];
			
			
			int pos = min(platformMount[i]+1, r-platformLength[i]) - max(platformMount[i] - platformLength[i], l+1);
			
			if(pos >= 0) {
				sol *= pos;
			} else {
				return 0;
			}
			
			if(sol > MOD) {
				sol %= MOD;
			}
		}
		return sol;
	}
};
