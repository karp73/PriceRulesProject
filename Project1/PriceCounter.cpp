#include "PriceCounter.h"

PriceCounter::PriceCounter(std::shared_ptr<IPricingRules> p_pricingRules)
{
	m_pricingRules = p_pricingRules;
}


PriceCounter::~PriceCounter()
{
}

void PriceCounter::Scan(shared_ptr<IItem> p_item)
{
	auto l_it = m_scannedItems.find(p_item);
	if (l_it != m_scannedItems.end())
	{
		l_it->second++;
	}
	else
	{
		m_scannedItems.emplace(p_item, 1);
	}
}

void PriceCounter::Void(shared_ptr<IItem> p_item)
{
	auto l_it = m_scannedItems.find(p_item);
	if (l_it != m_scannedItems.end() && l_it->second >= 1)
	{
		l_it->second--;
		if (l_it->second == 0)
		{
			m_scannedItems.erase(l_it);
		}
	}
}

double PriceCounter::GetTotal()
{
	double l_totalPrice = 0.0;

	for (auto& l_item : m_scannedItems)
	{
		auto l_outputPrice = m_pricingRules->applyPricingRules(l_item);
		if (l_outputPrice > 0)
		{
			l_totalPrice += l_outputPrice;
		}
		else
		{
			l_totalPrice += l_item.first->getPrice() * l_item.second;
		}
	}
	return l_totalPrice;
}

