/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_AUDIO_AUDIOUTILS_H
#define AURORAFW_AUDIO_AUDIOUTILS_H

// AuroraFW
#include <AuroraFW/Global.h>

// LibSNDFile
#include <sndfile.h>

namespace AurroaFW {
	namespace AudioManager {
		struct AFW_EXPORT AudioInfo {
			AudioInfo();
			AudioInfo(AudioOStream );
			~AudioInfo();

			const unsigned int getSampleRate() const;
			const unsigned long getFrames() const;
			const int getChannels() const;
			const int getFormat() const;

			void setSampleRate(const unsigned int );
			void setFrames(const unsigned long );
			void setChannels(const int );
			void setFormat(const int );

			const char* getTitle() const;
			const char* getCopyright() const;
			const char* getSoftware() const;
			const char* getArtist() const;
			const char* getComment() const;
			const char* getDate() const;
			const char* getAlbum() const;
			const char* getLicense() const;
			const char* getTrackNumber() const;
			const char* getGenre() const;

			void setTitle(const char* title);
			void setCopyright(const char* copyright);
			void setSoftware(const char* software);
			void setArtist(const char* artist);
			void setComment(const char* comment);
			void setDate(const char* date);
			void setAlbum(const char* album);
			void setLicense(const char* license);
			void setTrackNumber(const char* trackNumber);
			void setGenre(const char* genre);
		};
	}
}

#endif  // AURORAFW_AUDIO_AUDIO_UTILS_H