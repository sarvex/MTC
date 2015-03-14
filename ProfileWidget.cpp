#include "DeamonSetting.h"
#include "ProfileWidget.h"

ProfileWidget::ProfileWidget
(QWidget *parent) :
    QWidget(parent)
{
    this->usernameLabel = new QLabel (tr ("Username"));
    this->usernameLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->username = new QLineEdit (DeamonSetting::getInstance ()
                                    ->getUsername ());
    this->username->setAlignment (Qt::AlignBottom);

    this->passwordLabel = new QLabel (tr ("Password"));
    this->passwordLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->password = new QLineEdit (DeamonSetting::getInstance ()
                                    ->getPassword ());
    this->password->setAlignment (Qt::AlignBottom);

    this->numberLabel = new QLabel (tr ("Number"));
    this->numberLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->number = new QLineEdit (DeamonSetting::getInstance ()
                                  ->getNumber ());
    this->number->setAlignment (Qt::AlignBottom);

    this->grid = new QGridLayout;
    this->grid->setContentsMargins (20, 0, 20, 0);

    this->grid->addWidget (this->usernameLabel, 0, 0);
    this->grid->addWidget (this->username, 0, 1);

    this->grid->addWidget (this->passwordLabel, 1, 0);
    this->grid->addWidget (this->password, 1, 1);

    this->grid->addWidget (this->numberLabel, 2, 0);
    this->grid->addWidget (this->number, 2, 1);

    this->save = new ImageButton(tr("Save"),
                                 ":/smallButtonDefault.png",
                                 ":/smallButtonHover.png",
                                 ":/smallButtonPress.png",
                                 false, this);
    this->save->setFixedWidth (80);
    this->save->setFixedHeight (21);


    this->cancel = new ImageButton(tr("Cancel"),
                                   ":/smallButtonDefault.png",
                                   ":/smallButtonHover.png",
                                   ":/smallButtonPress.png",
                                   false, this);
    this->cancel->setFixedWidth (80);
    this->cancel->setFixedHeight (21);

    this->buttons = new QVBoxLayout;
    this->buttons->addWidget (this->save);
    this->buttons->addWidget (this->cancel);

    this->layout = new QHBoxLayout;
    this->layout->addLayout (this->grid);
    this->layout->addLayout (this->buttons);

    this->setLayout (this->layout);

    QObject::connect (this->save,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onSaveClicked()));

    QObject::connect (this->cancel,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onCancelClicked()));
}

bool ProfileWidget::onSaveClicked(){

    DeamonSetting::getInstance ()->setUsername (this->username->text ());
    DeamonSetting::getInstance ()->setPassword (this->password->text ());
    DeamonSetting::getInstance ()->setNumber (this->number->text ());

    emit dismissAction ();
    return true;
}

bool ProfileWidget::onCancelClicked(){

    emit dismissAction ();
    return true;
}

bool ProfileWidget::onRetranslate(){

    this->usernameLabel->setText (tr("Username"));
    this->passwordLabel->setText (tr("Password"));
    this->numberLabel->setText (tr("Number"));
    this->save->setText (tr("Save"));
    this->cancel->setText (tr("Cancel"));

    return true;
}

