#include <iostream>  
#include <stack>  
#include <string>  
#include <sstream> // ����istringstream����������ض�������ʵ����û���õ�
#include<algorithm>
 
using namespace std;
 
// �жϸ����ĳ�վ�����Ƿ�Ϸ�  
bool isValidOutSequence(const string& inSequence, const string& outSequence) {
    stack<char> stk;
    int i = 0, j = 0;
    while (j < inSequence.length()) {
        stk.push(inSequence[j++]);
        while (!stk.empty() && stk.top() == outSequence[i]) {
            stk.pop();
            i++;
        }
    }
    return i == outSequence.length();
}
 
int main() {
    string inSequence, outSequence, result;
 
    // ��ȡ��һ�е���վ����  
    getline(cin, inSequence);
    // �Ƴ����ܵĻ��з�����Ȼgetlineͨ�����ᱣ�����з���  
    inSequence.erase(remove_if(inSequence.begin(), inSequence.end(), ::isspace), inSequence.end());
 
    // ��ȡ�����ĳ�վ���У�ֱ��EOF  
    string line;
    while (getline(cin, line)) {
        // �Ƴ����ܵĻ��з��Ϳո���Ȼgetlineͨ�����ᱣ�����з������������ȷ��û�ж���Ŀո�  
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        outSequence = line; // ��ÿ�����ݸ�ֵ����վ���б���  
        if (isValidOutSequence(inSequence, outSequence)) {
            result += "yes\n";
        }
        else {
            result += "no\n";
        }
    }
 
    // ������  
    cout << result;
 
    return 0;
}
