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
  vector<float> f_initial_energy;                
  vector<float> f_initial_energy_err2;           
  vector<float> f_final_energy;          
  vector<float> f_final_energy_err2;     
  vector<float> f_energy_transfer(n);
  vector<float> f_energy_transfer_err2(n);
  vector<float> f_true_energy_transfer(n);          
  vector<float> f_true_energy_transfer_err2(n);     
  float f_h2;

  //double
  vector<double> d_initial_energy;                
  vector<double> d_initial_energy_err2;           
  vector<double> d_final_energy;          
  vector<double> d_final_energy_err2;     
  vector<double> d_energy_transfer(n);
  vector<double> d_energy_transfer_err2(n);
  vector<double> d_true_energy_transfer(n);          
  vector<double> d_true_energy_transfer_err2(n);     
  double d_h2;
  
  //int
  vector<int> i_initial_energy;                
  vector<int> i_initial_energy_err2;           
  vector<int> i_final_energy;          
  vector<int> i_final_energy_err2;     
  vector<int> i_energy_transfer(n);
  vector<int> i_energy_transfer_err2(n);
  vector<int> i_true_energy_transfer(n);          
  vector<int> i_true_energy_transfer_err2(n);     
  int i_h2;

  //unsigned
  vector<unsigned int> u_initial_energy;                
  vector<unsigned int> u_initial_energy_err2;           
  vector<unsigned int> u_final_energy;          
  vector<unsigned int> u_final_energy_err2;     
  vector<unsigned int> u_energy_transfer(n);
  vector<unsigned int> u_energy_transfer_err2(n);
  vector<unsigned int> u_true_energy_transfer(n);          
  vector<unsigned int> u_true_energy_transfer_err2(n);     
  unsigned int u_h2;

  int error_case_1 = 0;   //size of initial_energy = 1 , size of final_energy > 1
  int error_case_2 = 0;   //size of initial_energy > 1 , size of final_energy = 1
  int error_case_3 = 0;   //size of initial_energy = 1 , size of final_energy = 1
  int error_case_4 = 0;   //size of initial_energy > 1 , size of final_energy > 1
  
  int error = 0;
  
  f_h2 = (float)(PhysConst::H * PhysConst::H);
  d_h2 = (double)(PhysConst::H * PhysConst::H);
  i_h2 = (int)(PhysConst::H) * (int)(PhysConst::H);
  u_h2 = (unsigned int)(PhysConst::H) * (unsigned int)(PhysConst::H);
  
  // ****case 1****
  
  f_initial_energy.push_back(static_cast<float>(26.3454));
  f_initial_energy_err2.push_back(static_cast<float>(24.34395));
  d_initial_energy.push_back(static_cast<double>(26.3454));
  d_initial_energy_err2.push_back(static_cast<double>(24.34395));
  i_initial_energy.push_back(static_cast<int>(26.3454));
  i_initial_energy_err2.push_back(static_cast<int>(24.34395));
  u_initial_energy.push_back(static_cast<unsigned int>(26.3454));
  u_initial_energy_err2.push_back(static_cast<unsigned int>(24.34395));

  for(int i=0; i<n; i++)            
    {
      f_final_energy.push_back((float)i+1);
      f_final_energy_err2.push_back((float)i+2);
      
      d_final_energy.push_back((double)i+1);
      d_final_energy_err2.push_back((double)i+2);
      
      i_final_energy.push_back((int)i+1);
      i_final_energy_err2.push_back((int)i+2);
      
      u_final_energy.push_back((unsigned int)i+1);
      u_final_energy_err2.push_back((unsigned int)i+2);
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
  AxisManip::energy_transfer(i_initial_energy, i_initial_energy_err2,
			     i_final_energy, i_final_energy_err2,
			     i_energy_transfer, i_energy_transfer_err2);
  
  AxisManip::energy_transfer(u_initial_energy, u_initial_energy_err2,
			     u_final_energy, u_final_energy_err2,
			     u_energy_transfer, u_energy_transfer_err2);
  
  for(int i=0; i<n; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[0] - f_final_energy[i]) /
	(float)(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[0] + 
					f_final_energy_err2[i]) / f_h2;
      
      d_true_energy_transfer[i] = (d_initial_energy[0] - d_final_energy[i]) /
	(double)(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[0] + 
					d_final_energy_err2[i]) / d_h2;
      
      i_true_energy_transfer[i] = (i_initial_energy[0] - i_final_energy[i]) /
	(int)(PhysConst::H);
      i_true_energy_transfer_err2[i] = (i_initial_energy_err2[0] +
					i_final_energy_err2[i]) / i_h2;
      
      u_true_energy_transfer[i] = (u_initial_energy[0] - u_final_energy[i]) /    
	(unsigned int)(PhysConst::H);
      u_true_energy_transfer_err2[i] = (u_initial_energy_err2[0] + 
					u_final_energy_err2[i]) / u_h2;
    }
  
  //compare results for case 1
  
  while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_1, 10, n);
      if (error_case_1 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_1, 20, n);
      if (error_case_1 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_1, 110, n);
      if (error_case_1 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_1, 120, n);
      if (error_case_1 != 0) break;

      Utils::iu_comparison(i_energy_transfer, i_true_energy_transfer, error_case_1, 210, n);
      if (error_case_1 != 0) break;
      Utils::iu_comparison(i_energy_transfer_err2, i_true_energy_transfer_err2, 
			   error_case_1, 220, n);
      if (error_case_1 != 0) break;

      Utils::iu_comparison(u_energy_transfer, u_true_energy_transfer, error_case_1, 310, n);
      if (error_case_1 != 0) break;
      Utils::iu_comparison(u_energy_transfer_err2, u_true_energy_transfer_err2, 
			   error_case_1, 320, n);
      break;
    }
 
  // ****case 2****
  
  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();
  
  
  i_final_energy.clear();
  i_final_energy_err2.clear();
  i_initial_energy_err2.clear();
  i_initial_energy.clear();
  
  u_final_energy.clear();
  u_final_energy_err2.clear();
  u_initial_energy_err2.clear();
  u_initial_energy.clear();
  

  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(2.445456));
  
  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(2.445456));
  
  i_final_energy.push_back(static_cast<int>(1.34566));
  i_final_energy_err2.push_back(static_cast<int>(2.445456));
  
  u_final_energy.push_back(static_cast<unsigned int>(1.34566));
  u_final_energy_err2.push_back(static_cast<unsigned int>(2.445456));
  
   for(int i=0; i<n; i++)            
    {
      f_initial_energy.push_back(3.*(float)i+2);
      f_initial_energy_err2.push_back((float)i+3);
      
      d_initial_energy.push_back(3.*(double)i+2);
      d_initial_energy_err2.push_back((double)i+3);
      
      i_initial_energy.push_back(3*(int)i+2);
      i_initial_energy_err2.push_back((int)i+3);
      
      u_initial_energy.push_back(3*(unsigned int)i+2);
      u_initial_energy_err2.push_back((unsigned int)i+3);
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
  AxisManip::energy_transfer(i_initial_energy, i_initial_energy_err2,
			     i_final_energy, i_final_energy_err2,
			     i_energy_transfer, i_energy_transfer_err2);
  
  AxisManip::energy_transfer(u_initial_energy, u_initial_energy_err2,
			     u_final_energy, u_final_energy_err2,
			     u_energy_transfer, u_energy_transfer_err2);
  
  for(int i=0; i<n; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[i] - f_final_energy[0]) /
	(float)(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[i] + 
					f_final_energy_err2[0]) / f_h2;
      
      d_true_energy_transfer[i] = (d_initial_energy[i] - d_final_energy[0]) /
	(double)(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[i] +
					d_final_energy_err2[0]) / d_h2;
      
      i_true_energy_transfer[i] = (i_initial_energy[i] - i_final_energy[0]) /
	(int)(PhysConst::H);
      i_true_energy_transfer_err2[i] = (i_initial_energy_err2[i] + 
					i_final_energy_err2[0]) / i_h2;
      
      u_true_energy_transfer[i] = (u_initial_energy[i] - u_final_energy[0]) /
	(unsigned int)(PhysConst::H);
      u_true_energy_transfer_err2[i] = (u_initial_energy_err2[i] + 
					u_final_energy_err2[0]) / u_h2;

    }
  
  //compare results for case 2
    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_2, 10, n);
      if (error_case_2 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_2, 20, n);
      if (error_case_2 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_2, 110, n);
      if (error_case_2 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_2, 120, n);
      if (error_case_2 != 0) break;

      Utils::iu_comparison(i_energy_transfer, i_true_energy_transfer, error_case_2, 210, n);
      if (error_case_2 != 0) break;
      Utils::iu_comparison(i_energy_transfer_err2, i_true_energy_transfer_err2, 
			   error_case_2, 220, n);
      if (error_case_2 != 0) break;

      Utils::iu_comparison(u_energy_transfer, u_true_energy_transfer, error_case_2, 310, n);
      if (error_case_2 != 0) break;
      Utils::iu_comparison(u_energy_transfer_err2, u_true_energy_transfer_err2, 
			   error_case_2, 320, n);
      break;
    }


  // ****case 3****
  
  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();
  
  
  i_final_energy.clear();
  i_final_energy_err2.clear();
  i_initial_energy_err2.clear();
  i_initial_energy.clear();
  
  u_final_energy.clear();
  u_final_energy_err2.clear();
  u_initial_energy_err2.clear();
  u_initial_energy.clear();

  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(1.445456));
  f_initial_energy.push_back(static_cast<float>(43.34546));
  f_initial_energy_err2.push_back(static_cast<float>(5.00909));
  
  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(1.445456));
  d_initial_energy.push_back(static_cast<double>(43.34546));
  d_initial_energy_err2.push_back(static_cast<double>(5.00909));
  
  i_final_energy.push_back(static_cast<int>(1.34566));
  i_final_energy_err2.push_back(static_cast<int>(1.445456));
  i_initial_energy.push_back(static_cast<int>(43.34546));
  i_initial_energy_err2.push_back(static_cast<int>(5.00909));
  
  u_final_energy.push_back(static_cast<unsigned int>(1.34566));
  u_final_energy_err2.push_back(static_cast<unsigned int>(1.445456));
  u_initial_energy.push_back(static_cast<unsigned int>(43.34546));
  u_initial_energy_err2.push_back(static_cast<unsigned int>(5.00909));
  
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
  AxisManip::energy_transfer(i_initial_energy, i_initial_energy_err2,
			     i_final_energy, i_final_energy_err2,
			     i_energy_transfer, i_energy_transfer_err2);
  
  AxisManip::energy_transfer(u_initial_energy, u_initial_energy_err2,
			     u_final_energy, u_final_energy_err2,
			     u_energy_transfer, u_energy_transfer_err2);
  
  
  f_true_energy_transfer[0] = (f_initial_energy[0] - f_final_energy[0]) /
	(float)(PhysConst::H);
  f_true_energy_transfer_err2[0] = (f_initial_energy_err2[0] + 
				    f_final_energy_err2[0]) / f_h2;
  
  d_true_energy_transfer[0] = (d_initial_energy[0] - d_final_energy[0]) /
	(double)(PhysConst::H);
  d_true_energy_transfer_err2[0] = (d_initial_energy_err2[0] + 
				    d_final_energy_err2[0]) / d_h2;

  i_true_energy_transfer[0] = (i_initial_energy[0] - i_final_energy[0]) /
	(int)(PhysConst::H);
  i_true_energy_transfer_err2[0] = (i_initial_energy_err2[0] + 
				    i_final_energy_err2[0]) / i_h2;

  u_true_energy_transfer[0] = (u_initial_energy[0] - u_final_energy[0]) /
	(unsigned int)(PhysConst::H);
  u_true_energy_transfer_err2[0] = (u_initial_energy_err2[0] + 
				    u_final_energy_err2[0]) / u_h2;
  
  //compare results for case 3
    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_3, 10, n);
      if (error_case_3 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_3, 20, n);
      if (error_case_3 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_3, 110, n);
      if (error_case_3 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_3, 120, n);
      if (error_case_3 != 0) break;

      Utils::iu_comparison(i_energy_transfer, i_true_energy_transfer, error_case_3, 210, n);
      if (error_case_3 != 0) break;
      Utils::iu_comparison(i_energy_transfer_err2, i_true_energy_transfer_err2, 
			   error_case_3, 220, n);
      if (error_case_3 != 0) break;

      Utils::iu_comparison(u_energy_transfer, u_true_energy_transfer, error_case_3, 310, n);
      if (error_case_3 != 0) break;
      Utils::iu_comparison(u_energy_transfer_err2, u_true_energy_transfer_err2, 
			   error_case_3, 320, n);
      break;
    }


  // ****case 4****
  
  f_final_energy.clear();
  f_final_energy_err2.clear();
  f_initial_energy_err2.clear();
  f_initial_energy.clear();

  d_final_energy.clear();
  d_final_energy_err2.clear();
  d_initial_energy_err2.clear();
  d_initial_energy.clear();
  
  
  i_final_energy.clear();
  i_final_energy_err2.clear();
  i_initial_energy_err2.clear();
  i_initial_energy.clear();
  
  u_final_energy.clear();
  u_final_energy_err2.clear();
  u_initial_energy_err2.clear();
  u_initial_energy.clear();

  for(int i=0; i<n; i++)            
    {
      f_initial_energy.push_back(3.*(float)i+3);
      f_initial_energy_err2.push_back((float)i+5);
      f_final_energy.push_back(3.*(float)i+2);
      f_final_energy.push_back((float)i+2);

      d_initial_energy.push_back(3.*(double)i+3);
      d_initial_energy_err2.push_back((double)i+5);
      d_final_energy.push_back(3.*(double)i+2);
      d_final_energy.push_back((double)i+2);

      i_initial_energy.push_back(3*(int)i+3);
      i_initial_energy_err2.push_back((int)i+5);
      i_final_energy.push_back(3*(int)i+2);
      i_final_energy.push_back((int)i+2);

      u_initial_energy.push_back(3*(unsigned int)i+3);
      u_initial_energy_err2.push_back((unsigned int)i+5);
      u_final_energy.push_back(3*(unsigned int)i+2);
      u_final_energy.push_back((unsigned int)i+2);
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
  AxisManip::energy_transfer(i_initial_energy, i_initial_energy_err2,
			     i_final_energy, i_final_energy_err2,
			     i_energy_transfer, i_energy_transfer_err2);
  
  AxisManip::energy_transfer(u_initial_energy, u_initial_energy_err2,
			     u_final_energy, u_final_energy_err2,
			     u_energy_transfer, u_energy_transfer_err2);

  for(int i=0; i<n; i++)
    {
      f_true_energy_transfer[i] = (f_initial_energy[i] - f_final_energy[i]) /
	(float)(PhysConst::H);
      f_true_energy_transfer_err2[i] = (f_initial_energy_err2[i] + 
					f_final_energy_err2[i]) / f_h2;

      d_true_energy_transfer[i] = (d_initial_energy[i] - d_final_energy[i]) /
	(double)(PhysConst::H);
      d_true_energy_transfer_err2[i] = (d_initial_energy_err2[i] + 
					d_final_energy_err2[i]) / d_h2;

      i_true_energy_transfer[i] = (i_initial_energy[i] - i_final_energy[i]) /
	(int)(PhysConst::H);
      i_true_energy_transfer_err2[i] = (i_initial_energy_err2[i] + 
					i_final_energy_err2[i]) / i_h2;

      u_true_energy_transfer[i] = (u_initial_energy[i] - u_final_energy[i]) /
	(unsigned int)(PhysConst::H);
      u_true_energy_transfer_err2[i] = (u_initial_energy_err2[i] + 
					u_final_energy_err2[i]) / u_h2;
    }

    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_4, 10, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_4, 20, n);
      if (error_case_4 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_4, 110, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_4, 120, n);
      if (error_case_4 != 0) break;

      Utils::iu_comparison(i_energy_transfer, i_true_energy_transfer, error_case_4, 210, n);
      if (error_case_4 != 0) break;
      Utils::iu_comparison(i_energy_transfer_err2, i_true_energy_transfer_err2, 
			   error_case_4, 220, n);
      if (error_case_4 != 0) break;

      Utils::iu_comparison(u_energy_transfer, u_true_energy_transfer, error_case_4, 310, n);
      if (error_case_4 != 0) break;
      Utils::iu_comparison(u_energy_transfer_err2, u_true_energy_transfer_err2, 
			   error_case_4, 320, n);
      break;
    }

  error = error_case_1 + error_case_2 + error_case_3 + error_case_4;
  
  cout << "energy_transfer.cpp..........";
  
  switch (error)
    {
    case 0:
      cout << "Functionality OK"<<endl;
      break;
    default:
      {
	if (error_case_1 != 0)
	  {
	      cout << "(sz1 == 1 && sz2 != 1):"<<endl;
	      switch (error_case_1)
		{
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
		}
	  }
	else if (error_case_2 != 0)
	  {
	      cout << "(sz1 != 1 && sz2 == 1):"<<endl;
	      switch (error_case_2)
		{
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
		}
	  }
	else if (error_case_3 != 0)
	  {
	    cout << "(sz1 == 1 && sz2 == 1):"<<endl;
	    switch (error_case_3)
	      {
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
	      }
	  }
	else if (error_case_4 != 0)
	  {
	    cout << "(sz1 != 1 && sz2 != 1):"<<endl;
	    switch (error_case_4)
	      {
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
	      }
	  }
      }	
    }
  return 0;
}
