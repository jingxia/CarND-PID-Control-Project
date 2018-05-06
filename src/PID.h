#ifndef PID_H
#define PID_H

class PID {

private:
  double cte_prev;
  double cte_sum;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

public:
  /*
  * Constructor
  */
  PID(double kp, double ki, double kd);

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double CalculateSteeringValue(double cte);
};

#endif /* PID_H */
