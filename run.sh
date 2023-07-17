#!/bin/bash

make bin/app
alacritty -e make execute &
