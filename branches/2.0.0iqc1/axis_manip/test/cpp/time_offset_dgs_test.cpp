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
 * \file axis_manip/test/cpp/time_offset_dgs_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup time_offset_dgs_test time_offset_dgs_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>time_offset_dgs</i> and described in 3.26
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
 * \param dist_downstream_monitor (OUTPUT) is the total flight path for  
 * the downstream monitor
 * \param dist_downstream_monitor_err2 (OUTPUT) is the square of the 
 * uncertainty in the total flight path for the downstream monitor
 * \param time_downstream_monitor (OUTPUT) is the time that is observed
 * at downstream monitor
 * \param time_downstream_monitor_err2 (OUTPUT) is the square of the 
 * uncertainty in the time that is observed at downstream monitor
 * \param initial_velocity (OUTPUT) is the velocity of the incident 
 * neutrons
 * \param initial_velocity_err2 (OUTPUT) is the square of the uncertainty
 * in the velocity of the incident neutrons
 */
template <typename NumT>
void initialize_inputs(NumT & dist_downstream_monitor ,
                       NumT & dist_downstream_monitor_err2 ,
                       NumT & time_downstream_monitor ,
                       NumT & time_downstream_monitor_err2,
                       NumT & initial_velocity,
                       NumT & initial_velocity_err2)
{
  dist_downstream_monitor = static_cast<NumT>(1.1);
  dist_downstream_monitor_err2 = static_cast<NumT>(0.1);
  time_downstream_monitor = static_cast<NumT>(2.75);
  time_downstream_monitor_err2 = static_cast<NumT>(0.75);
  initial_velocity = static_cast<NumT>(0.51);
  initial_velocity_err2 = static_cast<NumT>(0.05);
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
  true_output_ss=static_cast<float>(0.59313725);
  true_output_ss_err2=static_cast<float>(1.27874988);

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
  true_output_ss=static_cast<double>(0.59313725490196078);
  true_output_ss_err2=static_cast<double>(1.27874988488885991);

}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>time_offset_dgs</i> function for the
 * ss case.
 *
 * The function returns TRUE if the \f$output\f$ and the \f$true\_output\f$ 
 * match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by <i>time_offset_dgs</i> 
 * for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the 
 * value created by <i>time_offset_dgs</i> for the ss case
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
 * Function that generates the data using the <i>time_offset_dgs</i>
 * function (as described in the documentation of the
 * <i>time_offset_dgs</i> function) and launches the comparison of the
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
  NumT dist_downstream_monitor;
  NumT dist_downstream_monitor_err2;
  NumT time_downstream_monitor;
  NumT time_downstream_monitor_err2;
  NumT initial_velocity;
  NumT initial_velocity_err2;
  NumT output_ss;
  NumT output_ss_err2;
  NumT true_output_ss;
  NumT true_output_ss_err2;

  // fill in values as appropriate
  initialize_inputs(dist_downstream_monitor,
                    dist_downstream_monitor_err2,
                    time_downstream_monitor,
                    time_downstream_monitor_err2,
                    initial_velocity,
                    initial_velocity_err2);

  initialize_true_outputs(true_output_ss, true_output_ss_err2);

  // run the code being tested
  AxisManip::time_offset_dgs(dist_downstream_monitor ,
                             dist_downstream_monitor_err2 ,
                             time_downstream_monitor ,
                             time_downstream_monitor_err2,
                             initial_velocity,
                             initial_velocity_err2,
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
 * Main function that test time_offset_dgs for float and double.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "time_offset_dgs_test.cpp..........";

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

/**
 * \}
 */
