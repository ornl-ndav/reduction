// $Id$

#include "arith.hpp"
#include "num_comparison.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
  int num_val = 20;

  //float
  float f_scalar = 5.0;
  float f_scalar_err2 = 1.0;
  Nessi::Vector<float> f_input;                       //Original vector
  Nessi::Vector<float> f_input_err2;                  //Original vector err
  Nessi::Vector<float> f_input1;                      //Original vector 1
  Nessi::Vector<float> f_input1_err2;                 //Original vector 1 err
  Nessi::Vector<float> f_input2;                      //Original vector 2
  Nessi::Vector<float> f_input2_err2;                 //Original vector 2 err
  Nessi::Vector<float> f_output(num_val);             //Output vector
  Nessi::Vector<float> f_output_err2(num_val);        //Output vector err
  Nessi::Vector<float> f_true_vector;                 //True vector
  Nessi::Vector<float> f_true_vector_err2;            //True vector err

  //double 
  double d_scalar = 5;
  double d_scalar_err2 = 1;
  Nessi::Vector<double> d_input;
  Nessi::Vector<double> d_input_err2;
  Nessi::Vector<double> d_input1;
  Nessi::Vector<double> d_input1_err2;
  Nessi::Vector<double> d_input2;
  Nessi::Vector<double> d_input2_err2;
  Nessi::Vector<double> d_output(num_val);
  Nessi::Vector<double> d_output_err2(num_val);
  Nessi::Vector<double> d_true_vector;
  Nessi::Vector<double> d_true_vector_err2;

  //int 
  int i_scalar = 5;
  int i_scalar_err2 = 1;
  Nessi::Vector<int> i_input;
  Nessi::Vector<int> i_input_err2;
  Nessi::Vector<int> i_input1;
  Nessi::Vector<int> i_input1_err2;
  Nessi::Vector<int> i_input2;
  Nessi::Vector<int> i_input2_err2;
  Nessi::Vector<int> i_output(num_val);
  Nessi::Vector<int> i_output_err2(num_val);
  Nessi::Vector<int> i_true_vector;
  Nessi::Vector<int> i_true_vector_err2;
  
  //unsigned 
  unsigned u_scalar = 5;
  unsigned u_scalar_err2 = 1;
  Nessi::Vector<unsigned> u_input;
  Nessi::Vector<unsigned> u_input_err2;
  Nessi::Vector<unsigned> u_input1;
  Nessi::Vector<unsigned> u_input1_err2;
  Nessi::Vector<unsigned> u_input2;
  Nessi::Vector<unsigned> u_input2_err2;
  Nessi::Vector<unsigned> u_output(num_val);
  Nessi::Vector<unsigned> u_output_err2(num_val);
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
 
  // case 1 - vector-scalar

  ArrayManip::sub_ncerr(f_input, f_input_err2, f_scalar, f_scalar_err2,
                        f_output, f_output_err2);

  ArrayManip::sub_ncerr(d_input, d_input_err2, d_scalar, d_scalar_err2,
                        d_output, d_output_err2);
				   

  ArrayManip::sub_ncerr(i_input, i_input_err2, i_scalar, i_scalar_err2,
                        i_output, i_output_err2);

  ArrayManip::sub_ncerr(u_input, u_input_err2, u_scalar, u_scalar_err2,
                        u_output, u_output_err2);
				   
  
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
      cout << "(v,s) Input and output vectors do not have the same size" 
		   << endl;
      ++error1;
    }
  else
    {
	  while(1)
		{
		  Utils::vector_comparison(f_output, f_true_vector, error1, 10);
		  if (error1 != 0) break;
		  Utils::vector_comparison(f_output_err2, f_true_vector_err2, 
								   error1, 20);
		  if (error1 != 0) break;
		  
		  Utils::vector_comparison(d_output, d_true_vector, error1, 110);
		  if (error1 != 0) break;
		  Utils::vector_comparison(d_output_err2, d_true_vector_err2, 
								   error1, 120);
		  if (error1 != 0) break;
		  
		  Utils::vector_comparison(i_output, i_true_vector, error1, 210);
		  if (error1 != 0) break;
		  Utils::vector_comparison(i_output_err2, i_true_vector_err2, 
								   error1, 220);
		  if (error1 != 0) break;

		  Utils::vector_comparison(u_output, u_true_vector, error1, 310);
		  if (error1 != 0) break;
		  Utils::vector_comparison(u_output_err2, u_true_vector_err2, 
								   error1, 320);
		  break;
		}
	}

  for (int i = 0 ; i < num_val ; ++i)            //create the arrays
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
  
  // case 2 - vector-vector

  ArrayManip::sub_ncerr(f_input1, f_input1_err2, f_input2, 
                        f_input2_err2, f_output, f_output_err2);

  ArrayManip::sub_ncerr(d_input1, d_input1_err2, d_input2, 
                        d_input2_err2, d_output, d_output_err2);
  
  ArrayManip::sub_ncerr(i_input1, i_input1_err2, i_input2, 
                        i_input2_err2, i_output, i_output_err2);
  
  ArrayManip::sub_ncerr(u_input1, u_input1_err2, u_input2, 
                        u_input2_err2, u_output, u_output_err2);
  
  for (int i = 0 ; i < num_val ; ++i)
    {
      std::transform(f_input1.begin(), f_input1.end(), f_input2.begin(), 
		     f_true_vector.begin(),std::minus<float>());

      std::transform(d_input1.begin(), d_input1.end(), d_input2.begin(), 
		     d_true_vector.begin(),std::minus<double>());

      std::transform(i_input1.begin(), i_input1.end(), i_input2.begin(), 
		     i_true_vector.begin(),std::minus<int>());

      std::transform(u_input1.begin(), u_input1.end(), u_input2.begin(), 
		     u_true_vector.begin(),std::minus<unsigned>());


      std::transform(f_input1_err2.begin(), f_input1_err2.end(), 
		     f_input2_err2.begin(), f_true_vector_err2.begin(), 
		     std::plus<float>());

      std::transform(d_input1_err2.begin(), d_input1_err2.end(), 
		     d_input2_err2.begin(), d_true_vector_err2.begin(), 
		     std::plus<double>());

      std::transform(i_input1_err2.begin(), i_input1_err2.end(), 
		     i_input2_err2.begin(), i_true_vector_err2.begin(), 
		     std::plus<int>());

      std::transform(u_input1_err2.begin(), u_input1_err2.end(), 
		     u_input2_err2.begin(), u_true_vector_err2.begin(), 
		     std::plus<unsigned>());
    }
  
  //check first if the size are in good agreement
  if ( (f_input1.size() != f_output.size())
       || (d_input1.size() != d_output.size())
       || (i_input1.size() != i_output.size())
       || (u_input1.size() != u_output.size()) )
    {
      cout << "(v,v) Input and output vectors do not have the same size" 
		   << endl;
      ++error2;
    }
  else
    {
	  while(1)
		{
		  Utils::vector_comparison(f_output, f_true_vector, error2, 10);
		  if (error2 != 0) break;
		  Utils::vector_comparison(f_output_err2, f_true_vector_err2, 
								   error2, 20);
		  if (error2 != 0) break;

		  Utils::vector_comparison(d_output, d_true_vector, error2, 110);
		  if (error2 != 0) break;
		  Utils::vector_comparison(d_output_err2, d_true_vector_err2, 
								   error2, 120);
		  if (error2 != 0) break;

		  Utils::vector_comparison(i_output, i_true_vector, error2, 210);
		  if (error2 != 0) break;
		  Utils::vector_comparison(i_output_err2, i_true_vector_err2, 
								   error2, 220);
		  if (error2 != 0) break;

		  Utils::vector_comparison(u_output, u_true_vector, error2, 310);
		  if (error2 != 0) break;
		  Utils::vector_comparison(u_output_err2, u_true_vector_err2, 
								   error2, 320);
		  break;
		}
    }
  
  cout << "sub_ncerr_test.cpp..........";
  
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
      cout << "(float v,s) FAILED....Output error vector different from vector"
           << " expected" << endl;
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
           << " expected" << endl;
      break;
    case 310:
      cout << "(unsigned v,s) FAILED....Output vector different from vector"
           << " expected" << endl;
      break;
    case 320:
      cout << "(unsigned v,s) FAILED....Output error vector different from "
           << "vector expected" << endl;
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
      cout << "(v,v) FAILED....Output and input vectors have different sizes"
           << endl;
      break;
    case 10:
      cout << "(float v,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 20:
      cout << "(float v,v) FAILED....Output error vector different from vector"
           << "expected" << endl;
      break;
    case 110:
      cout << "(double v,v) FAILED....Output vector different from vector"
           << " expected" << endl;
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
      cout << "(int v,v) FAILED....Output error vector different from vector "
           << "expected" << endl;
      break;
    case 310:
      cout << "(unsigned v,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 320:
      cout << "(unsigned v,v) FAILED....Output error vector different from "
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

