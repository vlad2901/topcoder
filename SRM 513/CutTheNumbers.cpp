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

class CutTheNumbers {
	public:
	
	int rows, cols, maxim;
	
	int computeSol(vector<string> aux, vector<string> board) {
		vector<vector<int> >viz(rows, vector<int>(cols, 0));
		
		int sum = 0;
		int nr;

		for(int i=0;i<rows;++i) {
			for(int j=0;j<cols;++j) {
				if(!viz[i][j]) {
					nr = 0;
					
					int ai, aj;
					ai = i, aj = j;
					while(aj < cols && aux[ai][aj] == 'h') {
						nr = nr * 10 + board[ai][aj] - '0';
						viz[ai][aj] = 1;
						++aj;
					}
					
					ai = i, aj = j;
					while(ai < rows && aux[ai][aj] == 'v') {
						nr = nr * 10 + board[ai][aj] - '0';
						viz[ai][aj] = 1;
						++ai;
					}
					sum += nr;
				}	
			}
		}
		return sum;
	}
	
	void back(int r, int c, vector<string> &aux, vector<string> &board) {
		
		if(r == rows) {
			int current = computeSol(aux, board);
			if(current > maxim) {
				maxim = current;
				cout<<maxim<<endl;
			}
		} else {
			aux[r][c] = 'h';
			back(r + (c+1)/cols, (c+1)%cols, aux, board);
			aux[r][c] = 'v';
			back(r + (c+1)/cols, (c+1)%cols, aux, board);
		}
	}
	
	int maximumSum(vector <string> board) {

		vector<string> aux = board;

		maxim = -1;
		rows = board.size();
		cols = board[0].size();
		
		back(0, 0, aux, board);
		
		return maxim;
	}
};
