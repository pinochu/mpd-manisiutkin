/*
 * Copyright 2003-2017 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_EVENT_PIPE_HXX
#define MPD_EVENT_PIPE_HXX

#include "check.h"

/**
 * A pipe that can be used to trigger an event to the read side.
 *
 * Errors in the constructor are fatal.
 */
class EventPipe {
	int fds[2];

public:
	/**
	 * Throws on error.
	 */
	EventPipe();

	~EventPipe() noexcept;

	EventPipe(const EventPipe &other) = delete;
	EventPipe &operator=(const EventPipe &other) = delete;

	int Get() const noexcept {
		return fds[0];
	}

	/**
	 * Checks if Write() was called at least once since the last
	 * Read() call.
	 */
	bool Read() noexcept;

	/**
	 * Wakes up the reader.  Multiple calls to this function will
	 * be combined to one wakeup.
	 */
	void Write() noexcept;
};

#endif /* MAIN_NOTIFY_H */
