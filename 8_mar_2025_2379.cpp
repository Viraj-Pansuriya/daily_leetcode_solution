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
        int minimumRecolors(string blocks, int k) {
            int maxi = k; 
            int curr = 0; 
            int i = 0 , j = 0; 
            for(int i = 0 ; i < k-1; i++){
                if(blocks[i]  == 'B') curr++; 
            }
            for(int i = k-1 ; i < blocks.size() ; i++){
                if(blocks[i] == 'B') curr++; 
                maxi = min(maxi , k - curr); 
                if(blocks[i-k + 1] == 'B') curr--;  
            }
            return maxi;  
        }
    };