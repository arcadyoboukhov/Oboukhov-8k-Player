#pragma once

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include "ui_OboukhovPlayer.h"

class OboukhovPlayer : public QMainWindow
{
    Q_OBJECT

public:
    OboukhovPlayer(QWidget* parent = nullptr);
    ~OboukhovPlayer();

private slots:
    void openFile();
    void playPause();
    void stop();

    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);

private:
    QString formatTime(qint64 ms);

    Ui::OboukhovPlayerClass ui;

    QMediaPlayer* player;
    QAudioOutput* audioOutput;

    bool fullscreen = false;

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;
};
