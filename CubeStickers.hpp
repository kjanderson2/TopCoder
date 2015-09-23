#include <map>
#include <vector>
#include <iostream>

using namespace std;

class CubeStickers{
public:
	string isPossible(vector<string> sticker){
		// create the map
		map <string, int> colorMap;
		// increment for each sticker
		for (int i = 0; i< sticker.size(); ++i){
			colorMap[sticker[i]]++;
		}
		// count the number of individual stickers
		int onlyOne = 0;
		// count the number of stickers with 2 or more
		int multiple = 0;
		for(map<string,int>::iterator it = colorMap.begin(); it!= colorMap.end(); it++){
			if(it->second == 1){
				onlyOne++;
			} else {
				multiple++;
			}
		}
		if(onlyOne >= 6){
			return "YES";
		}
		else if(onlyOne >=4 && multiple >= 1){
			return "YES";
		}
		else if(onlyOne >= 2 && multiple >=2){
			return "YES";
		}
		else if(multiple >= 3){
			return "YES";
		} else {
			return "NO";
		}
	}
};
