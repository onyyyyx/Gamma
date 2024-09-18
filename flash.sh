#!/bin/bash
clear
make cleanall
clear
make THEME_NAME=gamma_dark OMEGA_USERNAME="Onyx" -j4
clear
make epsilon.B_flash
