#include "constants.hpp"
#include "conversions.hpp"
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>
#include <vector>

//int and unsigned cases are not consider because they lead to a infinite result

using namespace std;

int main() 
{
  int n = 20;

  //float
  vector<float> f_tof;                
  vector<float> f_tof_err2;           
  vector<float> f_initial_wavelength(n);          
  vector<float> f_initial_wavelength_err2(n);     
  vector<float> f_true_initial_wavelength(n);          
  vector<float> f_true_initial_wavelength_err2(n);     
  float f_final_wavelength;
  float f_final_wavelength_err2;
  float f_time_offset;
  float f_time_offset_err2;
  float f_dist_source_sample;
  float f_dist_source_sample_err2;
  float f_dist_sample_detector;
  float f_dist_sample_detector_err2;
  float f_a, f_a2;
  float f_b;
  float f_c, f_c2;
  float f_d, f_d2;
  float f_ls2;

  //double
  vector<double> d_tof;                
  vector<double> d_tof_err2;           
  vector<double> d_initial_wavelength(n);          
  vector<double> d_initial_wavelength_err2(n);     
  vector<double> d_true_initial_wavelength(n);          
  vector<double> d_true_initial_wavelength_err2(n);     
  double d_final_wavelength;
  double d_final_wavelength_err2;
  double d_time_offset;
  double d_time_offset_err2;
  double d_dist_source_sample;
  double d_dist_source_sample_err2;
  double d_dist_sample_detector;
  double d_dist_sample_detector_err2;
  double d_a, d_a2;
  double d_b;
  double d_c, d_c2;
  double d_d, d_d2;
  double d_ls2;

  int error=0;                      //==0,Pass  !=0,Fail

  float final_wavelength = 345.34;
  float final_wavelength_err2 = 35.;
  float time_offset = 0.0245;
  float time_offset_err2 = 0.002;
  float dist_source_sample = 34.45;
  float dist_source_sample_err2 = 9.2;
  float dist_sample_detector = 13.35;
  float dist_sample_detector_err2 = 8.5;
  
  f_final_wavelength = (float)(final_wavelength);
  f_final_wavelength_err2 = (float)(final_wavelength_err2);
  f_time_offset = (float)(time_offset);
  f_time_offset_err2 = (float)(time_offset_err2);
  f_dist_source_sample = (float)(dist_source_sample);
  f_dist_source_sample_err2 = (float)(dist_source_sample_err2);
  f_dist_sample_detector = (float)(dist_sample_detector);
  f_dist_sample_detector_err2 = (float)(dist_sample_detector_err2);
  
  d_final_wavelength = (double)(final_wavelength);
  d_final_wavelength_err2 = (double)(final_wavelength_err2);
  d_time_offset = (double)(time_offset);
  d_time_offset_err2 = (double)(time_offset_err2);
  d_dist_source_sample = (double)(dist_source_sample);
  d_dist_source_sample_err2 = (double)(dist_source_sample_err2);
  d_dist_sample_detector = (double)(dist_sample_detector);
  d_dist_sample_detector_err2 = (double)(dist_sample_detector_err2);
  
  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*(float)i+1);
      d_tof.push_back(2.*(double)i+1); 

      f_tof_err2.push_back((float)i+2);
      d_tof_err2.push_back((double)i+2);      
    }
  
  AxisManip::tof_to_initial_wavelength_igs(f_tof, f_tof_err2, 
					   f_final_wavelength, f_final_wavelength_err2,
                                           f_time_offset, f_time_offset_err2, 
					   f_dist_source_sample, f_dist_source_sample_err2,
                                           f_dist_sample_detector, f_dist_sample_detector_err2,
					   f_initial_wavelength, f_initial_wavelength_err2);

  AxisManip::tof_to_initial_wavelength_igs(d_tof, d_tof_err2,  
					   d_final_wavelength, d_final_wavelength_err2, 
                                           d_time_offset, d_time_offset_err2,
					   d_dist_source_sample, d_dist_source_sample_err2, 
                                           d_dist_sample_detector, d_dist_sample_detector_err2,
					   d_initial_wavelength, d_initial_wavelength_err2);

  

  f_a = (float)((PhysConst::H_OVER_MNEUT / f_dist_source_sample));
  f_a2 = f_a * f_a;

  f_b = (f_dist_sample_detector * f_final_wavelength);
  f_b = f_b / f_dist_source_sample;
  f_b += (f_a * f_time_offset);

  f_c = f_final_wavelength / f_dist_source_sample;
  f_c2 = f_c * f_c;
    
  f_d = f_dist_sample_detector / f_dist_source_sample;
  f_d2 = f_d * f_d;

  f_ls2 = f_dist_source_sample * f_dist_source_sample;
  

  d_a = (double)((PhysConst::H_OVER_MNEUT / d_dist_source_sample));
  d_a2 = d_a * d_a;
  d_b = (d_dist_sample_detector * d_final_wavelength);
  d_b =  d_b / d_dist_source_sample;
  d_b += (d_a * d_time_offset);

  d_c = d_final_wavelength / d_dist_source_sample;
  d_c2 = d_c * d_c;
    
  d_d = d_dist_sample_detector / d_dist_source_sample;
  d_d2 = d_d * d_d;

  d_ls2 = d_dist_source_sample * d_dist_source_sample;

  for (int i=0; i<n; i++)
    {
      //float
      f_true_initial_wavelength[i] = f_a * f_tof[i] - f_b;
      f_true_initial_wavelength_err2[i] = f_a2 * (f_tof_err2[i] + f_time_offset_err2);
      f_true_initial_wavelength_err2[i] += f_c2 * f_dist_sample_detector_err2;
      f_true_initial_wavelength_err2[i] += f_d2 * f_final_wavelength_err2;
      f_true_initial_wavelength_err2[i] += f_initial_wavelength[i] *
	f_initial_wavelength[i] * f_dist_source_sample_err2 / f_ls2;

      //double
      d_true_initial_wavelength[i] = (d_a * d_tof[i]) - d_b;
      d_true_initial_wavelength_err2[i] = d_a2 * (d_tof_err2[i] + d_time_offset_err2);
      d_true_initial_wavelength_err2[i] += d_c2 * d_dist_sample_detector_err2;
      d_true_initial_wavelength_err2[i] += d_d2 * d_final_wavelength_err2;
      d_true_initial_wavelength_err2[i] += d_initial_wavelength[i] *
	d_initial_wavelength[i] * d_dist_source_sample_err2 / d_ls2;
    }
  
  //check first if the size are in good agreement
  if ((f_tof.size() != f_initial_wavelength.size())||(d_tof.size() != d_initial_wavelength.size()) )
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      while(1)
	{
	  Utils::fd_comparison(f_initial_wavelength, f_true_initial_wavelength,
			       error, 10, n);
	  if (error != 0) break;
	  Utils::fd_comparison(f_initial_wavelength_err2, f_true_initial_wavelength_err2, 
			       error, 20, n);
	  if (error != 0) break;
	  
	  Utils::fd_comparison(d_initial_wavelength, d_true_initial_wavelength, 
			       error, 110, n);
	  if (error != 0) break;
	  Utils::fd_comparison(d_initial_wavelength_err2, d_true_initial_wavelength_err2, 
			       error, 120, n);
	  break;
	}
    }
  
  cout << "tof_to_initial_wavelength_igs.cpp..........";

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
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
