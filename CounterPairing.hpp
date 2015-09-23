#include <vector>
#include <iostream>

using namespace std;

class CounterPairing{
public:
	int countersLeft(vector<int> start){
		for(int i = start.size()-1; i>0; --i){
			while(start[i]>1){
				start[i-1]++;
				start[i] -=2;
			}
		}
		return start[0];
	}
};
