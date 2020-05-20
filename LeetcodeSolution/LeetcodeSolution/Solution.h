#pragma once
#include<vector>
#include<string>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
private:
	stack<char> removeBackSpace(string S);
public:
	Solution();
	virtual ~Solution();
	int singleNumber(vector<int>& nums);
	bool isHappy(int n);
	int maxSubArray(vector<int>& nums);
	void moveZeroes(vector<int>& nums);
	int maxProfit(vector<int>& prices);
	vector<vector<string>> groupAnagrams(vector<string>& strs);

	ListNode* middleNode(ListNode* head);
	bool backspaceCompare(string S, string T);
	int lastStoneWeight(vector<int>& stones);
	int findMaxLength(vector<int>& nums);
};

