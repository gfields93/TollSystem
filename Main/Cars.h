//
//  Cars.h
//  FieldsGlen - Project3
//
//  Created by Glen Fields on 4/11/15.
//  Copyright (c) 2015 gfields. All rights reserved.
//

#ifndef FieldsGlenProject3Carsh
#define FieldsGlenProject3Carsh
#include <cmath>

class Cars{
public:
	int getMonthA() { return monthA; };
	void setMonthA(int x) { monthA = x; };
	int getMonthD() { return monthD; };
	void setMonthD(int x) { monthD = x; };
	
	int getDayA() { return dayA; };
	void setDayA(int x) { dayA = x; };
	int getDayD() { return dayD; };
	void setDayD(int x) { dayD = x; };

	int getHourA() { return hourA; };
	void setHourA(int x) { hourA = x; };
	int getHourD() { return hourD; };
	void setHourD(int x) { dayD = x; };

	int getMinA() { return minuteA; };
	void setMinA(int x) { minuteA = x; };
	int getMinD() { return minuteD; };
	void setMinD(int x) { minuteD = x; };

	int getExit() { return exit; };
	void setExit(int x) { exit = x; };
	int getEnter() { return enter; };
	void setEnter(int x) { enter = x; };

	float getFare() { return currentFare; };
	void setFare(float x) { currentFare = x; };
	float getBill() { return currentBill; };
	void setBill(float x) { currentBill = x; };


	void calculateBill(){
		float x = exit - enter;
		if (x < 0.0){
			x = std::abs(x);
		}
		currentFare /= 100;
		currentBill += (x * currentFare) + dollarPT;
		Reset();
	}

private:
	int monthA, monthD;
	int dayA, dayD;
	int hourA, hourD;
	int minuteA, minuteD;
	int enter, exit;
	float currentFare;
	float currentBill = 2.00;
	const float dollarPT = 1.00;
	void Reset(){
		monthA = 0, monthD = 0;
		dayA = 0, dayD = 0;
		hourA = 0, hourD = 0;
		minuteA = 0, minuteD = 0;
		enter = 0, exit = 0;
	}
};

#endif