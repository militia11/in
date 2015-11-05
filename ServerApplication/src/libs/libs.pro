TEMPLATE = subdirs

SUBDIRS += \
    controllers \
    dao \
    ui

testssupport.depends += controllers
#ui.depends += controllers
