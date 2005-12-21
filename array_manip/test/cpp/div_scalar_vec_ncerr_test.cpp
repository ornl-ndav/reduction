// $Id$

#include "nessi.hpp"
#include "vec_scalar_arith.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  int n = 20;
  float f_a = 5.0;
  float f_a_err2 = 3.0;
  float f_a_2;
  Nessi::Vector<float> f_x;                   //Original vector
  Nessi::Vector<float> f_x_err2;              //Original vector err
  Nessi::Vector<float> f_y(n);                //Output vector
  Nessi::Vector<float> f_y_err2(n);           //Output vector err
  Nessi::Vector<float> f_true_vector;         //True vector
  Nessi::Vector<float> f_true_vector_err2(n); //True vector err

  double d_a = 5;
  double d_a_err2 = 3;
  double d_a_2;
  Nessi::Vector<double> d_x;
  Nessi::Vector<double> d_x_err2;
  Nessi::Vector<double> d_y(n);
  Nessi::Vector<double> d_y_err2(n);
  Nessi::Vector<double> d_true_vector;
  Nessi::Vector<double> d_true_vector_err2(n);

  int i_a = 5;
  int i_a_err2 = 3;
  int i_a_2;
  Nessi::Vector<int> i_x;
  Nessi::Vector<int> i_x_err2;
  Nessi::Vector<int> i_y(n);
  Nessi::Vector<int> i_y_err2(n);
  Nessi::Vector<int> i_true_vector;
  Nessi::Vector<int> i_true_vector_err2(n);
  
  unsigned u_a = 5;
  unsigned u_a_err2 = 3;
  unsigned u_a_2;
  Nessi::Vector<unsigned> u_x;
  Nessi::Vector<unsigned> u_x_err2;
  Nessi::Vector<unsigned> u_y(n);
  Nessi::Vector<unsigned> u_y_err2(n);
  Nessi::Vector<unsigned> u_true_vector;
  Nessi::Vector<unsigned> u_true_vector_err2(n);
  
  int error=0;                      //==0,Pass  !=0,Fail

  for(int i=0; i<n; i++)
    {
      f_x.push_back(2.*(float)i+1);
      d_x.push_back(2*(double)i+1); 
      i_x.push_back(2*(int)i+1);
      u_x.push_back(2*(unsigned)i+1);

      f_x_err2.push_back((float)i+1);
      d_x_err2.push_back((double)i+1);      
      i_x_err2.push_back((int)i+1);
      u_x_err2.push_back((unsigned)i+1);
    }
 
  ArrayManip::div_scalar_vec_ncerr(f_x, f_x_err2, 
				   f_y, f_y_err2, 
				   f_a, f_a_err2);

  ArrayManip::div_scalar_vec_ncerr(d_x, d_x_err2, 
				   d_y, d_y_err2, 
				   d_a, d_a_err2);

  ArrayManip::div_scalar_vec_ncerr(i_x, i_x_err2, 
				   i_y, i_y_err2, 
				   i_a, i_a_err2);

  ArrayManip::div_scalar_vec_ncerr(u_x, u_x_err2, 
				   u_y, u_y_err2, 
				   u_a, u_a_err2);

  for (int i=0; i<n; i++)
    {
      f_true_vector.push_back(f_a / f_x[i]);
      d_true_vector.push_back(d_a/d_x[i]);
      i_true_vector.push_back(i_a/i_x[i]);
      u_true_vector.push_back(u_a/u_x[i]);

      f_a_2 = f_x[i]*f_x[i];
      f_true_vector_err2[i] = (((f_a*f_a)/(f_a_2*f_a_2)) * 
			       f_x_err2[i])+(f_a_err2/f_a_2);

      d_a_2 = d_x[i]*d_x[i];
      d_true_vector_err2[i] = (((d_a*d_a)/(d_a_2*d_a_2)) * 
			       d_x_err2[i])+(d_a_err2/d_a_2);

      i_a_2 = i_x[i]*i_x[i];
      i_true_vector_err2[i] = (((i_a*i_a)/(i_a_2*i_a_2)) * 
			       i_x_err2[i])+(i_a_err2/i_a_2);

      u_a_2 = u_x[i]*u_x[i];
      u_true_vector_err2[i] = (((u_a*u_a)/(u_a_2*u_a_2)) * 
			       u_x_err2[i])+(u_a_err2/u_a_2);
    }

  //check first the size
  if ((f_x.size() != f_y.size())||(d_x.size() != d_y.size()) || 
      (i_x.size() != i_y.size()) || (u_x.size() != u_y.size()))
    {
      cout << "Input and output vectors do not have the same size" <<endl;
      ++error;
    }
  else
    {
      for ( int i=0 ; i<n ; ++i )
	{
	  if (fabs(f_y[i] - f_true_vector[i])>0.0000001)
	    {
	      error=error+10;
	      break;
	    }
	  if (fabs(f_y_err2[i] - f_true_vector_err2[i])>0.0000001)
	    {
	      error=error+20;
	      break;
	    }
	  if (fabs(d_y[i] - d_true_vector[i]) > 0.0000001)
	    {
	      error=error+110;
	      break;
	    }
	  if (fabs(d_y_err2[i] - d_true_vector_err2[i]) > 0.0000001)
	    {
	      error=error+120;
	      break;
	    }
	  if (i_y[i] != i_true_vector[i])
	    {
	      error=error+210;
	      break;
	    }
	  if (i_y_err2[i] != i_true_vector_err2[i])
	    {
	      error=error+220;
	      break;
	    }
	  if (u_y[i] != u_true_vector[i])
	    {
	      error=error+310;
	      break;
	    }
	  if (u_y_err2[i] != u_true_vector_err2[i])
	    {
	      error=error+320;
	      break;
	    }
	}
    }

  cout << "div_scalar_vec_ncerr.cpp..........";

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

