#ifndef CHIAKI_PI_DECODER_H
#define CHIAKI_PI_DECODER_H

#include <chiaki/config.h>
#include <chiaki/log.h>

#include <ilclient.h>

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct chiaki_pi_decoder_t
{
	ChiakiLog *log;
	TUNNEL_T     tunnel[2];
	COMPONENT_T *list[4];   // array of pointers, was[3] but added GL for [4]
	ILCLIENT_T  *client;
	COMPONENT_T *video_decode;
	COMPONENT_T *video_scheduler;
	COMPONENT_T *video_render;
	bool port_settings_changed;
	bool first_packet;
} ChiakiPiDecoder;

CHIAKI_EXPORT void chiaki_pi_decoder_init(ChiakiPiDecoder *decoder, ChiakiLog *log);
CHIAKI_EXPORT void chiaki_pi_decoder_fini(ChiakiPiDecoder *decoder);
CHIAKI_EXPORT void chiaki_pi_decoder_transform(ChiakiPiDecoder *decoder, int x, int y, int w, int h);
CHIAKI_EXPORT void chiaki_pi_decoder_visibility(ChiakiPiDecoder *decoder, bool visible);
CHIAKI_EXPORT bool chiaki_pi_decoder_video_sample_cb(uint8_t *buf, size_t buf_size, void *user);

#ifdef __cplusplus
}
#endif 

#endif // CHIAKI_PI_DECODER_H
