#pragma once
#include "IItem.h"
class ItemA :
	public IItem
{
public:
	ItemA(string p_itemDescription, double p_price) : IItem(p_itemDescription, p_price) {}
	~ItemA();
};

