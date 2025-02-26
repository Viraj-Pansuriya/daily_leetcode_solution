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
        int maxAbsoluteSum(vector<int>& nums) {
    
            // positive OR negative; 
    
            int pos = 0 , neg = 0;; 
            int curr = 0; 
            for(auto & x : nums){
                curr += x; 
                curr = max(0 , curr); 
                pos = max(pos , curr); 
            }
    
            curr = 0; 
            for(auto & x : nums){
                curr += x; 
                curr = min(0 , curr); 
                neg = min(neg , curr); 
            }
    
            neg = abs(neg); 
            return max(pos , neg); 
            
        }
    };