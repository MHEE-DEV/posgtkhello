#!/bin/bash

source "./config.sh"

release=false

for arg in "$@"; do
    if [[ "$arg" == "--release" ]]; then
        release=true
        break
    fi
done

if $release; then
  pmbootstrap checksum $pkgname
  tar czf $source app
  pmbootstrap build $pkgname --force
else
    cmake -S app -B build
    cmake --build build
fi