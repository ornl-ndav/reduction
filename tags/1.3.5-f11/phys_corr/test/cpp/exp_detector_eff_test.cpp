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
 * \file phys_corr/test/cpp/exp_detector_eff_test.cpp
 */

#include "physcorr.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup exp_detector_eff_test exp_detector_eff_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>exp_detector_eff</i> and described in 3.66
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
 * This function initializes the value of arrays \f$axis\_bc\f$.
 * \param axis_bc (OUTPUT) is the wavelength axis in units of Angstroms
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis_bc)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      axis_bc.push_back(static_cast<NumT>(i+1));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis_bc\f$ for the float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * \f$axis\_bc[0]\f$.
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
  true_output_ss = static_cast<float>(1.35335283);
  true_output_ss_err2 = static_cast<float>(1.83156389e-03);

  // vector vector
  true_output_vv.push_back(static_cast<float>(1.35335283));
  true_output_vv_err2.push_back(static_cast<float>(1.83156389e-03));
  true_output_vv.push_back(static_cast<float>(1.83156389e-01));
  true_output_vv_err2.push_back(static_cast<float>(3.35462628e-05));
  true_output_vv.push_back(static_cast<float>(2.47875218e-02));
  true_output_vv_err2.push_back(static_cast<float>(6.14421235e-07));
  true_output_vv.push_back(static_cast<float>(3.35462628e-03));
  true_output_vv_err2.push_back(static_cast<float>(1.12535175e-08));
  true_output_vv.push_back(static_cast<float>(4.53999298e-04));
  true_output_vv_err2.push_back(static_cast<float>(2.06115362e-10));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis\_bc\f$ and \f$tof\_err2\f$ for the double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * \f$axis\_bc[0]\f$.
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
  true_output_ss = static_cast<double>(1.35335283236612702);
  true_output_ss_err2 = static_cast<double>(1.83156388887341804e-03);

  // vector vector
  true_output_vv.push_back(static_cast<double>(1.35335283236612702));
  true_output_vv_err2.push_back(static_cast<double>(1.83156388887341804e-03));
  true_output_vv.push_back(static_cast<double>(1.83156388887341787e-01));
  true_output_vv_err2.push_back(static_cast<double>(3.35462627902511894e-05));
  true_output_vv.push_back(static_cast<double>(2.47875217666635866e-02));
  true_output_vv_err2.push_back(static_cast<double>(6.14421235332821002e-07));
  true_output_vv.push_back(static_cast<double>(3.35462627902511842e-03));
  true_output_vv_err2.push_back(static_cast<double>(1.12535174719259130e-08));
  true_output_vv.push_back(static_cast<double>(4.53999297624848555e-04));
  true_output_vv_err2.push_back(static_cast<double>(2.06115362243855797e-10));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>exp_detector_eff</i> function for the ss and
 * vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by <i>exp_detector_eff</i>
 * for the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>exp_detector_eff</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of the
 * true value for the ss case
 * \param output_vv (INPUT) is the array created by <i>exp_detector_eff</i>
 * for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>exp_detector_eff</i> for the vv case
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
  if(!test_okay(output_vv, true_output_vv, VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2, true_output_vv_err2, VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>exp_detector_eff</i> function
 * (as described in the documentation of the <i>exp_detector_eff</i> function)
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
  Nessi::Vector<NumT>   axis_bc;
  NumT                  scale = static_cast<NumT>(10.);
  NumT                  scale_err2 = static_cast<NumT>(0.1);
  NumT                  constant = static_cast<NumT>(2.0);
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(NUM_VAL);
  Nessi::Vector<NumT>   output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(axis_bc);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested

  PhysCorr::exp_detector_eff(axis_bc[0], scale, scale_err2, constant,
                             output_ss, output_ss_err2);

  PhysCorr::exp_detector_eff(axis_bc, scale, scale_err2, constant,
                             output_vv, output_vv_err2);

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
 * Main function that test exp_detector_eff for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "exp_detector_eff_test.cpp..........";

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
 */  // end of exp_detector_eff_test.cpp group

