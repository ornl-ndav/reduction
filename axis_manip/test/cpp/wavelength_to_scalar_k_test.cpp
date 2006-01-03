#include "conversions.hpp"
#include "constants.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
  int num_val = 20;

  //float
  Nessi::Vector<float> f_wavelength;                
  float f_wavelength2;
  Nessi::Vector<float> f_wavelength_err2;           
  Nessi::Vector<float> f_wavevector(num_val);          
  Nessi::Vector<float> f_wavevector_err2(num_val);     
  Nessi::Vector<float> f_true_wavevector(num_val);          
  Nessi::Vector<float> f_true_wavevector_err2(num_val);     
  float f_a, f_a2;

  //double
  Nessi::Vector<double> d_wavelength;                
  double d_wavelength2;
  Nessi::Vector<double> d_wavelength_err2;           
  Nessi::Vector<double> d_wavevector(num_val);          
  Nessi::Vector<double> d_wavevector_err2(num_val);     
  Nessi::Vector<double> d_true_wavevector(num_val);          
  Nessi::Vector<double> d_true_wavevector_err2(num_val);     
  double d_a, d_a2;

  int error=0;                      //==0,Pass  !=0,Fail

  f_a = 2. * static_cast<float>(PhysConst::PI);
  f_a2 = f_a * f_a;

  d_a = 2. * PhysConst::PI;
  d_a2 = d_a * d_a;

  for (int i = 0 ; i < num_val ; i++)            //create the arrays
    {
      //_input1 array
      f_wavelength.push_back(2.*static_cast<float>(i));
      d_wavelength.push_back(2.*static_cast<double>(i)); 

      f_wavelength_err2.push_back(static_cast<float>(i));
      d_wavelength_err2.push_back(static_cast<double>(i));      
    }
  
  AxisManip::wavelength_to_scalar_k(f_wavelength, f_wavelength_err2,  
                                    f_wavevector, f_wavevector_err2);
  AxisManip::wavelength_to_scalar_k(d_wavelength, d_wavelength_err2, 
                                    d_wavevector, d_wavevector_err2);
  
  for (int i = 0 ; i < num_val ; i++)
    {
      //float
      f_true_wavevector[i] = f_a / f_wavelength[i];
      f_wavelength2 = (f_wavelength[i] * f_wavelength[i] 
		      * f_wavelength[i] * f_wavelength[i]);
      f_true_wavevector_err2[i] = (f_a2 * f_wavelength_err2[i]) /
	f_wavelength2;
      
      //double
      d_true_wavevector[i] = d_a / d_wavelength[i];
      d_wavelength2 = 	(d_wavelength[i] * d_wavelength[i] 
			 * d_wavelength[i] * d_wavelength[i]);
      d_true_wavevector_err2[i] = (d_a2 * d_wavelength_err2[i]) /
	d_wavelength2;
    }
  
  //check first if the size are in good agreement
  if ( (f_wavelength.size() != f_wavevector.size())
       || (d_wavelength.size() != d_wavevector.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error;
    }
  else
    {
      while(1)
	{
	  Utils::vector_comparison(f_wavevector, f_true_wavevector, error, 10);
	  if (error != 0) break;
	  Utils::vector_comparison(f_wavevector_err2, f_true_wavevector_err2,
                               error, 20);
	  if (error != 0) break;
	  
	  Utils::vector_comparison(d_wavevector, d_true_wavevector, error, 110);
	  if (error != 0) break;
	  Utils::vector_comparison(d_wavevector_err2, d_true_wavevector_err2,
                               error, 120);
	  if (error != 0) break;

	  break;
	  
	}
    }

  cout << "wavelength_to_scalar_k.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK" << endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes" << endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"
           << endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector "
           << "expected" << endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector expected"
           << endl;
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
