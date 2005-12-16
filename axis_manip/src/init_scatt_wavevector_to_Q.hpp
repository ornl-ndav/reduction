/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_Q.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.32
 template <typename NumT>
 std::string
 init_scatt_wavevector_to_Q(std::vector<NumT> const & initial_wavevector,
			    std::vector<NumT> const & initial_wavevector_err2,
			    std::vector<NumT> const & final_wavevector,
			    std::vector<NumT> const & final_wavevector_err2,
			    const NumT azimuthal_angle,
			    const NumT azimuthal_angle_err2,
			    const NumT polar_angle,
			    const NumT polar_angle_err2,
			    std::vector<NumT> & Qx,
			    std::vector<NumT> & Qx_err2,
			    std::vector<NumT> & Qy,
			    std::vector<NumT> & Qy_err2,
			    std::vector<NumT> & Qz,
			    std::vector<NumT> & Qz_err2,
			    void *temp=NULL)
 {
    throw std::runtime_error("Function [init_scatt_wavevector_to_Q] not implemented");
 }
} // AxisManip
