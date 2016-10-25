/*
 * Portfolio.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Vadim
 */

#include "Portfolio.h"
#include <iostream>
//1b. a constructor initializing the portfolio name with a string parameter
Portfolio::Portfolio(string portfolioName) {
	this->portfolioName = portfolioName;



}

//1c. c. A function to add a Position to Portfolio
void Portfolio::addPosition(Position p){
	Pos.push_back(p);
}

//1d) A function to add several Position to Portfolio
void Portfolio::addSeveralPositions(vector<Position> v){
	Pos.insert(Pos.end(), v.begin(), v.end());
}

//1e) A function to remove a Position of a given symbol from Portfolio
void Portfolio::removePosition(string givenName){
	// declare an iterator to a vector of Positions
	vector<Position>::iterator it;
	//element to be found.
	string targetVal = givenName;
	// now start at from the beginning
	// and keep iterating over the element till you find
	// target element...or reach the end of vector.
	for (it = Pos.begin(); it < Pos.end(); it++) {
		// found nth element..print and break.
		if (it->getSymbol() == targetVal) {
			Pos.erase(it);//cout << *it;  // prints d.
			//break; no need to break since we may see a symbol later on again, but if u only have one symbol
			//each you can save time and break
		}
	}
}

//1f)A function to return number of positions
int Portfolio::getNumOfPositions(){
	return Pos.size();
}

//1g) A function to get the benchmark return rate
//in the header file
//}

//1h) A function currValue that returns the current value of the portfolio
double Portfolio::getCurrentPorfolioValue(){

	double currentPortVal = 0.0;

	//declare an iterator to a vector of Positions
	vector<Position>::iterator it;
	//iterate...
	for (it = Pos.begin(); it < Pos.end(); it++){

		currentPortVal += it->getCurrentValue();
	}

	return currentPortVal;


}


//1i) A function currValueByAssetType that returns the current value of all the positions of a given asset type, e.g.“EQUITY”
double Portfolio::getValByAssetType(string givenSymbol){

	string targetVal = givenSymbol;

	double valByAssetType = 0.0;

	//declare an iterator to a vector of Positions
	vector<Position>::iterator it;
	//iterate...
	for (it = Pos.begin(); it < Pos.end(); it++){

		if (it->getAssetType() == givenSymbol){
			valByAssetType += it->getCurrentValue();

		}
		else{
			continue;
		}
	}

	return valByAssetType;

}

//1j) A function getAvgRetRate to return the weighted average rate of return of this portfolio
double Portfolio::getAvgRetRate(){

	double equitySize = 0.0;
	double bondSize = 0.0;
	double otherAssetSize = 0.0;// defensive purposes, we only have bonds and equities
	double equityReturn = 0.0;
	double bondReturn = 0.0;
	double otherAssetReturn = 0.0;// defensive purposes, we only have bonds and equities in our example


	//declare an iterator to a vector of Positions
	vector<Position>::iterator it;
	// iterate.. we will go over each position in the symbol, get its asset, based on the asset symbol we will
	// add to one of the initialized variables above ^^ to get the size and return of each class's position
	// to apply the formula of : Expected Return E(R) = p1R1 + p2R2 + .....+ pnRn
	// Where: pn = the probability the return actually will occur in state n
	// Rn = the expected return for state n

	for (it = Pos.begin(); it < Pos.end(); it++){
		if (it->getAssetType() == "EQUITY"){
			equitySize++;
			equityReturn = it->getTotalReturn();
		}
		else if (it->getAssetType() == "BOND"){
			bondSize++;
			bondReturn = it->getTotalReturn();
		}
		else {
			otherAssetSize++; //defensive coding
			otherAssetReturn; //defensive coding
		}

	}

	//now we got our sizes and returns for each asset class, we also need overall position size for frequency calculation
	//of each asset class


	double portSize = getNumOfPositions();

	//apply the formula

	double weightedAvgWithOutOther = (equitySize / portSize)*equityReturn + (bondSize / portSize)*bondReturn;

	//if there aren't any other assets
	double weightedAvgWithOther = (equitySize / portSize)*equityReturn + (bondSize / portSize)*bondReturn + (otherAssetSize / otherAssetReturn) *otherAssetReturn;

	return otherAssetSize == 0 ? weightedAvgWithOutOther : weightedAvgWithOutOther;



}



//1k) A function getExcessRetRate to return the excess return above the benchmark return rate
//in header file since i have to use static benchmark variable

Portfolio::~Portfolio() {
	// TODO Auto-generated destructor stub
}


//2. Initialize the Benchmark return rate to 0;
double Portfolio::benchMarkReturnRate = 0.0;
