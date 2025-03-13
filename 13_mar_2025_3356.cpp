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
    
    
    
        bool check(int index , vector < int > nums ,  vector < vector < int > > &q){
            vector < int > store(nums.size() , 0); 
            for(int i = 0 ; i <= index ; i++){
                int x = q[i][0]; 
                int y = q[i][1]; 
                int val = q[i][2]; 
                store[x] -= val; 
                if((y + 1) < store.size()) store[y+1] += val;  
            }
    
    
            for(int i = 1 ; i < nums.size() ; i++){
                store[i] += store[i-1]; 
            }
            for(int i = 0 ; i < nums.size() ; i++){
                if((nums[i] + store[i]) > 0) return false; 
            }
            return true; 
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    
            // not a segment tree / fenwich tree. , just a binary search: 
            int one = 0; 
            for(auto & x : nums){
               if(x > 0) {
                one = 1; 
                break; 
               }
            }
            if(one == 0) return 0; 
    
            int l = 0 , r = queries.size() - 1; 
            int ans = -2; 
    
            while(l <= r){
                int mid = (l) + (r-l)/2; 
                if(check(mid , nums, queries)){
                    ans = mid; 
                    r = mid -1; 
                }
               else l = mid + 1; 
            }
    
            return ans + 1; 
        }
    };
    