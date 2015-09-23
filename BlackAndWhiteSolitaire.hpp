#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class BlackAndWhiteSolitaire{

private:
	int blackFirst(string cardFront){
		int difficulty = 0;
		char currColor = 'B';
		for(int i = 0; i<cardFront.length(); i++){
			if(cardFront[i] != currColor){
				cardFront[i] = currColor;
				difficulty++;
			}
			if(currColor == 'B'){
				currColor = 'W';
			} else {
				currColor = 'B';
			}
		}
		return difficulty;
	}
	int whiteFirst(string cardFront){
	int difficulty = 0;
		char currColor = 'W';
		for(int i = 0; i<cardFront.length(); i++){
			if(cardFront[i] != currColor){
				cardFront[i] = currColor;
				difficulty++;
			}
			if(currColor == 'W'){
				currColor = 'B';
			} else {
				currColor = 'W';
			}
		}
		return difficulty;
	}
public:
	int minimumTurns(string cardFront){
		int answer = min(blackFirst(cardFront), whiteFirst(cardFront));
		return answer;
	}
};
