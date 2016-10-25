/*

 * Asset.cpp
 *
 *  Created on: Oct 22, 2016
 *      Author: Vadim
 */
using namespace std;
#include<string>
#include<math.h>

#include "Asset.h"

//1c. Parameterized constructors that set
//1c i. Asset symbol, current asset price, and annual yield of the asset.
Asset::Asset(string c_symbol, double c_currentAssetPrice,
		double c_annualYield) {

	symbol = c_symbol;
	currentAssetPrice = c_currentAssetPrice;
	annualYield = c_annualYield;

}

//1 e. Public member functions that
//1 e i. Set values of one or more of the private member variables
void Asset::setPriceHistory(double * inputPrices) {
	pHist = inputPrices;
}
void Asset::setType(string sType) {
	type = sType;
}
//1e ii. Get values of yield, current asset price
double Asset::getAnnualYield() {
	return annualYield;
}
double Asset::getCurrentAssetPrice() {
	return currentAssetPrice;
}
//1e iii. Get asset type
string Asset::getAssetType() {
	return type;
}
//1e iv. Get asset symbol
string Asset::getAssetSymbol() {
	return symbol;
}
//1e v. Total return of the asset over last x-months given an initial price, p0. (don’t forget to
//take into account of the return from yield)
double Asset::totalReturn(double initPrice, double xMonths) {

	double assetReturn = annualYield * (xMonths / 12)
			+ ((currentAssetPrice - initPrice) / initPrice);

	return assetReturn;
}

//1d. Destructor (make sure you take care of the dynamically allocated memory)
Asset::~Asset() {
	delete[] pHist;
}
