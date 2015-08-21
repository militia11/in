TEMPLATE = subdirs

SUBDIRS += \
    src \
    tests \
    share

tests.depends += src
