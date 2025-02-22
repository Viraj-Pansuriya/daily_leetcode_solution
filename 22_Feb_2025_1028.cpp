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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        unordered_map < int , TreeNode* > store; 
        TreeNode* recoverFromPreorder(string traversal) {
            // we have to go for a latest previous node: 
    
            int index = 0; 
            int number = 0; 
    
            while(index < traversal.size() && traversal[index] != '-'){
                number = number*10 + (traversal[index] -'0'); 
                index++; 
            }
            TreeNode* root = new TreeNode(number);
            store[0] = root; 
            opr(traversal , index); 
            return root; 
    
        }
    
        void opr(string trv , int index){
            if(index >= trv.size()) return ; 
    
            int depth = 0; 
            while(trv[index] == '-'){
                depth++; 
                index++; 
            } 
            int number = 0; 
            while(index < trv.size() && trv[index] != '-'){
                number = number*10 + (trv[index] -'0'); 
                index++;   
            }
    
            TreeNode* root = store[depth-1];
            TreeNode* currNode = new TreeNode(number); 
            if(root->left == nullptr){
                root->left = currNode; 
            }
            else root->right = currNode; 
            store[depth] = currNode; 
            opr(trv , index);
        }
    
    
    
    };