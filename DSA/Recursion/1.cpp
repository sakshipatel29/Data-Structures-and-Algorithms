//Functional recursion: 

#include <iostream>

int fn(int n){
    if(n == 0){
        return 0;
    }
    return n + fn(n-1);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fn(n);
    
}