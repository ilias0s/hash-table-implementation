#include "../include/hashtable.h"
int hashtable::hash(int key)
{
	return key % 10;
}