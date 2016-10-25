/*
 * Bond.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

#include "Bond.h"
#include <math.h>

//2c ii constructor continued

	// 2c ii 2. Set asset yield to 0 (since it is paying discrete coupons)
	//2c ii 3. Set default bond par value = 1000
	//2c ii 4. Coupon frequency = 2

Bond::Bond(string symbol, double currentAssetPrice, double couponRate, double par, double couponFrequency,double annualYield): Asset(symbol,currentAssetPrice, annualYield){
	//2c ii 1. set asset type to Bond
	type = "BOND";
	this->couponRate = couponRate;
}

//2c iii. Public function to set coupon rate
void Bond::setCouponRate(double newCoupRate){
	couponRate = newCoupRate;
}


//2c iv. Override the total return function in base class (instead of continuous yield, you
//need to add coupon payments. For this calculation, assume today is a coupon
//payment date)
double Bond::totalReturn(double initPrice, double xMonths){
	/*double totalReturn = 0.0;
	for (int i = 0; i <= couponFrequency;++i ){
		totalReturn+= par * couponRate;
	}

	*/

	//double t = (xMonths/12)*couponFrequency;

	//rounded t
	double t=ceil (xMonths*couponFrequency/12);
	double numerator = ((couponRate*par*t)/couponFrequency) + this->getCurrentAssetPrice() - initPrice;
	return numerator/initPrice;
}


double Bond::getFrequency(){
	return couponFrequency;
}
Bond::~Bond() {
	// TODO Auto-generated destructor stub
}

