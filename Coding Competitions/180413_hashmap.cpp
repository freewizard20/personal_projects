#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class HashNode {
private:
	K key;
	V value;
	HashNode * next;
public:
	HashNode(K k, V v) : key(k), value(v), next(NULL) {}
	V getValue() { return value; }
	K getKey() { return key; }
	HashNode<K,V> * getNext() { return next;}
	void setNext(HashNode<K,V> * root) { next = root; }
	void removeNext() {
		if (next != NULL)  next = next->next; 
	}
};

template <typename K, typename V>
class myTable {
private:
	HashNode<K,V> ** table;
	int size;
	int hash(K k) {
		return reinterpret_cast<int>(k) % size;
	}
public:
	myTable(int s) : size(s) {
	}

	~myTable() {
		for (int i = 0; i < size; i++) {
			HashNode<K,V> * move = table[i];
			while (move != NULL) {
				HashNode<K, V> * prev = move;
				move = move->getNext();
				delete prev;
			}
		}
		delete [] table;
	}
	HashNode<K,V> * find(K k, V v) {
		if (table[hash(k)] != NULL) {
			HashNode<K,V> * runner = table[hash(k)];
			while (runner != NULL) {
				if (v == runner->getValue()) return runner;
			}
		}
		return NULL;
	}
	void insert(K k, V v) {
		if (table[hash(k)] == NULL) {
			table[hash(k)] = new HashNode<K, V>(k, v);
		}
		else {
			HashNode<K, V> * runner = table[hash(k)];
			while (runner->getNext() != NULL) {
				runner = runner->getNext();
			}
			runner->setNext(new HashNode<K, V>(k, v));
		}
	}
	void remove(K k, V v) {
		HashNode<K, V> * runner = table[hash(k)];
		if (runner != NULL) {
			if (runner->getValue() == v) {
				table[hash(k)] = runner->getNext();
				delete runner;
				return;
			}
			// search for v
			while (runner != NULL) {
				HashNode<K, V> * prev = runner;
				runner = runner->getNext();
				if (runner->getValue() == v) {
					prev->setNext(runner->getNext());
					delete runner;
					return;
				}
			}
		}
	}
};

int main() {
	myTable<int,int> sam(20);
	sam.insert(3, 3);
	sam.insert(4, 3);
	HashNode<int,int> * ret = sam.find(3,3);
	if (ret != NULL) {
		cout << ret->getKey() << " " << ret->getValue() << endl;
	}
	while(1){}
	return 0;
}
