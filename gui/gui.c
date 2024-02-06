#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "gui.h"
#include "calculator.h"

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *entry = (GtkWidget *)data;
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    if (strcmp(label, "=") == 0) {
        // Attempt to perform calculation
        double num1 = 0.0, num2 = 0.0;
        char operator = '\0', *token;
        char new_text[128] = {0};
        strncpy(new_text, current_text, sizeof(new_text) - 1);
        
        token = strtok(new_text, " ");
        if (token != NULL) {
            num1 = atof(token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                operator = token[0];
                token = strtok(NULL, " ");
                if (token != NULL) {
                    num2 = atof(token);
                    double result = calculate(num1, num2, operator);
                    if (result != 0xDEADBEEF) {
                        char result_str[128];
                        snprintf(result_str, sizeof(result_str), "%.2f", result);
                        gtk_entry_set_text(GTK_ENTRY(entry), result_str);
                    } else {
                        gtk_entry_set_text(GTK_ENTRY(entry), "Error");
                    }
                    return;
                }
            }
        }
        gtk_entry_set_text(GTK_ENTRY(entry), "Error");
    } else if (strcmp(label, "C") == 0) {
        // Clear the entry widget
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    } else {
        // Append the button's label to the entry widget, handling space for operators
        char new_text[128];
        if (label[0] == '+' || label[0] == '-' || label[0] == '*' || label[0] == '/') {
            snprintf(new_text, sizeof(new_text), "%s %s ", current_text, label);
        } else {
            snprintf(new_text, sizeof(new_text), "%s%s", current_text, label);
        }
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    }
}

void init_gui(int *argc, char ***argv) {
    gtk_init(argc, argv);
}

void start_gui(void) {
    GtkWidget *window, *grid, *button, *entry;
    const char *buttons[16] = {"7", "8", "9", "/",
                               "4", "5", "6", "*",
                               "1", "2", "3", "-",
                               "C", "0", "=", "+"};

    // Initialize window and grid
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Initialize entry
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    // Initialize buttons and attach to grid
    for (int i = 0; i < 16; i++) {
        button = gtk_button_new_with_label(buttons[i]);
        gtk_grid_attach(GTK_GRID(grid), button, i % 4, 1 + i / 4, 1, 1);
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);
    }

    gtk_widget_show_all(window);
    gtk_main();
}

int main(int argc, char *argv[]) {
    // Initialize the GUI
    init_gui(&argc, &argv);
    
    // Start the GUI
    start_gui();
    
    return 0;
}
