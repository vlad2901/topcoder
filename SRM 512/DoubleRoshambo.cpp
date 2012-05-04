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

class DoubleRoshambo {
	int wins(char a, char b) {
		if(a == 'S' && b == 'P') {
			return 1;
		}
		if(a == 'P' && b == 'R') {
			return 1;
		}
		if(a == 'R' && b == 'S') {
			return 1;
		}
		return 0;
	}
	
	int score(string a, string b) {
		int score = 0;
		

		if(wins(a[1], b[1])) {
			if(wins(a[0], b[0])) {
				score = 2;
			}
			if(a[0] == b[0]) {
				score = 1;
			}
		}
		return score;
	}
	
	int encode(string s) {
		int code = 0;

		for(int i=0;i<2;++i) {
			if(s[i] > 'Q') {
				code = code * 3 + s[i] - 'Q';
			} else {
				code = code * 3;
			}
		}
		return code;
	}
		
	public:
	int maxScore(vector <string> A, vector <string> E) {
		vector<pair<int, int> > edgeA(9, pair<int, int>(0, 0));
		vector<pair<int, int> > multA(9, pair<int, int>( 0,  0));
		vector<pair<int, int> > multE(9, pair<int, int>( 0,  0));
		
		int apA[9];
		int apE[9];
		
		memset(apA, 0, sizeof(apA));
		memset(apE, 0, sizeof(apE));
		
		for(int i=0;i<A.size();++i) {
			apA[encode(A[i])]++;
			apE[encode(E[i])]++;
		}

		for(int i=0;i<A.size();++i) {
			for(int j=0;j<E.size();++j) {
				cout<<encode(A[i])<<" "<<encode(E[j])<<endl;
				
			
				if(score(A[i], E[j]) == 1) {
					edgeA[encode(A[i])].first = encode(E.at(j));
					multA[encode(A[i])].first++;
					multE[encode(E[j])].first++;
					
					cout<<A[i]<<" "<<E[j]<<" 1"<<endl;
				}
			
				if(score(A[i], E[j]) == 2) {
					edgeA[encode(A[i])].second = encode(E.at(j));
					multA[encode(A[i])].second++;
					multE[encode(E[j])].second++;
					
					cout<<A[i]<<" "<<E[j]<<" 2"<<endl;
				}
			}
		}
		
		int s = 0;
		
		cout<<"test"<<endl;
		
		for(int i=0;i<9;++i) {
			
			if(multA[i].second) cout<<i<<" "<<multA[i].second<<" "<<edgeA[i].second<<" "<<multE[edgeA[i].second].second<<endl;

			int m = min(min(min(multA[i].second, multE[edgeA[i].second].second), apE[edgeA[i].second]), apA[i]);
			multA[i].second -= m;
			multE[edgeA[i].second].second -= m;
			apE[edgeA[i].second] -= m;
			apA[i] -= m;
			
			s += 2*m;
		}

		for(int i=0;i<9;++i) {
		
			if(multA[i].first) cout<<i<<" "<<multA[i].first<<" "<<edgeA[i].first<<" "<<multE[edgeA[i].first].first<<endl;
		
			int m = min(min(min(multA[i].first, multE[edgeA[i].first].first), apE[edgeA[i].first]), apA[i]);
			multA[i].first -= m;
			multE[edgeA[i].first].first -= m;
			apE[edgeA[i].first] -= m;
			apA[i] -= m;
			s += m;
		}

	return s;
	}	
};

