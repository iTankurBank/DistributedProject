#include "allusers.h"
#include "ui_allusers.h"
#include "peer.h"
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include "profile.h"

AllUsers::AllUsers(QWidget *parent, Peer *peer) :
    QDialog(parent),
    ui(new Ui::AllUsers),
    peer(peer)
{
    ui->setupUi(this);
    ui->lbl_time->setText(
        QString::fromStdString("Last Time Refreshed: " + peer->getCurrentTime()));
    //ui->lbl_time->setStyleSheet("QLabel { color : white; }");
    ui->lbl_result->setVisible(false);

    int resultUsers = peer->getUsers();
    if(resultUsers == 1){
    int i = 0;
    for (peer->it = peer->users.begin(); peer->it != peer->users.end();
         peer->it++) {
      if (peer->username != peer->it->first) {
        if (peer->it->second[0].at((0)) == '1') {
          ui->listWidget->addItem(QString::fromStdString(peer->it->first));
          ui->listWidget->item(i)->setTextColor(Qt::green);
        } else {
          ui->listWidget->addItem(QString::fromStdString(peer->it->first));
          ui->listWidget->item(i)->setTextColor(Qt::red);
        }
        i = i + 1;
      }
    }
  }
  else if(resultUsers == 2){
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("DoS Offline!");
  }
  else if(resultUsers == 0){
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("Check your internet connection!"); // Getusers send failed!
  }
  else{
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("Check your internet connection!");
  }
}



AllUsers::~AllUsers()
{
    delete ui;
}

void AllUsers::on_push_back_clicked()
{
    this->hide();
    Profile profile (this,peer);
    profile.setModal(true);
    profile.exec();
}
/*
void AllUsers::on_push_view_clicked()
{
    if (ui->listWidget->currentRow() >= 0) {
        int resultUsers = peer->getUsers();
        if(resultUsers == 1){
      if (peer->users[ui->listWidget->currentItem()->text().toStdString()][0] == "0") { //  ->textColor() == Qt::red
          ui->listWidget->currentItem()->textColor() = Qt::red; // set red if not already
          ui->lbl_result->setVisible(true);
        ui->lbl_result->setStyleSheet("QLabel { color : red; }");
      } else {
        ui->lbl_result->setVisible(false);
        const QString &s = ui->listWidget->currentItem()->text();
        secdia = new userimagesdialog(this, peer, s); // if want to distroy secdia
                                                      // with the main, put (this)
        secdia->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                               Qt::CustomizeWindowHint);
        secdia->show();
      }
        }
        else if(resultUsers == 2){
          ui->lbl_result->setVisible(true);
          ui->lbl_result->setStyleSheet("QLabel { color : red; }");
          ui->lbl_result->setText("DoS Offline!");
        }
        else if(resultUsers == 0){
          ui->lbl_result->setVisible(true);
          ui->lbl_result->setStyleSheet("QLabel { color : red; }");
          ui->lbl_result->setText("Check your internet connection!"); // Getusers send failed!
        }
        else{
          ui->lbl_result->setVisible(true);
          ui->lbl_result->setStyleSheet("QLabel { color : red; }");
          ui->lbl_result->setText("Check your internet connection!");
        }


    } else {
      ui->lbl_result->setVisible(true);
      ui->lbl_result->setStyleSheet("QLabel { color : red; }");
      ui->lbl_result->setText("Please, select a user!");
    }
}

void AllUsers::on_push_refresh_clicked()
{
    ui->listWidget->clear();
    ui->lbl_result->setVisible(false);
    ui->lbl_time->setText(
        QString::fromStdString("Last Time Refreshed: " + peer->getCurrentTime()));
    ui->lbl_time->setStyleSheet("QLabel { color : white; }");
    int resultUsers = peer->getUsers();
    if(resultUsers == 1){
    int i = 0;
    for (peer->it = peer->users.begin(); peer->it != peer->users.end();
         peer->it++) {
      if (peer->username != peer->it->first) {
        if (peer->it->second[0].at((0)) == '1') {
          ui->listWidget->addItem(QString::fromStdString(peer->it->first));
          ui->listWidget->item(i)->setTextColor(Qt::green);
        } else {
          ui->listWidget->addItem(QString::fromStdString(peer->it->first));
          ui->listWidget->item(i)->setTextColor(Qt::red);
        }
        i = i + 1;
      }
    }
  }
  else if(resultUsers == 2){
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("DoS Offline!");
  }
  else if(resultUsers == 0){
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("Check your internet connection!"); // Getusers send failed!
  }
  else{
    ui->lbl_result->setVisible(true);
    ui->lbl_result->setStyleSheet("QLabel { color : red; }");
    ui->lbl_result->setText("Check your internet connection!");
  }
}
*/
