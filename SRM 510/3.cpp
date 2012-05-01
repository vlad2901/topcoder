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

class TheLuckyBasesDivTwo {
public:
	long long find(long long);
	int lucky_base(long long n, int b) {
		int d = 0;
		while(n) {
			if(n % b != 4 && n % b != 7) {
				return 0;
			}
			++d;
			n /= b;
		}
	return d;
	}
};

long long TheLuckyBasesDivTwo::find(long long n) {

	int lucky_no[2] = {4, 7};
	long long nr = 0;
	
	if(n == 4 || n == 7) return -1;
	
	for(int i=0;i<2;++i) {
		for(int j=0;j<2;++j) {
			if((n - lucky_no[i]) % lucky_no[j] == 0 && (n - lucky_no[i]) / lucky_no[j] > max(lucky_no[i], lucky_no[j])) {
				++nr;
			}
		}
	}
	
	for(int b=2;b<=sqrt(n);++b) {
		int d;
		if(d = lucky_base(n, b)) {
			if(d <= 2) {
				break;
			}
			++nr;
		}
	}
	return nr;
}


//Powered by [KawigiEdit] 2.0!