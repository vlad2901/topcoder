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

class MarbleDecoration {
	public:
	int maxLength(int R, int G, int B) {
		int m1 = max(R, max(G, B));
		int m2 = 0;
		if(m1 == R) {
			m2 = max(G, B);
		}
		if(m1 == G) {
			m2 = max(R, B);
		}
		if(m1 == B) {
			m2 = max(R, G);
		}
		
		if(m1 > m2) return 2*m2 +1;
		return 2 * m2;
	}
};
