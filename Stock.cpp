/*
 * Stock.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

#include "Stock.h"
//2b. Stock: for now we treat none-dividend stock, dividend paying stock, and preferred stock all
//as stock, differing only in the dividend yield

Stock::Stock(string symbol, double currentAssetPrice, double annualYield): Asset(symbol, currentAssetPrice, annualYield) {
	//2b i. Set asset type as “EQUITY” in constructor
	this->type = "EQUITY";

}

Stock::~Stock() {
	// TODO Auto-generated destructor stub
}

