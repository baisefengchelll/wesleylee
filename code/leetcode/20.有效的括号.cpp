/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// 思路：栈
/// 首先，判断字符串长度是否为奇数。如果为奇数，返回false。
/// 遍历字符串，遍历到左括号，将其压入栈顶。遍历到右括号，判断其与栈顶左括号比较
/// 如果不匹配，返回false
/// 最后判断栈是否为空，若为空，返回true;反之返回false。
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int size = s.size();
        if (size % 2)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false; // 遍历到右括号，栈为空，表示没有左括号与之匹配
                }
                char ch = st.top();
                if (s[i] == ')' && ch == '(' ||
                    s[i] == ']' && ch == '[' ||
                    s[i] == '}' && ch == '{')
                {
                    st.pop(); // 如果匹配，弹出栈顶元素
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end
