#include "boomlin_app.hpp"
#include <iostream>

BoomlinApp::BoomlinApp(): m_button("Hello World") {
  set_border_width(10);

  m_button.signal_clicked().connect(sigc::mem_fun(*this, &BoomlinApp::on_button_clicked));

  add(m_button);

  m_button.show();
}

void BoomlinApp::on_button_clicked() {
  std::cout << "Testing" << std::endl;
}

