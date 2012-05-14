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

class ToastXToast {
	public:
	int bake(vector <int> undertoasted, vector <int> overtoasted) {
		sort(undertoasted.begin(), undertoasted.end());
		sort(overtoasted.begin(), overtoasted.end());
		
		if((undertoasted[0] >= overtoasted[0]) || (undertoasted[undertoasted.size()-1] >= overtoasted[overtoasted.size()-1])) {
			return -1;
		}
		
		int i = 0;
		
		while(i < undertoasted.size() && undertoasted[i] < overtoasted[0]) {
			++i;
		}
		
		if(i == undertoasted.size()) {
			return 1;
		}
		
		return 2;
	}
};
