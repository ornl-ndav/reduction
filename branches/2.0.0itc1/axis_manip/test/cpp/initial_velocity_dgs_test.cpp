/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file axis_manip/test/cpp/initial_velocity_dgs_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup initial_velocity_dgs_test initial_velocity_dgs_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>initial_velocity_dgs</i> and described in 3.19
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notation used:</b>
 * - ss : scalar-scalar
 * - vv : vector-vector
 * - SS : "s,s"
 * - VV : "v,v"
 * - ERROR = "Error"
 * - EMPTY = ""
 */

/**
 * This function initializes the value of inputs.
 *
 * \param dist_upsteam_mon (OUTPUT) is the distance to upstream monitor
 * \param dist_upstream_mon_err2 (OUTPUT) is the square of the uncertainty  
 * in the distance to upstream monitor
 * \param time_upstream_mon (OUTPUT) is the time of flight to reach the 
 * upstream monitor
 * \param time_upstream_mon_err2 (OUTPUT) is the square of the uncertainty 
 * in the time of flight to reach the upstream monitor
 * \param dist_downstream_mon (OUTPUT) is the distance to downstream monitor
 * \param dist_downstream_mon_err2 (OUTPUT) is the square of the uncertainty
 * in the distance to downstream monitor
 * \param time_downstream_mon (OUTPUT) is the time of flight to reach the 
 * downstream monitor
 * \param time_downstream_mon_err2 (OUTPUT) is the square of the uncertainty
 * in the time of flight to reach the downstream monitor
 */
template <typename NumT>
void initialize_inputs(NumT & dist_upsteam_mon,
                       NumT & dist_upstream_mon_err2 ,
                       NumT & time_upstream_mon ,
                       NumT & time_upstream_mon_err2 ,
                       NumT & dist_downstream_mon ,
                       NumT & dist_downstream_mon_err2 ,
                       NumT & time_downstream_mon ,
                       NumT & time_downstream_mon_err2)
{
  dist_upsteam_mon = static_cast<NumT>(0.51);
  dist_upstream_mon_err2 = static_cast<NumT>(0.05);
  time_upstream_mon = static_cast<NumT>(1.25);
  time_upstream_mon_err2 = static_cast<NumT>(0.25);
  dist_downstream_mon = static_cast<NumT>(1.1);
  dist_downstream_mon_err2 = static_cast<NumT>(0.1);
  time_downstream_mon = static_cast<NumT>(2.75);
  time_downstream_mon_err2 = static_cast<NumT>(0.75);
}

/**
 * This function sets the true outputs based on values contained 
 * from the scalar inputs for the float case.
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty 
 * of the true output for the ss case
 */
void initialize_true_outputs(float & true_output_ss,
                             float & true_output_ss_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(0.39333333);
  true_output_ss_err2=static_cast<float>(0.06666667);

}

/**
 * This function sets the true outputs based on values contained 
 * from the scalar inputs for the double case.
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty 
 * of the true output for the ss case
 */
void initialize_true_outputs(double & true_output_ss,
                             double & true_output_ss_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(0.39333333333333333);
  true_output_ss_err2=static_cast<double>(0.06666666666666667);

}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>initial_velocity_dgs</i> function for the
 * ss case.
 *
 * The function returns TRUE if the \f$output\f$ and the \f$true\_output\f$ 
 * match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by
 * <i>initial_velocity_dgs</i> for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the 
 * value created by <i>initial_velocity_dgs</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of 
 * the true value for the ss case
 */
template <typename NumT>
bool test_okay(NumT & output_ss,
               NumT & output_ss_err2,
               NumT & true_output_ss,
               NumT & true_output_ss_err2)
{
  bool value = true;

  // scalar scalar
  if(!test_okay(output_ss,true_output_ss))
    {
      value = false;
    }
  if(!test_okay(output_ss_err2,true_output_ss_err2))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>initial_velocity_dgs</i>
 * function (as described in the documentation of the
 * <i>initial_velocity_dgs</i> function) and launches the comparison of the
 * data.
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays             
  NumT dist_upsteam_mon;
  NumT dist_upstream_mon_err2;
  NumT time_upstream_mon;
  NumT time_upstream_mon_err2;
  NumT dist_downstream_mon;
  NumT dist_downstream_mon_err2;
  NumT time_downstream_mon;
  NumT time_downstream_mon_err2;
  NumT output_ss;
  NumT output_ss_err2;
  NumT true_output_ss;
  NumT true_output_ss_err2;

  // fill in values as appropriate
  initialize_inputs(dist_upsteam_mon,
                    dist_upstream_mon_err2,
                    time_upstream_mon,
                    time_upstream_mon_err2,
                    dist_downstream_mon,
                    dist_downstream_mon_err2,
                    time_downstream_mon,
                    time_downstream_mon_err2);

  initialize_true_outputs(true_output_ss, true_output_ss_err2);

  // run the code being tested
  AxisManip::initial_velocity_dgs(dist_upsteam_mon,
                                  dist_upstream_mon_err2 ,
                                  time_upstream_mon ,
                                  time_upstream_mon_err2 ,
                                  dist_downstream_mon ,
                                  dist_downstream_mon_err2 ,
                                  time_downstream_mon ,
                                  time_downstream_mon_err2,
                                  output_ss,
                                  output_ss_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2);
}

/**
 * Main function that test initial_velocity_dgs for float and double.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "initial_velocity_dgs_test.cpp..........";

  string debug;
  if(argc > 1)
    {
      debug = argv[1];
    }

  int value = 0;

  if(!test_func(static_cast<float>(1), debug))
    {
      value = -1;
    }

  if(!test_func(static_cast<double>(1), debug))
    {
      value = -1;
    }

  if(value == 0)
    {
      cout << "Functionality OK" << endl;
    }

  return value;
}
