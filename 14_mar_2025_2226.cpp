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

    bool check(ll mid , vector < int > & can , ll k){
        ll count = 0; 
        for(auto & x  :  can){
            count += (x / mid); 
            if(count >= k) return true; 
        }
        return false; 
    }
    int maximumCandies(vector<int>& candies, long long k) {

        long long left = 1 , right = 1e8; 
        long long ans = 0; 
        while(left <= right){
            long long mid = (left) + (right - left)/2;
            if(check(mid , candies , k)){
                ans = mid; 
                left = mid + 1;
            }
            else right = mid -1;
        }
        return ans;    
    }
};
