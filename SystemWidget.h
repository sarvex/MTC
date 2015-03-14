#ifndef SYSTEMWIDGET_H
#define SYSTEMWIDGET_H

#include "ImageButton.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class SystemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SystemWidget(QWidget *parent = 0);

signals:
    bool languageChange (QString language);
    bool dismissAction ();

public slots:
    bool onSoftwareVersionUpdate (QString value);
    bool onPrlUpdate (QString value);
    bool onMeidUpdate (QString value);
    bool onEsnUpdate (QString value);

    bool onOkClicked();
    bool onCancelClicked();

    bool onRetranslate();

protected:
    void showEvent(QShowEvent* event);

private:

    QLabel * deviceLabel;
    QLabel * hardwareLabel;
    QLabel * softwareLabel;
    QLabel * dialerVersionLabel;
    QLabel * prlLabel;
    QLabel * meidLabel;
    QLabel * esnLabel;

    QLineEdit * device;
    QLineEdit * hardware;
    QLineEdit * software;
    QLineEdit * dialerVersion;
    QLineEdit * prl;
    QLineEdit * meid;
    QLineEdit * esn;

    QGridLayout * grid;
    QVBoxLayout * buttons;
    QHBoxLayout * layout;

    ImageButton * ok;
    ImageButton * cancel;
};

#endif // SYSTEMWIDGET_H
