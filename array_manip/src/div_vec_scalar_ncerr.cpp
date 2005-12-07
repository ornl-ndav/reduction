/**
 * $Id$
 *
 * \file array_manip/src/div_vec_scalar_ncerr.cpp
 */
#include "vec_scalar_arith.hpp"
#include <string>
#include <vector>

namespace ArrayManip
{
  // 3.5
  template <typename NumT>
  std::string 
  div_vec_scalar_ncerr(std::vector<NumT> const & array_in, 
		       std::vector<NumT> const & array_in_err2, 
		       std::vector<NumT> & array_out,
		       std::vector<NumT> & array_out_err2,
		       NumT scalar, NumT scalar_err2,
		       void *temp=NULL)
  {
    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
    	array_out[i] = array_in[i] / scalar;
	NumT scalar2 = scalar * scalar;
        array_out_err2[i] = (array_in_err2[i] / scalar2) + (((array_in[i] * array_in[i]) / (scalar2 * scalar2)) * scalar_err2);
      }
    return errstr;
  }
    
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.5.
   *
   * \see div_vec_scalar_ncerr()
   */
  template std::string 
  div_vec_scalar_ncerr<float>(std::vector<float> const & array_in, 
			      std::vector<float> const & array_in_err2, 
			      std::vector<float> & array_out,
			      std::vector<float> & array_out_err2,
			      float scalar, float scalar_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.5.
   *
   * \see div_vec_scalar_ncerr()
   */
  template std::string 
  div_vec_scalar_ncerr<double>(std::vector<double> const & array_in, 
			       std::vector<double> const & array_in_err2, 
			       std::vector<double> & array_out,
			       std::vector<double> & array_out_err2,
			       double scalar, double scalar_err2,
			       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.5.
   *
   * \see div_vec_scalar_ncerr()
   */
  template std::string 
  div_vec_scalar_ncerr<int>(std::vector<int> const & array_in, 
			    std::vector<int> const & array_in_err2, 
			    std::vector<int> & array_out,
			    std::vector<int> & array_out_err2,
			    int scalar, int scalar_err2,
			    void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.5.
   *
   * \see div_vec_scalar_ncerr()
   */
  template std::string 
  div_vec_scalar_ncerr<unsigned int>(
                              std::vector<unsigned int> const & array_in, 
                              std::vector<unsigned int> const & array_in_err2, 
                              std::vector<unsigned int> & array_out,
                              std::vector<unsigned int> & array_out_err2,
                              unsigned int scalar, 
                              unsigned int scalar_err2,
                              void *temp);
  
} // ArrayManip 

