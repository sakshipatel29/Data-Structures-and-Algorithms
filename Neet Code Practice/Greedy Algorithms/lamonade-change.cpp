#include <iostream>
#include <vector>
using namespace std;

//TC: O(N)
//SC: O(1)

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int fives = 0;
            int tens = 0;
            for (int i = 0; i < bills.size(); i++) {
                if (bills[i] == 5)
                    fives++;
                else if (bills[i] == 10 && fives >= 1) {
                    tens++;
                    fives--;
                } else {
                    if (tens >= 1 && fives >= 1) {
                        tens--;
                        fives--;
                    } else if (fives >= 3) {
                        fives -= 3;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    };