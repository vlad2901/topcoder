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

class SRMCards {
	public:
	int maxTurns(vector <int> cards) {
		sort(cards.begin(), cards.end());
		
		int t = 0;
		
		for(int i=0;i<cards.size();++i) {
			if(i+1 < cards.size() && cards[i] == cards[i+1] - 1) {
				++i;
			}
			++t;
		}
		return t;		
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
