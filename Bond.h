/*
 * Bond.h
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

/*
2c. Bond:



2c iv. Override the total return function in base class (instead of continuous yield, you
need to add coupon payments. For this calculation, assume today is a coupon
payment date)*/
#ifndef BOND_H_
#define BOND_H_

#include "Asset.h"

class Bond: public Asset {
//i. Additional data variable
private:

	//1. bond par value
	double par = 1000;
	//2. coupon rate
	double couponRate;
	//3. coupon frequency (number of coupons per annum)
	double couponFrequency = 2;


public:

	//2c ii. Constructor
	Bond(string symbol, double currentAssetPrice, double couponRate, double par , double couponFrequency,double annualYield =0 );
	virtual ~Bond();
	//2c iii. Public function to set coupon rate
	void setCouponRate(double newCoupRate);
	//2c iv. Override the total return function in base class (instead of continuous yield, you
	//need to add coupon payments. For this calculation, assume today is a coupon
	//payment date)
	double totalReturn(double initPrice, double xMonths);
	double getFrequency();


};

#endif /* BOND_H_ */
