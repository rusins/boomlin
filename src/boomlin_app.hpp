#ifndef BOOMLIN_APP
#define BOOMLIN_APP

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class BoomlinApp : public Gtk::Window {
public:
  BoomlinApp();

protected:
  // Signal handlers:
  void on_button_clicked();

  // Member widgets
  Gtk::Button m_button;
};

#endif // BOOMLIN_APP
