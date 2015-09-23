#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ColorfulRabbits{
public:
    int getMinimum(vector<int> replies){
		sort(replies.begin(), replies.end());
		int answer = 0;
		int i = 0; 
		while(i<replies.size()){
			int j = i;
			int dupes = 0;
			while(replies[j] == replies[i] && j<replies.size()){
				dupes++;
				j++;
			}
			for(int k = 0; k<dupes; k+= replies[i]+1){
				answer += replies[i]+1;
			}
			i+= dupes;
		}
		return answer;
	}
};
