/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.hpp
 */
#include "conversions.hpp"
#include <cmath>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.33
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_scalar_Q(
				    std::vector<NumT> const & initial_wavevector,
				    std::vector<NumT> const & initial_wavevector_err2,
				    std::vector<NumT> const & final_wavevector,
				    std::vector<NumT> const & final_wavevector_err2,
				    const NumT polar_angle,
				    const NumT polar_angle_err2,
				    std::vector<NumT> & Q,
				    std::vector<NumT> & Q_err2,
				    void *temp=NULL)
  {
    std::string retstr("");
    
    size_t sz1 = initial_wavevector.size();
    size_t sz2 = final_wavevector.size();
    
    // FIXME
    // Need a zero length check for all vectors
    
    NumT a = static_cast<NumT>(2 * std::cos(static_cast<double>(polar_angle)));
    NumT pang = static_cast<NumT>(std::cos(static_cast<double>(polar_angle)));

    if (sz1 == 1 && sz2 != 1)
      {
	NumT ki2 = initial_wavevector[0] * initial_wavevector[0];

	for (size_t i = 0; i < sz2; ++i)
	  {
	    NumT kf2 = final_wavevector[i] * final_wavevector[i];
	    NumT akikf = a * initial_wavevector[0] * final_wavevector[i];
	    
	    Q[i] = static_cast<NumT>
	      (std::sqrt(static_cast<double>(ki2 + kf2 - akikf)));

	    NumT termi = initial_wavevector[0] - (final_wavevector[i] * pang);
	    NumT termi2 = termi * termi;

	    NumT termf = final_wavevector[i] - (initial_wavevector[0] * pang);
	    NumT termf2 = termf * termf;
	      
	    NumT front = 4 / (Q[i] * Q[i]);

	    Q_err2[i] = front * ((initial_wavevector_err2[0] * termi2) + 
				      (final_wavevector_err2[i] * termf2));
	  }
      }
    else if (sz1 != 1 && sz2 == 1)
      {
	NumT kf2 = final_wavevector[0] * final_wavevector[0];

	for (size_t i = 0; i < sz1; ++i)
	  {
	    NumT ki2 = initial_wavevector[i] * initial_wavevector[i];
	    NumT akikf = a * initial_wavevector[i] * final_wavevector[0];
	    
	    Q[i] = static_cast<NumT>
	      (std::sqrt(static_cast<double>(ki2 + kf2 - akikf)));

	    NumT termi = initial_wavevector[i] - (final_wavevector[0] * pang);
	    NumT termi2 = termi * termi;

	    NumT termf = final_wavevector[0] - (initial_wavevector[i] * pang);
	    NumT termf2 = termf * termf;
	      
	    NumT front = 4 / (Q[i] * Q[i]);

	    Q_err2[i] = front * ((initial_wavevector_err2[i] * termi2) + 
				      (final_wavevector_err2[0] * termf2));
	  }
      }
    else if (sz1 == 1 && sz2 == 1)
      {
	NumT ki2 = initial_wavevector[0] * initial_wavevector[0];
	NumT kf2 = final_wavevector[0] * final_wavevector[0];
	NumT akikf = a * initial_wavevector[0] * final_wavevector[0];
	
	Q[0] = static_cast<NumT>(std::sqrt(static_cast<double>(ki2 + 
								    kf2 - 
								    akikf)));
	
	NumT termi = initial_wavevector[0] - (final_wavevector[0] * pang);
	NumT termi2 = termi * termi;
	
	NumT termf = final_wavevector[0] - (initial_wavevector[0] * pang);
	NumT termf2 = termf * termf;
	
	NumT front = 4 / (Q[0] * Q[0]);
	
	Q_err2[0] = front * ((initial_wavevector_err2[0] * termi2) + 
				  (final_wavevector_err2[0] * termf2));
      }
    else
      {
	for (size_t i = 0; i < sz1; ++i)
	  {
	    NumT ki2 = initial_wavevector[i] * initial_wavevector[i];
	    NumT kf2 = final_wavevector[i] * final_wavevector[i];
	    NumT akikf = a * initial_wavevector[i] * final_wavevector[i];
	
	    Q[i] = static_cast<NumT>
	      (std::sqrt(static_cast<double>(ki2 + kf2 - akikf)));

	    NumT termi = initial_wavevector[i] - (final_wavevector[i] * pang);
	    NumT termi2 = termi * termi;

	    NumT termf = final_wavevector[i] - (initial_wavevector[i] * pang);
	    NumT termf2 = termf * termf;
	      
	    NumT front = 4 / (Q[i] * Q[i]);

	    Q_err2[i] = front * ((initial_wavevector_err2[i] * termi2) + 
				      (final_wavevector_err2[i] * termf2));
	  }
      }

    return retstr;
  }
} // AxisManip
