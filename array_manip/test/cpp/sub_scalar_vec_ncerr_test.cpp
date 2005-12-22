// $Id$

#include "nessi.hpp"
#include "vec_scalar_arith.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  int num_val = 20;
  float f_scalar = 5.0;
  float f_scalar_err2 = 1.0;
  Nessi::Vector<float> f_input;                       //Original vector
  Nessi::Vector<float> f_input_err2;                  //Original vector err
  Nessi::Vector<float> f_output(num_val);             //Output vector
  Nessi::Vector<float> f_output_err2(num_val);        //Output vector err
  Nessi::Vector<float> f_true_vector;                 //True vector
  Nessi::Vector<float> f_true_vector_err2;            //True vector err

  double d_scalar = 5;
  double d_scalar_err2 = 1;
  Nessi::Vector<double> d_input;
  Nessi::Vector<double> d_input_err2;
  Nessi::Vector<double> d_output(num_val);
  Nessi::Vector<double> d_output_err2(num_val);
  Nessi::Vector<double> d_true_vector;
  Nessi::Vector<double> d_true_vector_err2;

  int i_scalar = 5;
  int i_scalar_err2 = 1;
  Nessi::Vector<int> i_input;
  Nessi::Vector<int> i_input_err2;
  Nessi::Vector<int> i_output(num_val);
  Nessi::Vector<int> i_output_err2(num_val);
  Nessi::Vector<int> i_true_vector;
  Nessi::Vector<int> i_true_vector_err2;
  
  unsigned u_scalar = 5;
  unsigned u_scalar_err2 = 1;
  Nessi::Vector<unsigned> u_input;
  Nessi::Vector<unsigned> u_input_err2;
  Nessi::Vector<unsigned> u_output(num_val);
  Nessi::Vector<unsigned> u_output_err2(num_val);
  Nessi::Vector<unsigned> u_true_vector;
  Nessi::Vector<unsigned> u_true_vector_err2;
  
  int error=0;                      //==0,Pass  !=0,Fail

  for(int i = 0 ; i < num_val ; ++i)
    {
      f_input.push_back(2.*static_cast<float>(i));
      d_input.push_back(2*static_cast<double>(i)); 
      i_input.push_back(2*static_cast<int>(i));
      u_input.push_back(2*static_cast<unsigned int>(i));

      f_input_err2.push_back(static_cast<float>(i));
      d_input_err2.push_back(static_cast<double>(i));      
      i_input_err2.push_back(static_cast<int>(i));
      u_input_err2.push_back(static_cast<unsigned int>(i));
    }
 
  ArrayManip::sub_scalar_vec_ncerr(f_input, f_input_err2, 
				   f_output, f_output_err2, 
				   f_scalar, f_scalar_err2);

  ArrayManip::sub_scalar_vec_ncerr(d_input, d_input_err2,
				   d_output, d_output_err2, 
				   d_scalar, d_scalar_err2);

  ArrayManip::sub_scalar_vec_ncerr(i_input, i_input_err2, 
				   i_output, i_output_err2, 
				   i_scalar, i_scalar_err2);

  ArrayManip::sub_scalar_vec_ncerr(u_input, u_input_err2,
				   u_output, u_output_err2, 
				   u_scalar, u_scalar_err2);
  
  for (int i = 0 ; i < num_val ; ++i)
    {
      f_true_vector.push_back(f_input[i]-f_scalar);
      d_true_vector.push_back(d_input[i]-d_scalar);
      i_true_vector.push_back(i_input[i]-i_scalar);
      u_true_vector.push_back(u_input[i]-u_scalar);

      f_true_vector_err2.push_back(f_input_err2[i]+f_scalar_err2);
      d_true_vector_err2.push_back(d_input_err2[i]+d_scalar_err2);
      i_true_vector_err2.push_back(i_input_err2[i]+i_scalar_err2);
      u_true_vector_err2.push_back(u_input_err2[i]+u_scalar_err2);
    }

  //check first the size
  if ( (f_input.size() != f_output.size())
       || (d_input.size() != d_output.size()) 
       || (i_input.size() != i_output.size())
       || (u_input.size() != u_output.size()) )
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for (int i = 0 ; i < num_val ; ++i)
	{
	  if (fabs(f_output[i] - f_true_vector[i])>0.0000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_output_err2[i] - f_true_vector_err2[i])>0.0000001)
	    {
	      error=error+20;
	      break;
	    }
	  if ((d_output[i] - d_true_vector[i]) > 0.0000001)
	    {
	      error=error+110;
	      break;
	    }
	  if ((d_output_err2[i] - d_true_vector_err2[i])>0.0000001)
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

  cout << "sub_scalar_vec_ncerr.cpp..........";
  
  switch (error)
    {
    case 0:
      cout << "Functionality OK"<<endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes"<<endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector"
	" expected"<<endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    case 210:
      cout << "(int) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 220:
      cout << "(int) FAILED....Output error vector different from vector"
	" expected"<<endl;
      break;
    case 310:
      cout << "(unsigned) FAILED....Output vector different from vector"
	" expected"
	   <<endl;
      break;
    case 320:
      cout << "(unsigned) FAILED....Output error vector different from vector"
	"expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}

