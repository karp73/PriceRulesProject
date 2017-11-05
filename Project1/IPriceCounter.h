#pragma once
#include <memory>
#include "IItem.h"
#include "IPricingRules.h"

using namespace std;
class IPricingRules;

class IPriceCounter
{
public:
	IPriceCounter();
	virtual ~IPriceCounter();
	virtual void Scan(shared_ptr<IItem>) = 0;
	virtual void Void(shared_ptr<IItem>) = 0;
	virtual double GetTotal() = 0;
protected:
	shared_ptr<IPricingRules> m_pricingRules;
};

