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
            string st[k];  // Maximum possible size of st can be 3^n (assuming n ≤ 10 here for simplicity)
            int index = 0;     // To keep track of how many strings have been added to st
            string ans = "";
            
            // Call the helper function to fill the st array
            opr(0, n, st, "", index, k);
            
            if (index >= k) {
                ans = st[k - 1];
            }
            
            return ans;
        }
    
        void opr(int index, int n, string st[], string curr, int &currIndex, int k) {
            // If we have already collected k strings, we return
            if (currIndex == k) return;
            
            if (index == n) {
                st[currIndex] = curr;
                currIndex++;
                return;
            }
            
            for (char ch = 'a'; ch <= 'c'; ch++) {
                // Skip if the previous character is the same
                if (index > 0 && curr[index - 1] == ch) continue;
                
                opr(index + 1, n, st, curr + ch, currIndex, k);
            }
        }
    };
    