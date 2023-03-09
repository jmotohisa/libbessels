#!/bin/sh

mkdir -p m4

autoreconf --verbose --install --symlink --force
autoreconf --verbose --install --symlink --force
autoreconf --verbose --install --symlink --force

./configure "$@"
