# QRoboticsCenter

Interfacing Embedded Development

## 1. Should I be interested?

Are you doing some serious embedded programming? Are you using arduino and looking for a nice way of streamlining development? Are you looking for a way of interfacing your larest project? Keep on reading because this might be the thing you have been looking for all along.

QRoboticsCenter serves as an interface to embedded hardware. It's main purpose is to handle communication with one or more external systems and making this data available to the user by means of a Graphical User Interface. Connections are serial and encoded by the [mavlink](http://qgroundcontrol.org/mavlink/start) protocol. USB and bluetooth are supported for now.

## 2. How does it go?

Once QRoboticsCenter is launched, it listens on all serial ports for incoming data. Once a heartbeat is found (cfr. heartbeat_message), the connection is recognized as being valid and the peer is added to a list. The peer has a unique id, between 0 and 255, and has a type, to describe its capabilities. 

Once a peer is discovered, a button is added to the main window, which allows the user to access the peers control panel. The standard panel allows the user to visualize all incoming data by means of a graph (12 in total) and set outgoing values (again 12). Also, there are 8 buttons which are meant to trigger events on the peer.

When the generic control panel is not enough, a more specific version can be designed to meet the needs at hand. This has already been done for a class of balancing robots, but can be done for many more. This however requires to add your own control panel to the source, whhich is described later on.

## 3. Getting it up and running

__The easy way:__
As the QRoboticsCenter is part of a larger project [MECO-CSI](https://github.com/maartenverbandt/MECO-CSI), prebuild versions are available in that repo and should readily deployable.

__The slightly harder way:__
If you want to have the latest version or if you want to add your own modules, you have to build the project from source. Since this is a Qt project, it is fairly easy to do the building.
1. Install [Qt](https://www.qt.io/) (At least Qt5)
2. Clone this repo in some directory, e.g projects
3. Clone the [QtModules](https://github.com/maartenverbandt/QtModules) repo in that same directory, e.g. projects
4. Open Qt and open the QRoboticsCenter project.
5. Configure the project and build it.

## 4. Interfacing your own system

Although the default implementation of the control window is for sure enough to get started, one might be interested in a more attractive, peer-specific implementation of the control panel. In order to do so, one must create some new type of robot, other than type 0. This type is used in the QRobotCoordinator to launch the right kind of GUI. As you can see, some types such as `BALLBOT` and `CAR` are already available. 

The QCar class is a simple example for a non-standard robot. The only thing that is added to the basic robot implementation is its name, 'car', and a nice icon. The control panel remains the default panel. However, some other panel is easily added by calling `getWindow()->addView(QWidget *w)`. This adds a new widget to the control panel. The default widget is still available. Switching happens using CTRL+LEFT and CTRL+RIGHT. This allows you to use for instance custom events, which link to your own buttons and using the standard debug channels to send and receive values.

The QBallbot class is a more elaborate example. This is because the ballbot sends custom mavlink messages, which requires a custom connectionmanager which links to the custom mavlink messages. As it also has some other recorders (attitude,velocity,position), it also has its own recordermanager. Of course, a customized control panel is available. If you decide you need more than the available 12 standard channels and want to use your own customized message set, you should study this example.

## 5. Interesting links

* [MECO-CSI](https://github.com/maartenverbandt/MECO-CSI)
A toolchain to easily interface embedded hardware with a pc
* [MicroOS](https://github.com/maartenverbandt/MicroOS)
Arduino library to do multitasking and handle communications to the QRoboticsCenter
