#include "HelpWidget.h"

HelpWidget::HelpWidget(QWidget *parent) :
    QWidget(parent)
{
    this->manual = tr("<h2>MTC Olive Dialer</h2>"
                      "<h3>Install software</h3>"
                      "<p>The installation software has been written for the modem V-ME200. When you plug the modem into the PC or laptop, it will automatically install it as the prompts. Please check the following steps under XP operation system as an example.</p>"
                      "<ol><li>Connect device with PC.</li>"
                      "<li>If PC opens the auto run function, it will pop up an installation interface. If not, please go to \"My Computer\", find the new CD-ROM, open it and double click the \"AutoRun.exe\" file.</li>"
                      "<li>Install it according to the Wizard information step by step. </li></ol>"
                      "<h3>Uninstall software</h3>"
                      "<p>If you want to uninstall the software, Go to \"Add or delete program\" in Control Panel to uninstall the software. Select Uninstall and follow the Wizard information.</p>"
                      "<h3>Usage</h3>"
                      "<p>Using this Dialer, you can enter the corresponding function modules through each button or menu in the main interface. Same like as below: </p>"
                      "<p><u>Connect</u>: Press Connect, the software will create a wireless network connection automatically. </p>"
                      "<p><u>Disconnect</u>: Press Disconnect, the software will disconnect connection automatically. </p>"
                      "</p><u>Setting</u>: Press Setting, the software will create a Setting window and you will change setting of dialer automatically. </p>");

    this->content = new QTextEdit(this);
    this->content->setReadOnly (true);
    this->content->setHtml (this->manual);

    this->ok = new ImageButton(tr("OK"), ":/smallButtonDefault.png", ":/smallButtonHover.png", ":/smallButtonPress.png", "", this);
    this->ok->setFixedWidth (80);
    this->ok->setFixedHeight (21);
    QObject::connect (this->ok, SIGNAL(clicked()), SLOT(onOkClicked()));

    this->cancel = new ImageButton(tr("Cancel"), ":/smallButtonDefault.png", ":/smallButtonHover.png", ":/smallButtonPress.png", "", this);
    this->cancel->setFixedWidth (80);
    this->cancel->setFixedHeight (21);
    QObject::connect (this->cancel, SIGNAL(clicked()), SLOT(onCancelClicked()));

    this->buttons = new QVBoxLayout;
    this->buttons->addWidget (this->ok);
    this->buttons->addWidget (this->cancel);

    this->layout = new QHBoxLayout;
    this->layout->addWidget (this->content);
    this->layout->addLayout (this->buttons);

    this->setLayout (this->layout);

}

bool HelpWidget::onOkClicked () {

    emit dismissAction ();
    return true;
}

bool HelpWidget::onCancelClicked () {

    emit dismissAction ();
    return true;
}

bool HelpWidget::onRetranslate(){

    this->ok->setText (tr("OK"));
    this->cancel->setText (tr("Cancel"));

    this->manual = tr("<h2>MTC Olive Dialer</h2>"
                      "<h3>Install software</h3>"
                      "<p>The installation software has been written for the modem V-ME200. When you plug the modem into the PC or laptop, it will automatically install it as the prompts. Please check the following steps under XP operation system as an example.</p>"
                      "<ol><li>Connect device with PC.</li>"
                      "<li>If PC opens the auto run function, it will pop up an installation interface. If not, please go to \"My Computer\", find the new CD-ROM, open it and double click the \"AutoRun.exe\" file.</li>"
                      "<li>Install it according to the Wizard information step by step. </li></ol>"
                      "<h3>Uninstall software</h3>"
                      "<p>If you want to uninstall the software, Go to \"Add or delete program\" in Control Panel to uninstall the software. Select Uninstall and follow the Wizard information.</p>"
                      "<h3>Usage</h3>"
                      "<p>Using this Dialer, you can enter the corresponding function modules through each button or menu in the main interface. Same like as below: </p>"
                      "<p><u>Connect</u>: Press Connect, the software will create a wireless network connection automatically. </p>"
                      "<p><u>Disconnect</u>: Press Disconnect, the software will disconnect connection automatically. </p>"
                      "</p><u>Setting</u>: Press Setting, the software will create a Setting window and you will change setting of dialer automatically. </p>");

    this->content->setHtml (this->manual);

    return true;
}
