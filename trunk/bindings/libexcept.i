//                     SNS Common Libraries
//           A part of the SNS Analysis Software Suite.
//
//                  Spallation Neutron Source
//          Oak Ridge National Laboratory, Oak Ridge TN.
//
//
//                             NOTICE
//
// For this software and its associated documentation, permission is granted
// to reproduce, prepare derivative works, and distribute copies to the public
// for any purpose and without fee.
//
// This material was prepared as an account of work sponsored by an agency of
// the United States Government.  Neither the United States Government nor the
// United States Department of Energy, nor any of their employees, makes any
// warranty, express or implied, or assumes any legal liability or
// responsibility for the accuracy, completeness, or usefulness of any
// information, apparatus, product, or process disclosed, or represents that
// its use would not infringe privately owned rights.
//
// libexcept.i - SWIG interface
//
// $Id$
//
%module libexcept

%include <exception.i>

// Exceptions
%exception {
  try {
    $action
  } catch (std::runtime_error &e) {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  } catch (std::invalid_argument &e) {
    PyErr_SetString(PyExc_IndexError, e.what());
    return NULL;
  } catch (std::exception &e) {
    PyErr_SetString(PyExc_Exception, e.what());
    return NULL;
  }
}
