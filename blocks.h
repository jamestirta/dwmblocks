//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0}, */
	{"", "[ -z $( pgrep 'obs-ffmpeg-mux' ) ] && echo '' || echo ' 🔴 |'",					          3600,  1},
	{"📅 ", "date '+%a, %d %b %Y |'",					                                              10800, 0},
  {"🧠 ", "echo $( free --giga | grep Mem | frawk '{print $2}' )'% |'",                   30,    0},
  {"💻 ", "echo $( cut -d'0' -f1 /sys/class/thermal/thermal_zone1/temp )'° |'",           2,     0},
  {"🚀 ", "echo $( nvidia-smi -q -d temperature | rg 'GPU C' | frawk '{print $5}')'° |'", 2,     0},
  {"🔊 ", "echo $( pamixer --get-volume ) '|'",                                           60,    2},
	{"⏰ ", "date '+%I:%M %p'",				                                                  	  60,  	 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 1;
