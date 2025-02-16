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
        vector<int> constructDistancedSequence(int n) {
            vector<int> result(2 * n - 1, 0);
            vector<bool> used(n + 1, false);
            backtrack(result, used, n, 0);
            return result;
        }
    
    private:
        bool backtrack(vector<int>& result, vector<bool>& used, int n, int index) {
            while (index < result.size() && result[index] != 0) {
                index++;
            }
            if (index == result.size()) {
                return true;
            }
    
            for (int i = n; i >= 1; i--) {
                if (used[i]) continue;
    
                if (i == 1) {
                    result[index] = 1;
                    used[1] = true;
                    if (backtrack(result, used, n, index + 1)) return true;
                    result[index] = 0;
                    used[1] = false;
                } else if (index + i < result.size() && result[index + i] == 0) {
                    result[index] = i;
                    result[index + i] = i;
                    used[i] = true;
                    if (backtrack(result, used, n, index + 1)) return true;
                    result[index] = 0;
                    result[index + i] = 0;
                    used[i] = false;
                }
            }
            return false;
        }
    };