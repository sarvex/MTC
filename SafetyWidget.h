#ifndef SAFETYWIDGET_H
#define SAFETYWIDGET_H

#include "ImageButton.h"

#include <QRadioButton>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>

class SafetyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SafetyWidget(QWidget *parent = 0);

signals:
    bool languageChange (QString language);
    bool dismissAction ();

public slots:
    bool onSaveClicked();
    bool onCancelClicked();

    bool onOkClicked();
    bool onSaveChangePinClicked();
    bool onSecurityCancelClicked();

    bool onRetranslate ();

protected:
    virtual void showEvent (QShowEvent* event);

private:
    QLabel * pinLock;
    QLabel * pinCode;
    QLabel * pinSettingLabel;

    ImageButton * save;
    ImageButton * saveChangePin;
    ImageButton * ok;
    ImageButton * cancel;
    ImageButton * securityCancel;

    QLineEdit * pinCodeLineEdit;

    QRadioButton * onPinLock;
    QRadioButton * offPinLock;

    QComboBox * pinSetting;

    QLineEdit * existing;
    QLineEdit * lock;
    QLineEdit * confirm;

    QLabel * existingLabel;
    QLabel * lockLabel;
    QLabel * confirmLabel;


};

#endif // SAFETYWIDGET_H
