#pragma once
#include "IItem.h"
class ItemD :
	public IItem
{
public:
	ItemD(string p_itemDescription, double p_price) : IItem(p_itemDescription, p_price) {}
	~ItemD();
};

