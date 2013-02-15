#!/bin/bash

if [[ "$1" == "debug" ]]; then
	echo "build haxe in debug"
	haxe ./debug.hxml
	echo "copy ./bin/libApplicationMain-debug.so to ../libs/armeabi/libApplicationMain.so"
	cp ./bin/libApplicationMain-debug.so ../libs/armeabi/libApplicationMain.so
	echo "--------------Haxe build done!------------"
else
	echo "build haxe in release"
	haxe release.hxml
	echo "copy ./bin/libApplicationMain.so to ../libs/armeabi/libApplicationMain.so"
	cp ./bin/libApplicationMain.so ../libs/armeabi/libApplicationMain.so
	echo "--------------Haxe build done!------------"
fi
