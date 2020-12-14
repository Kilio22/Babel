# Babel

The goal of this project was to create a **VOIP** cross-platform (Linux & Windows) software which enables multiple users to talk at any time.  

Here is an extract of the subject:  
### PROTOCOL
The Babel project aims to create an SIP-like Voice Over IP (VOIP) protocol. It MUST be usable over the
Internet (no multicast or anything LAN specific).  
To test your protocol you MUST write a server and a client implementation.  
The protocol MUST be a client/server protocol but voice transport MUST be client to client (the server can
have a proxy mode for conference calls or NAT-ed clients).  

The protocol MUST be a binary protocol, not a text one. For instance, TCP is a binary
protocol and HTTP is a text one.
### LIBRARIES
Any non-explicitly authorized library is explicitly **forbidden**. However:
* You are NOT allowed to use any SIP or other VOIP library.
* You MUST use the **PortAudio** (v190600.20161030) library for anything sound related
* You MUST use **Opus** (1.3.1) for the compression codec.
* You MUST use **Qt** (5.14.2) for the client’s graphical user interface, or any implementation detail on the
client side.
* You are NOT allowed to use any Qt library on the server side.
* You are allowed and encouraged to use **Boost** libraries.
* For storage you are allowed to use **sqlite3** and/or **sqlite_orm**
* PortAudio and Opus are C libraries, so you MUST create your own *abstractions* to them.

## How to run it?
### LINUX (recommended)
First, make sure QT5 library and Conan C++ package manager are installed.  
Add following remotes to Conan:
* epitech: https://api.bintray.com/conan/epitech/public-conan
* bincrafters: https://api.bintray.com/conan/bincrafters/public-conan  

At the root of the repository, run the following command:
```sh
$> mkdir build && cd build && conan install .. --build missing && cmake .. && make && cd bin
```
To run the server:
```sh
$> ./babel_server <PORT>
```
To run the client:
```sh
$> ./babel_client <SERVER_IP> <SERVER_PORT> <CLIENT_IP>
```
### WINDOWS
The QT5 Windows installation is really **hard** to do, I recommend you to use any linux distro.  
First, make sure QT5 library and Conan C++ package manager are installed.  
Add following remotes to Conan:
* epitech: https://api.bintray.com/conan/epitech/public-conan
* bincrafters: https://api.bintray.com/conan/bincrafters/public-conan  

At the root of the repository, run the following commands using powershell:
```sh
$> mkdir build
$> cd build
$> conan install .. --build missing
$> cmake ..
$> cmake --build .
$> cd bin
```
To run the server:
```sh
$> ./babel_server.exe <PORT>
```
To run the client:
```sh
$> ./babel_client.exe <SERVER_IP> <SERVER_PORT> <CLIENT_IP>
```
