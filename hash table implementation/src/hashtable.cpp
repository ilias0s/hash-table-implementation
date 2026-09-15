#include "../include/hashtable.h"
hashtable::hashtable()
{
	for (auto &i : arr)
	{
		i = nullptr;
	}
}

int hashtable::hash(int key)
{
	return key % 10;
}
void hashtable::push(int k, std::string v)
{
	int index = hash(k);

	if (arr[index] == nullptr)
	{
		arr[index] = new entity{ k,v };
		return;
	}
	entity* current = arr[index];

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = new entity{ k, v };
}

entity hashtable::pull(int k)
{
	int index = hash(k);
	if (arr[index] != nullptr)
	{
		if (arr[index]->key == k)
			return *arr[index];
		entity* current = arr[index];
		while (current!=nullptr && current->key != k)
		{
			current = current->next;
		}
		if (current == nullptr)
		{
			throw std::runtime_error("invalid key");
		}
		return *current;
	}
	else
		throw std::runtime_error("invalid key");
}
void hashtable::remove(int k)
{
	int index = hash(k);

	entity* current = arr[index];
	entity* previous = nullptr;

	while (current != nullptr && current->key != k)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr)
		throw std::runtime_error("invalid key");

	if (previous == nullptr)
		arr[index] = current->next;
	else
		previous->next = current->next;

	delete current;
}