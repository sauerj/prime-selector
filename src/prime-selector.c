/*
 * prime-selector.c
 * 
 * Copyright 2015 Jens Sauer <jsauer65@gmail.com>
 * 
 * This program provides a GUI to easily change PRIME status.
 * 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Constant to reperesent the GPU */
#define GPU_NVIDIA 0
#define GPU_INTEL 1
#define GPU_ERROR -1

/**
 * Signal "clicked" Handler for the Intel Button
 * 
 * @param widget Pointer to widget passed by signal call
 * @param data Userdata passed by signal call
 */
void on_intel_clicked (GtkWidget * widget, gpointer data);

/**
 * Signal "clicked" Handler for the Nvidia Button
 * 
 * @param widget Pointer to widget passed by signal call
 * @param data Userdata passed by signal call
 */
void on_nvidia_clicked (GtkWidget * widget, gpointer data);

/**
 * Detect the current PRIME status
 * 
 * @return GPU_NVIDIA, GPU_INTEL or GPU_ERROR
 */
int get_prime_status ();

/**
 * Change the PRIME status
 * 
 * @param gpu Parameter must be GPU_INTEL or GPU_NVIDIA
 */
void change_gpu (int gpu);

/**
 * Switch the sensitivity of the Buttons
 * 
 * @param activate Button which should be clickable
 * @param deactivate Button which should not be clickable
 */
void set_sensitive_button (GtkWidget * activate, GtkWidget * deactivate);

/* Pointer to the buttons */
GtkWidget *nvidia_button;
GtkWidget *intel_button;

int
main (int argc, char **argv)
{
  int status;
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *label;
  GtkWidget *nvidia_image;
  GtkWidget *intel_image;
  GtkWidget *label2;
  GtkWidget *logout_switch;

  gtk_init (&argc, &argv);

/* Window */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), PACKAGE_NAME);
  gtk_window_set_icon_name (GTK_WINDOW (window), PACKAGE);
  gtk_container_set_border_width (GTK_CONTAINER (window), 18);

/* Grid */
  grid = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (window), grid);
  gtk_grid_set_column_spacing (GTK_GRID (grid), 12);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 6);

/* Label */
  label = gtk_label_new (NULL);
  gtk_label_set_markup (GTK_LABEL (label),
			"<b>Select the GPU you want to use</b>");
  gtk_grid_attach (GTK_GRID (grid), label, 0, 0, 2, 1);

/* Buttons */
  nvidia_button = gtk_button_new ();
  intel_button = gtk_button_new ();
  /* use logos shipped with 'prime-selector' */
  nvidia_image =
    gtk_image_new_from_file (DATADIR "/" PACKAGE "/nvidia-logo.svg");
  intel_image =
    gtk_image_new_from_file (DATADIR "/" PACKAGE "/intel-logo.svg");

  gtk_button_set_image (GTK_BUTTON (nvidia_button), nvidia_image);
  gtk_button_set_image (GTK_BUTTON (intel_button), intel_image);
  gtk_grid_attach (GTK_GRID (grid), nvidia_button, 0, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), intel_button, 1, 1, 1, 1);

/*************************************************
 * Logout switch is not implemented and useless. *
 *************************************************/

/*  label2 = gtk_label_new ("Logout");
 *  gtk_widget_set_halign (label2, GTK_ALIGN_END);
 *
 *  gtk_grid_attach (GTK_GRID (grid), label2, 0, 2, 1, 1);
 */

/*  logout_switch = gtk_switch_new ();
 *  gtk_switch_set_active (GTK_SWITCH (logout_switch), TRUE);
 *  gtk_widget_set_halign (logout_switch, GTK_ALIGN_START);
 *
 *  gtk_grid_attach (GTK_GRID (grid), logout_switch, 1, 2, 1, 1);
 */

/* Signals */
  g_signal_connect (intel_button, "clicked", G_CALLBACK (on_intel_clicked),
		    NULL);
  g_signal_connect (nvidia_button, "clicked", G_CALLBACK (on_nvidia_clicked),
		    NULL);
  g_signal_connect (window, "delete-event", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_show_all (window);

/* Get status and set sensitivity */
  status = get_prime_status ();
  switch (status)
    {
    case GPU_NVIDIA:
      set_sensitive_button (intel_button, nvidia_button);
      break;

    case GPU_INTEL:
      set_sensitive_button (nvidia_button, intel_button);
      break;

    case GPU_ERROR:
      fprintf (stderr, "Error detecting the used GPU\n");
      break;
    }

  gtk_main ();

  return 0;
}

void
on_intel_clicked (GtkWidget * widget, gpointer data)
{
  change_gpu (GPU_INTEL);
}

void
on_nvidia_clicked (GtkWidget * widget, gpointer data)
{
  change_gpu (GPU_NVIDIA);
}

void
set_sensitive_button (GtkWidget * activate, GtkWidget * deactivate)
{
  gtk_widget_set_sensitive (activate, TRUE);
  gtk_widget_set_sensitive (deactivate, FALSE);
}

int
get_prime_status ()
{
  FILE *output;
  char gpu[7];

  output = popen ("prime-select query", "r");
  if (!output)
    {
      fprintf (stderr, "incorrect parameters or too many files.\n");
      return 1;
    }

  fscanf (output, "%s\n", gpu);
  if (pclose (output) != 0)
    {
      fprintf (stderr, "Could not run more or other error.\n");
    }

  if (strcmp (gpu, "intel") == 0)
    return GPU_INTEL;

  else if (strcmp (gpu, "nvidia") == 0)
    return GPU_NVIDIA;

  else
    return -1;
}

void
change_gpu (int gpu)
{
  if (gpu == GPU_NVIDIA)
    {
      set_sensitive_button (intel_button, nvidia_button);
      system (LIBEXECDIR "/prime-selector-select nvidia");
    }
  if (gpu == GPU_INTEL)
    {
      set_sensitive_button (nvidia_button, intel_button);
      system (LIBEXECDIR "/prime-selector-select intel");
    }
}
