SUBDIRS = PRIMEselector
bin_PROGRAMS = primeselect
primeselect_SOURCES = primeselect.c

bin_SCRIPTS = prime-selector
CLEANFILES = $(bin_SCRIPTS)
EXTRA_DIST = prime-selector.in

do_subst = sed -e 's,[@]pythondir[@],$(pythondir),g' \
		-e 's,[@]pkgdatadir[@],$(pkgdatadir),g' \
		-e 's,[@]PACKAGE[@],$(PACKAGE),g' \
		-e 's,[@]VERSION[@],$(VERSION),g'

prime-selector: prime-selector.in Makefile
	$(do_subst) < $(srcdir)/prime-selector.in > prime-selector
	chmod +x prime-selector

install-exec-hook:
	/bin/chown root $(DESTDIR)$(bindir)/primeselect
	/bin/chmod 4755 $(DESTDIR)$(bindir)/primeselect
