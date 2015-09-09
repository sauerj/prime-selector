SUBDIRS = PRIMEselector
libexec_PROGRAMS = primeselect
primeselect_SOURCES = primeselect.c

bin_PROGRAMS = primeselector
primeselector_SOURCES = primeselector.c
primeselector_CPPFLAGS = -DDATADIR='"$(datadir)"' \
			-DLIBEXECDIR='"$(libexecdir)"' 
primeselector_CFLAGS = $(GTK_CFLAGS)
primeselector_LDADD = $(GTK_LIBS)


bin_SCRIPTS = prime-selector
CLEANFILES = $(bin_SCRIPTS)
EXTRA_DIST = prime-selector.in

do_subst = sed -e 's,[@]pythondir[@],$(pythondir),g' \
		-e 's,[@]pkgdatadir[@],$(pkgdatadir),g' \
		-e 's,[@]PACKAGE_NAME[@],$(PACKAGE_NAME),g' \
		-e 's,[@]VERSION[@],$(VERSION),g' \
		-e 's,[@]libexecdir[@],$(libexecdir),g' \
		-e 's,[@]PACKAGE[@],$(PACKAGE),g'

prime-selector: prime-selector.in Makefile
	$(do_subst) < $(srcdir)/prime-selector.in > prime-selector
	chmod +x prime-selector

install-exec-hook:
	/bin/chown root $(DESTDIR)$(libexecdir)/primeselect
	/bin/chmod 4755 $(DESTDIR)$(libexecdir)/primeselect
