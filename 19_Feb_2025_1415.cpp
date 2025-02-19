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
        string getHappyString(int n, int k) {
            vector < string > st; 
            opr(0 , n , st, "" , k); 
            int pick = 0; 
            string ans = ""; 
            if(st.size() >= (k)){
                ans = st[k-1]; 
            }
            return ans; 
        }
    
        void opr(int index , int n , vector < string > &st , string curr , int k){
            if(st.size() == k) return ; 
            if(index == n) {
                st.push_back(curr); 
                return ; 
            }
            for(char ch = 'a' ; ch <= 'c' ; ch++){
                if(index > 0 && curr[index-1] == ch) continue; 
                opr(index + 1 , n , st , curr + ch , k); 
                
            }
        }
    };