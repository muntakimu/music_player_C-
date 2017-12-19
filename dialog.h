#ifndef DIALOG_H
#define DIALOG_H
#include <QMainWindow>
#include<QMediaPlayer>
#include<QDebug>

namespace Ui {
class dialog;
}

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

private slots:

    void on_actionOpen_triggered();
    void on_positionChanged(qint64 position);
    void on_durationChanged(qint64 position);
    void on_horizontalSlider_sliderMoved(int position);

    void on_VolumeSlider_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionExit_triggered();

private:
    Ui::dialog *ui;
    QMediaPlayer* player;
};

#endif // DIALOG_H
