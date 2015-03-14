#include "DeamonNetwork.h"

DeamonNetwork::DeamonNetwork(QObject * parent) : QObject(parent) {
}

DeamonNetwork* DeamonNetwork::singleton = NULL;

DeamonNetwork* DeamonNetwork::getInstance () {
    if (NULL == singleton) {
        singleton = new DeamonNetwork();
    }
    return (singleton);
}
