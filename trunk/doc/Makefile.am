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

# $Id$

CPP_PDFFILE = $(PACKAGE_TARNAME)_cpp-$(VERSION).pdf
PYTHON_PDFFILE = $(PACKAGE_TARNAME)_python-$(VERSION).pdf

if PDFDOC
MAKEPDF = ./makepdf $(CPP_PDFFILE) $(PYTHON_PDFFILE)
CP_CPP_PDF = cp latex_cpp/$(CPP_PDFFILE) $(DRLIBDOCDIR)
CP_PYTHON_PDF = cp latex_python/$(PYTHON_PDFFILE) $(DRLIBDOCDIR)
RM_CPP_PDF = rm $(DRLIBDOCDIR)/$(CPP_PDFFILE)
RM_PYTHON_PDF = rm $(DRLIBDOCDIR)/$(PYTHON_PDFFILE)
else
MAKEPDF =
CP_CPP_PDF =
CP_PYTHON_PDF =
RM_CPP_PDF =
RM_PYTHON_PDF =
endif

EXTRA_DIST = html_cpp html_python images index.html instdoc latex_cpp \
	     latex_python makepdf material scl_cpp.cfg scl_python.cfg tutorials

nodist_EXTRA_DIST = latex_cpp/*.aux latex_cpp/*.dvi latex_cpp/*.log \
		    latex_python/*.aux latex_python/*.dvi latex_python/*.log

docs:
	doxygen scl_cpp.cfg
	doxygen scl_python.cfg
	$(MAKEPDF)

install:
	./instdoc $(DRLIBDOCDIR)
	$(CP_CPP_PDF)
	$(CP_PYTHON_PDF)

uninstall:
	rm -rf $(DRLIBDOCDIR)/html_cpp
	rm -rf $(DRLIBDOCDIR)/latex_cpp
	rm -rf $(DRLIBDOCDIR)/html_python
	rm -rf $(DRLIBDOCDIR)/latex_python
	$(RM_CPP_PDF)	
	$(RM_PYTHON_PDF)

clean-local:
	rm -rf html_cpp
	rm -rf latex_cpp
	rm -rf html_python
	rm -rf latex_python
