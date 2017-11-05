#pragma once
#include <string>

using namespace std;

class IItem
{
public:
	IItem(string p_itemDescription, double p_price) : m_price(p_price), m_itemDescription(p_itemDescription){}
	virtual ~IItem();
	virtual void setPrice(double p_price);
	virtual double getPrice();
	virtual string getItemDescription();
protected:
	double m_price;
	string m_itemDescription;
};

