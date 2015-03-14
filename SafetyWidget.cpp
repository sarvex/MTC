#include "Define.h"
#include "SafetyWidget.h"

SafetyWidget::SafetyWidget(QWidget *parent) :
    QWidget(parent)
{
    this->pinSettingLabel = new QLabel (tr ("PIN Settings"), this);
    this->pinSettingLabel->setGeometry (70, 53, 100, 20);

    this->pinSetting = new QComboBox(this);
    this->pinSetting->addItem (tr ("Block PIN"));
    this->pinSetting->addItem (tr ("Change PIN"));
    this->pinSetting->setGeometry (194, 53, 125, 20);

    this->pinLock = new QLabel (tr("PIN Lock"), this);
    this->pinLock->setGeometry (20, 20, 100, 20);

    this->pinCode = new QLabel (tr("PIN Code"), this);
    this->pinCode->setGeometry (20, 55, 100, 20);

    this->pinCodeLineEdit = new QLineEdit (this);
    this->pinCodeLineEdit->setGeometry (150, 55, 140, 20);
    this->pinCodeLineEdit->setEchoMode (QLineEdit::Password);
    this->pinCodeLineEdit->setMaxLength (LOCK_LENGTH);

    this->onPinLock = new QRadioButton(tr("On"), this);
    this->onPinLock->setGeometry (150, 20, 80, 20);

    this->offPinLock = new QRadioButton(tr("Off"), this);
    this->offPinLock->setGeometry (230, 20, 80, 20);
    this->offPinLock->setChecked (true);

    this->existingLabel = new QLabel (tr("Existing PIN"), this);
    this->existingLabel->setGeometry (20, 20, 100, 20);

    this->existing = new QLineEdit(this);
    this->existing->setEchoMode (QLineEdit::Password);
    this->existing->setMaxLength (LOCK_LENGTH);
    this->existing->setGeometry (150, 20, 150, 20);

    this->lockLabel = new QLabel (tr("New PIN"), this);
    this->lockLabel->setGeometry (20, 40, 100, 20);

    this->lock = new QLineEdit(this);
    this->lock->setEchoMode (QLineEdit::Password);
    this->lock->setMaxLength (LOCK_LENGTH);
    this->lock->setGeometry (150, 40, 150, 20);

    this->confirmLabel = new QLabel (tr("Confirm PIN"), this);
    this->confirmLabel->setGeometry (20, 60, 100, 20);

    this->confirm = new QLineEdit(this);
    this->confirm->setEchoMode (QLineEdit::Password);
    this->confirm->setMaxLength (LOCK_LENGTH);
    this->confirm->setGeometry (150, 60, 150, 20);

    this->saveChangePin = new ImageButton(tr("Save"),
                                          ":/smallButtonDefault.png",
                                          ":/smallButtonHover.png",
                                          ":/smallButtonPress.png",
                                          false, this);
    this->saveChangePin->setGeometry (345, 29, 80, 21);


    this->ok = new ImageButton(tr("OK"),
                               ":/smallButtonDefault.png",
                               ":/smallButtonHover.png",
                               ":/smallButtonPress.png",
                               false, this);
    this->ok->setGeometry (345, 29, 80, 21);

    this->securityCancel = new ImageButton(tr("Cancel"),
                                           ":/smallButtonDefault.png",
                                           ":/smallButtonHover.png",
                                           ":/smallButtonPress.png",
                                           false, this);
    this->securityCancel->setGeometry (345, 76, 80, 21);

    this->save = new ImageButton(tr("Save"),
                                 ":/smallButtonDefault.png",
                                 ":/smallButtonHover.png",
                                 ":/smallButtonPress.png",
                                 false, this);
    this->save->setGeometry (345, 29, 80, 21);


    this->cancel = new ImageButton(tr("Cancel"),
                                   ":/smallButtonDefault.png",
                                   ":/smallButtonHover.png",
                                   ":/smallButtonPress.png",
                                   false, this);
    this->cancel->setGeometry (345, 76, 80, 21);


    QObject::connect (this->ok,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onOkClicked()));

    QObject::connect (this->securityCancel,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onSecurityCancelClicked()));

    QObject::connect (this->save,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onSaveClicked()));

    QObject::connect (this->cancel,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onCancelClicked()));

    QObject::connect (this->saveChangePin,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onSaveChangePinClicked()));
}

void
SafetyWidget::showEvent (
        QShowEvent* event)
{
     Q_UNUSED (event)

    this->pinSettingLabel->setVisible (true);
    this->pinSetting->setVisible (true);
    this->ok->setVisible (true);
    this->securityCancel->setVisible (true);

    this->pinLock->setVisible (false);
    this->pinCode->setVisible (false);
    this->pinCodeLineEdit->setVisible (false);
    this->offPinLock->setVisible (false);
    this->existingLabel->setVisible (false);
    this->existing->setVisible (false);
    this->lockLabel->setVisible (false);
    this->lock->setVisible (false);
    this->confirmLabel->setVisible (false);
    this->confirm->setVisible (false);
    this->saveChangePin->setVisible (false);
    this->save->setVisible (false);
    this->cancel->setVisible (false);
    this->onPinLock->setVisible (false);

}

bool SafetyWidget::onOkClicked () {

    this->pinSettingLabel->setVisible (false);
    this->pinSetting->setVisible (false);
    this->ok->setVisible (false);
    this->securityCancel->setVisible (false);

    if( 0 == this->pinSetting->currentIndex ())
    {
        this->pinLock->setVisible (true);
        this->pinCode->setVisible (true);
        this->pinCodeLineEdit->setVisible (true);
        this->save->setVisible (true);
        this->cancel->setVisible (true);
        this->onPinLock->setVisible (true);
        this->offPinLock->setVisible (true);
    }

    else
    {
        this->existingLabel->setVisible (true);
        this->existing->setVisible (true);
        this->lockLabel->setVisible (true);
        this->lock->setVisible (true);
        this->confirmLabel->setVisible (true);
        this->confirm->setVisible (true);
        this->cancel->setVisible (true);
        this->saveChangePin->setVisible (true);
    }


    return true;
}


bool
SafetyWidget::onSaveClicked
()
{
    emit dismissAction ();

    return true;
}

bool
SafetyWidget::onSaveChangePinClicked
()
{
    return true;
}

bool
SafetyWidget::onCancelClicked
()
{
    this->pinSettingLabel->setVisible (true);
    this->pinSetting->setVisible (true);
    this->ok->setVisible (true);
    this->securityCancel->setVisible (true);

    this->existingLabel->setVisible (false);
    this->existing->setVisible (false);
    this->lockLabel->setVisible (false);
    this->lock->setVisible (false);
    this->confirmLabel->setVisible (false);
    this->confirm->setVisible (false);
    this->cancel->setVisible (false);
    this->pinLock->setVisible (false);
    this->pinCode->setVisible (false);
    this->pinCodeLineEdit->setVisible (false);
    this->save->setVisible (false);
    this->onPinLock->setVisible (false);
    this->offPinLock->setVisible (false);
    this->saveChangePin->setVisible (false);

    return true;
}

bool SafetyWidget::onSecurityCancelClicked(){

    emit dismissAction ();
    return true;
}

bool SafetyWidget::onRetranslate (){

    this->pinSettingLabel->setText (tr("PIN Settings"));
    this->pinLock->setText (tr("PIN Lock"));
    this->pinCode->setText (tr("PIN Code"));
    this->onPinLock->setText (tr("On"));
    this->offPinLock->setText (tr("Off"));
    this->existingLabel->setText (tr("Existing PIN"));
    this->lockLabel->setText (tr("New PIN"));
    this->confirmLabel->setText (tr("Confirm PIN"));
    this->saveChangePin->setText (tr("Save"));
    this->ok->setText (tr("OK"));
    this->securityCancel->setText (tr("Cancel"));
    this->save->setText (tr("Save"));
    this->cancel->setText (tr("Cancel"));

    this->pinSetting->setItemText (0,tr("Block PIN"));
    this->pinSetting->setItemText (1,tr("Change PIN"));

    return true;

}
