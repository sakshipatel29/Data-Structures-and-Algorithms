#include<iostream>
using namespace std;

int main() {
    char str[100];
    char str1[100];
    char str2[100];
    cin>> str; //sakshi patel
    cin.getline(str1,100); // sakshi patel
    cin.getline(str2, 100, '$'); // sakshi pa$tel
    cout<<str<<endl;  // sakshi
    cout<<str1;// sakshi patel
    cout<< str2; // sakshi pa
    return 0;
}