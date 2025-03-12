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
        int maximumCount(vector<int>& nums) {
            
            int left = 0 , right = nums.size()- 1; 
            int negIndex = -1 , posIndex = -1; 
    
            while(left < right){
                int mid = (left + right) / 2; 
                if(nums[mid] < 0){
                    left = mid + 1; 
                    negIndex = mid; 
                }
                else{
                    right = mid - 1;
                } 
            }
    
            if(nums[left] < 0)
                negIndex = left; 
    
            left = 0 , right = nums.size()-1; 
    
            while(left < right){
                int mid = (left + right)/ 2; 
                if(nums[mid] > 0){
                    right = mid - 1; 
                    posIndex = mid; 
                }
                else left = mid + 1; 
            }
    
            if(nums[left] > 0)
                posIndex = left; 
    
            if(negIndex == -1 && posIndex == -1)return 0; 
            if(negIndex == -1) return nums.size() - posIndex; 
            if(posIndex == -1) return negIndex + 1;
    
            return max(negIndex + 1 , (int)nums.size() - posIndex);  
    
        }
    };