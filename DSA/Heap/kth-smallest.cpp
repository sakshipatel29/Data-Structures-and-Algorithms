//TC: O(nlogk)
//SC: O(k)

#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    int num[100];
    int size;

    Heap() {
        num[0] = -1;
        size = 0;
    }

    void insertion(int val) {
        size++;
        int index = size;
        num[index] = val;
        while(index > 1 && num[index / 2] < num[index]) {
            swap(num[index], num[index / 2]);
            index = index / 2;
        }
    }

    void deletion() {
        if(size == 0) return;

        num[1] = num[size];
        size--;

        int i = 1;
        while(i <= size) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if(left <= size && num[left] > num[largest]) largest = left;
            if(right <= size && num[right] > num[largest]) largest = right;

            if(largest != i) {
                swap(num[i], num[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    int top() {
        return num[1];
    }

    vector<int> print() {
        vector<int> ans;
        for(int i = 1; i <= size; i++) {
            ans.push_back(num[i]);
        }
        return ans;
    }
};

int main() {
    int arr[7] = {-1, 7, 19, 4, 3, 20, 15};
    int k = 4;
    int n = 6;

    Heap h;

    for(int i = 1; i <= k; i++) {
        h.insertion(arr[i]);
    }

    for(int i = k + 1; i <= n; i++) {
        if(arr[i] < h.top()) {
            h.deletion();
            h.insertion(arr[i]);
        }
    }

    cout << "Kth smallest element is: " << h.top() << endl;
    return 0;
}

//Output:
//Kth smallest element is: 15