TEMPLATE = subdirs

SUBDIRS += \
    ServerTests \
    ReceiverTests \
    StorePhotoTests \
    ChecksumTests \
    CReceiverFactoryTests \
    GetSettingsTests \
    testlibs \
    RunUnitTests

ServerTests.depends += testlibs
ReceiverTests.depends += testlibs
CReceiverFactoryTests.depends += testlibs
