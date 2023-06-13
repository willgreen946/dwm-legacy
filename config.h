/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int user_bh	    = 16;
static const char *fonts[]          = { "terminus:size=8" };
static const char dmenufont[]       = "terminus:size=8";
static const char black[]      	    = "#000000";
static const char purple[]          = "#54487a"; // Purple 
static const char white[]           = "#ffffff"; // White
static const char yellow[]          = "#f2ca30"; // Yellow
static const char orange[]          = "#f26711"; // Orange
static const char matrix_green[]    = "#008f11";
static const char matrix_dark[]	    = "#003b00";


static const char *colors[][3]      = {
	/*               fg         bg         border   */
	// Yellow Theme
        { white, black, purple }, /* SchemeNorm orig */
        { black, yellow,yellow  }, /* SchemeSel orig */

	// Red Theme
	{ matrix_green, black, matrix_dark },      /* matrix */
       	{ black, matrix_green, matrix_green },      
	
	// Orange Theme
       	{ white, black, black },     /* SchemeNorm light */
       	{ black, orange, orange},      /* SchemeSel light */
};

/* tagging */
static const char *tags[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]"};

#define BROWSER "vieb"
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{  "gimp",  NULL,       NULL,       1 << 7,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[S]",      spiral },
	{ "[D]",      dwindle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define SEARCH   "searx.be"
#define SEARCH_ALT "searx.org"
#define TERMINAL "st"
#define FM	 "vifm"
#define VIM 	 "nvim"
#define SYSMON	 "htop"
#define MYSITE   "torchweb.neocities.org"
#define EMAIL_SITE "protonmail.com"
#define BOOKMARKS  "/home/will/Documents/Bookmarks/bookmarks.html"
#define BRIGHTNESS_PATH "/sys/class/backlight/nv_backlight/brightness"
/* Note certain key chains are in place to allow for alot more keybinds
alt + f will allow for dwm function for example quitting dwm or killing a program
alt + w will allow to open certain pages within a browser */

static const Key keys[] = {
	/* modifier                     chain key key        function        argument */
	/* program launch */
	{ MODKEY,           	-1,       XK_space,  spawn,	{.v = (const char*[]) {TERMINAL, 	       			 NULL}}},
	{ MODKEY,		XK_p, 	  XK_f,      spawn,	{.v = (const char*[]) {TERMINAL, FM,     			 NULL}}},
	{ MODKEY,		XK_p,	  XK_h,	     spawn,	{.v = (const char*[]) {TERMINAL, SYSMON, 			 NULL}}},
	{ MODKEY,		XK_p,	  XK_v,	     spawn,	{.v = (const char*[]) {TERMINAL, VIM,				 NULL}}},
	{ MODKEY,		XK_p,	  XK_p,	     spawn,	{.v = (const char*[]) {"dmenu_run",				 NULL}}},
	/* scripts */
	#ifdef __linux
	{ MODKEY,		XK_s,	  XK_n,	     spawn,	{.v = (const char*[]) {TERMINAL, "sh", "/home/will/.scripts/wifi.sh", "-o", "linux", "-i", "wlan0", NULL}}},
	{ MODKEY,		XK_s,	  XK_b,	     spawn,	{.v = (const char*[]) {TERMINAL, "doas", "nvim", "/sys/class/backlight/nv_backlight/brightness",    NULL}}},
	#endif
	#ifdef __OpenBSD__
	{ MODKEY,		XK_s,	  XK_n,	     spawn,	{.v = (const char*[]) {TERMINAL, "doas", "sh", "home/will/.scripts/obsd.sh", NULL}}},
	#endif
	{ MODKEY,		XK_s,	  XK_w,	     spawn,	{.v = (const char*[]) {TERMINAL, "curl", "wttr.in", "&&", "read i", NULL}}},
	/* web  XK_w is normal websites XK_o is other websites since theres a lot of websites I want to have binds for*/
	{ MODKEY,		XK_w,	  XK_space,  spawn,	{.v = (const char*[]) {BROWSER,  SEARCH, 			 NULL}}},
	{ MODKEY,		XK_w,     XK_y,	     spawn,	{.v = (const char*[]) {BROWSER, "yewtu.be", 			 NULL}}},
	{ MODKEY,		XK_w,	  XK_e,	     spawn,	{.v = (const char*[]) {BROWSER, EMAIL_SITE, 			 NULL}}},
	{ MODKEY,		XK_w,	  XK_f,	     spawn,	{.v = (const char*[]) {BROWSER, "forums.freebsd.org", 		 NULL}}},
	{ MODKEY,		XK_w,	  XK_l,	     spawn,	{.v = (const char*[]) {BROWSER, "lemmy.ml", 		   	 NULL}}},
	{ MODKEY,	 	XK_w,	  XK_c,	     spawn,	{.v = (const char*[]) {BROWSER, "cprogramming.com",		 NULL}}},
	{ MODKEY,		XK_w,	  XK_equal, spawn,	{.v = (const char*[]) {BROWSER, "legacy.cplusplus.com/",	 NULL}}},
	{ MODKEY,		XK_w,	  XK_o,	     spawn,	{.v = (const char*[]) {BROWSER, "man.openbsd.org", 		 NULL}}},
	{ MODKEY,		XK_w,	  XK_g,	     spawn,	{.v = (const char*[]) {BROWSER, "github.com/africavoid", 	 NULL}}},
	{ MODKEY,		XK_w,	  XK_t,	     spawn,	{.v = (const char*[]) {BROWSER, "gentoo.org", 			 NULL}}},
	{ MODKEY,		XK_w,	  XK_a,	     spawn,	{.v = (const char*[]) {BROWSER, "wiki.archlinux.org", 		 NULL}}},
	{ MODKEY,		XK_w,	  XK_s,	     spawn,	{.v = (const char*[]) {BROWSER, "suckless.org",			 NULL}}},
	{ MODKEY,		XK_w,	  XK_w,	     spawn,	{.v = (const char*[]) {BROWSER, "wiby.me", 			 NULL}}},
	{ MODKEY,		XK_w,	  XK_m,	     spawn,	{.v = (const char*[]) {BROWSER, MYSITE,				 NULL}}},
	{ MODKEY,		XK_w,	  XK_b,	     spawn,	{.v = (const char*[]) {BROWSER, BOOKMARKS,			 NULL}}},
	{ MODKEY,		XK_o,	  XK_b,	     spawn,	{.v = (const char*[]) {BROWSER, "bbc.com/iplayer",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_space,  spawn,	{.v = (const char*[]) {BROWSER, SEARCH_ALT,			 NULL}}},
	{ MODKEY,		XK_o,	  XK_y,	     spawn,	{.v = (const char*[]) {BROWSER, "vid.puffyan.us",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_l,	     spawn,	{.v = (const char*[]) {BROWSER,	"linuxquestions.org",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_c,	     spawn,	{.v = (const char*[]) {BROWSER,	"cboard.cprogramming.com",	 NULL}}},
	{ MODKEY,		XK_o,	  XK_equal,  spawn,	{.v = (const char*[]) {BROWSER, "legacy.cplusplus.com/forum",	 NULL}}},
	{ MODKEY,		XK_o,	  XK_g,	     spawn,	{.v = (const char*[]) {BROWSER, "forums.gentoo.org",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_d,	     spawn,	{.v = (const char*[]) {BROWSER, "daemonforums.org",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_o,	     spawn,	{.v = (const char*[]) {BROWSER,	"https://www.linuxquestions.org/questions/%2Absd-17/", NULL}}},
	{ MODKEY,		XK_o,	  XK_a,	     spawn,	{.v = (const char*[]) {BROWSER, "forums.archlinux.org",		 NULL}}},
	{ MODKEY,		XK_o,	  XK_k,	     spawn,	{.v = (const char*[]) {BROWSER, "wiki.linuxquestions.org/wiki/Main_Page", NULL}}},
	#ifdef __linux 
	/* Linux specific commands */
	/* audio */
	{ MODKEY,               XK_a,     XK_k,      spawn,     {.v = (const char*[]) {"amixer",   "set", "Master", "10%+",      NULL}}},
        { MODKEY,               XK_a,     XK_j,      spawn,     {.v = (const char*[]) {"amixer",   "set", "Master", "10%-",      NULL}}},
        { MODKEY,               XK_a,     XK_m,      spawn,     {.v = (const char*[]) {"amixer",   "set", "Master", "mute",      NULL}}},
        { MODKEY,               XK_a,     XK_u,      spawn,     {.v = (const char*[]) {"amixer",   "set", "Master", "unmute",    NULL}}},
        { MODKEY,               XK_a,     XK_a,      spawn,     {.v = (const char*[]) {TERMINAL,   "alsamixer",		       	 NULL}}},
	#endif 
	#ifdef __OpenBSD__ 
	/* OpenBSD specific commands */
	/* audio */
	{ MODKEY,		XK_a,	  XK_k,	     spawn,	{.v = (const char*[]) {"sndioctl", "output.level=+0.1",		 NULL}}},
	{ MODKEY,		XK_a,	  XK_j,	     spawn,	{.v = (const char*[]) {"sndioctl", "output.level=-0.1",		 NULL}}},
	{ MODKEY,		XK_a,	  XK_m,	     spawn,	{.v = (const char*[]) {"sndioctl", "output.mute=1",		 NULL}}},
	{ MODKEY,		XK_a,	  XK_u,	     spawn,	{.v = (const char*[]) {"sndioctl", "output.mute=0",		 NULL}}},
	#endif
	/* dwm functions */
	{ MODKEY,		XK_f,     XK_b,	     togglebar,	     {0}},
	{ MODKEY,		XK_f,	  XK_c,	     schemeCycle,    {0}},
	{ MODKEY,		XK_f,	  XK_k,	     killclient,     {0}},
	{ MODKEY,		XK_f,	  XK_t,      setlayout,	     {.v = &layouts[0]}},
	{ MODKEY,		XK_f,	  XK_m,	     setlayout,	     {.v = &layouts[1]}},
	{ MODKEY,		XK_f,	  XK_s,	     setlayout,	     {.v = &layouts[2]}},
	{ MODKEY,		XK_f,	  XK_d,	     setlayout,	     {.v = &layouts[3]}},
	/* navigation */
	{ MODKEY,               -1,	  XK_j,      focusstack,     {.i = +1 }},
	{ MODKEY,               -1,	  XK_k,      focusstack,     {.i = -1 }},
	{ MODKEY,               -1,       XK_i,      incnmaster,     {.i = +1 }},
	{ MODKEY,               -1,       XK_d,      incnmaster,     {.i = -1 }},
	{ MODKEY|ShiftMask,     -1,       XK_h,      setmfact,       {.f = -0.05}},
	{ MODKEY|ShiftMask,     -1,	  XK_l,      setmfact,       {.f = +0.05}},
	{ MODKEY|ShiftMask,     -1,	  XK_k,      setcfact,       {.f = +0.25}},
	{ MODKEY|ShiftMask,     -1,	  XK_j,      setcfact,       {.f = -0.25}},
	{ MODKEY,               -1,       XK_Return, zoom,           {0}},
	{ MODKEY,               -1,       XK_Tab,    view,           {0}},
	/* resize */
	{ MODKEY,		XK_r,	  XK_h,      resizemouse,    {0}},
	{ MODKEY,		XK_r,	  XK_l,	     resizemouse,    {0}},
	{ MODKEY,		XK_r,	  XK_j,	     movemouse,	     {0}},
	{ MODKEY,		XK_r,	  XK_k,	     movemouse,	     {0}},
	{ MODKEY,		XK_r,	  XK_r,	     togglefloating, {0}},
	/* move between tags */
	TAGKEYS(                -1, 	  XK_1,                    0)
	TAGKEYS(                -1,	  XK_2,                    1)
	TAGKEYS(                -1,       XK_3,                    2)
	TAGKEYS(		-1,       XK_4,			   3)
	TAGKEYS(		-1,       XK_5,			   4)
	TAGKEYS(		-1,	  XK_6,			   5)
	TAGKEYS(		-1,	  XK_7,			   6)
	TAGKEYS(		-1,	  XK_8,			   7)
	{ MODKEY,               XK_f,     XK_q,      quit,         {0}},
		
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

