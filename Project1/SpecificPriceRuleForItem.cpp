#include "SpecificPriceRuleForItem.h"



//SpecificPriceRuleForItem::SpecificPriceRuleForItem()
//{
//}


SpecificPriceRuleForItem::~SpecificPriceRuleForItem()
{
}

double SpecificPriceRuleForItem::applyPricingRules(map<shared_ptr<IItem>, int>::value_type& p_specificItem)
{
	double l_priceForItems = 0.0;
	auto l_item = p_specificItem.first;
	auto l_amountOfItems = p_specificItem.second;
	auto l_itemPrice = l_item->getPrice();

	if (l_item->getItemDescription() == m_relatedItem->getItemDescription())
	{
		auto l_numOfPackages = l_amountOfItems / m_rule.first;
		auto l_othersItems = l_amountOfItems % m_rule.first;
		l_priceForItems += l_numOfPackages * m_rule.second + l_othersItems * l_itemPrice;
		//return l_priceForItems;
	}
	return l_priceForItems;
}