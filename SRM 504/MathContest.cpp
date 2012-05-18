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

class MathContest {
	public:
	int countBlack(string ballSequence, int repetitions) {
		int inverted = 0;

		int n = ballSequence.size();
				int last = n;
		int pos = -1;
		int tr[50];
		
		for(int i=0;i<n;++i) {
			tr[i] = ballSequence[i] == 'W' ? 0 : 1;
			cout<<tr[i]<<endl;
		}
		
		int nr = 0;
		int rev = 0;
		
		for(int i=0; i<n * repetitions;++i) {
			if(rev) {
				--pos;
			} else {
				++pos;
			}
			pos += n;
			pos %= n;

			if(abs(inverted-tr[pos]) == 1) {
				inverted = 1 - inverted;
				++nr;
			} else {
				swap(last, pos); 
				rev = 1-rev;
			}
			
		}
	
		return nr;
				
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
