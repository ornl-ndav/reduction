/**
 * $Id$
 *
 * \file array_manip/src/sub_vec_vec_ncerr.cpp
 */
#include "vec_vec_arith.hpp"
#include "check_inputs.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace ArrayManip
{
  // 3.7
  template <typename NumT>
  std::string 
  sub_vec_vec_ncerr(std::vector<NumT> const & input1, 
		    std::vector<NumT> const & input1_err2, 
		    std::vector<NumT> const & input2, 
		    std::vector<NumT> const & input2_err2, 
		    std::vector<NumT> & output,
		    std::vector<NumT> & output_err2,
		    void *temp=NULL)
  {
    std::string retstr("");
    
    try 
      {
	std::string errstr("ArrayManip::sub_vec_vec_ncerr: data ");
	check_sizes_2in1out(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::sub_vec_vec_ncerr: error ");
	check_sizes_2in1out(errstr, input1_err2, input2_err2, output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    std::transform(input1.begin(), input1.end(), input2.begin(), 
		   output.begin(), std::minus<NumT>());
    std::transform(input1_err2.begin(), input1_err2.end(), 
		   input2_err2.begin(), output_err2.begin(), 
		   std::plus<NumT>());

    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_vec_vec_ncerr<float>(std::vector<float> const & input1, 
			   std::vector<float> const & input1_err2, 
			   std::vector<float> const & input2, 
			   std::vector<float> const & input2_err2, 
			   std::vector<float> & output,
			   std::vector<float> & output_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_vec_vec_ncerr<double>(std::vector<double> const & input1, 
			    std::vector<double> const & input1_err2, 
			    std::vector<double> const & input2, 
			    std::vector<double> const & input2_err2, 
			    std::vector<double> & output,
			    std::vector<double> & output_err2,
			    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_vec_vec_ncerr<int>(std::vector<int> const & input1, 
			 std::vector<int> const & input1_err2, 
			 std::vector<int> const & input2, 
			 std::vector<int> const & input2_err2, 
			 std::vector<int> & output,
			 std::vector<int> & output_err2,
			 void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.7.
   *
   * \see sub_vec_vec_ncerr()
   */
  template std::string 
  sub_vec_vec_ncerr<unsigned int>(std::vector<unsigned int> const & input1, 
			      std::vector<unsigned int> const & input1_err2, 
			      std::vector<unsigned int> const & input2, 
			      std::vector<unsigned int> const & input2_err2, 
			      std::vector<unsigned int> & output,
			      std::vector<unsigned int> & output_err2,
			      void *temp);

} // ArrayManip
