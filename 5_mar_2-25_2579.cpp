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
        long long coloredCells(int n) {
            
            // each time you can see 4 aditional box are coming.
            // it is forming some kind of arithmatic sequence. which will have difference as 4.   
            long long mul  = 1LL*(n) * 1LL*(n-1)/2; 
            mul *= 1LL*4; 
            mul++;
            return mul; 
        }
};