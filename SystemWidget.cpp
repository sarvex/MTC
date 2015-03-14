#include "At.h"
#include "Define.h"
#include "DeamonPort.h"
#include "DeamonSetting.h"
#include "SystemWidget.h"

#include <QDebug>

SystemWidget::SystemWidget(QWidget *parent) :
    QWidget(parent)
{
    this->deviceLabel = new QLabel (tr("Device"));
    this->deviceLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->device = new QLineEdit (tr (MODEM_DEVICE));
    this->device->setAlignment (Qt::AlignBottom);
    this->device->setPlaceholderText (tr("Updating..."));
    this->device->setReadOnly (true);

    this->hardwareLabel = new QLabel (tr("Hardware"));
    this->hardwareLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->hardware = new QLineEdit (tr (MODEM_HARDWARE));
    this->hardware->setAlignment (Qt::AlignBottom);
    this->hardware->setPlaceholderText (tr("Updating..."));
    this->hardware->setReadOnly (true);

    this->softwareLabel = new QLabel (tr("Software"));
    this->softwareLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->software = new QLineEdit;
    this->software->setAlignment (Qt::AlignBottom);
    this->software->setPlaceholderText (tr("Updating..."));
    this->software->setReadOnly (true);

    this->dialerVersionLabel = new QLabel (tr("Dialer Version"));
    this->dialerVersionLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->dialerVersion = new QLineEdit (tr (MODEM_DIALER_VERSION));
    this->dialerVersion->setAlignment (Qt::AlignBottom);
    this->dialerVersion->setPlaceholderText (tr("Updating..."));
    this->dialerVersion->setReadOnly (true);

    this->prlLabel = new QLabel (tr("PRL"));
    this->prlLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->prl = new QLineEdit;
    this->prl->setAlignment (Qt::AlignBottom);
    this->prl->setPlaceholderText (tr("Updating..."));
    this->prl->setReadOnly (true);

    this->meidLabel = new QLabel (tr("MEID"));
    this->meidLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->meid = new QLineEdit;
    this->meid->setAlignment (Qt::AlignBottom);
    this->meid->setPlaceholderText (tr("Updating..."));
    this->meid->setReadOnly (true);

    this->esnLabel = new QLabel (tr("ESN"));
    this->esnLabel->setAlignment (Qt::AlignRight | Qt::AlignBottom);
    this->esn = new QLineEdit;
    this->esn->setAlignment (Qt::AlignBottom);
    this->esn->setPlaceholderText (tr("Updating..."));
    this->esn->setReadOnly (true);

    this->grid = new QGridLayout();
    this->grid->setContentsMargins (0, 0, 0, 0);

    this->grid->addWidget (this->deviceLabel, 0, 0);
    this->grid->addWidget (this->device, 0, 1);

    this->grid->addWidget (this->hardwareLabel, 0, 2);
    this->grid->addWidget (this->hardware, 0, 3);

    this->grid->addWidget (this->esnLabel, 1, 0);
    this->grid->addWidget (this->esn, 1, 1);

    this->grid->addWidget (this->dialerVersionLabel, 1, 2);
    this->grid->addWidget (this->dialerVersion, 1, 3);

    this->grid->addWidget (this->prlLabel, 2, 0);
    this->grid->addWidget (this->prl, 2, 1);

    this->grid->addWidget (this->meidLabel, 2, 2);
    this->grid->addWidget (this->meid, 2, 3);

    this->grid->addWidget (this->softwareLabel, 3, 0, 1, 1);
    this->grid->addWidget (this->software, 3, 1, 1, 3);

    this->ok = new ImageButton (tr("OK"),
                                ":/smallButtonDefault.png",
                                ":/smallButtonHover.png",
                                ":/smallButtonPress.png",
                                false, this);
    this->ok->setFixedWidth (80);
    this->ok->setFixedHeight (21);

    this->cancel = new ImageButton (tr("Cancel"),
                                    ":/smallButtonDefault.png",
                                    ":/smallButtonHover.png",
                                    ":/smallButtonPress.png",
                                    false, this);
    this->cancel->setFixedWidth (80);
    this->cancel->setFixedHeight (21);

    this->buttons = new QVBoxLayout;
    this->buttons->addWidget (this->ok);
    this->buttons->addWidget (this->cancel);

    this->layout = new QHBoxLayout;
    this->layout->addLayout (this->grid);
    this->layout->addLayout (this->buttons);

    this->setLayout (this->layout);

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(softwareVersionUpdate(QString)),
                      this,
                      SLOT(onSoftwareVersionUpdate(QString)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(prlUpdate(QString)),
                      this,
                      SLOT(onPrlUpdate(QString)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(meidUpdate(QString)),
                      this,
                      SLOT(onMeidUpdate(QString)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(esnUpdate(QString)),
                      this,
                      SLOT(onEsnUpdate(QString)));

    QObject::connect (this->ok,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onOkClicked()));

    QObject::connect (this->cancel,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onCancelClicked()));

}

void SystemWidget::showEvent (QShowEvent* event) {
    DeamonPort::getInstance ()->writeToAtPort (At::softwareVersion);
    DeamonPort::getInstance ()->writeToAtPort (At::prl);
    DeamonPort::getInstance ()->writeToAtPort (At::meid);
    DeamonPort::getInstance ()->writeToAtPort (At::esn);

    QWidget::showEvent (event);
}

bool
SystemWidget::onRetranslate ()
{
    this->deviceLabel->setText (tr("Device"));
    this->device->setPlaceholderText (tr("Updating..."));

    this->hardwareLabel->setText (tr("Hardware"));
    this->hardware->setPlaceholderText (tr("Updating..."));

    this->softwareLabel->setText (tr("Software"));
    this->software->setPlaceholderText (tr("Updating..."));

    this->dialerVersionLabel->setText (tr("Dialer Version"));
    this->dialerVersion->setPlaceholderText (tr("Updating..."));

    this->prlLabel->setText (tr("PRL"));
    this->prl->setPlaceholderText (tr("Updating..."));

    this->meidLabel->setText (tr("MEID"));
    this->meid->setPlaceholderText (tr("Updating..."));

    this->esnLabel->setText (tr("ESN"));
    this->esn->setPlaceholderText (tr("Updating..."));

    return true;
}


bool
SystemWidget::onSoftwareVersionUpdate
(QString value)
{
    this->software->setText (value);

    return true;
}

bool
SystemWidget::onPrlUpdate
(QString value)
{
    this->prl->setText (value);

    return true;
}

bool
SystemWidget::onMeidUpdate
(QString value)
{
    this->meid->setText (value);

    return true;
}

bool
SystemWidget::onEsnUpdate
(QString value)
{
    this->esn->setText (value);

    return true;
}

bool
SystemWidget::onOkClicked
()
{
    emit dismissAction ();
    return true;
}

bool
SystemWidget::onCancelClicked
()
{

    emit dismissAction ();
    return true;
}
