#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class CircularLine{
private:
    int minPath(vector<int> t, int i, int j){
    	int answer1 = 0;
        int k = i;
		for(int k = i; k < j; k++){
			answer1 += t[k];
		}

		int answer2 = 0;
        int m = j;
        if(m != j){
        //    cout << m << " " << j << endl;
        }
        int numSteps = t.size() - abs(m-i) ;
		for(int i = 0; i<numSteps; i++){
			if(m>t.size()-1){
				m=0;
			}
			answer2+= t[m];
            m++;
		}
		return min(answer1, answer2);
	}
public:
	int longestTravel(vector<int> t){
		int longest = 0;
		for(int i = 0; i < t.size(); i++){
			for(int j = 0; j < t.size(); j++){
				if(i!=j && i<j){
					longest = max(longest, minPath(t, i, j));
				}
			}
		}
		return longest;
	}
};
