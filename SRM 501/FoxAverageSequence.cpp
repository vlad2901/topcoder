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

#define MOD 1000000007

using namespace std;

class FoxAverageSequence {
	public:
	int theCount(vector <int> seq) {
		int a[2][1601][41][2];
		int n = seq.size();
		
		memset(a[1], 0, sizeof(a[1]));

		if(seq[0] == -1) {
			for(int i=0;i<=40;++i) {
				a[1][i][i][1] = 1;
			}
		} else {
			a[1][seq[0]][seq[0]][1] = 1;
		}
		
		for(int i=1, ln=1;i<n;++i, ln = 1-ln) {
			memset(a[1-ln], 0, sizeof(a[1-ln]));
			for(int j=0;j<=1560;++j) {
				for(int k=0;k<=40;++k) {
					if(seq[i] == -1) {
						//noul element mai mic strict decat ultimul
						for(int t=0;t<=min(40, min(k-1, j/i));++t) { //ultimul element trebuie sa fie maxim 40 si mai mic sau egal decat media
							a[1-ln][j+t][t][0] += a[ln][j][k][1];
							a[1-ln][j+t][t][0] %= MOD;
							
						}
						//noul element mai mare sau egal decat ultimul
						for(int t=k;t<=min(40, j/i);++t) {
							a[1-ln][j+t][t][1] += a[ln][j][k][1];
							a[1-ln][j+t][t][1] %= MOD;
							a[1-ln][j+t][t][1] += a[ln][j][k][0];
							a[1-ln][j+t][t][1] %= MOD;
							
						}
					} else {
						if(seq[i] <= j/i) {
							if(k <= seq[i]) {						
								a[1-ln][j+seq[i]][seq[i]][1] += a[ln][j][k][0];
								a[1-ln][j+seq[i]][seq[i]][1] %= MOD;
								a[1-ln][j+seq[i]][seq[i]][1] += a[ln][j][k][1];
								a[1-ln][j+seq[i]][seq[i]][1] %= MOD;
							} else {							
								a[1-ln][j+seq[i]][seq[i]][0] += a[ln][j][k][1];
								a[1-ln][j+seq[i]][seq[i]][0] %= MOD;
							}
						}
					}
				}
			}
		}
		
		int sum = 0;
		
		for(int j=0;j<=1600;++j) {
			for(int k=0;k<=40;++k) {
				for(int l=0;l<=1;++l) {
					sum += a[n%2][j][k][l];
					sum %= MOD;
				}
			}
		}
		return sum;
	}
};
