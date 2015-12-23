TEMPLATE = subdirs

SUBDIRS += \
    ServerTests \
    ReceiverTests \
    StorePhotoTests \
    ChecksumTests \
    CReceiverFactoryTests \
    GetSettingsTests \
    testlibs \
    RunUnitTests \
    ValidatorTests \
    SynchronizerTests

ServerTests.depends += testlibs
ReceiverTests.depends += testlibs
CReceiverFactoryTests.depends += testlibs
