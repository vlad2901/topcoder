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

class TheLuckyGameDivTwo {
public:
	int find(int, int, int, int);
	int lucky(int n) {
		while(n) {
			if(n % 10 != 4 && n % 10 != 7) {
				return 0;
			}
			n /= 10;
		}
	return 1;
	}
	
};

int TheLuckyGameDivTwo::find(int a, int b, int jLen, int bLen) {
	
	int l[4748];
	memset(l, 0, sizeof(l));
	
	for(int i=a;i<=b;++i) {
		l[i] = l[i-1] + lucky(i);
	}
	
	int jmax = -1;
	for(int john=a;john+jLen-1<=b;++john) {
		int bmin = 5000;
		for(int brus=john;brus+bLen<=john+jLen;++brus) {
			if(bmin > l[brus+bLen-1] - l[brus-1]) {
				bmin = l[brus+bLen-1] - l[brus-1];
			}
		}
		if(jmax < bmin) {
			jmax = bmin;
		}
	}
	return jmax;
}


//Powered by [KawigiEdit] 2.0!