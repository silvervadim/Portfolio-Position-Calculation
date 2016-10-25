/*
 * Position.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: Vadim
 */

#include "Position.h"

//3b. A constructor
Position::Position(Asset* pAsset, int quantity, double costPriceOfPosition,
		double positionAge) {
	this->pAsset = pAsset;
	this->quantity = quantity;
	this->costPriceOfPosition = costPriceOfPosition;
	this->positionAge = positionAge;

}
//3c. A destructor
Position::~Position() {
}

//3d. A function getQuantity() to return the quantity of the asset held in position
int Position::getQuantity() {
	return quantity;
}

//3e. A function getSymbol() to return the asset symbol of the position
string Position::getSymbol() {
	return pAsset->getAssetSymbol();
}

//3f. A function getAssetType() to return the type of asset of the position
string Position::getAssetType() {
	return pAsset->getAssetType();
}
//3g. A function getPosAge() to return the age of the position
double Position::getPosAge() {
	return positionAge;
}
//3h. A function getCurrentPrice() to return the current price of the position
double Position::getCurrentPrice() {
	return pAsset->getCurrentAssetPrice();
}
//3i. A function getTotalReturn() to return the total return of the position since inception
double Position::getTotalReturn(){
	//we still need initial price, but positionAge we have inside our class
	 return pAsset->totalReturn(costPriceOfPosition,positionAge);
}
//3j. A function getCurrentValue() to return the current total dollar value of the position
double Position::getCurrentValue(){
	return quantity * (pAsset->getCurrentAssetPrice());
}
//3k. A function getCostBasis() to return the total dollar cost of the position at purchase
double Position::getCostBasis(){
	return this-> costPriceOfPosition * quantity;
}

