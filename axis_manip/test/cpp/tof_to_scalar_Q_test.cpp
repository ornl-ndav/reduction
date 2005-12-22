#include "constants.hpp"
#include "conversions.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
  int n = 20;

  //float
  Nessi::Vector<float> f_tof;                
  Nessi::Vector<float> f_tof_err2;           
  float f_pathlength;
  float f_pathlength_err2;
  float f_scatt_angle;
  float f_scatt_angle_err2;
  Nessi::Vector<float> f_Q(n);
  Nessi::Vector<float> f_Q_err2(n);
  Nessi::Vector<float> f_true_Q(n);
  Nessi::Vector<float> f_true_Q_err2(n);
  float f_a, f_a2;
  float f_cang, f_cang2;
  float f_sang, f_sang2;
  float f_term1, f_term2, f_term3;

  //double
  Nessi::Vector<double> d_tof;                
  Nessi::Vector<double> d_tof_err2;           
  double d_pathlength;
  double d_pathlength_err2;
  double d_scatt_angle;
  double d_scatt_angle_err2;
  Nessi::Vector<double> d_Q(n);
  Nessi::Vector<double> d_Q_err2(n);
  Nessi::Vector<double> d_true_Q(n);
  Nessi::Vector<double> d_true_Q_err2(n);
  double d_a, d_a2;
  double d_cang, d_cang2;
  double d_sang, d_sang2;
  double d_term1, d_term2, d_term3;

  int error=0;                      //==0,Pass  !=0,Fail

  //initialization
  double pathlength = 43.43;
  double pathlength_err2 = 3.33;
  double scatt_angle = 1.22;
  double scatt_angle_err2 = 0.55;

  f_pathlength = (float)(pathlength);
  f_pathlength_err2 = (float)(pathlength_err2);
  d_pathlength = (double)(pathlength);
  d_pathlength_err2 = (double)(pathlength_err2);

  f_scatt_angle = (float)(scatt_angle);
  f_scatt_angle_err2 = (float)(scatt_angle_err2);
  d_scatt_angle = (double)(scatt_angle);
  d_scatt_angle_err2 = (double)(scatt_angle_err2);
  
  for(int i=0; i<n; i++)            //create the arrays
    {
      f_tof.push_back(2.*(float)i+1);
      f_tof_err2.push_back((float)i+0.5);
      
      d_tof.push_back(2.*(double)i+1);
      d_tof_err2.push_back((double)i+0.5);
    }
  
  AxisManip::tof_to_scalar_Q(f_tof, f_tof_err2,
			     f_pathlength, f_pathlength_err2,
			     f_scatt_angle, f_scatt_angle_err2,
			     f_Q, f_Q_err2);

  AxisManip::tof_to_scalar_Q(d_tof, d_tof_err2,
			     d_pathlength, d_pathlength_err2,
			     d_scatt_angle, d_scatt_angle_err2,
			     d_Q, d_Q_err2);
  
  f_a = static_cast<float>(1/(PhysConst::H_OVER_MNEUT));
  f_a *= 4*static_cast<float>(PhysConst::PI);
  f_a2 = f_a * f_a;
  
  f_cang = static_cast<float>(std::cos(static_cast<double>(f_scatt_angle)));
  f_cang2 = f_cang * f_cang;
  f_sang = static_cast<float>(std::cos(static_cast<double>(f_scatt_angle)));
  f_sang2 = f_sang * f_sang;
  
  f_term1 = f_sang2 * f_pathlength_err2 * f_pathlength_err2;
  f_term2 = f_cang2 * f_pathlength * f_pathlength;
  f_term2 *= (f_scatt_angle_err2 * f_scatt_angle_err2);
  
  f_term3 = f_sang2 * f_pathlength * f_pathlength;

  d_a = static_cast<double>(1/(PhysConst::H_OVER_MNEUT));
  d_a *= 4*static_cast<double>(PhysConst::PI);
  d_a2 = d_a * d_a;
  
  d_cang = static_cast<double>(std::cos(static_cast<double>(d_scatt_angle)));
  d_cang2 = d_cang * d_cang;
  d_sang = static_cast<double>(std::cos(static_cast<double>(d_scatt_angle)));
  d_sang2 = d_sang * d_sang;
  
  d_term1 = d_sang2 * d_pathlength_err2 * d_pathlength_err2;
  d_term2 = d_cang2 * d_pathlength * d_pathlength;
  d_term2 *= (d_scatt_angle_err2 * d_scatt_angle_err2);
  
  d_term3 = d_sang2 * d_pathlength * d_pathlength;

    for (int i = 0; i < n; ++i)
      {
	f_true_Q[i] = f_sang / f_tof[i];
	f_true_Q[i] *= (f_a * f_pathlength);
	f_true_Q_err2[i] = f_tof_err2[i] * f_tof_err2[i];
	f_true_Q_err2[i] /= f_tof[i] * f_tof[i];
	f_true_Q_err2[i] *= f_term3;
	f_true_Q_err2[i] += f_term1 + f_term2;
	f_true_Q_err2[i] *= f_a2 / (f_tof[i] * f_tof[i]);

	d_true_Q[i] = d_sang / d_tof[i];
	d_true_Q[i] *= (d_a * d_pathlength);
	d_true_Q_err2[i] = d_tof_err2[i] * d_tof_err2[i];
	d_true_Q_err2[i] /= d_tof[i] * d_tof[i];
	d_true_Q_err2[i] *= d_term3;
	d_true_Q_err2[i] += d_term1 + d_term2;
	d_true_Q_err2[i] *= d_a2 / (d_tof[i] * d_tof[i]);
      }
    
  //check first if the size are in good agreement
  if ((f_tof.size() != f_Q.size())||(d_tof.size() != d_Q.size()) )
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      while(1)
	{
	  Utils::fd_comparison(f_Q, f_true_Q, error, 10, n);
	  if (error != 0) break;

	  Utils::fd_comparison(f_Q_err2, f_true_Q_err2, error, 20, n);
	  if (error != 0) break;

	  Utils::fd_comparison(d_Q, d_true_Q, error, 110, n);
	  if (error != 0) break;
	  
	  Utils::fd_comparison(d_Q_err2, d_true_Q_err2, error, 120, n);
	  break;
	}
    }
  
  cout << "tof_to_scalar_Q.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK"<<endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes"<<endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector "
	"expected"<<endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
