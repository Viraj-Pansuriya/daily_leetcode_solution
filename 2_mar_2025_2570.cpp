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
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            
    
           vector < vector < int >> res; 
    
           int i = 0 ; int j = 0; 
           while(i < nums1.size() && j < nums2.size()){
    
                if(nums1[i][0] == nums2[j][0]){
                    res.push_back({nums1[i][0] , nums1[i++][1] + nums2[j++][1]}); 
                }
                else if(nums1[i][0] > nums2[j][0]){
                    res.push_back(nums2[j]); 
                    j++; 
                }
                else {
                    res.push_back(nums1[i++]); 
                }
           }
    
           while(i < nums1.size()) res.push_back(nums1[i++]); 
           while(j < nums2.size()) res.push_back(nums2[j++]); 
           return res; 
    
        }
    };