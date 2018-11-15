#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	/*	Initialize Proportional, Integral, Derivative parameters:
	steering = -Kp * CTE - Kd * diff_CTE - Ki * int_CTE
	where the integrated crosstrack error (int_CTE) is the sum of all the previous crosstrack errors. This term works to cancel out steering drift.
	*/
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	PID::prev = false;

	pError = 0.0;
  	iError = 0.0;
  	dError = 0.0;

  	// Previous cte.
  	prevCTE = 0.0;
  	intCTE = 0.0;
  	//diffCTE = 0.0;
	
}

void PID::UpdateError(double cte) {
	/* Update
	*/
	if (!prev) {
		prevCTE = cte;
		prev = true;
	}

	double diffCTE = cte - prevCTE;   // one period
	intCTE += cte;

	pError = Kp * cte;
	iError = Ki * intCTE;
	dError = Kd* diffCTE;

	prevCTE = cte;

}

double PID::TotalError() {
	/* Calculate Total
	*/
	double totError = pError + dError + iError;

	return totError;
}

