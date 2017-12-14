#ifndef BOOMLIN_APP_WINDOW
#define BOOMLIN_APP_WINDOW

#include <gtkmm.h>

class BoomlinAppWindow : public Gtk::ApplicationWindow {
public:
  BoomlinAppWindow(BaseObjectType* cobject,
				   const Glib::RefPtr<Gtk::Builder>& ref_builder);

  static BoomlinAppWindow* create();
  
  void open_file(const Glib::RefPtr<Gio::File>& file);

protected:
  Glib::RefPtr<Gtk::Builder> m_refBuilder;
};

#endif //BOOMLIN_APP_WINDOW
