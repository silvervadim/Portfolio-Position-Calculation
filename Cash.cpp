/*
 * Cash.cpp
 *
 *  Created on: Oct 22, 2016
 *      Author: Vadim
 */

#include "Cash.h"

//2a. For cash, the asset price can be thought of as a constant $1
Cash::Cash(string symbol, double currentAssetPrice , double annualYield): Asset(symbol, currentAssetPrice = 1.0, annualYield) {
	//2a i. Set asset type as “CASH” in constructor
	this->type = "CASH";
}

Cash::~Cash() {
	// TODO Auto-generated destructor stub
}

