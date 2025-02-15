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
        int punishmentNumber(int n) {
            int count = 0; 
            for(int i = 1 ; i <= n ; i++){
                bool able = check(i); 
                if(able)
                    count += (i*i); 
            }
            return count; 
        }
    
        bool check(int i){
            int sum = i*i; 
            string num = to_string(i*i);
            int index = 0; 
            return calc(i , index , num);  
        }
    
    
        bool calc(int sum , int index , string num){
            if(index == num.size()) return sum == 0;
            string temp = ""; 
            bool chk = false; 
            for(int i = index ; i < num.size() ; i++){
                temp += num[i]; 
                int tt = stoi(temp);
                if(tt > sum) return false; 
                chk = calc(sum - tt , i+1 , num); 
                if(chk) return true; 
            } 
            return chk; 
        }
    };