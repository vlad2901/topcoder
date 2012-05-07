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

class MagicalGirlLevelOneDivTwo {
	public:
	double theMinDistance(int d, int x, int y) {
		int dx = 0, dy = 0;
		if(x > d) {
			dx = x - d;
		}
		if(x < -d) {
			dx = -x - d;
		}
		if(y > d) {
			dy = y - d;
		}
		if(y < -d) {
			dy = -y - d;
		}
	
	return sqrt(dx*dx + dy*dy);
	}
};
