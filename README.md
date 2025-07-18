# ChalkBoardApp

A lightweight collaborative whiteboard application built in C++ using SFML.

## 🔍 Overview

ChalkBoardApp lets you draw freehand on a persistent canvas with smooth, continuous strokes powered by Bresenham’s line algorithm. A top toolbar scaffold provides space for drawing tools and UI elements.

## 🚀 Features

- **Smooth Drawing:** Freehand lines rendered with Bresenham’s algorithm to fill gaps during fast mouse movements.
- **Persistent Canvas:** Uses `sf::RenderTexture` behind the scenes to accumulate strokes.
- **Toolbar Scaffold:** Placeholder buttons for pencil, shape selector, and menu — ready for eraser, color pickers, etc.
- **Modular Architecture:** Separate classes for Canvas, Menu, Brush, and future NetworkManager.

## ⚙️ Installation & Build

### Prerequisites

- **C++17** compatible compiler (Clang, GCC)
- **CMake ≥ 3.10**

### Installing SFML

**macOS (Homebrew):**

```bash
brew install sfml@2
```

**Ubuntu/Debian:**

```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

**Windows (vcpkg):**

```bash
vcpkg install sfml[graphics,window,system]
```

### Build Steps

```bash
# Clone the repository
git clone https://github.com/your‑user/ChalkBoardApp.git
cd ChalkBoardApp

# Create and enter a clean build folder
rm -rf build && mkdir build && cd build

# Configure and build
cmake ..
cmake --build .
```

## ▶️ Usage

From the `build/` directory, run:

```bash
./whiteboard
```

- **Click** once to draw a single dot.
- **Click and drag** to draw smooth lines.
- The toolbar at the top is a placeholder — future tools will include an eraser and color pickers.

## 📂 Project Structure

```plaintext
ChalkBoardApp/
├── assets/            # Images, icons, fonts
├── include/           # Public headers (Canvas.hpp, Menu.hpp, etc.)
├── src/               # Implementation files (Canvas.cpp, main.cpp, Menu.cpp)
├── build/             # CMake-generated build output
├── CMakeLists.txt     # Build configuration
└── README.md          # Project overview and instructions
```

## 🤝 Contributing

We welcome contributions! Some next steps:

- Implement **Eraser** and **Color Picker** tools in the toolbar
- Refactor `Canvas` to own its texture/image internally
- Add **real-time collaboration** via NetworkManager (SFML sockets or ASIO)
- Improve UI/UX: Undo/Redo, save/load, brush presets

## 📝 License

This project is released under the **MIT License**.

