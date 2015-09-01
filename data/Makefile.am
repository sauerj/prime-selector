dist_pkgdata_DATA = intel-logo.png nvidia-logo.png

desktopdir = $(datadir)/applications
desktop_DATA = PRIMEselector.desktop

CLEANFILES = PRIMEselector.desktop
EXTRA_DIST = PRIMEselector.desktop.in

do_subst = sed 	-e 's,[@]bindir[@],$(bindir),g' \
		-e 's,[@]PACKAGE_NAME[@],$(PACKAGE_NAME),g' \
		-e 's,[@]pkgdatadir[@],$(pkgdatadir),g'

PRIMEselector.desktop: PRIMEselector.desktop.in Makefile
	$(do_subst) < PRIMEselector.desktop.in > PRIMEselector.desktop
