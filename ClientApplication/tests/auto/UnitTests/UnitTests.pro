TEMPLATE = subdirs

SUBDIRS += \
    ClientTests \
    RunUnitTests \
    testlib

ClientTests.depends += testlib
