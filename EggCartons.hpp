#include <iostream>

using namespace std;

class EggCartons{
public:
	int minCartons(int n){
		for(int sixes = 0; sixes<17; sixes++){
			for(int eights = 0; eights<13; eights++){
				if (n == sixes*6 + eights*8){
					return sixes+eights;
				}
			}
		}
		return -1;
	}
};
