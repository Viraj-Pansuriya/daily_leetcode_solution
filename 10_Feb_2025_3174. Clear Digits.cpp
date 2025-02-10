#include<iostream>
using namespace std;
#include <stack>

class Solution {
public:
    string clearDigits(string s) {

        stack < char > store; 

        for(auto & x : s){
            if(x >= '0' && x <='9'){
                store.pop(); 
            }
            else store.push(x); 
        }


        string ans = ""; 

        while(store.empty() == false){
            char c = store.top();
            ans += c;
            store.pop();  
        }
        reverse(ans.begin() , ans.end()); 
        return ans; 
        
    }
};