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

class WorkingRabbits {
	public:
	double getEfficiency(vector <string> profit) {
		int n = profit.size();
		double sum = 0;
		for(int i=0;i<n;++i) {
			for(int j=0;j<i;++j) {
				sum += profit[i][j]-'0';
			}
		}
		return 2*sum / (n*(n-1));
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
