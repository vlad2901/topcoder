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

class TheAlmostLuckyNumbersDivTwo {
public:
	int find(int, int);
	int has(int n) {
		int a = 0;
		while(n) {
			if(n%10 != 7 && n%10 != 4) {
				++a;
			}
			if(a > 1) return 0;
			n /= 10;
		}
	return 1;
	}
};

int TheAlmostLuckyNumbersDivTwo::find(int a, int b) {
	int nr = 0;
	for(int i=a;i<=b;++i) {
		if(has(i)) {
			++nr;
			cout<<i<<endl;
		}
	}
	
	return nr;
		
}


//Powered by [KawigiEdit] 2.0!