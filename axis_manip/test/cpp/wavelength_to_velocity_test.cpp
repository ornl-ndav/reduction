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
 * \file axis_manip/test/cpp/wavelength_to_velocity_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL = 5;

/**
 * \defgroup wavelength_to_velocity_test wavelength_to_velocity_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>wavelength_to_velocity</i> and described in 3.20
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\f$ and \f$true\_output\_vv\f$ manually calculated.
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
 * This function initializes the value of arrays, \f$wavelength\f$ and 
 * \f$wavelength\_err2\f$.
 * \param wavelength (OUTPUT) is the wavelength axis in units of Angstroms
 * \param wavelength_err2 (OUTPUT) is the square of the uncertainty in the
 * wavelength axis.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & wavelength,
                       Nessi::Vector<NumT> & wavelength_err2)
{
  for( size_t i = 0; i < NUM_VAL; ++i )
    {
      wavelength.push_back(static_cast<NumT>(i+1));
      wavelength_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$wavelength\f$ and \f$wavelength\_err2\f$ for the float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$wavelength\_i[0]\f$ and \f$wavelength\_err2[0]\f$).
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
  true_output_ss=static_cast<float>(3.95603400e-03);
  true_output_ss_err2=static_cast<float>(7.82510250e-06);

  // vector vector
  true_output_vv.push_back(static_cast<float>(3.95603400e-03));
  true_output_vv_err2.push_back(static_cast<float>(7.82510250e-06));
  true_output_vv.push_back(static_cast<float>(1.97801700e-03));
  true_output_vv_err2.push_back(static_cast<float>(1.46720672e-06));
  true_output_vv.push_back(static_cast<float>(1.31867800e-03));
  true_output_vv_err2.push_back(static_cast<float>(4.83031019e-07));
  true_output_vv.push_back(static_cast<float>(9.89008500e-04));
  true_output_vv_err2.push_back(static_cast<float>(2.13967647e-07));
  true_output_vv.push_back(static_cast<float>(7.91206800e-04));
  true_output_vv_err2.push_back(static_cast<float>(1.12681476e-07));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$wavelength\f$ and \f$wavelength\_err2\f$ for the double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$wavelength\_i[0]\f$ and \f$wavelength\_err2[0]\f$).
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
  true_output_ss=static_cast<double>(3.95603399999999977e-03);
  true_output_ss_err2=static_cast<double>(7.82510250457799879e-06);

  // vector vector
  true_output_vv.push_back(static_cast<double>(3.95603399999999977e-03));
  true_output_vv_err2.push_back(static_cast<double>(7.82510250457799879e-06));
  true_output_vv.push_back(static_cast<double>(1.97801699999999988e-03));
  true_output_vv_err2.push_back(static_cast<double>(1.46720671960837467e-06));
  true_output_vv.push_back(static_cast<double>(1.31867799999999999e-03));
  true_output_vv_err2.push_back(static_cast<double>(4.83031018801111101e-07));
  true_output_vv.push_back(static_cast<double>(9.89008499999999941e-04));
  true_output_vv_err2.push_back(static_cast<double>(2.13967646609554648e-07));
  true_output_vv.push_back(static_cast<double>(7.91206799999999975e-04));
  true_output_vv_err2.push_back(static_cast<double>(1.12681476065923179e-07));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>wavelength_to_velocity</i> function for the ss 
 * and vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by 
 * <i>wavelength_to_velocity</i> for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>wavelength_to_velocity</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of the
 * true value for the ss case
 * \param output_vv (INPUT) is the array created by 
 * <i>wavelength_to_velocity</i> for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>wavelength_to_velocity</i> for the vv case
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
  if(!test_okay(output_ss, true_output_ss))
    {
      value = false;
    }
  if(!test_okay(output_ss_err2, true_output_ss_err2))
    {
      value = false;
    }

  // vector vector
  if(!test_okay(output_vv,true_output_vv, VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2,true_output_vv_err2, VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>wavelength_to_velocity</i> 
 * function (as described in the documentation of the 
 * <i>wavelength_to_velocity</i> function) and launches the comparison of the 
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
  Nessi::Vector<NumT>   wavelength;
  Nessi::Vector<NumT>   wavelength_err2;
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(NUM_VAL);
  Nessi::Vector<NumT>   output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(wavelength, wavelength_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested

  AxisManip::wavelength_to_velocity(wavelength[0], wavelength_err2[0],
                                    output_ss,
                                    output_ss_err2);

  AxisManip::wavelength_to_velocity(wavelength, wavelength_err2,
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
 * Main function that test wavelength_to_velocity for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "wavelength_to_velocity_test.cpp..........";

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
 */  // end of wavelength_to_velocity_test.cpp group

