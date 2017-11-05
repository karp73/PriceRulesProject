#include "Functions.h"
#include "PriceCounter.h"
#include "IPricingRules.h"
#include <memory>

unique_ptr<IPriceCounter> CheckOut(shared_ptr<IPricingRules> p_pricingRules)
{
	return std::make_unique<PriceCounter>(p_pricingRules);
}