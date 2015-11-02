TEMPLATE = subdirs

SUBDIRS += \
    ui \
	clientcontrollers \
    dao \
    testssupport

clientcontrollers.depends += dao
testssupport.depends += clientcontrollers
