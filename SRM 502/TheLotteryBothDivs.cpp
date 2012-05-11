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

class TheLotteryBothDivs {
	public:
	int is_suffix(string a, string b) { //testez daca a e sufix al lui b
		if(a.size() > b.size()) {
			return 0;
		}
		for(int i=1;i<=a.size();++i) {
			if(a[a.size() - i] != b[b.size() - i]) {
				return 0;
			}
		}
		return 1;
	}
			
			
	double find(vector <string> goodSuffixes) {
		
		for(int i=0;i<goodSuffixes.size();++i) {
			for(int j=0;j<goodSuffixes.size();++j) {
				if(i != j && i<goodSuffixes.size() && is_suffix(goodSuffixes[i], goodSuffixes[j])) {
					cout<<i<<" "<<j<<endl;
					cout<<goodSuffixes[i]<<" "<<goodSuffixes[j]<<endl;
					goodSuffixes.erase(goodSuffixes.begin() + j);
					if(j < i) {
						--i;
					}
					--j;
				}
			}
		}
		
		double sol = 0;
		
		for(int i=0;i<goodSuffixes.size();++i) {
			sol += pow(10.0, -(double)goodSuffixes[i].size());
		}
		
		return sol;
		
	}	
};
