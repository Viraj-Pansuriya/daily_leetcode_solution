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
        vector<int> closestPrimes(int left, int right) {
            
            bool store[1000001];
            memset(store , true, sizeof(store));
            store[1] = false; 
    
    
            for(long long  i = 2 ; i <= right ; i++){
                if(store[i] == false) continue; 
                for(long long  j = i*i ; j <= right ; j += i){
                    store[j] = false; 
                }
            }
            int prev1 = -1; 
            int prev2 = -1; 
            int diff = INT_MAX;  
    
            int finalP1 = -1  , finalP2 = -1;
            for(int i = left ; i <= right ; i++){
                if(store[i] == true){
                   prev2 = prev1; 
                   prev1 = i; 
                   if(prev1 != -1 && prev2 != -1 &&  diff > (prev1 - prev2)){
                    finalP1 = prev1; 
                    finalP2 = prev2; 
                    diff = (prev1 - prev2); 
                   }
                }
            }
    
            return {finalP2 , finalP1}; 
    
            }
    };