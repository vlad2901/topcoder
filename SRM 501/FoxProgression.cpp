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

class FoxProgression {
	public:
	int theCount(vector <int> seq) {
		if(seq.size() == 1) {
			return -1;
		}
		int ar = seq[1] - seq[0];
		
		int gr = 0;
		
		if(seq[0] != 0 && seq[1] % seq[0] == 0) {
			gr = seq[1] / seq[0];
		}
		
		int isgp = 1;
		int isap = 1;
		
		if(ar == 0) {
			isap = 0;
		}
		
		for(int i=1;i<seq.size() && (isap || isgp);++i) {
			if(seq[i] - seq[i-1] != ar) {
				isap = 0;
			}
			if(seq[i] % seq[i-1] != 0 || seq[i] / seq[i-1] != gr) {
				isgp = 0;
			}
		}
		
		return isap + isgp;
		
	}
};
