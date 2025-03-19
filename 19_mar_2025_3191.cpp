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
        int minOperations(vector<int>& nums) {
            long long count = 0; 
            for(int i = 0 ; i < nums.size() - 2; i++){
                if(nums[i] == 0){
                    nums[i] = 1; 
                    nums[i+1] = 1 - nums[i+1]; 
                    nums[i+2] = 1 - nums[i+2]; 
                    count++; 
                }
            }
    
            if(nums[nums.size()-2] == 0 || nums[nums.size() - 1] == 0) return -1; 
    
            return count; 
        }
    };