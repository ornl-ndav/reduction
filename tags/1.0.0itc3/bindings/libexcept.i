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
