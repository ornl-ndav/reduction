// $Id$

#include "arith.hpp"
#include "test_common.hpp"
#include <iostream>

using namespace std;

const int NUM_VAL = 5;

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
      input1_err2.push_back(static_cast<NumT>(1.));
      input2_err2.push_back(static_cast<NumT>(1.));
    }
}

template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & output_vv,
                             Nessi::Vector<NumT> & output_vv_err2)
{
  // initialize the correct outputs for vector vector case
  output_vv.push_back(static_cast<NumT>(6.)); // =(0/1+6/1) * (1+1)/2
  output_vv_err2.push_back(static_cast<NumT>(2.));
  output_vv.push_back(static_cast<NumT>(6.)); // =(1/1+5/1) * (1+1)/2
  output_vv_err2.push_back(static_cast<NumT>(2.));
  output_vv.push_back(static_cast<NumT>(6.)); // =(2/1+4/1) * (1+1)/2
  output_vv_err2.push_back(static_cast<NumT>(2.));
  output_vv.push_back(static_cast<NumT>(6.)); // =(3/1+3/1) * (1+1)/2
  output_vv_err2.push_back(static_cast<NumT>(2.));
  output_vv.push_back(static_cast<NumT>(6.)); // =(4/1+2/1) * (1+1)/2
  output_vv_err2.push_back(static_cast<NumT>(2.));
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
{
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
  Nessi::Vector<NumT> output_vv(NUM_VAL);
  Nessi::Vector<NumT> output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2);
  initialize_true_outputs(true_output_vv,true_output_vv_err2);

  // run the code being tested
  ArrayManip::sumw_ncerr(input1, input1_err2, input2, input2_err2,
                         output_vv, output_vv_err2);

  return test_okay(output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

int main()
{
  cout << "sumw_ncerr_test.cpp..........";

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
