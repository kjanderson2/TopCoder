#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ElevatorLimit{
private:
    bool isInvalid(int value, int limit){
        return (value<0 || value>limit);
    }
public:
    vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit){
        vector<int> answer;
        int min = 1000;
        int max = -1000;
        int total = 0;
        for(int i=0; i<enter.size(); ++i){
            total -= exit[i];
            min = std::min(total, min);
            total += enter[i];
            max = std::max(total, max);
        }
        int totalRange = max - min;
        min = std::max(0, abs(min));
        max = std::min(physicalLimit, physicalLimit-max);
        if(totalRange>physicalLimit || min>max){
            return answer;
        }
        answer.push_back(min);
        answer.push_back(max);
        return answer;
    }
};
