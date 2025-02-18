#include <iostream>
#include <queue>
#include <deque>
 
using namespace std;
 
int Queue[10010] = { 0 };     /* �洢���ݵĶ��� */
int maxsize = 0;
int total = 0;
 
 
 queue<int> que;       // �����У����ڴ洢Ԫ��
 deque<int> deq;       // �������У����ڴ洢��ǰ���ֵ
 
   
/* ���ص�ǰ���е����ֵ���������Ϊ���򷵻� -1 */
void Getmax() {
 
    if (que.empty() == 1) {
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << deq.front() << endl;
    }
 
}
 
 
/* �ڶ���ĩβ���һ����Ԫ�� */
void Enqueue(int value) {
 
    if (total == maxsize) {
        cout << "Queue is Full" << endl;
    }
    else {
 
        que.push(value); // ����Ԫ�ؼ���������
 
        /* ά�� deq���Ƴ�����С����ֵ��Ԫ�� */
        while ((deq.empty() != 1) && (deq.back() < value)) {
            deq.pop_back();
        }
 
        deq.push_back(value); // ����ֵ���� deq
 
        total++;
 
    }
 
}
 
 
/* �Ƴ������ض��е�ǰ��Ԫ�� */
void Dequeue() {
 
    if (que.empty() == 1) {
        cout << "Queue is Empty" << endl;
        return;
    }
 
    int val = que.front(); // ��ȡ����ǰ���Ԫ��
 
    /* ����Ƴ���Ԫ���ǵ�ǰ���ֵ����Ҳ�� deq ���Ƴ� */
    if (val == deq.front()) {
        deq.pop_front();
    }
 
    cout << que.front() << endl;
    que.pop(); // �Ƴ�ǰ���Ԫ��
 
    total--;
 
}
 
 
void Quit() {
 
    while(que.empty() != 1) {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}
 
int main() {
 
    cin >> maxsize;
 
    string Operation;
    int value = 0;
 
    while (1) {
 
        cin >> Operation;
        if (Operation[0] == 'q') {
            Quit();
            break;
        }
 
        if (Operation[0] == 'm') {
            Getmax();
        }
        else if (Operation[0] == 'd') {
            Dequeue();
        }
        else {
            cin >> value;
            Enqueue(value);
        }
 
    }
 
 
}
