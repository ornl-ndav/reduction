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
# \file bindings/phys_corr.py
#

"""
   This module gives NessiList access to the various correction routines
   provided by the C++ phys_corr library. These functions are written in
   reference to SNS 107030214-TD0001-R00, \"Data Reduction Library Software
   Requirements and Specifications.\"

   Once a function is called, according to the type of the NessiLists calling
   it, the module redirects the call to the right function.
"""

import nessi_list
import phys_corr_bind

from scl_defs import VERSION as __version__

##
# \namespace phys_corr
#
# \brief This Python abstraction layer module contains the various corrections
#        that require a model of the data.
#
# This module gives NessiList access to the various correction routines
# provided by the <i>phys_corr</i> library. These functions are written in
# reference to SNS 107030214-TD0001-R00, "Data Reduction Library Software
# Requirements and Specifications."
#
# Once a function is called, according to the type of the NessiLists calling
# it, the module redirects the call to the right function.

##
# \defgroup absorption_mult_scatt phys_corr::absorption_mult_scatt
# \{
#

##
# \brief This function calculates the absorption and multiple scattering
#        effect on the data
#
# This function is described in section 3.36 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def absorption_mult_scatt():
    """
    ---------------------------------------------------------------------------
    This function calculates the absorption and multiple scattering effect on
    the data.

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError, "This function is not implemented."
##
# \}

##
# \defgroup dead_time_corr phys_corr::dead_time_corr
# \{

##
# \brief This function calculates the effect of dead time on the data
#
# This function is described in section 3.38 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION IS NOT DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def dead_time():
    """
    ---------------------------------------------------------------------------
    This function calculates the effect of dead time on the data

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError, "This function is not implemented."

##
# \}

##
# \defgroup exp_detector_eff phys_corr::exp_detector_eff
# \{
#
   
##
# \brief This function calculates exponential detector efficiency
#
# This function is described in section 3.66 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function takes a set of (usually) wavelength values and constants 
# and calculates the detector efficiency via the following equation.
# \f[
# eff[i] = scale \times e^{-const \times axis_{bc}[i]}
# \f]
#
# where \f$eff[i]\f$ is the \f$i^{th}\f$ component of the detector 
# efficiency, \f$axis_{bc}[i]\f$ is the \f$i^{th}\f$ component of the bin 
# center axis, \f$scale\f$ is the scale factor for the detector efficiency 
# and \f$const\f$ is the exponential constant for the detector efficiency.
#
# Assuming that the uncertainties are uncorrelated, the uncertainty in the 
# detector efficiency is defined by
# \f[
# \sigma^2_{eff}[i] = e^{-2 \times const \times axis_{bc}[i]} 
# \sigma^2_{scale}
# \f]
#
# where \f$\sigma^2_{eff}[i]\f$ is the \f$i^{th}\f$ component of the 
# uncertainty of the detector efficiency and \f$\sigma^2_{scale}\f$ is the 
# uncertainty in the efficiency scale factor.
#
# <b>NOTE</b>: The units of the supplied constants should be compatible 
# with the units of the axis bin center values.
#
# \param axis_bc (INPUT) is the (usually) wavelength axis bin center values 
# \param scale (INPUT) is the scale factor for the detector efficiency
# \param scale_err2 (INPUT) is the square uncertainty of the scale factor 
# for the detector efficiency
# \param constant (INPUT) is the exponential constant for the detector 
# efficiency
#
# \return
# - The calculated detector efficiency
# - The square uncertainty in the detector efficiency
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the arrays are not recognized types

def exp_detector_eff(axis_bc, scale, scale_err2, constant):
    """
    This function takes a set of (usually) wavelength values and constants 
    and calculates the detector efficiency via the following equation.

    eff[i] = scale x e^(-const x axis_bc[i])

    where eff[i] is the i^th component of the detector efficiency, axis_bc[i]
    is the i^th component of the bin center axis, scale is the scale factor
    for the detector efficiency and const is the exponential constant for the
    detector efficiency.

    Assuming that the uncertainties are uncorrelated, the uncertainty in the 
    detector efficiency is defined by

    sigma^2_eff[i] = e^(-2 x const x axis_bc[i]) sigma^2_scale

    where sigma^2_eff[i] is the i^th component of the uncertainty of the
    detector efficiency and sigma^2_scale is the uncertainty in the efficiency
    scale factor.

    NOTE: The units of the supplied constants should be compatible with the
    units of the axis bin center values.

    Parameters:
    ----------
    -> axis_bc is the (usually) wavelength axis bin center values 
    -> scale is the scale factor for the detector efficiency
    -> scale_err2 is the square uncertainty of the scale factor for the
       detector efficiency
    -> constant is the exponential constant for the detector efficiency

    Returns:
    -------
    <- The calculated detector efficiency
    <- The square uncertainty in the detector efficiency

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized types
    """
    
    try:
        if axis_bc.__type__ == nessi_list.NessiList.DOUBLE:
            eff = nessi_list.NessiList(len(axis_bc))
            eff_err2 = nessi_list.NessiList(len(axis_bc))
            phys_corr_bind.exp_detector_eff_d(axis_bc.__array__,
                                              scale,
                                              scale_err2,
                                              constant,
                                              eff.__array__,
                                              eff_err2.__array__)

            return (eff, eff_err2)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(axis_bc.__type__))
    except AttributeError:
        eff_ss = vpair_bind.DoubleVPair()
        phys_corr_bind.exp_detector_eff_ss_d(float(axis_bc),
                                             float(scale),
                                             float(scale_err2),
                                             float(constant),
                                             eff_ss)

        return (eff_ss.val, eff_ss.val_err2)

##
# \}

##
# \defgroup incoherent_scatt_corr phys_corr::incoherent_scatt_corr
# \{

##
# \brief This function calculates the effect of incoherent scattering on the
#        data
#
# This function is described in section 3.41 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION IS NOT DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def incoherent_scatt_corr():
    """
    ---------------------------------------------------------------------------
    This function calculates the effect of incoherent scattering on the data

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError, "This function is not implemented."

##
# \}

##
# \defgroup inelastic_scatt_corr phys_corr::inelastic_scatt_corr
# \{

##
# \brief This function calculates the effect of inelastic scattering on the
#        data
#
# This function is described in section 3.40 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION IS NOT DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def inelastic_scatt_corr():
    """
    ---------------------------------------------------------------------------
    This function calculates the effect of inelastic scattering on the data

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError, "This function is not implemented."

##
# \}
