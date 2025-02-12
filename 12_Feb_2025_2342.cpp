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
        int maximumSum(vector<int>& nums) {
               unordered_map < int , priority_queue < int , vector < int > , greater < int >  >> mp; 
               for(auto & x : nums){
                    int num = x; 
                    int sum = 0; 
                    while(num){
                        sum += num % 10; 
                        num /= 10; 
                    }
                    mp[sum].push(x); 
                    if(mp[sum].size() > 2){
                        mp[sum].pop(); 
                    }
               } 
    
               int ans = -1; 
               for(auto & x : mp){
    
               
                if(x.second.size() > 1){
                    int curr = x.second.top(); 
                    x.second.pop(); 
                    curr += x.second.top();
                    x.second.pop(); 
                    ans = max(ans , curr); 
                }
               }
    
               return ans; 
    
    
            
        }
    };