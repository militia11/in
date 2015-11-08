TEMPLATE = subdirs

SUBDIRS += \
    ServerTests \
    ReceiverTests \
    TestStorePhoto \
    ChecksumTests \
    CReceiverFactoryTests \
    GetSettingsTests \
    testlibs

ServerTests.depends += testlibs
ReceiverTests.depends += testlibs
CReceiverFactoryTests.depends += testlibs
