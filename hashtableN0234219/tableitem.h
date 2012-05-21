#include <string>
#include <vector>


//Enumeration to assist with open addressing
enum BucketState {
		EMPTY,
		FULL,
		DELETED
};

template <class T>
class TableItem {

private:
	std::string key;
	T value;
	BucketState status;

public:

	TableItem(); 
	TableItem(std::string key, T value);
	std::string getKey();
	void setKey(std::string key);
	T getValue();
	void setValue(T value);
	BucketState getState();
	void setState(BucketState status);
	bool operator == (TableItem& toCompare);
	bool operator != (TableItem& toCompare);
	void operator = (TableItem& equals);

};

template<class T>
TableItem<T>::TableItem(std::string key, T value) {
	this->key = key;
	this->value = value;
	this->status = FULL;
};

template<class T>
TableItem<T>::TableItem() {
	this->status = EMPTY;
}

template<class T>
void TableItem<T>::setValue(T value) {
	this->value = value;
};

template<class T> 
std::string TableItem<T>::getKey() {
	return this->key;
};

template<class T>
void TableItem<T>::setKey(std::string key) {
	this->key = key;
}

template<class T>
T TableItem<T>::getValue() {
	return this->value;
};

template<class T>
BucketState TableItem<T>::getState() {
	return this->status;
}

template<class T> 
void TableItem<T>::setState(BucketState status) {
	this->status = status;
}

template <class T>
bool TableItem<T>::operator == (TableItem& toCompare)
{
	return ((this->getKey() == toCompare.getKey()) && (this->getValue() == toCompare.getValue()));
};

template <class T>
bool TableItem<T>::operator != (TableItem& toCompare)
{
	return ((this->getKey() != toCompare.getKey()) && (this->getValue() != toCompare.getValue()));
};

template <class T>
void TableItem<T>::operator = (TableItem& equals) 
{
	this->key = equals.getKey();
	this->value = equals.getValue();
};


