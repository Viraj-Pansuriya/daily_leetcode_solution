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
        int lenLongestFibSubseq(vector<int>& arr) {
    
            int n = arr.size(); 
            vector < vector < int >> dp(n , vector < int > (n , 0)); 
            map < int , int > mp; 
            int maxi = 0; 
    
            for(int i = 0 ; i < arr.size() ; i++){
                mp[arr[i]] = i; 
    
                for(int j = 0  ; j < i ; j++){
                    int diff = arr[i]- arr[j]; 
                    if(diff < arr[j] && mp.find(diff) != mp.end()){
                        int index = mp[diff]; 
                        dp[i][j] = 1 + dp[j][index]; 
                    } 
    
                    maxi = max(maxi , dp[i][j]); 
                }   
            }
    
            return (maxi == 0) ? 0 : maxi + 2; 
        }
    };