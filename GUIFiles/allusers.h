#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QDialog>
#include <string>
#include <QtDebug>
#include <QList>
#include <QLabel>
#include <QSizePolicy>
#include "peer.h"


namespace Ui {
class AllUsers;
}

class AllUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AllUsers(QWidget *parent = nullptr, Peer *peer = nullptr);
    ~AllUsers();
    void showUsers();

private:
    Ui::AllUsers *ui;
    Peer *peer;
};

#endif // ALLUSERS_H
