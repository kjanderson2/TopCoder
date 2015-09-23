#include <iostream>
#include <cmath>
using namespace std;

class ExerciseMachine{
private:
	int convertToSeconds(string time){
		int answer = 0;
		string hoursString = time.substr(0,2);
		string minsString = time.substr(3,2);
		string secsString = time.substr(6,2);
		int hours = atoi(hoursString.c_str());
		int mins = atoi(minsString.c_str());
		int secs = atoi(secsString.c_str());
		answer += secs;
		answer += mins*60;
		answer += hours*3600;
		return answer;
	}
public:
	int getPercentages(string time){
		int answer =0;
		int numSecs = convertToSeconds(time);
		for(int i=1; i<=numSecs; i++){
			if(remainder((i*100),numSecs)==0){
				answer += 1;
			}
		}
		return answer-1;
	}
};
