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

class Zoo {
	public:
	long long theCount(vector <int> answers) {
		int a[41];
		int n = answers.size();
		
		memset(a, 0, sizeof(a));
		
		for(int i=0;i<n;++i) {
			if(answers[i] >= n) 
			{
				return 0;
				cout<<"start";
			}
				
			++a[answers[i]];
		}
		int an = 2, p = 0, x = 0, y = 0, add = 0;
		
		for(int i=0;i < n;++i) {
		
			if(a[i] == 1 && !add) {
				add = 1;
			}
		
			if(an == 0) {
				cout<<"caz0\n";
				if(a[i] != 0) {
				cout<<an<<" "<<i<<endl;
					return 0;
				}
			}
			
			if(an == 1) {
			cout<<"caz1\n";
				switch(a[i]) {
					case 2: return 0;
					case 1: break;
					case 0: y = i; an = 0; break;
					default: cout<<an<<" "<<i<<endl; return 0;
				}
			}
			
			if(an == 2) {
			cout<<"caz2\n";
				switch(a[i]) {
					case 2: ++p; break;
					case 1: x = i; an = 1; break;
					case 0: x = i; y = i; an = 0; break;
					default: cout<<an<<" "<<i<<endl; return 0;
				}
			}
		}
		
		if(!y) {
			y = n;
		}
		
		if(x + y != n) {
			cout <<"final" << x << " " << y;
			return 0;
		}
		
		return pow(2.0, p+add);
		
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
