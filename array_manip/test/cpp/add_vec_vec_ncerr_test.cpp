#include "nessi.hpp"
#include "vec_vec_arith.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

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

  //double 
  Nessi::Vector<double> d_input1;                      //Original vector 1
  Nessi::Vector<double> d_input1_err2;                 //Original vector 1 err
  Nessi::Vector<double> d_input2;                      //Original vector 2
  Nessi::Vector<double> d_input2_err2;                 //Original vector 2 err
  Nessi::Vector<double> d_output(num_val);             //Output vector
  Nessi::Vector<double> d_output_err2(num_val);        //Output vector err
  Nessi::Vector<double> d_true_vector(num_val);        //True output vector
  Nessi::Vector<double> d_true_vector_err2(num_val);   //True output vector err

  //int 
  Nessi::Vector<int> i_input1;                         //Original vector 1
  Nessi::Vector<int> i_input1_err2;                    //Original vector 1 err
  Nessi::Vector<int> i_input2;                         //Original vector 2
  Nessi::Vector<int> i_input2_err2;                    //Original vector 2 err
  Nessi::Vector<int> i_output(num_val);                //Output vector
  Nessi::Vector<int> i_output_err2(num_val);           //Output vector err
  Nessi::Vector<int> i_true_vector(num_val);           //True output vector
  Nessi::Vector<int> i_true_vector_err2(num_val);      //True output vector err

  //unsigned 
  Nessi::Vector<unsigned> u_input1;                    //Original vector 1
  Nessi::Vector<unsigned> u_input1_err2;               //Original vector 1 err
  Nessi::Vector<unsigned> u_input2;                    //Original vector 2
  Nessi::Vector<unsigned> u_input2_err2;               //Original vector 2 err
  Nessi::Vector<unsigned> u_output(num_val);           //Output vector
  Nessi::Vector<unsigned> u_output_err2(num_val);      //Output vector err
  Nessi::Vector<unsigned> u_true_vector(num_val);      //True output vector
  Nessi::Vector<unsigned> u_true_vector_err2(num_val); //True output vector err

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
      i_input1_err2.push_back(static_cast<int>(i));
      u_input1_err2.push_back(static_cast<unsigned int>(i));
      
      //_input2 array
      f_input2.push_back(4.*static_cast<float>(i));
      d_input2.push_back(4.*static_cast<double>(i)); 
      i_input2.push_back(4*static_cast<int>(i));
      u_input2.push_back(4*static_cast<unsigned int>(i));

      f_input2_err2.push_back(static_cast<float>(i)+5.);
      d_input2_err2.push_back(static_cast<double>(i)+5.);      
      i_input2_err2.push_back(static_cast<int>(i+5));
      u_input2_err2.push_back(static_cast<unsigned int>(i+5));

    }
  
  ArrayManip::add_vec_vec_ncerr(f_input1, f_input1_err2, f_input2,
				f_input2_err2, f_output, f_output_err2);

  ArrayManip::add_vec_vec_ncerr(d_input1, d_input1_err2, d_input2, 
				d_input2_err2, d_output, d_output_err2);

  ArrayManip::add_vec_vec_ncerr(i_input1, i_input1_err2, i_input2, 
				i_input2_err2, i_output, i_output_err2);

  ArrayManip::add_vec_vec_ncerr(u_input1, u_input1_err2, u_input2, 
				u_input2_err2, u_output, u_output_err2);
  
  for (int i = 0 ; i < num_val ; i++)
    {
      transform(f_input1.begin(), f_input1.end(), f_input2.begin(), 
		     f_true_vector.begin(),plus<float>());

      transform(d_input1.begin(), d_input1.end(), d_input2.begin(), 
		     d_true_vector.begin(),plus<double>());

      transform(i_input1.begin(), i_input1.end(), i_input2.begin(), 
		     i_true_vector.begin(),plus<int>());

      transform(u_input1.begin(), u_input1.end(), u_input2.begin(), 
		     u_true_vector.begin(),plus<unsigned>());


      transform(f_input1_err2.begin(), f_input1_err2.end(), 
		     f_input2_err2.begin(), f_true_vector_err2.begin(),
		     plus<float>());

      transform(d_input1_err2.begin(), d_input1_err2.end(), 
		     d_input2_err2.begin(), d_true_vector_err2.begin(),
		     plus<double>());

      transform(i_input1_err2.begin(), i_input1_err2.end(), 
		     i_input2_err2.begin(), i_true_vector_err2.begin(),
		     plus<int>());

      transform(u_input1_err2.begin(), u_input1_err2.end(),
		     u_input2_err2.begin(), u_true_vector_err2.begin(),
		     plus<unsigned>());
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
      for (int i = 0 ; i < num_val ; ++i)
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
	  if (fabs(d_output_err2[i] - d_true_vector_err2[i])> 0.000001)
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

  cout << "add_vec_vec_ncerr.cpp..........";

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
      cout << "(float) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector"
	" expected"<<endl;
      break;
    case 210:
      cout << "(int) FAILED....Output vector different from vector expected"
	   <<endl;
      break;
    case 220:
      cout << "(int) FAILED....Output error vector different from vector"
	"expected"<<endl;
      break;
    case 310:
      cout << "(unsigned) FAILED....Output vector different from vector "
	"expected"<<endl;
      break;
    case 320:
      cout << "(unsigned) FAILED....Output error vector different from vector "
	"expected"<<endl;
      break;
    default:
      cout << "FAILED"<<endl;
      break;
    }

  return 0;
}

