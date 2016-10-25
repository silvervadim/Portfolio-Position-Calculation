/*
 * Stock.h
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

#ifndef STOCK_H_
#define STOCK_H_

#include "Asset.h"
//2b. Stock: for now we treat none-dividend stock, dividend paying stock, and preferred stock all
//as stock, differing only in the dividend yield
class Stock: public Asset {
public:
	Stock(string symbol, double currentAssetPrice, double annualYield);
	virtual ~Stock();
};

#endif /* STOCK_H_ */
