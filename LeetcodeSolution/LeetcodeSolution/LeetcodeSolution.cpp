// LeetcodeSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Solution.h"
int main()
{
	Solution sol;
	vector<int> v1 = {2,2,1};
	int ret = sol.singleNumber(v1);
	cout << ret <<endl;//return 1

	bool ishappy = sol.isHappy(19);
	cout << ishappy << endl;//return true;

	vector<int> v2 = { -2,1,-3,4,-1,2,1,-5,4 };
	ret = sol.maxSubArray(v2);
	cout << ret << endl;//return 6

	vector<int> v3 = { 0,1,0,3,12 };
	sol.moveZeroes(v3);//Output: [1,3,12,0,0]

	vector<int> v4 = { 7,1,5,3,6,4 };
	ret = sol.maxProfit(v4);
	cout << ret << endl;//return 7

	vector<string> v5 = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> output = sol.groupAnagrams(v5);
	/*
	Output:
		[
		  ["ate","eat","tea"],
		  ["nat","tan"],
		  ["bat"]
		]
	*/

	sol.backspaceCompare("ab#c", "ad#c");//return true

	vector<int> stones = { 2,7,4,1,8,1 };
	sol.lastStoneWeight(stones);//return 1

	vector<int> v6 = { 0,1 };
	sol.findMaxLength(v6);//reutrn 2;
}

