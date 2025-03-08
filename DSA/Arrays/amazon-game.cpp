//TC: O(N) here O(3)
//SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int AmazonGame(vector<int>& booster1, vector<int>& booster2, vector<int>& booster3) {
    int atob = 0, atoc = 0, btoc = 0;
    int btoa = 0, ctoa = 0, ctob = 0;

    for (int i = 0; i < 3; ++i) {
        if (booster1[i] > booster2[i]) atob++;
        else if (booster1[i] < booster2[i]) btoa++;

        if (booster1[i] > booster3[i]) atoc++;
        else if (booster1[i] < booster3[i]) ctoa++;

        if (booster2[i] > booster3[i]) btoc++;
        else if (booster2[i] < booster3[i]) ctob++;
    }

    int count = 0;
    if (atob >= 2 && atoc >= 2) count++;
    if (btoa >= 2 && btoc >= 2) count++;
    if (ctoa >= 2 && ctob >= 2) count++;

    return count;
}

int main() {
    int n = 3;
    vector<int> booster1(n), booster2(n), booster3(n);

    for (int j = 0; j < n; ++j) cin >> booster1[j];
    for (int j = 0; j < n; ++j) cin >> booster2[j];
    for (int j = 0; j < n; ++j) cin >> booster3[j];

    int answer = AmazonGame(booster1, booster2, booster3);
    cout << answer;

    return 0;
}

