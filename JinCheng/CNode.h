#ifndef CNODE_H
#define CNODE_H

#include<memory>
template<typename T> class CNode {
private:
	std::shared_ptr<T> tElement;
	std::shared_ptr<CNode<T>> next;
public:
	explicit CNode(T);
	std::shared_ptr<T> Element() const;
	std::shared_ptr<CNode<T>> &Next();
};
#endif // !CNODE_H


template<typename T> CNode<T>::CNode(T tElement)
try :tElement(std::make_shared<T>(tElement)), next(nullptr){

}
catch (...) {
	std::cout << "erro.....   " << std::endl;
}

template<typename T> std::shared_ptr<T> CNode<T>::Element() const {
	return tElement;
}

template<typename T> std::shared_ptr<CNode<T>> &CNode<T>::Next() {
	return next;
}