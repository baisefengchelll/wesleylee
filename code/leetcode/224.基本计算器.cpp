/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
// 思路：栈
/// 利用栈记录累加的num
/// 初始化op为‘+’, num为0，遇到数字更新num，直到遇到操作符
/// 操作符'+‘, 压入num为栈顶
/// 操作符'-', 压入-num为栈顶
/// 操作符为'*', 取出top，弹出pop，压入（top * num)
/// 操作符为'-', 取出top, 弹出pop, 压入(top / num)
class Solution
{
public:
    int calculate(string s)
    
};
// @lc code=end
