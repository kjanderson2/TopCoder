
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class DownloadingFiles
{   
    public:
    double actualTime(vector<string> tasks)
    {
        const string delimiter = " ";

        int bandWidth = 0;
        int answer = 0;
        
        for (int i=0; i<tasks.size(); ++i)
        {
            int num1, num2;
            istringstream (tasks[i].substr(0, tasks[i].find(delimiter))) >> num1;
            istringstream (tasks[i].substr(tasks[i].find(delimiter), tasks[i].length())) >> num2;
            answer += num1 * num2;
            bandWidth += num1;
        }
        return (double) answer /bandWidth ;
    }
};
