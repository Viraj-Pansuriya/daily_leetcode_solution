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
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            
            // based on pivot rearrange. 
    
            vector < int > resp(nums.size() , 1e9); 
            int start = 0; 
    
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] < pivot) resp[start++] = nums[i]; 
            }
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] ==  pivot) resp[start++] = nums[i]; 
            }
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] > pivot) resp[start++] = nums[i]; 
            }
    
            return resp; 
        }
    };