#include <vector>
#include <cmath>
#include "conversions.hpp"
#include "constants.hpp"
#include <iostream>

using namespace std;

int main() 
{
  int n = 20;

  //float
  vector<float> f_tof;                
  vector<float> f_tof_err2;           
  const float f_pathlength = 3.3;
  vector<float> f_wavelength(n);          
  vector<float> f_wavelength_err2(n);     
  vector<float> f_true_wavelength(n);          
  vector<float> f_true_wavelength_err2(n);     
  const float f_H_OVER_MNEUT = static_cast<float>(0.003961617 / f_pathlength);
  float f_H_OVER_MNEUT2;

  //double
  vector<double> d_tof;                
  vector<double> d_tof_err2;           
  const double d_pathlength = 3.3;
  vector<double> d_wavelength(n);          
  vector<double> d_wavelength_err2(n);     
  vector<double> d_true_wavelength(n);          
  vector<double> d_true_wavelength_err2(n);     
  const double d_H_OVER_MNEUT = static_cast<double>(0.003961617 / d_pathlength);
  double d_H_OVER_MNEUT2;

  //int
  vector<int> i_tof;                
  vector<int> i_tof_err2;           
  const int i_pathlength = 3;
  vector<int> i_wavelength(n);          
  vector<int> i_wavelength_err2(n);     
  vector<int> i_true_wavelength(n);          
  vector<int> i_true_wavelength_err2(n);     
  const int i_H_OVER_MNEUT = static_cast<int>(0.003961617 / i_pathlength);
  int i_H_OVER_MNEUT2;

  //unsigned
  vector<unsigned> u_tof;                
  vector<unsigned> u_tof_err2;           
  const unsigned u_pathlength = 3;
  vector<unsigned> u_wavelength(n);          
  vector<unsigned> u_wavelength_err2(n);     
  vector<unsigned> u_true_wavelength(n);          
  vector<unsigned> u_true_wavelength_err2(n);     
  const unsigned u_H_OVER_MNEUT = static_cast<unsigned>(0.003961617 / u_pathlength);
  unsigned u_H_OVER_MNEUT2;

  int error=0;                      //==0,Pass  !=0,Fail

  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*(float)i);
      d_tof.push_back(2.*(double)i); 
      i_tof.push_back(2*(int)i);
      u_tof.push_back(2*(unsigned)i);

      f_tof_err2.push_back((float)i);
      d_tof_err2.push_back((double)i);      
      i_tof_err2.push_back((int)i);
      u_tof_err2.push_back((unsigned)i);
    }
  
  AxisManip::tof_to_wavelength(f_tof, f_tof_err2, f_pathlength, 
				f_wavelength, f_wavelength_err2);
  AxisManip::tof_to_wavelength(d_tof, d_tof_err2, d_pathlength,
				d_wavelength, d_wavelength_err2);
  AxisManip::tof_to_wavelength(i_tof, i_tof_err2, i_pathlength,
				i_wavelength, i_wavelength_err2);
  AxisManip::tof_to_wavelength(u_tof, u_tof_err2, u_pathlength,
				u_wavelength, u_wavelength_err2);
  
  f_H_OVER_MNEUT2 = f_H_OVER_MNEUT * f_H_OVER_MNEUT;
  d_H_OVER_MNEUT2 = d_H_OVER_MNEUT * d_H_OVER_MNEUT;
  i_H_OVER_MNEUT2 = i_H_OVER_MNEUT * i_H_OVER_MNEUT;
  u_H_OVER_MNEUT2 = u_H_OVER_MNEUT * u_H_OVER_MNEUT;
  
  for (int i=0; i<n; i++)
    {
      //float
      f_true_wavelength[i] = f_H_OVER_MNEUT * f_tof[i];
      f_true_wavelength_err2[i] = f_H_OVER_MNEUT2 * f_tof_err2[i];
      
      //double
      d_true_wavelength[i] = d_H_OVER_MNEUT * d_tof[i];
      d_true_wavelength_err2[i] = d_H_OVER_MNEUT2 * d_tof_err2[i];

      //int
      i_true_wavelength[i] = i_H_OVER_MNEUT * i_tof[i];
      i_true_wavelength_err2[i] = i_H_OVER_MNEUT2 * i_tof_err2[i];

      //unsigned
      u_true_wavelength[i] = u_H_OVER_MNEUT * u_tof[i];
      u_true_wavelength_err2[i] = u_H_OVER_MNEUT2 * u_tof_err2[i];
    }
  
  //check first if the size are in good agreement
  if ((f_tof.size() != f_wavelength.size())||(d_tof.size() != d_wavelength.size()) || (i_tof.size() != i_wavelength.size()) || (u_tof.size() != u_wavelength.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
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
	  //	  if (fabs(d_wavelength[i] - d_true_wavelength[i]) > 0.000001)
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
	  if (i_wavelength[i] != i_true_wavelength[i])
	    {
	      error=error+210;
	      break;
	    }
	  if (i_wavelength_err2[i] != i_true_wavelength_err2[i])
	    {
	      error=error+220;
	      break;
	    }
	  if (u_wavelength[i] != u_true_wavelength[i])
	    {
	      error=error+310;
	      break;
	    }
	  if (u_wavelength_err2[i] != u_true_wavelength_err2[i])
	    {
	      error=error+320;
	      break;
	    }
	}
    }

  cout << "tof_to_wavelength_test.cpp..........";

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
