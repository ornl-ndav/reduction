#include "constants.hpp"
#include "conversions.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  int n = 20;

  //float
  vector<float> f_tof;                
  vector<float> f_tof_err2;           
  const float f_pathlength = 3.3;
  const float f_pathlength_err2 = .3;
  vector<float> f_wavelength(n);          
  vector<float> f_wavelength_err2(n);     
  vector<float> f_true_wavelength(n);          
  vector<float> f_true_wavelength_err2(n);     
  const float f_a = static_cast<float>(PhysConst::H_OVER_MNEUT)/f_pathlength;
  float f_a_err2 = static_cast<float>(PhysConst::H_OVER_MNEUT)/f_pathlength;
  f_a_err2=f_a_err2*f_a_err2*f_pathlength_err2;

  //double
  vector<double> d_tof;                
  vector<double> d_tof_err2;           
  const double d_pathlength = 3.3;
  const double d_pathlength_err2 = .3;
  vector<double> d_wavelength(n);          
  vector<double> d_wavelength_err2(n);     
  vector<double> d_true_wavelength(n);          
  vector<double> d_true_wavelength_err2(n);     
  const double d_a = static_cast<double>(PhysConst::H_OVER_MNEUT)/d_pathlength;
  double d_a_err2 = static_cast<double>(PhysConst::H_OVER_MNEUT)/d_pathlength;
  d_a_err2=d_a_err2*d_a_err2*d_pathlength_err2;
  
  int error=0;                      //==0,Pass  !=0,Fail

  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*(float)i);
      d_tof.push_back(2.*(double)i); 

      f_tof_err2.push_back((float)i);
      d_tof_err2.push_back((double)i);      
    }
  
  AxisManip::tof_to_wavelength(f_tof, f_tof_err2, 
			       f_pathlength, f_pathlength_err2,
			       f_wavelength, f_wavelength_err2);

  AxisManip::tof_to_wavelength(d_tof, d_tof_err2, 
			       d_pathlength, d_pathlength_err2,
			       d_wavelength, d_wavelength_err2);

  for (int i=0; i<n; i++)
    {
      f_true_wavelength[i] = f_a * f_tof[i];
      f_true_wavelength_err2[i] = (f_a*f_a) * f_tof_err2[i]
        + ((f_tof[i]*f_tof[i])*f_a_err2);
      
      d_true_wavelength[i] = d_a * d_tof[i];
      d_true_wavelength_err2[i] = (d_a*d_a) * d_tof_err2[i]
        + ((d_tof[i]*d_tof[i])*d_a_err2);
    }
  
  //check first if the size are in good agreement
  if ((f_tof.size() != f_wavelength.size())||(d_tof.size() != d_wavelength.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      while(1)
	{
      Utils::fd_comparison(f_wavelength, f_true_wavelength, error, 10, n);
      if (error != 0) break;
      Utils::fd_comparison(f_wavelength_err2, f_true_wavelength_err2, error, 20, n);
      if (error != 0) break;

      Utils::fd_comparison(d_wavelength, d_true_wavelength, error, 110, n);
      if (error != 0) break;
      Utils::fd_comparison(d_wavelength_err2, d_true_wavelength_err2, error, 120, n);
      if (error != 0) break;

      break;
	}

      /*
       for (int i=0; i<n;++i)
	{
	  if (fabs(f_wavelength[i] - f_true_wavelength[i])>0.000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_wavelength_err2[i] - f_true_wavelength_err2[i])>0.000001)
	    {
	      error=error+20;
	      break;
	    }
	  if (fabs(d_wavelength[i] - d_true_wavelength[i]) > 0.0001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_wavelength_err2[i] - d_true_wavelength_err2[i])> 0.0001)
	    {
	      error=error+120;
	      break;
	    }
      */

	}

  cout << "tof_to_wavelength.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK"<<endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes"<<endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"<<endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector expected"<<endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector expected"<<endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
