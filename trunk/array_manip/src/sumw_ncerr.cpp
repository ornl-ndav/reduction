/**
 * $Id$
 *
 * \file array_manip/src/sumw_ncerr.cpp
 */
#include "sumw_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_ncerr<float>(const Nessi::Vector<float> & input1, 
                    const Nessi::Vector<float> & input1_err2, 
                    const Nessi::Vector<float> & input2, 
                    const Nessi::Vector<float> & input2_err2, 
                    Nessi::Vector<float> & output,
                    Nessi::Vector<float> & output_err2,
                    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_ncerr<double>(const Nessi::Vector<double> & input1, 
                     const Nessi::Vector<double> & input1_err2, 
                     const Nessi::Vector<double> & input2, 
                     const Nessi::Vector<double> & input2_err2, 
                     Nessi::Vector<double> & output,
                     Nessi::Vector<double> & output_err2,
                     void *temp);

  /**
   * This is the integer declaration of the function defined in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_ncerr<int>(const Nessi::Vector<int> & input1, 
                  const Nessi::Vector<int> & input1_err2, 
                  const Nessi::Vector<int> & input2, 
                  const Nessi::Vector<int> & input2_err2, 
                  Nessi::Vector<int> & output,
                  Nessi::Vector<int> & output_err2,
                  void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.10.
   *
   * \see sumw_vec_vec_ncerr()
   */
  template std::string 
  sumw_ncerr<unsigned int>(const Nessi::Vector<unsigned int> & input1, 
                           const Nessi::Vector<unsigned int> & input1_err2,
                           const Nessi::Vector<unsigned int> & input2, 
                           const Nessi::Vector<unsigned int> & input2_err2,
                           Nessi::Vector<unsigned int> & output,
                           Nessi::Vector<unsigned int> & output_err2,
                           void *temp);
} // ArrayManip
