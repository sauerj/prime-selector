AM_CPPFLAGS = -Wall
libexec_PROGRAMS = prime-selector-select
prime_selector_select_SOURCES = prime-selector-select.c

bin_PROGRAMS = prime-selector
prime_selector_SOURCES = prime-selector.c
prime_selector_CPPFLAGS = -DDATADIR='"$(datadir)"' \
			-DLIBEXECDIR='"$(libexecdir)"' 
prime_selector_CFLAGS = $(GTK_CFLAGS)
prime_selector_LDADD = $(GTK_LIBS)

install-exec-hook:
	/bin/chown root $(DESTDIR)$(libexecdir)/prime-selector-select
	/bin/chmod 4755 $(DESTDIR)$(libexecdir)/prime-selector-select
