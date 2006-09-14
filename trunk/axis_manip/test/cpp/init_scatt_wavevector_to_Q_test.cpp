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
 * \file axis_manip/test/cpp/init_scatt_wavevector_to_Q_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup init_scatt_wavevector_to_Q_test init_scatt_wavevector_to_Q_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>init_scatt_wavevector_to_Q</i> and described in 3.32
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\_Qx\f$, \f$true\_output\_ss\_Qy\f$,
 * \f$true\_output\_ss\_Qz\f$, \f$true\_output\_sv\_Qx\f$,
 * \f$true\_output\_sv\_Qy\f$, \f$true\_output\_sv\_Qz\f$, 
 * \f$true\_output\_vs\_Qx\f$, \f$true\_output\_vs\_Qy\f$,
 * \f$true\_output\_vs\_Qz\f$, \f$true\_output\_vv\_Qx\f$,
 * \f$true\_output\_vv\_Qy\f$, \f$true\_output\_vv\_Qz\f$,
 * manually calculated. Any discrepancy between the outputs 
 * (\f$output\f$ and \f$true\_output\f$) will generate in the testsuite.log 
 * file an error message that gives details about the location and type of 
 * the error.
 *
 * <b>Notation used:</b>
 * - ss : scalar-scalar
 * - vv : vector-vector
 * - vs : vector-scalar
 * - sv : scalar-vector
 * - SS : "s,s"
 * - VV = "v,v"
 * - SV = "s,v"
 * - VS = "v,s"
 * - ERROR = "Error"
 * - EMPTY = ""
 */

/**
 * This function initializes the value of arrays, \f$k\_i\f$, \f$k\_i\_err2\f$,
 * \f$k\_f\f$, and \f$k\_f\_err2\f$.
 *
 * \param k_i (OUTPUT) is the incident wavevector axis in units of reciprocal
 * Angstroms
 * \param k_i_err2 (OUTPUT) is the square of the uncertainty of the incident
 * wavevector axis
 * \param k_f (OUTPUT) is the final wavevector axis in units of reciprocal
 * Angstroms
 * \param k_f_err2 (OUTPUT) is the square of the uncertainty of the final
 * wavector axis
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & k_i,
                       Nessi::Vector<NumT> & k_i_err2,
                       Nessi::Vector<NumT> & k_f,
                       Nessi::Vector<NumT> & k_f_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      k_i.push_back(static_cast<NumT>(i+1));
      k_i_err2.push_back(static_cast<NumT>(i+0.5));
      k_f.push_back(static_cast<NumT>(i+1.25));
      k_f_err2.push_back(static_cast<NumT>(i+0.25));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$k\_i\f$, \f$k\_i\_err2\f$, \f$k\_f\f$, and \f$k\_f\_err2\f$ for the
 * float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$k\_i[0]\f$, \f$k\_i\_err2[0]\f$, \f$k\_f[0]\f$, and
 * \f$k\_f\_err2[0]\f$).
 *
 * \param true_output_ss_Qx (OUTPUT) is the true output for Qx for the ss case
 * \param true_output_ss_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the ss case
 * \param true_output_ss_Qy (OUTPUT) is the true output for Qy for the ss case
 * \param true_output_ss_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the ss case
 * \param true_output_ss_Qz (OUTPUT) is the true output for Qz for the ss case
 * \param true_output_ss_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the ss case
 * \param true_output_sv_Qx (OUTPUT) is the true array for Qx for the sv case
 * \param true_output_sv_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the sv case
 * \param true_output_sv_Qy (OUTPUT) is the true array for Qy for the sv case
 * \param true_output_sv_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the sv case
 * \param true_output_sv_Qz (OUTPUT) is the true array for Qz for the sv case
 * \param true_output_sv_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the sv case
 * \param true_output_vs_Qx (OUTPUT) is the true array for Qx for the vs case
 * \param true_output_vs_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the vs case
 * \param true_output_vs_Qy (OUTPUT) is the true array for Qy for the vs case
 * \param true_output_vs_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the vs case
 * \param true_output_vs_Qz (OUTPUT) is the true array for Qz for the vs case
 * \param true_output_vs_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the vs case
 * \param true_output_vv_Qx (OUTPUT) is the true array for Qx for the vv case
 * \param true_output_vv_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the vv case
 * \param true_output_vv_Qy (OUTPUT) is the true array for Qy for the vv case
 * \param true_output_vv_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the vv case
 * \param true_output_vv_Qz (OUTPUT) is the true array for Qz for the vv case
 * \param true_output_vv_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the vv case
 */
void initialize_true_outputs(float                & true_output_ss_Qx,
                             float                & true_output_ss_Qx_err2,
                             float                & true_output_ss_Qy,
                             float                & true_output_ss_Qy_err2,
                             float                & true_output_ss_Qz,
                             float                & true_output_ss_Qz_err2,
                             Nessi::Vector<float> & true_output_sv_Qx,
                             Nessi::Vector<float> & true_output_sv_Qx_err2,
                             Nessi::Vector<float> & true_output_sv_Qy,
                             Nessi::Vector<float> & true_output_sv_Qy_err2,
                             Nessi::Vector<float> & true_output_sv_Qz,
                             Nessi::Vector<float> & true_output_sv_Qz_err2,
                             Nessi::Vector<float> & true_output_vs_Qx,
                             Nessi::Vector<float> & true_output_vs_Qx_err2,
                             Nessi::Vector<float> & true_output_vs_Qy,
                             Nessi::Vector<float> & true_output_vs_Qy_err2,
                             Nessi::Vector<float> & true_output_vs_Qz,
                             Nessi::Vector<float> & true_output_vs_Qz_err2,
                             Nessi::Vector<float> & true_output_vv_Qx,
                             Nessi::Vector<float> & true_output_vv_Qx_err2,
                             Nessi::Vector<float> & true_output_vv_Qy,
                             Nessi::Vector<float> & true_output_vv_Qy_err2,
                             Nessi::Vector<float> & true_output_vv_Qz,
                             Nessi::Vector<float> & true_output_vv_Qz_err2)

{
  // scalar scalar
  true_output_ss_Qx=static_cast<float>(-0.17380656);
  true_output_ss_Qx_err2=static_cast<float>(0.09073486);
  true_output_ss_Qy=static_cast<float>(-0.21024756);
  true_output_ss_Qy_err2=static_cast<float>(0.11760239);
  true_output_ss_Qz=static_cast<float>(-0.21987181);
  true_output_ss_Qz_err2=static_cast<float>(0.74627936);

  // scalar vector
  true_output_sv_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_sv_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_sv_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_sv_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_sv_Qz.push_back(static_cast<float>(-0.21987181));
  true_output_sv_Qz_err2.push_back(static_cast<float>(0.74627936));

  true_output_sv_Qx.push_back(static_cast<float>(-0.31285182));
  true_output_sv_Qx_err2.push_back(static_cast<float>(0.30248772));
  true_output_sv_Qy.push_back(static_cast<float>(-0.37844562));
  true_output_sv_Qy_err2.push_back(static_cast<float>(0.39347961));
  true_output_sv_Qz.push_back(static_cast<float>(-1.19576926));
  true_output_sv_Qz_err2.push_back(static_cast<float>(1.71699049));

  true_output_sv_Qx.push_back(static_cast<float>(-0.45189707));
  true_output_sv_Qx_err2.push_back(static_cast<float>(0.62419446));
  true_output_sv_Qy.push_back(static_cast<float>(-0.54664367));
  true_output_sv_Qy_err2.push_back(static_cast<float>(0.81083490));
  true_output_sv_Qz.push_back(static_cast<float>(-2.17166671));
  true_output_sv_Qz_err2.push_back(static_cast<float>(2.69817872));

#ifdef LINUX64
  true_output_sv_Qx.push_back(static_cast<float>(-0.59094232));
  true_output_sv_Qx_err2.push_back(static_cast<float>(1.05585507));
  true_output_sv_Qy.push_back(static_cast<float>(-0.71484173));
  true_output_sv_Qy_err2.push_back(static_cast<float>(1.36966827));
  true_output_sv_Qz.push_back(static_cast<float>(-3.14756392));
  true_output_sv_Qz_err2.push_back(static_cast<float>(3.68984472));
#else
  true_output_sv_Qx.push_back(static_cast<float>(-0.59094232));
  true_output_sv_Qx_err2.push_back(static_cast<float>(1.05585507));
  true_output_sv_Qy.push_back(static_cast<float>(-0.71484173));
  true_output_sv_Qy_err2.push_back(static_cast<float>(1.36966827));
  true_output_sv_Qz.push_back(static_cast<float>(-3.1475642));
  true_output_sv_Qz_err2.push_back(static_cast<float>(3.68984472));
#endif

#ifdef LINUX64
  true_output_sv_Qx.push_back(static_cast<float>(-0.72998758));
  true_output_sv_Qx_err2.push_back(static_cast<float>(1.59746921));
  true_output_sv_Qy.push_back(static_cast<float>(-0.88303978));
  true_output_sv_Qy_err2.push_back(static_cast<float>(2.06997925));
  true_output_sv_Qz.push_back(static_cast<float>(-4.12346160));
  true_output_sv_Qz_err2.push_back(static_cast<float>(4.69198733));
#else
  true_output_sv_Qx.push_back(static_cast<float>(-0.72998758));
  true_output_sv_Qx_err2.push_back(static_cast<float>(1.59746921));
  true_output_sv_Qy.push_back(static_cast<float>(-0.88303978));
  true_output_sv_Qy_err2.push_back(static_cast<float>(2.0699797));
  true_output_sv_Qz.push_back(static_cast<float>(-4.12346160));
  true_output_sv_Qz_err2.push_back(static_cast<float>(4.69198733));
#endif

  // vector scalar
  true_output_vs_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vs_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vs_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vs_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vs_Qz.push_back(static_cast<float>(-0.21987181));
  true_output_vs_Qz_err2.push_back(static_cast<float>(0.74627936));

  true_output_vs_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vs_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vs_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vs_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vs_Qz.push_back(static_cast<float>(0.78012818));
  true_output_vs_Qz_err2.push_back(static_cast<float>(1.74627936));

  true_output_vs_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vs_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vs_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vs_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vs_Qz.push_back(static_cast<float>(1.78012818));
  true_output_vs_Qz_err2.push_back(static_cast<float>(2.74627913));

  true_output_vs_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vs_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vs_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vs_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vs_Qz.push_back(static_cast<float>(2.78012818));
  true_output_vs_Qz_err2.push_back(static_cast<float>(3.74627913));

  true_output_vs_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vs_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vs_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vs_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vs_Qz.push_back(static_cast<float>(3.78012818));
  true_output_vs_Qz_err2.push_back(static_cast<float>(4.74627936));

  // vector vector
  true_output_vv_Qx.push_back(static_cast<float>(-0.17380656));
  true_output_vv_Qx_err2.push_back(static_cast<float>(0.09073486));
  true_output_vv_Qy.push_back(static_cast<float>(-0.21024756));
  true_output_vv_Qy_err2.push_back(static_cast<float>(0.11760239));
  true_output_vv_Qz.push_back(static_cast<float>(-0.21987181));
  true_output_vv_Qz_err2.push_back(static_cast<float>(0.74627936));

  true_output_vv_Qx.push_back(static_cast<float>(-0.31285182));
  true_output_vv_Qx_err2.push_back(static_cast<float>(0.30248772));
  true_output_vv_Qy.push_back(static_cast<float>(-0.37844562));
  true_output_vv_Qy_err2.push_back(static_cast<float>(0.39347961));
  true_output_vv_Qz.push_back(static_cast<float>(-0.19576926));
  true_output_vv_Qz_err2.push_back(static_cast<float>(2.71699049));

#ifdef LINUX64
  true_output_vv_Qx.push_back(static_cast<float>(-0.45189707));
  true_output_vv_Qx_err2.push_back(static_cast<float>(0.62419446));
  true_output_vv_Qy.push_back(static_cast<float>(-0.54664367));
  true_output_vv_Qy_err2.push_back(static_cast<float>(0.81083490));
  true_output_vv_Qz.push_back(static_cast<float>(-0.17166671));
  true_output_vv_Qz_err2.push_back(static_cast<float>(4.69817848));
#else
  true_output_vv_Qx.push_back(static_cast<float>(-0.45189707));
  true_output_vv_Qx_err2.push_back(static_cast<float>(0.62419446));
  true_output_vv_Qy.push_back(static_cast<float>(-0.54664367));
  true_output_vv_Qy_err2.push_back(static_cast<float>(0.81083490));
  true_output_vv_Qz.push_back(static_cast<float>(-0.17166671));
  true_output_vv_Qz_err2.push_back(static_cast<float>(4.6981788));
#endif

#ifdef LINUX64
  true_output_vv_Qx.push_back(static_cast<float>(-0.59094232));
  true_output_vv_Qx_err2.push_back(static_cast<float>(1.05585507));
  true_output_vv_Qy.push_back(static_cast<float>(-0.71484173));
  true_output_vv_Qy_err2.push_back(static_cast<float>(1.36966827));
  true_output_vv_Qz.push_back(static_cast<float>(-0.14756394));
  true_output_vv_Qz_err2.push_back(static_cast<float>(6.68984472));
#else
  true_output_vv_Qx.push_back(static_cast<float>(-0.59094232));
  true_output_vv_Qx_err2.push_back(static_cast<float>(1.05585507));
  true_output_vv_Qy.push_back(static_cast<float>(-0.71484173));
  true_output_vv_Qy_err2.push_back(static_cast<float>(1.36966827));
  true_output_vv_Qz.push_back(static_cast<float>(-0.1475641));
  true_output_vv_Qz_err2.push_back(static_cast<float>(6.6898441));
#endif

#ifdef LINUX64
  true_output_vv_Qx.push_back(static_cast<float>(-0.72998758));
  true_output_vv_Qx_err2.push_back(static_cast<float>(1.59746921));
  true_output_vv_Qy.push_back(static_cast<float>(-0.88303978));
  true_output_vv_Qy_err2.push_back(static_cast<float>(2.06997925));
  true_output_vv_Qz.push_back(static_cast<float>(-0.12346172));
  true_output_vv_Qz_err2.push_back(static_cast<float>(8.69198685));
#else
  true_output_vv_Qx.push_back(static_cast<float>(-0.72998758));
  true_output_vv_Qx_err2.push_back(static_cast<float>(1.59746921));
  true_output_vv_Qy.push_back(static_cast<float>(-0.88303978));
  true_output_vv_Qy_err2.push_back(static_cast<float>(2.0699797));
  true_output_vv_Qz.push_back(static_cast<float>(-0.1234615));
  true_output_vv_Qz_err2.push_back(static_cast<float>(8.69198685));
#endif

}

/**
 * This function sets the true outputs based on values contained in
 * \f$k\_i\f$, \f$k\_i\_err2\f$, \f$k\_f\f$, and \f$k\_f\_err2\f$ for the
 * double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays (
 * \f$k\_i[0]\f$, \f$k\_i\_err2[0]\f$, \f$k\_f[0]\f$, and \f$k\_f\_err2[0]\f$.
 *
 * \param true_output_ss_Qx (OUTPUT) is the true output for Qx for the ss case
 * \param true_output_ss_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the ss case
 * \param true_output_ss_Qy (OUTPUT) is the true output for Qy for the ss case
 * \param true_output_ss_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the ss case
 * \param true_output_ss_Qz (OUTPUT) is the true output for Qz for the ss case
 * \param true_output_ss_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the ss case
 * \param true_output_sv_Qx (OUTPUT) is the true array for Qx for the sv case
 * \param true_output_sv_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the sv case
 * \param true_output_sv_Qy (OUTPUT) is the true array for Qy for the sv case
 * \param true_output_sv_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the sv case
 * \param true_output_sv_Qz (OUTPUT) is the true array for Qz for the sv case
 * \param true_output_sv_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the sv case
 * \param true_output_vs_Qx (OUTPUT) is the true array for Qx for the vs case
 * \param true_output_vs_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the vs case
 * \param true_output_vs_Qy (OUTPUT) is the true array for Qy for the vs case
 * \param true_output_vs_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the vs case
 * \param true_output_vs_Qz (OUTPUT) is the true array for Qz for the vs case
 * \param true_output_vs_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the vs case
 * \param true_output_vv_Qx (OUTPUT) is the true array for Qx for the vv case
 * \param true_output_vv_Qx_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qx for the vv case
 * \param true_output_vv_Qy (OUTPUT) is the true array for Qy for the vv case
 * \param true_output_vv_Qy_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qy for the vv case
 * \param true_output_vv_Qz (OUTPUT) is the true array for Qz for the vv case
 * \param true_output_vv_Qz_err2 (OUTPUT) is the square of the uncertainty of 
 * the true output for Qz for the vv case
 */
void initialize_true_outputs(double                & true_output_ss_Qx,
                             double                & true_output_ss_Qx_err2,
                             double                & true_output_ss_Qy,
                             double                & true_output_ss_Qy_err2,
                             double                & true_output_ss_Qz,
                             double                & true_output_ss_Qz_err2,
                             Nessi::Vector<double> & true_output_sv_Qx,
                             Nessi::Vector<double> & true_output_sv_Qx_err2,
                             Nessi::Vector<double> & true_output_sv_Qy,
                             Nessi::Vector<double> & true_output_sv_Qy_err2,
                             Nessi::Vector<double> & true_output_sv_Qz,
                             Nessi::Vector<double> & true_output_sv_Qz_err2,
                             Nessi::Vector<double> & true_output_vs_Qx,
                             Nessi::Vector<double> & true_output_vs_Qx_err2,
                             Nessi::Vector<double> & true_output_vs_Qy,
                             Nessi::Vector<double> & true_output_vs_Qy_err2,
                             Nessi::Vector<double> & true_output_vs_Qz,
                             Nessi::Vector<double> & true_output_vs_Qz_err2,
                             Nessi::Vector<double> & true_output_vv_Qx,
                             Nessi::Vector<double> & true_output_vv_Qx_err2,
                             Nessi::Vector<double> & true_output_vv_Qy,
                             Nessi::Vector<double> & true_output_vv_Qy_err2,
                             Nessi::Vector<double> & true_output_vv_Qz,
                             Nessi::Vector<double> & true_output_vv_Qz_err2)
{
  // scalar scalar 
  true_output_ss_Qx=static_cast<double>(-0.17380656755500100);
  true_output_ss_Qx_err2=static_cast<double>(0.09073486048493280);
  true_output_ss_Qy=static_cast<double>(-0.21024756879486733);
  true_output_ss_Qy_err2=static_cast<double>(0.11760239343867500);
  true_output_ss_Qz=static_cast<double>(-0.21987181166325700);
  true_output_ss_Qz_err2=static_cast<double>(0.74627936184453000);

  // scalar vector
  true_output_sv_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_sv_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_sv_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_sv_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_sv_Qz.push_back(static_cast<double>(-0.21987181166325700));
  true_output_sv_Qz_err2.push_back(static_cast<double>(0.74627936184453000));

  true_output_sv_Qx.push_back(static_cast<double>(-0.31285182159900200));
  true_output_sv_Qx_err2.push_back(static_cast<double>(0.30248772434693300));
  true_output_sv_Qy.push_back(static_cast<double>(-0.37844562383076100));
  true_output_sv_Qy_err2.push_back(static_cast<double>(0.39347961245716444));
  true_output_sv_Qz.push_back(static_cast<double>(-1.19576926099386244));
  true_output_sv_Qz_err2.push_back(static_cast<double>(1.71699049828466867));

  true_output_sv_Qx.push_back(static_cast<double>(-0.45189707564300251));
  true_output_sv_Qx_err2.push_back(static_cast<double>(0.62419446317455556));
  true_output_sv_Qy.push_back(static_cast<double>(-0.54664367886665500));
  true_output_sv_Qy_err2.push_back(static_cast<double>(0.81083490764744300));
  true_output_sv_Qz.push_back(static_cast<double>(-2.17166671032446778));
  true_output_sv_Qz_err2.push_back(static_cast<double>(2.69817895177061133));
    
#ifdef LINUX64
  true_output_sv_Qx.push_back(static_cast<double>(-0.59094232968700300));
  true_output_sv_Qx_err2.push_back(static_cast<double>(1.05585507696780088));
  true_output_sv_Qy.push_back(static_cast<double>(-0.71484173390254900));
  true_output_sv_Qy_err2.push_back(static_cast<double>(1.36966827900951199));
  true_output_sv_Qz.push_back(static_cast<double>(-3.14756415965507310));
  true_output_sv_Qz_err2.push_back(static_cast<double>(3.68984472230235778));
#else
  true_output_sv_Qx.push_back(static_cast<double>(-0.59094232968700300));
  true_output_sv_Qx_err2.push_back(static_cast<double>(1.05585507696780088));
  true_output_sv_Qy.push_back(static_cast<double>(-0.71484173390254900));
  true_output_sv_Qy_err2.push_back(static_cast<double>(1.36966827900951199));
  true_output_sv_Qz.push_back(static_cast<double>(-3.1475641596550736));
  true_output_sv_Qz_err2.push_back(static_cast<double>(3.68984472230235778));
#endif

  true_output_sv_Qx.push_back(static_cast<double>(-0.72998758373100400));
  true_output_sv_Qx_err2.push_back(static_cast<double>(1.59746956572666845));
  true_output_sv_Qy.push_back(static_cast<double>(-0.88303978893844267));
  true_output_sv_Qy_err2.push_back(static_cast<double>(2.06997972654337000));
  true_output_sv_Qz.push_back(static_cast<double>(-4.12346160898567823));
  true_output_sv_Qz_err2.push_back(static_cast<double>(4.69198780987990912));

  // vector scalar
  true_output_vs_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vs_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vs_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vs_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vs_Qz.push_back(static_cast<double>(-0.21987181166325700));
  true_output_vs_Qz_err2.push_back(static_cast<double>(0.74627936184453000));

  true_output_vs_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vs_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vs_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vs_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vs_Qz.push_back(static_cast<double>(0.78012818833674300));
  true_output_vs_Qz_err2.push_back(static_cast<double>(1.74627936184453000));

  true_output_vs_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vs_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vs_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vs_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vs_Qz.push_back(static_cast<double>(1.78012818833674310));
  true_output_vs_Qz_err2.push_back(static_cast<double>(2.74627936184453000));

  true_output_vs_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vs_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vs_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vs_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vs_Qz.push_back(static_cast<double>(2.78012818833674310));
  true_output_vs_Qz_err2.push_back(static_cast<double>(3.74627936184453000));

  true_output_vs_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vs_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vs_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vs_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vs_Qz.push_back(static_cast<double>(3.78012818833674310));
  true_output_vs_Qz_err2.push_back(static_cast<double>(4.74627936184453000));

  // vector vector 
  true_output_vv_Qx.push_back(static_cast<double>(-0.17380656755500100));
  true_output_vv_Qx_err2.push_back(static_cast<double>(0.09073486048493280));
  true_output_vv_Qy.push_back(static_cast<double>(-0.21024756879486733));
  true_output_vv_Qy_err2.push_back(static_cast<double>(0.11760239343867500));
  true_output_vv_Qz.push_back(static_cast<double>(-0.21987181166325700));
  true_output_vv_Qz_err2.push_back(static_cast<double>(0.74627936184453000));

  true_output_vv_Qx.push_back(static_cast<double>(-0.31285182159900200));
  true_output_vv_Qx_err2.push_back(static_cast<double>(0.30248772434693300));
  true_output_vv_Qy.push_back(static_cast<double>(-0.37844562383076100));
  true_output_vv_Qy_err2.push_back(static_cast<double>(0.39347961245716444));
  true_output_vv_Qz.push_back(static_cast<double>(-0.19576926099386238));
  true_output_vv_Qz_err2.push_back(static_cast<double>(2.71699049828466823));

  true_output_vv_Qx.push_back(static_cast<double>(-0.45189707564300253));
  true_output_vv_Qx_err2.push_back(static_cast<double>(0.62419446317455556));
  true_output_vv_Qy.push_back(static_cast<double>(-0.54664367886665500));
  true_output_vv_Qy_err2.push_back(static_cast<double>(0.81083490764744300));
  true_output_vv_Qz.push_back(static_cast<double>(-0.17166671032446800));
  true_output_vv_Qz_err2.push_back(static_cast<double>(4.69817895177061088));

#ifdef LINUX64
  true_output_vv_Qx.push_back(static_cast<double>(-0.59094232968700300));
  true_output_vv_Qx_err2.push_back(static_cast<double>(1.05585507696780088));
  true_output_vv_Qy.push_back(static_cast<double>(-0.71484173390254900));
  true_output_vv_Qy_err2.push_back(static_cast<double>(1.36966827900951199));
  true_output_vv_Qz.push_back(static_cast<double>(-0.14756415965507300));
  true_output_vv_Qz_err2.push_back(static_cast<double>(6.68984472230235823));
#else
  true_output_vv_Qx.push_back(static_cast<double>(-0.59094232968700300));
  true_output_vv_Qx_err2.push_back(static_cast<double>(1.05585507696780088));
  true_output_vv_Qy.push_back(static_cast<double>(-0.71484173390254900));
  true_output_vv_Qy_err2.push_back(static_cast<double>(1.36966827900951199));
  true_output_vv_Qz.push_back(static_cast<double>(-0.1475641596550734));
  true_output_vv_Qz_err2.push_back(static_cast<double>(6.68984472230235823));
#endif

#ifdef LINUX64
  true_output_vv_Qx.push_back(static_cast<double>(-0.72998758373100400));
  true_output_vv_Qx_err2.push_back(static_cast<double>(1.59746956572666845));
  true_output_vv_Qy.push_back(static_cast<double>(-0.88303978893844267));
  true_output_vv_Qy_err2.push_back(static_cast<double>(2.06997972654337000));
  true_output_vv_Qz.push_back(static_cast<double>(-0.12346160898567860));
  true_output_vv_Qz_err2.push_back(static_cast<double>(8.69198780987991000));
#else
  true_output_vv_Qx.push_back(static_cast<double>(-0.72998758373100400));
  true_output_vv_Qx_err2.push_back(static_cast<double>(1.59746956572666845));
  true_output_vv_Qy.push_back(static_cast<double>(-0.88303978893844267));
  true_output_vv_Qy_err2.push_back(static_cast<double>(2.06997972654337000));
  true_output_vv_Qz.push_back(static_cast<double>(-0.1234616089856790));
  true_output_vv_Qz_err2.push_back(static_cast<double>(8.69198780987991000));
#endif

}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>init_scatt_wavevector_to_Q</i> function
 * for the ss, sv, vs and  vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss_Qx (INPUT) is the value created by
 * <i>init_scatt_wavevector_to_Q</i> for Qx for the ss case
 * \param output_ss_Qx_err2 (INPUT) is the square of the uncertainty of the 
 * value created by <i>init_scatt_wavevector_to_Q</i> for Qx for the ss case
 * \param true_output_ss_Qx (INPUT)) is the true value for Qx for the ss case
 * \param true_output_ss_Qx_err2 (INPUT) is the square of the uncertainty of 
 * the true value for Qx for the ss case
 * \param output_ss_Qy (INPUT) is the value created by
 * <i>init_scatt_wavevector_to_Q</i> for Qy for the ss case
 * \param output_ss_Qy_err2 (INPUT) is the square of the uncertainty of the 
 * value created by <i>init_scatt_wavevector_to_Q</i> for Qy for the ss case
 * \param true_output_ss_Qy (INPUT)) is the true value for Qy for the ss case
 * \param true_output_ss_Qy_err2 (INPUT) is the square of the uncertainty of 
 * the true value for Qy for the ss case
 * \param output_ss_Qz (INPUT) is the value created by
 * <i>init_scatt_wavevector_to_Q</i> for Qz for the ss case
 * \param output_ss_Qz_err2 (INPUT) is the square of the uncertainty of the 
 * value created by <i>init_scatt_wavevector_to_Q</i> for Qz for the ss case
 * \param true_output_ss_Qz (INPUT)) is the true value for Qz for the ss case
 * \param true_output_ss_Qz_err2 (INPUT) is the square of the uncertainty of 
 * the true value for Qz for the ss case
 * \param output_sv_Qx (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qx for the sv case
 * \param output_sv_Qx_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qx for the sv case
 * \param true_output_sv_Qx (INPUT) is the true array for Qx for the sv case
 * \param true_output_sv_Qx_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qx for the sv case
 * \param output_sv_Qy (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qy for the sv case
 * \param output_sv_Qy_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qy for the sv case
 * \param true_output_sv_Qy (INPUT) is the true array for Qy for the sv case
 * \param true_output_sv_Qy_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qy for the sv case
 * \param output_sv_Qz (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qz for the sv case
 * \param output_sv_Qz_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qz for the sv case
 * \param true_output_sv_Qz (INPUT) is the true array for Qz for the sv case
 * \param true_output_sv_Qz_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qz for the sv case
 * \param output_vs_Qx (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qx for the vs case
 * \param output_vs_Qx_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qx for the vs case
 * \param true_output_vs_Qx (INPUT) is the true array for Qx for the vs case
 * \param true_output_vs_Qx_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qx for the vs case
 * \param output_vs_Qy (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qy for the vs case
 * \param output_vs_Qy_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qy for the vs case
 * \param true_output_vs_Qy (INPUT) is the true array for Qy for the vs case
 * \param true_output_vs_Qy_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qy for the vs case
 * \param output_vs_Qz (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qz for the vs case
 * \param output_vs_Qz_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qz for the vs case
 * \param true_output_vs_Qz (INPUT) is the true array for Qz for the vs case
 * \param true_output_vs_Qz_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qz for the vs case
 * \param output_vv_Qx (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qx for the vv case
 * \param output_vv_Qx_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qx for the vv case
 * \param true_output_vv_Qx (INPUT) is the true array for Qx for the vv case
 * \param true_output_vv_Qx_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qx for the vv case
 * \param output_vv_Qy (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qy for the vv case
 * \param output_vv_Qy_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qy for the vv case
 * \param true_output_vv_Qy (INPUT) is the true array for Qy for the vv case
 * \param true_output_vv_Qy_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qy for the vv case
 * \param output_vv_Qz (INPUT) is the array created by
 * <i>init_scatt_wavevector_to_Q</i> for Qz for the vv case
 * \param output_vv_Qz_err2 (INPUT) is the square of the uncertainty in the 
 * array created by <i>init_scatt_wavevector_to_Q</i> for Qz for the vv case
 * \param true_output_vv_Qz (INPUT) is the true array for Qz for the vv case
 * \param true_output_vv_Qz_err2 (INPUT) is the square of the uncertainty in 
 * the true array for Qz for the vv case
 */
template <typename NumT>
bool test_okay(NumT                & output_ss_Qx,
               NumT                & output_ss_Qx_err2,
               NumT                & true_output_ss_Qx,
               NumT                & true_output_ss_Qx_err2,
               NumT                & output_ss_Qy,
               NumT                & output_ss_Qy_err2,
               NumT                & true_output_ss_Qy,
               NumT                & true_output_ss_Qy_err2,
               NumT                & output_ss_Qz,
               NumT                & output_ss_Qz_err2,
               NumT                & true_output_ss_Qz,
               NumT                & true_output_ss_Qz_err2,
               Nessi::Vector<NumT> & output_sv_Qx,
               Nessi::Vector<NumT> & output_sv_Qx_err2,
               Nessi::Vector<NumT> & true_output_sv_Qx,
               Nessi::Vector<NumT> & true_output_sv_Qx_err2,
               Nessi::Vector<NumT> & output_sv_Qy,
               Nessi::Vector<NumT> & output_sv_Qy_err2,
               Nessi::Vector<NumT> & true_output_sv_Qy,
               Nessi::Vector<NumT> & true_output_sv_Qy_err2,
               Nessi::Vector<NumT> & output_sv_Qz,
               Nessi::Vector<NumT> & output_sv_Qz_err2,
               Nessi::Vector<NumT> & true_output_sv_Qz,
               Nessi::Vector<NumT> & true_output_sv_Qz_err2,
               Nessi::Vector<NumT> & output_vs_Qx,
               Nessi::Vector<NumT> & output_vs_Qx_err2,
               Nessi::Vector<NumT> & true_output_vs_Qx,
               Nessi::Vector<NumT> & true_output_vs_Qx_err2,
               Nessi::Vector<NumT> & output_vs_Qy,
               Nessi::Vector<NumT> & output_vs_Qy_err2,
               Nessi::Vector<NumT> & true_output_vs_Qy,
               Nessi::Vector<NumT> & true_output_vs_Qy_err2,
               Nessi::Vector<NumT> & output_vs_Qz,
               Nessi::Vector<NumT> & output_vs_Qz_err2,
               Nessi::Vector<NumT> & true_output_vs_Qz,
               Nessi::Vector<NumT> & true_output_vs_Qz_err2,
               Nessi::Vector<NumT> & output_vv_Qx,
               Nessi::Vector<NumT> & output_vv_Qx_err2,
               Nessi::Vector<NumT> & true_output_vv_Qx,
               Nessi::Vector<NumT> & true_output_vv_Qx_err2,
               Nessi::Vector<NumT> & output_vv_Qy,
               Nessi::Vector<NumT> & output_vv_Qy_err2,
               Nessi::Vector<NumT> & true_output_vv_Qy,
               Nessi::Vector<NumT> & true_output_vv_Qy_err2,
               Nessi::Vector<NumT> & output_vv_Qz,
               Nessi::Vector<NumT> & output_vv_Qz_err2,
               Nessi::Vector<NumT> & true_output_vv_Qz,
               Nessi::Vector<NumT> & true_output_vv_Qz_err2)
{
  bool value = true;

  // scalar scalar
  if(!test_okay(output_ss_Qx,true_output_ss_Qx))
    {
      value = false;
    }
  if(!test_okay(output_ss_Qx_err2,true_output_ss_Qx_err2))
    {
      value = false;
    }

  if(!test_okay(output_ss_Qy,true_output_ss_Qy))
    {
      value = false;
    }
  if(!test_okay(output_ss_Qy_err2,true_output_ss_Qy_err2))
    {
      value = false;
    }
  if(!test_okay(output_ss_Qz,true_output_ss_Qz))
    {
      value = false;
    }
  if(!test_okay(output_ss_Qz_err2,true_output_ss_Qz_err2))
    {
      value = false;
    }

  // scalar vector
  if(!test_okay(output_sv_Qx,true_output_sv_Qx,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_Qx_err2,true_output_sv_Qx_err2,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_Qy,true_output_sv_Qy,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_Qy_err2,true_output_sv_Qy_err2,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_Qz,true_output_sv_Qz,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_Qz_err2,true_output_sv_Qz_err2,SV))
    {
      value = false;
    }

  // vector scalar
  if(!test_okay(output_vs_Qx,true_output_vs_Qx,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_Qx_err2,true_output_vs_Qx_err2,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_Qy,true_output_vs_Qy,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_Qy_err2,true_output_vs_Qy_err2,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_Qz,true_output_vs_Qz,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_Qz_err2,true_output_vs_Qz_err2,VS))
    {
      value = false;
    }

  // vector vector
  if(!test_okay(output_vv_Qx,true_output_vv_Qx,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_Qx_err2,true_output_vv_Qx_err2,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_Qy,true_output_vv_Qy,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_Qy_err2,true_output_vv_Qy_err2,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_Qz,true_output_vv_Qz,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_Qz_err2,true_output_vv_Qz_err2,VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the
 * <i>init_scatt_wavevector_to_Q</i> function (as described in the
 * documentation of the <i>init_scatt_wavevector_to_Q</i> function)
 * and launches the comparison of the data.
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any string that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  NumT                azimuthal=static_cast<NumT>(0.88);
  NumT                azimuthal_err2=static_cast<NumT>(0.44);
  NumT                polar=static_cast<NumT>(0.22);
  NumT                polar_err2=static_cast<NumT>(0.11);
  Nessi::Vector<NumT> k_i;
  Nessi::Vector<NumT> k_i_err2;
  Nessi::Vector<NumT> k_f;
  Nessi::Vector<NumT> k_f_err2;
  NumT                output_ss_Qx;
  NumT                output_ss_Qx_err2;
  NumT                true_output_ss_Qx;
  NumT                true_output_ss_Qx_err2;
  NumT                output_ss_Qy;
  NumT                output_ss_Qy_err2;
  NumT                true_output_ss_Qy;
  NumT                true_output_ss_Qy_err2;
  NumT                output_ss_Qz;
  NumT                output_ss_Qz_err2;
  NumT                true_output_ss_Qz;
  NumT                true_output_ss_Qz_err2;
  Nessi::Vector<NumT> output_sv_Qx(NUM_VAL);
  Nessi::Vector<NumT> output_sv_Qx_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_sv_Qx;
  Nessi::Vector<NumT> true_output_sv_Qx_err2;
  Nessi::Vector<NumT> output_sv_Qy(NUM_VAL);
  Nessi::Vector<NumT> output_sv_Qy_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_sv_Qy;
  Nessi::Vector<NumT> true_output_sv_Qy_err2;
  Nessi::Vector<NumT> output_sv_Qz(NUM_VAL);
  Nessi::Vector<NumT> output_sv_Qz_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_sv_Qz;
  Nessi::Vector<NumT> true_output_sv_Qz_err2;
  Nessi::Vector<NumT> output_vs_Qx(NUM_VAL);
  Nessi::Vector<NumT> output_vs_Qx_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs_Qx;
  Nessi::Vector<NumT> true_output_vs_Qx_err2;
  Nessi::Vector<NumT> output_vs_Qy(NUM_VAL);
  Nessi::Vector<NumT> output_vs_Qy_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs_Qy;
  Nessi::Vector<NumT> true_output_vs_Qy_err2;
  Nessi::Vector<NumT> output_vs_Qz(NUM_VAL);
  Nessi::Vector<NumT> output_vs_Qz_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs_Qz;
  Nessi::Vector<NumT> true_output_vs_Qz_err2;
  Nessi::Vector<NumT> output_vv_Qx(NUM_VAL);
  Nessi::Vector<NumT> output_vv_Qx_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vv_Qx;
  Nessi::Vector<NumT> true_output_vv_Qx_err2;
  Nessi::Vector<NumT> output_vv_Qy(NUM_VAL);
  Nessi::Vector<NumT> output_vv_Qy_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vv_Qy;
  Nessi::Vector<NumT> true_output_vv_Qy_err2;
  Nessi::Vector<NumT> output_vv_Qz(NUM_VAL);
  Nessi::Vector<NumT> output_vv_Qz_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vv_Qz;
  Nessi::Vector<NumT> true_output_vv_Qz_err2;

  // fill in values as appropriate
  initialize_inputs(k_i,k_i_err2,k_f,k_f_err2);

  initialize_true_outputs(true_output_ss_Qx, true_output_ss_Qx_err2,
                          true_output_ss_Qy, true_output_ss_Qy_err2,
                          true_output_ss_Qz, true_output_ss_Qz_err2,
                          true_output_sv_Qx, true_output_sv_Qx_err2,
                          true_output_sv_Qy, true_output_sv_Qy_err2,
                          true_output_sv_Qz, true_output_sv_Qz_err2,
                          true_output_vs_Qx, true_output_vs_Qx_err2,
                          true_output_vs_Qy, true_output_vs_Qy_err2,
                          true_output_vs_Qz, true_output_vs_Qz_err2,
                          true_output_vv_Qx, true_output_vv_Qx_err2,
                          true_output_vv_Qy, true_output_vv_Qy_err2,
                          true_output_vv_Qz, true_output_vv_Qz_err2);


  // run the code being tested
  AxisManip::init_scatt_wavevector_to_Q(k_i[0], k_i_err2[0],
                                        k_f[0], k_f_err2[0],
                                        azimuthal, azimuthal_err2,
                                        polar,polar_err2,
                                        output_ss_Qx, output_ss_Qx_err2,
                                        output_ss_Qy, output_ss_Qy_err2,
                                        output_ss_Qz, output_ss_Qz_err2);


  AxisManip::init_scatt_wavevector_to_Q(k_i[0], k_i_err2[0],
                                        k_f, k_f_err2,
                                        azimuthal, azimuthal_err2,
                                        polar,polar_err2,
                                        output_sv_Qx, output_sv_Qx_err2,
                                        output_sv_Qy, output_sv_Qy_err2,
                                        output_sv_Qz, output_sv_Qz_err2);


  AxisManip::init_scatt_wavevector_to_Q(k_i, k_i_err2,
                                        k_f[0], k_f_err2[0],
                                        azimuthal, azimuthal_err2,
                                        polar,polar_err2,
                                        output_vs_Qx, output_vs_Qx_err2,
                                        output_vs_Qy, output_vs_Qy_err2,
                                        output_vs_Qz, output_vs_Qz_err2);

  AxisManip::init_scatt_wavevector_to_Q(k_i, k_i_err2,
                                        k_f, k_f_err2,
                                        azimuthal, azimuthal_err2,
                                        polar,polar_err2,
                                        output_vv_Qx, output_vv_Qx_err2,
                                        output_vv_Qy, output_vv_Qy_err2,
                                        output_vv_Qz, output_vv_Qz_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv_Qx, true_output_vv_Qx, VV, debug);
      print(output_vv_Qx_err2, true_output_vv_Qx_err2, ERROR+VV, debug);
      print(output_vs_Qx, true_output_vs_Qx, VS, debug);
      print(output_vs_Qx_err2, true_output_vs_Qx_err2, ERROR+VS, debug);
      print(output_sv_Qx, true_output_sv_Qx, SV, debug);
      print(output_sv_Qx_err2, true_output_sv_Qx_err2, ERROR+SV, debug);
      print(output_ss_Qx, true_output_ss_Qx, SS, debug);
      print(output_ss_Qx_err2, true_output_ss_Qx_err2, ERROR+SS, debug);

      print(output_vv_Qy, true_output_vv_Qy, VV, debug);
      print(output_vv_Qy_err2, true_output_vv_Qy_err2, ERROR+VV, debug);
      print(output_vs_Qy, true_output_vs_Qy, VS, debug);
      print(output_vs_Qy_err2, true_output_vs_Qy_err2, ERROR+VS, debug);
      print(output_sv_Qy, true_output_sv_Qy, SV, debug);
      print(output_sv_Qy_err2, true_output_sv_Qy_err2, ERROR+SV, debug);
      print(output_ss_Qy, true_output_ss_Qy, SS, debug);
      print(output_ss_Qy_err2, true_output_ss_Qy_err2, ERROR+SS, debug);


      print(output_vv_Qz, true_output_vv_Qz, VV, debug);
      print(output_vv_Qz_err2, true_output_vv_Qz_err2, ERROR+VV, debug);
      print(output_vs_Qz, true_output_vs_Qz, VS, debug);
      print(output_vs_Qz_err2, true_output_vs_Qz_err2, ERROR+VS, debug);
      print(output_sv_Qz, true_output_sv_Qz, SV, debug);
      print(output_sv_Qz_err2, true_output_sv_Qz_err2, ERROR+SV, debug);
      print(output_ss_Qz, true_output_ss_Qz, SS, debug);
      print(output_ss_Qz_err2, true_output_ss_Qz_err2, ERROR+SS, debug);
    }

  return test_okay(output_ss_Qx, output_ss_Qx_err2,
                   true_output_ss_Qx, true_output_ss_Qx_err2,
                   output_ss_Qy, output_ss_Qy_err2,
                   true_output_ss_Qy, true_output_ss_Qy_err2,
                   output_ss_Qz, output_ss_Qz_err2,
                   true_output_ss_Qz, true_output_ss_Qz_err2,
                   output_sv_Qx, output_sv_Qx_err2,
                   true_output_sv_Qx, true_output_sv_Qx_err2,
                   output_sv_Qy, output_sv_Qy_err2,
                   true_output_sv_Qy, true_output_sv_Qy_err2,
                   output_sv_Qz, output_sv_Qz_err2,
                   true_output_sv_Qz, true_output_sv_Qz_err2,
                   output_vs_Qx, output_vs_Qx_err2,
                   true_output_vs_Qx, true_output_vs_Qx_err2,
                   output_vs_Qy, output_vs_Qy_err2,
                   true_output_vs_Qy, true_output_vs_Qy_err2,
                   output_vs_Qz, output_vs_Qz_err2,
                   true_output_vs_Qz, true_output_vs_Qz_err2,
                   output_vv_Qx, output_vv_Qx_err2,
                   true_output_vv_Qx, true_output_vv_Qx_err2,
                   output_vv_Qy, output_vv_Qy_err2,
                   true_output_vv_Qy, true_output_vv_Qy_err2,
                   output_vv_Qz, output_vv_Qz_err2,
                   true_output_vv_Qz, true_output_vv_Qz_err2);
}

/**
 * Main function that test init_scatt_wavevector_to_Q_test for float
 * and double.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "init_scatt_wavevector_to_Q_test.cpp..........";

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
 */  // end of init_scatt_wavevector_to_Q_test group
