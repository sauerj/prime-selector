desktopdir = $(datadir)/applications
desktop_DATA = PRIMEselector.desktop

EXTRA_DIST = PRIMEselector.desktop

UPDATE_DESKTOP = update-desktop-database $(datadir)/applications || :

install-data-hook: 
	$(UPDATE_DESKTOP)
uninstall-hook: 
	$(UPDATE_DESKTOP)
