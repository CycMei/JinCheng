#ifndef CLIST_H
#define CLIST_H

#include<Windows.h>
#include"CNode.h"
template<typename T> class CList {
private:
	std::shared_ptr<CNode<T>> head;
	DWORD dwCount;
public:
	CList();
	explicit CList(T*);
	virtual ~CList() {

	}
	void Insert(T);
	bool Remove(T);
	void Append(T tElement);
	DWORD Count() const {
		return dwCount;
	}
	T *Head() {
		return &*(head->Element());
	}
	T *GetFirst() {
		return head != nullptr ? Head() : nullptr;
	}
	T *GetLast();
private:
	void tempForAppend(std::shared_ptr<CNode<T>>&, T tElement);
};
#endif // !CLIST_H

template<typename T> CList<T>::CList()
try :head(nullptr), dwCount(0){

}
catch (...) {

}

template<typename T> CList<T>::CList(T *tElement)
try :dwCount(1), head(std::make_shared<CNode<T>*>(new CNode<T>(tElement))){

}
catch (...) {
	std::cout << "erro....1.....   " << std::endl;
}

template<typename T> void CList<T>::Insert(T tElement) {
	if (!head) {
		head = std::make_shared<CNode<T>>(CNode<T>(tElement));
		++dwCount;
		return;
	}
	std::shared_ptr<CNode<T>> tmp = head;
	head = std::make_shared<CNode<T>>(CNode<T>(tElement));
	head->Next() = tmp;
	++dwCount;
}

template<typename T> bool CList<T>::Remove(T tElement) {
	if (!head)
		return false;
	if (*(head->Element()) == tElement) {
		head = head->Next();
		--dwCount;
		return true;
	}
	std::shared_ptr<CNode<T>> tmp = head;
	std::shared_ptr<CNode<T>> lst = head->Next();
	while (lst) {
		if (*(lst->Element()) == tElement) {
			tmp->Next() = lst->Next();
			--dwCount;
			return true;
		}
		lst = lst->Next();
		tmp = tmp->Next();
	}
	return false;
}

template<typename T> void CList<T>::Append(T tElement) {
	tempForAppend(head, tElement);
}
template<typename T> 
void CList<T>::tempForAppend(std::shared_ptr<CNode<T>> &node, T tElement) {
	if (!node) {
		node = std::make_shared<CNode<T>>(tElement);
		++dwCount;
		return;
	}
	tempForAppend(node->Next(),tElement);
}

template<typename T> T *CList<T>::GetLast() {
	if (head) {
		std::shared_ptr<CNode<T>> tmp = head;
		while (tmp->Next()) {
			tmp = tmp->Next();
		}
		return &*(tmp->Element());
	}
}



void myCList() {
	CList<int> clist;
	clist.Insert(32);

	clist.Insert(23);
	//clist.Remove(2);
	clist.Append(50);
	clist.GetFirst();
	clist.GetLast();
}