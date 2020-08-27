/*--------------------------------------------------------------------------|
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。	|
																			|
有效字符串需满足：															|
																			|
左括号必须用相同类型的右括号闭合。											|
左括号必须以正确的顺序闭合。												|
注意空字符串可被认为是有效字符串。											|
																			|
示例 1:																		|
																			|
输入: "()"																	|
输出: true																	|
示例 2:																		|
																			|
输入: "()[]{}"																|
输出: true																	|
示例 3:																		|
																			|
输入: "(]"																	|
输出: false																	|
示例 4:																		|
																			|
输入: "([)]"																|
输出: false																	|
示例 5:																		|
																			|
输入: "{[]}"																|
输出: true																	|
																			|
来源：力扣（LeetCode）														|
链接：https://leetcode-cn.com/problems/valid-parentheses					|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。		|
---------------------------------------------------------------------------*/

/*	栈
*	思路对了，使用的方法不对，导致上个版本内存占用较高。应该想到用栈的
* 
*	执行用时：4 ms, 在所有 C++ 提交中击败了46.94%的用户
*	内存消耗：6.3 MB, 在所有 C++ 提交中击败了88.62%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isValid(string s)
{
	int n = s.size();

	if (n == 0)
	{
		return true;
	}

	stack<char> now;
	for (char c : s)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			now.push(c);
			continue;
		}
		if (c == ' ')
		{
			continue;
		}
		else
		{
			if (now.size() == 0)
			{
				return false;
			}
			if (c == ')'&& now.top() == '(')
			{
				now.pop();
				continue;
			}
			if (c == ']' && now.top() == '[')
			{
				now.pop();
				continue;
			}
			if (c == '}' && now.top() == '{')
			{
				now.pop();
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	if (now.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	string s = "(([]){})";

	//

	//

	cout << isValid(s) << endl;
}