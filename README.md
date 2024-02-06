Attempt to build a calculator app in C

This project is a simple calculator application built with C and GTK+ 3. It demonstrates basic GUI application development on macOS, specifically for systems with the M1 chip, using the GTK+ 3 framework.

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

Before you begin, ensure you have the following installed on your macOS system:
- Homebrew
- GTK+ 3
- pkg-config
- Clang compiler

If you're using Visual Studio Code, you might need to configure the include paths for IntelliSense. 
Note: The .vscode folder is excluded from this repository to maintain environment neutrality. You should configure it based on your local development environment.

To compile the calculator app, navigate to the project root directory and run:
```
clang `pkg-config --cflags gtk+-3.0` -o calculator_gui gui/gui.c src/calculator.c -Isrc/ `pkg-config --libs gtk+-3.0`
```

After compilation, you can run the application with:
```
./calculator_gui
```