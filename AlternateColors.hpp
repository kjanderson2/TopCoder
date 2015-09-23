#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class AlternateColors{
public:
    string getColor(unsigned long long r, unsigned long long g, 
        			unsigned long long b, unsigned long long k){
		unsigned long long minimum = min(r, min(g,b));
		if(k <= 3*minimum){
			switch(k%3){
				case(1):
					return "RED";
					break;
				case(2):
					return "GREEN";
					break;
				case(0):
					return "BLUE";
					break;
			}
		}
		k -= 3*minimum;
		r -= minimum;
		g -= minimum;
		b -= minimum;
		if(r==0){
			if(k<=2*min(g,b)){
				switch(k%2){
					case(1):
						return "GREEN";
						break;
					case(0):
						return "BLUE";
						break;
				}
			} else if(g>=b) {
				return "GREEN";
			} else {
				return "BLUE";
			}
		}
		if(g==0){
			if(k<=2*min(r,b)){
				switch(k%2){
					case(0):
						return "BLUE";
						break;
					case(1):
						return "RED";
						break;
				}
			} else if(r>=b) {
				return "RED";
			} else {
				return "BLUE";
			}
		}
		if(b==0){
			if(k<=2*min(r,g)){
				switch(k%2){
					case(1):
						return "RED";
						break;
					case(0):
						return "GREEN";
						break;
				}	
			} else if(r>=g){
				return "RED";
			} else {
				return "GREEN";
			}
		}
	}
};
