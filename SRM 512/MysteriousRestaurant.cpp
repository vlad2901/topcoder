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

#define MAX 1000000000

using namespace std;

class MysteriousRestaurant {
	public:
	int dollars(char c) {
		if(c >= 'a') {
			return c - 'a' + 36;
		}
		if(c >= 'A') {
			return c - 'A' + 10;
		}
		return c - '0';
	}
	
	int maxDays(vector <string> prices, int budget) {
		int d = prices[0].size();
		int n = prices.size();
        
        while(n) {
			int p = 0;
			cout<<"plan pentru: "<<n<<endl;
			for(int day=0;day<7;++day) {
				int mind = MAX;
				for(int dish=0;dish<d;++dish) {
					int pday = 0;
					for(int i=day;i<n;i+=7) {
						pday += dollars(prices[i][dish]);
					}
					if(mind > pday) {
						mind = pday;
					}
				}
				cout<<"ziua mincost "<<day<<" "<<mind<<endl;
				p += mind;
			}
			cout<<"costa "<<p<<endl;
			if(budget >= p) {
				return n;
			}
			--n;
		}
		return 0;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
