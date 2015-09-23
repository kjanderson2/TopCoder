#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class BigBurger{
public:
	int maxWait(vector<int> arrival, vector<int> service){
		int answer = 0;
		int currTime = 0;
		for(int i = 0; i < arrival.size(); ++i){
			if(arrival[i] < currTime){
				answer = max(answer, currTime - arrival[i]);
				currTime = currTime + service[i];
			} else {
				currTime = arrival[i] + service[i];
			}
		}
		return answer; 
	}
};
