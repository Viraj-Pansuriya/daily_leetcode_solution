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
        int numberOfSubstrings(string s) {
            map < char , int > mp; 
    
            int i = 0 , j = 0;
            int ans = 0; 
            while(j < s.size()){
                mp[s[j]]++; 
                while(mp.size() == 3){
                    ans += (s.size() - j); 
                    mp[s[i]]--; 
                    if(mp[s[i]] == 0) mp.erase(s[i]); 
                    i++; 
                }
                j++; 
            } 
            return ans; 
        }
    };