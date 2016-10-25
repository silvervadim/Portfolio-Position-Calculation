/*
 * Cash.h
 *
 *  Created on: Oct 22, 2016
 *      Author: Vadim
 */

#ifndef CASH_H_
#define CASH_H_
using namespace std;
#include<string>
#include "Asset.h"

//2a. For cash, the asset price can be thought of as a constant $1
class Cash : public Asset {
public:
	Cash(string symbol, double annualYield, double currentAssetPrice);
	virtual ~Cash();
};

#endif /* CASH_H_ */
