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
        string shortestCommonSupersequence(string str1, string str2) {
            // take a concat and do something like deletion or what.  
            // longest would be a + b , which contains both strings. 
            // 
    
            int n = str1.size(); 
            int m = str2.size(); 
    
            vector < vector < int >> dp(n+1 , vector < int >(m+1 , 0)); 
            for(int i = 1 ; i  <= n ; i++){
                for(int j = 1 ; j <= m ; j++){
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1]; 
                    }
                    else dp[i][j] = max(dp[i-1][j]  , dp[i][j-1]); 
                }
            }
    
    
            int index1 = n; 
            int index2 = m;
            string ans = ""; 
            while(index1 > 0 && index2 > 0){
                cout<<index1<<" "<<index2<<endl; 
                if(str1[index1-1] == str2[index2-1]){
                    ans += str1[index1-1]; 
                    index1--; 
                    index2--; 
                }
                else if(dp[index1-1][index2] > dp[index1][index2-1]){
                    ans += str1[index1-1]; 
                    cout<<ans<<endl; 
                    index1--; 
                }
                else{
                    ans += str2[index2-1]; 
                    index2--; 
                }
            }
    
            while(index1 > 0){
                ans += str1[--index1];
                 
            }
            while(index2 > 0){
                ans += str2[--index2];
            }
            reverse(ans.begin() , ans.end()); 
            return ans; 
    
        }
        
    };