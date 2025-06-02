#include <gtk-2.0/gtk/gtk.h>

#include "include/config.hpp"

GtkWidget* new_label(const char* text, const char* font_str, GdkColor *color) {
    GtkWidget *label = gtk_label_new(text);

    PangoFontDescription *font_desc = pango_font_description_from_string(font_str);
    gtk_widget_modify_font(label, font_desc);
    pango_font_description_free(font_desc);

    if (color != NULL) {
        gtk_widget_modify_fg(label, GTK_STATE_NORMAL, color);
    }

    return label;
}
GtkWidget* new_button(const char* text, const char* font_str, GdkColor *color_fg, GdkColor *color_bg) {
    GtkWidget *event_box = gtk_event_box_new();

    // Цвет фона
    if (color_bg != NULL) {
        gtk_widget_modify_bg(event_box, GTK_STATE_NORMAL, color_bg);
    }

    // Контейнер с отступами внутри "кнопки"
    GtkWidget *frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(event_box), frame);

    GtkWidget *label = gtk_label_new(text);

    // Шрифт и цвет текста
    if (font_str != NULL) {
        PangoFontDescription *font_desc = pango_font_description_from_string(font_str);
        gtk_widget_modify_font(label, font_desc);
        pango_font_description_free(font_desc);
    }

    if (color_fg != NULL) {
        gtk_widget_modify_fg(label, GTK_STATE_NORMAL, color_fg);
    }

    // Контейнер с отступами для текста
    GtkWidget *alignment = gtk_alignment_new(0.5, 0.5, 0, 0);
    gtk_container_set_border_width(GTK_CONTAINER(alignment), 10); // padding
    gtk_container_add(GTK_CONTAINER(alignment), label);
    gtk_container_add(GTK_CONTAINER(frame), alignment);

    return event_box;
}

GdkColor color_text1, color_text2, color_primary, color_bg;

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    // Colors
    gdk_color_parse("#ffffff", &color_text1);
    gdk_color_parse("#a8a8a8", &color_text2);
    gdk_color_parse("#0da62c", &color_primary);
    gdk_color_parse("#000000", &color_bg);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &color_bg);
    gtk_window_set_default_size(GTK_WINDOW(window), W_WIDTH, W_HEIGHT);
    if (MAXIMIZE) {
        gtk_window_maximize(GTK_WINDOW(window));
    }
    gtk_window_set_title(GTK_WINDOW(window), W_TITLE);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
    GtkWidget *label1 = new_label("Welcome to GTK2 on PostmarketOS!", "Sans Bold 24", &color_text1);
    GtkWidget *label2 = new_label("Made with love by DiabloSat <3", "Sans 18", &color_text1);
    GtkWidget *label3 = new_label("GitHub: @progzone122 | TG/YouTube: @DiabloSat", "Sans 16", &color_text2);
    GtkWidget *button_exit = new_button("LGTM. Bye", "Sans Bold 18", &color_text1, &color_primary);

    gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button_exit, FALSE, FALSE, 20);

    g_signal_connect(button_exit, "button-press-event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *alignment = gtk_alignment_new(0.5, 0.4, 0, 0);
    gtk_container_add(GTK_CONTAINER(alignment), vbox);

    gtk_container_add(GTK_CONTAINER(window), alignment);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}