#include <bits/stdc++.h>
using namespace std;
namespace MyQueue {
	const int MaxSize = 5e5 + 10; //在第七周作业的C题中，你必须使用该框架，并且不得修改本常量，也不得用任何方式，去明显增加队列的容量
	struct queue {
		int item[MaxSize], //存储元素的数组 
		limit, //容量限制
		head, //队首下标
		tail; //队尾下标
		int headReturn = 0;
		int tailReturn = 0;
		//本题需要你实现一个循环利用空间的队列
		//你并不需要增加其他数据成员，也不需要在item中写入非队列元素的数据，也不需要全局变量或者什么静态局部变量就能够实现以下几个功能
		//但如果你想不到怎么做，可以增加其他数据成员或全局变量, 但不能明显增加队列容量
		void init(int n) {//初始化为一个容量限制为limit的队列
			for (int i = 0; i < n; i++)
			{
				item[i] = 0;
			} 
			limit = n;
			head = 0;
			tail = 0;
		}
		bool empty() {//探测是否队列为空
			if (((tail - head) == 0) && (tailReturn == headReturn)) return true;
			else return false;
		}
		bool full() {//探测队列是否为满
			int tail1;
			if ((tail <= head) && (tailReturn > headReturn)) tail1 = tail + limit;
			else tail1 = tail;
			if ((tail1 - head) == (limit)){
				return true;
			}
			else {
				return false;
			}
		}
		void insert(int value) {//在队尾插入一个元素
				item[tail] = value;
				tail++;
				if (tail >= limit) {
					tail -= limit;
					tailReturn++;
				}
				
			}
		
		int pop() {//弹出队首，并将原来的队首的元素作为返回值
			if (!empty())
			{
				int temp = item[head];
				item[head] = 0;
				if(!empty()) 
				{
					head++;
				}
				if (head >= limit) {
					head -= limit;
					headReturn++;
				}
				return temp;
			}
		}

	};
}
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	using MyQueue::queue;
	queue q;
	q.init(n);
	while (m--) {
		int op, x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			if (!q.full()) {
				q.insert(x);
			}
		} else {
			if (!q.empty()) {
				cout << q.pop() << endl;
			}
		}
	}
	return 0;
}
