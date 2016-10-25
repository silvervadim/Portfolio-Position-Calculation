/*
 * Position.h
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

#ifndef POSITION_H_
#define POSITION_H_

using namespace std;
#include<string>
#include "Asset.h"

//3. Write a class Position that contains

class Position {
	//a. Private data variables
private:
	//3a i. Pointer to an Asset: *pAsset
	Asset * pAsset;
	//3a ii. Quantity of the asset held in position
	int quantity;
	//3a iii. Cost price of the position
	double costPriceOfPosition;
	//3a iv. Age of the position (number of months the position has been held)
	double positionAge;
public:
	//3b. A constructor
	Position(Asset* pAsset,int quantity, double costPriceOfPosition, double positionAge);
	//3c. A destructor
	virtual ~Position();
	//3d. A function getQuantity() to return the quantity of the asset held in position
	int getQuantity();
	//3e. A function getSymbol() to return the asset symbol of the position
	string getSymbol();
	//3f. A function getAssetType() to return the type of asset of the position
	string getAssetType();
	//3g. A function getPosAge() to return the age of the position
	double getPosAge();
	//3h. A function getCurrentPrice() to return the current price of the position
	double getCurrentPrice();
	//3i. A function getTotalReturn() to return the total return of the position since inception
	double getTotalReturn();
	//3j. A function getCurrentValue() to return the current total dollar value of the position
	double getCurrentValue();
	//3k. A function getCostBasis() to return the total dollar cost of the position at purchase
	double getCostBasis();
};

#endif /* POSITION_H_ */
