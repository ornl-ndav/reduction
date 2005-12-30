// $Id: $

#include "arith.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
  int num_val = 20;

  //float
  float f_scalar = 5.0;
  float f_scalar_err2 = 3.0;
  Nessi::Vector<float> f_input;                       //Original vector
  Nessi::Vector<float> f_input_err2;                  //Original vector err
  Nessi::Vector<float> f_input1;                      //Original vector 1
  Nessi::Vector<float> f_input1_err2;                 //Original vector 1 err
  Nessi::Vector<float> f_input2;                      //Original vector 2
  Nessi::Vector<float> f_input2_err2;                 //Original vector 2 err
  Nessi::Vector<float> f_output(num_val);             //Output vector
  Nessi::Vector<float> f_output_err2(num_val);        //Output vector err
  Nessi::Vector<float> f_y(num_val);                  //Output vector
  Nessi::Vector<float> f_y_err2(num_val);             //Output vector err
  Nessi::Vector<float> f_true_vector;                 //True vector
  Nessi::Vector<float> f_true_vector_err2;            //True vector err

  //double 
  double d_scalar = 5;
  double d_scalar_err2 = 3;
  Nessi::Vector<double> d_input;
  Nessi::Vector<double> d_input_err2;
  Nessi::Vector<double> d_input1;
  Nessi::Vector<double> d_input1_err2;
  Nessi::Vector<double> d_input2;
  Nessi::Vector<double> d_input2_err2;
  Nessi::Vector<double> d_output(num_val);
  Nessi::Vector<double> d_output_err2(num_val);
  Nessi::Vector<double> d_y(num_val);
  Nessi::Vector<double> d_y_err2(num_val);
  Nessi::Vector<double> d_true_vector;
  Nessi::Vector<double> d_true_vector_err2;

  //int 
  int i_scalar = 5;
  int i_scalar_err2 = 3;
  Nessi::Vector<int> i_input;
  Nessi::Vector<int> i_input_err2;
  Nessi::Vector<int> i_input1;
  Nessi::Vector<int> i_input1_err2;
  Nessi::Vector<int> i_input2;
  Nessi::Vector<int> i_input2_err2;
  Nessi::Vector<int> i_output(num_val);
  Nessi::Vector<int> i_output_err2(num_val);
  Nessi::Vector<int> i_y(num_val);
  Nessi::Vector<int> i_y_err2(num_val);
  Nessi::Vector<int> i_true_vector;
  Nessi::Vector<int> i_true_vector_err2;
  
  //unsigned 
  unsigned u_scalar = 5;
  unsigned u_scalar_err2 = 3;
  Nessi::Vector<unsigned> u_input;
  Nessi::Vector<unsigned> u_input_err2;
  Nessi::Vector<unsigned> u_input1;
  Nessi::Vector<unsigned> u_input1_err2;
  Nessi::Vector<unsigned> u_input2;
  Nessi::Vector<unsigned> u_input2_err2;
  Nessi::Vector<unsigned> u_output(num_val);
  Nessi::Vector<unsigned> u_output_err2(num_val);
  Nessi::Vector<unsigned> u_y(num_val);
  Nessi::Vector<unsigned> u_y_err2(num_val);
  Nessi::Vector<unsigned> u_true_vector;
  Nessi::Vector<unsigned> u_true_vector_err2;

  int error1=0;                      //==0,Pass  !=0,Fail
  int error2=0;                      //==0,Pass  !=0,Fail

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
 
  // case 1 - vector*scalar

  ArrayManip::mult_ncerr(f_input, f_input_err2, f_scalar, f_scalar_err2,
                         f_y, f_y_err2);

  ArrayManip::mult_ncerr(d_input, d_input_err2, d_scalar, d_scalar_err2,
                         d_y, d_y_err2);
  
  ArrayManip::mult_ncerr(i_input, i_input_err2, i_scalar, i_scalar_err2,
                         i_y, i_y_err2);

  ArrayManip::mult_ncerr(u_input, u_input_err2, u_scalar, u_scalar_err2,
                         u_y, u_y_err2);
  
  for (int i = 0 ; i < num_val ; ++i)
    {
      f_true_vector.push_back(f_input[i]*f_scalar);
      d_true_vector.push_back(d_input[i]*d_scalar);
      i_true_vector.push_back(i_input[i]*i_scalar);
      u_true_vector.push_back(u_input[i]*u_scalar);

      f_true_vector_err2.push_back(((f_scalar*f_scalar)*f_input_err2[i])+
				   ((f_input[i]*f_input[i])*f_scalar_err2));
      d_true_vector_err2.push_back(((d_scalar*d_scalar)*d_input_err2[i])+
				   ((d_input[i]*d_input[i])*d_scalar_err2));
      i_true_vector_err2.push_back(((i_scalar*i_scalar)*i_input_err2[i])+
				   ((i_input[i]*i_input[i])*i_scalar_err2));
      u_true_vector_err2.push_back(((u_scalar*u_scalar)*u_input_err2[i])+
				   ((u_input[i]*u_input[i])*u_scalar_err2));
    }

  //check first the size
  if ( (f_input.size() != f_y.size())
       || (d_input.size() != d_y.size())
       || (i_input.size() != i_y.size())
       || (u_input.size() != u_y.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error1;
    }
  else
    {
      for (int i = 0 ; i < num_val ; ++i )
	{
	  if (fabs(f_y[i] - f_true_vector[i])>0.0000001)
	    {
	      error1=error1+10;
	      break;
	    }
	  if (fabs(f_y_err2[i] - f_true_vector_err2[i])>0.0000001)
	    {
	      error1=error1+20;
	      break;
	    }
	  if ((d_y[i] - d_true_vector[i]) > 0.0000001)
	    {
	      error1=error1+110;
	      break;
	    }
	  if ((d_y_err2[i] - d_true_vector_err2[i])>0.0000001)
	    {
	      error1=error1+120;
	      break;
	    }
	  if (i_y[i] != i_true_vector[i])
	    {
	      error1=error1+210;
	      break;
	    }
	  if (i_y_err2[i] != i_true_vector_err2[i])
	    {
	      error1=error1+220;
	      break;
	    }
	  if (u_y[i] != u_true_vector[i])
	    {
	      error1=error1+310;
	      break;
	    }
	  if (u_y_err2[i] != u_true_vector_err2[i])
	    {
	      error1=error1+320;
	      break;
	    }
	}
    }

  for(int i = 0 ; i < num_val ; ++i)            //create the arrays
    {
      //_input1 array
      f_input1.push_back(2.*static_cast<float>(i));
      d_input1.push_back(2.*static_cast<double>(i)); 
      i_input1.push_back(2*static_cast<int>(i));
      u_input1.push_back(2*static_cast<unsigned int>(i));

      f_input1_err2.push_back(static_cast<float>(i));
      d_input1_err2.push_back(static_cast<double>(i));      
      i_input1_err2.push_back(static_cast<int>(i));
      u_input1_err2.push_back(static_cast<unsigned int>(i));
      
      //_input2 array
      f_input2.push_back(4.*static_cast<float>(i));
      d_input2.push_back(4.*static_cast<double>(i)); 
      i_input2.push_back(4*static_cast<int>(i));
      u_input2.push_back(4*static_cast<unsigned int>(i));

      f_input2_err2.push_back(static_cast<float>(i+5));
      d_input2_err2.push_back(static_cast<double>(i+5));      
      i_input2_err2.push_back(static_cast<int>(i+5));
      u_input2_err2.push_back(static_cast<unsigned int>(i+5));

    }
  
  // case 2 - vector*vector

  ArrayManip::mult_ncerr(f_input1, f_input1_err2, f_input2, f_input2_err2,
                         f_output, f_output_err2);

  ArrayManip::mult_ncerr(d_input1, d_input1_err2, d_input2, d_input2_err2,
                         d_output, d_output_err2);

  ArrayManip::mult_ncerr(i_input1, i_input1_err2, i_input2, i_input2_err2,
                         i_output, i_output_err2);

  ArrayManip::mult_ncerr(u_input1, u_input1_err2, u_input2, u_input2_err2,
                         u_output, u_output_err2);
  
  for (int i = 0 ; i < num_val ; ++i)
    {
      std::transform(f_input1.begin(), f_input1.end(), f_input2.begin(), 
		     f_true_vector.begin(),std::multiplies<float>());

      std::transform(d_input1.begin(), d_input1.end(), d_input2.begin(), 
		     d_true_vector.begin(),std::multiplies<double>());

      std::transform(i_input1.begin(), i_input1.end(), i_input2.begin(), 
		     i_true_vector.begin(),std::multiplies<int>());

      std::transform(u_input1.begin(), u_input1.end(), u_input2.begin(), 
		     u_true_vector.begin(),std::multiplies<unsigned>());

      f_true_vector_err2[i] = (f_input2[i] * f_input2[i] * f_input1_err2[i]) +
	(f_input1[i] * f_input1[i] * f_input2_err2[i]);
      d_true_vector_err2[i] = (d_input2[i] * d_input2[i] * d_input1_err2[i]) +
	(d_input1[i] * d_input1[i] * d_input2_err2[i]);
      i_true_vector_err2[i] = (i_input2[i] * i_input2[i] * i_input1_err2[i]) +
	(i_input1[i] * i_input1[i] * i_input2_err2[i]);
      u_true_vector_err2[i] = (u_input2[i] * u_input2[i] * u_input1_err2[i]) +
	(u_input1[i] * u_input1[i] * u_input2_err2[i]);
      
    }
  
  //check first if the size are in good agreement
  if ( (f_input1.size() != f_output.size())
       || (d_input1.size() != d_output.size())
       || (i_input1.size() != i_output.size())
       || (u_input1.size() != u_output.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error2;
    }
  else
    {
      for (int i = 0 ; i < num_val ; ++i)
	{
	  if (fabs(f_output[i] - f_true_vector[i])>0.000001)
	    {
	      error2=error2+10;
	      break;
	    }
	  if (fabs(f_output_err2[i] - f_true_vector_err2[i])>0.000001)
	    {
	      error2=error2+20;
	      break;
	    }
	  if (fabs(d_output[i] - d_true_vector[i]) > 0.000001)
	    {
	      error2=error2+110;
	      break;
	    }
	  if (fabs(d_output_err2[i] - d_true_vector_err2[i])> 0.000001)
	    {
	      error2=error2+120;
	      break;
	    }
	  if (i_output[i] != i_true_vector[i])
	    {
	      error2=error2+210;
	      break;
	    }
	  if (i_output_err2[i] != i_true_vector_err2[i])
	    {
	      error2=error2+220;
	      break;
	    }
	  if (u_output[i] != u_true_vector[i])
	    {
	      error2=error2+310;
	      break;
	    }
	  if (u_output_err2[i] != u_true_vector_err2[i])
	    {
	      error2=error2+320;
	      break;
	    }
	}
    }

  cout << "mult_ncerr.cpp..........";

  switch (error1)
    {
    case 0:
      break;
    case 1:
      cout << "(v,s) FAILED....Outut and input vectors have different sizes"
           << endl;
      break;
    case 10:
      cout << "(float v,s) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 20:
      cout << "(float v,s) FAILED....Output error vector different from "
           << "vector expected" << endl;
      break;
    case 110:
      cout << "(double v,s) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 120:
      cout << "(double v,s) FAILED....Output error vector different from "
           << "vector expected" << endl;
      break;
    case 210:
      cout << "(int v,s) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 220:
      cout << "(int v,s) FAILED....Output error vector different from vector"
           << "expected" << endl;
      break;
    case 310:
      cout << "(unsigned v,s) FAILED....Output vector different from vector"
           << " expected" << endl;
      break;
    case 320:
      cout << "(unsigned v,s) FAILED....Output error vector different from"
           << " vector expected" << endl;
      break;
    default:
      cout << "(v,s) FAILED" << endl;
      break;
    }

  if(error1)
    {
      return -1;
    }

  switch (error2)
    {
    case 0:
      break;
    case 1:
      cout << "(v,v) FAILED....Outut and input vectors have different sizes"
           << endl;
      break;
    case 10:
      cout << "(float v,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 20:
      cout << "(float v,v) FAILED....Output error vector different from vector"
           << " expected" << endl;
      break;
    case 110:
      cout << "(double v,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 120:
      cout << "(double v,v) FAILED....Output error vector different from "
           << "vector expected" << endl;
      break;
    case 210:
      cout << "(int v,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 220:
      cout << "(int v,v) FAILED....Output error vector different from vector"
           << " expected" << endl;
      break;
    case 310:
      cout << "(unsigned v,v) FAILED....Output vector different from vector"
           << " expected" << endl;
      break;
    case 320:
      cout << "(unsigned v,v) FAILED....Output error vector different from"
           << "vector expected" << endl;
      break;
    default:
      cout << "(v,v) FAILED" << endl;
      break;
    }

  if(error2)
    {
      return -1;
    }

  cout << "Functionality OK" << endl;
  return 0;
}

