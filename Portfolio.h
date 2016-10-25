/*
 * Portfolio.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Vadim

 We want to write a portfolio analytics application that tracks portfolio performance over a variety of
 portfolio holdings, such as cash in interest bearing account, stocks, dividend paying stocks, preferred
 stocks, bonds etc.
 Let’s build on last homework assignment, we now proceed to build our portfolio application.
 */

using namespace std;
#include<string>
#include<vector>
#include "Position.h""

//1. Write a class Portfolio that contains
#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

class Portfolio {
	//1a data members
	private:
		string portfolioName;
		vector<Position> Pos;
		static double benchMarkReturnRate;

public:
	Portfolio(string portfolioName);
	virtual ~Portfolio();
	//1c) A function to add a position to portfolio
	void addPosition(Position p);
	//1d) A function to add several Position to Portfolio
	void addSeveralPositions(vector<Position> v);
	//1e) A function to remove a Position of a given symbol from Portfolio
	void removePosition(string givenName);
	//1f) A function to return number of positions
	int getNumOfPositions();
	//1g) A function to get the benchmark return rate,  since it returns static variable i implemented it fully here
	static double getBenchMarkReturnRate(){ return benchMarkReturnRate; }
	//1h) A function currValue that returns the current value of the portfolio
	double getCurrentPorfolioValue();
	//1i) A function currValueByAssetType that returns the current value of all the positions of a given asset type, e.g.“EQUITY”
	double getValByAssetType(string givenSymbol);
	//1j) A function getAvgRetRate to return the weighted average rate of return of this portfolio
	double getAvgRetRate();
	//1k) A function getExcessRetRate to return the excess return above the benchmark return rate
	double getExcessRetRate(){
		double benchMark = getBenchMarkReturnRate();

		double excessRetRate = getAvgRetRate() - benchMark;

		return excessRetRate;
	}


	//benchmark setter
	static void setBenchMarkReturnRate(double inputRate){
		benchMarkReturnRate = inputRate;
	}

};

#endif /* PORTFOLIO_H_ */
