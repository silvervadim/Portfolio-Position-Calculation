//============================================================================
// Name        : Vadim_Serebrinskiy_HW5_10_22_2016.cpp
// Author      : Vadim Serebrinskiy
// Version     : 1.0 10_23_2016
// Copyright   : This project was done by vadim serebrinskiy, anybody can use this.
// Description : Polymorphism and Inheritance in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string>
#include "Asset.h"
#include "Cash.h"
#include "Stock.h"
#include "Bond.h"
#include "Position.h"
#include "Portfolio.h"

//4. In main function

int main() {

	/*
	 symbol	type	quantity	yield	age	costPrice	currentPrice
	 GE		Equity	5000		3.20%	9	29.15		29.08
	 FB		Equity	2000		0		12	104.5		130.1

	 symbol	type	quantity	coupon	age	costPrice	currentPrice
	 US10Y	BOND	250			3.75%	14	101.2		100.8

	 */

	//4a. Instantiate 3 Position objects with the necessary data provided for each of them in the data
	//file provided (for this homework, you will not need historical price series.)
	Asset *ge = new Stock("GE", 29.08, 0.0320);
	Position GE(ge, 5000, 29.15, 9);

	Asset *fb = new Stock("FB", 130.1, 0);
	Position FB(fb, 2000, 104.5, 12);

	Asset *us10Y = new Bond("US10Y",100.8, 0.0375,1000,2,0);
	Position US10Y(us10Y,250,101.2,14);

	cout <<"======================= HOMEWORK # 5 MAIN=====================" << endl;
	//4b. For each position, print out the result of
	//4b i. getSymbol()
	cout << "The symbol for GE is: " << GE.getSymbol() << endl;
	cout << "The symbol for FB is: " << FB.getSymbol() << endl;
	cout << "The symbol for US10Y is: " << US10Y.getSymbol() << endl;
	cout << endl;
	//ii. getAssetType()
	cout << "The Asset Type for GE is: " << GE.getAssetType() << endl;
	cout << "The Asset Type for FB is: " << FB.getAssetType() << endl;
	cout << "The Asset Type for US10Y is: " << US10Y.getAssetType() << endl;
	cout << endl;
	//iii. getPosAge()
	cout << "The position age for GE is: " << GE.getPosAge() << endl;
	cout << "The position age for FB is: " << FB.getPosAge() << endl;
	cout << "The position age for US10Y is: " << US10Y.getPosAge() << endl;
	cout << endl;
	//iv. getCostBasis()
	cout << "The cost basis for GE is: "<< GE.getCostBasis() << endl;
	cout << "The cost basis for FB is: " << FB.getCostBasis() << endl;
	cout << "The cost basis for US10Y is: " << US10Y.getCostBasis() << endl;
	cout << endl;
	//v. getCurrentValue()
	cout << "The current value for GE is: " << GE.getCurrentValue() << endl;
	cout << "The current value for FB is: " << FB.getCurrentValue() << endl;
	cout << "The current value for US10Y is: " << US10Y.getCurrentValue() << endl;
	cout << endl;
	//vi. getTotalReturn()
	cout << "The total return for GE is: " << GE.getTotalReturn() << endl;
	cout << "The total return for FB is: " << FB.getTotalReturn() << endl;
	cout << "The total return for US10Y is: " << US10Y.getTotalReturn() << endl;

	/*In - class assignment(10 / 24 / 2016)
	We want to write a portfolio analytics application that tracks portfolio performance over a variety of
	portfolio holdings, such as cash in interest bearing account, stocks, dividend paying stocks, preferred
	stocks, bonds etc.

	*/

	//In class 3. In main
	//a.Use the 3 Position data from last week’s homework to construct a Portfolio object
	string portfolioName = "vadim's portfolio";
	Portfolio myPort(portfolioName);

	myPort.addPosition(GE);
	myPort.addPosition(FB);
	myPort.addPosition(US10Y);


	//b. Set the benchmark return rate to 0.005
	myPort.setBenchMarkReturnRate(0.005);

	//c.Print out the following information about the portfolio

	cout <<"\n"<< endl;
	cout <<"=======================IN CLASS ASSIGNMENT=====================" << endl;
	cout <<"=====================PORTFOLIO INFORMATION =====================" << endl;
	//i.the number of positions
	cout <<"The number of positions is : "<< myPort.getNumOfPositions() << endl;

		//ii.current value
	cout << "The current portfolio value is : " << myPort.getCurrentPorfolioValue() << endl;

		//iii.current value per asset type
	cout << "The current (portfolio) value per asset type: Equity is : " << myPort.getValByAssetType("EQUITY") << endl;
	cout << "The current (portfolio) value per asset type: Bond is : " << myPort.getValByAssetType("BOND") << endl;
	cout << "The current (portfolio) value per asset type: Other is : " << myPort.getValByAssetType("Other") << endl;
		//iv.weighted average rate of return
	cout << "The weighted average rate of return is : " << myPort.getAvgRetRate() << endl;
		//v.benchmark return rate
	cout << "The benchmark return rate is : " << myPort.getBenchMarkReturnRate() << endl;
		//vi.portfolio excess rate of return
	cout << "The excess return rate is : " << myPort.getExcessRetRate() << endl;






	//system("PAUSE"); when using visual studio to see results
	return 0;
}
