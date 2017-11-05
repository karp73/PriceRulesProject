#pragma once
#include <map>
#include "IPriceCounter.h"

using namespace std;

class IPricingRules
{
public:
	IPricingRules();
	virtual ~IPricingRules();
	virtual double applyPricingRules(map<shared_ptr<IItem>, int>::value_type&) = 0;
};

