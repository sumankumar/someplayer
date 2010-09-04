#include "library.h"

using namespace SomePlayer::DataObjects;
using namespace SomePlayer::Storage;

Library::Library(QString databasePath, QString playlistsPath) {
	_library_storage = new DbStorage(databasePath);
	_playlist_storage = new FileStorage(playlistsPath);
}

Library::~Library() {
	delete _library_storage;
	delete _playlist_storage;
}

void Library::addDirectory(QString path) {
	/// TODO: implement this
}

void Library::addFile(QString path) {
	/// TODO: implement this
}

QList<QString> Library::getArtists() {
	return _library_storage->getArtists();
}

QList<QString> Library::getAlbumsForArtist(QString artist) {
	return _library_storage->getAlbumsForArtist(artist);
}

QList<Track> Library::getTracksForAlbum(QString album, QString artist) {
	return _library_storage->getTracksForAlbum(album, artist);
}


// dynamic:

Playlist Library::getFavorites() {
	return _library_storage->getFavorites();
}

Playlist Library::getMostPlayed() {
	return _library_storage->getMostPlayed();
}

Playlist Library::getNeverPlayed() {
	return _library_storage->getNeverPlayed();
}

Playlist Library::getRecentlyAdded() {
	return _library_storage->getRecentlyAdded();
}


void Library::removeTrack(Track track) {
	_library_storage->removeTrack(track);
}

void Library::addToFavorites(Track track) {
	_library_storage->addToFavorites(track);
}

void Library::updateTrack(Track track) {
	_library_storage->updateTrack(track);
}


// playlists:

QList<Playlist> Library::getPlaylists() {
	return _playlist_storage->getPlaylists();
}

void Library::savePlaylist(Playlist playlist) {
	_playlist_storage->savePlaylist(playlist);
}

void Library::removePlaylist(Playlist playlist) {
	_playlist_storage->removePlaylist(playlist);
}


Playlist Library::getCurrentPlaylist() {
	return _playlist_storage->getCurrentPlaylist();
}

void Library::saveCurrentPlaylist(Playlist playlist) {
	_playlist_storage->saveCurrentPlaylist(playlist);
}
