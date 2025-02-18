#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
#include <functional>
#include <type_traits>
#include <tuple>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <valarray>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdarg>
#include <climits>
#include <cfloat>
#include <bitset>
#define ll long long
using namespace std;

class Solution {
    public:
        string smallestNumber(string pattern) {
    
            string curr(pattern.size() + 1 , '&'); 
            string num ; 
            vector < bool > store(10 , false);
            opr(pattern , store , 0  , num , curr); 
            return num; 
            
        }
    
        bool opr(string & pattern , vector < bool >  store , int index , string & num , string curr){
            if(index-1 == pattern.size()){
                num = curr; 
                return true; 
            }
    
            bool ans = false; 
            for(int i = 1 ; i <= 9 ; i++){
                if(store[i] == false){
                    if(index >  0){
                        char c = (i + '0'); 
                        if(pattern[index-1] == 'I' && (c >  curr[index - 1])){
                            curr[index] = c; 
                            store[i] = true; 
                            if(opr(pattern , store , index+1 , num , curr)) return true; 
                            store[i] = false; 
                            curr[index] = '~';  
                        }
                        else if(pattern[index-1] == 'D' && (c < curr[index - 1])){
                            curr[index] = c; 
                            store[i] = true; 
                            if(opr(pattern , store, index+1 , num , curr)) return true; 
                            store[i] = false; 
                            curr[index] = '~';
                        }
                    }
                    else{
                        char c = (i + '0') ;
                        curr[index] = c; 
                        store[i] = true; 
                        if(opr(pattern , store , index + 1 , num , curr)) return true; 
                        store[i] = false; 
                        curr[index] = '~'; 
                    }
                }
            }
    
            return false; 
        }
    };