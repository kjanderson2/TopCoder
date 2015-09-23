#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class FairWorkload{
public:
    int getMostWork(vector<int> folders, int workers){
    	vector<int> foldersCopy (folders.size());
		copy(folders.begin(), folders.end(), foldersCopy.begin());
		sort(foldersCopy.begin(), foldersCopy.end());
		int smallest = foldersCopy[folders.size()-1];
		int largest = INT_MAX;
		while(smallest<largest){
			int possLoad = smallest + (largest-smallest)/2;
			int currLoad = 0;
			int numWorkers = 1;
			for(int i = 0; i<folders.size(); ++i){
				if(folders[i] + currLoad <= possLoad){
					currLoad += folders[i];
				} else {
					currLoad = folders[i];
					numWorkers++;
				}
			}
			if (numWorkers <= workers){
				largest = possLoad;
			} else {
				smallest = possLoad+1;
			}
		}
		return smallest;
	}
};
