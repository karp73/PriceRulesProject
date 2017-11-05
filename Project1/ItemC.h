#pragma once
#include "IItem.h"
class ItemC :
	public IItem
{
public:
	ItemC(string p_itemDescription, double p_price) : IItem(p_itemDescription, p_price) {}
	~ItemC();
};

