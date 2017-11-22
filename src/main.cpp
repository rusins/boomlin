#include <gtkmm/application.h>

#include "boomlin_app.hpp"

int main(int argc, char *argv[])
{
  auto app =
	Gtk::Application::create(argc, argv, "com.github.rusins.boomlin");

  BoomlinApp boomlin_app;

  return app->run(boomlin_app);
}
