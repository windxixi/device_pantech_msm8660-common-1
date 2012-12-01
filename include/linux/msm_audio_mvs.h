#ifndef __MSM_AUDIO_MVS_H
#define __MSM_AUDIO_MVS_H

#include <linux/msm_audio.h>

#define AUDIO_GET_MVS_CONFIG _IOW(AUDIO_IOCTL_MAGIC, \
	(AUDIO_MAX_COMMON_IOCTL_NUM + 0), unsigned)
#define AUDIO_SET_MVS_CONFIG _IOR(AUDIO_IOCTL_MAGIC, \
	(AUDIO_MAX_COMMON_IOCTL_NUM + 1), unsigned)
#ifdef CONFIG_SKY_SND_MVS //N1066 20120410 Sound Patch
#define AUDIO_GET_CURRENT_STATUS _IOR(AUDIO_IOCTL_MAGIC, \
	(AUDIO_MAX_COMMON_IOCTL_NUM + 2), unsigned)
#endif

/* MVS modes */
#define MVS_MODE_IS733 0x1
#define MVS_MODE_IS127 0x2
#define MVS_MODE_4GV_NB 0x3
#define MVS_MODE_4GV_WB 0x4
#define MVS_MODE_AMR 0x5
#define MVS_MODE_EFR 0x6
#define MVS_MODE_FR 0x7
#define MVS_MODE_HR 0x8
#define MVS_MODE_LINEAR_PCM 0x9
#define MVS_MODE_G711 0xA
#define MVS_MODE_PCM 0xC
#define MVS_MODE_AMR_WB 0xD
#define MVS_MODE_G729A 0xE
#define MVS_MODE_G711A 0xF
#define MVS_MODE_G722 0x10
#define MVS_MODE_PCM_WB 0x80000000

enum msm_audio_amr_mode {
	MVS_AMR_MODE_0475, /* AMR 4.75 kbps */
	MVS_AMR_MODE_0515, /* AMR 5.15 kbps */
	MVS_AMR_MODE_0590, /* AMR 5.90 kbps */
	MVS_AMR_MODE_0670, /* AMR 6.70 kbps */
	MVS_AMR_MODE_0740, /* AMR 7.40 kbps */
	MVS_AMR_MODE_0795, /* AMR 7.95 kbps */
	MVS_AMR_MODE_1020, /* AMR 10.20 kbps */
	MVS_AMR_MODE_1220, /* AMR 12.20 kbps */
	MVS_AMR_MODE_0660, /* AMR-WB 6.60 kbps */
	MVS_AMR_MODE_0885, /* AMR-WB 8.85 kbps */
	MVS_AMR_MODE_1265, /* AMR-WB 12.65 kbps */
	MVS_AMR_MODE_1425, /* AMR-WB 14.25 kbps */
	MVS_AMR_MODE_1585, /* AMR-WB 15.85 kbps */
	MVS_AMR_MODE_1825, /* AMR-WB 18.25 kbps */
	MVS_AMR_MODE_1985, /* AMR-WB 19.85 kbps */
	MVS_AMR_MODE_2305, /* AMR-WB 23.05 kbps */
	MVS_AMR_MODE_2385, /* AMR-WB 23.85 kbps */
	MVS_AMR_MODE_UNDEF
};

enum msm_audio_voc_rate {
		MVS_VOC_0_RATE, /* Blank frame */
		MVS_VOC_8_RATE, /* 1/8 rate    */
		MVS_VOC_4_RATE, /* 1/4 rate    */
		MVS_VOC_2_RATE, /* 1/2 rate    */
		MVS_VOC_1_RATE	/* Full rate   */
};

enum msm_audio_amr_frame_type {
	MVS_AMR_SPEECH_GOOD,	      /* Good speech frame              */
	MVS_AMR_SPEECH_DEGRADED,      /* Speech degraded                */
	MVS_AMR_ONSET,		      /* Onset                          */
	MVS_AMR_SPEECH_BAD,	      /* Corrupt speech frame (bad CRC) */
	MVS_AMR_SID_FIRST,	      /* First silence descriptor       */
	MVS_AMR_SID_UPDATE,	      /* Comfort noise frame            */
	MVS_AMR_SID_BAD,	      /* Corrupt SID frame (bad CRC)    */
	MVS_AMR_NO_DATA,	      /* Nothing to transmit            */
	MVS_AMR_SPEECH_LOST	      /* Downlink speech lost           */
};

enum msm_audio_g711a_mode {
	MVS_G711A_MODE_MULAW,
	MVS_G711A_MODE_ALAW
};

enum mvs_g722_mode_type {
	MVS_G722_MODE_01,
	MVS_G722_MODE_02,
	MVS_G722_MODE_03,
	MVS_G722_MODE_MAX,
	MVS_G722_MODE_UNDEF
};

enum msm_audio_g711a_frame_type {
	MVS_G711A_SPEECH_GOOD,
	MVS_G711A_SID,
	MVS_G711A_NO_DATA,
	MVS_G711A_ERASURE
};

enum msm_audio_g729a_frame_type {
	MVS_G729A_NO_DATA,
	MVS_G729A_SPEECH_GOOD,
	MVS_G729A_SID,
	MVS_G729A_ERASURE
};

struct min_max_rate {
	uint32_t min_rate;
	uint32_t max_rate;
};

struct msm_audio_mvs_config {
	uint32_t mvs_mode;
	uint32_t rate_type;
	struct min_max_rate min_max_rate;
	uint32_t dtx_mode;
};

#define MVS_MAX_VOC_PKT_SIZE 640

struct gsm_header {
	uint8_t bfi;
	uint8_t sid;
	uint8_t taf;
	uint8_t ufi;
};

struct q6_msm_audio_mvs_frame {
	union {
	uint32_t frame_type;
	uint32_t packet_rate;
	struct gsm_header gsm_frame_type;
	} header;
	uint32_t len;
	uint8_t voc_pkt[MVS_MAX_VOC_PKT_SIZE];

};

struct msm_audio_mvs_frame {
	uint32_t frame_type;
	uint32_t len;
	uint8_t voc_pkt[MVS_MAX_VOC_PKT_SIZE];

};

#define Q5V2_MVS_MAX_VOC_PKT_SIZE 320

struct q5v2_msm_audio_mvs_frame {
	uint32_t frame_type;
	uint32_t len;
	uint8_t voc_pkt[Q5V2_MVS_MAX_VOC_PKT_SIZE];

};
#endif /* __MSM_AUDIO_MVS_H */