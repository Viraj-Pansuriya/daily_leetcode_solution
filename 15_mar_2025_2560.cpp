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


#define ll long long 
class Solution {
public:


    bool check(vector < int > &nums , ll mid, int k){

        int curr = 0; 
        int i = 0; 
        while( i < nums.size()){
            if(nums[i] <= mid){
                i++; 
                curr++; 
            }
            i++; 
            if(curr == k) return true; 
        }
        return false; 

    }
    int minCapability(vector<int>& nums, int k) {
        
        
        
        ll left = 1 , right = 1e9;

        ll ans = 0; 
        while(left <= right){

            ll mid = (left) + (right - left) / 2; 
            if(check(nums , mid , k)){
                ans = mid; 
                right = mid - 1;
            }
            else left = mid + 1;

        }
        return ans; 
    }
};