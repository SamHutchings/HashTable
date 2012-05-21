#include "tableitem.h"
#include <string>
#include <vector>
#include <iostream>

template <class T>
class HashTable
{
	friend std::ostream& operator<<(std::ostream& os, HashTable<T>& hashTable);
public:
	HashTable();
	void insert(std::string key, T value);
	T get(std::string key);
	bool remove(std::string key);
	bool exists(std::string key);
	double checkCapacity();
	void increaseCapacity();
	void shrink();
	
	void viewStats();
	~HashTable();
	

private:
	//monitoring statistics
	int inserts;
	int collisions;
	int removals;
	int resizes;


	int probeInterval;
	double maxCapacity;

	//hash function
	int hash(std::string key); 

	//helper function for both shrink and increase size
	void newTable(int size);

	std::vector<TableItem<T>> table;
	static const int DEFAULT_TABLE_SIZE = 23;
	int TABLE_SIZE;

};

template <class T>
HashTable<T>::HashTable() {
	//initialise performance monitoring

	inserts = 0;
	collisions = 0;
	removals = 0;
	resizes = 0;
	
	//initialise probe interval

	probeInterval = 1;
	//initialise maximum capacity level
	maxCapacity = 0.7;
	TABLE_SIZE = DEFAULT_TABLE_SIZE;
	table.resize(TABLE_SIZE);
};

template <class T>
HashTable<T>::~HashTable() {
};

template <class T>
void HashTable<T>::insert(std::string key, T value) {
	int hashed = hash(key);

	//checking for collisions - if slot is full but key is different, probe for empty slot
	while (table.at(hashed).getState() == FULL && table.at(hashed).getKey() != key) {
		collisions++;
		if(hashed < TABLE_SIZE - probeInterval) {
				hashed += probeInterval;
			} else {
				hashed = (hashed + probeInterval) - TABLE_SIZE;
			}
	}
	inserts++;
	table.at(hashed).setKey(key);
	table.at(hashed).setValue(value);
	table.at(hashed).setState(FULL);

	//check capacity to make sure threshold hasn't been reached
	if(checkCapacity() > maxCapacity) {
		resizes++;
		increaseCapacity();
	}
	
};

template <class T>
T HashTable<T>::get(std::string key) {
	int hashed = hash(key);
	while((table.at(hashed).getState() == FULL && table.at(hashed).getKey() != key) ||
		table.at(hashed).getState() == DELETED) {
			if(hashed < TABLE_SIZE - probeInterval) {
				hashed += probeInterval;
			} else {
				hashed = 0;
			}
	}
	if(table.at(hashed).getKey() == key) {
		return table.at(hashed).getValue();
	} else {
		T empty;
		return empty;	
	}
};


template <class T> 
bool HashTable<T>::remove(std::string key) {
	int hashed = hash(key);
	while(!table.at(hashed).getState() == FULL && table.at(hashed).getKey() != key) {
		if(table.at(hashed).getState() == EMPTY) {
			return false;
		} else {
			if(hashed < TABLE_SIZE - probeInterval) {
				hashed += probeInterval;
			} else {
				hashed = 0;
			}
		}
	} 
	table.at(hashed).setState(DELETED);
	removals++;
	return true;

};

template <class T> 
bool HashTable<T>::exists(std::string key) {
	int hashed = hash(key);
	while(table.at(hashed).getKey() != key) {
		if(table.at(hashed).getState() == EMPTY) {
			return false;
		} else {
			if(hashed < TABLE_SIZE - probeInterval) {
				hashed += probeInterval;
			} else {
				hashed = 0;
			}
		}
	}
	return true;	
};


template <class T>
double HashTable<T>::checkCapacity() {
	int full = 0;
	for each (TableItem<T> current in table) {
		if(current.getState() == FULL) {
			full++;
		}
	}
	double result = (double) full / (double) TABLE_SIZE;
	return result;
}

template <class T>
void HashTable<T>::increaseCapacity() {
	newTable(TABLE_SIZE*2);
}


template <class T>
void HashTable<T>::shrink() {
	if(checkCapacity() < 0.3) {
		newTable(TABLE_SIZE/2);
	} else {
		return;
	}
}

template<class T> 
void HashTable<T>::newTable(int size) {
	vector<TableItem<T>> newTable;
	TABLE_SIZE = size;
	newTable.resize(TABLE_SIZE);

	for each (TableItem<T> current in table) {
		if(current.getState() == FULL) {
			int hashed = hash(current.getKey());
			while (newTable.at(hashed).getState() == FULL && newTable.at(hashed).getKey() != current.getKey()) {
				if(hashed < TABLE_SIZE - 1) {
					hashed++;
				} else {
					hashed = 0;
				}
			}
			newTable.at(hashed).setKey(current.getKey());
			newTable.at(hashed).setValue(current.getValue());
			newTable.at(hashed).setState(FULL);
		}
	}
	table = newTable;
}

template <class T>
int HashTable<T>::hash(std::string key) {

	unsigned i, sum;
	for (sum = 0, i=0; i < key.size(); i++) {
		sum+= key[i];
	}
	return sum % TABLE_SIZE;
};

template <class T> 
void HashTable<T>::viewStats() {
	cout << "Inserts: " << inserts << endl;
	cout << "Collisions: " << collisions << endl;
	cout << "Removals: " << removals << endl;
	cout << "Resizes: " << resizes << endl;
	cout << "Current usage: " << checkCapacity() << endl;
};



template <class T>
std::ostream& operator<<(std::ostream &os, HashTable<T> &hashTable) {

	for(TableEntry<T> entry in hashTable) {
		if(entry.getState() == FULL) {
			os << "Key: " << entry.getKey() << " Value: " << entry.getValue() << endl;
		}
	}
	return os;

};