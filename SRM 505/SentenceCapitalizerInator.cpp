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

#define UP -32

using namespace std;

class SentenceCapitalizerInator {
	public:
	string fixCaps(string paragraph) {
		paragraph[0] += UP;
		int i = 1;
		while(i < paragraph.size()-2) {
			if(paragraph[i] == '.') {
				paragraph[i+2] += UP;
				++i;
			}
			++i;
		}
	return paragraph;
	}

};
