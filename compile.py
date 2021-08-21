from colorama import init, Fore, Back, Style
import sys
import os
import glob
import arrow
import argparse

parser = argparse.ArgumentParser()

parser.add_argument('Clean', '-c', metavar='clean', help='Cleans the build tree.')
parser.add_argument('Build', '-b', metavar='build', help='Builds the program tree.')
args = parser.parse_args()

PWD = os.getcwd()


LOG_DIR = '/build/build_logs'

SRC_DIR = "/src"
BIN_DIR = "/build/bin"
OBJ_DIR = "/build/obj"
INC_DIR = "/include"
LIB_DIR = "/lib"
TMP_DIR = "/tmp"

PROGRAM_NAME = "OpenGL Program - {timestamp}".format(timestamp = arrow.now())

LOG_HEADER = "OS: {sys.platform}\nTIME: {arrow.now}"


SRC_FILES = [file for file in os.listdir(SRC_DIR) if file.endswith('.cpp')]
OBJ_FILES = [file for file in os.listdir(OBJ_DIR) if file.endswith('.o')]

def main():
    if parser.Clean:

        
    
    
if __name__ == '__main__':
    main()
