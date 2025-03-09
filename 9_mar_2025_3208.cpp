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
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int ans = 0; 
            int i = 0; 
            for(int j = 1 ; i < (colors.size()) && j < 2*colors.size() ; j++){
                if(colors[(j-1 + colors.size()) % colors.size()]  == colors[j % colors.size()])
                    i = j; 
                if((j - i + 1) > k) i++; 
                if(i == colors.size()) break; 
                if((j - i + 1) == k) ans++; 
            }
            return ans; 
    
    
    
        }
    };