# leetcode from 0 to 100

- [top100 liked questions](https://leetcode.com/problemset/top-100-liked-questions/)

---

- **two sum**
字典方式
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

// 这种写法更清晰一些：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target-nums[i];
            if (m.find(key)!=m.end()) {
                return {i, m[key]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
```

- **70. climbing stairs**
```cpp

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> path(n);
        path[0]=1;path[1]=2;
        for(int i=2;i<n;++i){
            path[i] = path[i-1]+path[i-2];
        }
        return path.back();
    }
};
```
- **136. Single Number**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i){
            res^=nums[i];
        }
        return res;
        }
};

```
- 104. Maximum Depth of Binary Tree
```cpp

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }
};

```

- 206. Reverse Linked List
```cpp
      ListNode *reverseList(ListNode *head){
            if(!head||!head->next) return head;
            ListNode *p = head;
            ListNode *q = head->next;
            p->next=NULL;
            while(q){
                ListNode * tmp = q->next;
                q->next = p;
                p=q;
                q=tmp; 
            }
            return p;
        }

```
- 283. Move Zeroes
```cpp 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=0) return;
        int left_pos = 0;
        while(nums[left_pos]!=0){
            left_pos++;
        }
        int right_pos = left_pos+1;
        while(right_pos<nums.size()){
            if(nums[right_pos]!=0){
                swap(nums[left_pos++],nums[right_pos]);
            }
            right_pos++;
        }  
    }
};

```
- 169. Majority Element
```cpp
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int len = nums.size();
        int cnt = 1;
        int candidate = nums[0];
        for(int i = 1;i<len;++i){
            if(cnt==0){
                candidate = nums[i];
                cnt = 1;
            }else{
                if(candidate==nums[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
    return candidate;
};
```



-
-
-
-
-
-
-
-


