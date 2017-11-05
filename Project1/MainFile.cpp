#include "Functions.h"
#include "SpecificPriceRuleForItem.h"
#include "PricingRulesComposite.h"
#include "ItemA.h"
#include "ItemB.h"
#include "ItemC.h"
#include "ItemD.h"
#include <iostream>

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
	cout << "A=50, B=30, C=20, D=15\n";
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}

void test1()
{
	cout << "Test1 \n";
	cout << "Pricing rules: 3A=130, 2B=45\n";
	cout << "+A+B-B+D+A+A = 3xA+D = 130+15 = 145 should be\n";
	auto l_itemA = std::make_shared<ItemA>("A", 50.0);
	auto l_itemB = std::make_shared<ItemB>("B", 30.0);
	auto l_itemC = std::make_shared<ItemC>("C", 20.0);
	auto l_itemD = std::make_shared<ItemD>("D", 15.0);

	auto l_threeItemsForThePrice130 = std::make_shared<SpecificPriceRuleForItem>(l_itemA, 3, 130.0);
	auto l_twoItemsForThePrice45 = std::make_shared<SpecificPriceRuleForItem>(l_itemB, 2, 45.0);

	auto l_pricingRulesComposite = std::make_shared<PricingRulesComposite>();
	l_pricingRulesComposite->addPricingRule(l_threeItemsForThePrice130);
	l_pricingRulesComposite->addPricingRule(l_twoItemsForThePrice45);

	auto co = CheckOut(l_pricingRulesComposite);

	co->Scan(l_itemA);
	co->Scan(l_itemB);
	co->Void(l_itemB);
	co->Scan(l_itemD);
	co->Scan(l_itemA);
	co->Scan(l_itemA);
	auto priceSoFar = co->GetTotal();
	std::cout << "Total price " << priceSoFar << "\n";
	cout << "==================\n";
}

void test2()
{
	cout << "Test2 \n";
	cout << "Pricing rules: 3A=130, 2B=45\n";
	cout << "+A+B-B+D+A = 2xA+D = 100+15 = 115 should be\n";
	auto l_itemA = std::make_shared<ItemA>("A", 50.0);
	auto l_itemB = std::make_shared<ItemB>("B", 30.0);
	auto l_itemC = std::make_shared<ItemC>("C", 20.0);
	auto l_itemD = std::make_shared<ItemD>("D", 15.0);

	auto l_threeItemsForThePrice130 = std::make_shared<SpecificPriceRuleForItem>(l_itemA, 3, 130.0);
	auto l_twoItemsForThePrice45 = std::make_shared<SpecificPriceRuleForItem>(l_itemB, 2, 45.0);

	auto l_pricingRulesComposite = std::make_shared<PricingRulesComposite>();
	l_pricingRulesComposite->addPricingRule(l_threeItemsForThePrice130);
	l_pricingRulesComposite->addPricingRule(l_twoItemsForThePrice45);

	auto co = CheckOut(l_pricingRulesComposite);

	co->Scan(l_itemA);
	co->Scan(l_itemB);
	co->Void(l_itemB);
	co->Scan(l_itemD);
	co->Scan(l_itemA);
	auto priceSoFar = co->GetTotal();
	std::cout << "Total price " << priceSoFar << "\n";
	cout << "==================\n";
}

void test3()
{
	cout << "Test3 \n";
	cout << "Pricing rules: 3A=130, 2B=45\n";
	cout << "B+B+B+B = 90 should be\n";
	auto l_itemA = std::make_shared<ItemA>("A", 50.0);
	auto l_itemB = std::make_shared<ItemB>("B", 30.0);
	auto l_itemC = std::make_shared<ItemC>("C", 20.0);
	auto l_itemD = std::make_shared<ItemD>("D", 15.0);

	auto l_threeItemsForThePrice130 = std::make_shared<SpecificPriceRuleForItem>(l_itemA, 3, 130.0);
	auto l_twoItemsForThePrice45 = std::make_shared<SpecificPriceRuleForItem>(l_itemB, 2, 45.0);

	auto l_pricingRulesComposite = std::make_shared<PricingRulesComposite>();
	l_pricingRulesComposite->addPricingRule(l_threeItemsForThePrice130);
	l_pricingRulesComposite->addPricingRule(l_twoItemsForThePrice45);

	auto co = CheckOut(l_pricingRulesComposite);

	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);

	auto priceSoFar = co->GetTotal();
	std::cout << "Total price " << priceSoFar << "\n";
	cout << "==================\n";
}

void test4()
{
	cout << "Test4 \n";
	cout << "Pricing rules: \n";
	cout << "B+B+B+B = 120 should be\n";
	auto l_itemA = std::make_shared<ItemA>("A", 50.0);
	auto l_itemB = std::make_shared<ItemB>("B", 30.0);
	auto l_itemC = std::make_shared<ItemC>("C", 20.0);
	auto l_itemD = std::make_shared<ItemD>("D", 15.0);

	//auto l_threeItemsForThePrice130 = std::make_shared<SpecificPriceRuleForItem>(l_itemA, 3, 130.0);
	//auto l_twoItemsForThePrice45 = std::make_shared<SpecificPriceRuleForItem>(l_itemB, 2, 45.0);

	auto l_pricingRulesComposite = std::make_shared<PricingRulesComposite>();
	//l_pricingRulesComposite->addPricingRule(l_threeItemsForThePrice130);
	//l_pricingRulesComposite->addPricingRule(l_twoItemsForThePrice45);

	auto co = CheckOut(l_pricingRulesComposite);

	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);

	auto priceSoFar = co->GetTotal();
	std::cout << "Total price " << priceSoFar << "\n";
	cout << "==================\n";
}

void test5()
{
	cout << "Test5 \n";
	cout << "Pricing rules: 2B=45\n";
	cout << "B+B+B+B-B=75 should be\n";
	auto l_itemA = std::make_shared<ItemA>("A", 50.0);
	auto l_itemB = std::make_shared<ItemB>("B", 30.0);
	auto l_itemC = std::make_shared<ItemC>("C", 20.0);
	auto l_itemD = std::make_shared<ItemD>("D", 15.0);

	//auto l_threeItemsForThePrice130 = std::make_shared<SpecificPriceRuleForItem>(l_itemA, 3, 130.0);
	auto l_twoItemsForThePrice45 = std::make_shared<SpecificPriceRuleForItem>(l_itemB, 2, 45.0);

	//auto l_pricingRulesComposite = std::make_shared<PricingRulesComposite>();
	//l_pricingRulesComposite->addPricingRule(l_threeItemsForThePrice130);
	//l_pricingRulesComposite->addPricingRule(l_twoItemsForThePrice45);

	auto co = CheckOut(l_twoItemsForThePrice45);

	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Scan(l_itemB);
	co->Void(l_itemB);

	auto priceSoFar = co->GetTotal();
	std::cout << "Total price " << priceSoFar << "\n";
	cout << "==================\n";
}