// TC: O(2N) + O(NLOGN)
// SC: O(3*N) + O(N)
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Data{
    public:
    int start;
    int end;
    int pos;
    Data(int s, int e, int p){
        start = s;
        end = e;
        pos = p;
    }
};
class compare {
public: 
    bool operator()(const Data& d1, const Data& d2) {
        return d1.end < d2.end;
    }
};

vector<int> check(vector<int>& start, vector<int>& end, int n){
    vector<int> answer;
    vector<Data> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(Data(start[i], end[i], i + 1));
    }
    sort(arr.begin(), arr.end(), compare());
    int count = 1;
    int freeAt = arr[0].end;
    answer.push_back(arr[0].pos);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i].start > freeAt){
            count++;
            freeAt = arr[i].end;
            answer.push_back(arr[i].pos);
        }
    }
    return answer;
}

int main() {
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};
    int N = 6;
    vector<int> ans = check(start,end,6);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
    
    return 0;
}



//Output: 3 2 5 6 