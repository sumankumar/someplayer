#ifndef LIBRARY
#define LIBRARY

#include "someplayer.h"
#include "track.h"
#include "playlist.h"
#include "dbstorage.h"
#include "filestorage.h"
#include "mediascanner.h"
#include "tagresolver.h"

#define _DATABASE_PATH_ "/tmp"
#define _PLAYLISTS_PATH_ "/tmp"

// represents media library: tracks, playlists
// it uses different media storages for tracks and playlists
// but dynamic playlits will be stored with tracks into the same storage

using SomePlayer::DataObjects::Track;
using SomePlayer::DataObjects::Playlist;
using SomePlayer::Storage::DbStorage;
using SomePlayer::Storage::FileStorage;
using SomePlayer::Storage::MediaScanner;

namespace SomePlayer {
	namespace DataObjects {

		class Library : public QObject {
			Q_OBJECT
		public:
			Library(QString databasePath, QString playlistsPath);
			~Library();

			void addDirectory(QString path);
			void addFile(QString path);

			QList<QString> getArtists();
			QList<QString> getAlbumsForArtist(QString artist);
			QList<Track> getTracksForAlbum(QString album, QString artist);

			Playlist getFavorites();
			Playlist getMostPlayed();
			Playlist getNeverPlayed();
			Playlist getRecentlyAdded();

			QList<Playlist> getPlaylists();
			QStringList getPlaylistsNames();
			Playlist getPlaylist(QString name);
			void savePlaylist(const Playlist &playlist);
			void removePlaylist(const Playlist &playlist);
			void removePlaylist(QString name);

			Playlist getCurrentPlaylist();
			void saveCurrentPlaylist(const Playlist &playlist);

		signals:
			void addingDone();

		private:
			DbStorage *_library_storage;
			FileStorage *_playlist_storage;
			MediaScanner *_scanner;
			TagResolver *_resolver;

		public slots:
			void removeTrack(Track);
			void addTrack(Track);
			void addToFavorites(Track);
			void updateTrackCount(Track);
		};

	};
};

#endif
