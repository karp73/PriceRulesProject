#pragma once
#include "IPricingRules.h"
#include <vector>

class PricingRulesComposite :
	public IPricingRules
{
public:
	PricingRulesComposite();
	~PricingRulesComposite();
	void addPricingRule(shared_ptr<IPricingRules>);
	double applyPricingRules(map<shared_ptr<IItem>, int>::value_type& p_specificItem) override;
private:
	std::vector<shared_ptr<IPricingRules>> m_rules;
};

