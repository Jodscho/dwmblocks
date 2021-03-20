//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/*{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},*/
    //{"", "status_usb.sh", 0, 18},
    {"", "status_weather.sh", 1800, 0},
    {"", "status_pg.sh", 0, 16},
    {"", "status_volume.sh", 0, 17},
    #ifdef LAPTOP
    {"", "status_battery.sh", 350, 0},
    #endif
	{"", "status_date.sh", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
