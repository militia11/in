TEMPLATE = subdirs

SUBDIRS += \
    ClientTests \
    RunUnitTests \
    testlib \
    RepositoryTests

ClientTests.depends += testlib
