#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class AzimuthMonitoring
{   
    private:
    int extractDegree(string instruction)
    {
        istringstream iss(instruction);
        string command;
        int degree;
        iss >> command >> degree ;
        return degree;
    }
    int fixDegree(int degree)
    {
        while (degree < 0)
        {
            degree += 360;
        }
        while (degree >= 360)
        {
            degree -= 360;
        }
        return degree;
    }
    public:

    int getAzimuth(vector<string> instructions)
    {
        int result = 0;
        for (int i = 0; i < instructions.size(); ++i)
        {
            if (instructions[i] == "HALT" )
            {
                result = fixDegree(result);
                return result;
            } 
            else if (instructions[i] == "LEFT")
            {
                result -= 90;
            }
            else if (instructions[i] == "RIGHT")
            {
                result += 90;
            }
            else if (instructions[i] == "TURN AROUND")
            {
                result += 180;
            }
            else if (instructions[i].find("LEFT ") != string::npos)
            {
                 result -= extractDegree(instructions[i]);
            }
            else if (instructions[i].find("RIGHT ") != string::npos)
            {
                 result += extractDegree(instructions[i]);
            }
            
        }
        result = fixDegree(result);
        return result;
    }

};

