TEMPLATE = subdirs

SUBDIRS += \
    ServerApplication \
    ClientApplication

ServerApplication.depends += ClientApplication
