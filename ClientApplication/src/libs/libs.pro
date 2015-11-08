TEMPLATE = subdirs

SUBDIRS += \
    ui \
	controllers \
    dao

controllers.depends += dao
testssupport.depends += controllers
