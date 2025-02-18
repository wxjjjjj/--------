#include <iostream>
#include <string>
#include <stack>
#include <map>
 
using namespace std;
 
stack <char> Operation;      // ���ڴ洢�������ջ
stack <bool> Value;          // ���ڴ洢ֵ��ջ
map <char, int> Priority;    // ���ڴ洢����������ȼ�
 
bool result = 0;             // ��¼���ս��
int total = 0;               // ��¼���ʽ������
 
string expression[100];
 
bool Calculation(char temp) {
 
    bool num_1 = 0, num_2 = 0;
 
    if (temp == '|') {
 
        num_1 = Value.top();    // ��ȡջ��Ԫ��
        Value.pop();            // ����ջ��Ԫ��
        num_2 = Value.top();    // ��ȡջ��Ԫ��
        Value.pop();            // ����ջ��Ԫ��
 
        return (num_1 || num_2);
 
    }
 
    if (temp == '&') {
 
        num_1 = Value.top();    // ��ȡջ��Ԫ��
        Value.pop();            // ����ջ��Ԫ��
        num_2 = Value.top();    // ��ȡջ��Ԫ��
        Value.pop();            // ����ջ��Ԫ��
 
        return (num_1 && num_2);
 
    }
 
    if (temp == '!') {
 
        num_1 = Value.top();    // ��ȡջ��Ԫ��
        Value.pop();            // ����ջ��Ԫ��
        return (!num_1);
 
    }
 
    return 0;
 
}
 
 
void Judgement_1(char temp) {
 
    char top = 0;
 
    /* �ж��Ƿ�Ϊ�� */
    if (Operation.empty() == 1) {
        Operation.push(temp);
        return;
    }
 
    if (temp == '(') {
        Operation.push(temp);
        return;
    }
 
    top = Operation.top();  // �鿴ջ��Ԫ��
 
    /* �������ջ��Ԫ�ط����ȼ�����ջ��Ԫ�أ�����ջ */
    if (Priority[top] >= Priority[temp]) {
        Operation.push(temp);
    }
    else {
        while (1) {
 
            /* ��ջ��Ԫ�ص��� */
            result = Calculation(top);
            Value.push(result);
            Operation.pop();
 
            /* �ж�ջ�Ƿ�Ϊ�� */
            if (Operation.empty() == 1) {
                Operation.push(temp);
                break;
            }
 
            /* �ж�����ջ��Ԫ�غͽ���ջ��Ԫ�����ȼ���ϵ*/
            top = Operation.top();
            if (Priority[top] >= Priority[temp]) {
                Operation.push(temp);
                break;
            }
            
        }
    }
 
 
 
}
 
 
void Judgement_2(char temp) {
 
    char top = 0;
    
    while (1) {
 
        /* �鿴ջ��Ԫ���Ƿ�Ϊ�����ţ������˳������� */
        top = Operation.top();
        if (top == '(') {
            Operation.pop();
            break;
        }
 
        /* ��ջ��Ԫ�� ����*/
        result = Calculation(top);
        Value.push(result);
        Operation.pop();
 
    }
 
}
 
 
 
 
int main() {
 
    /* ������������ȼ�������ԽС�����ȼ�Խ�ߣ�*/
    Priority['('] = 3;
    Priority['|'] = 2;
    Priority['&'] = 1;
    Priority['!'] = 0;
 
    char temp;   // ��ʱ�洢�����ֵ
 
    /* ������� */
    while (1) {
 
        getline(cin, expression[total]);
        if (expression[total].empty() == 1) {
            break;
        }
 
        total++;    // ���ʽ��������
        
    }
 
    /* �жϼ�������� */
    for (int i = 0; i <= total - 1; i++) {
        
        int length = expression[i].length();   // ��ȡ���ʽ����
 
        /* ���ջ */
        while (Operation.empty() != 1) {
            Operation.pop();
        }
 
        while (Value.empty() != 1) {
            Value.pop();
        }
 
 
        /* ������� */
        for (int k = 0; k <= length - 1; k++) {
 
            temp = expression[i][k];
 
            /* �Ի��з���Ϊ�˳������� */
            if (temp == ' ') {
                continue;
            }
 
            if (temp == 'V') {
                Value.push(1);
            }
 
            else if (temp == 'F') {
                Value.push(0);
            }
 
            else if ((temp == '(') || (temp == '!') || (temp == '&') || (temp == '|')) {
                Judgement_1(temp);
            }
 
            else if (temp == ')') {
                Judgement_2(temp);
            }
 
        }
 
        bool judge = 0;   // �ж�ջ�Ƿ�Ϊ��
 
        /* ȷ������Ԫ�س�ջ */
        while (1) {
 
            /* �жϲ�������ջ�Ƿ�Ϊ�� */
            judge = Operation.empty();
            if (judge == 1) {
                result = Value.top();
                if (result == 1) {
                    cout << "Expression " << i + 1 << ": V" << endl;
                }
                else {
                    cout << "Expression " << i + 1 << ": F" << endl;
                }
                break;
            }
 
            temp = Operation.top();
            Operation.pop();
            result = Calculation(temp);
            Value.push(result);
 
        }
 
    }
 
    return 0;
 
}
