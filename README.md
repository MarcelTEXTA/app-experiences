# app-experiences
This is a simple repo to publish my experience with Desktop and Juce with C++.

There are :

- **Note Pad** : a simple notepad to write text and save it in a file. It is made with wxWidgets.
- **Audio Player** : a simple audio player to play audio files. It is made with Juce.
- **Audio Recorder** : a simple audio recorder to record audio from the microphone. It is made with Juce.
- **Calculator** : a simple calculator to perform basic arithmetic operations. It is made with wxWidgets.
- **To Do List** : a simple to do list to manage tasks. It is made with wxWidgets.

## Installation
To install the applications, you need to have C++ and the respective libraries (wxWidgets for Note Pad, Calculator, and To Do List; Juce for Audio Player and Audio Recorder) installed on your system. You can clone this repository and build the applications using your preferred C++ IDE or command line tools.

## Contributing
If you want to contribute to this repository, feel free to fork it and create a pull request with your changes. You can also open an issue if you have any suggestions or find any bugs or regarding the applications.

## Compiler
To compile the application, you can go to the respective folder of the application and run the following command in the terminal:

```bash
g++ main.cpp $(wx-config --cxxflags --libs) -o app.exe
```

Or with the `.vscode/tasks.json` file, you can simply press `Ctrl + Shift + B` to build the application.