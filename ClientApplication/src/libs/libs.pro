TEMPLATE = subdirs

SUBDIRS += \
    ui \
    controllers \
    dao \
    testssupport

controllers.depends += dao
testssupport.depends += controllers
