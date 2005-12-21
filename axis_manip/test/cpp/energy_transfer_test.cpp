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
  Nessi::Vector<float> f_initial_energy;                
  Nessi::Vector<float> f_initial_energy_err2;           
  Nessi::Vector<float> f_final_energy;          
  Nessi::Vector<float> f_final_energy_err2;     
  Nessi::Vector<float> f_energy_transfer(n);
  Nessi::Vector<float> f_energy_transfer_err2(n);
  Nessi::Vector<float> f_true_energy_transfer(n);          
  Nessi::Vector<float> f_true_energy_transfer_err2(n);     
  float f_h2;

  //double
  Nessi::Vector<double> d_initial_energy;                
  Nessi::Vector<double> d_initial_energy_err2;           
  Nessi::Vector<double> d_final_energy;          
  Nessi::Vector<double> d_final_energy_err2;     
  Nessi::Vector<double> d_energy_transfer(n);
  Nessi::Vector<double> d_energy_transfer_err2(n);
  Nessi::Vector<double> d_true_energy_transfer(n);          
  Nessi::Vector<double> d_true_energy_transfer_err2(n);     
  double d_h2;
  

  int error_case_1 = 0;   //size of initial_energy = 1 , size of final_energy > 1
  int error_case_2 = 0;   //size of initial_energy > 1 , size of final_energy = 1
  int error_case_3 = 0;   //size of initial_energy = 1 , size of final_energy = 1
  int error_case_4 = 0;   //size of initial_energy > 1 , size of final_energy > 1
  
  int error = 0;
  
  f_h2 = (float)(PhysConst::H * PhysConst::H);
  d_h2 = (double)(PhysConst::H * PhysConst::H);
  
  // ****case 1****
  
  f_initial_energy.push_back(static_cast<float>(26.3454));
  f_initial_energy_err2.push_back(static_cast<float>(24.34395));
  d_initial_energy.push_back(static_cast<double>(26.3454));
  d_initial_energy_err2.push_back(static_cast<double>(24.34395));

  for(int i=0; i<n; i++)            
    {
      f_final_energy.push_back((float)i+1);
      f_final_energy_err2.push_back((float)i+2);
      
      d_final_energy.push_back((double)i+1);
      d_final_energy_err2.push_back((double)i+2);
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
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
    }
  
  //compare results for case 1
  
  while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, 
			   error_case_1, 10, n);
      if (error_case_1 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_1, 20, n);
      if (error_case_1 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_1,
			   110, n);
      if (error_case_1 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_1, 120, n);
      if (error_case_1 != 0) break;

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
  

  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(2.445456));
  
  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(2.445456));
  
   for(int i=0; i<n; i++)            
    {
      f_initial_energy.push_back(3.*(float)i+2);
      f_initial_energy_err2.push_back((float)i+3);
      
      d_initial_energy.push_back(3.*(double)i+2);
      d_initial_energy_err2.push_back((double)i+3);
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
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
    }
  
  //compare results for case 2
    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_2, 
			   10, n);
      if (error_case_2 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_2, 20, n);
      if (error_case_2 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_2, 
			   110, n);
      if (error_case_2 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_2, 120, n);
      if (error_case_2 != 0) break;

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
  
  f_final_energy.push_back(static_cast<float>(1.34566));
  f_final_energy_err2.push_back(static_cast<float>(1.445456));
  f_initial_energy.push_back(static_cast<float>(43.34546));
  f_initial_energy_err2.push_back(static_cast<float>(5.00909));
  
  d_final_energy.push_back(static_cast<double>(1.34566));
  d_final_energy_err2.push_back(static_cast<double>(1.445456));
  d_initial_energy.push_back(static_cast<double>(43.34546));
  d_initial_energy_err2.push_back(static_cast<double>(5.00909));
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);
  
  f_true_energy_transfer[0] = (f_initial_energy[0] - f_final_energy[0]) /
	(float)(PhysConst::H);
  f_true_energy_transfer_err2[0] = (f_initial_energy_err2[0] + 
				    f_final_energy_err2[0]) / f_h2;
  
  d_true_energy_transfer[0] = (d_initial_energy[0] - d_final_energy[0]) /
	(double)(PhysConst::H);
  d_true_energy_transfer_err2[0] = (d_initial_energy_err2[0] + 
				    d_final_energy_err2[0]) / d_h2;

  //compare results for case 3
    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_3, 
			   10, n);
      if (error_case_3 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_3, 20, n);
      if (error_case_3 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_3, 
			   110, n);
      if (error_case_3 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_3, 120, n);
      if (error_case_3 != 0) break;

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
    }
  
  AxisManip::energy_transfer(f_initial_energy, f_initial_energy_err2,
			     f_final_energy, f_final_energy_err2,
			     f_energy_transfer, f_energy_transfer_err2);
  
  AxisManip::energy_transfer(d_initial_energy, d_initial_energy_err2,
			     d_final_energy, d_final_energy_err2,
			     d_energy_transfer, d_energy_transfer_err2);

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
    }

    while(1)
    {
      Utils::fd_comparison(f_energy_transfer, f_true_energy_transfer, error_case_4, 
			   10, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(f_energy_transfer_err2, f_true_energy_transfer_err2, 
			   error_case_4, 20, n);
      if (error_case_4 != 0) break;

      Utils::fd_comparison(d_energy_transfer, d_true_energy_transfer, error_case_4, 
			   110, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(d_energy_transfer_err2, d_true_energy_transfer_err2, 
			   error_case_4, 120, n);
      if (error_case_4 != 0) break;

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
		  cout << "(float) FAILED....Output vector different from vector"
		    " expected"<<endl;
		  break;
		case 20:
		  cout << "(float) FAILED....Output error vector different from "
		    "vector expected"<<endl;
		  break;
		case 110:
		  cout << "(double) FAILED....Output vector different from vector "
		    "expected"<<endl;
		  break;
		case 120:
		  cout << "(double) FAILED....Output error vector different from "
		    "vector expected"<<endl;
		  break;
		}
	  }
	else if (error_case_2 != 0)
	  {
	      cout << "(sz1 != 1 && sz2 == 1):"<<endl;
	      switch (error_case_2)
		{
		case 10:
		  cout << "(float) FAILED....Output vector different from vector "
		    "expected"<<endl;
		  break;
		case 20:
		  cout << "(float) FAILED....Output error vector different from "
		    "vector expected"<<endl;
		  break;
		case 110:
		  cout << "(double) FAILED....Output vector different from vector "
		    "expected"<<endl;
		  break;
		case 120:
		  cout << "(double) FAILED....Output error vector different from "
		    "vector expected"<<endl;
		  break;
		}
	  }
	else if (error_case_3 != 0)
	  {
	    cout << "(sz1 == 1 && sz2 == 1):"<<endl;
	    switch (error_case_3)
	      {
	      case 10:
		cout << "(float) FAILED....Output vector different from vector"
		  " expected"<<endl;
		break;
	      case 20:
		cout << "(float) FAILED....Output error vector different from "
		  "vector expected"<<endl;
		break;
	      case 110:
		cout << "(double) FAILED....Output vector different from vector"
		  " expected"<<endl;
		break;
	      case 120:
		cout << "(double) FAILED....Output error vector different from "
		  "vector expected"<<endl;
		break;
	      }
	  }
	else if (error_case_4 != 0)
	  {
	    cout << "(sz1 != 1 && sz2 != 1):"<<endl;
	    switch (error_case_4)
	      {
	      case 10:
		cout << "(float) FAILED....Output vector different from vector "
		  "expected"<<endl;
		break;
	      case 20:
		cout << "(float) FAILED....Output error vector different from "
		  "vector expected"<<endl;
		break;
	      case 110:
		cout << "(double) FAILED....Output vector different from vector"
		  " expected"<<endl;
		break;
	      case 120:
		cout << "(double) FAILED....Output error vector different from "
		  "vector expected"<<endl;
		break;
	      }
	  }
      }	
    }
  return 0;
}
