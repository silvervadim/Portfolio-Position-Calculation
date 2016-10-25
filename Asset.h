/*
 * Asset.h
 *
 *  Created on: Oct 22, 2016
 *      Author: Vadim
 */

#ifndef ASSET_H_
#define ASSET_H_
using namespace std;
#include<string>

//1. Write a base class Asset that contains (!)
class Asset {
//1a. Private data members:
private:
	//1a i. Asset symbol (e.g. “AAPL”)
	string symbol;
	/*1a ii. double *pHist: 1-d dynamic array of monthly historical asset prices (which is in
	 reverse chronological order), set the default value as nullptr*/
	double * pHist = nullptr;
	//1a iii. Number of data points in the price history
	int numPoints = 0;
	//1a iv. Current asset price
	double currentAssetPrice;

//1b. Protected member:
protected:
	//1b i. Asset type (e.g. “CASH”)
	string type;
	//1b ii. Annual yield of the asset
	double annualYield;

public:
	//1c. Parametrized constructors that set
	//1c i. Asset symbol, current asset price, and annual yield of the asset.
	Asset(string symbol, double currentAssetPrice, double annualYield);
	//1d. Destructor (make sure you take care of the dynamically allocated memory)
	virtual ~Asset();
	//1e. Public member functions that
	//1e i. Set values of one or more of the private member variables
	void setPriceHistory(double * inputPrices);
	void setType(string sType);
	//1e ii. Get values of yield, current asset price, initial price
	double getAnnualYield();
	double getCurrentAssetPrice();
	//1e iii. Get asset type
	string getAssetType();
	//1e iv. Get asset symbol
	string getAssetSymbol();
	//1e v. Total return of the asset over last x-months given an initial price, p0. (don’t forget to
	//take into account of the return from yield)
	virtual double totalReturn(double initPrice, double xMonths);

	//setcouponrate in case its a bond and we started off using an asset pointer
	//virtual double setCouponRate();

};


#endif /* ASSET_H_ */
