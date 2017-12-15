// made with help from https://szilard.blogs.balabit.com/en/2012/06/how-to-add-custom-gtkmm-widget-to-glade/b

#ifndef BOOMLIN_HEADER_BAR
#define BOOMLIN_HEADER_BAR

#include <gtkmm.h>

// A lot of the seamingly useless stuff here is for Glade integration
class BoomlinHeaderBar : public Gtk::HeaderBar {
private:
  static GType gtype;

  // C to C++ conversion
  BoomlinHeaderBar(GtkHeaderBar *gobj);
  BoomlinHeaderBar();

  // C to C++ conversion
  static Glib::ObjectBase *wrap_new(GObject *o);

public:
  static void register_type();
};

#endif // BOOMLIN_HEADER_BAR
