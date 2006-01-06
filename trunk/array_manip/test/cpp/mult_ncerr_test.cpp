// $Id$

#include "arith.hpp"
#include "num_comparison.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

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
      input1.push_back(static_cast<NumT>(NUM_VAL+1-i)); // 6,5,4,3,2
      input2.push_back(static_cast<NumT>(i));           // 0,1,2,3,4
      input1_err2.push_back(static_cast<NumT>(1));
      input2_err2.push_back(static_cast<NumT>(1));
    }
}


template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & output_vs,
                             Nessi::Vector<NumT> & output_vs_err2,
                             Nessi::Vector<NumT> & output_vv,
                             Nessi::Vector<NumT> & output_vv_err2)
{
  // SNS-FIXME: Need true values for uncertainties

  // initialize the correct outputs for vector vector case
  output_vv.push_back(static_cast<NumT>(0)); // =0*6
  output_vv_err2.push_back(static_cast<NumT>(0));
  output_vv.push_back(static_cast<NumT>(5)); // =1*5
  output_vv_err2.push_back(static_cast<NumT>(0));
  output_vv.push_back(static_cast<NumT>(8)); // =2*4
  output_vv_err2.push_back(static_cast<NumT>(0));
  output_vv.push_back(static_cast<NumT>(9)); // =3*3
  output_vv_err2.push_back(static_cast<NumT>(0));
  output_vv.push_back(static_cast<NumT>(8)); // =4*2
  output_vv_err2.push_back(static_cast<NumT>(0));

  // initialize the correct outputs for vector scalar case
  output_vs.push_back(static_cast<NumT>(24)); // =4*6
  output_vs_err2.push_back(static_cast<NumT>(0));
  output_vs.push_back(static_cast<NumT>(20)); // =4*5
  output_vs_err2.push_back(static_cast<NumT>(0));
  output_vs.push_back(static_cast<NumT>(16)); // =4*4
  output_vs_err2.push_back(static_cast<NumT>(0));
  output_vs.push_back(static_cast<NumT>(12)); // =4*3
  output_vs_err2.push_back(static_cast<NumT>(0));
  output_vs.push_back(static_cast<NumT>(8));  // =4*2
  output_vs_err2.push_back(static_cast<NumT>(0));
}

template <typename NumT>
string type_string(Nessi::Vector<NumT> & vec)
{
  return string("");
}

string type_string(Nessi::Vector<double> & vec)
{
  return string("double");
}

string type_string(Nessi::Vector<float> & vec)
{
  return string("float");
}

string type_string(Nessi::Vector<int> & vec)
{
  return string("int");
}

string type_string(Nessi::Vector<unsigned> & vec)
{
  return string("unsigned");
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
{
  int error=0; // dummy variable for use in testing code

  // vector scalar
  Utils::vector_comparison(output_vs, true_output_vs, error, 10);
  if(error>0){
    cout << "(" << type_string(output_vs) << " v,s) FAILED....Output vector different from vector expected" << endl;
    return false;
  }
  /* SNS-FIXME: uncomment this code
  Utils::vector_comparison(output_vs_err2, true_output_vs_err2, error, 10);
  if(error>0){
    cout << "(" << type_string(output_vs_err2) << " v,s) FAILED....Output error vector different from vector expected" << endl;
    return false;
  }
  */

  // vector vector
  Utils::vector_comparison(output_vv, true_output_vv, error, 10);
  if(error>0){
    cout << "(" << type_string(output_vv) << " v,v) FAILED....Output vector different from vector expected" << endl;
    return false;
  }
  /* SNS-FIXME: uncomment this code
  Utils::vector_comparison(output_vv_err2, true_output_vv_err2, error, 10);
  if(error>0){
    cout << "(" << type_string(output_vv_err2) << " v,v) FAILED....Output error vector different from vector expected" << endl;
    return false;
  }
  */
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
  Nessi::Vector<NumT> output_vv(NUM_VAL);
  Nessi::Vector<NumT> output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2);
  initialize_true_outputs(true_output_vs,true_output_vs_err2,
                          true_output_vv,true_output_vv_err2);

  // run the code being tested
  ArrayManip::mult_ncerr(input1, input1_err2, input2, input2_err2,
                         output_vv, output_vv_err2);
  ArrayManip::mult_ncerr(input1, input1_err2,
                         input2[NUM_VAL-1], input2_err2[NUM_VAL-1],
                         output_vs, output_vs_err2);

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

int main() 
{
  cout << "mult_ncerr_test.cpp..........";

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<double>(1)))
    return -1;

  if(!test_func(static_cast<int>(1)))
    return -1;

  if(!test_func(static_cast<unsigned int>(1)))
    return -1;
  
  cout << "Functionality OK" << endl;

  return 0;
}

