#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include "ImageButton.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class ProfileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileWidget(QWidget *parent = 0);

signals:
    bool languageChange (QString language);
    bool dismissAction ();

public slots:
    bool onSaveClicked();
    bool onCancelClicked();

    bool onRetranslate();

private:
    QLineEdit * username;
    QLineEdit * password;
    QLineEdit * number;

    QLabel * usernameLabel;
    QLabel * passwordLabel;
    QLabel * numberLabel;

    ImageButton * save;
    ImageButton * cancel;

    QGridLayout * grid;
    QVBoxLayout * buttons;
    QHBoxLayout * layout;
};

#endif // PROFILEWIDGET_H
