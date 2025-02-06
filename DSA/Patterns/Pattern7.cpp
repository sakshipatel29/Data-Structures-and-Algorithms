//     *    
//    ***   
//   *****  
//  ******* 
// *********

#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i < 5; i++){
        //space
        for( int j = 0; j < 4-i; j++){
            cout<< " ";
        }
        //star
        for( int j = 0; j < 2*i+1; j++){
            cout<< "*";
        }
        //space
        for( int j = 0; j < 4-i; j++){
            cout<< " ";
        }
        cout << endl;
    }
}