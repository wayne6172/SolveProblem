#include "BagInterface.h"
#include <cstddef>
#include <string>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	bool remove(const ArrayBag<ItemType>& aBag);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
}; // end ArrayBag


template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;       // Current array index

	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		}  // end if
		curIndex++;          // Increment to next entry
	}  // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;

	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

	return bagContents;
}  // end toVector

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}

	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int i = 0;
	for (i = 0; i < itemCount;) {
		if (items[i] == anEntry) {
			for (int j = i; j < itemCount - 1; j++) {
				items[j] = items[j + 1];
			}
			itemCount--;
		}
		else {
			i++;
		}
	}
	return true;

	return true;
}  // end remove

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ArrayBag<ItemType>& aBag)
{
	int a;
	for (a = 0; a<aBag.itemCount; a++) {
		remove(aBag.items[a]);
	}

	return true;
}  // end remove
