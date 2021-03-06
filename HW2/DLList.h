/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_

namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() { return n; }
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) { add(size(), x); }
	virtual T remove(int i);
	virtual void clear();

	virtual bool  IsPalindrome();
	virtual void Rotate(int r);
	virtual void Absorb(DLList<T> &l2);
	virtual DLList deal();
};

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}


template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
	n = 0;
}



template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}


template<class T>
T DLList<T>::get(int i) {
    return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}
//Start of John Shaver's code
template<class T>
bool DLList<T>::IsPalindrome(){
  Node* tmp1 = dummy.next;
  Node* tmp2 = dummy.prev;
  for(int i = 0; i<n/2; i++){
    if(tmp1->x != tmp2->x){
      return false;
    }
    tmp1 = tmp1->next;
    tmp2 = tmp2->prev;
  }
  return true;
}

template<class T> 
  void DLList<T>::Rotate(int r){
  int index = r%n;
  if(index == 0){
    return ;
  }
  Node* tmp = dummy.prev;
    for(int i = 0; i<index; i++ ){
   tmp = tmp->prev;
   }

  
  dummy.prev->next = dummy.next;
  dummy.next->prev = dummy.prev;

  dummy.prev = tmp->next->prev;
  dummy.next = tmp->next;
 
  tmp->next->prev = &dummy;
  tmp->next = &dummy;
 
 }

 
template<class T> 
  void DLList<T>::Absorb(DLList<T> &l2){
  dummy.prev->next = l2.dummy.next;
  l2.dummy.next->prev = dummy.prev;
  dummy.prev = l2.dummy.prev;
  l2.dummy.prev->next = &dummy;
  n = n+l2.n;
  l2.dummy.next = &l2.dummy;
  l2.dummy.prev = &l2.dummy;
  l2.n = 0;
 }
 
template<class T> 
  DLList<T> DLList<T>::deal(){
  
  DLList<T> l2;
  Node* tmp1 = dummy.next;
  Node* tmp2 = &l2.dummy;
  for(int i = 0; i<n/2; i++){
    tmp2->next = tmp1->next;
    tmp1->next = tmp1->next->next;
    tmp1->next->prev = tmp2->next->prev;
    tmp2->next->prev = tmp2;
    tmp2->next->next = &l2.dummy;
    l2.dummy.prev = tmp2->next;
    
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  
  l2.n = n/2;
  n = n-l2.n;
  
  return l2;
 }
 
 
//End of John SHaver's code
} /* namespace ods */
#endif /* DLLIST_H_ */
