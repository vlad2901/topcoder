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

#define MAX 120
#define DEP 60

using namespace std;

class MagicalGirlLevelTwoDivTwo {
	public:
	
	int xf ,yf;
	int depx[4];
	int depy[4];
	
	
	int back(int x, int y, vector<vector<int> > &a, vector <int> &jumpTypes) {
		//cout<<x<<" "<<y<<endl;

		
		if(a[x][y] == 1) {
			return 1;
		}
		if(a[x][y] == -1) {
			return 0;
		}
		a[x][y] = -1;
		if(x == xf && y == yf) {
			return 1;
		} else {
			for(int j=0;j<jumpTypes.size();++j) {
				int nx, ny;
				for(int i=0;i<4;++i) {
					nx = x + depx[i];
					ny = y + depy[i] * jumpTypes[j];
					if(nx < 0 || nx > MAX || ny < 0 || ny > MAX) {
						return 0;
					}
					if(back(nx, ny, a, jumpTypes)) {
						a[nx][ny] = 1;
						return 1;
					}
				}
				for(int i=0;i<4;++i) {
					nx = x + depx[i] * jumpTypes[j];
					ny = y + depy[i];
					if(nx < 0 || nx > MAX || ny < 0 || ny > MAX) {
						return 0;
					}
					if(back(nx, ny, a, jumpTypes)) {
						a[nx][ny] = 1;
						return 1;
					}
				}
			}
		}
		return 0;
	}
						
			
	
	string isReachable(vector <int> jumpTypes, int x, int y) {
	
		vector<vector<int> >a(MAX+1, vector<int>(MAX+1, 0));
		xf = x + DEP;
		yf = y + DEP;
		
		depx[0] = 1;
		depx[1] = 1;
		depx[2] = -1;
		depx[3] = -1;
		depy[0] = 1;
		depy[1] = -1;
		depy[2] = -1;
		depy[3] = 1;
		
		return back(DEP, DEP, a, jumpTypes) ? "YES" : "NO";
	}
};
