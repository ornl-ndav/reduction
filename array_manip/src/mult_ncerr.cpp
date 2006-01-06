/**
 * $Id$
 *
 * \file array_manip/src/mult_ncerr.cpp
 */
#include "mult_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_ncerr<float>(Nessi::Vector<float> const & array_in, 
                    Nessi::Vector<float> const & array_in_err2, 
                    const float scalar,
                    const float scalar_err2,
                    Nessi::Vector<float> & array_out,
                    Nessi::Vector<float> & array_out_err2,
                    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_ncerr<double>(Nessi::Vector<double> const & array_in, 
                     Nessi::Vector<double> const & array_in_err2, 
                     const double scalar,
                     const double scalar_err2,
                     Nessi::Vector<double> & array_out,
                     Nessi::Vector<double> & array_out_err2,
                     void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_ncerr<int>(Nessi::Vector<int> const & array_in, 
                  Nessi::Vector<int> const & array_in_err2, 
                  const int scalar,
                  const int scalar_err2,
                  Nessi::Vector<int> & array_out,
                  Nessi::Vector<int> & array_out_err2,
                  void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.3.
   *
   * \see mult_scalar_vec_ncerr()
   */
  template std::string 
  mult_ncerr<unsigned int>(Nessi::Vector<unsigned int> const & array_in, 
                           Nessi::Vector<unsigned int> const & array_in_err2, 
                           const unsigned int scalar, 
                           const unsigned int scalar_err2,
                           Nessi::Vector<unsigned int> & array_out,
                           Nessi::Vector<unsigned int> & array_out_err2,
                           void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.8.
   *
   * \see mult_vec_vec_ncerr()
   */
  template std::string 
  mult_ncerr<float>(Nessi::Vector<float> const & input1, 
                    Nessi::Vector<float> const & input1_err2, 
                    Nessi::Vector<float> const & input2, 
                    Nessi::Vector<float> const & input2_err2, 
                    Nessi::Vector<float> & output,
                    Nessi::Vector<float> & output_err2,
                    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.8.
   *
   * \see mult_vec_vec_ncerr()
   */
  template std::string 
  mult_ncerr<double>(Nessi::Vector<double> const & input1, 
                     Nessi::Vector<double> const & input1_err2, 
                     Nessi::Vector<double> const & input2, 
                     Nessi::Vector<double> const & input2_err2, 
                     Nessi::Vector<double> & output,
                     Nessi::Vector<double> & output_err2,
                     void *temp);

  /**
   * This is the integer declaration of the function defined in 3.8.
   *
   * \see mult_vec_vec_ncerr()
   */
  template std::string 
  mult_ncerr<int>(Nessi::Vector<int> const & input1, 
                  Nessi::Vector<int> const & input1_err2, 
                  Nessi::Vector<int> const & input2, 
                  Nessi::Vector<int> const & input2_err2, 
                  Nessi::Vector<int> & output,
                  Nessi::Vector<int> & output_err2,
                  void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.8.
   *
   * \see mult_vec_vec_ncerr()
   */
  template std::string 
  mult_ncerr<unsigned int>(Nessi::Vector<unsigned int> const & input1, 
                           Nessi::Vector<unsigned int> const & input1_err2, 
                           Nessi::Vector<unsigned int> const & input2, 
                           Nessi::Vector<unsigned int> const & input2_err2, 
                           Nessi::Vector<unsigned int> & output,
                           Nessi::Vector<unsigned int> & output_err2,
                           void *temp);

} // ArrayManip
