#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CastleGuards{
public:
	int missing(vector<string> castle){
		int emptyRows = 0;
		int emptyCols = 0;
		int rowsInventory[50] = {0};
		int colsInventory[50] = {0};
		for(int i = 0; i<castle.size(); ++i){
			for (int j = 0; j<castle[i].length(); ++j){
				if (castle[i][j] == 'X'){
					rowsInventory[i] = 1;
					colsInventory[j] = 1;
				}
			}
			if(rowsInventory[i] == 0){
				emptyRows++;
			}
		}
		for(int k = 0; k < castle[0].length(); ++k){
			if(colsInventory[k] == 0){
				emptyCols++;
			}
		}
		return max(emptyCols, emptyRows);
	}
};
