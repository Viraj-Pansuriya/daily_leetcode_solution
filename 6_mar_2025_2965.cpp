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
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            // it is fix that it is inside 1 to (n*n); 
            int n = grid.size(); 
            vector < int > store((n*n) + 1 , 0); 
    
            for(auto & x : grid){
                for(auto & y : x){
                    store[y]++; 
                }
            }
    
            vector < int > ans(2); 
            for(int i = 1 ; i <= n*n ;  i++){
                if(store[i] == 0) ans[1] = i;
                else if(store[i] == 2) ans[0] = i; 
            }
            return ans; 
        }
    };