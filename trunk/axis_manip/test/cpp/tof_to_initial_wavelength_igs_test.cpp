#include <vector>
#include <cmath>
#include "conversions.hpp"
#include "constants.hpp"
#include <iostream>

using namespace std;
static const double PI = 3.14159265358979323846264338328;
static const double H_OVER_MNEUT = 0.003961617;

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
  float f_time_offset;
  float f_dist_source_sample;
  float f_dist_sample_detector;
  float f_a;
  float f_a2;
  float f_b;

  //double
  vector<double> d_tof;                
  vector<double> d_tof_err2;           
  vector<double> d_initial_wavelength(n);          
  vector<double> d_initial_wavelength_err2(n);     
  vector<double> d_true_initial_wavelength(n);          
  vector<double> d_true_initial_wavelength_err2(n);     
  double d_final_wavelength;
  double d_time_offset;
  double d_dist_source_sample;
  double d_dist_sample_detector;
  double d_a;
  double d_a2;
  double d_b;

  //int
  vector<int> i_tof;                
  vector<int> i_tof_err2;           
  vector<int> i_initial_wavelength(n);          
  vector<int> i_initial_wavelength_err2(n);     
  vector<int> i_true_initial_wavelength(n);          
  vector<int> i_true_initial_wavelength_err2(n);     
  int i_final_wavelength;
  int i_time_offset;
  int i_dist_source_sample;
  int i_dist_sample_detector;
  int i_a;
  int i_a2;
  int i_b;

  //unsigned
  vector<unsigned> u_tof;                
  vector<unsigned> u_tof_err2;           
  vector<unsigned> u_initial_wavelength(n);          
  vector<unsigned> u_initial_wavelength_err2(n);     
  vector<unsigned> u_true_initial_wavelength(n);          
  vector<unsigned> u_true_initial_wavelength_err2(n);     
  unsigned u_final_wavelength;
  unsigned u_time_offset;
  unsigned u_dist_source_sample;
  unsigned u_dist_sample_detector;
  unsigned u_a;
  unsigned u_a2;
  unsigned u_b;

  int error=0;                      //==0,Pass  !=0,Fail

  float final_wavelength = 345.34;
  float time_offset = 0.0245;
  float dist_source_sample = 34.45;
  float dist_sample_detector = 3.35;
  
  f_final_wavelength = static_cast<float>(final_wavelength);
  f_time_offset = static_cast<float>(time_offset);
  f_dist_source_sample = static_cast<float>(dist_source_sample);
  f_dist_sample_detector = static_cast<float>(dist_sample_detector);
  
  d_final_wavelength = static_cast<double>(final_wavelength);
  d_time_offset = static_cast<double>(time_offset);
  d_dist_source_sample = static_cast<double>(dist_source_sample);
  d_dist_sample_detector = static_cast<double>(dist_sample_detector);
  
  i_final_wavelength = static_cast<int>(final_wavelength);
  i_time_offset = static_cast<int>(time_offset);
  i_dist_source_sample = static_cast<int>(dist_source_sample);
  i_dist_sample_detector = static_cast<int>(dist_sample_detector);
  
  u_final_wavelength = static_cast<unsigned>(final_wavelength);
  u_time_offset = static_cast<unsigned>(time_offset);
  u_dist_source_sample = static_cast<unsigned>(dist_source_sample);
  u_dist_sample_detector = static_cast<unsigned>(dist_sample_detector);
  
  
  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*(float)i+1);
      d_tof.push_back(2.*(double)i+1); 
      i_tof.push_back(2*(int)i+1);
      u_tof.push_back(2*(unsigned)i+1);

      f_tof_err2.push_back((float)i+2);
      d_tof_err2.push_back((double)i+2);      
      i_tof_err2.push_back((int)i+2);
      u_tof_err2.push_back((unsigned)i+2);
    }
  
  AxisManip::tof_to_initial_wavelength_igs(f_tof, f_tof_err2, 
					   f_final_wavelength, f_time_offset,
					   f_dist_source_sample, f_dist_sample_detector,
					   f_initial_wavelength, f_initial_wavelength_err2);
  AxisManip::tof_to_initial_wavelength_igs(d_tof, d_tof_err2,  
					   d_final_wavelength, d_time_offset,
					   d_dist_source_sample, d_dist_sample_detector,
					   d_initial_wavelength, d_initial_wavelength_err2);
  AxisManip::tof_to_initial_wavelength_igs(i_tof, i_tof_err2, 
					   i_final_wavelength, i_time_offset,
					   i_dist_source_sample, i_dist_sample_detector,
					   i_initial_wavelength, i_initial_wavelength_err2);
  AxisManip::tof_to_initial_wavelength_igs(u_tof, u_tof_err2,  
					   u_final_wavelength, u_time_offset,
					   u_dist_source_sample, u_dist_sample_detector,
					   u_initial_wavelength, u_initial_wavelength_err2);
  
  f_a = static_cast<float>(1 / (H_OVER_MNEUT * f_dist_sample_detector));
  f_a2 = f_a * f_a;
  f_b = (f_dist_sample_detector * f_final_wavelength) / f_dist_source_sample;
  f_b += (f_a * f_time_offset);
  
  d_a = static_cast<double>(1 / (H_OVER_MNEUT * d_dist_sample_detector));
  d_a2 = d_a * d_a;
  d_b = (d_dist_sample_detector * d_final_wavelength) / d_dist_source_sample;
  d_b += (d_a * d_time_offset);

  i_a = static_cast<int>(1 / (H_OVER_MNEUT * i_dist_sample_detector));
  i_a2 = i_a * i_a;
  i_b = (i_dist_sample_detector * i_final_wavelength) / i_dist_source_sample;
  i_b += (i_a * i_time_offset);

  u_a = static_cast<unsigned>(1 / (H_OVER_MNEUT * u_dist_sample_detector));
  u_a2 = u_a * u_a;
  u_b = (u_dist_sample_detector * u_final_wavelength) / u_dist_source_sample;
  u_b += (u_a * u_time_offset);
  
  
  for (int i=0; i<n; i++)
    {
      //float
      f_true_initial_wavelength[i] = f_a * f_tof[i] - f_b;
      f_true_initial_wavelength_err2[i] = f_a2 * f_tof_err2[i];
      
      //double
      d_true_initial_wavelength[i] = d_a * d_tof[i] - d_b;
      d_true_initial_wavelength_err2[i] = d_a2 * d_tof_err2[i];

      //int
      i_true_initial_wavelength[i] = i_a * i_tof[i] - i_b;
      i_true_initial_wavelength_err2[i] = i_a2 * i_tof_err2[i];

      //unsigned
      u_true_initial_wavelength[i] = u_a * u_tof[i] - u_b;
      u_true_initial_wavelength_err2[i] = u_a2 * u_tof_err2[i];
      
    }
  
  //check first if the size are in good agreement
  if ((f_tof.size() != f_initial_wavelength.size())||(d_tof.size() != d_initial_wavelength.size()) || (i_tof.size() != i_initial_wavelength.size()) || (u_tof.size() != u_initial_wavelength.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for (int i=0; i<n;++i)
	{
	  if (fabs(f_initial_wavelength[i] - f_true_initial_wavelength[i])>0.000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_initial_wavelength_err2[i] - f_true_initial_wavelength_err2[i])>0.000001)
	    {
	      error=error+20;
	      break;
	    }
	  if (fabs(d_initial_wavelength[i] - d_true_initial_wavelength[i]) > 0.0001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_initial_wavelength_err2[i] - d_true_initial_wavelength_err2[i])> 0.0001)
	    {
	      error=error+120;
	      break;
	    }
	  if (i_initial_wavelength[i] != i_true_initial_wavelength[i])
	    {
	      error=error+210;
	      break;
	    }
	  if (i_initial_wavelength_err2[i] != i_true_initial_wavelength_err2[i])
	    {
	      error=error+220;
	      break;
	    }
	  if (u_initial_wavelength[i] != u_true_initial_wavelength[i])
	    {
	      error=error+310;
	      break;
	    }
	  if (u_initial_wavelength_err2[i] != u_true_initial_wavelength_err2[i])
	    {
	      error=error+320;
	      break;
	    }

	}
    }

  cout << "tof_to_initial_wavelength_igs_test.cpp..........";

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
