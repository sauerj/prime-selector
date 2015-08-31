#!/usr/bin/python
from gi.repository import Gtk, GObject
import subprocess

class PRIMEselector(Gtk.Window):

    datadir = ""
    def __init__(self, *args, **kwargs):
        for key in kwargs:
            setattr(self, key, kwargs[key])
	self._create_main_window()

    def _create_main_window(self):
	self.window = Gtk.Window()
	grid = Gtk.Grid()
	grid.set_property("margin", 18)
	grid.set_row_spacing(6)
	grid.set_column_spacing(12)
	grid.set_column_homogeneous(True)
	self.window.add(grid)

	label = Gtk.Label()
	label.set_markup("<b>Select the GPU you want to use</b>")
	grid.attach(label, 0, 0, 2, 1)

	print("pkgdatadir: %s" % self.pkgdatadir)
	self.intel_button = Gtk.Button()
	self.nvidia_button = Gtk.Button()
	nvidia_image = Gtk.Image.new_from_file("%s/nvidia-logo.png" % self.pkgdatadir)
	intel_image = Gtk.Image.new_from_file("%s/intel-logo.png" % self.pkgdatadir)
	self.intel_button.set_image(intel_image)
	self.nvidia_button.set_image(nvidia_image)
	grid.attach(self.nvidia_button, 0, 1, 1, 1)
	grid.attach(self.intel_button, 1, 1, 1, 1)

	label2 = Gtk.Label("Logout")
	label2.set_halign(2)
	grid.attach(label2, 0, 2, 1, 1)

	logout_switch = Gtk.Switch()
	logout_switch.set_active(True)
	logout_switch.set_halign(1)
	grid.attach(logout_switch, 1, 2, 1, 1)

	if self.get_prime_status() == "intel":
	    self.set_sensitive_button(self.nvidia_button, self.intel_button)
	else:
	    self.set_sensitive_button(self.intel_button, self.nvidia_button)

	self.window.connect("delete-event", Gtk.main_quit)
	self.intel_button.connect("clicked", self.on_intel_clicked)
	self.nvidia_button.connect("clicked", self.on_nvidia_clicked)

    def run(self):
	self.window.show_all()
	Gtk.main()

    def get_prime_status(self):
	if "intel" in subprocess.check_output(["prime-select", "query"]):
	    return "intel"
	else:
	    return "nvidia"

    def set_sensitive_button(self, activate, deactivate):
	activate.set_sensitive(True)
	deactivate.set_sensitive(False)

    def on_intel_clicked(self, button):
	self.set_sensitive_button(self.nvidia_button, self.intel_button)

    def on_nvidia_clicked(self, button):
	self.set_sensitive_button(self.intel_button, self.nvidia_button)
