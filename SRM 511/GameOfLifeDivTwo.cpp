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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {

		int n = init.size();
		string aux[2];
		aux[0] = init;
		aux[1] = string(n, '0');
		int c = 0;
		for(int i=0;i<T;++i,c = 1-c) {
			cout<<aux[c]<<endl;
			for(int j=1;j<n-1;++j) {
				if(aux[c][j-1] + aux[c][j] + aux[c][j+1] - 3 * '0' >= 2) {
					aux[1-c][j] = '1';
				} else {
					aux[1-c][j] = '0';
				}
			}
			
			if(aux[c][n-1] + aux[c][0] + aux[c][1] - 3 * '0' >= 2) {
				aux[1-c][0] = '1';
			} else {
				aux[1-c][0] = '0';
			}
			
			if(aux[c][n-2] + aux[c][n-1] + aux[c][0] - 3 * '0' >= 2) {
				aux[1-c][n-1] = '1';
			} else {
				aux[1-c][n-1] = '0';
			}
		}
		
		return aux[c];
				
	}
};
