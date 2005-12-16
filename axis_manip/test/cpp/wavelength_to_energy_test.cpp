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
  vector<float> f_wavelength;                
  vector<float> f_wavelength_err2;           
  vector<float> f_energy(n);          
  vector<float> f_energy_err2(n);     
  vector<float> f_true_energy(n);          
  vector<float> f_true_energy_err2(n);     
  float f_wavelength2;
  float f_a2;

  //double
  vector<double> d_wavelength;                
  vector<double> d_wavelength_err2;           
  vector<double> d_energy(n);          
  vector<double> d_energy_err2(n);     
  vector<double> d_true_energy(n);          
  vector<double> d_true_energy_err2(n);     
  double d_wavelength2;
  double d_a2;

  //int
  vector<int> i_wavelength;                
  vector<int> i_wavelength_err2;           
  vector<int> i_energy(n);          
  vector<int> i_energy_err2(n);     
  vector<int> i_true_energy(n);          
  vector<int> i_true_energy_err2(n);     
  int i_wavelength2;
  int i_a2;

  //unsigned
  vector<unsigned int> u_wavelength;                
  vector<unsigned int> u_wavelength_err2;           
  vector<unsigned int> u_energy(n);          
  vector<unsigned int> u_energy_err2(n);     
  vector<unsigned int> u_true_energy(n);          
  vector<unsigned int> u_true_energy_err2(n);     
  unsigned int u_wavelength2;
  unsigned int u_a2;


  int error=0;                      //==0,Pass  !=0,Fail

  f_a2 = 4 * (float)PhysConst::H2_OVER_2MNEUT * (float)PhysConst::H2_OVER_2MNEUT;
  d_a2 = 4 * (double)PhysConst::H2_OVER_2MNEUT * (double)PhysConst::H2_OVER_2MNEUT;
  i_a2 = 4 * (int)PhysConst::H2_OVER_2MNEUT * (int)PhysConst::H2_OVER_2MNEUT;
  u_a2 = 4 * (unsigned int)PhysConst::H2_OVER_2MNEUT * (unsigned int)PhysConst::H2_OVER_2MNEUT;

  for(int i=0; i<n; i++)            //create the arrays
    {
      f_wavelength.push_back(2.*(float)i);
      d_wavelength.push_back(2.*(double)i); 
      i_wavelength.push_back(2*(int)i+1);
      u_wavelength.push_back(2*(unsigned int)i+1);

      f_wavelength_err2.push_back((float)i);
      d_wavelength_err2.push_back((double)i);      
      i_wavelength_err2.push_back((int)i+1);
      u_wavelength_err2.push_back((unsigned int)i+1);
    }
  
  AxisManip::wavelength_to_energy(f_wavelength, f_wavelength_err2,  
				f_energy, f_energy_err2);
  AxisManip::wavelength_to_energy(d_wavelength, d_wavelength_err2, 
				d_energy, d_energy_err2);
  AxisManip::wavelength_to_energy(i_wavelength, i_wavelength_err2, 
				i_energy, i_energy_err2);
  AxisManip::wavelength_to_energy(u_wavelength, u_wavelength_err2, 
				u_energy, u_energy_err2);
  
  for (int i=0; i<n; i++)
    {
      //float
      f_wavelength2 = f_wavelength[i] * f_wavelength[i];
      f_true_energy[i] = (float)(PhysConst::H2_OVER_2MNEUT) / f_wavelength2;
      f_true_energy_err2[i] = (f_a2 * f_wavelength_err2[i]) /
	(f_wavelength2 * f_wavelength2 * f_wavelength2);

      //double
      d_wavelength2 = d_wavelength[i] * d_wavelength[i];
      d_true_energy[i] = (double)(PhysConst::H2_OVER_2MNEUT) / d_wavelength2;
      d_true_energy_err2[i] = (d_a2 * d_wavelength_err2[i]) / 
	(d_wavelength2 * d_wavelength2 * d_wavelength2);
      
      //int
      i_wavelength2 = i_wavelength[i] * i_wavelength[i];
      i_true_energy[i] = (int)(PhysConst::H2_OVER_2MNEUT) / i_wavelength2;
      i_true_energy_err2[i] = (i_a2 * i_wavelength_err2[i]) / 
	(i_wavelength2 * i_wavelength2 * i_wavelength2);
      
      //unsigned
      u_wavelength2 = u_wavelength[i] * u_wavelength[i];
      u_true_energy[i] = (unsigned int)(PhysConst::H2_OVER_2MNEUT) / u_wavelength2;
      u_true_energy_err2[i] = (u_a2 * u_wavelength_err2[i]) / 
	(u_wavelength2 * u_wavelength2 * u_wavelength2);
    }
  
  //check first if the size are in good agreement
  if ((f_wavelength.size() != f_energy.size())||(d_wavelength.size() != d_energy.size()) || (i_wavelength.size() != i_energy.size()) || (u_wavelength.size() != u_energy.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      
      while(1)
	{
	  Utils::fd_comparison(f_energy, f_true_energy, error, 10, n);
	  if (error != 0) break;
	  Utils::fd_comparison(f_energy_err2, f_true_energy_err2, error, 20, n);
	  if (error != 0) break;
	  
	  Utils::fd_comparison(d_energy, d_true_energy, error, 110, n);
	  if (error != 0) break;
	  Utils::fd_comparison(d_energy_err2, d_true_energy_err2, error, 120, n);
	  if (error != 0) break;

	  Utils::iu_comparison(i_energy, i_true_energy, error, 210, n);
	  if (error != 0) break;
	  Utils::iu_comparison(i_energy_err2, i_true_energy_err2, error, 220, n);
	  if (error != 0) break;

	  Utils::iu_comparison(u_energy, u_true_energy, error, 310, n);
	  if (error != 0) break;
	  Utils::iu_comparison(u_energy_err2, u_true_energy_err2, error, 320, n);
	  break;
	}
    }

  cout << "wavelength_to_energy.cpp..........";

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
