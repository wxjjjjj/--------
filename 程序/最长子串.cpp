#include <iostream>  
#include <stack>  
#include <string>  
 
using namespace std;
 
pair<int, int> longestValidParentheses(const string& s) {
    stack<int> stk; // �洢����  
    stk.push(-1);   // ��ʼ��Ϊ-1�����㴦���һ���ַ�  
    int maxLength = 0;
    int startIndex = 0;
 
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        }
        else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i); // �Ƿ������ţ���¼λ��  
            }
            else {
                int length = i - stk.top();
                if (length > maxLength) {
                    maxLength = length;
                    startIndex = stk.top() + 1; // ��ʼλ����ջ����������һ��λ��  
                }
            }
        }
    }
 
    return { maxLength, startIndex };
}
 
int main() {
    string input;
    cin >> input;
 
    pair<int, int> result = longestValidParentheses(input);
 
    cout << result.first << " " << result.second << endl;
 
    return 0;
}
