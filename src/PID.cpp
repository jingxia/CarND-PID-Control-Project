#include "PID.h" 
#include <algorithm> 
#include <iostream> 

using namespace std;

/*
* TODO: Complete the PID class.
*/
PID::PID(double kp, double ki, double kd):Kp(kp), Ki(ki), Kd(kd){}

PID::~PID() {}

void PID::UpdateError(double cte) {
  cte_sum += cte;
  cte_prev = cte;
}

double PID::TotalError() {
  return cte_sum;
}

double PID::CalculateSteeringValue(double cte)
{
  double  p_portion = Kp * cte; 
  double  i_portion = Ki * (cte_sum + cte);
  double  d_portion = Kd * (cte - cte_prev);

  UpdateError(cte);

  double steering = -1 *(p_portion + i_portion + d_portion);

  return max(min(steering, 1.0), -1.0);
}


