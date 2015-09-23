#include <iostream>
#include <vector>

using namespace std;

class Barbecue{
public:
	int eliminate(int n, vector<int> voter, vector<int> excluded){
		vector<int> timesVoted;
		vector<int> numAgainst;
		for(int i = 0; i<n; i++){
			numAgainst.push_back(0);
			timesVoted.push_back(0);
		}
		for(int i = 0; i< voter.size(); i++){
			int votedFor = voter[i];
			int votedAgainst = excluded[i];
			timesVoted[votedFor]++;
			numAgainst[votedAgainst]++;
		}
		int maxVal = numAgainst[0];
		int maxIndex = 0;
		for(int i=1; i<n; i++){
			if(numAgainst[i]>maxVal){
				maxVal = numAgainst[i];
				maxIndex = i;
			}
			else if(numAgainst[i]==maxVal){
				if(timesVoted[i]>timesVoted[maxIndex]){
					maxVal = numAgainst[i];
					maxIndex = i;
				} 
			}
		}
		return maxIndex;
	}
};
