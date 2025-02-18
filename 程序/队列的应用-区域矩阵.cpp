#include <iostream>
#include <vector>
 
using namespace std;
 
int line = 0;
int row = 0;
int flag = 0;
int total = 0;
int result = 0;
 
class Node_1 {
public:
 
    int m = 0;
    int n = 0;
 
};
 
bool region[1010][1010] = { 0 };  /* ������� */
 
vector <Node_1> ones; 
 
void Seek(int x, int y) {
 
    region[x][y] = 0;   // �������ĵ���0
 
    if ((x != 0) && (x != (line - 1)) && (y != 0) && (y != (row - 1))) {
        flag = 1;
    }
 
    /* �ж��Ƿ����ϱ߽� */
    if (x != 0) {
        if (region[x - 1][y] == 1) {
            if (((x - 1) != 0) && ((x - 1) != (line - 1)) && (y != 0) && (y != (row - 1))){
                flag = 1;
            }
            Seek(x - 1, y);
        }
    }
 
 
    /* �ж��Ƿ����±߽� */
    if (x != line - 1) {
        if (region[x + 1][y] == 1) {
            if (((x + 1) != 0) && ((x + 1) != (line - 1)) && (y != 0) && (y != (row - 1))) {
                flag = 1;
            }
            Seek(x + 1, y);
        }
    }
 
 
    /* �ж��Ƿ�����߽� */
    if (y != 0) {
        if (region[x][y - 1] == 1) {
            if ((x != 0) && (x != (line - 1)) && ((y - 1) != 0) && ((y - 1) != (row - 1))) {
                flag = 1;
            }
            Seek(x, y - 1);
        }
    }
 
 
    /* �ж��Ƿ����ұ߽� */
    if (y != row - 1) {
        if (region[x][y + 1] == 1) { 
            if ((x != 0) && (x != (line - 1)) && ((y + 1) != 0) && ((y + 1) != (row - 1))) {
                flag = 1;
            }
            Seek(x, y + 1);
        }
    }
 
}
 
 
 
int main() {
 
    /* �����к��� */
    cin >> line >> row;
 
    bool temp = 0;  // ��ʱ�洢�����ֵ
 
    /* ����������� */
    for (int i = 0; i <= line - 1; i++) {
        for (int k = 0; k <= row - 1; k++) {
            
            cin >> region[i][k];
            temp = region[i][k];
            
            /* �洢ֵΪ1�Ľڵ㣬��������������Լ����1��ʱ�� */
            if (temp == 1) {
                ones.resize(total + 1);
                ones[total].m = i;
                ones[total].n = k;
                total++;
            }
 
        }
    }
    
    /* Ѱ����������ͨ���� */
    for (int num = 1; num <= total; num++) {
 
        int x = ones[num - 1].m;
        int y = ones[num - 1].n;
 
        /* �ж��Ƿ�Ϊ1 */
        if (region[x][y] == 1) {
 
            flag = 0;  // ��ǻָ�Ϊ0
            result++;
            Seek(x, y);
            if (flag == 0) {
                result--;
            }
 
        }
 
    }
 
    cout << result << endl;
 
    return 0;
}
