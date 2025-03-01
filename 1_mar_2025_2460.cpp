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
        vector<int> applyOperations(vector<int>& nums) {
            vector < int > copy(nums.begin() , nums.end());
            for(int j = 0 ; j < nums.size() - 1 ; j++){
                if(copy[j] == copy[j+1]){
                    copy[j] *= 2;
                    copy[j+1] = 0; 
                }
            } 
            int p = 0 , q = 0; 
            while(p < nums.size()){
                if(copy[p] != 0) {
                    nums[q] = copy[p]; 
                    q++; 
                }
                p++; 
            }
            while(q < nums.size()) nums[q++] = 0; 
            return nums; 
        }
    };