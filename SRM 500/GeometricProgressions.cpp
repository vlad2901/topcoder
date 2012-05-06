/*
Pica pe exemplul: {9, 0, 1656, 2, 1, 901}
Expected: 3 Recived: 2

Nu inteleg de ce ar trebuie sa intoarca 3. In progresie apare 0^0... ceva nu e in regula.
*/
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

class GeometricProgressions {
	public:
	
	void gen_factors(int n, set<int> &f) {
		int d = 2;
		
		if(n == 0) return;
		
		while(n > 1) {
			int fact = 0;
			while(n%d == 0) {
				n /= d;
				fact = d;
			}
			if(fact) {
				f.insert(fact);
			}
			++d;
		}
	}
		
		
	void dec(int n, vector<int> &p, vector<int> &f) {
	
		if(!n) return;
	
		for(int i=0;i<f.size();++i) {
		cout<<f[i]<<" ";
			int power = 0;
			while(n%f[i] == 0) {
				++power;
				n /= f[i];
			}
			p.push_back(power);
		}
		cout<<endl;
	}
	
	int count(int b1, int q1, int n1, int b2, int q2, int n2) {
		
		set<int> f;
		vector<int> db1, dq1, db2, dq2;
		set<vector<int> >t;
		
		gen_factors(b1, f);
		gen_factors(q1, f);
		gen_factors(b2, f);
		gen_factors(q2, f);
		
		vector<int> vf(f.begin(), f.end());
		
		vector<int> zero(f.size(), 0);
		
		dec(b1, db1, vf);
		dec(q1, dq1, vf);
		dec(b2, db2, vf);
		dec(q2, dq2, vf);
		
		if(q1 == 0) {
			t.insert(zero);
		} else {
			for(int i=0;i<n1;++i) {
				t.insert(db1);
				for(int j=0;j<db1.size();++j) {
					cout<<db1[j]<<" ";
					db1[j] += dq1[j];
				}
				cout<<endl;
			}
		}
		
		cout<<"--------------"<<endl;
		
		if(q2 == 0) {
			t.insert(zero);
		} else {
			for(int i=0;i<n2;++i) {
				t.insert(db2);
				for(int j=0;j<db2.size();++j) {
					cout<<db2[j]<<" ";
					db2[j] += dq2[j];
				}
				cout<<endl;
			}
		}
		
		if(b1 == 0 || b2 == 0) {
			return t.size() + 1;
		}
		
		return t.size();
	
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
