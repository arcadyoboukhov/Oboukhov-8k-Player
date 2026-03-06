# OboukhovPlayer

A lightweight desktop media player built with **C++** and **Qt**.

It supports local audio/video playback with a simple UI: open file, play/pause, stop, seek, volume control, and click-to-toggle fullscreen video.

## Features

- Play local media files (`.mp4`, `.mkv`, `.avi`, `.mov`, `.mp3`, `.wav`)
- Video output via `QVideoWidget`
- Play/Pause and Stop controls
- Seek bar (timeline slider)
- Volume slider
- Current time / total duration display
- Click video area to toggle fullscreen

## Tech Stack

- C++
- Qt Widgets
- Qt Multimedia (`QMediaPlayer`, `QAudioOutput`, `QVideoWidget`)
- Visual Studio project files (`.vcxproj`)

## Project Structure

```text
OboukhovPlayer.slnx
OboukhovPlayer/
  main.cpp
  OboukhovPlayer.h
  OboukhovPlayer.cpp
  OboukhovPlayer.ui
  OboukhovPlayer.qrc
  OboukhovPlayer.vcxproj
```

## How It Works

- `main.cpp` creates `QApplication`, constructs `OboukhovPlayer`, and starts the Qt event loop.
- `OboukhovPlayer` (inherits `QMainWindow`) initializes UI and media objects.
- `QMediaPlayer` handles playback state and position updates.
- `QAudioOutput` handles output volume.
- `QVideoWidget` renders video.
- Signal/slot connections wire buttons and sliders to media actions.

## Build and Run (Windows + Visual Studio)

1. Install dependencies:
   - Visual Studio with C++ Desktop workload
   - Qt (with Multimedia module)
   - Qt Visual Studio Tools (recommended)
2. Open `OboukhovPlayer.slnx` in Visual Studio.
3. Select `Debug` or `Release`, and target `x64`.
4. Build the solution.
5. Run the app.

## Usage

1. Click **Open** and select a local media file.
2. Use **Play/Pause** and **Stop** for playback control.
3. Drag the timeline slider to seek.
4. Adjust audio with the volume slider.
5. Click the video area to enter/exit fullscreen.

## Notes

- Playback support depends on the codecs available in your Qt/runtime environment.
- Runtime Qt multimedia plugins must be available next to the executable for distribution builds.

## License
- GNU License