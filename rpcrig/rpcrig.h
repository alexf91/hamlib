/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCRIG_H_RPCGEN
#define _RPCRIG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Hamlib Interface - RPC definitions
 *  Copyright (c) 2000,2001 by Stephane Fillod and Frank Singleton
 *
 *		$Id: rpcrig.h,v 1.3 2001-12-27 21:59:10 fillods Exp $
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Library General Public License for more details.
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */
#include <rpc/xdr.h>
#include <hamlib/rig.h>

typedef u_int model_x;

typedef int vfo_x;

typedef int64_t freq_x;

typedef u_int rmode_x;

typedef int pbwidth_x;

typedef u_long split_x;

typedef int ptt_x;

typedef int dcd_x;

typedef long vfo_op_x;

typedef long shortfreq_x;

typedef uint64_t setting_x;

typedef long ant_x;

typedef long ann_x;

struct mode_s {
	rmode_x mode;
	pbwidth_x width;
};
typedef struct mode_s mode_s;

struct value_s {
	int i;
	float f;
};
typedef struct value_s value_s;

struct freq_arg {
	vfo_x vfo;
	freq_x freq;
};
typedef struct freq_arg freq_arg;

struct freq_res {
	int rigstatus;
	union {
		freq_x freq;
	} freq_res_u;
};
typedef struct freq_res freq_res;

struct mode_arg {
	vfo_x vfo;
	mode_s mw;
};
typedef struct mode_arg mode_arg;

struct mode_res {
	int rigstatus;
	union {
		mode_s mw;
	} mode_res_u;
};
typedef struct mode_res mode_res;

struct vfo_res {
	int rigstatus;
	union {
		vfo_x vfo;
	} vfo_res_u;
};
typedef struct vfo_res vfo_res;

struct split_arg {
	vfo_x vfo;
	split_x split;
};
typedef struct split_arg split_arg;

struct split_res {
	int rigstatus;
	union {
		split_x split;
	} split_res_u;
};
typedef struct split_res split_res;

struct ptt_arg {
	vfo_x vfo;
	ptt_x ptt;
};
typedef struct ptt_arg ptt_arg;

struct ptt_res {
	int rigstatus;
	union {
		ptt_x ptt;
	} ptt_res_u;
};
typedef struct ptt_res ptt_res;

struct dcd_res {
	int rigstatus;
	union {
		dcd_x dcd;
	} dcd_res_u;
};
typedef struct dcd_res dcd_res;

struct setting_arg {
	vfo_x vfo;
	setting_x setting;
	value_s val;
};
typedef struct setting_arg setting_arg;

struct val_res {
	int rigstatus;
	union {
		value_s val;
	} val_res_u;
};
typedef struct val_res val_res;

struct vfo_op_arg {
	vfo_x vfo;
	vfo_op_x op;
};
typedef struct vfo_op_arg vfo_op_arg;

struct freq_range_s {
	freq_x start;
	freq_x end;
	rmode_x modes;
	int low_power;
	int high_power;
	vfo_x vfo;
	ant_x ant;
};
typedef struct freq_range_s freq_range_s;

struct tuning_step_s {
	rmode_x modes;
	shortfreq_x ts;
};
typedef struct tuning_step_s tuning_step_s;

struct filter_s {
	rmode_x modes;
	pbwidth_x width;
};
typedef struct filter_s filter_s;

struct chan_s {
	int start;
	int end;
	u_int type;
};
typedef struct chan_s chan_s;

struct rigstate_s {
	int itu_region;
	shortfreq_x max_rit;
	shortfreq_x max_xit;
	shortfreq_x max_ifshift;
	ann_x announces;
	setting_x has_get_func;
	setting_x has_set_func;
	setting_x has_get_level;
	setting_x has_set_level;
	setting_x has_get_parm;
	setting_x has_set_parm;
	int preamp[MAXDBLSTSIZ];
	int attenuator[MAXDBLSTSIZ];
	freq_range_s rx_range_list[FRQRANGESIZ];
	freq_range_s tx_range_list[FRQRANGESIZ];
	tuning_step_s tuning_steps[TSLSTSIZ];
	filter_s filters[FLTLSTSIZ];
	chan_s chan_list[CHANLSTSIZ];
};
typedef struct rigstate_s rigstate_s;

struct rigstate_res {
	int rigstatus;
	union {
		rigstate_s state;
	} rigstate_res_u;
};
typedef struct rigstate_res rigstate_res;

#define freq_t2x(t, x) do { *(x) = (t); } while(0)
#define freq_x2t(x) ((freq_t)*(x))

#define setting_t2x(t, x) do { *(x) = (t); } while(0)
#define setting_x2t(x) ((setting_t)*(x))

static inline void mode_t2s(rmode_t modet, pbwidth_t widtht, mode_s *modes)
{
	modes->mode = modet;
	modes->width = widtht;
}
static inline void mode_s2t(mode_s *modes, rmode_t *modet, pbwidth_t *widtht)
{
	*modet = modes->mode;
	*widtht = modes->width;
}

#define RIGPROG 0x20000099
#define RIGVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define GETMODEL 1
extern  model_x * getmodel_1(void *, CLIENT *);
extern  model_x * getmodel_1_svc(void *, struct svc_req *);
#define GETRIGSTATE 3
extern  rigstate_res * getrigstate_1(void *, CLIENT *);
extern  rigstate_res * getrigstate_1_svc(void *, struct svc_req *);
#define SETFREQ 10
extern  int * setfreq_1(freq_arg *, CLIENT *);
extern  int * setfreq_1_svc(freq_arg *, struct svc_req *);
#define GETFREQ 11
extern  freq_res * getfreq_1(vfo_x *, CLIENT *);
extern  freq_res * getfreq_1_svc(vfo_x *, struct svc_req *);
#define SETMODE 12
extern  int * setmode_1(mode_arg *, CLIENT *);
extern  int * setmode_1_svc(mode_arg *, struct svc_req *);
#define GETMODE 13
extern  mode_res * getmode_1(vfo_x *, CLIENT *);
extern  mode_res * getmode_1_svc(vfo_x *, struct svc_req *);
#define SETVFO 14
extern  int * setvfo_1(vfo_x *, CLIENT *);
extern  int * setvfo_1_svc(vfo_x *, struct svc_req *);
#define GETVFO 15
extern  vfo_res * getvfo_1(vfo_x *, CLIENT *);
extern  vfo_res * getvfo_1_svc(vfo_x *, struct svc_req *);
#define SETSPLITFREQ 16
extern  int * setsplitfreq_1(freq_arg *, CLIENT *);
extern  int * setsplitfreq_1_svc(freq_arg *, struct svc_req *);
#define GETSPLITFREQ 17
extern  freq_res * getsplitfreq_1(vfo_x *, CLIENT *);
extern  freq_res * getsplitfreq_1_svc(vfo_x *, struct svc_req *);
#define SETSPLITMODE 18
extern  int * setsplitmode_1(mode_arg *, CLIENT *);
extern  int * setsplitmode_1_svc(mode_arg *, struct svc_req *);
#define GETSPLITMODE 19
extern  mode_res * getsplitmode_1(vfo_x *, CLIENT *);
extern  mode_res * getsplitmode_1_svc(vfo_x *, struct svc_req *);
#define SETSPLIT 20
extern  int * setsplit_1(split_arg *, CLIENT *);
extern  int * setsplit_1_svc(split_arg *, struct svc_req *);
#define GETSPLIT 21
extern  split_res * getsplit_1(vfo_x *, CLIENT *);
extern  split_res * getsplit_1_svc(vfo_x *, struct svc_req *);
#define SETPTT 22
extern  int * setptt_1(ptt_arg *, CLIENT *);
extern  int * setptt_1_svc(ptt_arg *, struct svc_req *);
#define GETPTT 23
extern  ptt_res * getptt_1(vfo_x *, CLIENT *);
extern  ptt_res * getptt_1_svc(vfo_x *, struct svc_req *);
#define GETDCD 24
extern  dcd_res * getdcd_1(vfo_x *, CLIENT *);
extern  dcd_res * getdcd_1_svc(vfo_x *, struct svc_req *);
#define SETFUNC 25
extern  int * setfunc_1(setting_arg *, CLIENT *);
extern  int * setfunc_1_svc(setting_arg *, struct svc_req *);
#define GETFUNC 26
extern  val_res * getfunc_1(setting_arg *, CLIENT *);
extern  val_res * getfunc_1_svc(setting_arg *, struct svc_req *);
#define SETLEVEL 27
extern  int * setlevel_1(setting_arg *, CLIENT *);
extern  int * setlevel_1_svc(setting_arg *, struct svc_req *);
#define GETLEVEL 28
extern  val_res * getlevel_1(setting_arg *, CLIENT *);
extern  val_res * getlevel_1_svc(setting_arg *, struct svc_req *);
#define SETPARM 29
extern  int * setparm_1(setting_arg *, CLIENT *);
extern  int * setparm_1_svc(setting_arg *, struct svc_req *);
#define GETPARM 30
extern  val_res * getparm_1(setting_arg *, CLIENT *);
extern  val_res * getparm_1_svc(setting_arg *, struct svc_req *);
#define VFOOP 31
extern  int * vfoop_1(vfo_op_arg *, CLIENT *);
extern  int * vfoop_1_svc(vfo_op_arg *, struct svc_req *);
extern int rigprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define GETMODEL 1
extern  model_x * getmodel_1();
extern  model_x * getmodel_1_svc();
#define GETRIGSTATE 3
extern  rigstate_res * getrigstate_1();
extern  rigstate_res * getrigstate_1_svc();
#define SETFREQ 10
extern  int * setfreq_1();
extern  int * setfreq_1_svc();
#define GETFREQ 11
extern  freq_res * getfreq_1();
extern  freq_res * getfreq_1_svc();
#define SETMODE 12
extern  int * setmode_1();
extern  int * setmode_1_svc();
#define GETMODE 13
extern  mode_res * getmode_1();
extern  mode_res * getmode_1_svc();
#define SETVFO 14
extern  int * setvfo_1();
extern  int * setvfo_1_svc();
#define GETVFO 15
extern  vfo_res * getvfo_1();
extern  vfo_res * getvfo_1_svc();
#define SETSPLITFREQ 16
extern  int * setsplitfreq_1();
extern  int * setsplitfreq_1_svc();
#define GETSPLITFREQ 17
extern  freq_res * getsplitfreq_1();
extern  freq_res * getsplitfreq_1_svc();
#define SETSPLITMODE 18
extern  int * setsplitmode_1();
extern  int * setsplitmode_1_svc();
#define GETSPLITMODE 19
extern  mode_res * getsplitmode_1();
extern  mode_res * getsplitmode_1_svc();
#define SETSPLIT 20
extern  int * setsplit_1();
extern  int * setsplit_1_svc();
#define GETSPLIT 21
extern  split_res * getsplit_1();
extern  split_res * getsplit_1_svc();
#define SETPTT 22
extern  int * setptt_1();
extern  int * setptt_1_svc();
#define GETPTT 23
extern  ptt_res * getptt_1();
extern  ptt_res * getptt_1_svc();
#define GETDCD 24
extern  dcd_res * getdcd_1();
extern  dcd_res * getdcd_1_svc();
#define SETFUNC 25
extern  int * setfunc_1();
extern  int * setfunc_1_svc();
#define GETFUNC 26
extern  val_res * getfunc_1();
extern  val_res * getfunc_1_svc();
#define SETLEVEL 27
extern  int * setlevel_1();
extern  int * setlevel_1_svc();
#define GETLEVEL 28
extern  val_res * getlevel_1();
extern  val_res * getlevel_1_svc();
#define SETPARM 29
extern  int * setparm_1();
extern  int * setparm_1_svc();
#define GETPARM 30
extern  val_res * getparm_1();
extern  val_res * getparm_1_svc();
#define VFOOP 31
extern  int * vfoop_1();
extern  int * vfoop_1_svc();
extern int rigprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_model_x (XDR *, model_x*);
extern  bool_t xdr_vfo_x (XDR *, vfo_x*);
extern  bool_t xdr_freq_x (XDR *, freq_x*);
extern  bool_t xdr_rmode_x (XDR *, rmode_x*);
extern  bool_t xdr_pbwidth_x (XDR *, pbwidth_x*);
extern  bool_t xdr_split_x (XDR *, split_x*);
extern  bool_t xdr_ptt_x (XDR *, ptt_x*);
extern  bool_t xdr_dcd_x (XDR *, dcd_x*);
extern  bool_t xdr_vfo_op_x (XDR *, vfo_op_x*);
extern  bool_t xdr_shortfreq_x (XDR *, shortfreq_x*);
extern  bool_t xdr_setting_x (XDR *, setting_x*);
extern  bool_t xdr_ant_x (XDR *, ant_x*);
extern  bool_t xdr_ann_x (XDR *, ann_x*);
extern  bool_t xdr_mode_s (XDR *, mode_s*);
extern  bool_t xdr_value_s (XDR *, value_s*);
extern  bool_t xdr_freq_arg (XDR *, freq_arg*);
extern  bool_t xdr_freq_res (XDR *, freq_res*);
extern  bool_t xdr_mode_arg (XDR *, mode_arg*);
extern  bool_t xdr_mode_res (XDR *, mode_res*);
extern  bool_t xdr_vfo_res (XDR *, vfo_res*);
extern  bool_t xdr_split_arg (XDR *, split_arg*);
extern  bool_t xdr_split_res (XDR *, split_res*);
extern  bool_t xdr_ptt_arg (XDR *, ptt_arg*);
extern  bool_t xdr_ptt_res (XDR *, ptt_res*);
extern  bool_t xdr_dcd_res (XDR *, dcd_res*);
extern  bool_t xdr_setting_arg (XDR *, setting_arg*);
extern  bool_t xdr_val_res (XDR *, val_res*);
extern  bool_t xdr_vfo_op_arg (XDR *, vfo_op_arg*);
extern  bool_t xdr_freq_range_s (XDR *, freq_range_s*);
extern  bool_t xdr_tuning_step_s (XDR *, tuning_step_s*);
extern  bool_t xdr_filter_s (XDR *, filter_s*);
extern  bool_t xdr_chan_s (XDR *, chan_s*);
extern  bool_t xdr_rigstate_s (XDR *, rigstate_s*);
extern  bool_t xdr_rigstate_res (XDR *, rigstate_res*);

#else /* K&R C */
extern bool_t xdr_model_x ();
extern bool_t xdr_vfo_x ();
extern bool_t xdr_freq_x ();
extern bool_t xdr_rmode_x ();
extern bool_t xdr_pbwidth_x ();
extern bool_t xdr_split_x ();
extern bool_t xdr_ptt_x ();
extern bool_t xdr_dcd_x ();
extern bool_t xdr_vfo_op_x ();
extern bool_t xdr_shortfreq_x ();
extern bool_t xdr_setting_x ();
extern bool_t xdr_ant_x ();
extern bool_t xdr_ann_x ();
extern bool_t xdr_mode_s ();
extern bool_t xdr_value_s ();
extern bool_t xdr_freq_arg ();
extern bool_t xdr_freq_res ();
extern bool_t xdr_mode_arg ();
extern bool_t xdr_mode_res ();
extern bool_t xdr_vfo_res ();
extern bool_t xdr_split_arg ();
extern bool_t xdr_split_res ();
extern bool_t xdr_ptt_arg ();
extern bool_t xdr_ptt_res ();
extern bool_t xdr_dcd_res ();
extern bool_t xdr_setting_arg ();
extern bool_t xdr_val_res ();
extern bool_t xdr_vfo_op_arg ();
extern bool_t xdr_freq_range_s ();
extern bool_t xdr_tuning_step_s ();
extern bool_t xdr_filter_s ();
extern bool_t xdr_chan_s ();
extern bool_t xdr_rigstate_s ();
extern bool_t xdr_rigstate_res ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPCRIG_H_RPCGEN */
