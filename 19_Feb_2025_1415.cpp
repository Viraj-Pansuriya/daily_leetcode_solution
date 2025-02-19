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
            set < string > st; 
            opr(0 , n , '~' , st, ""); 
            int pick = 0; 
            string ans = ""; 
            for(auto & itr : st){
                pick++;
                if(pick == k){
                    ans = itr;
                    break;
                }
            }
            return ans; 
        }
    
        void opr(int index , int n , char c , set < string > &st , string curr){
    
            if(index == n) {
                st.insert(curr); 
                return ; 
            }
            for(char ch = 'a' ; ch <= 'c' ; ch++){
                if(c != ch){
                    opr(index + 1 , n , ch , st , curr + ch); 
                }
            }
        }
    
    
    };