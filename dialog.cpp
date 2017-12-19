#include "dialog.h"
#include "ui_dialog.h"
#include<QFileDialog>
#include<QMessageBox>
dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&dialog::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&dialog::on_durationChanged);

}

dialog::~dialog()
{
    delete ui;
}


QString FileName;
void dialog::on_actionOpen_triggered()
{
    FileName=QFileDialog::getOpenFileName(this,tr("Music library"),"fileL://home/","All files(*.*);;Music file(*.mp3)");
    player->setMedia(QUrl::fromLocalFile(FileName));
    player->play();
    qDebug()<<player->errorString();
}

void dialog::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);

}

void dialog::on_VolumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}

void dialog::on_durationChanged(qint64 position)
{
    ui->horizontalSlider->setMaximum(position);
}
void dialog::on_positionChanged(qint64 position)
{
    ui->horizontalSlider->setValue(position);
}

void dialog::on_pushButton_clicked()
{
    ui->pushButton->setToolTip(tr("Mute"));
    player->setVolume(0);
}

void dialog::on_pushButton_2_clicked()
{
    ui->pushButton_2->setToolTip(tr("Start"));
    player->setMedia(QUrl::fromLocalFile(FileName));
    player->play();
    qDebug()<<player->errorString();
}

void dialog::on_pushButton_3_clicked()
{
    ui->pushButton_3->setToolTip(tr("Stop"));
     player->pause();
}

void dialog::on_actionExit_triggered()
{
    this->close();
}
