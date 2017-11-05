#pragma once
#include <memory>
#include "IPriceCounter.h"

unique_ptr<IPriceCounter> CheckOut(shared_ptr<IPricingRules> p_pricingRules);