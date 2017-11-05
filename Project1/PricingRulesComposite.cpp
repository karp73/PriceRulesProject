#include "PricingRulesComposite.h"



PricingRulesComposite::PricingRulesComposite()
{
}


PricingRulesComposite::~PricingRulesComposite()
{
}

void PricingRulesComposite::addPricingRule(shared_ptr<IPricingRules> p_pricingRule)
{
	m_rules.push_back(p_pricingRule);
}

double PricingRulesComposite::applyPricingRules(map<shared_ptr<IItem>, int>::value_type& p_specificItem)
{
	double l_priceForSpecificItem = 0.0;

	for (auto& l_rule : m_rules)
	{
		l_priceForSpecificItem = l_rule->applyPricingRules(p_specificItem);
		if (l_priceForSpecificItem > 0.0)
		{
			break;
		}
	}

	return l_priceForSpecificItem;
}