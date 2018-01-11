#include <QApplication>
#include "GraphicalUserInterface.h"


int main(int argc, char** argv)
{
    std::string config_path;
    // Change here
    config_path = "/home/rcj33_ccf/ros_ws/src/daVinciToolTrack/config/sim_config_win.xml";

    QApplication app(argc, argv);

    GraphicalUserInterface gui (config_path);
    gui.show();

    return app.exec();
}
