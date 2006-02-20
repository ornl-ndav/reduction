#
#                     SNS Common Libraries
#           A part of the SNS Analysis Software Suite.
#
#                  Spallation Neutron Source
#          Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                             NOTICE
#
# For this software and its associated documentation, permission is granted
# to reproduce, prepare derivative works, and distribute copies to the public
# for any purpose and without fee.
#
# This material was prepared as an account of work sponsored by an agency of
# the United States Government.  Neither the United States Government nor the
# United States Department of Energy, nor any of their employees, makes any
# warranty, express or implied, or assumes any legal liability or
# responsibility for the accuracy, completeness, or usefulness of any
# information, apparatus, product, or process disclosed, or represents that
# its use would not infringe privately owned rights.
#
#

# $Id$

##
# \file bindings/axis_manip.py 

##
# \namespace axis_manip
#
# \brief Python abstraction layer for access to AxisManip library functions
#
# This module gives the NessiVector access to the various physical axis
# conversions that are useful for time-on-flight neutron scattering. All of
# the bases functions are written in reference to SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# Once a function is called, according to the type of the NessiVector calling
# it,the module redirectes the call to the right function
#
# For example, when calling the function \f$energy\_transfer\f$ with 4
# NessiVector of type <i>float</i>, the module redirects the call to the
# function \f$energy\_transfer\_f\f$.
#

import nessi_vector
import axis_manip_bind
import sys

CalculationError = "Error of calculation"
TypeError = "Error of type"
TypesDifferentError = "Error in types"

##
# \defgroup py_energy_transfer axis_manip::energy_transfer
# \{

##
# \brief This function calculates the energy transfer and its uncertainty.
#
# This function is described  in section 3.30 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the energy transfer according to the equation
# \f[
# \nu[i]=\frac{E_i[i]-E_f[i]}{h}=\frac{E_i[i]-E_f[i]}{4.1357}\frac{THz}{meV}
# \f]
# Where \f$\nu\f$ is the energy transfer, \f$E_i\f$ is the incident
# energy, and \f$E_f\f$ is the final energy.
# Using the assumption of uncorrelated uncertainties, the square of
# the uncertainty of the energy transfer is given by
# \f[
# \sigma^2_\nu [i]=\frac{\sigma^2_{E_i}[i] +\sigma^2_{E_f}[i]}{h^2}
# \f]
# Where \f$\sigma_{E_i} \f$ is the uncertainty of the incident
# energy axis, and \f$\sigma_{E_f} \f$ is the uncertainty of the
# final energy axis.
#
# \param initial_energy (INPUT) is the incident energy axis in units of meV
# \param initial_energy_err2 (INPUT) is the square of the uncertainty of the
# incident energy axis
# \param final_energy (INPUT) is the final energy axis in units of meV
# \param final_energy_err2 (INPUT) is the square of the uncertainty of the
# final energy axis
# \return Two NessiVectors:
# - The first NessiVector returned is the energy transfer axis in
# units of THz.
# - The second NessiVector returned is the square of the uncertainty in the
# energy tranfser axis.
#

def energy_transfer(initial_energy, initial_energy_err2,\
                final_energy, final_energy_err2):
   try:
      if (initial_energy.__type__ == nessi_vector.NessiVector.FLOAT):
         if (final_energy.__type__ == nessi_vector.NessiVector.FLOAT):
        try:
           energy_transfer = nessi_vector.NessiVector(len(\
          initial_energy))
           energy_transfer_err2 = nessi_vector.NessiVector(len(\
              initial_energy))
           axis_manip_bind.energy_transfer_f(\
              initial_energy.__array__,\
          initial_energy_err2.__array__,\
              final_energy.__array__,\
          final_energy_err2.__array__,\
          energy_transfer.__array__,\
          energy_transfer_err2.__array__)
        except:
           raise CalculationError
     else:
        raise TypesDifferentError

      elif (initial_energy.__type__ == nessi_vector.NessiVector.DOUBLE):
         if (final_energy.__type__ == nessi_vector.NessiVector.DOUBLE):
            try:
           energy_transfer = nessi_vector.NessiVector(len(\
              initial_energy),"double")
           energy_transfer_err2 = nessi_vector.NessiVector(len(\
              initial_energy),"double")
           axis_manip_bind.energy_transfer_d(\
              initial_energy.__array__,\
          initial_energy_err2.__array__,\
          final_energy.__array__,\
          final_energy_err2.__array__,\
          energy_transfer.__array__,\
          energy_transfer_err2.__array__)
        except:
           raise CalculationError
     else:
        raise TypesDifferentError

      else:
         raise TypeError

   except TypeError:
      print "Vector type requested, %s, is not supported!" %initial_energy.__type__
      energy_transfer=nessi_vector.NessiVector(len(initial_energy))
      energy_transfer_err2=nessi_vector.NessiVector(len(initial_energy))

   except TypesDifferentError:
      print "Vector types (%s,%s) are different" %(initial_energy.__type__, \
       final_energy.__type__)
      energy_transfer=nessi_vector.NessiVector(len(initial_energy))
      energy_transfer_err2=nessi_vector.NessiVector(len(initial_energy))

   except CalculationError:
      print "Calculation of energy_transfer failed"
      energy_transfer=nessi_vector.NessiVector(len(initial_energy))
      energy_transfer_err2=nessi_vector.NessiVector(len(initial_energy))

   except:
      print "Object has no attribute __type__"

   return energy_transfer, energy_transfer_err2

##
# \}

##
# \defgroup py_init_scatt_wavevector_to_scalar_Q \
# axis_manip::init_scatt_wavevector_to_scalar_Q
# \{

##
# \brief This function calculates the scalar momentum transfer from the
# incident and scattered wavevectors.
#
# This function is described in section 3.33 of the SNS 107030214-TD0001-R00,
# "Data Reduciton Library Software Requirements and Specifications".
#
# This function calculates the scalar momentum transfer from the
# incident and scattered wavevectors according to the equation
# \f[
# Q[i]=\sqrt{k_i^2[i]+k_f^2[i]-2k_i[i]k_f[i]\cos(\theta)}
# \f]
# Where \f$Q\f$ is the scalar momentum transfer, \f$k_i\f$ is the
# incident wavevector, \f$k_f\f$ is the final wavevector, and
# \f$\theta\f$ is the angle between the z-axis and the scattered
# neutron.
#
# Using the assumption that the uncertainties are uncorrelated,
# the square of the uncertainty of the scalar momentum transfer
# is given by
# \f[
# \sigma^2_Q[i]=\frac{1}{Q^2}((k_i[i]-k_f[i]
# cos(\theta))^2\sigma^2_{k_i}[i]+(k_f[i]-k_i[i]
# cos(\theta))^2\sigma^2_{k_f}[i]+
# (k_i[i]k_f[i]sin(\theta))^2\sigma^2_{\theta})
# \f]
# where \f$\sigma_Q\f$ is the uncertainty of the scalar momentum
# transfer, \f$\sigma_{k_i}\f$ is the uncertainty of the incident
# wavevector, \f$\sigma_{k_f}\f$ is the uncertainty of the final
# wavevector, and \f$\sigma_{\theta}\f$ is the uncertainty of the angle
# between the z-axis and the scattered neutron.
#
# \param initial_wavevector (INPUT) is the incident wavevector axis in units
# of reciprocal Angstroms
# \param initial_wavevector_err2 (INPUT) is the square of the uncertainty of
# the incident wavevector axis
# \param final_wavevector (INPUT) is the final wavevector axis in units of
# reciprocal Angstroms
# \param final_wavevector_err2 (INPUT) is the square of the uncertainty of the
# final wavevector axis
# \param polar (INPUT) is the polar angle in the equation above in units of
# radians
# \param polar_err2 (INPUT) is the square of the uncertainty in polar angle
# \return Two NessiVectors:
# - The first NessiVector returned is the scalar momentum transfer Q, axis in
# units of reciprocal Angstroms
# - The second NessiVector returned is the square of the uncertainty in the
# scalar momentum transfer axis
#

def init_scatt_wavevector_to_scalar_Q(initial_wavevector,\
                initial_wavevector_err2,\
                final_wavevector,\
                final_wavevector_err2,\
                polar, polar_err2):

   try:
      if (initial_wavevector.__type__ == nessi_vector.NessiVector.FLOAT):
         if (final_wavevector.__type__ == nessi_vector.NessiVector.FLOAT):
            try:
           Q = nessi_vector.NessiVector(len(initial_wavevector))
           Q_err2 = nessi_vector.NessiVector(len(\
          initial_wavevector))
           axis_manip_bind.init_scatt_wavevector_to_scalar_Q_f(\
              initial_wavevector.__array__,\
          initial_wavevector_err2.__array__,\
          final_wavevector.__array__,\
          final_wavevector_err2.__array__,\
          float(polar), float(polar_err2),\
          Q.__array__, Q_err2.__array__)
            except:
           raise CalculationError
         else:
        raise TypesDifferentError

      elif (initial_wavevector.__type__ == nessi_vector.NessiVector.DOUBLE):
         if (final_energy.__type__ == nessi_vector.NessiVector.DOUBLE):
            try:
           Q = nessi_vector.NessiVector(len(initial_wavevector),"double")
           Q_err2 = nessi_vector.NessiVector(len(initial_wavevector),\
                  "double")
           axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
              initial_wavevector.__array__,\
          initial_wavevector_err2.__array__,\
          final_wavevector.__array__,\
          final_wavevector_err2.__array__,\
          float(polar), float(polar_err2),\
          Q.__array__, Q_err2.__array__)
        except:
           raise CalculationError
     else:
        raise TypesDifferentError

      else:
         raise TypeError

   except TypeError:
      print "Vector type requested, %s, is not supported!" %initial_wavevector.__type__
      Q=nessi_vector.NessiVector(len(initial_wavevector))
      Q_err2=nessi_vector.NessiVector(len(initial_wavevector))

   except TypesDifferentError:
      print "Vector types (%s,%s) are different" %(initial_wavevector.__type__, \
       final_wavevector.__type__)
      Q=nessi_vector.NessiVector(len(initial_wavevector))
      Q_err2=nessi_vector.NessiVector(len(initial_wavevector))

   except CalculationError:
      print "Calculation of init_scatt_wavevector_to_scalar_Q failed"
      Q=nessi_vector.NessiVector(len(initial_wavevector))
      Q_err2=nessi_vector.NessiVector(len(initial_wavevector))

   except:
      print "Object has no attribute __type__"

   return Q, Q_err2

##
# \}

##
# \defgroup py_rebin_axis_1D axis_manip::rebin_axis_1D
# \{

##
# \brief This function rebin data and its associated errors from one axis to
# another given axis.
#
# This function is described in section 3.12 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins data and its associated errors from one axis to
# another given axis. This function uses fractional overlap of bins to
# perform the rebinning process. The function also assumes that the data
# is represented by a histogram model.
#
# To show the effects of rebinning, an example will now be discussed. We
# start with a histogram containing 3 bins, which runs from 0 to 3 on its
# x-axis. So, the histogram looks like:
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>10</TD><TD>1</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>4</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>30</TD><TD>9</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# Notice that the final x-axis value is not associated with a count value.
# This is a property of the histogram data model. Our new histogram has the
# same x-axis range [0,3], but it only has two bins. The result of the
# rebinned histogram is shown in the table below.
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>20</TD><TD>2</TD></TR>
# <TR ALIGN="CENTER"><TD>1.5</TD><TD>40</TD><TD>10</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# The new bin boundary (1.5) lies in the middle of the second bin in the
# original histogram. That means that its contents will be evenly split
# into the new bins. So,
# \f[
# Bin_1^{new} = Bin_1^{old} + 0.5 \times Bin_2^{old}
# \f]
# \f[
# Bin_2^{new} = Bin_3^{old} + 0.5 \times Bin_2^{old}
# \f]
# and
# \f[
# \sigma^2_{Bin_1^{new}} = \sigma^2_{Bin_1^{old}} + (0.5)^2 \times
# \sigma^2_{Bin_2^{old}}
# \f]
# \f[
# \sigma^2_{Bin_2^{new}} = \sigma^2_{Bin_3^{old}} + (0.5)^2 \times
# \sigma^2_{Bin_2^{old}}
# \f]
#
# This can be seen in the results presented in the above table. Now, we will
# reverse the process. The original histogram is the rebinned histogram
# with two bins used previously and the new rebinned histogram will have
# the same number of bins (3) as the previously used original histogram.
# One can see that we have the following distribution of bin contents:
#
# \f[
# Bin_1^{new} = \frac{2}{3} \times Bin_1^{old}
# \f]
# \f[
# Bin_2^{new} = \frac{1}{3} \times Bin_1^{old} + \frac{1}{3} \times
# Bin_2^{old}
# \f]
# \f[
# Bin_3^{new} = \frac{2}{3} \times Bin_3^{old}
# \f]
# and
# \f[
# \sigma^2_{Bin_1^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_1^{old}}
# \f]
# \f[
# \sigma^2_{Bin_2^{new}} = (\frac{1}{3})^2 \times \sigma^2_{Bin_1^{old}} +
# (\frac{1}{3})^2 \times \sigma^2_{Bin_2^{old}}
# \f]
# \f[
# \sigma^2_{Bin_3^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_3^{old}}
# \f]
#
# The results of this operation are shown in the following table:
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>13.33333</TD><TD>0.88888</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>1.33333</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>26.66666</TD><TD>4.44444</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# As one can see, these values are different from the first table shown in
# this example. This is due to the loss of information when performing a
# rebin on data. Therefore, rebin your data thoughtfully and carefully!
#
# This function was provided by Paul Kienzle (NIST) and is based on an
# OpenGenie routine.
#
# \param axis_in (INPUT) is the initial data axis
# \param input (INPUT) is the data associated with the initial axis
# \param input_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out (INPUT) is the target axis for rebinning
# \return Two NessiVectors:
# - The first NessiVector returned is rebinned data according to the target
# axis
# - The second NessiVector returned is the uncertainty associated with the
# rebinned  data
#

def rebin_axis_1D(axis_in, input, input_err2, axis_out):

   try:
      if (axis_in.__type__ == nessi_vector.NessiVector.FLOAT):
         if (input.__type__ == nessi_vector.NessiVector.FLOAT):
            if (axis_out.__type__ == nessi_vector.NessiVector.FLOAT):
           try:
              output = nessi_vector.NessiVector(len(axis_out)-1)
          output_err2 = nessi_vector.NessiVector(len(axis_out)-1)
          axis_manip_bind.rebin_axis_1D_f(axis_in.__array__, input.__array__,\
           input_err2.__array__, axis_out.__array__,\
           output.__array__, output_err2.__array__)
           except:
           raise CalculationError
            else:
           raise TypesDifferentError
     else:
          raise TypesDifferentError

      elif (axis_in.__type__ == nessi_vector.NessiVector.DOUBLE):
         if (input.__type__ == nessi_vectoor.NessiVector.DOUBLE):
        if (axis_out.__type__ == nessi_vector.NessiVector.DOUBLE):
               try:
                  output = nessi_vector.NessiVector(len(axis_out))
          output_err2 = nessi_vector.NessiVector(len(axis_out))
          axis_manip_bind.rebin_axis_1D_d(axis_in.__array__, input.__array__,\
           input_err2.__array__, axis_out.__array__,\
            output.__array__, output_err2.__array__)
           except:
              raise CalculationError
        else:
           raise TypesDifferentError
     else:
        raise TypesDifferentError

      else:
         raise TypeError

   except TypeError:
      print "Vector type requested is not supported!"
      output=nessi_vector.NessiVector(len(input))
      output_err2=nessi_vector.NessiVector(len(input))

   except TypesDifferentError:
      print "Vector types are different"
      output=nessi_vector.NessiVector(len(input))
      output_err2=nessi_vector.NessiVector(len(input))

   except CalculationError:
      print "Calculation of rebin_axis_1D failed"
      output=nessi_vector.NessiVector(len(input))
      output_err2=nessi_vector.NessiVector(len(input))

   except:
      print "Object has no attribute __type__"

   return output, output_err2

##
# \}

##
# \defgroup py_reverse_array_cp axis_manip::reverse_array_cp
# \{

##
# \brief This function will reorder a NessiVector so the last element of the
# supplied NessiVector is the first element of the result NessiVector
#
# This function is described in section 3.11 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function will reorder a NessiVector so the last element of the
# supplied NessiVector is the first element of the result NessiVector.
#
# \param input (INPUT) is the NessiVector to be reversed
#
# \return The reversed NessiVector.
#

def reverse_array_cp(input):

    try:
        if (input.__type__ == nessi_vector.NessiVector.FLOAT):
            try:
                output = nessi_vector.NessiVector(len(input))
                axis_manip_bind.reverse_array_cp_f(input.__array__, output.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.DOUBLE):
            try:
                output = nessi_vector.NessiVector(len(input),"double")
                axis_manip_bind.reverse_array_cp_d(input.__array__, output.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.INT):
            try:
                output = nessi_vector.NessiVector(len(input),"int")
                axis_manip_bind.reverse_array_cp_d(input.__array__, output.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.UINT):
            try:
                output = nessi_vector.NessiVector(len(input),"uint")
                axis_manip_bind.reverse_array_cp_d(input.__array__, output.__array__)
            except:
                raise CalculationError

          else:
            raise TypeError

    except CalculationError:
        print "Calculation of reverse_array_cp failed"
        output = nessi_vector.NessiVector(len(input))

    except TypeError:
        print "Type not supported by NessiVector"
        output = nessi_vector.NessiVector(len(input))

    except:
        print "Object has no attribute __type__"

    return output

##
# \}

##
# \defgroup py_reverse_array_nc axis_manip::reverse_array_nc
# \{

##
# \brief This function will reorder a NessiVector so the last element of the
# NessiVector is the first element of the supplied NessiVector.
#
# This function is not described but is based on section 3.11 of the SNS
# 107030214-TD0001-R00, "Data Reduction Library Software Requirements and
# Specifications".
#
# This function will reorder a NessiVector so the last element of the
# supplied NessiVector is the first element of the supplied NessiVector. This
# NessiVector reversal is done in place on the supplied NessiVector
# (i.e. no copy).
#
# \param input (INPUT/OUTPUT) is the NessiVector to be reversed. It also is the
# place holder for the reversed NessiVector.
#

def reverse_array_nc(input):

    try:
        if (input.__type__ == nessi_vector.NessiVector.FLOAT):
            try:
                axis_manip_bind.reverse_array_nc_f(input.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.DOUBLE):
            try:
                 axis_manip_bind.reverse_array_nc_d(input.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.INT):
            try:
                 axis_manip_bind.reverse_array_nc_d(input.__array__)
            except:
                raise CalculationError

        elif (input.__type__ == nessi_vector.NessiVector.UINT):
            try:
                 axis_manip_bind.reverse_array_nc_d(input.__array__)
            except:
                raise CalculationError

        else:
            raise TypeError

    except CalculationError:
        print "Calculation of reverse_array_nc failed"

    except TypeError:
        print "Type not supported by NessiVector"

    except:
        print "object has no attribute __type__"

    return

##
#\}

##
# \defgroup py_tof_to_initial_wavelength_igs \
# axis_manip::tof_to_initial_wavelength_igs
# \{

##
# \brief This function calculates the initial wavelength for an inverse
# geometry spectrometer
#
# This function is described in section 3.29 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the initial wavelength for an inverse
# geometry spectrometer according to the equation
# \f[
# \lambda_i[i]=\frac{h}{m_n L_S}
#              \left(t[i]-\frac{m_n \lambda_f L_D}{h} -t_0 \right)
# \f]
# Where \f$\lambda_i[i]\f$ is the incident wavelength, \f$h\f$ is
# Planck's constant, \f$m_n\f$ is the mass of the neutron,
# \f$L_S\f$ is the distance from the source to the sample,
# \f$t[i]\f$ is the total time-of-flight, \f$\lambda_f\f$ is the
# final wavelength, \f$L_D\f$ is the distance from the sample to
# the detector, and \f$t_0\f$ is the time offset.
#
# Assuming that the uncertainties are uncorrelated, the square of
# the uncertainty of the initial wavelength for an inverse geometry
# spectromer is defined by
# \f[
# \sigma^2_{\lambda_i}[i]=
# \left(\frac{\lambda_i[i]}{L_S}\right)^2*\sigma^2_{L_S}
# + \left(\frac{h}{m_n*L_S}\right)^2(\sigma^2_t+\sigma^2_{t_0})+
# \left(\frac{\lambda_f}{L_S}\right)^2\sigma^2_{L_D}
# + \left(\frac{L_D}{L_S}\right)^2\sigma^2_{\lambda_f}
# \f]
#
# where \f$\sigma_{\lambda_i}\f$ is the uncertainty of the initial
# wavelength axis, \f$\sigma_{L_S}\f$ is the uncertainty of the
# distance from the source to the sample, \f$\sigma_t\f$ is the
# uncertainty of the time-of-flight, \f$\sigma_{t_0}\f$ is the
# uncertainty of the time-offset, \f$\sigma_{L_D}\f$ is the
# uncertainty of the distance from the sample to the detector, and
# \f$\sigma_{\lambda_f}\f$ the uncertainty of the final wavelength.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param final_wavelength (INPUT) is the final wavelength of the
# neutron in units of Angstroms
# \param final_wavelength_err2 (INPUT) is the square of the
# uncertainty in final_wavelength
# \param time_offset (INPUT) is the time offset of the neutron
# emitting from the source assuming the velocity supplied in units
# of micro-seconds
# \param time_offset_err2 (INPUT) is the square of the uncertainty
# in time_offset
# \param dist_source_sample (INPUT) is the distance from source to
# sample in units of meter
# \param dist_source_sample_err2 (INPUT) is the square of the
# uncertainty in dist_source_sample
# \param dist_sample_detector (INPUT) is the distance from sample
# to detector in units of meter
# \param dist_sample_detector_err2 (INPUT) is the square of the
# uncertainty in dist_sample_detector
#
# \return Two NessiVectors:
# - The first NessiVector returned is the initial wavelength axis
# in units of Angstrom
# - The second NessiVector returned is the square of the
# uncertainty of the initial wavelength axis
#

def tof_to_initial_wavelength_igs(tof,tof_err2,\
            final_wavelength, final_wavelength_err2,\
            time_offset, time_offset_err2,\
            dist_source_sample, dist_source_sample_err2,\
            dist_sample_detector, dist_sample_detector_err2):

   try:
      if (tof.__type__ == nessi_vector.NessiVector.FLOAT):
         try:
        initial_wavelength = nessi_vector.NessiVector(len(tof))
        initial_wavelength_err2 = nessi_vector.NessiVector(len(tof))
        axis_manip_bind.tof_to_initial_wavelength_igs_f(tof.__array__,\
         tof_err2.__array__,\
         float(final_wavelength), float(final_wavelength_err2),\
         float(time_offset), float(time_offset_err2),\
         float(dist_source_sample), float(dist_source_sample_err2),\
         float(dist_sample_detector), float(dist_sample_detector_err2),\
         initial_wavelength.__array__, \
         initial_wavelength_err2.__array__)
     except:
        raise CalculationError
      elif (tof.__type__ == nessi_vector.NessiVector.DOUBLE):
         try:
        initial_wavelength = nessi_vector.NessiVector(len(tof),\
         "double")
        initial_wavelength_err2 = nessi_vector.NessiVector(len(tof),\
         "double")
        axis_manip_bind.tof_to_initial_wavelength_igs_d(tof.__array__, \
         tof_err2.__array__,\
         final_wavelength, final_wavelength_err2,\
         time_offset, time_offset_err2,\
         dist_source_sample, dist_source_sample_err2,\
         dist_sample_detector, dist_sample_detector_err2,\
         initial_wavelength.__array__, \
         initial_wavelength_err2.__array__)
     except:
        raise CalculationError
      else:
         raise TypeError

   except TypeError:
      print "Vector type requested is not supported by NessiVector"
      initial_wavelength = nessi_vector.NessiVector(len(tof))
      initial_wavelength_err2 = nessi_vector.NessiVector(len(tof))


   except CalculationError:
      print "Calculation of tof_to_initial_wavevelength_igs failed"
      initial_wavelength = nessi_vector.NessiVector(len(tof))
      initial_wavelength_err2 = nessi_vector.NessiVector(len(tof))

   except:
      print "Object has no attribute __type__"

   return initial_wavelength, initial_wavelength_err2

##
# \}

##
# \defgroup py_tof_to_wavelength axis_manip::tof_to_wavelength
# \{

##
# \brief This function converts the time-of-fligth to wavelength
#
# This function is described in section 3.15 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts the time-of-flight to wavelength according
# to the equation
# \f[
# \lambda[i]=\frac{h TOF[i]}{m_n L}
# \f]
# Where \f$\lambda[i]\f$ is the wavelength, \f$h\f$ is Planck's
# constant, \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the
# mass of the neutron, and \f$L\f$ is the total flight path of the
# neutron.
#
# Assuming that the uncertainties are uncorrelated, the square of the
# uncertainty of the wavelength axis is given by
#
# \f[
# \sigma^2_{\lambda}[i]=\left(\frac{h}{m_n L}\right)^2\sigma^2_{TOF}[i]+
# \left(\frac{\lambda[i]}{L}\right)^2\sigma^2_L
# \f]
# where \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis,
# \f$\sigma_{TOF}\f$ is the uncertainty in the time of flight axis, and
# \f$\sigma_L\f$ is the uncertainty in the pathlength.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param pathlength (INPUT) is the total flight path of the neutron
# in units of meter
# \param pathlength_err2 (INPUT) is the square of the uncertainty
# in pathlength
#
# \return Two NessiVectors:
# - The first NessiVector returned is the wavelength axis in units of
# angstrom
# - The second NessiVector returned is the square of the uncertainty
# in the wavelength axis
#

def tof_to_wavelength(tof, tof_err2, pathlength, pathlength_err2):

   try:
      if (tof.__type__ == nessi_vector.NessiVector.FLOAT):
         try:
        wavelength = nessi_vector.NessiVector(len(tof))
        wavelength_err2 = nessi_vector.NessiVector(len(tof))
        axis_manip_bind.tof_to_wavelength_f(tof.__array__, tof_err2.__array__,\
         pathlength, pathlength_err2,\
         wavelength.__array__, wavelength_err2.__array__)
         except:
        raise CalculationError
      elif (tof.__type__ == nessi_vector.NessiVector.DOUBLE):
         try:
            wavelength = nessi_vector.NessiVector(len(tof),"double")
        wavelength_err2 = nessi_vector.NessiVector(len(tof),"double")
        axis_manip_bind.tof_to_wavelength_d(tof.__array__, tof_err2.__array__,\
         pathlength, pathlength_err2,\
         wavelength.__array__, wavelength_err2.__array__)
         except:
            raise CalculationError
      else:
         raise TypeError

   except TypeError:
      print "Vector type requested is not supported by NessiVector"
      wavelength = nessi_vector.NessiVector(len(tof))
      wavelength_err2 = nessi_vector.NessiVector(len(tof))

   except CalculationError:
      print "Calculation of tof_to_wavelength failed"
      wavelength = nessi_vector.NessiVector(len(tof))
      wavelength_err2 = nessi_vector.NessiVector(len(tof))

   except:
      print "Object has no attribute __type__"

   return wavelength, wavelength_err2

##
# \}

##
# \defgroup py_wavelength_to_energy axis_manip::wavelength_to_energy
# \{

##
# \brief This function calculates the energy of a neutron given its wavelength
#
# This function is described in section 3.22 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the energy of a neutron given its
# wavelength according to the equation
# \f[
# E[i]=\frac{h^2}{2 m_n \lambda[i]^2}
#     =\frac{81.83 Angstrom^2}{\lambda[i]^2} meV
# \f]
# Where \f$E\f$ is energy of the neutron, \f$h\f$ is Planck's
# constant, \f$m_n\f$ is the mass of the neutron, and \f$lambda\f$
# is the wavelength of the neutron.
#
# Assuming that the uncertainty are uncorrelated, the uncertainty
# in the energy is defined by
# \f[
# \sigma^2_E[i]=\left(\frac{2E}{\lambda}\right)^2\sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma_E\f$ is the uncertainty in the energy, and
# \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis.
#
# \param wavelength (INPUT) is the wavelength axis in units of
# angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
#
# \return Two NessiVectors:
# - The first NessiVector returned is the energy of the neutron in units of
# meV
# - The second NessiVector returned is the square of the uncertainty in
# the energy
#

def wavelength_to_energy(wavelength, wavelength_err2):

   try:
      if (wavelength.__type__ == nessi_vector.NessiVector.FLOAT):
         try:
        energy = nessi_vector.NessiVector(len(wavelength))
        energy_err2 = nessi_vector.NessiVector(len(wavelength))
        axis_manip_bind.wavelength_to_energy_f(wavelength.__array__, \
         wavelength_err2.__array__, energy.__array__, energy_err2.__array__)
     except:
        raise CalculationError

      elif (wavelength.__type__ == nessi_vector.NessiVector.DOUBLE):
         try:
        energy = nessi_vector.NessiVector(len(wavelength),"double")
        energy_err2 = nessi_vector.NessiVector(len(wavelength),\
         "double")
        axis_manip_bind.wavelength_to_energy_d(wavelength.__array__, \
         wavelength_err2.__array__, energy.__array__, energy_err2.__array__)
     except:
        raise CalculationError

      else:
        raise TypeError

   except CalculationError:
      print "Calculation of wavelength_to_energy failded"
      energy = nessi_vector.NessiVector(len(wavelength))
      energy_err2 = nessi_vector.NessiVector(len(wavelength))

   except TypeError:
      print "Type not supported by NessiVector"
      energy = nessi_vector.NessiVector(len(wavelength))
      energy_err2 = nessi_vector.NessiVector(len(wavelength))

   except:
      print "Object has no attribute __type__"

   return energy, energy_err2

##
# \}

##
# \defgroup py_wavelength_to_scalar_k axis_manip::wavelength_to_scalar_k
# \{

##
# \brief This function calculates the scalar wavevector given the wavelength
#
# This function is described in section 3.24 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the scalar wavevector given the
# wavelength according to the equation
# \f[
# k[i]=\frac{2\pi}{\lambda[i]}
# \f]
# Where \f$k[i]\f$ is the scalar wavevector, and \f$\lambda\f$ is
# the wavelength.
#
# Assuming that the uncertainties are uncorrelated, the uncertainty
# in the scalar wavevector is given by
# \f[
# \sigma^2_k[i]=\left(\frac{k[i]}{\lambda}\right)^2\sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma_k\f$ is the uncertainty in the scalar wavevector, and
# \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis.
#
# \param wavelength (INPUT) is the wavelength axis in units of
# Angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
#
# \return Two NessiVectors:
# - The first NessiVector returned is the scalar wavevector in units of
# reciprocal Angstroms
# - The second NessiVector returned is the square of the uncertainty
# in the scalar wavevector
#

def wavelength_to_scalar_k(wavelength, wavelength_err2):

   try:
      if (wavelength.__type__ == nessi_vector.NessiVector.FLOAT):
         try:
            wavevector = nessi_vector.NessiVector(len(wavelength))
        wavevector_err2 = nessi_vector.NessiVector(len(wavelength))
        axis_manip_bind.wavelength_to_scalar_k_f(wavelength.__array__, \
         wavelength_err2.__array__,\
         wavevector.__array__, wavevector_err2.__array__)
     except:
        raise CalculationError

      elif (wavelength.__type__ == nessi_vector.NessiVector.DOUBLE):
     try:
        wavevector = nessi_vector.NessiVector(len(wavelength),"double")
        wavevector_err2 = nessi_vector.NessiVector(len(wavelength),\
         "double")
        axis_manip_bind.wavelength_to_scalar_k_d(wavelength.__array__,\
         wavelength_err2.__array__,\
         wavevector.__array__, wavevector_err2.__array__)
     except:
        raise CalculationError

      else:
     raise TypeError

   except CalculationError:
      print "Calculation of wavelength_to_scalar_k failed"
      wavevector = nessi_vector.NessiVector(len(wavelength))
      wavevector_err2 = nessi_vector.NessiVector(len(wavelength))

   except TypeError:
      print "Type not supported by NessiVector"
      wavevector = nessi_vector.NessiVector(len(wavelength))
      wavevector_err2 = nessi_vector.NessiVector(len(wavelength))

   except:
      print "Object has no attribute __type__"

   return wavevector, wavevector_err2

##
# \}
