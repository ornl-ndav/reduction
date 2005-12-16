#include "conversions.hpp"
#include "constants.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  int n = 20;

  //float
  vector<float> f_wavelength;                
  float f_wavelength2;
  vector<float> f_wavelength_err2;           
  vector<float> f_wavevector(n);          
  vector<float> f_wavevector_err2(n);     
  vector<float> f_true_wavevector(n);          
  vector<float> f_true_wavevector_err2(n);     
  float f_a, f_a2;

  //double
  vector<double> d_wavelength;                
  double d_wavelength2;
  vector<double> d_wavelength_err2;           
  vector<double> d_wavevector(n);          
  vector<double> d_wavevector_err2(n);     
  vector<double> d_true_wavevector(n);          
  vector<double> d_true_wavevector_err2(n);     
  double d_a, d_a2;

  //int
  vector<int> i_wavelength;                
  int i_wavelength2;
  vector<int> i_wavelength_err2;           
  vector<int> i_wavevector(n);          
  vector<int> i_wavevector_err2(n);     
  vector<int> i_true_wavevector(n);          
  vector<int> i_true_wavevector_err2(n);     
  int i_a, i_a2;

  //unsigned
  vector<unsigned int> u_wavelength;                
  unsigned int u_wavelength2;
  vector<unsigned int> u_wavelength_err2;           
  vector<unsigned int> u_wavevector(n);          
  vector<unsigned int> u_wavevector_err2(n);     
  vector<unsigned int> u_true_wavevector(n);          
  vector<unsigned int> u_true_wavevector_err2(n);     
  unsigned int u_a, u_a2;

  int error=0;                      //==0,Pass  !=0,Fail

  f_a = 2 * (float)(PhysConst::PI);
  f_a2 = f_a * f_a;

  d_a = 2 * (double)(PhysConst::PI);
  d_a2 = d_a * d_a;

  i_a = 2 * (int)(PhysConst::PI);
  i_a2 = i_a * i_a;

  u_a = 2 * (unsigned int)(PhysConst::PI);
  u_a2 = u_a * u_a;

  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_wavelength.push_back(2.*(float)i);
      d_wavelength.push_back(2.*(double)i); 
      i_wavelength.push_back(2*(int)i+1);
      u_wavelength.push_back(2*(unsigned int)i+1);

      f_wavelength_err2.push_back((float)i);
      d_wavelength_err2.push_back((double)i);      
      i_wavelength_err2.push_back((int)i+1);
      u_wavelength_err2.push_back((unsigned int)i+1);
    }
  
  AxisManip::wavelength_to_scalar_k(f_wavelength, f_wavelength_err2,  
				f_wavevector, f_wavevector_err2);
  AxisManip::wavelength_to_scalar_k(d_wavelength, d_wavelength_err2, 
				d_wavevector, d_wavevector_err2);
  AxisManip::wavelength_to_scalar_k(i_wavelength, i_wavelength_err2, 
				i_wavevector, i_wavevector_err2);
  AxisManip::wavelength_to_scalar_k(u_wavelength, u_wavelength_err2, 
				u_wavevector, u_wavevector_err2);
  
  for (int i=0; i<n; i++)
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
      
      //int
      i_true_wavevector[i] = i_a / i_wavelength[i];
      i_wavelength2 = 	(i_wavelength[i] * i_wavelength[i] 
			 * i_wavelength[i] * i_wavelength[i]);
      i_true_wavevector_err2[i] = (i_a2 * i_wavelength_err2[i]) /
	i_wavelength2;
      
      //unsigned int
      u_true_wavevector[i] = u_a / u_wavelength[i];
      u_wavelength2 = 	(u_wavelength[i] * u_wavelength[i] 
			 * u_wavelength[i] * u_wavelength[i]);
      u_true_wavevector_err2[i] = (u_a2 * u_wavelength_err2[i]) /
	u_wavelength2;
    }
  
  //check first if the size are in good agreement
  if ((f_wavelength.size() != f_wavevector.size())||(d_wavelength.size() != d_wavevector.size()) || (i_wavelength.size() != i_wavevector.size()) || (u_wavelength.size() != u_wavevector.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      while(1)
	{
	  Utils::fd_comparison(f_wavevector, f_true_wavevector, error, 10, n);
	  if (error != 0) break;
	  Utils::fd_comparison(f_wavevector_err2, f_true_wavevector_err2, error, 20, n);
	  if (error != 0) break;
	  
	  Utils::fd_comparison(d_wavevector, d_true_wavevector, error, 110, n);
	  if (error != 0) break;
	  Utils::fd_comparison(d_wavevector_err2, d_true_wavevector_err2, error, 120, n);
	  if (error != 0) break;

	  Utils::iu_comparison(i_wavevector, i_true_wavevector, error, 210, n);
	  if (error != 0) break;
	  Utils::iu_comparison(i_wavevector_err2, i_true_wavevector_err2, error, 220, n);
	  if (error != 0) break;

	  Utils::iu_comparison(u_wavevector, u_true_wavevector, error, 310, n);
	  if (error != 0) break;
	  Utils::iu_comparison(u_wavevector_err2, u_true_wavevector_err2, error, 320, n);
	  break;
	  
	}
    }

  cout << "wavelength_to_scalar_k.cpp..........";

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
    case 210:
      cout << "(int) FAILED....Output vector different from vector expected"<<endl;
      break;
    case 220:
      cout << "(int) FAILED....Output error vector different from vector expected"<<endl;
      break;
    case 310:
      cout << "(unsigned int) FAILED....Output vector different from vector expected"<<endl;
      break;
    case 320:
      cout << "(unsigned int) FAILED....Output error vector different from vector expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
