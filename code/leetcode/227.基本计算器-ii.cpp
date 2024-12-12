/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        char op = '+';
        int num = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isdigit(s[i]))
            {
                num = num * 10 + (ch - '0'); // 记录完成num
            }
            if (!isdigit(ch) && ch != ' ' || i == s.size() - 1) // 保证最后一个数字被记录
            {
                switch (op)
                {
                case '+':
                {
                    st.push(num);
                    break;
                }
                case '-':
                {
                    st.push(-num);
                    break;
                }
                case '*':
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                    break;
                }
                case '/':
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                    break;
                }
                }
                op = ch; // 更新op
                num = 0; // 更新num
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
// @lc code=end
