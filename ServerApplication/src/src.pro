TEMPLATE = subdirs

SUBDIRS += \
    libs \
    app

app.depends += libs
