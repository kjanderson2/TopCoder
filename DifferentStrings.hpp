#include <iostream>
#include <string>
#include <climits>
#include <math.h>

using namespace std;

class DifferentStrings{
private:
	int countDiffs(int index, string str1, string str2){
		int result = 0;
		for(int i = 0; i < str1.length(); ++i){
			if(str1[i] != str2[i+index]){
				result++;
			}
		}
		return result;
	}
public:
	int minimize(string A, string B){
		int answer = INT_MAX;
		for(int i = 0; i < (B.length()-A.length()+1); ++i){
			answer = min(answer, countDiffs(i, A, B));
		}
		return answer;
	}

};
