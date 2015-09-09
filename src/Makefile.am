libexec_PROGRAMS = primeselect
primeselect_SOURCES = primeselect.c

bin_PROGRAMS = primeselector
primeselector_SOURCES = primeselector.c
primeselector_CPPFLAGS = -DDATADIR='"$(datadir)"' \
			-DLIBEXECDIR='"$(libexecdir)"' 
primeselector_CFLAGS = $(GTK_CFLAGS)
primeselector_LDADD = $(GTK_LIBS)

install-exec-hook:
	/bin/chown root $(DESTDIR)$(libexecdir)/primeselect
	/bin/chmod 4755 $(DESTDIR)$(libexecdir)/primeselect
