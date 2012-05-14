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

#define MAX_DIST 1500000

using namespace std;

class KingdomXCitiesandVillagesAnother {
	
	double dist(int x1, int y1, int x2, int y2) {
		return sqrt((double)(x2-x1)*(x2-x1) + (double)(y2-y1)*(y2-y1));
	}
	
	public:
	
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
	
		double d[50];
		double cost = 0.0;
		
		for(int i=0;i<villageX.size();++i) {
			double minim = MAX_DIST;
			for(int j=0;j<cityX.size();++j) {
				minim = min(minim, dist(villageX[i], villageY[i], cityX[j], cityY[j]));
			}
			d[i] = minim;
		}

		
		for(int i=0;i<villageX.size();++i) {
		
			double minim = MAX_DIST;
			int minv = 0;
			
			for(int i=0;i<villageX.size();++i) {
				//cout<<"+"<<i<<endl;
				if(minim > d[i] && d[i] > 0) {
					minim = d[i];
					minv = i;
				}
			}
			
			d[minv] = 0;
			cost += minim;
			
			cout<<minim<<" "<<cost<<endl;
			
			for(int i=0;i<villageX.size();++i) {
			
				double vdist = dist(villageX[minv], villageY[minv], villageX[i], villageY[i]);
				if(d[i] > vdist) {
					d[i] = vdist;
				}
			}
		}
		return cost;
	}
};
