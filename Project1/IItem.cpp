#include "IItem.h"


IItem::~IItem()
{
}

void IItem::setPrice(double p_price)
{
	m_price = p_price;
}

double IItem::getPrice()
{
	return m_price;
}

string IItem::getItemDescription()
{
	return m_itemDescription;
}