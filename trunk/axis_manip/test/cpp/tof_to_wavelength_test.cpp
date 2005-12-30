#include "nessi.hpp"
#include "constants.hpp"
#include "conversions.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
  int num_val = 20;

  //float
  Nessi::Vector<float> f_tof;                
  Nessi::Vector<float> f_tof_err2;           
  const float f_pathlength = 3.3;
  const float f_pathlength_err2 = .3;
  Nessi::Vector<float> f_wavelength(num_val);          
  Nessi::Vector<float> f_wavelength_err2(num_val);     
  Nessi::Vector<float> f_true_wavelength(num_val);          
  Nessi::Vector<float> f_true_wavelength_err2(num_val);     
  const float f_a = static_cast<float>(PhysConst::H_OVER_MNEUT)/f_pathlength;
  float f_a_err2 = static_cast<float>(PhysConst::H_OVER_MNEUT)/f_pathlength;
  f_a_err2=f_a_err2*f_a_err2*f_pathlength_err2;

  //double
  Nessi::Vector<double> d_tof;                
  Nessi::Vector<double> d_tof_err2;           
  const double d_pathlength = 3.3;
  const double d_pathlength_err2 = .3;
  Nessi::Vector<double> d_wavelength(num_val);          
  Nessi::Vector<double> d_wavelength_err2(num_val);     
  Nessi::Vector<double> d_true_wavelength(num_val);          
  Nessi::Vector<double> d_true_wavelength_err2(num_val);     
  const double d_a = static_cast<double>(PhysConst::H_OVER_MNEUT)/d_pathlength;
  double d_a_err2 = static_cast<double>(PhysConst::H_OVER_MNEUT)/d_pathlength;
  d_a_err2=d_a_err2*d_a_err2*d_pathlength_err2;
  
  int error=0;                      //==0,Pass  !=0,Fail

  for (int i = 0 ; i < num_val ; i++)            //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*static_cast<float>(i));
      d_tof.push_back(2.*static_cast<double>(i));

      f_tof_err2.push_back(static_cast<float>(i));
      d_tof_err2.push_back(static_cast<double>(i));
    }
  
  AxisManip::tof_to_wavelength(f_tof, f_tof_err2, 
			       f_pathlength, f_pathlength_err2,
			       f_wavelength, f_wavelength_err2);

  AxisManip::tof_to_wavelength(d_tof, d_tof_err2, 
			       d_pathlength, d_pathlength_err2,
			       d_wavelength, d_wavelength_err2);

  for (int i = 0 ; i < num_val ; i++)
    {
      f_true_wavelength[i] = f_a * f_tof[i];
      f_true_wavelength_err2[i] = (f_a*f_a) * f_tof_err2[i]
        + ((f_tof[i]*f_tof[i])*f_a_err2);
      
      d_true_wavelength[i] = d_a * d_tof[i];
      d_true_wavelength_err2[i] = (d_a*d_a) * d_tof_err2[i]
        + ((d_tof[i]*d_tof[i])*d_a_err2);
    }
  
  //check first if the size are in good agreement
  if ( (f_tof.size() != f_wavelength.size())
       || (d_tof.size() != d_wavelength.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error;
    }
  else
    {
      while(1)
	{
      Utils::vector_comparison(f_wavelength, f_true_wavelength, error, 10,
                           num_val);
      if (error != 0) break;
      Utils::vector_comparison(f_wavelength_err2, f_true_wavelength_err2, 
			   error, 20, num_val);
      if (error != 0) break;

      Utils::vector_comparison(d_wavelength, d_true_wavelength, error, 110,
                           num_val);
      if (error != 0) break;
      Utils::vector_comparison(d_wavelength_err2, d_true_wavelength_err2, 
			   error, 120, num_val);
      if (error != 0) break;

      break;
	}
    }
  
  cout << "tof_to_wavelength.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK" << endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes" << endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector "
           << "expected" << endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector "
           << "expected" << endl;
      break;
    default:
      cout << "FAILED" << endl;
      break;
    }

  return 0;
}
