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
// nessi_vector.i - SWIG interface
//
// $Id$
//
%module nessi_vector_bind
%{
#include "nessi.hpp"
%}

// Need to ignore guard names from header files
%ignore _NESSI_HPP;

%include <std_string.i>
%include <std_vector.i>
%include "nessi.hpp"

namespace std {
  %template(DoubleVector) vector<double>;
  %template(IntVector) vector<int>;
}

namespace Nessi {
  %extend Vector<double> {
    std::string __type__() {
      return "double";
    }
    PyObject * __set_from_NessiVector__(std::vector<double> *target,
                                        PyObject *source){
        if(!PyCObject_Check(source)){
          PyErr_SetString(PyExc_TypeError,"Can only handle c-objects");
          return NULL;
        }
          
        void * void_source=PyCObject_AsVoidPtr(source);
        std::vector<double> *source_ptr=static_cast<std::vector<double> *>(void_source);

        target->assign(source_ptr->begin(),source_ptr->end());

        Py_INCREF(Py_None);
        return Py_None;
    }
  }
  %extend Vector<int> {
    std::string __type__() {
      return "int";
    }
    PyObject * __set_from_NessiVector__(std::vector<int> *target, PyObject *source){
        if(!PyCObject_Check(source)){
          PyErr_SetString(PyExc_TypeError,"Can only handle c-objects");
          return NULL;
        }
          
        void * void_source=PyCObject_AsVoidPtr(source);
        std::vector<int> *source_ptr=static_cast<std::vector<int> *>(void_source);

        target->assign(source_ptr->begin(),source_ptr->end());

        Py_INCREF(Py_None);
        return Py_None;
    }
  }
  %template(DoubleNessiVector) Vector<double>;
  %template(IntNessiVector) Vector<int>;
}
