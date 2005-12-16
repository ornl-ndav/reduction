/**
 * $Id$
 *
 * \file array_manip/src/sumw_vec_vec_ncerr.cpp
 */
#include "sumw_vec_vec_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_vec_vec_ncerr<float>(std::vector<float> const & input1, 
			    std::vector<float> const & input1_err2, 
			    std::vector<float> const & input2, 
			    std::vector<float> const & input2_err2, 
			    std::vector<float> & output,
			    std::vector<float> & output_err2,
			    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_vec_vec_ncerr<double>(std::vector<double> const & input1, 
			     std::vector<double> const & input1_err2, 
			     std::vector<double> const & input2, 
			     std::vector<double> const & input2_err2, 
			     std::vector<double> & output,
			     std::vector<double> & output_err2,
			     void *temp);

  /**
   * This is the integer declaration of the function defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_vec_vec_ncerr<int>(std::vector<int> const & input1, 
			  std::vector<int> const & input1_err2, 
			  std::vector<int> const & input2, 
			  std::vector<int> const & input2_err2, 
			  std::vector<int> & output,
			  std::vector<int> & output_err2,
			  void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_vec_vec_ncerr<unsigned int>(std::vector<unsigned int> const & input1, 
			       std::vector<unsigned int> const & input1_err2, 
			       std::vector<unsigned int> const & input2, 
			       std::vector<unsigned int> const & input2_err2, 
			       std::vector<unsigned int> & output,
			       std::vector<unsigned int> & output_err2,
			       void *temp);
} // ArrayManip
