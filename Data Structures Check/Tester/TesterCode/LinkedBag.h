#include "BagInterface.h"
#include "Node.h"
#include <cstddef>
#include <string>

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   void copy(const LinkedBag<ItemType>* anotherBag);
   void compact();
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;
}; // end LinkedBag

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor


template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;

   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
   itemCount = 0;
}  // end clear

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{   
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  

	headPtr = nextNodePtr;  
	itemCount++;

	return true;
}  

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
}  // end getFrequencyOf


template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while

	return bagContents;
}  // end

template<class ItemType>
void LinkedBag<ItemType>::copy(const LinkedBag<ItemType>* anotherBag)
{
	Node<ItemType> *curPtr = anotherBag->headPtr, *news=headPtr;
	while (curPtr != nullptr) {
		Node<ItemType>* set = new Node<ItemType>();
		set->setNext(nullptr);
		set->setItem(curPtr->getItem());
		if (headPtr == nullptr) {
			headPtr= new Node<ItemType>();
			headPtr->setItem(curPtr->getItem());
			itemCount++;
		}
		else {
			news = headPtr;
			while (news->getNext() != nullptr)  news = news->getNext();
			news->setNext(set);
			itemCount++;
		}
		curPtr = curPtr->getNext();
	}


	return;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::compact()
{
	Node<ItemType> *curPtr = headPtr,*next,*pre;
	while (curPtr != nullptr) {
		next = curPtr->getNext();
		pre = nullptr;
		while (next != nullptr) {
			if (next->getItem() == curPtr->getItem()) {
				if (pre == nullptr) headPtr = headPtr->getNext();
				else {
					pre->setNext(next->getNext());
				}
				itemCount--;
			}
			pre = next;
			next = next->getNext();
		}
		curPtr = curPtr->getNext();
	}

	


	return;
}  // end
