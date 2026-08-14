<div align="center">

```
 ██╗   ██╗███████╗██╗      ██████╗  ██████╗██╗████████╗██╗   ██╗
 ██║   ██║██╔════╝██║     ██╔═══██╗██╔════╝██║╚══██╔══╝╚██╗ ██╔╝
 ██║   ██║█████╗  ██║     ██║   ██║██║     ██║   ██║    ╚████╔╝ 
 ╚██╗ ██╔╝██╔══╝  ██║     ██║   ██║██║     ██║   ██║    ╚██╔╝  
  ╚████╔╝ ███████╗███████╗╚██████╔╝╚██████╗██║   ██║     ██║   
   ╚═══╝  ╚══════╝╚══════╝ ╚═════╝  ╚═════╝╚═╝   ╚═╝     ╚═╝   
  ```

### ⚡ high-performance · cross-platform · real-time chat

*Built with C++ and Qt 6. Engineered for speed. Designed to feel alive.*

<br/>

[![C++](https://img.shields.io/badge/C%2B%2B-17-black?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-6.5-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![CMake](https://img.shields.io/badge/CMake-3.18-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)
[![SQLite](https://img.shields.io/badge/SQLite-3-003B57?style=for-the-badge&logo=sqlite&logoColor=white)](https://www.sqlite.org/)
[![License](https://img.shields.io/badge/License-MIT-purple?style=for-the-badge)](LICENSE)

</div>

---

<br/>

## ✦ &nbsp;What is Velocity?

Velocity is a desktop chat application that refuses to be slow. Built on a custom `QAbstractListModel` backend, a hardware-accelerated QML interface, and raw TCP sockets — every layer is optimized so that messages feel instant, the UI never stutters, and history loads without a hint of lag.

<br/>

## ✦ &nbsp;Features

```
  ⚡  REAL-TIME MESSAGING    →   QTcpSocket — zero perceptible latency
  ✦   MODERN UI/UX           →   Hardware-accelerated Qt Quick / QML
  ⬡   HIGH-PERF CORE         →   Custom QAbstractListModel data engine
  ◈   HYBRID INTELLIGENCE    →   Python bridge: sentiment analysis + spam filter  [optional]
  ◎   LOCAL PERSISTENCE      →   SQLite — full offline history & storage
```

<br/>

## ✦ &nbsp;Tech Stack

| Layer | Technology |
|---|---|
| 🧩 &nbsp;Framework | Qt 6.5 — C++ & QML |
| 🔨 &nbsp;Build System | CMake 3.18 |
| 🌐 &nbsp;Networking | TCP/IP via Qt Network Module |
| 🗄️ &nbsp;Database | SQLite via Qt SQL Module |
| 🐍 &nbsp;Language Bridge | C++ Backend / Python Logic |

<br/>

## ✦ &nbsp;Architecture

Velocity follows a strict **MVC** pattern — no shortcuts, no spaghetti.

```
  ┌──────────────────────────────────────────────┐
  │                 VIEW  ( QML )                │  ← animations, rendering, input
  └───────────────────────┬──────────────────────┘
                          │  signals & data binding
  ┌───────────────────────▼──────────────────────┐
  │          CONTROLLER  ( C++ Manager )         │  ← sockets, network state, JSON
  └───────────────────────┬──────────────────────┘
                          │  model updates
  ┌───────────────────────▼──────────────────────┐
  │            MODEL  ( C++ ListModel )          │  ← data flow, memory efficiency
  └──────────────────────────────────────────────┘
```

<br/>

## ✦ &nbsp;Getting Started

**Prerequisites**

- [Qt 6.5](https://www.qt.io/download) with Network + SQL modules
- [CMake 3.18+](https://cmake.org/download/)
- [Qt Creator](https://www.qt.io/product/development-tools) *(recommended)*
- Python 3.x *(optional — for the intelligence bridge)*

<br/>

**1 · Clone**

```bash
git clone https://github.com/yourusername/velocity.git
cd velocity
```

**2 · Build**

*Via Qt Creator:* open `CMakeLists.txt` → select your Qt 6 kit → Configure → Build

*Via terminal:*
```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt6
cmake --build . --parallel
```

**3 · Run**

> [!IMPORTANT]
> Always launch **Velocity Server** before **Velocity Client.**

<br/>

## ✦ &nbsp;Project Structure

```
velocity/
├── server/          # server application
│   └── src/
├── client/          # client application
│   ├── src/         # C++ controllers & models
│   └── qml/         # QML views & components
├── shared/          # shared utilities & types
├── python/          # optional intelligence bridge
└── CMakeLists.txt
```

<br/>

## ✦ &nbsp;Roadmap

```
  [ ]  End-to-End Encryption      →   OpenSSL E2EE for all messages
  [ ]  File & Media Sharing       →   Images, documents, rich transfers
  [ ]  Voice & Video Calling      →   Real-time A/V via WebRTC
  [ ]  User Presence & Status     →   Online indicators, custom status
  [ ]  Group Channels             →   Multi-user rooms + permissions
```

<br/>

---

<div align="center">

<br/>

```
built with ❤️ using C++ & Qt 6  
```

*Velocity — because milliseconds matter.*

</div>
