/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int user_bh	    = 16;
static const char *fonts[]          = { "ubuntu:size=8" };
static const char dmenufont[]       = "ubuntu:size=8";
static const char col_gray[]       = "#121212";
static const char col_purple[]      = "#54487a"; // Purple 
static const char col_white[]       = "#f0f0f0"; // White
static const char col_yellow[]      = "#f2ca30"; // Yellow
static const char s_base00[]        = "#f26711"; // Orange
static const char s_base01[]        = "#121212";
static const char s_base02[]        = "#121212";
static const char s_base03[]        = "#f2ca30";
static const char s_base0[]         = "#eb0028";
static const char s_base1[]         = "#121212";
static const char s_base2[]         = "#121212";
static const char s_base3[]         = "#f0f0f0";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	// Yellow Theme
        { col_white, col_gray, col_purple }, /* SchemeNorm orig */
        { col_gray, col_yellow,  col_yellow  }, /* SchemeSel orig */

	// Red Theme
	{ s_base3, s_base2, s_base2 },      /* SchemeNorm dark */
       	{ s_base2, s_base0, s_base0 },      /* SchemeSel dark */
	
	// Orange Theme
       	{ s_base3, s_base2, s_base2 },     /* SchemeNorm light */
       	{ s_base2, s_base00, s_base00},      /* SchemeSel light */
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

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[M]",      monocle },
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
#define TERMINAL "st"
#define FM	 "vifm"
#define SYSMON	 "htop"
#define MYSITE   "torchweb.neocities.org"
#define EMAIL_SITE "protonmail.com"
#define BRIGHTNESS_PATH "/sys/class/backlight/nv_backlight/brightness"
/* Note certain key chains are in place to allow for alot more keybinds
alt + f will allow for dwm function for example quitting dwm or killing a program
alt + w will allow to open certain pages within a browser */

static const Key keys[] = {
	/* modifier                     chain key key        function        argument */
	{ MODKEY,             		-1,       XK_space,  spawn,          {.v = (const char*[]) {TERMINAL, 	       			NULL}}},
	{ MODKEY|ShiftMask,		-1,	  XK_space,  spawn,	     {.v = (const char*[]) {"tabbed", "-c", "-r", "2", TERMINAL, "-w", """",NULL}}},
	{ MODKEY,			-1, 	  XK_f,      spawn,	     {.v = (const char*[]) {TERMINAL, FM,      			NULL}}},
	{ MODKEY,			XK_p,	  XK_m,	     spawn,	     {.v = (const char*[]) {TERMINAL, SYSMON,			NULL}}},
	{ MODKEY,			XK_w,	  XK_b,	     spawn,	     {.v = (const char*[]) {BROWSER,  SEARCH,  	        	NULL}}},
	{ MODKEY,			XK_w,     XK_y,	     spawn,	     {.v = (const char*[]) {BROWSER, "yewtu.be", 		NULL}}},
	{ MODKEY,			XK_w,	  XK_e,	     spawn,	     {.v = (const char*[]) {BROWSER, EMAIL_SITE,		NULL}}},
	{ MODKEY,			XK_w,	  XK_f,	     spawn,	     {.v = (const char*[]) {BROWSER, "forums.freebsd.org",	NULL}}},
	{ MODKEY,			XK_w,	  XK_l,	     spawn,	     {.v = (const char*[]) {BROWSER, "lemmy.ml",		NULL}}},
	{ MODKEY,			XK_w,	  XK_c,	     spawn,	     {.v = (const char*[]) {BROWSER, "cboard.cprogramming.com", NULL}}},
	{ MODKEY,			XK_w,	  XK_o,	     spawn,	     {.v = (const char*[]) {BROWSER, "man.openbsd.org",		NULL}}},
	{ MODKEY,			XK_w,	  XK_g,	     spawn,	     {.v = (const char*[]) {BROWSER, "github.com/africavoid", 	NULL}}},
	{ MODKEY,			XK_w,	  XK_t,	     spawn,	     {.v = (const char*[]) {BROWSER, "forums.gentoo.org",	NULL}}},
	{ MODKEY,			XK_w,	  XK_r,	     spawn,	     {.v = (const char*[]) {BROWSER, "old.reddit.com",		NULL}}},
	{ MODKEY,			XK_w,	  XK_a,	     spawn,	     {.v = (const char*[]) {BROWSER, "wiki.archlinux.org",	NULL}}},
	{ MODKEY,			XK_w,	  XK_s,	     spawn,	     {.v = (const char*[]) {BROWSER, "suckless.org",		NULL}}},
	{ MODKEY,			XK_w,	  XK_w,	     spawn,	     {.v = (const char*[]) {BROWSER, "wiby.me",			NULL}}},
	{ MODKEY,			XK_w,	  XK_m,	     spawn,	     {.v = (const char*[]) {BROWSER, MYSITE,			NULL}}},
	{ MODKEY,			XK_p,	  XK_p,	     spawn,	     {.v = (const char*[]) {"dmenu_run",			NULL}}},
	#ifdef __linux 
	{ MODKEY,                       XK_a,     XK_k,      spawn,          {.v = (const char*[]) {"amixer",   "set", "Master", "10%+",    NULL}}},
        { MODKEY,                       XK_a,     XK_j,      spawn,          {.v = (const char*[]) {"amixer",   "set", "Master", "10%-",    NULL}}},
        { MODKEY,                       XK_a,     XK_m,      spawn,          {.v = (const char*[]) {"amixer",   "set", "Master", "mute",    NULL}}},
        { MODKEY,                       XK_a,     XK_u,      spawn,          {.v = (const char*[]) {"amixer",   "set", "Master", "unmute",  NULL}}},
        { MODKEY,                       XK_a,     XK_a,      spawn,          {.v = (const char*[]) {TERMINAL,"alsamixer",		    NULL}}},
	{ MODKEY,			XK_m,	  XK_k,	     spawn,	     {.v = (const char*[]) {"sh","echo", "100", ">", BRIGHTNESS_PATH, NULL}}},
	{ MODKEY,			XK_m,	  XK_j,	     spawn,	     {.v = (const char*[]) {"sh","echo", "30", ">", BRIGHTNESS_PATH, NULL}}}, 
	#endif 
	#ifdef __OpenBSD__ 
	{ MODKEY,			XK_a,	  XK_k,	     spawn,	     {.v = (const char*[]) {"sndioctl", "output.level=+0.1",	NULL}}},
	{ MODKEY,			XK_a,	  XK_j,	     spawn,	     {.v = (const char*[]) {"sndioctl", "output.level=-0.1",	NULL}}},
	{ MODKEY,			XK_a,	  XK_m,	     spawn,	     {.v = (const char*[]) {"sndioctl", "output.mute=1",	NULL}}},
	{ MODKEY,			XK_a,	  XK_u,	     spawn,	     {.v = (const char*[]) {"sndioctl", "output.mute=0",	NULL}}},
	#endif
	{ MODKEY,			XK_s,     XK_b,	     togglebar,	     {0}},
	{ MODKEY,			XK_s,	  XK_s,	     schemeCycle,    {0}},
	{ MODKEY,                       -1,	  XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       -1,	  XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       -1,       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       -1,       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             -1,       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             -1,	  XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             -1,	  XK_k,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             -1,	  XK_j,      setcfact,       {.f = -0.25} },
	{ MODKEY,             		XK_s,     XK_r,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       -1,       XK_Return, zoom,           {0} },
	{ MODKEY,                       -1,       XK_Tab,    view,           {0} },
	{ MODKEY,             		XK_s,     XK_k,      killclient,     {0} },
	{ MODKEY,             		XK_s,     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,             		XK_s,	  XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,			XK_r,	  XK_h,      resizemouse,    {0} },
	{ MODKEY,			XK_r,	  XK_l,	     resizemouse,    {0} },
	{ MODKEY,			XK_r,	  XK_j,	     movemouse,	     {0} },
	{ MODKEY,			XK_r,	  XK_k,	     movemouse,	     {0} },
	{ MODKEY,			XK_r,	  XK_r,	     togglefloating, {0} },
	TAGKEYS(                        -1, 	  XK_1,                    0)
	TAGKEYS(                        -1,	  XK_2,                    1)
	TAGKEYS(                        -1,       XK_3,                    2)
	TAGKEYS(			-1,       XK_4,			   3)
	TAGKEYS(			-1,       XK_5,			   4)
	TAGKEYS(			-1,	  XK_6,			   5)
	TAGKEYS(			-1,	  XK_7,			   6)
	TAGKEYS(			-1,	  XK_8,			   7)
	{ MODKEY,                       XK_s,     XK_q,      quit,           {0} },
		
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

