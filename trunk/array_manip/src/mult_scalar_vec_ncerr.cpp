/**
 * $Id$
 *
 * \file array_manip/src/mult_scalar_vec_ncerr.cpp
 */
#include "vec_scalar_arith.hpp"
#include <string>
#include <vector>

namespace ArrayManip
{
  // 3.3
  template <typename NumT>
  std::string 
  mult_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
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
	array_out[i] = array_in[i] * scalar;
        array_out_err2[i] = ((scalar * scalar) * array_in_err2[i]) + 
	  ((array_in[i] * array_in[i]) * scalar_err2);
      }
    return errstr;
  }
    
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<float>(std::vector<float> const & array_in, 
			       std::vector<float> const & array_in_err2, 
			       std::vector<float> & array_out,
			       std::vector<float> & array_out_err2,
			       float scalar, float scalar_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<double>(std::vector<double> const & array_in, 
				std::vector<double> const & array_in_err2, 
				std::vector<double> & array_out,
				std::vector<double> & array_out_err2,
				double scalar, double scalar_err2,
				void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<int>(std::vector<int> const & array_in, 
			     std::vector<int> const & array_in_err2, 
			     std::vector<int> & array_out,
			     std::vector<int> & array_out_err2,
			     int scalar, int scalar_err2,
			     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_scalar_vec_ncerr<unsigned int>(
                                 std::vector<unsigned int> const & array_in, 
                                 std::vector<unsigned int> const & array_in_err2, 
                                 std::vector<unsigned int> & array_out,
                                 std::vector<unsigned int> & array_out_err2,
                                 unsigned int scalar, 
                                 unsigned int scalar_err2,
                                 void *temp);
  
} // ArrayManip 

