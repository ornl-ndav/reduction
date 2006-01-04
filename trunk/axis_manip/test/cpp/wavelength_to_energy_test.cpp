#include "constants.hpp"
#include "conversions.hpp"
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
  Nessi::Vector<float> f_wavelength_err2;           
  Nessi::Vector<float> f_energy(num_val);          
  Nessi::Vector<float> f_energy_err2(num_val);     
  Nessi::Vector<float> f_true_energy(num_val);          
  Nessi::Vector<float> f_true_energy_err2(num_val);     
  float f_wavelength2;
  float f_a2;

  //double
  Nessi::Vector<double> d_wavelength;                
  Nessi::Vector<double> d_wavelength_err2;           
  Nessi::Vector<double> d_energy(num_val);          
  Nessi::Vector<double> d_energy_err2(num_val);     
  Nessi::Vector<double> d_true_energy(num_val);          
  Nessi::Vector<double> d_true_energy_err2(num_val);     
  double d_wavelength2;
  double d_a2;

  int error=0;                      //==0,Pass  !=0,Fail

  f_a2 = static_cast<float>(2) * static_cast<float>(PhysConst::H2_OVER_2MNEUT);
  f_a2=f_a2*f_a2;
  d_a2 = static_cast<double>(4) * PhysConst::H2_OVER_2MNEUT;
  d_a2=d_a2*d_a2;

  for (int i = 0 ; i < num_val ; i++)            //create the arrays
    {
      f_wavelength.push_back(2.*static_cast<float>(i));
      d_wavelength.push_back(2.*static_cast<double>(i)); 

      f_wavelength_err2.push_back(static_cast<float>(i));
      d_wavelength_err2.push_back(static_cast<double>(i));      
    }
  
  AxisManip::wavelength_to_energy(f_wavelength, f_wavelength_err2,  
				f_energy, f_energy_err2);
  AxisManip::wavelength_to_energy(d_wavelength, d_wavelength_err2, 
				d_energy, d_energy_err2);
  
  for (int i = 0 ; i < num_val ; i++)
    {
      //float
      f_wavelength2 = f_wavelength[i] * f_wavelength[i];
      f_true_energy[i] = static_cast<float>(PhysConst::H2_OVER_2MNEUT)
        / f_wavelength2;
      f_true_energy_err2[i] = (f_a2 * f_wavelength_err2[i])
        / (f_wavelength2 * f_wavelength2 * f_wavelength2);

      //double
      d_wavelength2 = d_wavelength[i] * d_wavelength[i];
      d_true_energy[i] = PhysConst::H2_OVER_2MNEUT / d_wavelength2;
      d_true_energy_err2[i] = (d_a2 * d_wavelength_err2[i])
        / (d_wavelength2 * d_wavelength2 * d_wavelength2);
    }
  
  //check first if the size are in good agreement
  if ( (f_wavelength.size() != f_energy.size())
       || (d_wavelength.size() != d_energy.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error;
    }
  else
    {
      
      while(1)
	{
	  Utils::vector_comparison(f_energy, f_true_energy, error, 10);
	  if (error != 0) break;
	  Utils::vector_comparison(f_energy_err2, f_true_energy_err2, error, 20);
	  if (error != 0) break;
	  
	  Utils::vector_comparison(d_energy, d_true_energy, error, 110);
	  if (error != 0) break;
	  Utils::vector_comparison(d_energy_err2, d_true_energy_err2, error, 120);
	  if (error != 0) break;

	  break;
	}
    }

  cout << "wavelength_to_energy_test.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK" << endl;
      break;
    case 1:
      cout << "FAILED....Output and input vectors have different sizes" << endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"
           << endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector"
           << " expected" << endl;
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
