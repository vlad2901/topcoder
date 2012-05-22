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

class StrangeDictionary {
	public:
	double prob_first(string a, string b) {
		if(a == b) {	
			return 1;
		}
		int d = 0, first = 0;
		for(int i=0;i<a.size();++i) {
			if(a[i] != b[i]) {
				++d;
				if(a[i] < b[i]) {
					++first;
				}
			}
		}
		return (double)first/d;
	}
	
	vector <double> getExpectedPositions(vector <string> words) {
		vector <double> sol(words.size(), 0);
		for(int i=0;i<words.size();++i) {

			double exp = 0;
			for(int j=0;j<words.size();++j) {
				exp += 1 - prob_first(words[i], words[j]);
			}
			sol[i] = exp;
		}
		return sol;
	}
};
