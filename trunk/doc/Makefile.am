# $Id$

docs:
	doxygen sns_dr_lib.cfg
	./makepdf $(PACKAGE_TARNAME) $(VERSION)

install:
	mkdir -p $(DRLIBDOCDIR)
	mkdir -p $(DRLIBDOCDIR)/latex
	cp -r html $(DRLIBDOCDIR)
	cp latex/*.eps $(DRLIBDOCDIR)/latex
	cp latex/*.tex $(DRLIBDOCDIR)/latex
	cp latex/$(PACKAGE_TARNAME)-$(VERSION).pdf $(DRLIBDOCDIR)

uninstall:
	rm -rf $(DRLIBDOCDIR)/html
	rm -rf $(DRLIBDOCDIR)/latex
	rm $(DRLIBDOCDIR)/$(PACKAGE_TARNAME)-$(VERSION).pdf

clean:
	rm -rf html
	rm -rf latex

EXTRA_DIST = html latex 
nodist_EXTRA_DIST = latex/*.aux latex/*.dvi latex/*.log 