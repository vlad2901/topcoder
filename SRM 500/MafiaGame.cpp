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

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> decisions) {
		int a[500];
		int v=0, maxim = 0;
		
		memset(a, 0, sizeof(a));
		
		for(int i=0;i<decisions.size();++i) {
			++a[decisions[i]];
			if(maxim < a[decisions[i]]) {
				maxim = a[decisions[i]];
			}
		}
		
		
		for(int i=0;i<N;++i) {
			if(a[i] == maxim) {
				++v;
			}
		}
		
		if(v == decisions.size()) {
			return 0;
		}
		
		int aux = v;
		
		while(aux > 1) {
			aux = N % aux;
		}

		if(aux == 1) {
			return 1.0/v;
		}
		return 0;
		
		
		
		
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
