#include <iostream>
#include <vector>
#include <cmath>
#include "vec_scalar_arith.hpp"
using namespace std;

int main() 
{
  int n = 20;
  float f_scalar = 5.0;
  float f_scalar_err2 = 3.0;
  float f_scalar_2;
  vector<float> f_input;                //Original vector
  vector<float> f_input_err2;            //Original vector err
  vector<float> f_output(n);             //Output vector
  vector<float> f_output_err2(n);         //Output vector err
  vector<float> f_true_vector;      //True vector
  vector<float> f_true_vector_err2(n);  //True vector err

  double d_scalar = 5;
  double d_scalar_err2 = 3;
  double d_scalar_2;
  vector<double> d_input;
  vector<double> d_input_err2;
  vector<double> d_output(n);
  vector<double> d_output_err2(n);
  vector<double> d_true_vector;
  vector<double> d_true_vector_err2(n);

  int i_scalar = 5;
  int i_scalar_err2 = 3;
  int i_scalar_2;
  vector<int> i_input;
  vector<int> i_input_err2;
  vector<int> i_output(n);
  vector<int> i_output_err2(n);
  vector<int> i_true_vector;
  vector<int> i_true_vector_err2(n);
  
  unsigned u_scalar = 5;
  unsigned u_scalar_err2 = 3;
  unsigned u_scalar_2;
  vector<unsigned> u_input;
  vector<unsigned> u_input_err2;
  vector<unsigned> u_output(n);
  vector<unsigned> u_output_err2(n);
  vector<unsigned> u_true_vector;
  vector<unsigned> u_true_vector_err2(n);
  
  int error=0;                      //==0,Pass  !=0,Fail

  for(int i=0; i<n; i++)
    {
      f_input.push_back(2.*(float)i+1);
      d_input.push_back(2*(double)i+1); 
      i_input.push_back(2*(int)i+1);
      u_input.push_back(2*(unsigned)i+1);

      f_input_err2.push_back((float)i+1);
      d_input_err2.push_back((double)i+1);      
      i_input_err2.push_back((int)i+1);
      u_input_err2.push_back((unsigned)i+1);
    }
 
  ArrayManip::div_vec_scalar_ncerr(f_input, f_input_err2, f_output, f_output_err2, f_scalar, f_scalar_err2);
  ArrayManip::div_vec_scalar_ncerr(d_input, d_input_err2, d_output, d_output_err2, d_scalar, d_scalar_err2);
  ArrayManip::div_vec_scalar_ncerr(i_input, i_input_err2, i_output, i_output_err2, i_scalar, i_scalar_err2);
  ArrayManip::div_vec_scalar_ncerr(u_input, u_input_err2, u_output, u_output_err2, u_scalar, u_scalar_err2);

  for (int i=0; i<n; i++)
    {
      f_true_vector.push_back(f_input[i]/f_scalar);
      d_true_vector.push_back(d_input[i]/d_scalar);
      i_true_vector.push_back(i_input[i]/i_scalar);
      u_true_vector.push_back(u_input[i]/u_scalar);

      f_scalar_2 = f_scalar*f_scalar;
      d_scalar_2 = d_scalar*d_scalar;
      i_scalar_2 = i_scalar*i_scalar;
      u_scalar_2 = u_scalar*u_scalar;

      f_true_vector_err2[i] = (f_input_err2[i] / f_scalar_2) + 
	((( f_input[i] * f_input[i]) / (f_scalar_2 * f_scalar_2)) * f_scalar_err2);

      d_true_vector_err2[i] = (d_input_err2[i] / d_scalar_2) + 
	((( d_input[i] * d_input[i]) / (d_scalar_2 * d_scalar_2)) * d_scalar_err2);

      i_true_vector_err2[i] = (i_input_err2[i] / i_scalar_2) + 
	((( i_input[i] * i_input[i]) / (i_scalar_2 * i_scalar_2)) * i_scalar_err2);

      u_true_vector_err2[i] = (u_input_err2[i] / u_scalar_2) + 
	((( u_input[i] * u_input[i]) / (u_scalar_2 * u_scalar_2)) * u_scalar_err2);

    }

  //check first the size
  if ((f_input.size() != f_output.size())||(d_input.size() != d_output.size()) || (i_input.size() != i_output.size()) || (u_input.size() != u_output.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for ( int i=0 ; i<n ; ++i )
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
	  if (fabs(d_output[i] - d_true_vector[i]) > 0.000001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_output_err2[i] - d_true_vector_err2[i]) > 0.000001)
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

  cout << "div_vec_scalar_ncerr_test.cpp..........";

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

