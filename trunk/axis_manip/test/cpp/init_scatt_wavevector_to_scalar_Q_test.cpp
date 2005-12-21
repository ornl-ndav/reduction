#include "constants.hpp"
#include "conversions.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp" 
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

void f_function_init_scatt_wavevector_to_scalar_Q(Nessi::Vector<float> 
						  & f_initial_wavevector, 
						  Nessi::Vector<float> 
						  & f_initial_wavevector_err2,
						  int f_initial_wavevector_i,
						  Nessi::Vector<float> 
						  & f_final_wavevector, 
						  Nessi::Vector<float> 
						  & f_final_wavevector_err2,
						  int f_final_wavector_j,
						  float f_polar_angle,
						  float f_polar_angle_err2,
						  Nessi::Vector<float> & f_true_Q, 
						  Nessi::Vector<float> 
						  & f_true_Q_err2, 
						  int k);

void d_function_init_scatt_wavevector_to_scalar_Q(Nessi::Vector<double> 
						  & d_initial_wavevector, 
						  Nessi::Vector<double> 
						  & d_initial_wavevector_err2,
						  int d_initial_wavevector_i,
						  Nessi::Vector<double>
						  & d_final_wavevector, 
						  Nessi::Vector<double> 
						  & d_final_wavevector_err2,
						  int d_final_wavector_j,
						  double d_polar_angle,
						  double d_polar_angle_err2,
						  Nessi::Vector<double> & d_true_Q, 
						  Nessi::Vector<double> 
						  & d_true_Q_err2, 
						  int k);

int main() 
{
  int n = 20;

  //float
  Nessi::Vector<float> f_initial_wavevector;                
  Nessi::Vector<float> f_initial_wavevector_err2;           
  Nessi::Vector<float> f_final_wavevector;          
  Nessi::Vector<float> f_final_wavevector_err2;     
  Nessi::Vector<float> f_Q(n);
  Nessi::Vector<float> f_Q_err2(n);
  Nessi::Vector<float> f_true_Q(n);          
  Nessi::Vector<float> f_true_Q_err2(n);     
  float f_polar_angle;
  float f_polar_angle_err2;

  //double
  Nessi::Vector<double> d_initial_wavevector;                
  Nessi::Vector<double> d_initial_wavevector_err2;           
  Nessi::Vector<double> d_final_wavevector;          
  Nessi::Vector<double> d_final_wavevector_err2;     
  Nessi::Vector<double> d_Q(n);
  Nessi::Vector<double> d_Q_err2(n);
  Nessi::Vector<double> d_true_Q(n);          
  Nessi::Vector<double> d_true_Q_err2(n);     
  double d_polar_angle;
  double d_polar_angle_err2;  

  int error_case_1 = 0;   //size of initial_energy = 1 , size of final_energy > 1
  int error_case_2 = 0;   //size of initial_energy > 1 , size of final_energy = 1
  int error_case_3 = 0;   //size of initial_energy = 1 , size of final_energy = 1
  int error_case_4 = 0;   //size of initial_energy > 1 , size of final_energy > 1
  int error = 0;
  
  //initialization of parameters

  f_polar_angle = (float)34.45;
  d_polar_angle = (double)34.45;

  f_polar_angle_err2 = (float)34.45;
  d_polar_angle_err2 = (double)34.45;

  //case 1

      f_initial_wavevector.push_back((float)(2*3.5));
      f_initial_wavevector_err2.push_back((float)(4.4));

      d_initial_wavevector.push_back((double)(2*3.5));
      d_initial_wavevector_err2.push_back((double)(4.4));

  for(int i=0; i<n; i++)            
    {
      f_final_wavevector.push_back((float)(2*i+1));
      f_final_wavevector_err2.push_back((float)(2*i));
      
      d_final_wavevector.push_back((double)(2*i+1));
      d_final_wavevector_err2.push_back((double)(2*i));
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
					       f_initial_wavevector_err2,
					       f_final_wavevector, 
					       f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, 
					       f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
					       d_initial_wavevector_err2,
					       d_final_wavevector, 
					       d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, 
					       d_Q, d_Q_err2);
  
  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
						   f_initial_wavevector_err2,
						   0,f_final_wavevector, 
						   f_final_wavevector_err2,
						   i,f_polar_angle,
						   f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);
      
      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
						   d_initial_wavevector_err2,
						   0,d_final_wavevector, 
						   d_final_wavevector_err2,
						   i,d_polar_angle,
						   d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);
    }
  
  //compare results for case 1

  while (1)
  {
    Utils::fd_comparison(f_Q, f_true_Q, error_case_1, 10, n);
    if (error_case_1 != 0) break;
    Utils::fd_comparison(f_Q_err2, f_true_Q_err2, error_case_1, 20, n);
    if (error_case_1 != 0) break;
    Utils::fd_comparison(d_Q, d_true_Q, error_case_1, 110, n);
    if (error_case_1 != 0) break;
    Utils::fd_comparison(d_Q_err2, d_true_Q_err2, error_case_1, 120, n);
    break;
   }
  
  // ****case 2****

  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  f_final_wavevector.push_back(14.34);
  d_final_wavevector.push_back(14.34);

  f_final_wavevector_err2.push_back(4.34);
  d_final_wavevector_err2.push_back(4.34);
  
  for(int i=0; i<n; i++)            
    {
      f_initial_wavevector.push_back(i+1);
      f_initial_wavevector_err2.push_back(i);
      
      d_initial_wavevector.push_back(i+1);
      d_initial_wavevector_err2.push_back(i);
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
					       f_initial_wavevector_err2,
					       f_final_wavevector, 
					       f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2,
					       f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
					       d_initial_wavevector_err2,
					       d_final_wavevector, 
					       d_final_wavevector_err2,
					       d_polar_angle, 
					       d_polar_angle_err2, d_Q, d_Q_err2);
  
  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
						   f_initial_wavevector_err2,
						   i,f_final_wavevector, 
						   f_final_wavevector_err2,
						   0,f_polar_angle,
						   f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);
						   
      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
						   d_initial_wavevector_err2,
						   i,d_final_wavevector, 
						   d_final_wavevector_err2,
						   0,d_polar_angle,
						   d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);
    }  
  
  //compare results for case 2

  while (1)
    {
  Utils::fd_comparison(f_Q, f_true_Q, error_case_2, 10, n);
    if (error_case_2 != 0) break;
  Utils::fd_comparison(f_Q_err2, f_true_Q_err2, error_case_2, 20, n);
    if (error_case_2 != 0) break;
  Utils::fd_comparison(d_Q, d_true_Q, error_case_2, 110, n);
    if (error_case_2 != 0) break;
  Utils::fd_comparison(d_Q_err2, d_true_Q_err2, error_case_2, 120, n);
    if (error_case_2 != 0) break;
  break;   
    }  

  // ****case 3****
  
  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  f_final_wavevector.push_back((14.34));
  d_final_wavevector.push_back((14.34));

  f_final_wavevector_err2.push_back((4.34));
  d_final_wavevector_err2.push_back((4.34));
  
  f_initial_wavevector.push_back(11.44);
  f_initial_wavevector_err2.push_back(2.2);
  
  d_initial_wavevector.push_back(11.44);
  d_initial_wavevector_err2.push_back(2.2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
					       f_initial_wavevector_err2,
					       f_final_wavevector, 
					       f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, 
					       f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
					       d_initial_wavevector_err2,
					       d_final_wavevector, 
					       d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, 
					       d_Q, d_Q_err2);
  
  f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
					       f_initial_wavevector_err2,
					       0,f_final_wavevector, 
					       f_final_wavevector_err2,
					       0,f_polar_angle,f_polar_angle_err2,
					       f_true_Q, f_true_Q_err2, 0);
  
  d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
					       d_initial_wavevector_err2,
					       0,d_final_wavevector, 
					       d_final_wavevector_err2,
					       0,d_polar_angle,d_polar_angle_err2,
					       d_true_Q, d_true_Q_err2, 0);
  
  //compare results for case 3
  
  while (1)
    {
  Utils::fd_comparison(f_Q, f_true_Q, error_case_3, 10, 0);
    if (error_case_2 != 0) break;
  Utils::fd_comparison(f_Q_err2, f_true_Q_err2, error_case_3, 20, 0);
    if (error_case_2 != 0) break;
  Utils::fd_comparison(d_Q, d_true_Q, error_case_3, 110, 0);
    if (error_case_3 != 0) break;
  Utils::fd_comparison(d_Q_err2, d_true_Q_err2, error_case_3, 120, 0);
    if (error_case_3 != 0) break;
  break;   
    }  

  // ****case 4****
  
  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  for(int i=0; i<n; i++)            
    {
      f_initial_wavevector.push_back(i+1);
      f_initial_wavevector_err2.push_back(i);
      f_final_wavevector.push_back(2*i+3);
      f_final_wavevector_err2.push_back(i+2);
      
      d_initial_wavevector.push_back(i+1);
      d_initial_wavevector_err2.push_back(i);
      d_final_wavevector.push_back(2*i+3);
      d_final_wavevector_err2.push_back(i+2);
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
					       f_initial_wavevector_err2,
					       f_final_wavevector, 
					       f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, 
					       f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
					       d_initial_wavevector_err2,
					       d_final_wavevector, 
					       d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, 
					       d_Q, d_Q_err2);
  
  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, 
						   f_initial_wavevector_err2,
						   i,f_final_wavevector, 
						   f_final_wavevector_err2,
						   i,f_polar_angle,
						   f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);
						   

      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, 
						   d_initial_wavevector_err2,
						   i,d_final_wavevector, 
						   d_final_wavevector_err2,
						   i,d_polar_angle,
						   d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);
    }  
  
  //compare results for case 4
  
  while (1)
    {
      Utils::fd_comparison(f_Q, f_true_Q, error_case_4, 10, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(f_Q_err2, f_true_Q_err2, error_case_4, 20, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(d_Q, d_true_Q, error_case_4, 110, n);
      if (error_case_4 != 0) break;
      Utils::fd_comparison(d_Q_err2, d_true_Q_err2, error_case_4, 120, n);
      if (error_case_4 != 0) break;
      break;   
    }  
  
  error = error_case_1 + error_case_2 + error_case_3 + error_case_4;
  
  cout << "init_scatt_wavevector_to_scalar_Q.cpp..........";
  
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
      }	
    }
  return 0;
}


void f_function_init_scatt_wavevector_to_scalar_Q(Nessi::Vector<float> 
						  & f_initial_wavevector, 
						  Nessi::Vector<float> 
						  & f_initial_wavevector_err2,
						  int i,
						  Nessi::Vector<float> 
						  & f_final_wavevector, 
						  Nessi::Vector<float> 
						  & f_final_wavevector_err2,
						  int j,
						  float f_polar_angle,
						  float f_polar_angle_err2,
						  Nessi::Vector<float> & f_true_Q, 
						  Nessi::Vector<float> 
						  & f_true_Q_err2,
						  int k)
{
  float f_a;
  float f_pang, f_sang;
  float f_ki2, f_kf2, f_akikf;
  float f_termi, f_termi2;
  float f_termf, f_termf2;
  float f_front;
  float f_polar, f_polar2;

  f_ki2 = f_initial_wavevector[i] * f_initial_wavevector[i];

  f_a = static_cast<float>(2 * std::cos(static_cast<double>(f_polar_angle)));
  f_pang = static_cast<float>(std::cos(static_cast<double>(f_polar_angle)));
  f_sang = static_cast<float>(std::sin(static_cast<double>(f_polar_angle)));

  f_kf2 = f_final_wavevector[j] * f_final_wavevector[j];
  f_akikf = f_a * f_initial_wavevector[i] * f_final_wavevector[j];
  
  f_true_Q[k] = static_cast<float>(std::sqrt(static_cast<double>(f_ki2 + f_kf2 
								 - f_akikf)));
  
  f_termi = f_initial_wavevector[i] - (f_final_wavevector[j] * f_pang);
  f_termi2 = f_termi * f_termi;

  f_termf = f_initial_wavevector[i] * f_pang;
  f_termf = f_final_wavevector[j] - f_termf;
  f_termf2 = f_termf * f_termf;

  f_polar = f_final_wavevector[j] * f_initial_wavevector[i];
  f_polar = f_polar * f_sang;
  f_polar2 = f_polar * f_polar;

  f_front = 1 / (f_true_Q[k] * f_true_Q[k]);
  
  f_true_Q_err2[k] = f_final_wavevector_err2[j] * f_termf2;
  f_true_Q_err2[k] = f_true_Q_err2[k] + f_initial_wavevector_err2[i] * f_termi2;
  f_true_Q_err2[k] = f_true_Q_err2[k] + (f_polar_angle_err2 * f_polar2);
  f_true_Q_err2[k] = f_true_Q_err2[k] * f_front ;

  return;
}


void d_function_init_scatt_wavevector_to_scalar_Q(Nessi::Vector<double> 
						  & d_initial_wavevector, 
						  Nessi::Vector<double> 
						  & d_initial_wavevector_err2,
						  int i,
						  Nessi::Vector<double> 
						  & d_final_wavevector, 
						  Nessi::Vector<double> 
						  & d_final_wavevector_err2,
						  int j,
						  double d_polar_angle,
						  double d_polar_angle_err2,
						  Nessi::Vector<double> & d_true_Q, 
						  Nessi::Vector<double> 
						  & d_true_Q_err2,
						  int k)
{
  double d_a;
  double d_pang, d_sang;
  double d_ki2, d_kf2, d_akikf;
  double d_termi, d_termi2;
  double d_termf, d_termf2;
  double d_front;
  double d_polar, d_polar2;

  d_a = static_cast<double>(2 * std::cos(static_cast<double>(d_polar_angle)));
  d_pang = static_cast<double>(std::cos(static_cast<double>(d_polar_angle)));
  d_sang = static_cast<double>(std::sin(static_cast<double>(d_polar_angle)));

  d_ki2 = d_initial_wavevector[i] * d_initial_wavevector[i];

  d_kf2 = d_final_wavevector[j] * d_final_wavevector[j];
  d_akikf = d_a * d_initial_wavevector[i];
  d_akikf = d_akikf * d_final_wavevector[j];
  
  d_true_Q[k] = static_cast<double>(std::sqrt(static_cast<double>(d_ki2 + d_kf2 
								  - d_akikf)));
  
  d_termi = d_final_wavevector[j] * d_pang;
  d_termi = d_initial_wavevector[i] - d_termi;
  d_termi2 = d_termi * d_termi;

  d_termf = d_initial_wavevector[i] * d_pang;
  d_termf = d_final_wavevector[j] - d_termf;
  d_termf2 = d_termf * d_termf;

  d_polar = d_final_wavevector[j] * d_initial_wavevector[i] ;
  d_polar = d_polar *  d_sang;
  d_polar2 = d_polar * d_polar;

  d_front = 1 / (d_true_Q[k] * d_true_Q[k]);
  
  d_true_Q_err2[k] = d_initial_wavevector_err2[i] * d_termi2; 
  d_true_Q_err2[k] = d_true_Q_err2[k] + d_final_wavevector_err2[j] * d_termf2;
  d_true_Q_err2[k] = d_true_Q_err2[k] + d_polar_angle_err2 * d_polar2;
  d_true_Q_err2[k] = d_true_Q_err2[k] * d_front ;

  return;
}
