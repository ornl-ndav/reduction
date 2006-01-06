// $Id$

#include "test_common.hpp"
#include "arith.hpp"

using namespace std;

const int NUM_VAL=5;

template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2,
                       Nessi::Vector<NumT> & input2,
                       Nessi::Vector<NumT> & input2_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>(10-i)); // 10,9,8,7,6
      input2.push_back(static_cast<NumT>(2+i));  //  2,3,4,5,6
      input1_err2.push_back(static_cast<NumT>(1));
      input2_err2.push_back(static_cast<NumT>(1));
    }
}


template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & output_vs,
                             Nessi::Vector<NumT> & output_vs_err2,
                             Nessi::Vector<NumT> & output_sv,
                             Nessi::Vector<NumT> & output_sv_err2,
                             Nessi::Vector<NumT> & output_vv,
                             Nessi::Vector<NumT> & output_vv_err2)
{
  // initialize the correct outputs for vector vector case
  output_vv.push_back(static_cast<NumT>(5)); // =10/2
  output_vv_err2.push_back(static_cast<NumT>(6.5));
  output_vv.push_back(static_cast<NumT>(3)); // =9/3
  output_vv_err2.push_back(static_cast<NumT>(1.11111111111111111111111111111));
  output_vv.push_back(static_cast<NumT>(2)); // =8/4
  output_vv_err2.push_back(static_cast<NumT>(0.3125));
  output_vv.push_back(static_cast<NumT>(1.4)); // =7/5
  output_vv_err2.push_back(static_cast<NumT>(0.1184));
  output_vv.push_back(static_cast<NumT>(1)); // =6/6
  output_vv_err2.push_back(static_cast<NumT>(0.05555555555555555555555555556));

  // initialize the correct outputs for vector scalar case
  output_vs.push_back(static_cast<NumT>(5)); // =10/2
  output_vs_err2.push_back(static_cast<NumT>(6.5));
  output_vs.push_back(static_cast<NumT>(4.5)); // =9/2
  output_vs_err2.push_back(static_cast<NumT>(5.3125));
  output_vs.push_back(static_cast<NumT>(4)); // =8/2
  output_vs_err2.push_back(static_cast<NumT>(4.25));
  output_vs.push_back(static_cast<NumT>(3.5)); // =7/2
  output_vs_err2.push_back(static_cast<NumT>(3.3125));
  output_vs.push_back(static_cast<NumT>(3)); // =6/2
  output_vs_err2.push_back(static_cast<NumT>(2.5));

  // initialize the correct outputs for scalar vector case
  output_sv.push_back(static_cast<NumT>(5)); // =10/2
  output_sv_err2.push_back(static_cast<NumT>(6.5));
  output_sv.push_back(static_cast<NumT>(3.33333333333333333333333333)); //=10/3
  output_sv_err2.push_back(static_cast<NumT>(1.34567901234567899));
  output_sv.push_back(static_cast<NumT>(2.5)); // =10/4
  output_sv_err2.push_back(static_cast<NumT>(0.453125));
  output_sv.push_back(static_cast<NumT>(2)); // =10/5
  output_sv_err2.push_back(static_cast<NumT>(0.2));
  output_sv.push_back(static_cast<NumT>(1.66666666666666666666666667)); //=10/6
  output_sv_err2.push_back(static_cast<NumT>(0.104938271604938266));
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_sv,
               Nessi::Vector<NumT> & output_sv_err2,
               Nessi::Vector<NumT> & true_output_sv,
               Nessi::Vector<NumT> & true_output_sv_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
{
  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    return false;
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS,ERROR))
    return false;

  // scalar vector
  if(!test_okay(output_sv,true_output_sv,SV))
    return false;
  if(!test_okay(output_sv_err2,true_output_sv_err2,SV,ERROR))
    return false;

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    return false;
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV,ERROR))
    return false;

  // everything okay
  return true;
}

template <typename NumT>
bool test_func(NumT key){ // key forces correct test to happen
  // allocate arrays
  Nessi::Vector<NumT> input1;
  Nessi::Vector<NumT> input1_err2;
  Nessi::Vector<NumT> input2;
  Nessi::Vector<NumT> input2_err2;
  Nessi::Vector<NumT> output_vs(NUM_VAL);
  Nessi::Vector<NumT> output_vs_err2(NUM_VAL);
  Nessi::Vector<NumT> output_sv(NUM_VAL);
  Nessi::Vector<NumT> output_sv_err2(NUM_VAL);
  Nessi::Vector<NumT> output_vv(NUM_VAL);
  Nessi::Vector<NumT> output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> true_output_sv;
  Nessi::Vector<NumT> true_output_sv_err2;
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2);
  initialize_true_outputs(true_output_vs,true_output_vs_err2,
                          true_output_sv,true_output_sv_err2,
                          true_output_vv,true_output_vv_err2);

  // run the code being tested
  ArrayManip::div_ncerr(input1, input1_err2, input2, input2_err2,
                         output_vv, output_vv_err2);
  ArrayManip::div_ncerr(input1[0], input1_err2[0], input2, input2_err2,
                         output_sv, output_sv_err2);
  ArrayManip::div_ncerr(input1, input1_err2,
                         input2[0], input2_err2[0],
                         output_vs, output_vs_err2);

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_sv, output_sv_err2,
                   true_output_sv, true_output_sv_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

int main() 
{
  cout << "div_ncerr_test.cpp..........";

  if(!test_func(static_cast<double>(1)))
    return -1;

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<int>(1)))
    return -1;

  if(!test_func(static_cast<unsigned int>(1)))
    return -1;
  
  cout << "Functionality OK" << endl;

  return 0;
}

/* -------------------- OLD METHODS
int main() 
{
  // SNS-FIXME

  int num_val = 20;

  //float
  float f_scalar = 5.0;
  float f_scalar_err2 = 3.0;
  float f_scalar_2;
  Nessi::Vector<float> f_input;                     //Original vector
  Nessi::Vector<float> f_input_err2;                //Original vector err
  Nessi::Vector<float> f_input2;                    //Original vector 2
  Nessi::Vector<float> f_input2_err2;               //Original vector 2 err
  float f_input2_2;
  Nessi::Vector<float> f_output(num_val);           //Output vector
  Nessi::Vector<float> f_output_err2(num_val);      //Output vector err
  Nessi::Vector<float> f_true_vector;               //True vector
  Nessi::Vector<float> f_true_vector_err2(num_val); //True vector err

  //double 
  double d_scalar = 5;
  double d_scalar_err2 = 3;
  double d_scalar_2;
  Nessi::Vector<double> d_input;
  Nessi::Vector<double> d_input_err2;
  Nessi::Vector<double> d_input2;
  Nessi::Vector<double> d_input2_err2;
  double d_input2_2;
  Nessi::Vector<double> d_output(num_val);
  Nessi::Vector<double> d_output_err2(num_val);
  Nessi::Vector<double> d_true_vector;
  Nessi::Vector<double> d_true_vector_err2(num_val);

  //int 
  int i_scalar = 5;
  int i_scalar_err2 = 3;
  int i_scalar_2;
  Nessi::Vector<int> i_input;
  Nessi::Vector<int> i_input_err2;
  Nessi::Vector<int> i_input2;
  Nessi::Vector<int> i_input2_err2;
  int i_input2_2;
  Nessi::Vector<int> i_output(num_val);
  Nessi::Vector<int> i_output_err2(num_val);
  Nessi::Vector<int> i_true_vector;
  Nessi::Vector<int> i_true_vector_err2(num_val);
  
  //unsigned 
  unsigned u_scalar = 5;
  unsigned u_scalar_err2 = 3;
  unsigned u_scalar_2;
  Nessi::Vector<unsigned> u_input;
  Nessi::Vector<unsigned> u_input_err2;
  Nessi::Vector<unsigned> u_input2;
  Nessi::Vector<unsigned> u_input2_err2;
  unsigned u_input2_2;
  Nessi::Vector<unsigned> u_output(num_val);
  Nessi::Vector<unsigned> u_output_err2(num_val);
  Nessi::Vector<unsigned> u_true_vector;
  Nessi::Vector<unsigned> u_true_vector_err2(num_val);

  int error1=0;                      //==0,Pass  !=0,Fail
  int error2=0;                      //==0,Pass  !=0,Fail
  int error3=0;                      //==0,Pass  !=0,Fail

  for (int i = 0 ; i < num_val ; ++i)
    {
      f_input.push_back(2.*static_cast<float>(i+1));
      d_input.push_back(2.*static_cast<double>(i+1)); 
      i_input.push_back(2*static_cast<int>(i+1));
      u_input.push_back(2*static_cast<unsigned int>(i+1));

      f_input_err2.push_back(static_cast<float>(i+1));
      d_input_err2.push_back(static_cast<double>(i+1));      
      i_input_err2.push_back(static_cast<int>(i+1));
      u_input_err2.push_back(static_cast<unsigned int>(i+1));
    }
 
  // case 1 - scalar/vector

  ArrayManip::div_ncerr(f_scalar, f_scalar_err2, f_input, f_input_err2, 
						f_output, f_output_err2);

  ArrayManip::div_ncerr(d_scalar, d_scalar_err2, d_input, d_input_err2, 
						d_output, d_output_err2);

  ArrayManip::div_ncerr(i_scalar, i_scalar_err2, i_input, i_input_err2, 
						i_output, i_output_err2);

  ArrayManip::div_ncerr(u_scalar, u_scalar_err2, u_input, u_input_err2, 
						u_output, u_output_err2);
  

  for (int i = 0 ; i < num_val ; ++i)
    {
      f_true_vector.push_back(f_scalar / f_input[i]);
      d_true_vector.push_back(d_scalar/d_input[i]);
      i_true_vector.push_back(i_scalar/i_input[i]);
      u_true_vector.push_back(u_scalar/u_input[i]);

      f_scalar_2 = f_input[i]*f_input[i];
      f_true_vector_err2[i] = (((f_scalar*f_scalar)/(f_scalar_2*f_scalar_2)) * 
							   f_input_err2[i])+(f_scalar_err2/f_scalar_2);
	  
      d_scalar_2 = d_input[i]*d_input[i];
      d_true_vector_err2[i] = (((d_scalar*d_scalar)/(d_scalar_2*d_scalar_2)) * 
							   d_input_err2[i])+(d_scalar_err2/d_scalar_2);
	  
      i_scalar_2 = i_input[i]*i_input[i];
      i_true_vector_err2[i] = (((i_scalar*i_scalar)/(i_scalar_2*i_scalar_2)) * 
							   i_input_err2[i])+(i_scalar_err2/i_scalar_2);
	  
      u_scalar_2 = u_input[i]*u_input[i];
      u_true_vector_err2[i] = (((u_scalar*u_scalar)/(u_scalar_2*u_scalar_2)) * 
							   u_input_err2[i])+(u_scalar_err2/u_scalar_2);
    }
  
  //check first the size
  if ( (f_input.size() != f_output.size())
       ||(d_input.size() != d_output.size())
       || (i_input.size() != i_output.size())
       || (u_input.size() != u_output.size()) )
    {
      cout << "(s,v) Input and output vectors do not have the same size"  
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
  
  // reset outputs
  f_output.clear();
  f_output.resize(num_val);
  f_output_err2.clear();
  f_output_err2.resize(num_val);
  d_output.clear();
  d_output.resize(num_val);
  d_output_err2.clear();
  d_output_err2.resize(num_val);
  i_output.clear();
  i_output.resize(num_val);
  i_output_err2.clear();
  i_output_err2.resize(num_val);
  u_output.clear();
  u_output.resize(num_val);
  u_output_err2.clear();
  u_output_err2.resize(num_val);

  // case 2 - vector/scalar

  ArrayManip::div_ncerr(f_input, f_input_err2, f_scalar, f_scalar_err2,
                        f_output, f_output_err2);

  ArrayManip::div_ncerr(d_input, d_input_err2, d_scalar, d_scalar_err2,
                        d_output, d_output_err2);

  ArrayManip::div_ncerr(i_input, i_input_err2, i_scalar, i_scalar_err2,
                         i_output, i_output_err2);

  ArrayManip::div_ncerr(u_input, u_input_err2, u_scalar, u_scalar_err2,
                        u_output, u_output_err2);

  //initialization of true vectors
  f_true_vector.clear();
  d_true_vector.clear();
  i_true_vector.clear();
  u_true_vector.clear();


  for (int i = 0 ; i < num_val ; ++i)
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
	((( f_input[i] * f_input[i]) / (f_scalar_2 * f_scalar_2)) * 
	 f_scalar_err2);

      d_true_vector_err2[i] = (d_input_err2[i] / d_scalar_2) + 
	((( d_input[i] * d_input[i]) / (d_scalar_2 * d_scalar_2)) * 
	 d_scalar_err2);

      i_true_vector_err2[i] = (i_input_err2[i] / i_scalar_2) + 
	((( i_input[i] * i_input[i]) / (i_scalar_2 * i_scalar_2)) * 
	 i_scalar_err2);

      u_true_vector_err2[i] = (u_input_err2[i] / u_scalar_2) + 
	((( u_input[i] * u_input[i]) / (u_scalar_2 * u_scalar_2)) * 
	 u_scalar_err2);

    }

  //check first the size
  if ( (f_input.size() != f_output.size())
       ||(d_input.size() != d_output.size())
       || (i_input.size() != i_output.size())
       || (u_input.size() != u_output.size()) )
    {
      cout << "(v,s) Input and output vectors do not have the same size" 
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
  
  for (int i = 0 ; i < num_val ; ++i)            //create the arrays
    {
      //_input2 array
      f_input2.push_back(4.*static_cast<float>(i));
      d_input2.push_back(4.*static_cast<double>(i)); 
      i_input2.push_back(4*static_cast<int>(i+1));
      u_input2.push_back(4*static_cast<unsigned int>(i+1));

      f_input2_err2.push_back(static_cast<float>(i+5));
      d_input2_err2.push_back(static_cast<double>(i+5));      
      i_input2_err2.push_back(static_cast<int>(i+5));
      u_input2_err2.push_back(static_cast<unsigned int>(i+5));

    }
  
  // case 3 - vector/vector

  ArrayManip::div_ncerr(f_input, f_input_err2, f_input2, f_input2_err2,
                        f_output, f_output_err2);

  ArrayManip::div_ncerr(d_input, d_input_err2, d_input2, d_input2_err2,
                        d_output, d_output_err2);

  ArrayManip::div_ncerr(i_input, i_input_err2, i_input2, i_input2_err2,
                        i_output, i_output_err2);

  ArrayManip::div_ncerr(u_input, u_input_err2, u_input2, u_input2_err2,
                        u_output, u_output_err2);
  
  //initialization of true vectors
  f_true_vector.clear();
  d_true_vector.clear();
  i_true_vector.clear();
  u_true_vector.clear();

  for (int i = 0 ; i < num_val ; ++i)
    {
      std::transform(f_input.begin(), f_input.end(), f_input2.begin(), 
		     f_true_vector.begin(),std::divides<float>());

      std::transform(d_input.begin(), d_input.end(), d_input2.begin(), 
		     d_true_vector.begin(),std::divides<double>());

      std::transform(i_input.begin(), i_input.end(), i_input2.begin(), 
		     i_true_vector.begin(),std::divides<int>());

      std::transform(u_input.begin(), u_input.end(), u_input2.begin(), 
		     u_true_vector.begin(),std::divides<unsigned>());

      f_input2_2 = f_input2[i] * f_input2[i];      
      d_input2_2 = d_input2[i] * d_input2[i];      
      i_input2_2 = i_input2[i] * i_input2[i];      
      u_input2_2 = u_input2[i] * u_input2[i];      

      f_true_vector_err2[i] = (f_input_err2[i] / f_input2_2) +
	(((f_input[i] * f_input[i]) / (f_input2_2 * f_input2_2)) * 
	 f_input2_err2[i]);

      d_true_vector_err2[i] = (d_input_err2[i] / d_input2_2) +
	(((d_input[i] * d_input[i]) / (d_input2_2 * d_input2_2)) * 
	 d_input2_err2[i]);

      i_true_vector_err2[i] = (i_input_err2[i] / i_input2_2) +
	(((i_input[i] * i_input[i]) / (i_input2_2 * i_input2_2)) * 
	 i_input2_err2[i]);

      u_true_vector_err2[i] = (u_input_err2[i] / u_input2_2) +
	(((u_input[i] * u_input[i]) / (u_input2_2 * u_input2_2)) * 
	 u_input2_err2[i]);      
    }
  
  //check first if the size are in good agreement
  if ( (f_input.size() != f_output.size())
       || (d_input.size() != d_output.size())
       || (i_input.size() != i_output.size())
       || (u_input.size() != u_output.size()) )
    {
      cout << "(v,v) Input and output vectors do not have the same size" 
		   << endl;
      ++error3;
    }
  else
    {
	  while(1)
		{
		  Utils::vector_comparison(f_output, f_true_vector, error3, 10);
		  if (error3 != 0) break;
		  Utils::vector_comparison(f_output_err2, f_true_vector_err2, 
								   error3, 20);
		  if (error3 != 0) break;

		  Utils::vector_comparison(d_output, d_true_vector, error3, 110);
		  if (error3 != 0) break;
		  Utils::vector_comparison(d_output_err2, d_true_vector_err2, 
								   error3, 120);
		  if (error3 != 0) break;

		  Utils::vector_comparison(i_output, i_true_vector, error3, 210);
		  if (error3 != 0) break;
		  Utils::vector_comparison(i_output_err2, i_true_vector_err2, 
								   error3, 220);
		  if (error3 != 0) break;

		  Utils::vector_comparison(u_output, u_true_vector, error3, 310);
		  if (error3 != 0) break;
		  Utils::vector_comparison(u_output_err2, u_true_vector_err2, 
								   error3, 320);
		  break;
		}
    }
  
  cout << "div_ncerr_test.cpp..........";

  switch (error1)
    {
    case 0:
      break;
    case 1:
      cout << "(s,v) FAILED....Outut and input vectors have different sizes"
           << endl;
      break;
    case 10:
      cout << "(float s,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 20:
      cout << "(float s,v) FAILED....Output error vector different from vector"
           << " expected" << endl;
      break;
    case 110:
      cout << "(double s,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 120:
      cout << "(double s,v) FAILED....Output error vector different from "
           << "vector expected" << endl;
      break;
    case 210:
      cout << "(int s,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 220:
      cout << "(int s,v) FAILED....Output error vector different from vector"
           << " expected" << endl;
      break;
    case 310:
      cout << "(unsigned s,v) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 320:
      cout << "(unsigned s,v) FAILED....Output error vector different from "
           << "vector expected" << endl;
      break;
    default:
      cout << "(s,v) FAILED" << endl;
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
      cout << "(int v,s) FAILED....Output error vector different from vector "
           << "expected" << endl;
      break;
    case 310:
      cout << "(unsigned v,s) FAILED....Output vector different from vector "
           << "expected" << endl;
      break;
    case 320:
      cout << "(unsigned v,s) FAILED....Output error vector different from "
           <<"vector expected" << endl;
      break;
    default:
      cout << "(v,s) FAILED" << endl;
      break;
    }

  if(error2)
    {
      return -1;
    }

  switch (error3)
    {
    case 0:
      break;
    case 1:
      cout << "(v,v) FAILED....Outut and input vectors have different sizes"
           << endl;
      break;
    case 10:
      cout << "(float v,v) FAILED....Output vector different from vector"
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

  if(error3)
    {
      return -1;
    }

  cout << "Functionality OK" << endl;
  return 0;
}
*/
