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

class FiveHundredEleven {
	public:
	int a[51][512], n;
	int can_win(int p, int m, vector<int> &c) {
		//cout<<p<<" "<<m<<endl;
		if(m == 511) return 1;
		if(p == n) return 0;
		if(a[p][m] != -1) return a[p][m];

		int nr = 0;
		
		for(int i=0;i<n;++i) {
			if((m | c[i]) == m) { 
				//s-ar putea sa fi jucat cartea i
				++nr;
			} else {
				if(!can_win(p+1, m | c[i], c)) {
					a[p][m] = 1;
					return 1;
				}
			}
		}
		
		if(p < nr) { 
			// exista carti nejucate care nu modifica memoria
			if(!can_win(p+1, m, c)) {
				a[p][m] = 1;
				return 1;
			}
		}
		a[p][m] = 0;
		return 0;
	}	
				
	
	string theWinner(vector <int> cards) {
		n = cards.size();
		memset(a, -1, sizeof(a));
		if(can_win(0,0, cards)) {
			return "Fox Ciel";
		}
		return "Toastman";
	}
};
