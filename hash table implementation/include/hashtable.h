#include<iostream>
struct entity
{
	int key;
	std::string value;
	entity* next;
};
class hashtable
{
private:
	entity* arr[10];
	int hash(int key);
public:
	hashtable();
	void push(int k,std::string v);
	entity pull(int k);
	
};