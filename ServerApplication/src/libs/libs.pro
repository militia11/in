TEMPLATE = subdirs

SUBDIRS += \
    controllers \
    dao \
    ui \
    testssupport

testssupport.depends += controllers
#ui.depends += controllers
