#include "boomlin_header_bar.hpp"

GType BoomlinHeaderBar::gtype = 0;

BoomlinHeaderBar::BoomlinHeaderBar(GtkHeaderBar *gobj) :
  Gtk::HeaderBar(gobj) {
  
}

BoomlinHeaderBar::BoomlinHeaderBar() : Glib::ObjectBase("boomlinheaderbar") {
  
}

Glib::ObjectBase *BoomlinHeaderBar::wrap_new(GObject *o) {
  if (gtk_widget_is_toplevel(GTK_WIDGET(o)))
	return new BoomlinHeaderBar(GTK_HEADER_BAR(o));
  else
	return Gtk::manage(new BoomlinHeaderBar(GTK_HEADER_BAR(o)));
}

void BoomlinHeaderBar::register_type() {
  if (gtype)
	return;

  BoomlinHeaderBar dummy;

  GtkWidget *widget = GTK_WIDGET(dummy.gobj());

  gtype = G_OBJECT_TYPE(widget);

  Glib::wrap_register(gtype, BoomlinHeaderBar::wrap_new);
}
