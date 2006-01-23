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

PDFFILE = $(PACKAGE_TARNAME)-$(VERSION).pdf 

if PDFDOC
MAKEPDF = ./makepdf $(PDFFILE)
CPPDF = cp latex/$(PDFFILE) $(DRLIBDOCDIR)
RMPDF = rm $(DRLIBDOCDIR)/$(PDFFILE)
else
MAKEPDF = 
CPPDF = 
RMPDF = 
endif

EXTRA_DIST = html latex 
nodist_EXTRA_DIST = latex/*.aux latex/*.dvi latex/*.log 

docs:
	doxygen sns_dr_lib.cfg
	$(MAKEPDF)

install:
	./install $(DRLIBDOCDIR) $(PACKAGE_TARNAME) $(VERSION)
	$(CPPDF)

uninstall:
	rm -rf $(DRLIBDOCDIR)/html
	rm -rf $(DRLIBDOCDIR)/latex
	$(RMPDF)

clean:
	rm -rf html
	rm -rf latex
