//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0}, */
	{"", 	"[ -z $( pgrep 'obs-ffmpeg-mux' ) ] && echo '' || echo ' 🔴 |'",				2,     2},
	{"📅 ", "date '+%a, %d %b %Y |'",					                                10800, 0},
	/* {"🧠 ", "echo $( free | rg Mem | frawk '{print int($3/$2*100)}' )'% |'",  	                   	30,    0}, */
	{"🧠 ", "echo $( free | frawk '/Mem/ {print int($3/$2*100)}' )'% |'",  	                   		30,    0},
	{"💻 ", "echo $( cut -c1-2 /sys/class/thermal/thermal_zone1/temp )'° |'",                               2,     0},
	/* {"🚀 ", "echo $( nvidia-smi -q -d temperature | rg 'GPU C' | frawk '{print $5}')'°'",                   2,     0}, */
	{"🚀 ", "echo $( head -c 2 /tmp/.gputemp )'°'",       							2,     0},
	/* {"🚀 ", "echo $( nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader,nounits -i 0 )'° @' $( nvidia-smi | rg '%' | frawk '{print $2}')",       2,     0}, */
	/* {"~ ",  "echo $( nvidia-smi | rg '%' | frawk '{print substr($9/$11*100,1,1)}''% |' )",  5,     0}, */
	{"~ ",  "echo $(nvidia-smi | frawk '/%/ {print substr($9/$11*100,1,1)}')'% |'",  			5,     0},
	{"💾 ", "echo $( cut -c1-2 /sys/class/hwmon/hwmon0/temp1_input )'° |'",                     		10,    0},
	{"🔊 ", "echo $( pamixer --get-volume ) '|'",                                                           0,     1},
	{"⏰ ", "date '+%I:%M %p'",				                                        	59,    0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 1;
