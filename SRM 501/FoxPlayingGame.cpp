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



class FoxPlayingGame {
	public:
	double theMax(int nA, int nB, int paramA, int paramB) {
	
		double rez, pA, pB;
		
		pA = (double)paramA/1000;
		pB = (double)paramB/1000;
		
		if(paramB <= -1000 && nB % 2 == 1 && paramA >= 0) {
			nB--;
		}
		
		if(paramB <= -1000 && nB && nB % 2 == 0 && paramA <= 0) {
			nB--;
		}
		
		if(nB > 0 && paramA <= 0 && paramB < 0 && paramB >-1000) {
			nB = 1;
		}
		
		if((paramB >= 1000 && paramA >= 0) ||
			(paramB >= 0 && paramB <= 1000 && paramA <= 0) ||
			(paramB <= -1000) ||
			(paramA <= 0 && paramB < 0 && paramB >-1000)) {
				cout<<"caz 1"<<endl;
				cout<<nA<<" "<<nB<<endl;
				rez = nA * pA;
				cout<<rez<<endl;
				rez *= pow(pB, nB);
				cout<<pB<<"^"<<nB<<endl;
				cout<<rez<<endl;
				
			} else {
				cout<<"caz 2"<<endl;
				rez = nA * pA;
			}
		return rez;
			
	}
};
