/**
 * $Id$
 *
 * \file phys_corr/src/incoherent_scatt_cor.cpp
 */
#include "physcorr.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace PhysCorr
{
  // 3.41
  template <typename NumT>
  std::string
  incoherent_scatt_corr(std::vector<NumT> const & axis_in,
			std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			std::vector<NumT> & output,
			std::vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [incoherent_scatt_corr] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<float>(std::vector<float> const & axis_in,
			       std::vector<float> const & input,
			       std::vector<float> const & input_err2,
			       std::vector<float> & output,
			       std::vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<double>(std::vector<double> const & axis_in,
				std::vector<double> const & input,
				std::vector<double> const & input_err2,
				std::vector<double> & output,
				std::vector<double> & output_err2,
				void *temp);

  /**
   * This is the integer declaration of the function defined in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<int>(std::vector<int> const & axis_in,
			     std::vector<int> const & input,
			     std::vector<int> const & input_err2,
			     std::vector<int> & output,
			     std::vector<int> & output_err2,
			     void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<unsigned int>(
                                  std::vector<unsigned int> const & axis_in,
				  std::vector<unsigned int> const & input,
				  std::vector<unsigned int> const & input_err2,
				  std::vector<unsigned int> & output,
				  std::vector<unsigned int> & output_err2,
				  void *temp);

} // PhysCorr
