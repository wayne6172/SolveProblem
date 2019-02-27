#include "ArrayBag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry){
    bool hasRoomToAdd = (itemCount < maxItems);
    if(hasRoomToAdd){
        items[itemCount] = newEntry;
        itemCount++;
    }

    return hasRoomToAdd;
}

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    for(int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);
    return bagContents;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry){
    return false;
}

template<class ItemType>
void ArrayBag<ItemType>::clear(){

}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int curIndex = 0;
    while(curIndex < itemCount){
        if(items[curIndex] == anEntry)
            frequency++;
        curIndex++;
    }

    return frequency;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &target) const {
    return this->getFrequencyOf(target) > 0;
}
