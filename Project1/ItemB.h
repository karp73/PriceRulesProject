#pragma once
#include "IItem.h"
class ItemB :
	public IItem
{
public:
	ItemB(string p_itemDescription, double p_price) : IItem(p_itemDescription, p_price) {}
	~ItemB();
};

