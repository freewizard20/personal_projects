#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
class queue {
private:
	T * data;
	int size;
	int head;
	int tail;
	int maxsize;
public:
	queue();
	queue(int s);
	void enqueue(T da);
	T dequeue();
	void print();
	void printinfo();
};

template<class T>
void queue<T>::printinfo() {
	cout << size << " " << head << " " << tail << endl;
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template<class T>
queue<T>::queue(int s) {
	data = new int[s];
	maxsize = 10;
	size = 0;
	head = 0;
	tail = 0;
}

template<class T>
queue<T>::queue() {
	data = new int[10];
	maxsize = 10;
	size = 0;
	head = 0;
	tail = 0;
}

template<class T>
void queue<T>::enqueue(T da) {
	if (size == maxsize) {
		printf("queue full!\n");
		return;
	}
	data[tail] = da;
	tail++;
	size++;
	if (tail == maxsize) {
		tail = 0;
	}
}

template<class T>
T queue<T>::dequeue() {
	if (size == 0) {
		printf("queue empty!\n");
		return data[head];
	}
	T ret = data[head];
	head++;
	size--;
	if (head == maxsize) {
		head = 0;
	}
	return ret;
}

template<class T>
void queue<T>::print() {
	int i = 0;
	int curr = head;
	while (i < size) {
		if (curr == maxsize) {
			curr = 0;
		}
		cout << data[curr] << " ";
		curr++;
		i++;
	}
	cout << endl;
}

int main2() {
	while (1) {
		char inp[100];
		scanf(" %[^\n]", inp);
		printf("%s\n", inp);
		printf("%d\n", strcmp(inp, "what happened"));
	}
}

int main() {
	queue<int> q;
	while (1) {
		char inp[100];
		char com[20];
		int num[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		printf("what to do next\n");
		scanf(" %[^\n]", inp);
		int i = 0, count = 0;
		int tmpcnt = 0;
		int flag = 0;
		while (1) {
			if (flag == 1) {
				break;
			}
			if (inp[i] == '\0') {
				flag++;
			}
			char tmp[10];
			if (count == 0 && inp[i] != ' ' && flag == 0) {
				com[i] = inp[i];
				i++;
				continue;
			}
			if (count != 0 && inp[i] != ' ' && flag == 0) {
				tmp[tmpcnt] = inp[i];
				tmpcnt++;
				i++;
				continue;
			}
			if (count != 0) {
				for (int z = 0; z < tmpcnt; z++) {
					num[count - 1] = num[count - 1] + (tmp[z]-'0') * pow(10, tmpcnt - z - 1);
				}
				count++;
				tmpcnt = 0;
				i++;
			}
			if (count == 0) {
				com[i] = '\0';
				count++;
				i++;
			}
		}
		if (strcmp(com, "enqueue") == 0) {
			printf("enqueue done\n");
			for (int i = 0; i < count - 1; i++) {
				printf("enqueue %d\n", num[i]);
				q.enqueue(num[i]);
			}
		}
		else if (strcmp(com, "dequeue") == 0) {
			printf("dequeue done\n");
			if (num[0] == 0) {
				int m = q.dequeue();
			}
			for (int i = 0; i < num[0]; i++) {
				q.dequeue();
			}
		}
		else {
			printf("print done\n");
			q.print();
		}
	}
}
