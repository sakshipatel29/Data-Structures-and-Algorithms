#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(26)

class Solution {
    public:
        bool check(vector<int> a, vector<int> b){
            for(int i = 0;i < 26; i++){
                if(a[i] != b[i]) return false;
            }
            return true;
        }
        bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size()) return false;
            vector<int> hash(26, 0);
            for(int i = 0;i < s1.size(); i++){
                hash[s1[i] - 'a']++;
            }
            for(int i = 0; i < s2.size(); i++){
                vector<int> hash1(26, 0);
                for (int j = i; j < i + s1.size() && j < s2.size(); j++){
                    hash1[s2[j] - 'a']++;
                }
                if(check(hash, hash1)) return true;
            }
            return false;
        }
    };

// Time Complexity: O(n)
// Space Complexity: O(26)

//Sliding window

    class Solution {
        public:
            bool checkInclusion(string s1, string s2) {
                if(s1.size() > s2.size()) return false;
                vector<int> hash(26, 0);
                vector<int> hash1(26, 0);
                for(int i = 0;i < s1.size(); i++){
                    hash[s1[i] - 'a']++;
                    hash1[s2[i] - 'a']++;
                }
                if(hash == hash1) return true;
                int window = s1.size();
                for(int i = window ; i < s2.size(); i++){
                    hash1[s2[i] - 'a']++;
                    hash1[s2[i-window] - 'a']--;
                    if(hash == hash1) return true;
                }
                return false;
            }
        };