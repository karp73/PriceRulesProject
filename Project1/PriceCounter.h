#pragma once
#include <map>
#include "IPriceCounter.h"

using namespace std;

class PriceCounter :
	public IPriceCounter
{
public:
	void Scan(shared_ptr<IItem>) override;
	void Void(shared_ptr<IItem>) override;
	double GetTotal() override;
	PriceCounter(std::shared_ptr<IPricingRules>);
	~PriceCounter();
private:
	map<shared_ptr<IItem>, int> m_scannedItems;
};

