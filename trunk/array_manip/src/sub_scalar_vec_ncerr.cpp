/**
 * $Id$
 *
 * \file array_manip/src/sub_scalar_vec_ncerr.cpp
 */
#include "sub_scalar_vec_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_scalar_vec_ncerr<float>(std::vector<float> const & array_in, 
			      std::vector<float> const & array_in_err2, 
			      std::vector<float> & array_out,
			      std::vector<float> & array_out_err2,
			      float scalar, float scalar_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_scalar_vec_ncerr<double>(std::vector<double> const & array_in, 
			       std::vector<double> const & array_in_err2, 
			       std::vector<double> & array_out,
			       std::vector<double> & array_out_err2,
			       double scalar, double scalar_err2,
			       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_scalar_vec_ncerr<int>(std::vector<int> const & array_in, 
			    std::vector<int> const & array_in_err2, 
			    std::vector<int> & array_out,
			    std::vector<int> & array_out_err2,
			    int scalar, int scalar_err2,
			    void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_scalar_vec_ncerr<unsigned int>(
                              std::vector<unsigned int> const & array_in, 
                              std::vector<unsigned int> const & array_in_err2, 
                              std::vector<unsigned int> & array_out,
                              std::vector<unsigned int> & array_out_err2,
                              unsigned int scalar, 
                              unsigned int scalar_err2,
                              void *temp);
  } // ArrayManip 

