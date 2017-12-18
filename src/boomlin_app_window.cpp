#include "boomlin_app_window.hpp"

const std::string WINDOW_WIDGET_NAME = "main_window";

BoomlinAppWindow::BoomlinAppWindow(BaseObjectType* cobject,
								   const Glib::RefPtr<Gtk::Builder>& ref_builder) : Gtk::ApplicationWindow(cobject),
  m_refBuilder(ref_builder) {
  
  }

//static
BoomlinAppWindow* BoomlinAppWindow::create() {
  // Load the Builder file and instantiate its widgets.
  auto ref_builder = Gtk::Builder::create_from_resource("/com/github/rusins/boomlin/window.ui");

  BoomlinAppWindow *window = nullptr;
  ref_builder->get_widget_derived(WINDOW_WIDGET_NAME, window);
  if (!window)
	throw std::runtime_error("No " + WINDOW_WIDGET_NAME + " object in window.ui");

  // Temp code to make window pretty
  Gtk::Image *image = nullptr;
  ref_builder->get_widget("header_bar_album_art_image", image);
  if (!image)
	throw std::runtime_error("No album art image found!");

  auto pixbuf = Gdk::Pixbuf::create_from_file("/home/raitis/Music/WRLD/Awake EP/cover.jpg");
  auto scaled = pixbuf->scale_simple(48, 48, Gdk::INTERP_BILINEAR);
  image->set(scaled);
  
  
  
  // End of temp code
  
  return window;
}

void BoomlinAppWindow::open_file(const Glib::RefPtr<Gio::File>& file) {
  
}
