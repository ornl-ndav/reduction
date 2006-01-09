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

EXTRA_DIST = html latex 
nodist_EXTRA_DIST = latex/*.aux latex/*.dvi latex/*.log 