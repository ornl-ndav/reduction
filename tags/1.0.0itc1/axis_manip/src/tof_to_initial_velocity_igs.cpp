/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_velocity_igs.cpp
 */
#include "tof_to_initial_velocity_igs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.28.
   *
   * \ingroup tof_to_initial_velocity_igs
   */
  template std::string
  tof_to_initial_velocity_igs<float>(
                                  const Nessi::Vector<float> & tof,
                                  const Nessi::Vector<float> & tof_err2,
                                  const float final_velocity,
                                  const float final_velocity_err2,
                                  const float time_offset,
                                  const float time_offset_err2,
                                  const float dist_source_sample,
                                  const float dist_source_sample_err2,
                                  const float dist_sample_detector,
                                  const float dist_sample_detector_err2,
                                  Nessi::Vector<float> & initial_velocity,
                                  Nessi::Vector<float> & initial_velocity_err2,
                                  void *temp=NULL);
  
  /**
   * This is the float declaration of the function defined in 3.28.
   *
   * \ingroup tof_to_initial_velocity_igs
   */
  template std::string
  tof_to_initial_velocity_igs<float>(
                                  const float tof,
                                  const float tof_err2,
                                  const float final_velocity,
                                  const float final_velocity_err2,
                                  const float time_offset,
                                  const float time_offset_err2,
                                  const float dist_source_sample,
                                  const float dist_source_sample_err2,
                                  const float dist_sample_detector,
                                  const float dist_sample_detector_err2,
                                  float & initial_velocity,
                                  float & initial_velocity_err2,
                                  void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.28.
   *
   * \ingroup tof_to_initial_velocity_igs
   */
  template std::string
  tof_to_initial_velocity_igs<double>(
                                 const Nessi::Vector<double> & tof,
                                 const Nessi::Vector<double> & tof_err2,
                                 const double final_velocity,
                                 const double final_velocity_err2,
                                 const double time_offset,
                                 const double time_offset_err2,
                                 const double dist_source_sample,
                                 const double dist_source_sample_err2,
                                 const double dist_sample_detector,
                                 const double dist_sample_detector_err2,
                                 Nessi::Vector<double> & initial_velocity,
                                 Nessi::Vector<double> & initial_velocity_err2,
                                 void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.28.
   *
   * \ingroup tof_to_initial_velocity_igs
   */
  template std::string
  tof_to_initial_velocity_igs<double>(
                                 const double tof,
                                 const double tof_err2,
                                 const double final_velocity,
                                 const double final_velocity_err2,
                                 const double time_offset,
                                 const double time_offset_err2,
                                 const double dist_source_sample,
                                 const double dist_source_sample_err2,
                                 const double dist_sample_detector,
                                 const double dist_sample_detector_err2,
                                 double & initial_velocity,
                                 double & initial_velocity_err2,
                                 void *temp=NULL);
} // AxisManip