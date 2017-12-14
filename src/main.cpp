#include "boomlin_app.hpp"

int main(int argc, char *argv[])
{
  auto app = BoomlinApp::create();

  return app->run(argc, argv);
}
