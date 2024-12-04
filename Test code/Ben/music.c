#include "open_interface.h"
#include "music.h"

/// Load three songs onto the iRobot
/**
 *
 *Song to play when there is a delivery
 */
void load_delivery_sound() {

	unsigned char rickrollNumNotes = 11;
	unsigned char rickrollNotes[11]    = {53, 55, 48, 55, 57, 60, 58, 57, 53, 55, 48};
	unsigned char rickrollDuration[11] = {48, 64, 16, 48, 48, 8,  8,  8,  48, 64, 64};
	oi_loadSong(RICK_ROLL, rickrollNumNotes, rickrollNotes, rickrollDuration);
    oi_play_song(0);


}

/**
 *
 * Song to play when an edge is detected or another warning state is triggered
 */
void load_warning_sound() {

    // Notes: oi_load_song takes four arguments
    // arg1 - an integer from 0 to 16 identifying this song
    // arg2 - an integer that indicates the number of notes in the song (if greater than 16, it will consume the next song index's storage space)
    // arg3 - an array of integers representing the midi note values (example: 60 = C, 61 = C sharp)
    // arg4 - an array of integers representing the duration of each note (in 1/64ths of a second)

  unsigned char ImperialMarchNumNotes = 24;
  unsigned char ImperialMarchNotes[24] = {64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60, 64, 60};
  unsigned char ImperialMarchDurations[24] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
  oi_loadSong(IMERPIAL_MARCH, ImperialMarchNumNotes, ImperialMarchNotes, ImperialMarchDurations);

    oi_play_song(1);


}
