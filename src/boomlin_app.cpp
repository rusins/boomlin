#include "boomlin_app.hpp"
#include <iostream>

BoomlinApp::BoomlinApp() : Gtk::Application("com.github.rusins.boomlin"){

}

Glib::RefPtr<BoomlinApp> BoomlinApp::create() {
  return Glib::RefPtr<BoomlinApp>(new BoomlinApp());
}

BoomlinAppWindow* BoomlinApp::create_app_window() {
  auto app_window = BoomlinAppWindow::create();

  // Make sure that the application runs for as long this window is still open.
  add_window(*app_window);
  // Gtk::Application::add_window() connects a signal handler to the window's
  // signal_hide(). That handler removes the window from the application.
  // If it's the last window to be removed, the application stops running.
  // Gtk::Window::set_application() does not connect a signal handler, but is
  // otherwise equivalent to Gtk::Application::add_window().
  // TODO: replace add_window with set_application once minimizing to system tray is implemented

  // Delete the window when it is hidden.
  app_window->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &BoomlinApp::on_hide_window), app_window));

  return app_window;
}

void BoomlinApp::on_activate() {
  // The application has been started, so let's show a window.
  auto app_window = create_app_window();
  app_window->present();
}

void BoomlinApp::on_open(const Gio::Application::type_vec_files& files,
						 const Glib::ustring& hint) {
  // The application has been asked to open some files
  // so we ask the window to open each one
  BoomlinAppWindow* app_window = nullptr;
  auto windows = get_windows();
  if (windows.size() > 0)
	app_window = dynamic_cast<BoomlinAppWindow*>(windows[0]);

  try {
	if (!app_window)
	  app_window = create_app_window();

	for (const auto& file: files)
	  app_window->open_file(file);

	app_window->present();
  } catch (const Glib::Error& ex) {
	std::cerr << "ExampleApplication::on_open(): " << ex.what() << std::endl;
  } catch (const std::exception& ex) {
	std::cerr << "ExampleApplication::on_open(): " << ex.what() << std::endl;
  }
}

void BoomlinApp::on_hide_window(Gtk::Window* window) {
  delete window;
}
