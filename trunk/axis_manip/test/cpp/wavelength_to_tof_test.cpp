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
  Nessi::Vector<float> f_wavelength;                
  Nessi::Vector<float> f_wavelength_err2;           
  float f_pathlength;
  float f_pathlength_err2;
  Nessi::Vector<float> f_tof(n);
  Nessi::Vector<float> f_tof_err2(n);
  Nessi::Vector<float> f_true_tof(n);
  Nessi::Vector<float> f_true_tof_err2(n);
  float f_a, f_a2;
  float f_b, f_c;

  //double
  Nessi::Vector<double> d_wavelength;                
  Nessi::Vector<double> d_wavelength_err2;           
  double d_pathlength;
  double d_pathlength_err2;
  Nessi::Vector<double> d_tof(n);
  Nessi::Vector<double> d_tof_err2(n);
  Nessi::Vector<double> d_true_tof(n);
  Nessi::Vector<double> d_true_tof_err2(n);
  double d_a, d_a2;
  double d_b, d_c;

  int error=0;                      //==0,Pass  !=0,Fail

  //initialization
  double pathlength = 43.43;
  double pathlength_err2 = 3.33;

  f_pathlength = (float)(pathlength);
  f_pathlength_err2 = (float)(pathlength_err2);

  d_pathlength = (double)(pathlength);
  d_pathlength_err2 = (double)(pathlength_err2);
  
  for(int i=0; i<n; i++)            //create the arrays
    {
      f_wavelength.push_back(2.*(float)i+1);
      f_wavelength_err2.push_back((float)i+0.5);
      
      d_wavelength.push_back(2.*(double)i+1);
      d_wavelength_err2.push_back((double)i+0.5);
    }
  
  AxisManip::wavelength_to_tof(f_wavelength, f_wavelength_err2,
			       f_pathlength, f_pathlength_err2,
			       f_tof, f_tof_err2);

  AxisManip::wavelength_to_tof(d_wavelength, d_wavelength_err2,
			       d_pathlength, d_pathlength_err2,
			       d_tof, d_tof_err2);

  
    f_a = (float)(1 / (PhysConst::H_OVER_MNEUT));
    f_a2 = f_a * f_a;
    f_a = f_a * f_pathlength;
    f_b = f_pathlength * f_pathlength;
    f_c = f_pathlength_err2 * f_pathlength_err2;
    
    d_a = (double)(1 / (PhysConst::H_OVER_MNEUT));
    d_a2 = d_a * d_a;
    d_a = d_a * d_pathlength;
    d_b = d_pathlength * d_pathlength;
    d_c = d_pathlength_err2 * d_pathlength_err2;
    
    for (int i = 0; i < n ; ++i)
      {
	f_true_tof[i] = f_a * f_wavelength[i];
	f_true_tof_err2[i] = f_wavelength[i] * f_wavelength[i] * f_c;
	f_true_tof_err2[i] += f_b * (f_wavelength_err2[i] *
				     f_wavelength_err2[i]);
	f_true_tof_err2[i] *= f_a2;

	d_true_tof[i] = d_a * d_wavelength[i];
	d_true_tof_err2[i] = d_wavelength[i] * d_wavelength[i] * d_c;
	d_true_tof_err2[i] += d_b * (d_wavelength_err2[i] * 
    				     d_wavelength_err2[i]);
	d_true_tof_err2[i] *= d_a2;
      }
    
  //check first if the size are in good agreement
  if ((f_tof.size() != f_wavelength.size())||(d_tof.size() != 
					      d_wavelength.size()) )
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      while(1)
	{
	  Utils::fd_comparison(f_tof, f_true_tof, error, 10, n);
	  if (error != 0) break;

	  Utils::fd_comparison(f_tof_err2, f_true_tof_err2, error, 20, n);
	  if (error != 0) break;

	  Utils::fd_comparison(d_tof, d_true_tof, error, 110, n);
	  if (error != 0) break;
	  
	  Utils::fd_comparison(d_tof_err2, d_true_tof_err2, error, 120, n);
	  break;
	}
    }
  
  cout << "wavelength_to_tof.cpp..........";

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
      cout << "(double) FAILED....Output vector different from vector"
	" expected"<<endl;
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
