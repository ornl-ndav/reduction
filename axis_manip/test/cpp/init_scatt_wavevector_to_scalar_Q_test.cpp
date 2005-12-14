#include "constants.hpp"
#include "conversions.hpp"
#include "num_comparison.hpp" 
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void f_function_init_scatt_wavevector_to_scalar_Q(vector<float> & f_initial_wavevector, 
						  vector<float> & f_initial_wavevector_err2,
						  int f_initial_wavevector_i,
						  vector<float> & f_final_wavevector, 
						  vector<float> & f_final_wavevector_err2,
						  int f_final_wavector_j,
						  float f_polar_angle,
						  float f_polar_angle_err2,
						  vector<float> & f_true_Q, 
						  vector<float> & f_true_Q_err2, 
						  int k);

void d_function_init_scatt_wavevector_to_scalar_Q(vector<double> & d_initial_wavevector, 
						  vector<double> & d_initial_wavevector_err2,
						  int d_initial_wavevector_i,
						  vector<double> & d_final_wavevector, 
						  vector<double> & d_final_wavevector_err2,
						  int d_final_wavector_j,
						  double d_polar_angle,
						  double d_polar_angle_err2,
						  vector<double> & d_true_Q, 
						  vector<double> & d_true_Q_err2, 
						  int k);

void i_function_init_scatt_wavevector_to_scalar_Q(vector<int> & i_initial_wavevector, 
						  vector<int> & i_initial_wavevector_err2,
						  int i_initial_wavevector_i,
						  vector<int> & i_final_wavevector, 
						  vector<int> & i_final_wavevector_err2,
						  int i_final_wavector_j,
						  int i_polar_angle,
						  int i_polar_angle_err2,
						  vector<int> & i_true_Q, 
						  vector<int> & i_true_Q_err2, 
						  int k);

void u_function_init_scatt_wavevector_to_scalar_Q(vector<unsigned int> & u_initial_wavevector, 
						  vector<unsigned int> & u_initial_wavevector_err2,
						  int u_initial_wavevector_i,
						  vector<unsigned int> & u_final_wavevector, 
						  vector<unsigned int> & u_final_wavevector_err2,
						  int u_final_wavector_j,
						  unsigned int u_polar_angle,
						  unsigned int u_polar_angle_err2,
						  vector<unsigned int> & u_true_Q, 
						  vector<unsigned int> & u_true_Q_err2, 
						  int k);

int main() 
{
  int n = 20;

  //float
  vector<float> f_initial_wavevector;                
  vector<float> f_initial_wavevector_err2;           
  vector<float> f_final_wavevector;          
  vector<float> f_final_wavevector_err2;     
  vector<float> f_Q(n);
  vector<float> f_Q_err2(n);
  vector<float> f_true_Q(n);          
  vector<float> f_true_Q_err2(n);     
  float f_polar_angle;
  float f_polar_angle_err2;

  //double
  vector<double> d_initial_wavevector;                
  vector<double> d_initial_wavevector_err2;           
  vector<double> d_final_wavevector;          
  vector<double> d_final_wavevector_err2;     
  vector<double> d_Q(n);
  vector<double> d_Q_err2(n);
  vector<double> d_true_Q(n);          
  vector<double> d_true_Q_err2(n);     
  double d_polar_angle;
  double d_polar_angle_err2;  
  //int
  vector<int> i_initial_wavevector;                
  vector<int> i_initial_wavevector_err2;           
  vector<int> i_final_wavevector;          
  vector<int> i_final_wavevector_err2;     
  vector<int> i_Q(n);
  vector<int> i_Q_err2(n);
  vector<int> i_true_Q(n);          
  vector<int> i_true_Q_err2(n);     
  int i_polar_angle;
  int i_polar_angle_err2;

  //unsigned
  vector<unsigned int> u_initial_wavevector;                
  vector<unsigned int> u_initial_wavevector_err2;           
  vector<unsigned int> u_final_wavevector;          
  vector<unsigned int> u_final_wavevector_err2;     
  vector<unsigned int> u_Q(n);
  vector<unsigned int> u_Q_err2(n);
  vector<unsigned int> u_true_Q(n);          
  vector<unsigned int> u_true_Q_err2(n);     
  unsigned int u_polar_angle;
  unsigned int u_polar_angle_err2;

  int error_case_1 = 0;   //size of initial_energy = 1 , size of final_energy > 1
  int error_case_2 = 0;   //size of initial_energy > 1 , size of final_energy = 1
  int error_case_3 = 0;   //size of initial_energy = 1 , size of final_energy = 1
  int error_case_4 = 0;   //size of initial_energy > 1 , size of final_energy > 1
  int error = 0;
  
  //initialization of parameters

  f_polar_angle = static_cast<float>(34.45);
  d_polar_angle = static_cast<double>(34.45);
  i_polar_angle = static_cast<int>(34.45);
  u_polar_angle = static_cast<unsigned int>(34.45);

  f_polar_angle_err2 = static_cast<float>(34.45);
  d_polar_angle_err2 = static_cast<double>(34.45);
  i_polar_angle_err2 = static_cast<int>(34.45);
  u_polar_angle_err2 = static_cast<unsigned int>(34.45);

  //case 1

      f_initial_wavevector.push_back(2*(float)3.5);
      f_initial_wavevector_err2.push_back((float)4.4);

      d_initial_wavevector.push_back(2*(double)3.5);
      d_initial_wavevector_err2.push_back((double)4.4);

      i_initial_wavevector.push_back(2*(int)3.5);
      i_initial_wavevector_err2.push_back((int)4.4);

      u_initial_wavevector.push_back(2*(unsigned int)3.5);
      u_initial_wavevector_err2.push_back((unsigned int)4.4);

  for(int i=0; i<n; i++)            
    {
      f_final_wavevector.push_back(2*(float)i+1);
      f_final_wavevector_err2.push_back(2*(float)i);
      
      d_final_wavevector.push_back(2*(double)i+1);
      d_final_wavevector_err2.push_back(2*(double)i);

      i_final_wavevector.push_back(2*(int)i+1);
      i_final_wavevector_err2.push_back(2*(int)i);

      u_final_wavevector.push_back(2*(unsigned int)i+1);
      u_final_wavevector_err2.push_back(2*(unsigned int)i);
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
					       f_final_wavevector, f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, f_Q, f_Q_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
					       d_final_wavevector, d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, d_Q, d_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
					       i_final_wavevector, i_final_wavevector_err2,
					       i_polar_angle, i_polar_angle_err2, i_Q, i_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
					       u_final_wavevector, u_final_wavevector_err2,
					       u_polar_angle, u_polar_angle_err2, u_Q, u_Q_err2);

  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
						   0,f_final_wavevector, f_final_wavevector_err2,
						   i,f_polar_angle,f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);

      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
						   0,d_final_wavevector, d_final_wavevector_err2,
						   i,d_polar_angle,d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);

      i_function_init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
						   0,i_final_wavevector, i_final_wavevector_err2,
						   i,i_polar_angle,i_polar_angle_err2,
						   i_true_Q, i_true_Q_err2, i);

      u_function_init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
						   0,u_final_wavevector, u_final_wavevector_err2,
						   i,u_polar_angle,u_polar_angle_err2,
						   u_true_Q, u_true_Q_err2, i);
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
    if (error_case_1 != 0) break;
    Utils::iu_comparison(i_Q, i_true_Q, error_case_1, 210, n);
    if (error_case_1 != 0) break;
    Utils::iu_comparison(i_Q_err2, i_true_Q_err2, error_case_1, 220, n);
    if (error_case_1 != 0) break;
    Utils::iu_comparison(u_Q, u_true_Q, error_case_1, 310, n);
    if (error_case_1 != 0) break;
    Utils::iu_comparison(u_Q_err2, u_true_Q_err2, error_case_1, 320, n);
    break;
   }
  
  // ****case 2****

  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();
  i_final_wavevector.clear();
  i_final_wavevector_err2.clear();
  u_final_wavevector.clear();
  u_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();
  i_initial_wavevector.clear();
  i_initial_wavevector_err2.clear();
  u_initial_wavevector.clear();
  u_initial_wavevector_err2.clear();

  f_final_wavevector.push_back(static_cast<float>(14.34));
  d_final_wavevector.push_back(static_cast<double>(14.34));
  i_final_wavevector.push_back(static_cast<int>(14.34));
  u_final_wavevector.push_back(static_cast<unsigned int>(14.34));

  f_final_wavevector_err2.push_back(static_cast<float>(4.34));
  d_final_wavevector_err2.push_back(static_cast<double>(4.34));
  i_final_wavevector_err2.push_back(static_cast<int>(4.34));
  u_final_wavevector_err2.push_back(static_cast<unsigned int>(4.34));
  
  for(int i=0; i<n; i++)            
    {
      f_initial_wavevector.push_back((float)i+1);
      f_initial_wavevector_err2.push_back((float)i);
      
      d_initial_wavevector.push_back((double)i+1);
      d_initial_wavevector_err2.push_back((double)i);

      i_initial_wavevector.push_back((int)i+1);
      i_initial_wavevector_err2.push_back((int)i);

      u_initial_wavevector.push_back((unsigned int)i+1);
      u_initial_wavevector_err2.push_back((unsigned int)i);
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
					       f_final_wavevector, f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2,f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
					       d_final_wavevector, d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, d_Q, d_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
					       i_final_wavevector, i_final_wavevector_err2,
					       i_polar_angle, i_polar_angle_err2, i_Q, i_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
					       u_final_wavevector, u_final_wavevector_err2,
					       u_polar_angle, u_polar_angle_err2, u_Q, u_Q_err2);

  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
						   i,f_final_wavevector, f_final_wavevector_err2,
						   0,f_polar_angle,f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);
						   
      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
						   i,d_final_wavevector, d_final_wavevector_err2,
						   0,d_polar_angle,d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);

      i_function_init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
						   i,i_final_wavevector, i_final_wavevector_err2,
						   0,i_polar_angle,i_polar_angle_err2,
						   i_true_Q, i_true_Q_err2, i);

      u_function_init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
						   i,u_final_wavevector, u_final_wavevector_err2,
						   0,u_polar_angle,u_polar_angle_err2, 
						   u_true_Q, u_true_Q_err2, i);
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
  Utils::iu_comparison(i_Q, i_true_Q, error_case_2, 210, n);
    if (error_case_2 != 0) break;
  Utils::iu_comparison(i_Q_err2, i_true_Q_err2, error_case_2, 220, n);
    if (error_case_2 != 0) break;
  Utils::iu_comparison(u_Q, u_true_Q, error_case_2, 310, n);
    if (error_case_2 != 0) break;
  Utils::iu_comparison(u_Q_err2, u_true_Q_err2, error_case_2, 320, n);
  break;   
    }  

  // ****case 3****
  
  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();
  i_final_wavevector.clear();
  i_final_wavevector_err2.clear();
  u_final_wavevector.clear();
  u_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();
  i_initial_wavevector.clear();
  i_initial_wavevector_err2.clear();
  u_initial_wavevector.clear();
  u_initial_wavevector_err2.clear();

  f_final_wavevector.push_back((float)(14.34));
  d_final_wavevector.push_back((double)(14.34));
  i_final_wavevector.push_back((int)(14.34));
  u_final_wavevector.push_back((unsigned int)(14.34));

  f_final_wavevector_err2.push_back((float)(4.34));
  d_final_wavevector_err2.push_back((double)(4.34));
  i_final_wavevector_err2.push_back((int)(4.34));
  u_final_wavevector_err2.push_back((unsigned int)(4.34));
  
  f_initial_wavevector.push_back((float)11.44);
  f_initial_wavevector_err2.push_back((float)2.2);
  
  d_initial_wavevector.push_back((double)11.44);
  d_initial_wavevector_err2.push_back((double)2.2);
  
  i_initial_wavevector.push_back((int)11.44);
  i_initial_wavevector_err2.push_back((int)2.2);
  
  u_initial_wavevector.push_back((unsigned int)11.44);
  u_initial_wavevector_err2.push_back((unsigned int)2.2);

  
  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
					       f_final_wavevector, f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
					       d_final_wavevector, d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, d_Q, d_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
					       i_final_wavevector, i_final_wavevector_err2,
					       i_polar_angle, i_polar_angle_err2, i_Q, i_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
					       u_final_wavevector, u_final_wavevector_err2,
					       u_polar_angle, u_polar_angle_err2, u_Q, u_Q_err2);
  

  f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
					       0,f_final_wavevector, f_final_wavevector_err2,
					       0,f_polar_angle,f_polar_angle_err2,
					       f_true_Q, f_true_Q_err2, 0);
  
  d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
					       0,d_final_wavevector, d_final_wavevector_err2,
					       0,d_polar_angle,d_polar_angle_err2,
					       d_true_Q, d_true_Q_err2, 0);
  
  i_function_init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
					       0,i_final_wavevector, i_final_wavevector_err2,
					       0,i_polar_angle,i_polar_angle_err2,
					       i_true_Q, i_true_Q_err2, 0);
  
  u_function_init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
					       0,u_final_wavevector, u_final_wavevector_err2,
					       0,u_polar_angle,u_polar_angle_err2,
					       u_true_Q, u_true_Q_err2, 0);
  
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
  Utils::iu_comparison(i_Q, i_true_Q, error_case_3, 210, 0);
    if (error_case_3 != 0) break;
  Utils::iu_comparison(i_Q_err2, i_true_Q_err2, error_case_3, 220, 0);
    if (error_case_3 != 0) break;
  Utils::iu_comparison(u_Q, u_true_Q, error_case_3, 310, 0);
    if (error_case_3 != 0) break;
  Utils::iu_comparison(u_Q_err2, u_true_Q_err2, error_case_3, 320, 0);
  break;   
    }  

  // ****case 4****
  
  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();
  i_final_wavevector.clear();
  i_final_wavevector_err2.clear();
  u_final_wavevector.clear();
  u_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();
  i_initial_wavevector.clear();
  i_initial_wavevector_err2.clear();
  u_initial_wavevector.clear();
  u_initial_wavevector_err2.clear();

  for(int i=0; i<n; i++)            
    {
      f_initial_wavevector.push_back((float)i+1);
      f_initial_wavevector_err2.push_back((float)i);
      f_final_wavevector.push_back(2*(float)i+3);
      f_final_wavevector_err2.push_back((float)i+2);
      
      d_initial_wavevector.push_back((double)i+1);
      d_initial_wavevector_err2.push_back((double)i);
      d_final_wavevector.push_back(2*(double)i+3);
      d_final_wavevector_err2.push_back((double)i+2);

      i_initial_wavevector.push_back((int)i+1);
      i_initial_wavevector_err2.push_back((int)i);
      i_final_wavevector.push_back(2*(int)i+3);
      i_final_wavevector_err2.push_back((int)i+2);

      u_initial_wavevector.push_back((unsigned int)i+1);
      u_initial_wavevector_err2.push_back((unsigned int)i);
      u_final_wavevector.push_back(2*(unsigned int)i+3);
      u_final_wavevector_err2.push_back((unsigned int)i+2);
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
					       f_final_wavevector, f_final_wavevector_err2,
					       f_polar_angle, f_polar_angle_err2, f_Q, f_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
					       d_final_wavevector, d_final_wavevector_err2,
					       d_polar_angle, d_polar_angle_err2, d_Q, d_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
					       i_final_wavevector, i_final_wavevector_err2,
					       i_polar_angle, i_polar_angle_err2, i_Q, i_Q_err2);
  
  AxisManip::init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
					       u_final_wavevector, u_final_wavevector_err2,
					       u_polar_angle, u_polar_angle_err2, u_Q, u_Q_err2);
  
  for(int i=0; i<n; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector, f_initial_wavevector_err2,
						   i,f_final_wavevector, f_final_wavevector_err2,
						   i,f_polar_angle,f_polar_angle_err2,
						   f_true_Q, f_true_Q_err2, i);
						   

      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector, d_initial_wavevector_err2,
						   i,d_final_wavevector, d_final_wavevector_err2,
						   i,d_polar_angle,d_polar_angle_err2,
						   d_true_Q, d_true_Q_err2, i);

      i_function_init_scatt_wavevector_to_scalar_Q(i_initial_wavevector, i_initial_wavevector_err2,
						   i,i_final_wavevector, i_final_wavevector_err2,
						   i,i_polar_angle,i_polar_angle_err2,
						   i_true_Q, i_true_Q_err2, i);

      u_function_init_scatt_wavevector_to_scalar_Q(u_initial_wavevector, u_initial_wavevector_err2,
						   i,u_final_wavevector, u_final_wavevector_err2,
						   i,u_polar_angle,u_polar_angle_err2,
						   u_true_Q, u_true_Q_err2, i);
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
      Utils::iu_comparison(i_Q, i_true_Q, error_case_4, 210, n);
      if (error_case_4 != 0) break;
      Utils::iu_comparison(i_Q_err2, i_true_Q_err2, error_case_4, 220, n);
      if (error_case_4 != 0) break;
      Utils::iu_comparison(u_Q, u_true_Q, error_case_4, 310, n);
      if (error_case_4 != 0) break;
      Utils::iu_comparison(u_Q_err2, u_true_Q_err2, error_case_4, 320, n);
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
		cout << "(unsigned) FAILED....Output vector different from vector expected"<<endl;
		break;
	      case 320:
		cout << "(unsigned) FAILED....Output error vector different from vector expected"<<endl;
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
		cout << "(unsigned) FAILED....Output vector different from vector expected"<<endl;
		break;
	      case 320:
		cout << "(unsigned) FAILED....Output error vector different from vector expected"<<endl;
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
		cout << "(unsigned) FAILED....Output vector different from vector expected"<<endl;
		break;
	      case 320:
		cout << "(unsigned) FAILED....Output error vector different from vector expected"<<endl;
		break;
	      }
	  }
      }	
    }
  return 0;
}


void f_function_init_scatt_wavevector_to_scalar_Q(vector<float> & f_initial_wavevector, 
						  vector<float> & f_initial_wavevector_err2,
						  int i,
						  vector<float> & f_final_wavevector, 
						  vector<float> & f_final_wavevector_err2,
						  int j,
						  float f_polar_angle,
						  float f_polar_angle_err2,
						  vector<float> & f_true_Q, 
						  vector<float> & f_true_Q_err2,
						  int k)
{
  float f_a;
  float f_pang;
  float f_ki2, f_kf2, f_akikf;
  float f_termi, f_termi2;
  float f_termf, f_termf2;
  float f_front;

  f_ki2 = f_initial_wavevector[i] * f_initial_wavevector[i];

  f_a = static_cast<float>(2 * std::cos(static_cast<double>(f_polar_angle)));
  f_pang = static_cast<float>(std::cos(static_cast<double>(f_polar_angle)));

  f_kf2 = f_final_wavevector[j] * f_final_wavevector[j];
  f_akikf = f_a * f_initial_wavevector[i] * f_final_wavevector[j];
  
  f_true_Q[k] = static_cast<float>(std::sqrt(static_cast<double>(f_ki2 + f_kf2 - f_akikf)));
  
  f_termi = f_initial_wavevector[i] - (f_final_wavevector[j] * f_pang);
  f_termi2 = f_termi * f_termi;
  f_termf = f_final_wavevector[j] - (f_initial_wavevector[i] * f_pang);
  f_termf2 = f_termf * f_termf;
  f_front = 4. / (f_true_Q[k] * f_true_Q[k]);
  
  f_true_Q_err2[k] = f_front * (( f_initial_wavevector_err2[i] * f_termi2) +
				( f_final_wavevector_err2[j] * f_termf2));
  
  return;
}


void d_function_init_scatt_wavevector_to_scalar_Q(vector<double> & d_initial_wavevector, 
						  vector<double> & d_initial_wavevector_err2,
						  int i,
						  vector<double> & d_final_wavevector, 
						  vector<double> & d_final_wavevector_err2,
						  int j,
						  double d_polar_angle,
						  double d_polar_angle_err2,
						  vector<double> & d_true_Q, 
						  vector<double> & d_true_Q_err2,
						  int k)
{
  double d_a;
  double d_pang;
  double d_ki2, d_kf2, d_akikf;
  double d_termi, d_termi2;
  double d_termf, d_termf2;
  double d_front;

  d_a = static_cast<double>(2 * std::cos(static_cast<double>(d_polar_angle)));
  d_pang = static_cast<double>(std::cos(static_cast<double>(d_polar_angle)));

  d_ki2 = d_initial_wavevector[i] * d_initial_wavevector[i];

  d_kf2 = d_final_wavevector[j] * d_final_wavevector[j];
  d_akikf = d_a * d_initial_wavevector[i] * d_final_wavevector[j];
  
  d_true_Q[k] = static_cast<double>(std::sqrt(static_cast<double>(d_ki2 + d_kf2 - d_akikf)));
  
  d_termi = d_initial_wavevector[i] - (d_final_wavevector[j] * d_pang);
  d_termi2 = d_termi * d_termi;
  d_termf = d_final_wavevector[j] - (d_initial_wavevector[i] * d_pang);
  d_termf2 = d_termf * d_termf;
  d_front = 4 / (d_true_Q[k] * d_true_Q[k]);
  
  d_true_Q_err2[k] = d_front * (( d_initial_wavevector_err2[i] * d_termi2) +
				( d_final_wavevector_err2[j] * d_termf2));
  
  return;
}

void i_function_init_scatt_wavevector_to_scalar_Q(vector<int> & i_initial_wavevector, 
						  vector<int> & i_initial_wavevector_err2,
						  int i,
						  vector<int> & i_final_wavevector, 
						  vector<int> & i_final_wavevector_err2,
						  int j,
						  int i_polar_angle,
						  int i_polar_angle_err2,
						  vector<int> & i_true_Q, 
						  vector<int> & i_true_Q_err2,
						  int k)
{
  int i_a;
  int i_pang;
  int i_ki2, i_kf2, i_akikf;
  int i_termi, i_termi2;
  int i_termf, i_termf2;
  int i_front;

  i_ki2 = i_initial_wavevector[i] * i_initial_wavevector[i];

  i_a = static_cast<int>(2 * std::cos(static_cast<double>(i_polar_angle)));
  i_pang = static_cast<int>(std::cos(static_cast<double>(i_polar_angle)));

  i_kf2 = i_final_wavevector[j] * i_final_wavevector[j];
  i_akikf = i_a * i_initial_wavevector[i] * i_final_wavevector[j];
  
  i_true_Q[k] = static_cast<int>(std::sqrt(static_cast<double>(i_ki2 + i_kf2 - i_akikf)));
  
  i_termi = i_initial_wavevector[i] - (i_final_wavevector[j] * i_pang);
  i_termi2 = i_termi * i_termi;
  i_termf = i_final_wavevector[j] - (i_initial_wavevector[i] * i_pang);
  i_termf2 = i_termf * i_termf;
  i_front = static_cast<int>(4 / (i_true_Q[k] * i_true_Q[k]));
  
  i_true_Q_err2[k] = i_front * (( i_initial_wavevector_err2[i] * i_termi2) +
				( i_final_wavevector_err2[j] * i_termf2));
  
  return;
}


void u_function_init_scatt_wavevector_to_scalar_Q(vector<unsigned int> & u_initial_wavevector, 
						  vector<unsigned int> & u_initial_wavevector_err2,
						  int i,
						  vector<unsigned int> & u_final_wavevector, 
						  vector<unsigned int> & u_final_wavevector_err2,
						  int j,
						  unsigned int u_polar_angle,
						  unsigned int u_polar_angle_err2,
						  vector<unsigned int> & u_true_Q, 
						  vector<unsigned int> & u_true_Q_err2,
						  int k)
{
  unsigned int u_a;
  unsigned int u_pang;
  unsigned int u_ki2, u_kf2, u_akikf;
  unsigned int u_termi, u_termi2;
  unsigned int u_termf, u_termf2;
  unsigned int u_front;

  u_ki2 = u_initial_wavevector[i] * u_initial_wavevector[i];

  u_a = static_cast<unsigned int>(2 * std::cos(static_cast<double>(u_polar_angle)));
  u_pang = static_cast<unsigned int>(std::cos(static_cast<double>(u_polar_angle)));

  u_kf2 = u_final_wavevector[j] * u_final_wavevector[j];
  u_akikf = u_a * u_initial_wavevector[i] * u_final_wavevector[j];
  
  u_true_Q[k] = static_cast<unsigned int>(std::sqrt(static_cast<double>(u_ki2 + u_kf2 - u_akikf)));
  
  u_termi = u_initial_wavevector[i] - (u_final_wavevector[j] * u_pang);
  u_termi2 = u_termi * u_termi;
  u_termf = u_final_wavevector[j] - (u_initial_wavevector[i] * u_pang);
  u_termf2 = u_termf * u_termf;
  u_front = 4 / (u_true_Q[k] * u_true_Q[k]);
  
  u_true_Q_err2[k] = u_front * (( u_initial_wavevector_err2[i] * u_termi2) +
				( u_final_wavevector_err2[j] * u_termf2));
  
  return;
}
