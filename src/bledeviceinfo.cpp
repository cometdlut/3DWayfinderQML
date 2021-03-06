#include <qbluetoothuuid.h>

#include "bledeviceinfo.h"

BLEDeviceInfo::BLEDeviceInfo()
{
}

BLEDeviceInfo::BLEDeviceInfo(const QBluetoothDeviceInfo &d)
{
    device = d;
}

QString BLEDeviceInfo::getAddress() const
{
#ifdef Q_OS_MAC
    // On OS X and iOS we do not have addresses,
    // only unique UUIDs generated by Core Bluetooth.
    return device.deviceUuid().toString();
#else
    return device.address().toString();
#endif
}

QString BLEDeviceInfo::getName() const
{
    return device.name();
}

QBluetoothDeviceInfo BLEDeviceInfo::getDevice()
{
    return device;
}

void BLEDeviceInfo::setDevice(const QBluetoothDeviceInfo &dev)
{
    device = QBluetoothDeviceInfo(dev);
    Q_EMIT deviceChanged();
}
