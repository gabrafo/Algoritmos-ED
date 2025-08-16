#include <string>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string numS = to_string(num);
        for(int i = 0; i < numS.length(); i++){
            if (numS.at(i) == '6') {
                numS.at(i) = '9';
                return stoi(numS); // string to int
            }
        }
        return num;
    }
};