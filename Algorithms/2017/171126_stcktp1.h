#pragma once
#ifndef STCKTP1_H_
template <class Type> class Stack {
private:
	enum { SIZE = 10 };
	int stacksize;
	Type * items;
	int top;
public:
	explicit Stack(int ss = SIZE);  // myStack = 1.3 같은 구문을 못 쓰게 만든다.
	Stack(const Stack & st); // 원래값을 변경할 수 없는 참조
	~Stack() { delete[] items; }
	bool isempty() const { return top == 0; }
	bool isfull() const { return top == stacksize; }
	bool push(const Type & item); // 참조로 보내되 인자로 보낸 값 변경 X
	bool pop(Type & item);
	Stack & operator=(const Stack& st);
};

template <class Type> Stack<Type> ::Stack(int ss) : stacksize(ss), top(0) { // stacksize를 ss로 초기화, top을 0으로 초기화
	items = new Type[stacksize];
}

template <class Type> Stack<Type>::Stack(const Stack &st) {
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++) {
		items[i] = st.items[i];
	}
}

template <class Type> bool Stack<Type>::push(const Type & item) {
	if (top < stacksize) {
		items[top++] = item;
		return true;
	}
	else {
		return false;
	}
}

template <class Type> bool Stack<Type>::pop(Type & item) {
	if (top >0) {
		item = items[--top];
		return true;
	}
	else {
		return false;
	}
}

template <class Type> Stack <Type> & Stack<Type>::operator=(const Stack<Type> &st) {
	if (this == &st)
		return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++) {
		items[i] = st.items[i];
	}
	return *this
}

#endif
