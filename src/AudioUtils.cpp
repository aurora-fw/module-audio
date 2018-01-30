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

#include <AuroraFW/Audio/AudioUtils.h>

namespace AuroraFW {
	namespace AudioManager {
		// AudioInfo
		AudioInfo::AudioInfo(SF_INFO* sndInfo, SNDFILE* sndFile)
			: _sndInfo(sndInfo), _sndFile(sndFile)
		{}

		AudioInfo::~AudioInfo()
		{
			// NOTE: _sndFile is not deleted because that task belongs to AudioO/IStream
			delete _sndInfo;
		}

		const unsigned int AudioInfo::getSampleRate() const
		{
			return _sndInfo->samplerate;
		}

		const unsigned long AudioInfo::getFrames() const
		{
			return _sndInfo->frames;
		}

		const int AudioInfo::getChannels() const
		{
			return _sndInfo->channels;
		}

		const int AudioInfo::getFormat() const
		{
			return _sndInfo->format;
		}

		void AudioInfo::setSampleRate(const unsigned int samplerate)
		{
			_sndInfo->samplerate = samplerate;
		}

		void AudioInfo::setFrames(const unsigned long frames)
		{
			_sndInfo->frames = frames;
		}

		void AudioInfo::setChannels(const int channels)
		{
			_sndInfo->channels = channels;
		}

		void AudioInfo::setFormat(const int format)
		{
			_sndInfo->format = format;
		}

		const char* AudioInfo::getTitle() const
		{
			return sf_get_string(_sndFile, SF_STR_TITLE);
		}

		const char* AudioInfo::getCopyright() const
		{
			return sf_get_string(_sndFile, SF_STR_COPYRIGHT);
		}

		const char* AudioInfo::getSoftware() const
		{
			return sf_get_string(_sndFile, SF_STR_SOFTWARE);
		}

		const char* AudioInfo::getArtist() const
		{
			return sf_get_string(_sndFile, SF_STR_ARTIST);
		}

		const char* AudioInfo::getComment() const
		{
			return sf_get_string(_sndFile, SF_STR_COMMENT);
		}

		const char* AudioInfo::getDate() const
		{
			return sf_get_string(_sndFile, SF_STR_DATE);
		}

		const char* AudioInfo::getAlbum() const
		{
			return sf_get_string(_sndFile, SF_STR_ALBUM);
		}

		const char* AudioInfo::getLicense() const
		{
			return sf_get_string(_sndFile, SF_STR_LICENSE);
		}

		const char* AudioInfo::getTrackNumber() const
		{
			return sf_get_string(_sndFile, SF_STR_TRACKNUMBER);
		}

		const char* AudioInfo::getGenre() const
		{
			return sf_get_string(_sndFile, SF_STR_GENRE);
		}

		void AudioInfo::setTitle(const char* title)
		{
			sf_set_string(_sndFile, SF_STR_TITLE, title);
		}

		void AudioInfo::setCopyright(const char* copyright)
		{
			sf_set_string(_sndFile, SF_STR_COPYRIGHT, copyright);
		}

		void AudioInfo::setSoftware(const char* software)
		{
			sf_set_string(_sndFile, SF_STR_SOFTWARE, software);
		}

		void AudioInfo::setArtist(const char* artist)
		{
			sf_set_string(_sndFile, SF_STR_ARTIST, artist);
		}

		void AudioInfo::setComment(const char* comment)
		{
			sf_set_string(_sndFile, SF_STR_COMMENT, comment);
		}

		void AudioInfo::setDate(const char* date)
		{
			sf_set_string(_sndFile, SF_STR_DATE, date);
		}

		void AudioInfo::setAlbum(const char* album)
		{
			sf_set_string(_sndFile, SF_STR_ALBUM, album);
		}

		void AudioInfo::setLicense(const char* license)
		{
			sf_set_string(_sndFile, SF_STR_LICENSE, license);
		}

		void AudioInfo::setTrackNumber(const char* trackNumber)
		{
			sf_set_string(_sndFile, SF_STR_TRACKNUMBER, trackNumber);
		}

		void AudioInfo::setGenre(const char* genre)
		{
			sf_set_string(_sndFile, SF_STR_GENRE, genre);
		}
	}
}