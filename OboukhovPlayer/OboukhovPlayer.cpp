#include "OboukhovPlayer.h"

#include <QFileDialog>
#include <QStyle>

OboukhovPlayer::OboukhovPlayer(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    player->setVideoOutput(ui.videoWidget);

    ui.positionSlider->setRange(0, 0);
    ui.volumeSlider->setRange(0, 100);
    ui.volumeSlider->setValue(50);
    audioOutput->setVolume(0.5f);

    ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui.stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    connect(ui.openButton, &QPushButton::clicked,
        this, &OboukhovPlayer::openFile);

    connect(ui.playButton, &QPushButton::clicked,
        this, &OboukhovPlayer::playPause);

    connect(ui.stopButton, &QPushButton::clicked,
        this, &OboukhovPlayer::stop);

    connect(ui.positionSlider, &QSlider::sliderMoved,
        player, &QMediaPlayer::setPosition);

    connect(ui.volumeSlider, &QSlider::valueChanged,
        this, [this](int value)
        {
            audioOutput->setVolume(value / 100.0f);
        });

    connect(player, &QMediaPlayer::positionChanged,
        this, &OboukhovPlayer::positionChanged);

    connect(player, &QMediaPlayer::durationChanged,
        this, &OboukhovPlayer::durationChanged);
    // Install event filter to detect clicks on the video widget
    ui.videoWidget->installEventFilter(this);
}

OboukhovPlayer::~OboukhovPlayer() {}

void OboukhovPlayer::openFile()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        "Open Media",
        QString(),
        "Media Files (*.mp4 *.mkv *.avi *.mov *.mp3 *.wav)"
    );

    if (!file.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(file));
        player->play();
        ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
}

void OboukhovPlayer::playPause()
{
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
    else {
        player->play();
        ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
}

void OboukhovPlayer::stop()
{
    player->stop();
    ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void OboukhovPlayer::positionChanged(qint64 position)
{
    ui.positionSlider->setValue(position);
    ui.timeLabel->setText(
        formatTime(position) + " / " +
        formatTime(player->duration())
    );
}

void OboukhovPlayer::durationChanged(qint64 duration)
{
    ui.positionSlider->setRange(0, duration);
}

QString OboukhovPlayer::formatTime(qint64 ms)
{
    int seconds = (ms / 1000) % 60;
    int minutes = (ms / 60000) % 60;
    int hours = ms / 3600000;

    if (hours > 0) {
        return QString("%1:%2:%3")
            .arg(hours)
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
    }

    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

bool OboukhovPlayer::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui.videoWidget && event->type() == QEvent::MouseButtonPress) {
        if (!fullscreen) {
            ui.videoWidget->setFullScreen(true);
            fullscreen = true;
        }
        else {
            ui.videoWidget->setFullScreen(false);
            fullscreen = false;
        }
        return true; // event handled
    }
    return QMainWindow::eventFilter(watched, event);
}
