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
		std::cout << "vvv  " << std::endl;
	}
}