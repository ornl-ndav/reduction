/**
 * $Id$
 *
 * \file array_manip/src/sub_ncerr.cpp
 */
#include "sub_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_ncerr<float>(const Nessi::Vector<float> & array_in, 
                   const Nessi::Vector<float> & array_in_err2, 
                   float scalar,
                   float scalar_err2,
                   Nessi::Vector<float> & array_out,
                   Nessi::Vector<float> & array_out_err2,
                   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_ncerr<double>(const Nessi::Vector<double> & array_in, 
                    const Nessi::Vector<double> & array_in_err2, 
                    double scalar,
                    double scalar_err2,
                    Nessi::Vector<double> & array_out,
                    Nessi::Vector<double> & array_out_err2,
                    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_ncerr<int>(const Nessi::Vector<int> & array_in, 
                 const Nessi::Vector<int> & array_in_err2, 
                 int scalar,
                 int scalar_err2,
                 Nessi::Vector<int> & array_out,
                 Nessi::Vector<int> & array_out_err2,
                 void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.2.
   *
   * \see sub_scalar_vec_ncerr()
   */
  template std::string 
  sub_ncerr<unsigned int>(const Nessi::Vector<unsigned int> & array_in, 
                          const Nessi::Vector<unsigned int> & array_in_err2, 
                          unsigned int scalar, 
                          unsigned int scalar_err2,
                          Nessi::Vector<unsigned int> & array_out,
                          Nessi::Vector<unsigned int> & array_out_err2,
                          void *temp);

  /**
   * This is the float declaration of the function defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_ncerr<float>(const Nessi::Vector<float> & input1, 
                   const Nessi::Vector<float> & input1_err2, 
                   const Nessi::Vector<float> & input2, 
                   const Nessi::Vector<float> & input2_err2, 
                   Nessi::Vector<float> & output,
                   Nessi::Vector<float> & output_err2,
                   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_ncerr<double>(const Nessi::Vector<double> & input1, 
                    const Nessi::Vector<double> & input1_err2, 
                    const Nessi::Vector<double> & input2, 
                    const Nessi::Vector<double> & input2_err2, 
                    Nessi::Vector<double> & output,
                    Nessi::Vector<double> & output_err2,
                    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_ncerr<int>(const Nessi::Vector<int> & input1, 
                 const Nessi::Vector<int> & input1_err2, 
                 const Nessi::Vector<int> & input2, 
                 const Nessi::Vector<int> & input2_err2, 
                 Nessi::Vector<int> & output,
                 Nessi::Vector<int> & output_err2,
                 void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_ncerr<unsigned int>(const Nessi::Vector<unsigned int> & input1, 
                          const Nessi::Vector<unsigned int> & input1_err2, 
                          const Nessi::Vector<unsigned int> & input2, 
                          const Nessi::Vector<unsigned int> & input2_err2, 
                          Nessi::Vector<unsigned int> & output,
                          Nessi::Vector<unsigned int> & output_err2,
                          void *temp);
} // ArrayManip
