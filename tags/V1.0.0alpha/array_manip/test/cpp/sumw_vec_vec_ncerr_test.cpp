#include <iostream>
#include <vector>
#include <cmath>
#include "vec_vec_arith.hpp"
#include <algorithm>

using namespace std;

int main() 
{
  int n = 20;

  //float
  vector<float> f_input1;                //Original vector 1
  vector<float> f_input1_err2;           //Original vector 1 err
  vector<float> f_input2;                //Original vector 2
  vector<float> f_input2_err2;           //Original vector 2 err
  vector<float> f_output(n);             //Output vector
  vector<float> f_output_err2(n);        //Output vector err
  vector<float> f_true_vector(n);           //True output vector
  vector<float> f_true_vector_err2(n);      //True output vector err
  float f_input1_err;
  float f_input2_err;
  float f_sum_err;

  //double 
  vector<double> d_input1;                //Original vector 1
  vector<double> d_input1_err2;           //Original vector 1 err
  vector<double> d_input2;                //Original vector 2
  vector<double> d_input2_err2;           //Original vector 2 err
  vector<double> d_output(n);             //Output vector
  vector<double> d_output_err2(n);        //Output vector err
  vector<double> d_true_vector(n);           //True output vector
  vector<double> d_true_vector_err2(n);      //True output vector err
  float d_input1_err;
  float d_input2_err;
  float d_sum_err;

  //int 
  vector<int> i_input1;                //Original vector 1
  vector<int> i_input1_err2;           //Original vector 1 err
  vector<int> i_input2;                //Original vector 2
  vector<int> i_input2_err2;           //Original vector 2 err
  vector<int> i_output(n);             //Output vector
  vector<int> i_output_err2(n);        //Output vector err
  vector<int> i_true_vector(n);           //True output vector
  vector<int> i_true_vector_err2(n);      //True output vector err
  float i_input1_err;
  float i_input2_err;
  float i_sum_err;

  //unsigned 
  vector<unsigned> u_input1;                //Original vector 1
  vector<unsigned> u_input1_err2;           //Original vector 1 err
  vector<unsigned> u_input2;                //Original vector 2
  vector<unsigned> u_input2_err2;           //Original vector 2 err
  vector<unsigned> u_output(n);             //Output vector
  vector<unsigned> u_output_err2(n);        //Output vector err
  vector<unsigned> u_true_vector(n);           //True output vector
  vector<unsigned> u_true_vector_err2(n);      //True output vector err
  float u_input1_err;
  float u_input2_err;
  float u_sum_err;

  int error=0;                      //==0,Pass  !=0,Fail

  for(int i=0; i<n; i++)            //create the arrays
    {
      //_input1 array
      f_input1.push_back(2.*(float)i);
      d_input1.push_back(2.*(double)i); 
      i_input1.push_back(2*(int)i);
      u_input1.push_back(2*(unsigned)i);

      f_input1_err2.push_back((float)i);
      d_input1_err2.push_back((double)i);      
      i_input1_err2.push_back((int)i+1);
      u_input1_err2.push_back((unsigned)i+1);
      
      //_input2 array
      f_input2.push_back(4.*(float)i);
      d_input2.push_back(4.*(double)i); 
      i_input2.push_back(4*(int)i);
      u_input2.push_back(4*(unsigned)i);

      f_input2_err2.push_back((float)i+5.);
      d_input2_err2.push_back((double)i+5.);      
      i_input2_err2.push_back((int)i+5);
      u_input2_err2.push_back((unsigned)i+5);

    }
  
  ArrayManip::sumw_vec_vec_ncerr(f_input1, f_input1_err2, f_input2, 
				 f_input2_err2, f_output, f_output_err2);
  ArrayManip::sumw_vec_vec_ncerr(d_input1, d_input1_err2, d_input2, 
				 d_input2_err2, d_output, d_output_err2);
  ArrayManip::sumw_vec_vec_ncerr(i_input1, i_input1_err2, i_input2, 
				 i_input2_err2, i_output, i_output_err2);
  ArrayManip::sumw_vec_vec_ncerr(u_input1, u_input1_err2, u_input2, 
				 u_input2_err2, u_output, u_output_err2);
  
  for (int i=0; i<n; i++)
    {
      //float
      f_input1_err = static_cast<float>(std::sqrt(static_cast<double>(f_input1_err2[i])));
      f_input2_err = static_cast<float>(std::sqrt(static_cast<double>(f_input2_err2[i])));
      f_sum_err = f_input1_err + f_input2_err;
      
      f_true_vector[i] = (f_input1[i] / f_input1_err) + (f_input2[i] / f_input2_err);
      f_true_vector[i] *= f_sum_err;
      
      f_true_vector_err2[i] = f_input1_err2[i] + f_input2_err2[i];
      
      //double
      d_input1_err = static_cast<double>(std::sqrt(static_cast<double>(d_input1_err2[i])));
      d_input2_err = static_cast<double>(std::sqrt(static_cast<double>(d_input2_err2[i])));
      d_sum_err = d_input1_err + d_input2_err;
      
      d_true_vector[i] = (d_input1[i] / d_input1_err) + (d_input2[i] / d_input2_err);
      d_true_vector[i] *= d_sum_err;
      
      d_true_vector_err2[i] = d_input1_err2[i] + d_input2_err2[i];
      
      //int
      i_input1_err = static_cast<int>(std::sqrt(static_cast<double>(i_input1_err2[i])));
      i_input2_err = static_cast<int>(std::sqrt(static_cast<double>(i_input2_err2[i])));
      i_sum_err = static_cast<int>(i_input1_err + i_input2_err);
      
      i_true_vector[i] = static_cast<int>(i_input1[i] / i_input1_err) + 
	static_cast<int>(i_input2[i] / i_input2_err);
      i_true_vector[i] *= static_cast<int>(i_sum_err);
      
      i_true_vector_err2[i] = i_input1_err2[i] + i_input2_err2[i];

      //unsigned
      u_input1_err = static_cast<unsigned>(std::sqrt(static_cast<double>(u_input1_err2[i])));
      u_input2_err = static_cast<unsigned>(std::sqrt(static_cast<double>(u_input2_err2[i])));
      u_sum_err = static_cast<unsigned>(u_input1_err + u_input2_err);
      
      u_true_vector[i] = static_cast<unsigned>(u_input1[i] / u_input1_err) + 
	static_cast<unsigned>(u_input2[i] / u_input2_err);
      u_true_vector[i] *= static_cast<unsigned>(u_sum_err);
      
      u_true_vector_err2[i] = u_input1_err2[i] + u_input2_err2[i];

    }
  
  //check first if the size are in good agreement
  if ((f_input1.size() != f_output.size())||(d_input1.size() != d_output.size()) || (i_input1.size() != i_output.size()) || (u_input1.size() != u_output.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for (int i=0; i<n;++i)
	{
	  if (fabs(f_output[i] - f_true_vector[i])>0.000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_output_err2[i] - f_true_vector_err2[i])>0.000001)
	    {
	      error=error+20;
	      break;
	    }
	  //	  if (fabs(d_output[i] - d_true_vector[i]) > 0.000001)
	  if (fabs(d_output[i] - d_true_vector[i]) > 0.0001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_output_err2[i] - d_true_vector_err2[i])> 0.0001)
	    {
	      error=error+120;
	      break;
	    }
	  if (i_output[i] != i_true_vector[i])
	    {
	      error=error+210;
	      break;
	    }
	  if (i_output_err2[i] != i_true_vector_err2[i])
	    {
	      error=error+220;
	      break;
	    }
	  if (u_output[i] != u_true_vector[i])
	    {
	      error=error+310;
	      break;
	    }
	  if (u_output_err2[i] != u_true_vector_err2[i])
	    {
	      error=error+320;
	      break;
	    }
	}
    }

  cout << "sumw_vec_vec_ncerr_test.cpp..........";

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
