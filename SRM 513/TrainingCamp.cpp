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

class TrainingCamp {
	public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
		vector<string> sol(attendance.size());
		
		for(int s=0;s<attendance.size();++s) {
			for(int p=0;p<problemTopics.size();++p) {
				char c = 'X';
				for(int i=0;i<attendance[0].size();++i) {
					if(problemTopics[p][i] == 'X' && attendance[s][i] == '-') {
						c = '-';
						break;
					}
				}
				sol[s].push_back(c);
			}
		}
		return sol;
	}
};
