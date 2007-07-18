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
 * \file axis_manip/inc/rebinning.hpp
 */
#ifndef _REBINNING_HPP
#define _REBINNING_HPP 1

#include "nessi.hpp"
#include <string>

namespace AxisManip
{
  /**
   * \defgroup rebin_axis_1D AxisManip::rebin_axis_1D
   * \{
   */

  /**
   * \brief This function is described in section 3.12.
   *
   * This function rebins data and its associated errors from one axis to
   * another given axis. This function uses fractional overlap of bins to
   * perform the rebinning process. The function also assumes that the data
   * is represented by a histogram model.
   *
   * To show the effects of rebinning, an example will now be discussed. We
   * start with a histogram containing 3 bins, which runs from 0 to 3 on its
   * x-axis. So, the histogram looks like:
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>4</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>30</TD><TD>9</TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * Notice that the final x-axis value is not associated with a count value.
   * This is a property of the histogram data model. Our new histogram has the
   * same x-axis range [0,3], but it only has two bins. The result of the
   * rebinned histogram is shown in the table below.
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>20</TD><TD>2</TD></TR>
   * <TR ALIGN="CENTER"><TD>1.5</TD><TD>40</TD><TD>10</TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * The new bin boundary (1.5) lies in the middle of the second bin in the
   * original histogram. That means that its contents will be evenly split
   * into the new bins. So,
   * \f[
   * Bin_1^{new} = Bin_1^{old} + 0.5 \times Bin_2^{old}
   * \f]
   * \f[
   * Bin_2^{new} = Bin_3^{old} + 0.5 \times Bin_2^{old}
   * \f]
   *and
   * \f[
   * \sigma^2_{Bin_1^{new}} = \sigma^2_{Bin_1^{old}} + (0.5)^2 \times
   * \sigma^2_{Bin_2^{old}}
   * \f]
   * \f[
   * \sigma^2_{Bin_2^{new}} = \sigma^2_{Bin_3^{old}} + (0.5)^2 \times
   * \sigma^2_{Bin_2^{old}}
   * \f]
   *
   * This can be seen in the results presented in the above table. Now, we'll
   * reverse the process. The original histogram is the rebinned histogram
   * with two bins used previously and the new rebinned histogram will have
   * the same number of bins (3) as the previously used original histogram.
   * One can see that we have the following distribution of bin contents:
   *
   * \f[
   * Bin_1^{new} = \frac{2}{3} \times Bin_1^{old}
   * \f]
   * \f[
   * Bin_2^{new} = \frac{1}{3} \times Bin_1^{old} + \frac{1}{3} \times
   * Bin_2^{old}
   * \f]
   * \f[
   * Bin_3^{new} = \frac{2}{3} \times Bin_2^{old}
   * \f]
   * and
   * \f[
   * \sigma^2_{Bin_1^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_1^{old}}
   * \f]
   * \f[
   * \sigma^2_{Bin_2^{new}} = (\frac{1}{3})^2 \times \sigma^2_{Bin_1^{old}} +
   * (\frac{1}{3})^2 \times \sigma^2_{Bin_2^{old}}
   * \f]
   * \f[
   * \sigma^2_{Bin_3^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_2^{old}}
   * \f]
   *
   * The results of this operation are shown in the following table:
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>13.33333</TD><TD>0.88888</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>1.33333</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>26.66666</TD><TD>4.44444</TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * As one can see, these values are different from the first table shown in
   * this example. This is due to the loss of information when performing a
   * rebin on data. Therefore, rebin your data thoughtfully and carefully!
   *
   * This function was provided by Paul Kienzle (NIST) and is based on an
   * OpenGenie routine.
   *
   * \param axis_in (INPUT) is the initial data axis
   * \param input (INPUT) is the data associated with the initial axis
   * \param input_err2 (INPUT) is the square of the uncertainty associated
   * with the data
   * \param axis_out (INPUT) is the target axis for rebinning
   * \param output (OUTPUT) is the rebinned data according to the target axis
   * \param output_err2 (OUTPUT) is the square of the uncertainty associated
   * with the rebinned data
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the size of axis_in
   * is not one more than the size of input and input_err2.
   * \exception std::invalid_argument is thrown if the size of
   * axis_out is not one more than the size of output and output_err2.
   */
  template <typename NumT>
  std::string
  rebin_axis_1D(const Nessi::Vector<NumT> & axis_in,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL);

  /**
   * \}
   */ // end of rebin_axis_1D group

  /**
   * \defgroup rebin_axis_2D AxisManip::rebin_axis_2D
   * \{
   */

  /**
   * \brief This function is described in section 3.13.
   *
   * This function rebins data and its associated errors from two axes to
   * two different axes. This function uses fractional overlap of bins to
   * perform the rebinning process. The function also assumes that the data
   * is represented by a histogram model. The fractional overlap is performed
   * on one axis at a time with the second declared axis going first.
   *
   * To show the effects of rebinning, an example will now be discussed. We
   * start with a histogram containing 9 bins, which runs from 0 to 3 on its
   * x and y axes. So, the histogram looks like:
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Y-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * Our new histogram is still [0,3] on both the x and y axes, but now both
   * axes are two bins. The result of the rebinned histogram is shown in the
   * table below.
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Y-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>30</TD><TD>2.5</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>1.5</TD><TD>60</TD><TD>12.5</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1.5</TD><TD>0</TD><TD>30</TD><TD>2.5</TD></TR>
   * <TR ALIGN="CENTER"><TD>1.5</TD><TD>1.5</TD><TD>60</TD><TD>12.5</TD></TR>
   * <TR ALIGN="CENTER"><TD>1.5</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD> </TD><TD> </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * The algorithm relies on the constructs used in the 1D rebinning algorithm
   * to perform the calculations.
   *
   * Now, we reverse the process starting with the newly rebinned histogram
   * with four total bins and revert back to the original axes layout in the
   * histogram with nine bins. The results of the rebinning are shown in the
   * table below.
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Y-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * As one can see, these values are different from the first table shown in
   * this example. This is due to the loss of information when performing a
   * rebin on data. Therefore, rebin your data thoughtfully and carefully!
   *
   * \param axis_in_1 (INPUT) is the 1st initial data axis
   * \param axis_in_2 (INPUT) is the 2nd initial data axis
   * \param input (INPUT) is the data associated with the initial axis
   * \param input_err2 (INPUT) is the square of the uncertainty associated
   * with the data
   * \param axis_out_1 (INPUT) is the 1st target axis for rebinning
   * \param axis_out_2 (INPUT) is the 2nd target axis for rebinning
   * \param output (OUTPUT) is the rebinned data according to the target axis
   * \param output_err2 (OUTPUT) is the square of the uncertainty associated
   * with the rebinned data
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the size of axis_in
   * is not one more than the size of input and input_err2.
   * \exception std::invalid_argument is thrown if the size of
   * axis_out is not one more than the size of output and output_err2.
   */
  template <typename NumT>
  std::string
  rebin_axis_2D(const Nessi::Vector<NumT> & axis_in_1,
                const Nessi::Vector<NumT> & axis_in_2,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out_1,
                const Nessi::Vector<NumT> & axis_out_2,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL);

  /**
   * \}
   */ // end of rebin_axis_2D group

  /**
   * \defgroup rebin_axis_4D AxisManip::rebin_axis_4D
   * \{
   */

  /**
   * \brief This function is described in section 3.14.
   *
   * THIS FUNCTION IS NOT DEFINED
   */
  template <typename NumT>
  std::string
  rebin_axis_4D(const Nessi::Vector<NumT> & axis_in_1,
                const Nessi::Vector<NumT> & axis_in_2,
                const Nessi::Vector<NumT> & axis_in_3,
                const Nessi::Vector<NumT> & axis_in_4,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out_1,
                const Nessi::Vector<NumT> & axis_out_2,
                const Nessi::Vector<NumT> & axis_out_3,
                const Nessi::Vector<NumT> & axis_out_4,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL);

  /**
   * \}
   */ // end of rebin_axis_4D group

  /**
   * \defgroup rebin_diagonal AxisManip::rebin_diagonal
   * \{
   */

  /**
   * \brief This function is described in section 3.XX.
   *
   * This function rebins a two-dimensional spectrum that is diagonal in 
   * terms of the number of elements in the axes that make up the spectrum. 
   * The best way to illustrate the functionality is with an example.
   *
   * We start with a histogram containing 16 bins, which runs from 0 to 4 on 
   * its x and y axes, but with values only along the diagonal of the 
   * histogram. So, the histogram looks like:
   *
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Y-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>1</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>0</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>1</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>2</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>0</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>1</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>2</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>0</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>1</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>2</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>3</TD><TD>10</TD><TD>1</TD></TR>
   * <TR ALIGN="CENTER"><TD>3</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>4</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * Our new histogram is still [0,4] on both the x and y axes, but now the x 
   * axis is three bins and the y axis is two bins. The result of the 
   * rebinned histogram is shown in the table below.
   * 
   * <CENTER>
   * <TABLE>
   * <TR>
   * <TH>X-Axis Value</TH>
   * <TH>Y-Axis Value</TH>
   * <TH>Counts</TH>
   * <TH>\f$\sigma^2\f$</TH>
   * </TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>13.333</TD><TD>1.111</TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>0</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>1.333</TD><TD>0</TD><TD>6.666</TD><TD>0.444</TD></TR>
   * <TR ALIGN="CENTER"><TD>1.333</TD><TD>2</TD><TD>6.666</TD><TD>0.444</TD></TR>
   * <TR ALIGN="CENTER"><TD>1.333</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2.666</TD><TD>0</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>2.666</TD><TD>2</TD><TD>13.333</TD><TD>1.111</TD></TR>
   * <TR ALIGN="CENTER"><TD>2.666</TD><TD>4</TD><TD> </TD><TD> </TD></TR>
   * <TR ALIGN="CENTER"><TD>4</TD><TD>  </TD><TD> </TD></TR>
   * </TABLE>
   * </CENTER>
   *
   * \param axis_in_1 (INPUT) is the 1st initial data axis
   * \param axis_in_2 (INPUT) is the 2nd initial data axis
   * \param input (INPUT) is the data associated with the initial axis
   * \param input_err2 (INPUT) is the square of the uncertainty associated
   * with the data
   * \param axis_out_1 (INPUT) is the 1st target axis for rebinning
   * \param axis_out_2 (INPUT) is the 2nd target axis for rebinning
   * \param output (OUTPUT) is the rebinned data according to the target axis
   * \param output_err2 (OUTPUT) is the square of the uncertainty associated
   * with the rebinned data
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the sizes of axis_in_1, 
   * input and input_err2 are not that of a histogram dataset
   * \exception std::invalid_argument is thrown is the sizes of axis_in_1 and
   * axis_in_2 are not the same
   * \exception std::invalid_argument is thrown if the sizes of
   * axis_out_1, axis_out_2, output and output_err2 are not that of a 
   * histogram dataset
   */
  template <typename NumT>
  std::string
  rebin_diagonal(const Nessi::Vector<NumT> & axis_in_1,
                 const Nessi::Vector<NumT> & axis_in_2,
                 const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 const Nessi::Vector<NumT> & axis_out_1,
                 const Nessi::Vector<NumT> & axis_out_2,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL);

  /**
   * \}
   */ // end of rebin_diagonal group

} // AxisManip

#endif // _REBINNING_HPP