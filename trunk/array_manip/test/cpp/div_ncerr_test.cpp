// $Id$

#include "arith.hpp"
#include "test_common.hpp"

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
      input1.push_back(static_cast<NumT>(10.-i)); // 10,9,8,7,6
      input2.push_back(static_cast<NumT>(2.+i));  //  2,3,4,5,6
      input1_err2.push_back(static_cast<NumT>(1.));
      input2_err2.push_back(static_cast<NumT>(1.));
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
  output_vv.push_back(static_cast<NumT>(5.)); // =10/2
  output_vv_err2.push_back(static_cast<NumT>(6.5));
  output_vv.push_back(static_cast<NumT>(3.)); // =9/3
  output_vv_err2.push_back(static_cast<NumT>(1.11111111111111111111111111111));
  output_vv.push_back(static_cast<NumT>(2.)); // =8/4
  output_vv_err2.push_back(static_cast<NumT>(0.3125));
  output_vv.push_back(static_cast<NumT>(1.4)); // =7/5
  output_vv_err2.push_back(static_cast<NumT>(0.1184));
  output_vv.push_back(static_cast<NumT>(1.)); // =6/6
  output_vv_err2.push_back(static_cast<NumT>(0.05555555555555555555555555556));

  // initialize the correct outputs for vector scalar case
  output_vs.push_back(static_cast<NumT>(5.)); // =10/2
  output_vs_err2.push_back(static_cast<NumT>(6.5));
  output_vs.push_back(static_cast<NumT>(4.5)); // =9/2
  output_vs_err2.push_back(static_cast<NumT>(5.3125));
  output_vs.push_back(static_cast<NumT>(4.)); // =8/2
  output_vs_err2.push_back(static_cast<NumT>(4.25));
  output_vs.push_back(static_cast<NumT>(3.5)); // =7/2
  output_vs_err2.push_back(static_cast<NumT>(3.3125));
  output_vs.push_back(static_cast<NumT>(3.)); // =6/2
  output_vs_err2.push_back(static_cast<NumT>(2.5));

  // initialize the correct outputs for scalar vector case
  output_sv.push_back(static_cast<NumT>(5.)); // =10/2
  output_sv_err2.push_back(static_cast<NumT>(6.5));
  output_sv.push_back(static_cast<NumT>(3.33333333333333333333333333)); //=10/3
  output_sv_err2.push_back(static_cast<NumT>(1.34567901234567899));
  output_sv.push_back(static_cast<NumT>(2.5)); // =10/4
  output_sv_err2.push_back(static_cast<NumT>(0.453125));
  output_sv.push_back(static_cast<NumT>(2.)); // =10/5
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
