#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

// New Method to the ADT 
template<class ItemType>
ItemType ArrayBag<ItemType>::findSmallestHelper(int startIndex) const
{
    // Base case: if we're at the last element
    if (startIndex == itemCount - 1)
    {
      return items[startIndex];
    }
    // Recursive case: compare current element with smallest from rest of array
    ItemType smallestRest = findSmallestHelper(startIndex + 1);
    return (items[startIndex] < smallestRest) ? items[startIndex] : smallestRest;
}

template<class ItemType>
ItemType ArrayBag<ItemType>::findSmallest() const
{
   return findSmallestHelper(0);
}

template<class ItemType>
ItemType ArrayBag<ItemType>::findLargestHelper(int startIndex) const
{
    // Base case: if we're at the last element
    if (startIndex == itemCount - 1)
    {
        return items[startIndex];
    }
    // Recursive case: compare current element with largest from rest of array
    ItemType largestRest = findLargestHelper(startIndex + 1);
    return (items[startIndex] > largestRest) ? items[startIndex] : largestRest;
}

template<class ItemType>
ItemType ArrayBag<ItemType>::findLargest() const
{
   return findLargestHelper(0);
}

// starter code ⬇️
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
} 

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
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	} 
    
	return hasRoomToAdd;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
    
	return canRemoveItem;
} 

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
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
} 

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      } 
   }
   
   return result;
}

