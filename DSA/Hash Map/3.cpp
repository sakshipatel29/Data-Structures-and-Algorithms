//max in hashmap
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 1, 1, 1};
    
    int hash[5] = {0};
    for(int i = 0; i < 5; i++){
        if (arr[i] < 5) hash[arr[i]] +=1;
    }
    int max = 0;
    for(int i = 0; i < 5; i++){
        max = std::max(max, hash[i]);
    }
    cout << max;
    return 0;
}