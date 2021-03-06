/*
 *         SNS Common Libraries
 *     A part of the SNS Analysis Software Suite.
 *
 *      Spallation Neutron Source
 *    Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *           NOTICE
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
 * \file axis_manip/test/cpp/d_spacing_to_tof_focused_det_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup d_spacing_to_tof_focused_det_test \
 * d_spacing_to_tof_focused_det_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>d_spacing_to_tof_focused_det</i> and described in 3.39
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\f$, and \f$true\_output\_vv\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notation used:</b>
 * - ss : scalar-scalar
 * - vv : vector-vector
 * - SS : "s,s"
 * - VV = "v,v"
 * - ERROR = "Error"
 * - EMPTY = ""
 */

/**
 * This function initializes the value of arrays, \f$d\_spacing\f$, 
 * \f$d\_spacing\_err2\f$.
 *
 * \param d_spacing (OUTPUT) is the d-spacing axis in units of Angstrom
 * \param d_spacing_err2 (OUTPUT) is the square of the uncertainty in the
 * d_spacing axis
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & d_spacing,
                       Nessi::Vector<NumT> & d_spacing_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      d_spacing.push_back(static_cast<NumT>(1+i));
      d_spacing_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$d\_spacing\f$ and \f$d\_spacing\_err2\f$ for the float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$d\_spacing[0]\f$ and \f$d\_spacing\_err2[0]\f$)
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
 */
void initialize_true_outputs(float    & true_output_ss,
                             float    & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(1264.17918742);
  true_output_ss_err2=static_cast<float>(999410.19022388);

  // vector vector
  true_output_vv.push_back(static_cast<float>(1264.17918742));
  true_output_vv_err2.push_back(static_cast<float>(999410.19022388));
  true_output_vv.push_back(static_cast<float>(2528.35837484));
  true_output_vv_err2.push_back(static_cast<float>(3198566.25193769));
  true_output_vv.push_back(static_cast<float>(3792.53731813));
#ifdef LINUX
  true_output_vv_err2.push_back(static_cast<float>(5798393.50000000));
#else  
  true_output_vv_err2.push_back(static_cast<float>(5798394.23868356));
#endif
  true_output_vv.push_back(static_cast<float>(5056.71674969));
  true_output_vv_err2.push_back(static_cast<float>(8798893.46296149));
  true_output_vv.push_back(static_cast<float>(6320.89544883));
  true_output_vv_err2.push_back(static_cast<float>(12200063.17477150));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$d\_spacing\f$ and \f$d\_spacing\_err2\f$ for the double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$d\_spacing[0]\f$ and \f$d\_spacing\_err2[0]\f$)
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
 */
void initialize_true_outputs(double    & true_output_ss,
                             double    & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2)
{
  // scalar scalar
#ifdef LINUX
  true_output_ss=static_cast<double>(1264.17918742388204636);
  true_output_ss_err2=static_cast<double>(999410.2527238855836913);
#else
  true_output_ss=static_cast<double>(1264.17918742388204636);
  true_output_ss_err2=static_cast<double>(999410.25272388576716936);
#endif

  // vector vector
#ifdef LINUX
  true_output_vv.push_back(static_cast<double>(1264.17918742388204636));
  true_output_vv_err2.push_back(static_cast<double>(999410.2527238855836913));
#else
  true_output_vv.push_back(static_cast<double>(1264.17918742388204636));
  true_output_vv_err2.push_back(static_cast<double>(999410.25272388576716936));
#endif

  true_output_vv.push_back(static_cast<double>(2528.35837484776409272));

#ifdef LINUX
  true_output_vv_err2.push_back(static_cast<double>(3198566.5019376886030162));
#else
  true_output_vv_err2.push_back(static_cast<double>(3198566.5019376895343388));
#endif

#ifdef LINUX
  true_output_vv.push_back(static_cast<double>(3792.53756227164590728));
  true_output_vv_err2.push_back(static_cast<double>(5798394.2386835571378469));
#else
  true_output_vv.push_back(static_cast<double>(3792.53756227164590728));
  true_output_vv_err2.push_back(static_cast<double>(5798394.23868355906867743));
#endif

  true_output_vv.push_back(static_cast<double>(5056.71674969552818102));
#ifdef LINUX
  true_output_vv_err2.push_back(static_cast<double>(8798893.46296148933470250));
#else
  true_output_vv_err2.push_back(static_cast<double>(8798893.46296149186264514));
#endif

#ifdef LINUX
  true_output_vv.push_back(static_cast<double>(6320.8959371194099555));
  true_output_vv_err2.push_back(static_cast<double>(12200064.17477148696148395));
#else
  true_output_vv.push_back(static_cast<double>(6320.8959371194108650));
  true_output_vv_err2.push_back(static_cast<double>(12200064.17477148882412910));
#endif

}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>d_spacing_to_tof_focused_det</i> function
 * for the ss and vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by
 * <i>d_spacing_to_tof_focused_det</i> for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>d_spacing_to_tof_focused_det</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of the
 * true value for the ss case
 * \param output_vv (INPUT) is the value created by
 * <i>d_spacing_to_tof_focused_det</i> for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>d_spacing_to_tof_focused_det</i> for the vv case
 * \param true_output_vv (INPUT)) is the true value for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty of the
 * true value for the vv case
 */
template <typename NumT>
bool test_okay(NumT    & output_ss,
               NumT    & output_ss_err2,
               NumT    & true_output_ss,
               NumT    & true_output_ss_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
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

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the
 * <i>d_spacing_to_tof_focused_det</i> function (as described in the
 * documentation of the <i>d_spacing_to_tof_focused_det</i> function)
 * and launches the comparison of the data.
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
  Nessi::Vector<NumT>   d_spacing;
  Nessi::Vector<NumT>   d_spacing_err2;
  NumT                  pathlength_focused=static_cast<NumT>(2.75);
  NumT                  pathlength_focused_err2=static_cast<NumT>(0.75);
  NumT                  polar_angle_focused=static_cast<NumT> (4.0);
  NumT                  polar_angle_focused_err2=static_cast<NumT> (0.5);
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(NUM_VAL);
  Nessi::Vector<NumT>   output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(d_spacing, d_spacing_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::d_spacing_to_tof_focused_det(d_spacing[0], 
                                          d_spacing_err2[0],
                                          pathlength_focused,
                                          pathlength_focused_err2,
                                          polar_angle_focused,
                                          polar_angle_focused_err2,
                                          output_ss,
                                          output_ss_err2);

  AxisManip::d_spacing_to_tof_focused_det(d_spacing, 
                                          d_spacing_err2,
                                          pathlength_focused,
                                          pathlength_focused_err2,
                                          polar_angle_focused,
                                          polar_angle_focused_err2,
                                          output_vv,
                                          output_vv_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv, true_output_vv, VV, debug);
      print(output_vv_err2, true_output_vv_err2, ERROR+VV, debug);
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that test d_spacing_to_tof_focused_det for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "d_spacing_to_tof_focused_det_test.cpp..........";

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
 */  // end of d_spacing_to_tof_focused_det_test group
