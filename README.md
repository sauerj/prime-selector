PRIMEselector - Easily change the PRIME status
========

Introduction
--------
This project provides a GUI to change the PRIME status.
It internally depends on 'prime-select' from Canonical, later it
will be replaced to work on all kind of Linux OS.

If you are using the nouveau driver then you do not need
this program. Use instead 'DRI_PRIME=1 PROGRAM' to run
your program on the dedicated GPU.

Do I need root rights?
---------
PRIMEselector does not need any root privileges or sudoers.d rules.

Install
---------
See INSTALL for detailed instructions.

If you are using a checkout from git, then run ./bootstrap.sh
before you follow the instructions in INSTALL
You need the autotools for this.

Dependencies
---------
  * A working PRIME setup.
    See https://wiki.ubuntu.com/X/Config/HybridGraphics for help.
  * Gtk+3

Contribution
---------
See
https://help.github.com/articles/fork-a-repo/
and
https://help.github.com/articles/using-pull-requests/

for detailed workflow.
