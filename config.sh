#!/bin/bash

source ./APKBUILD

PROJECT_DIR=app

# pmbootstrap
PMBOOTSTRAP_DIR="$HOME/.local/var/pmbootstrap"
CHANNEL=edge

# apk binary settings
APK_NAME="$pkgname-${pkgver}-r${pkgrel}.apk"
APK_PATH="$PMBOOTSTRAP_DIR/packages/$CHANNEL/$arch/$APK_NAME"

# SSH sideload settings
SSH_USER=user
SSH_HOST=192.168.1.123
SSH_PORT=22

DIR_SIDELOAD="/home/$SSH_USER"