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
# \return
# - The energy transfer axis in units of THz.
# - The square of the uncertainty in the energy tranfser axis.
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the lists are not
# recognized types

def energy_transfer(initial_energy, initial_energy_err2,\
                    final_energy, final_energy_err2):
    """
    ---------------------------------------------------------------------------

    This function calculates the energy transfer according to the equation:

    nu[i]=(E_i - E_f)/h = (E_i - E_f)/4.1357 * THz/meV

    where, nu is the energy transfer, E_i is the incident energy, E_f is
    the final energy.

    Using the assumption of uncorrelated uncertainties, the square of the
    uncertainty of the energy transfer is given by:

    nu_err2[i]^2 = (E_i_err2[i]^2 + E_f_err2[i]^2)/h^2

    where E_i_err2 is the uncertainty of the incident energy axis, and
    E_f_err2 is the uncertainty of the final energy axis.

    Parameters:
    __________

    -> initial_energy is the incident energy axis in units of meV
    -> initial_energy_err2 is the square of the uncertainty of the incident
       energy axis
    -> final_energy is the final energy axis in units of meV
    -> final_energy_err2 is the square of the uncertainty of the final energy
       axis

    Returns - 2 NessiVectors:
    ________________________

    <- the energy transfer axis in units of THz
    <- the square of the uncertainty in the energy transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the lists are not
       recognized types
    """

    try:
        if initial_energy.__type__ != final_energy.__type__:
            raise TypeError, "Initial Energy and Final Energy array types \
            are not the same."

        if initial_energy.__type__ != initial_energy_err2.__type__:
            raise TypeError, "Initial Energy and Initial Energy Err2 array \
            types are not the same."

        if (initial_energy.__type__ == nessi_vector.NessiVector.FLOAT):
            energy_transfer = nessi_vector.NessiVector(len(initial_energy), \
                                                       "float")
            energy_transfer_err2 = nessi_vector.NessiVector(\
                len(initial_energy), "float")
            axis_manip_bind.energy_transfer_f(\
                            initial_energy.__array__,\
                            initial_energy_err2.__array__,\
                            final_energy.__array__,\
                            final_energy_err2.__array__,\
                            energy_transfer.__array__,\
                            energy_transfer_err2.__array__)

        elif (initial_energy.__type__ == nessi_vector.NessiVector.DOUBLE):
            energy_transfer = nessi_vector.NessiVector(len(initial_energy))
            energy_transfer_err2 = nessi_vector.NessiVector(\
                            len(initial_energy))
            axis_manip_bind.energy_transfer_d(\
                            initial_energy.__array__,\
                            initial_energy_err2.__array__,\
                            final_energy.__array__,\
                            final_energy_err2.__array__,\
                            energy_transfer.__array__,\
                            energy_transfer_err2.__array__)
        else:
            raise TypeError, "Unknown primitive type %s", \
                  str(initial_energy.__type__)

        return energy_transfer, energy_transfer_err2

    except AttributeError:
        pass

    try:
        initial_energy.__type__
        array = initial_energy
        array_err2 = initial_energy_err2
        scalar = final_energy
        scalar_err2 = final_energy_err2

        if(array.__type__ == array.FLOAT):
            energy_transfer = nessi_vector.NessiVector(len(array), "float")
            energy_transfer_err2 = nessi_vector.NessiVector(len(array), \
                                                            "float")
            axis_manip_bind.energy_transfer_f(\
                        array.__array__,\
                        array_err2.__array__,\
                        float(scalar),\
                        float(scalar_err2),\
                        energy_transfer.__array__,\
                        energy_transfer_err2.__array__)

        elif(array.__type__ == array.DOUBLE):
            energy_transfer = nessi_vector.NessiVector(len(array))
            energy_transfer_err2 = nessi_vector.NessiVector(len(array))
            axis_manip_bind.energy_transfer_d(\
                        array.__array__,\
                        array_err2.__array__,\
                        float(scalar),\
                        float(scalar_err2),\
                        energy_transfer.__array__,\
                        energy_transfer_err2.__array__)

        else:
            raise TypeError,"Unknown primative type %s" % str(array.__type__)

        return energy_transfer, energy_transfer_err2

    except AttributeError:
        try:
            final_energy.__type__
            array = final_energy
            array_err2 = final_energy_err2
            scalar = initial_energy
            scalar_err2 = initial_energy_err2

            if (array.__type__ == nessi_vector.NessiVector.FLOAT):
                energy_transfer = nessi_vector.NessiVector(len(array), "FLOAT")
                energy_transfer_err2 = nessi_vector.NessiVector(len(array), \
                                                                "FLOAT")
                axis_manip_bind.energy_transfer_f(\
                        float(scalar),\
                        float(scalar_err2),\
                        array.__array__,\
                        array_err2.__array__,\
                        energy_transfer.__array__,\
                        energy_transfer_err2.__array__)

            elif (array.__type__ == nessi_vector.NessiVector.DOUBLE):
                energy_transfer = nessi_vector.NessiVector(len(array))
                energy_transfer_err2 = nessi_vector.NessiVector(len(array))
                axis_manip_bind.energy_transfer_d(\
                        float(scalar),\
                        float(scalar_err2),\
                        array.__array__,\
                        array_err2.__array__,\
                        energy_transfer.__array__,\
                        energy_transfer_err2.__array__)
            else:
                raise TypeError,"Unknown primative type %s" \
                      % str(array.__type__)

            return energy_transfer, energy_transfer_err2

        except AttributeError:
            raise NotImplementedError, "Scalar-Scalar version of \
            energy_transfer is not implemented"

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
# \return
# - The scalar momentum transfer Q axis in units of reciprocal Angstroms
# - The square of the uncertainty in the scalar momentum transfer axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types


def init_scatt_wavevector_to_scalar_Q(initial_wavevector,\
                                      initial_wavevector_err2,\
                                      final_wavevector,\
                                      final_wavevector_err2,\
                                      polar, polar_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the scalar momentum transfer from the incident
    and scattered wavevectors according to the equation:

    Q[i] = sqrt{k_i[i]^2 + k_f[i]^2 - 2.k_i[i].k_f[i].cos(theta)}

    Where Q is the scalar momentum transfer, k_i is the incident wavevector,
    k_f is the final wavevector, and theta is the angle between the z-axis and
    the scattered neutron.

    Using the assumption that the uncertainties are uncorrelated, the square of
    of the uncertainty of the scalar momentum transfer is given by:

    Q_err2[i]^2 = 1/Q^2{(k_i[i]^2-k_f[i]^2.cos(theta))^2.k_i_err2[i]^2 +
                  (k_f[i]-k_i.cos(theta))^2.k_f_err2[i]^2 +
                  (k_i[i].k_f[i].sin(theta))^2.theta_err2^2

    where Q_err2[i] it the uncertainty of the scalar momentum transfer,
    k_i_err2 is the uncertainty of the incident wavevector, k_f_err2 is the
    uncertainty of the final wavevector, and theta_err2 is the
    uncertainty of the angle between the z-axis and the scattered neutron

    Parameters:
    __________

    -> initial_wavevector is the incident wavevector axis in units of
       reciprocal Angstroms
    -> initial_wavevector_err2 is the square of the uncertainty of the incident
       wavevector axis
    -> final_wavevector is the final wavevector axis in units of reciprocal
       Angstroms
    -> final_wavevector_err2 is the square of the uncertainty of the final
       wavevector axis
    -> polar is the polar angle in units of radians
    -> polar_err2 is the square of the uncertainty in polar

    Returns - 2 NessiVectors:
    ________________________

    <- the scalar momentum transfer axis in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar momentum transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
    """

    try:
        if initial_wavevector.__type__ != final_wavevector.__type__:
            raise TypeError, "Initial Wavevector and Scattered Wavevector \
            array types are not the same."

        if initial_wavevector.__type__ != initial_wavevector_err2.__type__:
            raise TypeError, "Initial Wavevector and Initial Wavevector Err2 \
            array types are not the same."

        if (initial_wavevector.__type__ == nessi_vector.NessiVector.FLOAT):
            Q = nessi_vector.NessiVector(len(initial_wavevector), "float")
            Q_err2 = nessi_vector.NessiVector(len(initial_wavevector),\
                                              "float")
            axis_manip_bind.init_scatt_wavevector_to_scalar_Q_f(\
                                            initial_wavevector.__array__,\
                                            initial_wavevector_err2.__array__,\
                                            final_wavevector.__array__,\
                                            final_wavevector_err2.__array__,\
                                            float(polar), \
                                            float(polar_err2),\
                                            Q.__array__, Q_err2.__array__)

        elif (initial_wavevector.__type__ == nessi_vector.NessiVector.DOUBLE):
            Q = nessi_vector.NessiVector(len(initial_wavevector))
            Q_err2 = nessi_vector.NessiVector(len(initial_wavevector))
            axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       initial_wavevector.__array__,\
                                       initial_wavevector_err2.__array__,\
                                       final_wavevector.__array__,\
                                       final_wavevector_err2.__array__,\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)
        else:
            raise TypeError, "Unknown primitive type %s", \
                  str(initial_wavevector.__type__)

        return Q, Q_err2

    except AttributeError:
        pass

    try:
        initial_wavevector.__type__
        array = initial_wavevector
        array_err2 = initial_wavevector_err2
        scalar = final_wavevector
        scalar_err2 = final_wavevector_err2

        if(array.__type__ == array.FLOAT):
            Q = nessi_vector.NessiVector(len(array), "float")
            Q_err2 = nessi_vector.NessiVector(len(array), "float")
            axis_manip_bind.init_scatt_wavevector_to_scalar_Q_f(\
                                            array.__array__,\
                                            array_err2.__array__,\
                                            float(scalar),\
                                            float(scalar_err2),\
                                            float(polar), \
                                            float(polar_err2),\
                                            Q.__array__, Q_err2.__array__)

        elif(array.__type__ == array.DOUBLE):
            Q = nessi_vector.NessiVector(len(array))
            Q_err2 = nessi_vector.NessiVector(len(array))
            axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       array.__array__,\
                                       array_err2.__array__,\
                                       float(scalar),\
                                       float(scalar_err2),\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)

        else:
            raise TypeError,"Unknown primative type %s" % str(array.__type__)

        return Q, Q_err2

    except AttributeError:
        try:
            final_wavevector.__type__
            array = final_wavevector
            array_err2 = final_wavevector_err2
            scalar = initial_wavevector
            scalar_err2 = initial_wavevector_err2

            if (array.__type__ == nessi_vector.NessiVector.FLOAT):
                Q = nessi_vector.NessiVector(len(array), "FLOAT")
                Q_err2 = nessi_vector.NessiVector(len(array), "FLOAT")
                axis_manip_bind.init_scatt_wavevector_to_scalar_Q_f(\
                                            float(scalar),\
                                            float(scalar_err2),\
                                            array.__array__,\
                                            array_err2.__array__,\
                                            float(polar), \
                                            float(polar_err2),\
                                            Q.__array__, Q_err2.__array__)

            elif (array.__type__ == nessi_vector.NessiVector.DOUBLE):
                Q = nessi_vector.NessiVector(len(array))
                Q_err2 = nessi_vector.NessiVector(len(array))
                axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       float(scalar),\
                                       float(scalar_err2),\
                                       array.__array__,\
                                       array_err2.__array__,\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)

            else:
                raise TypeError,"Unknown primative type %s" \
                      % str(array.__type__)

            return Q, Q_err2

        except AttributeError:
            raise NotImplementedError, "Scalar-Scalar version of \
            init_scatt_wavevector_to_scalar_Q is not implemented"

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
# \return
# - The rebinned data according to the target axis
# - The uncertainty associated with the rebinned  data
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def rebin_axis_1D(axis_in, input, input_err2, axis_out):

    """
    ---------------------------------------------------------------------------

    This function rebins data and its associated errors from one axis to
    another given axis. This function uses fractional overlap of bins to
    perform the rebinning process. The function also assumes that the data
    is represented by a histogram model.

    To show the effects of rebinning, an example will now be discussed. We
    start with a histogram containing 3 bins, which runs from 0 to 3 on its
    x-axis. So, the histogram looks like:

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        |    10     |     1
                     1        |    20     |     4
                     2        |    30     |     9
                     3

    Notice that the final x-axis value is not associated with a count value.
    This is a property of the histogram data model.
    Our new histogram has the same x-axis range [0,3], but it only has two
    bins. The result of the rebinned histrogram is shown in the table below.

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        |    20     |     2
                    1.5       |    40     |     10
                     3

    The new bin boundary (1.5) lies in the middle of the second bin in the
    original histogram. That means that its contents will be envly split into
    the new bins. So,

          Bin_1_new = Bin_1_old + 0.5.Bin_2_old
          Bin_2_new = Bin_3_old + 0.5.Bin_2_old
    and
          (Bin_1_new_err2)^2 = (Bin_1_old_err2)^2 + (0.5)^2.(Bin_2_old_err2)^2
          (Bin_2_new_err2)^2 = (Bin_3_old_err2)^2 + (0.5)^2.(Bin_2_old_err2)^2

    This can be seen in the results presented in the above table. Now, we will
    reverse the process. The original histogram is the rebinned histogram with
    the two bins used previously and the new rebinned histogram will have the
    same number of bins (3) as the previously used original histogram. One
    can see that we have the following distribution of bins contents:

          Bin_1_new = 2/3.Bin_1_old
          Bin_2_new = 1/3.Bin_1_old + 1/3.Bin_2_old
          Bin_3_new = 2/3.Bin_3_old
    and
          (Bin_1_new_err2)^2 = (2/3)^2.(Bin_1_old_err2)^2
          (Bin_2_new_err2)^2 = (1/3)^2.(Bin_1_old_err2)^2 +
                               (1/3)^2.(Bin_2_old_err2)^2
          (Bin_3_new_err2)^2 = (2/3)^2.(Bin_3_old_err2)^2

    The result of this operation are shown in the following table:

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        | 13.33333  |  0.88888
                     1        |    20     |  1.33333
                     2        | 26.66666  |  4.44444
                     3

    As one can see, these values are different from the first table
    shown in this example. This is due to the loss of information when
    performing a rebin on data. Therefore, rebin your data thoughtfully and
    carefully!

    Parameters:
    __________

    -> axis_in is the initial data axis
    -> input is the data associated with the initial axis
    -> input_err2 is the square of the uncertainty associated with the data
    -> axis_out is the target axis for rebinning

    Returns - two NessiVectors:
    __________________________

    <- the rebinned data according to the target axis
    <- the square of the uncertainty associated with the rebinned data

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
       
    """

    if axis_in.__type__ != input.__type__:
        raise TypeError, "Input Axis and Input Data are not the same type."

    if axis_in.__type__ != axis_out.__type__:
        raise TypeError, "Input Axis and Output Axis are not the same type."

    if input.__type__ != input_err2.__type__:
        raise TypeError, "Input Data and Input Data Err2 are not the same \
        type."

    if (axis_in.__type__ == nessi_vector.NessiVector.FLOAT):
        output = nessi_vector.NessiVector(len(axis_out)-1, "float")
        output_err2 = nessi_vector.NessiVector(len(axis_out)-1, "float")
        axis_manip_bind.rebin_axis_1D_f(axis_in.__array__,\
                                        input.__array__,\
                                        input_err2.__array__, \
                                        axis_out.__array__,\
                                        output.__array__, \
                                        output_err2.__array__)

    elif (axis_in.__type__ == nessi_vector.NessiVector.DOUBLE):
        output = nessi_vector.NessiVector(len(axis_out)-1)
        output_err2 = nessi_vector.NessiVector(len(axis_out)-1)
        axis_manip_bind.rebin_axis_1D_d(axis_in.__array__,\
                                        input.__array__,\
                                        input_err2.__array__,\
                                        axis_out.__array__,\
                                        output.__array__,\
                                        output_err2.__array__)
    else:
        raise TypeError, "Unknown primitive type %s", str(input.__type__)

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
# \return
# - The reversed NessiVector
#
# \exception TypeError is thrown if the array is not a recognized type

def reverse_array_cp(input):

    """
    ---------------------------------------------------------------------------

    This function will reorder an NessiVector so the last element of the
    supplied NessiVector is the first element of the result NessiVector.

    Parameter:
    _________

    -> input is the NessiVector to be reversed

    Return - 1 NessiVector:
    ______________________

    <- the reversed NessiVector

    Exception:
    _________

    <- TypeError is thrown if the array is not a recognized type
    
    """

    try:
        output = nessi_vector.NessiVector(len(input), input.__type__)
    except AttributeError:
        raise TypeError, "Function must be supplied a NessiVector"

    if (input.__type__ == nessi_vector.NessiVector.FLOAT):
        output = nessi_vector.NessiVector(len(input), "float")
        axis_manip_bind.reverse_array_cp_f(input.__array__, output.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.DOUBLE):
        output = nessi_vector.NessiVector(len(input))
        axis_manip_bind.reverse_array_cp_d(input.__array__, output.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.INT):
        output = nessi_vector.NessiVector(len(input),"int")
        axis_manip_bind.reverse_array_cp_i(input.__array__, output.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.UINT):
        output = nessi_vector.NessiVector(len(input),"uint")
        axis_manip_bind.reverse_array_cp_u(input.__array__, output.__array__)

    else:
        raise TypeError, "Unknown primitive type %s", str(input.__type__)

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
# \return reference to the input array
#
# \exception TypeError is thrown if the array is not a recognized
# type

def reverse_array_nc(input):

    """
    ---------------------------------------------------------------------------

    This function will reorder a NessiVector so the last element of the
    supplied NessiVector is the first element of the resulting array.
    This NessiVector reversal is done in place of the supplied NessiVector.

    Parameter:
    ________________

    -> input is the NessiVector to be reversed. It is also the place holder
       for the reversed NessiVector.

    Return - one NessiVector:
    ______________________

    <- reference to the input array

    Exception:
    _________

    <- TypeError is thrown if the array is not a recognized type
    
    """

    if (input.__type__ == nessi_vector.NessiVector.FLOAT):
        axis_manip_bind.reverse_array_nc_f(input.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.DOUBLE):
        axis_manip_bind.reverse_array_nc_d(input.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.INT):
        axis_manip_bind.reverse_array_nc_i(input.__array__)

    elif (input.__type__ == nessi_vector.NessiVector.UINT):
        axis_manip_bind.reverse_array_nc_u(input.__array__)

    else:
        raise TypeError, "Unknown primitive type %s", str(input.__type__)

    return input

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
# \return
# - The initial wavelength axis in units of Angstrom
# - The square of the uncertainty of the initial wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_initial_wavelength_igs(tof,\
                                  tof_err2,\
                                  final_wavelength,\
                                  final_wavelength_err2,\
                                  time_offset,\
                                  time_offset_err2,\
                                  dist_source_sample,\
                                  dist_source_sample_err2,\
                                  dist_sample_detector,\
                                  dist_sample_detector_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the initial wavelength for an inverse geometry
    spectrometer according to the equation:

    lambda_i[i] = {h/(m_n.L_s)}{t[i] - (m_n.lambda.L_d)/h - t_0}

    where lambda is the incident wavelength, h is Planck's constant,
    m_n is the mass of the neutron, L_s is the distance from the source to
    the sample, t[i] is the total time-of-flight, lambda is the final
    wavelength, L_d is the distance from the sample to the detector, and
    t_0 is the time offset.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the initial wavelength for an inverse geometry spectromter
    is defined by

    lambda_i_err2[i]^2 = (lambda_i[i]/L_s)^2.L_s_err2^2 +
                         {h/(m_n.L_s)}^2.(t_err2^2 + t_0_err2^2) +
                         (lambda_f/L_s)^2.L_d_err2^2 +
                         (L_d/L_s)^2.lambda_f_err2^2

    where lambda_i_err2 is the uncertainty of the initial wavelength axis,
    L_s_err2 is the uncertainty of the distance from the source to the sample,
    t_err2 is the uncertainty of the time-of-flight, t_0_err2 is the
    uncertainty of the time-offset, L_d_err2 is the uncertainty of the
    distance from the sample to the detector, and lambda_f_err2 is the
    uncertainty of the final wavelength.

    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> final_wavelength is the final wavelength of the neutron in units of
       Angstroms
    -> final_wavelength_err2 is the square of the uncertainty in
       final_wavelength
    -> time_offset is the time offset of the neutron emitting from the source
       assuming the velocity supplied in units of micro-seconds
    -> time_offset_err2 is the square of the uncertainty in time_offset
    -> dist_source_sample is the distance from source to sample in units of
       meter
    -> dist_source_sample_err2 is the square of the uncertainty in
       dist_source_sample
    -> dist_sample_detector is the distance from sample to detector in units
       of meter
    -> dist_sample_detector_err2 is the square of the uncertainty in
       dist_sample_detector

    Returns - 2 NessiVectors:
    ________________________

    <- the initial wavelength axis in units of Angstroms
    <- the square of the uncertainty of the initial wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
       
    """
    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError, "Tof and Tof Err2 arrays are not the same type."

        if (tof.__type__ == nessi_vector.NessiVector.FLOAT):
            initial_wavelength = nessi_vector.NessiVector(len(tof), "float")
            initial_wavelength_err2 = nessi_vector.NessiVector(len(tof), \
                                                               "float")
            axis_manip_bind.tof_to_initial_wavelength_igs_f(\
                    tof.__array__,\
                    tof_err2.__array__,\
                    float(final_wavelength), \
                    float(final_wavelength_err2),\
                    float(time_offset), float(time_offset_err2),\
                    float(dist_source_sample), \
                    float(dist_source_sample_err2),\
                    float(dist_sample_detector), \
                    float(dist_sample_detector_err2),\
                    initial_wavelength.__array__, \
                    initial_wavelength_err2.__array__)

        elif (tof.__type__ == nessi_vector.NessiVector.DOUBLE):
            initial_wavelength = nessi_vector.NessiVector(len(tof))
            initial_wavelength_err2 = nessi_vector.NessiVector(len(tof))
            axis_manip_bind.tof_to_initial_wavelength_igs_d(\
                    tof.__array__,\
                    tof_err2.__array__,\
                    float(final_wavelength),\
                    float(final_wavelength_err2),\
                    float(time_offset, time_offset_err2),\
                    float(dist_source_sample),\
                    float(dist_source_sample_err2),\
                    float(dist_sample_detector),\
                    float(dist_sample_detector_err2),\
                    initial_wavelength.__array__, \
                    initial_wavelength_err2.__array__)

        else:
            raise TypeError, "Unknown primitive type %s", str(tof.__type__)

        return initial_wavelength, initial_wavelength_err2

    except AttributeError:
        pass

    try:
        tof.__type__
        raise TypeError, "Tof and Tof Err2 must both be scalar values."

    except AttributeError:
        try:
            tof_err2.__type__
            raise TypeError, "Tof and Tof Err2 must both be scalar values."
        except AttributeError:
            pass

    raise NotImplementedError, "Scalar version of \
    tof_to_initial_wavelength_igs is not implemented."


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
# \return
# - The wavelength axis in units of Angstroms
# - The square of the uncertainty in the wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_wavelength(tof, tof_err2, pathlength, pathlength_err2):

    """
    ---------------------------------------------------------------------------

    This function converts the time-of-flight to wavelength according
    to the equation:

    lambda[i] = (h.TOF[i])/(m_n.L)

    where lambda is the wavelength, h is Planck's constant, TOF
    is the time-of-flight, m_n is the mass of the neutron, and
    L is the total flight path of the neutron.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the wavelength axis is given by:

    lambda_err2[i]^2 = {h/(m_n.L)}^2.TOF_err2^2 +
                       (lambda/L)^2.L_err2^2

    where lambda_err2 is the uncertainty in the wavelength axis,
    TOF_err2 is the uncertainty in the time of flight axis, and
    L_err2 is the uncertainty in the pathlength.

    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> pathlength is the total flight path of the neutron in units of meter
    -> pathlength_err2 is the square of the uncertainty in pathlength

    Returns - 2 NessiVectors:
    ________________________

    <- the wavelength axis in units of Angstroms
    <- the square of the uncertainty in the wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
       
    """

    try:
        if tof.__type__ != tof_err2.__type:
            raise TypeError, "Tof and Tof Err2 arrays are not the same type."

        if (tof.__type__ == nessi_vector.NessiVector.FLOAT):
            wavelength = nessi_vector.NessiVector(len(tof), "float")
            wavelength_err2 = nessi_vector.NessiVector(len(tof), "float")
            axis_manip_bind.tof_to_wavelength_f(tof.__array__, \
                                                tof_err2.__array__,\
                                                float(pathlength),\
                                                float(pathlength_err2),\
                                                wavelength.__array__,\
                                                wavelength_err2.__array__)

        elif (tof.__type__ == nessi_vector.NessiVector.DOUBLE):
            wavelength = nessi_vector.NessiVector(len(tof))
            wavelength_err2 = nessi_vector.NessiVector(len(tof))
            axis_manip_bind.tof_to_wavelength_d(tof.__array__,\
                                                tof_err2.__array__,\
                                                float(pathlength),\
                                                float(pathlength_err2),\
                                                wavelength.__array__,\
                                                wavelength_err2.__array__)

        else:
            raise TypeError, "Unknown primitive type %s", str(tof.__type__)

        return wavelength, wavelength_err2

    except AttributeError:
        pass

    try:
        tof.__type__
        raise TypeError, "Tof and Tof Err2 must both be scalar values."

    except AttributeError:
        try:
            tof_err2.__type__
            raise TypeError, "Tof and Tof Err2 must both be scalar values."
        except AttributeError:
            pass

    raise NotImplementedError, "Scalar version of tof_to_wavelength is not \
    implemented."


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
# \return
# - The energy of the neutron in units of meV
# - The square of the uncertainty in the energy
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def wavelength_to_energy(wavelength, wavelength_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the energy of a neutron given its
    wavelength according to the equation:

    E[i] = (h^2)/(2.m_n.lambda[i]^2)
         = (81.83 Angstroms^2)/(lambda[i]^2) meV

    where E is the energy of the neutron, h is Planck's constant,
    m_n is the mass of the neutron, and lambda is the wavelength of
    the neutron.

    Assuming that the uncertainties are uncorrelated, the uncertainty in the
    energy is defined by:

    E_err2[i]^2 = (2.E/lambda)^2.lambda_err2[i]^2

    where E_err2 is the uncertainty in the energy, and
    lambda_err2 is the uncertainty in the wavelength axis.

    Parameters:
    __________

    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength
       axis

    Returns 2 NessiVectors:
    ______________________

    <- the energy of the neutron in units of meV
    <- the square of the uncertainty in the energy

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
       
    """
    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError, "Wavelength and Wavelength Err2 arrays are not \
            the same type"

        if (wavelength.__type__ == nessi_vector.NessiVector.FLOAT):
            energy = nessi_vector.NessiVector(len(wavelength), "float")
            energy_err2 = nessi_vector.NessiVector(len(wavelength), "float")
            axis_manip_bind.wavelength_to_energy_f(wavelength.__array__, \
                                                   wavelength_err2.__array__, \
                                                   energy.__array__, \
                                                   energy_err2.__array__)

        elif (wavelength.__type__ == nessi_vector.NessiVector.DOUBLE):
            energy = nessi_vector.NessiVector(len(wavelength))
            energy_err2 = nessi_vector.NessiVector(len(wavelength))
            axis_manip_bind.wavelength_to_energy_d(wavelength.__array__, \
                                                   wavelength_err2.__array__,\
                                                   energy.__array__,\
                                                   energy_err2.__array__)
        else:
            raise TypeError, "Unknown primitive type %s", \
                  str(wavelength.__type__)

        return energy, energy_err2

    except AttributeError:
        pass

    try:
        wavelength.__type__
        raise TypeError, "Wavelength and Wavelength Err2 must both be \
        scalar values."

    except AttributeError:
        try:
            wavelength_err2.__type__
            raise TypeError, "Wavelength and Wavelength Err2 must both be \
            scalar values."
        except AttributeError:
            pass

    raise NotImplementedError, "Scalar version of wavelength_to_energy is not \
    implemented."

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
# \return
# - The scalar wavevector in units of reciprocal Angstroms
# - The square of the uncertainty in the scalar wavevector
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def wavelength_to_scalar_k(wavelength, wavelength_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the scalar wavevector given the
    wavelength according to the equation:

    k[i] = (2.Pi)/(lambda[i])

    where k[i] is the scalar wavevector, and lambda is the wavelength.

    assuming that the uncertainties are uncorrelated, the uncertainty
    in the scalar wavevector is given by:

    k_err2[i]^2 = (k[i]/lambda)^2.lambda_err2[i]^2

    where k_err2 is the uncertainty in the scalar wavevector, and
    lambda_err2 is the uncertainty in the wavelength axis.

    Parameters:
    __________

    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength_axis

    Returns 2 NessiVectors:
    ______________________

    <- the scalar wavevector in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar wavevector

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
       
    """

    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError, "Wavelength and Wavelength Err2 arrays are not \
            the same type"

        if (wavelength.__type__ == nessi_vector.NessiVector.FLOAT):
            wavevector = nessi_vector.NessiVector(len(wavelength), "float")
            wavevector_err2 = nessi_vector.NessiVector(len(wavelength), \
                                                       "float")
            axis_manip_bind.wavelength_to_scalar_k_f(\
                    wavelength.__array__, \
                    wavelength_err2.__array__,\
                    wavevector.__array__,\
                    wavevector_err2.__array__)

        elif (wavelength.__type__ == nessi_vector.NessiVector.DOUBLE):
            wavevector = nessi_vector.NessiVector(len(wavelength))
            wavevector_err2 = nessi_vector.NessiVector(len(wavelength))
            axis_manip_bind.wavelength_to_scalar_k_d(\
                    wavelength.__array__,\
                    wavelength_err2.__array__,\
                    wavevector.__array__,\
                    wavevector_err2.__array__)

        else:
            raise TypeError

        return wavevector, wavevector_err2

    except AttributeError:
        pass

    try:
        wavelength.__type__
        raise TypeError, "Wavelength and Wavelength Err2 must both be \
        scalar values."

    except AttributeError:
        try:
            wavelength_err2.__type__
            raise TypeError, "Wavelength and Wavelength Err2 must both be \
            scalar values."
        except AttributeError:
            pass

    raise NotImplementedError, "Scalar version of wavelength_to_scalar_k is \
    not implemented."

##
# \}
