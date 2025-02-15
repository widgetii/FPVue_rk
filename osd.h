#ifndef OSD_H
#define OSD_H

#include "drm.h"
#include <cairo.h>

// OSD Vars
struct osd_vars {
    int plane_zpos;

	// Video Decoder
    bool enable_video;
	int current_framerate;
	uint64_t latency_avg;
	uint64_t latency_max;
	uint64_t latency_min;
	// Video Feed
	int bw_curr;
	long long bw_stats[10];
	unsigned int video_width;
	unsigned int video_height;

	// Mavlink WFB-ng
    bool enable_wfbng;
    int8_t wfb_rssi;
    uint16_t wfb_errors;
    uint16_t wfb_fec_fixed;
    int8_t wfb_flags;

	// Mavlink
    // TODO (gehee) Render these elements in OSD.
    bool enable_mavlink;
    float telemetry_altitude;
    float telemetry_pitch;
    float telemetry_roll;
    float telemetry_yaw;
    float telemetry_battery;
    float telemetry_current;
    float telemetry_current_consumed;
    double telemetry_lat;
    double telemetry_lon;
    double telemetry_lat_base;
    double telemetry_lon_base;
    double telemetry_hdg;
    double telemetry_distance;
    double s1_double;
    double s2_double;
    double s3_double;
    double s4_double;
    float telemetry_sats;
    float telemetry_gspeed;
    float telemetry_vspeed;
    float telemetry_rssi;
    float telemetry_throttle;
    float telemetry_resolution;
    float telemetry_arm;
    float armed;
    char c1[30];
    char c2[30];
    char s1[30];
    char s2[30];
    char s3[30];
    char s4[30];
    char* ptr;
};

extern struct osd_vars osd_vars;
extern int osd_thread_signal;

typedef struct {
	struct modeset_output *output_list;
	int fd;
} osd_thread_params;

int modeset_perform_modeset_osd(int fd, struct modeset_output *output_list);

void modeset_draw_osd(int fd, struct drm_object *plane, struct modeset_output *out, 
	cairo_surface_t* fps_icon, cairo_surface_t* lat_icon, cairo_surface_t* net_icon);

void *__OSD_THREAD__(void *param);

#endif
