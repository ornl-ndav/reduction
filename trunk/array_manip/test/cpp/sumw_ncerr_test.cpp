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
  Nessi::Vector<float> f_input1;                      //Original vector 1
  Nessi::Vector<float> f_input1_err2;                 //Original vector 1 err
  Nessi::Vector<float> f_input2;                      //Original vector 2
  Nessi::Vector<float> f_input2_err2;                 //Original vector 2 err
  Nessi::Vector<float> f_output(num_val);             //Output vector
  Nessi::Vector<float> f_output_err2(num_val);        //Output vector err
  Nessi::Vector<float> f_true_vector(num_val);        //True output vector
  Nessi::Vector<float> f_true_vector_err2(num_val);   //True output vector err
  float f_input1_err;
  float f_input2_err;
  float f_sum_err;

  //double 
  Nessi::Vector<double> d_input1;                      //Original vector 1
  Nessi::Vector<double> d_input1_err2;                 //Original vector 1 err
  Nessi::Vector<double> d_input2;                      //Original vector 2
  Nessi::Vector<double> d_input2_err2;                 //Original vector 2 err
  Nessi::Vector<double> d_output(num_val);             //Output vector
  Nessi::Vector<double> d_output_err2(num_val);        //Output vector err
  Nessi::Vector<double> d_true_vector(num_val);        //True output vector
  Nessi::Vector<double> d_true_vector_err2(num_val);   //True output vector err
  float d_input1_err;
  float d_input2_err;
  float d_sum_err;

  //int 
  Nessi::Vector<int> i_input1;                         //Original vector 1
  Nessi::Vector<int> i_input1_err2;                    //Original vector 1 err
  Nessi::Vector<int> i_input2;                         //Original vector 2
  Nessi::Vector<int> i_input2_err2;                    //Original vector 2 err
  Nessi::Vector<int> i_output(num_val);                //Output vector
  Nessi::Vector<int> i_output_err2(num_val);           //Output vector err
  Nessi::Vector<int> i_true_vector(num_val);           //True output vector
  Nessi::Vector<int> i_true_vector_err2(num_val);      //True output vector err
  float i_input1_err;
  float i_input2_err;
  float i_sum_err;

  //unsigned 
  Nessi::Vector<unsigned> u_input1;                    //Original vector 1
  Nessi::Vector<unsigned> u_input1_err2;               //Original vector 1 err
  Nessi::Vector<unsigned> u_input2;                    //Original vector 2
  Nessi::Vector<unsigned> u_input2_err2;               //Original vector 2 err
  Nessi::Vector<unsigned> u_output(num_val);           //Output vector
  Nessi::Vector<unsigned> u_output_err2(num_val);      //Output vector err
  Nessi::Vector<unsigned> u_true_vector(num_val);      //True output vector
  Nessi::Vector<unsigned> u_true_vector_err2(num_val); //True output vector err
  float u_input1_err;
  float u_input2_err;
  float u_sum_err;

  int error=0;                      //==0,Pass  !=0,Fail

  for (int i = 0 ; i < num_val ; ++i)            //create the arrays
    {
      //_input1 array
      f_input1.push_back(2.*static_cast<float>(i));
      d_input1.push_back(2.*static_cast<double>(i)); 
      i_input1.push_back(2*static_cast<int>(i));
      u_input1.push_back(2*static_cast<unsigned int>(i));

      f_input1_err2.push_back(static_cast<float>(i));
      d_input1_err2.push_back(static_cast<double>(i));      
      i_input1_err2.push_back(static_cast<int>(i+1));
      u_input1_err2.push_back(static_cast<unsigned int>(i+1));
      
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
  
  ArrayManip::sumw_ncerr(f_input1, f_input1_err2, f_input2, 
                         f_input2_err2, f_output, f_output_err2);

  ArrayManip::sumw_ncerr(d_input1, d_input1_err2, d_input2, 
                         d_input2_err2, d_output, d_output_err2);

  ArrayManip::sumw_ncerr(i_input1, i_input1_err2, i_input2, 
                         i_input2_err2, i_output, i_output_err2);

  ArrayManip::sumw_ncerr(u_input1, u_input1_err2, u_input2, 
                         u_input2_err2, u_output, u_output_err2);
  
  for (int i = 0 ; i < num_val ; ++i)
    {
      //float
      f_input1_err = static_cast<float>(std::sqrt(static_cast<double>
												  (f_input1_err2[i])));
      f_input2_err = static_cast<float>(std::sqrt(static_cast<double>
												  (f_input2_err2[i])));
      f_sum_err = f_input1_err + f_input2_err;
      f_true_vector[i] = (f_input1[i] / f_input1_err) + 
		(f_input2[i] / f_input2_err);
      f_true_vector[i] *= f_sum_err;
      f_true_vector_err2[i] = f_input1_err2[i] + f_input2_err2[i];
      
      //double
      d_input1_err = static_cast<double>(std::sqrt(static_cast<double>
												   (d_input1_err2[i])));
      d_input2_err = static_cast<double>(std::sqrt(static_cast<double>
												   (d_input2_err2[i])));
      d_sum_err = d_input1_err + d_input2_err;
      d_true_vector[i] = (d_input1[i] / d_input1_err) +
		(d_input2[i] / d_input2_err);
      d_true_vector[i] *= d_sum_err;
      d_true_vector_err2[i] = d_input1_err2[i] + d_input2_err2[i];
      
      //int
      i_input1_err = static_cast<int>(std::sqrt(static_cast<double>
												(i_input1_err2[i])));
      i_input2_err = static_cast<int>(std::sqrt(static_cast<double>
												(i_input2_err2[i])));
      i_sum_err = static_cast<int>(i_input1_err + i_input2_err);
      i_true_vector[i] = static_cast<int>(i_input1[i] / i_input1_err) + 
		static_cast<int>(i_input2[i] / i_input2_err);
      i_true_vector[i] *= static_cast<int>(i_sum_err);
      i_true_vector_err2[i] = i_input1_err2[i] + i_input2_err2[i];
	  
      //unsigned
      u_input1_err = static_cast<unsigned>(std::sqrt(static_cast<double>
													 (u_input1_err2[i])));
      u_input2_err = static_cast<unsigned>(std::sqrt(static_cast<double>
													 (u_input2_err2[i])));
      u_sum_err = static_cast<unsigned>(u_input1_err + u_input2_err);
      u_true_vector[i] = static_cast<unsigned>(u_input1[i] / u_input1_err) + 
		static_cast<unsigned>(u_input2[i] / u_input2_err);
      u_true_vector[i] *= static_cast<unsigned>(u_sum_err);
      u_true_vector_err2[i] = u_input1_err2[i] + u_input2_err2[i];
    }
  
  //check first if the size are in good agreement
  if ( (f_input1.size() != f_output.size())
       || (d_input1.size() != d_output.size())
       || (i_input1.size() != i_output.size())
       || (u_input1.size() != u_output.size()) )
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
	  while(1)
		{
		  Utils::vector_comparison(f_output, f_true_vector, error, 10);
		  if (error != 0) break;
		  Utils::vector_comparison(f_output_err2, f_true_vector_err2, 
								   error, 20);
		  if (error != 0) break;

		  Utils::vector_comparison(d_output, d_true_vector, error, 110);
		  if (error != 0) break;
		  Utils::vector_comparison(d_output_err2, d_true_vector_err2, 
								   error, 120);
		  if (error != 0) break;

		  Utils::vector_comparison(i_output, i_true_vector, error, 210);
		  if (error != 0) break;
		  Utils::vector_comparison(i_output_err2, i_true_vector_err2, 
								   error, 220);
		  if (error != 0) break;

		  Utils::vector_comparison(u_output, u_true_vector, error, 310);
		  if (error != 0) break;
		  Utils::vector_comparison(u_output_err2, u_true_vector_err2, 
								   error, 320);
		  break;
		}
	}

  cout << "sumw_ncerr_test.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK"<<endl;
      break;
    case 1:
      cout << "FAILED....Outut and input vectors have different sizes"<<endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector"
	" expected"<<endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector"
	" expected"<<endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector"
	" expected"<<endl;
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
      cout << "(int) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    case 310:
      cout << "(unsigned) FAILED....Output vector different from vector "
	"expected"<<endl;
      break;
    case 320:
      cout << "(unsigned) FAILED....Output error vector different from "
	"vector expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}
