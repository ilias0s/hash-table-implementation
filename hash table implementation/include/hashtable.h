#include<iostream>
struct entity
{
	int key;
	std::string value;
};
class hashtable
{
private:
	entity* vec[10];
	int hash(int key);
public:
	
};