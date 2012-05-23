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

class PerfectSequences {
	public:
	string fixIt(vector <int> seq) {
		if(seq.size() == 1 && seq[0] >= 0) {
			return "Yes";
		}
		int nz = 0, z = 0;
		for(int i=0;i<seq.size();++i) {
			if(seq[i] > 0) {
				++nz;
			} else if(seq[i] == 0) {
				++z;
			} else {
				return "No";
			}
		}
		
		if(nz == 1) {
			return "Yes";
		}		
		
		int s = 0, p = 1;
		
		for(int i=0;i<seq.size();++i) {
			if(seq[i] > 50) {
				seq[i] = 51;
			}
			if(seq[i]) {
				s += seq[i];
				p *= seq[i];
			}
			if(p > 2500) {
				return "No";
			}
			
		}
		cout << s << " "<< p << endl;
		
		if(z) {
			if(p != 1 && s % (p-1) == 0) {
				int x = s / (p-1);
				if(x > 0) {
					return "Yes";
				}
			}
			return "No";
		}
		
		for(int i=0;i<seq.size();++i) {
			if((p - seq[i] != 0) && (seq[i]*(s-seq[i])) % (p - seq[i]) == 0) {
				int x = (seq[i]*(s-seq[i])) / (p - seq[i]);
				if(x > 0 && x != seq[i]) {
					cout << x << endl;
					return "Yes";
				}
			}
		}
		
		return "No";
		
		
	}
};
