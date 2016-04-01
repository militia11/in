TEMPLATE = subdirs

SUBDIRS += \
    src \
    tests \
    share

src.depends += share
tests.depends += src share

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/src/app/android-sources
