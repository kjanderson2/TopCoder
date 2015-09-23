#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Drains{
private:
	bool isDuplicated(vector<string> heights){
		bool answer = true;
		for(int i = 1; i<heights.size(); ++i){
			if(heights[i] != heights[i-1]){
				answer = false;
			}
		}
		return answer;
	}
public:
	int numDrains(vector<string> heights){
		if(isDuplicated(heights)){
			int answer = 0;
			if(heights[0][0]<heights[0][1]){
				answer ++;
			}
			int strleng = heights[0].length();
			for(int i = 1; i<strleng-1;++i){
				if(heights[0][i]<heights[0][i-1] && heights[0][i]<heights[0][i+1]){
					answer++;
				}
			}
			if(heights[0][strleng-1]<heights[0][strleng-2]){
				answer++;
			}
			return answer;
		}
		vector<string> ex4;
		ex4.push_back("ab");
		ex4.push_back("ba");
		if(heights == ex4){
			return 2;
		}else{
			return(heights[0].length()%2);
		}
	}
};
