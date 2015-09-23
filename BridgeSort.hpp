#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class BridgeSort{
private:
    vector<int> convertVec(vector<char> suit){
        cout << "Suit size is " << suit.size() << endl;
        vector<int> returnVec;
    	for(int i = 0; i < suit.size(); ++i){
			if(suit[i] == 'J'){
				returnVec.push_back(11);
			}
			else if(suit[i] == 'Q'){
				returnVec.push_back(12);
			}
			else if(suit[i] == 'K'){
				returnVec.push_back(13);
			}
			else if(suit[i] == 'A'){
				returnVec.push_back(14);
			} else if (suit[i] == 'T'){
				returnVec.push_back(10);
			} else {
				int value = suit[i] - '0';
				returnVec.push_back(value);
			}
		}
        return returnVec;
	}
	string suitString(vector<int> suit, string suitType){
		string answer = "";
		for(int i = 0; i < suit.size(); ++i){
			answer += suitType;
			if(suit[i]<10){
				char value = '0' + suit[i];
				answer += value;
			}
			else if (suit[i] == 10){
				answer += "T";
			}
			else if (suit[i] == 11){
				answer += "J";
			}
			else if (suit[i] == 12){
				answer += "Q";
			} 
			else if (suit[i] == 13){
				answer += "K";
			} 
			else if (suit[i] == 14){
				answer += "A";
			}
		}
		return answer;
	}
				
public:
	// Clubs -> Diamonds -> Hearts -> Spades
	string sortedHand(string hand){
		vector<char> hearts;
		vector<char> clubs;
		vector<char> diamonds;
		vector<char> spades;
		for(int i = 0; i < hand.length(); i+=2){
			if(hand[i] == 'H'){
				hearts.push_back(hand[i+1]);
			} 
			else if(hand[i] == 'C'){
				clubs.push_back(hand[i+1]);
			}
			else if(hand[i] == 'D'){
				diamonds.push_back(hand[i+1]);
			} else {
				spades.push_back(hand[i+1]);
			}
		}
		vector<int> heartsNum = convertVec(hearts);
		vector<int> clubsNum = convertVec(clubs);
		vector<int> diamondsNum = convertVec(diamonds);
		vector<int> spadesNum = convertVec(spades);
    	sort(heartsNum.begin(), heartsNum.end());
		sort(clubsNum.begin(), clubsNum.end());
		sort(diamondsNum.begin(), diamondsNum.end());
		sort(spadesNum.begin(), spadesNum.end());
		string answer = "";
		answer += suitString(clubsNum, "C");
		answer += suitString(diamondsNum, "D");
		answer += suitString(heartsNum, "H");
		answer += suitString(spadesNum, "S");
		return answer;


	}
};
