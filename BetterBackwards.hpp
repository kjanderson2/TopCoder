#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BetterBackwards{
private:
	bool origIsSmaller(string orig, string mod){
		return lexicographical_compare(orig.begin(),
									   orig.end(),
									   mod.begin(),
									   mod.end());
	}
	string genString(string S, int revBegin, int revEnd){
		string answer = "";
		for(int i = 0; i<revBegin; ++i){
			answer += S[i];
		}
		for(int i = revEnd; i>=revBegin; --i){
			answer += S[i];
		}
		for(int i = revEnd+1; i<S.length(); ++i){
			answer += S[i];
		}
		return answer;
	}
public:
	vector<int> makeBetter(string S){
		vector<int> answer;
		answer.push_back(0);
		answer.push_back(0);
		string currBest = S;
		for(int j = 0; j<S.length(); ++j){
			for(int i = 0; i<j; ++i){
				if(S[i]>S[j]){
					string newS = genString(S,i,j);
					if(!origIsSmaller(currBest,newS)){
						answer[0] = i;
						answer[1] = j;
						currBest = newS;
					}
				}
			}
		}
		return answer;
	}	
};
