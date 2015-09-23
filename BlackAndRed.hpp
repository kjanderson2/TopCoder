#include <iostream>
#include <string>

using namespace std;

class BlackAndRed{
private:
    bool winner(string deck){
		int value = 0;
		for(int i = 0; i<deck.length(); ++i){
			if(value<0){
				return false;
			} else {
				if(deck[i] == 'B'){
					value++;
				} else {
					value--;
				}
			}
		}
		return true;
	}
public:
	int cut(string deck){
		int length = deck.length();
		for(int i = 0; i<deck.length(); i++){
			string topCut = deck.substr(0, i);
			string bottomCut = deck.substr(i, length-i);
			string newDeck = bottomCut + topCut;
			if(winner(newDeck)){
				return i;
			}
		}
	}
};
