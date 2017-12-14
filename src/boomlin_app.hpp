#ifndef BOOMLIN_APP
#define BOOMLIN_APP

#include <gtkmm.h>
#include "boomlin_app_window.hpp"

class BoomlinApp : public Gtk::Application {

protected:
  BoomlinApp();
  
public:
  static Glib::RefPtr<BoomlinApp> create();

protected:
  // Override default signal handlers:
  void on_activate() override;
  void on_open(const Gio::Application::type_vec_files& files,
			   const Glib::ustring& hint) override;

private:
  BoomlinAppWindow* create_app_window();
  void on_hide_window(Gtk::Window* window);
};

#endif // BOOMLIN_APP
