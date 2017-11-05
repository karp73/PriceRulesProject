#pragma once
#include "IPricingRules.h"
class SpecificPriceRuleForItem :
	public IPricingRules
{
public:
	SpecificPriceRuleForItem(std::shared_ptr<IItem> p_relatedItem,
							 int p_amountOfItems, 
							 double p_price) : m_rule(std::make_pair(p_amountOfItems, p_price)),
											   m_relatedItem(p_relatedItem) {}
	~SpecificPriceRuleForItem();
	double applyPricingRules(map<shared_ptr<IItem>, int>::value_type&) override;
private:
	std::shared_ptr<IItem> m_relatedItem;
	const std::pair<int, double> m_rule;
};

