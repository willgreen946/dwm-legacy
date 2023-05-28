/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int user_bh	    = 16;
static const char *fonts[]          = { "ubuntu:size=8" };
static const char dmenufont[]       = "ubuntu:size=8";
static const char col_gray1[]       = "#121212";
static const char col_gray2[]       = "#121212"; // grey
static const char col_gray3[]       = "#f0f0f0";
static const char col_gray4[]       = "#121212"; // grey/white
static const char col_cyan[]        = "#f2ca30"; // Orange , yellow
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]"};

#define BROWSER "qutebrowser"
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ BROWSER,  NULL,       NULL,       1 << 7,       0,           -1 },
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

static const Key keys[] = {
	/* modifier                     chain key key        function        argument */
	{ MODKEY,             		-1,       XK_space,  spawn,          {.v = (const char*[]) {TERMINAL, 	       			NULL}}},
	{ MODKEY,			-1, 	  XK_v,      spawn,	     {.v = (const char*[]) {TERMINAL, FM,      			NULL}}},
	{ MODKEY,			-1,	  XK_b,	     spawn,	     {.v = (const char*[]) {BROWSER,  SEARCH,  	        	NULL}}},
	{ MODKEY,			XK_w,     XK_y,	     spawn,	     {.v = (const char*[]) {BROWSER, "yewtu.be", 		NULL}}},
	{ MODKEY,			XK_w,	  XK_c,	     spawn,	     {.v = (const char*[]) {BROWSER, "cboard.cprogramming.com", NULL}}},
	{ MODKEY,			XK_w,	  XK_o,	     spawn,	     {.v = (const char*[]) {BROWSER, "openbsd.org",		NULL}}},
	{ MODKEY,			XK_w,	  XK_g,	     spawn,	     {.v = (const char*[]) {BROWSER, "github.com/africavoid", 	NULL}}},
	{ MODKEY,			-1,       XK_m,	     spawn,	     {.v = (const char*[]) {TERMINAL, SYSMON,   		NULL}}},
	{ MODKEY,			XK_f,     XK_b,	     togglebar,	     {0}},
	{ MODKEY,                       -1,	  XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       -1,	  XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       -1,       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       -1,       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             -1,       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             -1,	  XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             -1,	  XK_k,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             -1,	  XK_j,      setcfact,       {.f = -0.25} },
	{ MODKEY,             		XK_f,     XK_r,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       -1,       XK_Return, zoom,           {0} },
	{ MODKEY,                       -1,       XK_Tab,    view,           {0} },
	{ MODKEY,             		XK_f,     XK_k,      killclient,     {0} },
	{ MODKEY,             		XK_f,     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,             		XK_f,	  XK_m,      setlayout,      {.v = &layouts[1]} },
	TAGKEYS(                        -1, 	  XK_1,                    0)
	TAGKEYS(                        -1,	  XK_2,                    1)
	TAGKEYS(                        -1,       XK_3,                    2)
	TAGKEYS(			-1,       XK_4,			   3)
	TAGKEYS(			-1,       XK_5,			   4)
	TAGKEYS(			-1,	  XK_6,			   5)
	TAGKEYS(			-1,	  XK_7,			   6)
	TAGKEYS(			-1,	  XK_8,			   7)
	{ MODKEY,                       XK_f,     XK_q,      quit,           {0} },
		
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

