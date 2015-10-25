TEMPLATE = subdirs

SUBDIRS += \
    src \
    tests \
    share

src.depends += share
tests.depends += src share

