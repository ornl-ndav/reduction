#include <vector>
#include <cmath>
#include "conversions.hpp"
#include "constants.hpp"
#include <iostream>

using namespace std;
static const double PI = 3.14159265358979323846264338328;

int main() 
{
  int n = 20;

  //float
  vector<float> f_wavelength;                
  vector<float> f_wavelength_err2;           
  vector<float> f_wavevector(n);          
  vector<float> f_wavevector_err2(n);     
  vector<float> f_true_wavevector(n);          
  vector<float> f_true_wavevector_err2(n);     
  float f_a, f_a2;

  //double
  vector<double> d_wavelength;                
  vector<double> d_wavelength_err2;           
  vector<double> d_wavevector(n);          
  vector<double> d_wavevector_err2(n);     
  vector<double> d_true_wavevector(n);          
  vector<double> d_true_wavevector_err2(n);     
  double d_a, d_a2;

  //int
  vector<int> i_wavelength;                
  vector<int> i_wavelength_err2;           
  vector<int> i_wavevector(n);          
  vector<int> i_wavevector_err2(n);     
  vector<int> i_true_wavevector(n);          
  vector<int> i_true_wavevector_err2(n);     
  int i_a, i_a2;

  //unsigned
  vector<unsigned> u_wavelength;                
  vector<unsigned> u_wavelength_err2;           
  vector<unsigned> u_wavevector(n);          
  vector<unsigned> u_wavevector_err2(n);     
  vector<unsigned> u_true_wavevector(n);          
  vector<unsigned> u_true_wavevector_err2(n);     
  unsigned u_a, u_a2;

  int error=0;                      //==0,Pass  !=0,Fail

  
  f_a = 2 * static_cast<float>(PI);
  f_a2 = f_a * f_a;

  d_a = 2 * static_cast<double>(PI);
  d_a2 = d_a * d_a;

  i_a = 2 * static_cast<int>(PI);
  i_a2 = i_a * i_a;

  u_a = 2 * static_cast<unsigned>(PI);
  u_a2 = u_a * u_a;

  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_wavelength.push_back(2.*(float)i);
      d_wavelength.push_back(2.*(double)i); 
      i_wavelength.push_back(2*(int)i+1);
      u_wavelength.push_back(2*(unsigned)i+1);

      f_wavelength_err2.push_back((float)i);
      d_wavelength_err2.push_back((double)i);      
      i_wavelength_err2.push_back((int)i+1);
      u_wavelength_err2.push_back((unsigned)i+1);
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
      f_true_wavevector_err2[i] = (f_a2 * f_wavelength_err2[i]) /
	(f_wavelength[i] * f_wavelength[i] * f_wavelength[i] * f_wavelength[i]);

      //double
      d_true_wavevector[i] = d_a / d_wavelength[i];
      d_true_wavevector_err2[i] = (d_a2 * d_wavelength_err2[i]) /
	(d_wavelength[i] * d_wavelength[i] * d_wavelength[i] * d_wavelength[i]);

      //int
      i_true_wavevector[i] = i_a / i_wavelength[i];
      i_true_wavevector_err2[i] = (i_a2 * i_wavelength_err2[i]) /
	(i_wavelength[i] * i_wavelength[i] * i_wavelength[i] * i_wavelength[i]);

      //unsigned
      u_true_wavevector[i] = u_a / u_wavelength[i];
      u_true_wavevector_err2[i] = (u_a2 * u_wavelength_err2[i]) /
	(u_wavelength[i] * u_wavelength[i] * u_wavelength[i] * u_wavelength[i]);
    }
  
  //check first if the size are in good agreement
  if ((f_wavelength.size() != f_wavevector.size())||(d_wavelength.size() != d_wavevector.size()) || (i_wavelength.size() != i_wavevector.size()) || (u_wavelength.size() != u_wavevector.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for (int i=0; i<n;++i)
	{
	  if (fabs(f_wavevector[i] - f_true_wavevector[i])>0.000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_wavevector_err2[i] - f_true_wavevector_err2[i])>0.000001)
	    {
	      error=error+20;
	      break;
	    }
	  //	  if (fabs(d_wavevector[i] - d_true_wavevector[i]) > 0.000001)
	  if (fabs(d_wavevector[i] - d_true_wavevector[i]) > 0.0001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_wavevector_err2[i] - d_true_wavevector_err2[i])> 0.0001)
	    {
	      error=error+120;
	      break;
	    }
	  if (i_wavevector[i] != i_true_wavevector[i])
	    {
	      error=error+210;
	      break;
	    }
	  if (i_wavevector_err2[i] != i_true_wavevector_err2[i])
	    {
	      error=error+220;
	      break;
	    }
	  if (u_wavevector[i] != u_true_wavevector[i])
	    {
	      error=error+310;
	      break;
	    }
	  if (u_wavevector_err2[i] != u_true_wavevector_err2[i])
	    {
	      error=error+320;
	      break;
	    }
	}
    }

  cout << "wavelength_to_scalar_k_test.cpp..........";

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
      cout << "(unsigned) FAILED....Output vector different from vector expected"<<endl;
      break;
    case 320:
      cout << "(unsigned) FAILED....Output error vector different from vector expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
